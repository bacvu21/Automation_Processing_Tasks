#include "lib.h"

int create_new_process_(int number_of_process)
{
    for (int i = 0; i < number_of_process; i++)
    {
#ifdef _WIN32
        // Windows platform
        STARTUPINFO si;
        PROCESS_INFORMATION pi;

        // Initialize structures
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));

        char command[] = "msedge.exe --proxy-server=http://152.230.215.123:8080";
        // Create new process to execute the command
        if (!CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
        {
            printf("CreateProcess failed (%lu).\n", GetLastError());
            return -1;
        }

        // Close handles
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
#else
        // Unix-like platform
        pid_t p = fork();
        if (p < 0)
        {
            perror("fork failed");
            return -1;
        }
        if (p == 0)
        {
            // Child process
            printf("Child process %d created, opening browser with proxy...\n", i + 1);

            // Open Firefox with proxy (example command)
            execlp("firefox", "firefox", "--proxy-server=http://yourproxy.com:8080", NULL);

            // If execlp fails, exit the child process
            perror("execlp failed");
            exit(EXIT_FAILURE);
        }
        // Parent process continues without waiting
#endif
    }
    return 0;
}