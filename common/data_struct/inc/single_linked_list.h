#ifndef _SINGLE_LINKED_LIST_
#define _SINGLE_LINKED_LIST_

#include "jack_lin_types.h"

typedef struct single_linked_list_node_t
{
    struct single_linked_list_node_t* next;
    void* data;
}single_linked_list_node_t;

typedef struct single_linked_list_t
{
    single_linked_list_node_t* head;
}single_linked_list_t;


void init_single_linked_list(single_linked_list_t* list);
return_t insert_single_linked_list_node(single_linked_list_t* list, single_linked_list_node_t* node);
return_t delete_single_linked_list_node(single_linked_list_t* list, single_linked_list_node_t* node);
void reverse_single_linked_list(single_linked_list_t* list);
void test_reverse_single_linked_list();
#endif