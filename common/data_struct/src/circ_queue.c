#include "circ_queue.h"
#include <stdlib.h>
#include <stdio.h>

UInt32 circQInit(CIRCQUEUE *list, UInt32 maxNodes)
{
    UInt32 i = 2;
    SInt32 idx = 0;
    list->max = 0;
    list->count = 0;
    while (i < maxNodes)
    {
        i = i * 2;
    }
    list->max = i - 1;

    list->ring = (NR_CNODE*)malloc(sizeof(NR_CNODE) * (list->max + 1));
    if (PNULL == list->ring)
    {
        return JACK_FAILURE;
    }

    for (idx = 0; idx <= list->max; idx++)
    {
        list->ring[idx].valid = CIRC_INVALID;
        list->ring[idx].data = PNULL;
    }
    list->head = 0;
    list->tail = 0;
    return JACK_SUCCESS;
}

UInt32 pushNodeCircQ(CIRCQUEUE *list, void* data)
{
    UInt32 prev;
    UInt32 temp;

    prev = list->tail;
    do{
        prev = prev & list->max;
        if (list->count == (list->max + 1))
        {
            return JACK_FAILURE;
        }
        if (PNULL == list->ring)
        {
            return JACK_FAILURE;
        }
        if (!BOOL_COMPARE_AND_SWAP(&list->ring[prev].valid, CIRC_INVALID, PENDING))
        {
            FETCH_AND_ADD_EV32(&prev, 1);
            continue;
        }
        else
        {
            break;
        }

    }while(1);

    list->ring[prev].data = data;
    if (!BOOL_COMPARE_AND_SWAP(&list->ring[prev].valid, PENDING, CIRC_VALID))
    {
        printf("how did this happen?\n");
        return JACK_FAILURE;
    }
#if defined(__x86_64__) || defined(__aarch64__)
    FETCH_AND_ADD_EV64(&list->tail, 1);
#else
    FETCH_AND_ADD_EV32(&list->tail, 1);
#endif

    do{
        temp = list->tail;
    }while(!BOOL_COMPARE_AND_SWAP(&list->tail,temp, temp & list->max));
    FETCH_AND_ADD_EV32(&list->count, 1);
    return JACK_SUCCESS;
}

UInt32 popNodeCircQ(CIRCQUEUE *list, void** outData)
{
    UInt32 prev;
    UInt32 next;

    prev = list->head & list->max;
    next = (prev+1) & list->max;

    do{
        if (list->count == 0)
        {
            printf("count is 0\n");
            *outData = PNULL;
            return JACK_FAILURE;
        }
        if  (list->ring[prev].valid == PENDING)
        {
            printf("ongoing push\n");
            *outData = PNULL;
            return JACK_FAILURE;
        }
        if (!BOOL_COMPARE_AND_SWAP(&list->head, prev, next))
        {
            prev = list->head & list->max;
            next = (prev+1) & list->max;
            continue;
        }
        else if (list->ring[prev].valid == CIRC_INVALID)
        {
            printf("fail: freeing memory\n");
            abort();
            prev = list->head & list->max;
            next = (prev+1) & list->max;
            continue;
        }
        else
        {
            break;
        }
    }while(1);

    *outData = list->ring[prev].data;
    if (!BOOL_COMPARE_AND_SWAP(&list->ring[prev].valid, CIRC_VALID, CIRC_INVALID))
    {
        printf("fail: set node state filed\n");
        *outData = PNULL;
        return JACK_FAILURE;
    }
    FETCH_AND_SUB_EV32(&list->count, 1);
    return JACK_SUCCESS;
}

UInt32 freeMemForCircQ(CIRCQUEUE *list)
{
    SInt32 idx = 0;

    if (PNULL == list->ring)
    {
        return JACK_FAILURE;
    }

    free((void*)list->ring);
    return JACK_SUCCESS;
}
