#include "single_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void init_single_linked_list(single_linked_list_t* list)
{
    list->head = PNULL;
}

return_t insert_single_linked_list_node(single_linked_list_t* list, single_linked_list_node_t* node)
{
    if (PNULL == list) return JACK_FAILURE;

    node->next = list->head;
    list->head = node;

    return JACK_SUCCESS;
}

return_t delete_single_linked_list_node(single_linked_list_t* list, single_linked_list_node_t* node)
{
    return JACK_SUCCESS;
}

void reverse_single_linked_list(single_linked_list_t* list)
{
    if (PNULL == list) return;
    single_linked_list_node_t* cur_node;
    single_linked_list_node_t* prev_node;
    single_linked_list_node_t* next_node;

    prev_node = list->head;
    cur_node = prev_node->next;
    if (PNULL == cur_node)
    {
        next_node = PNULL;
    }
    else
    {
        next_node = cur_node->next;
    }
    while(cur_node != PNULL)
    {
        cur_node->next = prev_node;
        prev_node = cur_node;
        cur_node = next_node;
        if (cur_node != PNULL)
        {
            next_node = cur_node->next;
        }
    }
    list->head->next = PNULL;
    list->head = prev_node;
}

void test_reverse_single_linked_list()
{
    single_linked_list_t list;
    init_single_linked_list(&list);
    UInt8 data[5] = {1,2,3,4,5};
    UInt8 loop = 0;
    single_linked_list_node_t node[5];
    for (; loop < 5; loop++)
    {
        node[loop].data = (void*)&data[loop];
        insert_single_linked_list_node(&list, &node[loop]);
    }
    single_linked_list_node_t* p_list_node = list->head;
    while (p_list_node != PNULL)
    {
        printf("%d   ", *((UInt8*)p_list_node->data));
        p_list_node = p_list_node->next;
    }
    printf("\n");
    reverse_single_linked_list(&list);
    p_list_node = list->head;
    while (p_list_node != PNULL)
    {
        printf("%d   ", *((UInt8*)p_list_node->data));
        p_list_node = p_list_node->next;
    }
    printf("\n");
}