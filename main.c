
#include "lib.h"

void banner()
{
	printf("*****************************************************\n");
	printf("*                                                   *\n");
	printf("*                Process Control Jobs               *\n");
	printf("*                     Author: Zen                   *\n");
	printf("*                                                   *\n");
	printf("*                                                   *\n");
	printf("*****************************************************\n");
}
void thankyouBanner()
{
	printf("*****************************************************\n");
	printf("*                                                   *\n");
	printf("*                   Thank You!                      *\n");
	printf("*            Your task has been completed!          *\n");
	printf("*                                                   *\n");
	printf("*****************************************************\n");
}




int main(void)
{
	/* Declare variables */
	int options = 0;
	int check_choosing = 0;
	int back = 0;
	printf("Welcome to the process management!\n");
	system("pause");
	// system("clear"); // For Unix/Linux
	system("cls"); // Clear screen (Windows)

	do
	{
		if (check_choosing == 1)
		{
		}
		else
		{
			system("cls");
			banner();
			printf("\nChoose one of the options:\n");
			printf("1. Create new task\n");
			printf("2. Show number of current tasks working\n");
			printf("3. Set up new rules\n");
			printf("4. Check connection\n");
			printf("5. Quit\n");
			printf("You are choosing: ");
		}

		// Read user input
		scanf("%d", &options);
		switch (options)
		{
		case 1:
			system("cls");
			check_choosing = 1;

			banner();
			printf("\n1.Choosing for back to the main menu ");
			printf("\n2.Insert number of task you want to create  ");
			printf("\n3.you are choosing:");
			scanf("%d", &back);
			if (back == 2)
			{
				int number_prc = 0;
				system("cls");
				banner();
				printf("\n1.Choosing for back to the main menu ");
				printf("\n2.Number of of process: ");
				scanf("%d", &number_prc);
				if (create_new_process_(number_prc) == -1)
				{
					printf("Fail to create task....");
				}
				else
				{
					printf("\nCreate successfully!\n");
				}
			}
			if (back == 1)
			{
				check_choosing = 0;
				break;
			}

			break;
		case 2:
			system("cls");
			check_choosing = 1;
			banner();
			printf("\n1.Choosing for back to the main menu ");
			printf("\n2.Insert number of task you want to create  ");
			printf("\n3.you are choosing:");
			scanf("%d", &back);

			if (back == 1)
			{
				check_choosing = 0;
				break;
			}
			printf("Showing current tasks...\n");
			// Functionality for showing current tasks goes here.
			break;
		case 3:

			system("cls");
			check_choosing = 1;
			banner();
			printf("\n1.Choosing for back to the main menu ");
			printf("\n2.Insert number of task you want to create  ");
			printf("\n3.you are choosing:");
			scanf("%d", &back);
			if (back == 1)
			{
				check_choosing = 0;
				break;
			}
			printf("Setting up new rules...\n");
			// Functionality for setting up new rules goes here.
			break;
		case 4:

			system("cls");
			check_choosing = 1;
			banner();
			printf("\n1.Choosing for back to the main menu ");
			printf("\n2.Check proxy connection ");
			printf("\n3.you are choosing:");
			scanf("%d", &back);
			if (back == 2)
			{

				char address[100];
				int port = 0;
				system("cls");
				banner();
				printf("\n1.Choosing for back to the main menu ");
				printf("\n2.Enter address: ");
				scanf("%s", address);
				printf("\n3.Enter port : ");
				scanf("%d", &port);
				if (check_proxy_connection(address, port) == 0)
				{
					printf("Connection successful!\n");
					
				}
				else
				{
					printf("Connection failed!\n");
				};
			}
			if (back == 1)
			{
				check_choosing = 0;
				break;
			}

			// Functionality for checking connection goes here.
			break;
		case 5:
			printf("Exiting the program...\n");
			break;
		default:
			check_choosing = 1;
			printf("Invalid option, please try again.\n");
		}

	} while (options != 5 || options < 0); // while loops make

	printf("You are quiting. Thanks for using");
	system("cls");
	thankyouBanner();
	return 0;
}