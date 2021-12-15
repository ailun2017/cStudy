#include "socket_wrapper.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/select.h>


static int g_listenfd;

static int parse_command_line_long_options(int argc, char* argv[], unsigned short *port)
{
    //使用长选项：--port=val
    static struct option long_options[] ={
            {"port", 1, NULL, 'p'},
            {0, 0, 0, 0}};
    int input_option = 0;
    int option_index = 0;
    while(1)
    {
        input_option = getopt_long(argc, argv, "", long_options, &option_index);
        if (-1 == input_option) break;
        switch(input_option)
        {
            case 'p':
            {
                *port = atoi(optarg);
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


static void signal_handler(int sig)
{
    printf("i have received the signal %d\n", sig);
   // sleep(20);
    close(g_listenfd);
    exit(0);
}

static int init_socket(unsigned short port)
{
    int listenfd;    
   if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
   {
      perror("socket");
      return -1;
   }

   struct sockaddr_in servaddr;
   memset(&servaddr, 0, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
   servaddr.sin_port = htons(port);
   if (0 != bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)))
   {
      perror("bind");
      close(listenfd);
      return -1;
   }

   if (0 != (listen(listenfd, 10)))
   {
      perror("listen");
      close(listenfd);
      return -1;
   }
   return listenfd;
}

void server_with_multi_pid_main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("using : ./server --port=val\nexample: ./server --port=5005\n");
        return;
    }

    unsigned short port;
    if (-1 ==  parse_command_line_long_options(argc, argv, &port))
    {
        printf("error argc\n");
        return;
    }
    g_listenfd = init_socket(port);
    if (g_listenfd < 0)
    {
        printf("init_socket fail\n");
        return;
    }
    int socklen = sizeof(struct sockaddr_in);
    struct sockaddr_in clientaddr;

    //set signal
    struct sigaction newact, oldact;
    newact.sa_handler = SIG_IGN;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    sigaction(SIGCHLD, &newact, &oldact);

    newact.sa_flags = SA_RESTART;
    newact.sa_handler = signal_handler;
    sigaction(SIGINT, &newact, &oldact);
    int clientfd;
    while(1)
    {
        clientfd = accept(g_listenfd, (struct sockaddr*)&clientaddr, (socklen_t*)&socklen);
        if(fork() > 0){
            close(clientfd);
            continue;       
        }
        close(g_listenfd);                                                                                                                                              int cur_pid =  getpid();                                                                                                                                      printf("pid%d: client（%s) accepted.\n", cur_pid, inet_ntoa(clientaddr.sin_addr));
        char buffer[1024];
        int iret;
        while(1)
        {
            memset(buffer, 0, sizeof(buffer));
            printf("start recv\n");
            if (0 >= (iret = recv(clientfd, buffer, sizeof(buffer), 0)))                                                                                                  {                                                                                                                                                                 printf("iret = %d\n", iret);                                                                                                                                  continue;                                                                                                                                                 }

            printf("[%d]recv: %s\n",cur_pid,  buffer);
            if (0 == strcmp(buffer, "over"))
            {
                break;
            }
            memset(buffer, 0, sizeof(buffer));
            printf("[%d]say:", cur_pid);
            scanf("%s", buffer);
            if (0 >= (iret = send(clientfd, buffer, sizeof(buffer), 0)))
            {                                                                                     
                printf("iret = %d\n", iret);
                break;
            }
            printf("[%d]send: %s\n",cur_pid, buffer);

        }
        close(clientfd);
        break;
    }
}

void server_with_select(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("using : ./server --port=val\nexample: ./server --port=5005\n");
        return;
    }

    unsigned short port;
    if (-1 ==  parse_command_line_long_options(argc, argv, &port))
    {
        printf("error argc\n");
        return;
    }
    g_listenfd = init_socket(port);
    if (g_listenfd < 0)
    {
        printf("init_socket fail\n");
        return;
    }
    printf("listen fd %d\n", g_listenfd);
    int socklen = sizeof(struct sockaddr_in);
    struct sockaddr_in clientaddr;

    //set signal
    struct sigaction newact, oldact;
    newact.sa_handler = SIG_IGN;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    sigaction(SIGCHLD, &newact, &oldact);

    newact.sa_flags = SA_RESTART;
    newact.sa_handler = signal_handler;
    sigaction(SIGINT, &newact, &oldact);

    int clientfd;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    
    fd_set socket_fd_set;
    FD_ZERO(&socket_fd_set);
    int max_fd;
    FD_SET(g_listenfd, &socket_fd_set);
    max_fd = g_listenfd;
    
    while(1)
    {
        fd_set temp_fd_set = socket_fd_set;

        int ret = select(max_fd + 1, &temp_fd_set, NULL, NULL, NULL);

        if (-1 == ret) {printf("select return error\n"); break;}
        if (0 == ret) {printf("select timeout\n"); continue;}

        for (int socket_fd = 0; socket_fd <= max_fd; socket_fd++)
        {
            if (FD_ISSET(socket_fd, &temp_fd_set) <= 0)
            {
               // printf("isset\n");
                continue;
            }
            if (g_listenfd == socket_fd)
            {
                //printf("listenfd\n");
                clientfd = accept(g_listenfd, (struct sockaddr*)&clientaddr, (socklen_t*)&socklen);
                if (clientfd < 0)
                {
                    printf("accept failed!\n");
                    continue;
                }
                FD_SET(clientfd, &socket_fd_set);
                if (max_fd < clientfd)
                {
                    max_fd = clientfd;
                }
                printf("client_fd-%d: client（%s) accepted.\n", clientfd, inet_ntoa(clientaddr.sin_addr));
                continue;
            }
            else// client
            {
                printf("clientfd\n");
                memset(buffer, 0, sizeof(buffer));
                if (0 >= (recv(socket_fd, buffer, 10, 0)))
                {
                    printf("client-%d disconnected.\n", socket_fd);
                    close(socket_fd);
                    FD_CLR(socket_fd, &socket_fd_set);
                    if (socket_fd == max_fd)
                    {
                        for (int loop = socket_fd - 1; loop  > 0; loop--)
                        {
                            if (FD_ISSET(loop,  &socket_fd_set))
                            {
                                max_fd = loop;
                                break;
                            }
                        }
                        printf("max_fd %d\n", max_fd);
                        
                    }
                    continue;
                }
                printf("client-%d recv %s\n", socket_fd, buffer);
            }
        }

    }
} 
