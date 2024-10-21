#include "lib.h"

void init_winsock()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("Failed to initialize Winsock. Error Code: %d\n", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
}

int check_proxy_connection(const char *proxy_address, int port)
{
    int sock;
    struct sockaddr_in server;
#ifdef _WIN32
    init_winsock(); // Initialize Winsock
#endif

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("Socket creation failed");
        return -1;
    }

    // Set up the server structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(proxy_address);

    // Try to connect to the proxy server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        perror("Connection to proxy failed");
#ifdef _WIN32
        closesocket(sock);
        WSACleanup();
#else
        close(sock);
#endif
        return -1;
    }

    // Connection successful
#ifdef _WIN32
    closesocket(sock);
    WSACleanup();
#else
    close(sock);
#endif
    return 0;
}