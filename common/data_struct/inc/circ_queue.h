#ifndef _CIRC_QUEUE_H_1209_
#define _CIRC_QUEUE_H_1209_

#include "jack_lin_types.h"

typedef struct nrcnode_t
{
    #define CIRC_VALID 0xBADFACE
    #define CIRC_INVALID 0xFEEDBAC
    #define PENDING 0x0DDF00D
    int valid;
    void* data;
}NR_CNODE;

typedef struct circ_queue_t
{
#if defined(__x86_64__) || defined(__aarch64__)
    long long int head;
    long long int tail;
#else
    long int head;
    long int tail;
#endif
    int count;// count = 2^n
    int max;// max = 2^n - 1
    NR_CNODE *ring;
}CIRCQUEUE;

UInt32 circQInit(CIRCQUEUE *list, UInt32 maxNodes);
UInt32 pushNodeCircQ(CIRCQUEUE *list, void* data);
UInt32 popNodeCircQ(CIRCQUEUE *list, void** outData);
UInt32 freeMemForCircQ(CIRCQUEUE *list);

#endif
