#ifndef _DOUBLE_END_QUEUE_
#define _DOUBLE_END_QUEUE_

typedef struct list_node_t
{
    struct list_node_t *prev;
    struct list_node_t *next;
}list_node_t;

typedef struct double_end_queue_t
{
    list_node_t* head;
    list_node_t* tail;
    unsigned int count;
}double_end_queue_t;

#endif
