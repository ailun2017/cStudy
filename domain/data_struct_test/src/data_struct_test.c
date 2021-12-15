#include "data_struct_test.h"
#include "circ_queue.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <error.h>
#define _GNU_SOURCE
#include <pthread.h>
#include <errno.h>
#include <sched.h>
#include <sys/syscall.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <semaphore.h>
#include <stdlib.h>

void* thread1_main_func(void* arg);
void* thread2_main_func(void* arg);


int create_thread(pthread_t* thread_id, int detach_state, int schedpolicy, int priority, int inherit_sched,
                int scope, char* thread_name, void* (*func)(void*), void* arg)
{
    int rc = 0;
    pthread_attr_t thread_attr;

    rc = pthread_attr_init(&thread_attr);
    if (0 == rc && detach_state != PTHREAD_CREATE_JOINABLE)
    {
        rc = pthread_attr_setdetachstate(&thread_attr, detach_state);
    }
    if (0 == rc && schedpolicy != SCHED_OTHER)
    {
        rc = pthread_attr_setschedpolicy(&thread_attr, schedpolicy);
    }

    if (0 == rc && priority != 0)
    {
        struct sched_param schedparam = {0};
        schedparam.sched_priority = priority;
        rc = pthread_attr_setschedparam(&thread_attr, &schedparam);
    }

    if (0 == rc && inherit_sched != PTHREAD_INHERIT_SCHED)
    {
        rc = pthread_attr_setinheritsched(&thread_attr, inherit_sched);
    }

    if (0 ==rc && scope != PTHREAD_SCOPE_SYSTEM)
    {
        rc = pthread_attr_setscope(&thread_attr, scope);
    }

    if (0 != rc) return rc;
    else rc = pthread_create(thread_id, &thread_attr, func, arg);

    if (0 != rc) return rc;
    else return (pthread_setname_np(*thread_id, (const char*)thread_name));
}




#define MAX_NODE_CIRC_Q 1024
UInt16 g_test_circQ_node[MAX_NODE_CIRC_Q] = {0};

CIRCQUEUE* gp_circ_queue;
UInt16 g_node_count[2] = {0, 300};

void test_circ_queue()
{
    gp_circ_queue = (CIRCQUEUE*)malloc(sizeof(CIRCQUEUE));
    circQInit(gp_circ_queue, MAX_NODE_CIRC_Q);
    pthread_t thread1;
    pthread_t thread2;

    UInt8 ret = create_thread(&thread1, PTHREAD_CREATE_JOINABLE, SCHED_OTHER, 0, PTHREAD_EXPLICIT_SCHED,
            PTHREAD_SCOPE_SYSTEM, "THREAD1", thread1_main_func, PNULL);
    if (ret != 0)
    {
        printf("create thread failed, errno %d\n", errno);
        return;
    }
    ret = create_thread(&thread2, PTHREAD_CREATE_JOINABLE, SCHED_OTHER, 0, PTHREAD_EXPLICIT_SCHED,
            PTHREAD_SCOPE_SYSTEM, "THREAD2", thread2_main_func, PNULL);
    if (ret != 0)
    {
        printf("create thread failed, errno %d\n", errno);
        return;
    }
    pthread_join(thread1, PNULL);
    pthread_join(thread2, PNULL);
    freeMemForCircQ(gp_circ_queue);
    free((void*)gp_circ_queue);
    return;
}

void* thread1_main_func(void* arg)
{
    UInt8 idx = 0;
    UInt16* data = PNULL;
    for (idx = 0; idx < 20; idx++)
    {
        g_test_circQ_node[g_node_count[0]] = g_node_count[0]; 
        pushNodeCircQ(gp_circ_queue, (void*)&g_test_circQ_node[g_node_count[0]]);
        g_node_count[0]++;
        sleep(1);
        popNodeCircQ(gp_circ_queue, (void**)&data);
        printf("thread1：pop data %d\n", *data);
    }
    pthread_exit(0);
}


void* thread2_main_func(void* arg)
{
    UInt8 idx = 0;
    UInt16* data = PNULL;
    for (idx = 0; idx < 20; idx++)
    {
        g_test_circQ_node[g_node_count[1]] = g_node_count[1];
        pushNodeCircQ(gp_circ_queue, (void*)&g_test_circQ_node[g_node_count[1]]);
        g_node_count[1]++;
        sleep(1);

        popNodeCircQ(gp_circ_queue, (void**)&data);
        printf("thread2：pop data %d\n", *data);
    }
    pthread_exit(0);
}
