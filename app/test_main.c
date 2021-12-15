#include "test_main.h"
#include "socket_wrapper.h"
#include <stdlib.h>
#include <stdio.h>
#include "data_struct_test.h"

/*
static int parse_command_line_long_options(int argc, char* argv[], int *test_num)
{
    //使用长选项：--port=val
    static struct option long_options[] ={
            {"test", 1, NULL, 'n'},
            {0, 0, 0, 0}};
    int input_option = 0;
    int option_index = 0;
    while(1)
    {
        input_option = getopt_long(argc, argv, "", long_options, &option_index);
        if (-1 == input_option) break;
        switch(input_option)
        {
            case 'n':
            {
                *test_num = atoi(optarg);
                break;
            }
            default:
            {
                return -1;
            }
        }
    }
    return 0;
}
*/

int main(int argc, char* argv[])
{
    int test_name_index = CIRC_QUEUE_TEST;
   /* if (-1 == parse_command_line_long_options(argc, argv, &test_name_index))
    {
        printf("argc is error!example:./server --test=0\n");
        return -1;
    }*/

    switch(test_name_index)
    {
        case SOCKET_WITH_MULTI_PID:
        {
            server_with_multi_pid_main(argc, argv);
            break;
        }
        case SOCKET_WITH_SELECT:
        {
            server_with_select(argc, argv);
            break;
        }
        case CIRC_QUEUE_TEST:
        {
            test_circ_queue();
            break;
        }
        default:
        {
            printf("error test_name_index!\n");
        }
    }
    return 0;
}
