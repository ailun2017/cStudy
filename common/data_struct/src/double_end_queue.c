#include "double_end_queue.h"

void dbeQueueInit(double_end_queue_t* queue)
{
    if (null == queue)
    {
        printf("queue is null!\n");
        return;
    }
    queue->count = 0;
    queue->head = null;
    queue->tail = null;
}
