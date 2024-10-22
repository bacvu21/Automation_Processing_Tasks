#ifndef __lib__h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#else
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#endif

#include <sys/types.h>

// #pragma comment(lib, "Ws2_32.lib") // add to information for compiler this link with Ws2 lib
/*max define 5 process*/
#define MAX_PROCESS 5

int create_new_process_(int number_of_process);
int check_proxy_connection(const char *proxy_address, int port);
int Open_browser(const char *url);

#endif