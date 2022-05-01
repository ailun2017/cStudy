#ifndef _DOUBLE_END_QUEUE_
#define _DOUBLE_END_QUEUE_

#include "jack_lin_types.h"
#include <pthread.h>


typedef struct list_node_t
{
    struct list_node_t *prev;
    struct list_node_t *next;
}list_node_t;

typedef struct double_end_queue_t
{
    void* head;
    void* tail;
    unsigned int count;
    pthread_mutex_t lock;
}double_end_queue_t;

typedef struct test_double_queue_node_t
{
    list_node_t anchor;
    UInt8 elem;

}test_double_queue_node_t;

void dbeQueueInit(double_end_queue_t* queue);
UInt8 dbeQueueIsEmpty(double_end_queue_t* queue);
return_t dbeQueueEnqueueInLeft(double_end_queue_t* queue, list_node_t* node);
return_t dbeQueueEnqueueInRight(double_end_queue_t* queue, list_node_t* node);
list_node_t* dbeQueueDequeueInRight(double_end_queue_t* queue);
list_node_t* dbeQueueDequeueInLeft(double_end_queue_t* queue);
void test_double_end_queue_example();

#endif
