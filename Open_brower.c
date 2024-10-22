#include "lib.h"

// size_t writeCallBack()
// {
// 	CURL *curl;
// 	return 0;
// }

int Open_browser(const char *url)
{
	if (url == NULL)
	{
		return -1; // Return -1 if the URL is NULL
	}

	// Validate URL (simple check; more robust validation can be added)
	if (strlen(url) == 0 || (strstr(url, "http://") == NULL && strstr(url, "https://") == NULL))
	{
		return -2; // Invalid URL format
	}

	// Determine the size needed for the command string
	size_t command_size = strlen(url) + 20; // Extra space for the platform-specific command

	// Dynamically allocate memory for the command string
	char *command = (char *)malloc(command_size);
	if (command == NULL)
	{
		return -3; // Memory allocation failed
	}

#ifdef _WIN32
	// Windows: Use "start"
	strcpy(command, "start \"\" ");
#elif __APPLE__
	// macOS: Use "open"
	strcpy(command, "open ");
#elif __linux__
	// Linux: Use "xdg-open"
	strcpy(command, "xdg-open ");
#else
	free(command);
	return -4; // Unsupported platform
#endif

	// Concatenate the URL to the command string
	strcat(command, url);

	// Execute the command
	int result = system(command);

	// Free the allocated memory
	free(command);

	// Check the result of the system call
	if (result == -1)
	{
		return -5; // Failed to execute command
	}

	return 0; // Return 0 for success
}