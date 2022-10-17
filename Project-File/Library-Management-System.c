// Pre-Defined Header Files
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

// Define Constant KeyWords 
#define ENTER 13
#define TAB 9
#define BKSP 8

// System Operation Functions 
void password(void);
void menu(void);
void userPanel(void);
void bookPanel(void);
void endScreen(void);

// User Operation Functions 
void addUser(void);
void modifyUser(void);
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

// System Functions 

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
    fflush(stdin);
    // verifies the password 
    if(strcmp(code, pwd) == 0)
    {
        printf("\nCorrect Password!");
        Sleep(2000);
        menu();
    }
    else
    {
        printf("\nInvaild Password!");
        Sleep(2000);
        password();
    }
}

void menu(){
    
    system("cls");

    int number;

    printf(">>> Library Management System <<< \n");
    printf("> 1. User Panel \n");
    printf("> 2. Book Panel \n");
    printf("\nEnter the number & hit ENTER: ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            userPanel();
            break;
        case 2:
            bookPanel();
            break;
        default:
            printf("\n>>> Invaild Input! <<<");
            Sleep(2000);
            menu();
    }
}

void userPanel(){

    system("cls");

    int number;

    printf(">>> Library Management System <<< \n");
    printf("> 1. Add User \n");
    printf("> 2. Modify User \n");
    printf("> 3. List User \n");
    printf("> 4. Search User \n");
    printf("> 5. Delete User \n");
    printf("> 6. Close the Program... \n");

    printf("\nEnter the number & hit ENTER: ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            addUser();
            break;
        case 2:
            modifyUser();
            break;
        case 3:
            listUser();
            break;
        case 4:
            searchUser();
            break;
        case 5:
            deleteUser();
            break;
        case 6:
            endScreen();
            break;
        default:
            printf("Invaild Input!");
            Sleep(2000);
            userPanel();
    }
}

void bookPanel(){

    system("cls");

    int number;

    printf(">>> Library Management System <<< \n");
    printf("> 1. Add Book \n");
    printf("> 2. Modify Book \n");
    printf("> 3. List Book \n");
    printf("> 4. Rent Book \n");
    printf("> 5. Search Book \n");
    printf("> 6. Delete Book \n");
    printf("> 7. Close the Program... \n");

    printf("\nEnter the number & hit ENTER: ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            addBook();
            break;
        case 2:
            modifyBook();
            break;
        case 3:
            listBook();
            break;
        case 4:
            rentBook();
            break;
        case 5:
            searchBook();
            break;
        case 6:
            deleteBook();
            break;
        case 7:
            endScreen();
            break;
        default:
            printf("Invaild Input!");
            Sleep(2000);
            bookPanel();
    }
}

void endScreen(){

    system("cls");

    printf(">>> Library Management System in C <<< \n\n");
    printf("> Creator: @Alkaison (Ganesh Mourya) \n\n");
    printf("> Github: https://github.com/Alkaison \n");
    printf("> Twitter: https://twitter.com/Alkaison \n");
    printf("> LinkedIn: https://www.linkedin.com/in/Alkaison \n\n");
    printf("Press any key to exit.\n");

    getch();
}

// User Functions 

void addUser(){
    
label1:
    
    system("cls");
    fflush(stdin);

    char fname[255], lname[255]; 
    char gender;
    double sid, phone, balance;

    FILE *pF = fopen("user_Records.txt", "ab+");

    if(pF != NULL)
    {
        printf("Enter the First Name: ");
        gets(fname) ;

        printf("Enter the Last Name: ");
        gets(lname);

        printf("Enter Gender [M/F]: ");
        scanf("%c",&gender);

        printf("Enter Student ID: ");
        scanf("%lf",&sid);

        printf("Enter Phone Number: ");
        scanf("%lf",&phone);

        fprintf(pF, "%s %s %c %.0lf %.0lf \n", fname, lname, gender, sid, phone);

    }
    else
    {
        printf("Unable to open/locate the file.");
    }

    fclose(pF); 

    printf("\n>>> User Record Added Successfully <<< \n");

    fflush(stdin);

    //retry screen
    char input;
    printf("\nDo you wanna enter more records [y/N]: ");
    scanf("%c",&input);

    if(input == 'y' || input=='Y')
    {
        goto label1;
    }
    else if(input=='n' || input=='N')
    {
        printf("\nRedirecting to User Panel.");
        Sleep(2000);
        userPanel();
    }
    else
    {
        printf("\nInvaild input. Redirecting to User Panel.");
        Sleep(2000);
        userPanel();
    }
}

void modifyUser(){

}

void listUser(){

}

void searchUser(){

}

void deleteUser(){

}

// Book Functions

void addBook(){

}

void modifyBook(){

}

void listBook(){

}

void rentBook(){

}

void searchBook(){

}

void deleteBook(){

}