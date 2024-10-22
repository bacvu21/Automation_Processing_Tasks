#include "lib.h"

int Open_browser(const char *url)
{
	if (url == NULL)
	{
		return -1; // Return -1 if the URL is NULL
	}

	// Determine the size needed for the command string
	size_t command_size = strlen(url) + 20; // Extra space for the platform-specific command

	// Dynamically allocate memory for the command string
	char *command = (char *)malloc(command_size);

	if (command == NULL)
	{
		return -1; // Memory allocation failed
	}

#ifdef _WIN32
	// Windows: Use "start"
	strcpy(command, "start ");
#elif __APPLE__
	// macOS: Use "open"
	strcpy(command, "open ");
#elif __linux__
	// Linux: Use "xdg-open"
	strcpy(command, "xdg-open ");
#else
	free(command);
	return -1; // Unsupported platform
#endif

	// Concatenate the URL to the command string
	strcat(command, url);

	// Execute the command
	int result = system(command);

	// Free the allocated memory
	free(command);

	return result; // Return the result of the system call
}