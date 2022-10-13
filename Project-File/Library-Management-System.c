// Pre-Defined Header Files
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

// Define Constant KeyWords 
#define ENTER 13
#define TAB 9
#define BKSP 8

// Function Prototypes
void password(void);
void menu(void);

// User Operation Functions 
void addUser(void);
void modifyuser(void);
void listUser(void);
void searchUser(void);
void deleteUser(void);

// Book Operation Functions 
void addBook(void);
void modifyBook(void);
void listBook(void);
void rentBook(void);
void searchBook(void);
void deleteBook(void);

// Main Function 
int main(){

    password();
    return 0;
}

void password(){

    system("cls");

    char pwd[255];
    char code[255] = {"Alkaison"};
    int i = 0;
	char ch;

	printf("Enter your password. Hit ENTER to confirm. \n");
	printf("Password:");

	while(1)
    {

		ch = getch(); // get key

		if(ch == ENTER || ch == TAB)
        {
			pwd[i] = '\0';
			break;
		}
        else if(ch == BKSP)
        {
			if(i > 0)
            {
				i--;
				printf("\b \b"); // for backspace
			}
		}
        else
        {
			pwd[i++] = ch;
			printf("* \b");	// to replace password character with * 
		}
	}

	// printf("\n\nPassword:%s\nLength:%d\n\n", pwd, i);  -- prints the user input & lenght of string 

    // verifies the password 
    if(strcmp(code, pwd) == 0)
    {
        printf("\nCorrect Password!");
        Sleep(2000);
    }
    else
    {
        printf("\nInvaild Password!");
        Sleep(2000);
        password();
    }
}