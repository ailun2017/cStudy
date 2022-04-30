#include "double_end_queue.h"
#include <stdio.h>

void dbeQueueInit(double_end_queue_t* queue)
{
    if (PNULL == queue)
    {
        printf("queue is PNULL!\n");
        return;
    }
    queue->count = 0;
    queue->head = PNULL;
    queue->tail = PNULL;
}

UInt8 dbeQueueIsEmpty(double_end_queue_t* queue)
{
    if (PNULL == queue)
    {
        printf("queue is PNULL!\n");
        return JACK_FALSE;
    }
    return (queue->count == 0);
}

return_t dbeQueueEnqueueInLeft(double_end_queue_t* queue, list_node_t* node)
{
    if (PNULL == queue || PNULL == node)
    {
        printf("queue is PNULL!\n");
        return JACK_FAILURE;
    }

    if (0 == queue->count)
    {
        queue->head = (void*)node;
        queue->tail = (void*)node;
        node->next = PNULL;
        node->prev = PNULL;
        queue->count++;
    }
    else
    {
        ((list_node_t*)(queue->head))->prev = node;
        node->prev = PNULL;
        node->next = (list_node_t*)(queue->head);
        queue->head = (void*)node;
        queue->count++;
    }
    return JACK_SUCCESS;
}

return_t dbeQueueEnqueueInRight(double_end_queue_t* queue, list_node_t* node)
{
    if (PNULL == queue || PNULL == node)
    {
        printf("queue is PNULL!\n");
        return JACK_FAILURE;
    }

    if (0 == queue->count)
    {
        queue->head = (void*)node;
        queue->tail = (void*)node;
        node->next = PNULL;
        node->prev = PNULL;
        queue->count++;
    }
    else
    {
        ((list_node_t*)queue->tail)->next = node;
        node->prev = ((list_node_t*)queue->tail);
        node->next = PNULL;
        queue->tail = (void*)node;
        queue->count++;
    }
    return JACK_SUCCESS;
}

list_node_t* dbeQueueDequeueInRight(double_end_queue_t* queue)
{
    list_node_t* dequeued_node = PNULL;
    if (PNULL == queue)
    {
        printf("queue is PNULL!\n");
        return PNULL;
    }
    if (0 == queue->count)
    {
        printf("queue->count is 0!\n");
        return PNULL;
    }

    if (1 == queue->count)
    {
        dequeued_node = (list_node_t*)queue->tail;
        queue->head = PNULL;
        queue->tail = PNULL;
        queue->count--;
    }
    else
    {
        dequeued_node = (list_node_t*)queue->tail;
        (((list_node_t*)queue->tail)->prev)->next = PNULL;
        queue->tail = (void*)(((list_node_t*)queue->tail)->prev);
        queue->count--;
    }
    return dequeued_node;
}

list_node_t* dbeQueueDequeueInLeft(double_end_queue_t* queue)
{
    list_node_t* dequeued_node = PNULL;
    if (PNULL == queue)
    {
        printf("queue is PNULL!\n");
        return PNULL;
    }
    if (0 == queue->count)
    {
        printf("queue->count is 0!\n");
        return PNULL;
    }

    if (1 == queue->count)
    {
        dequeued_node = (list_node_t*)queue->head;
        queue->head = PNULL;
        queue->tail = PNULL;
        queue->count--;
    }
    else
    {
        dequeued_node = (list_node_t*)queue->head;
        (((list_node_t*)queue->head)->next)->prev = PNULL;
        queue->head = (void*)(((list_node_t*)queue->head)->next);
        queue->count--;
    }
    return dequeued_node;
}

void test_double_end_queue_example()
{
    double_end_queue_t queue;
    dbeQueueInit(&queue);
    test_double_queue_node_t *p_left_node;
    test_double_queue_node_t *p_right_node;
    
    test_double_queue_node_t node1 = {0};
    node1.elem = 1;
    test_double_queue_node_t node2 = {0};
    node1.elem = 2;
    test_double_queue_node_t node3 = {0};
    node1.elem = 3;
    test_double_queue_node_t node4 = {0};
    node1.elem = 2;
    test_double_queue_node_t node5 = {0};
    node1.elem = 1;

    if (JACK_FAILURE == dbeQueueEnqueueInRight(&queue, (list_node_t*)&node1.anchor))
        printf("dbeQueueEnqueueInRight failed!\n");
    if (JACK_FAILURE == dbeQueueEnqueueInRight(&queue, (list_node_t*)&node2.anchor))
        printf("dbeQueueEnqueueInRight failed!\n");
    if (JACK_FAILURE == dbeQueueEnqueueInRight(&queue, (list_node_t*)&node3.anchor))
        printf("dbeQueueEnqueueInRight failed!\n");
    if (JACK_FAILURE == dbeQueueEnqueueInRight(&queue, (list_node_t*)&node4.anchor))
        printf("dbeQueueEnqueueInRight failed!\n");
    if (JACK_FAILURE == dbeQueueEnqueueInRight(&queue, (list_node_t*)&node5.anchor))
        printf("dbeQueueEnqueueInRight failed!\n");

    printf("init queue count %d\n", queue.count);
    UInt8 loop_max = queue.count > 2;
    UInt8 loop = 0;
    UInt8 is_same_elem = JACK_TRUE;
    for ( ; loop < loop_max; loop++)
    {
        p_left_node = (test_double_queue_node_t*)dbeQueueDequeueInLeft(&queue);
        p_right_node = (test_double_queue_node_t*)dbeQueueDequeueInRight(&queue);
        if (p_left_node && p_right_node)
        {
            if (p_left_node->elem != p_right_node->elem)
            {
                is_same_elem = JACK_FALSE;
                break;
            }
        }
    }
    printf("after queue count %d\n", queue.count);
    if (is_same_elem)
    {
        printf("this is the queue what we want\n");
    }
    else
    {
        printf("this is not the queue what we want\n");
    }
}

