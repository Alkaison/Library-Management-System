/*
  Project Name: Library Management System
  Created By: GANESH MOURYA
  
  Github: https://github.com/Alkaison/Library-Management-System/
  LinkedIn: https://linkedin.com/in/Alkaison
  Twitter: https://twitter.com/Alkaison
*/
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
int searchUser(int);
void rentList(void);
void deleteUser(void);

// Book Operation Functions 
void addBook(void);
int modifyBook(int);
void listBook(void);
void rentBook(void);
int searchBook(int);
void deleteBook(void);

// Main Function 
void main(){
    password();
}

// System Functions 
    int passTerminator = 1;
    int bookStock = 0;
    char rentName[255], bookName[255];

// If the user enters invaild password 3 times then the program gets terminated.
// Password: Alkaison
void password(){

    system("cls");
    fflush(stdin);

    char pwd[255];
    char code[255] = {"Alkaison"};
    int i = 0;
	char ch;

    printf("--------------------\n");
    printf(">>> Login First <<<\n");
    printf("--------------------\n\n");

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
        (passTerminator == 3) ? exit(0) : passTerminator++;
        Sleep(2000);
        password();
    }
}

// Main Selection menu between User & Book Panel 
void menu(){
    
    system("cls");
    fflush(stdin);

    int number;

    printf("----------------------------------\n");
    printf(">>> Library Management System <<< \n");
    printf("----------------------------------\n\n");
    printf("> 1. User Management Panel \n");
    printf("> 2. Book Management Panel \n\n");
    printf("> Enter the number & hit ENTER: ");
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

// User Panel sub-functions 
void userPanel(){

    system("cls");
    fflush(stdin);

    int number;

    printf("-----------------------------------------------\n");
    printf(">>> Library Management System - User Panel <<< \n");
    printf("-----------------------------------------------\n\n");
    printf("> 1. Add User \n");
    printf("> 2. Modify User \n");
    printf("> 3. List User \n");
    printf("> 4. List Rentals \n");
    printf("> 5. Search User \n");
    printf("> 6. Delete User \n");
    printf("> 7. Open Main Menu \n");
    printf("> 8. Close the Program... \n\n");

    printf("> Enter the number & hit ENTER: ");
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
            rentList();
            break;
        case 5:
            searchUser(0);
            break;
        case 6:
            deleteUser();
            break;
        case 7:
            menu();
            break;
        case 8:
            endScreen();
            break;
        default:
            printf("Invaild Input!");
            Sleep(2000);
            userPanel();
    }
}

// Book Panel sub-functions 
void bookPanel(){

    system("cls");
    fflush(stdin);

    int number;

    printf("-----------------------------------------------\n");
    printf(">>> Library Management System - Book Panel <<< \n");
    printf("-----------------------------------------------\n\n");
    printf("> 1. Add Book \n");
    printf("> 2. Modify Book \n");
    printf("> 3. List Book \n");
    printf("> 4. Rent Book \n");
    printf("> 5. Search Book \n");
    printf("> 6. Delete Book \n");
    printf("> 7. Open Main Menu \n");
    printf("> 8. Close the Program... \n");

    printf("\nEnter the number & hit ENTER: ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            addBook();
            break;
        case 2:
            modifyBook(0);
            break;
        case 3:
            listBook();
            break;
        case 4:
            rentBook();
            break;
        case 5:
            searchBook(0);
            break;
        case 6:
            deleteBook();
            break;
        case 7:
            menu();
            break;
        case 8:
            endScreen();
            break;
        default:
            printf("Invaild Input!");
            Sleep(2000);
            bookPanel();
    }
}

// Program end credit screen - Yeah, i made it alone 
// Star the Repo on github and follow me :) 
void endScreen(){

    system("cls");
    fflush(stdin);

    printf("----------------------------------------------\n");
    printf(">>> Creator: @Alkaison (Ganesh Mourya) <<< \n");
    printf("----------------------------------------------\n\n");

    printf("> Github: https://github.com/Alkaison \n");
    printf("> Twitter: https://twitter.com/Alkaison \n");
    printf("> LinkedIn: https://www.linkedin.com/in/Alkaison \n\n");

    exit(0);
}

// User Functions 
// Creates new file if old doesn't exist and saves user records in it 
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

        printf("\n>>> User Record Added Successfully <<< \n");

    }
    else
    {
        printf("Unable to open/locate the file.");
    }

    fclose(pF); 

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

// Edit the user details and saves it 
void modifyUser(){

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    char fname1[255], lname1[255], gender1[5];
    double sid, sid1, phone, phone1;

    int compare, flag=0;

    char find[255];
    printf("Enter the name of the person you want to modify the detail: ");
    gets(find);

    fflush(stdin);

    FILE *pF = fopen("user_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        compare = strcmp(find, fname);
        if(compare == 0)
        {
            printf("\n---------------------------------------------\n");
            printf(">>> Record Found, Allowing Modifications <<<\n");
            printf("-----------------------------------------------\n\n");

            printf("> Enter First Name: ");
            gets(fname1);

            printf("> Enter Last Name: ");
            gets(lname1);

            printf("> Enter Gender: ");
            gets(gender1);

            printf("> Enter Student ID: ");
            scanf("%lf",&sid1);

            printf("> Enter Phone Number: ");
            scanf("%lf",&phone1);

            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname1, lname1, gender1, sid1, phone1);
            printf("\n\nProcessing your changes....");

            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname, lname, gender, sid, phone);
        }
    }

    fclose(pF);
    fclose(pT);

    fflush(stdin);

    pF = fopen("user_Records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>> Record Not Found <<<\n");
        printf("-------------------------------\n\n");
        printf("Redirecting to User Panel...");
    }

    pF = fopen("user_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", fname, lname, gender, sid, phone);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    fflush(stdin);

    Sleep(2000);
    userPanel();

}

// Lists all the user records from user_Records.txt file 
void listUser(){
    
    system("cls");
    fflush(stdin);
    
    FILE *pF = fopen("user_Records.txt", "r");

    char fname[255], lname[255], gender[5];
    double sid, phone;
    int counter=0;

    printf("-------------------------------\n");
    printf(">>> List of Users Record <<< \n");
    printf("-------------------------------\n\n");
    
    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
       strcat(fname, " ");
       strcat(fname, lname);

        printf("-------------------------------\n");
        printf("> Full Name: %s \n", fname);
        //printf("> Last Name: %s \n", lname); 
        printf("> Gender: %s \n", gender);
        printf("> Student-ID: %.0lf \n", sid);
        printf("> Phone No.: %.0lf \n", phone);
        printf("-------------------------------\n\n\n");

        counter++; 
    }

    fclose(pF);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("There is no user records added yet...\n");
        printf("--------------------------------------\n\n");
    }

    printf("Press any key to get back to User Panel.\n");
    getch();
    userPanel();
}

// this checks if the specified user exists in the records or not 
int searchUser(int nameSearcher){

label2:

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    double sid, phone;

    int flag=0;
    int compare;
    char find[255];

    (nameSearcher != 3) ? printf("Search by First name of the student: ") : printf("Search by First name of the student who wants to rent book: ");
    gets(find);

    FILE *pF = fopen("user_Records.txt", "r");

     while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        //strcmp(variable, variable1) -- if both the strings are equal then it will return 0 otherwise a random number.
        compare = strcmp(find, fname);

        if(compare == 0)
        {
            if(nameSearcher != 3)
            {
                strcat(fname, " ");
                strcat(fname, lname);

                printf("\n---------------------\n");
                printf(">>> Record Found <<< \n");
                printf("---------------------\n\n");

                printf("-------------------------------\n");
                printf("> Full Name: %s \n", fname);
                printf("> Gender: %s \n", gender);
                printf("> Student-ID: %.0lf \n", sid);
                printf("> Phone Number: %.0lf \n", phone);
                printf("-------------------------------\n\n");
            
            }
            strcpy(rentName, fname);
            flag=1;
        }
    }
    
    fclose(pF);

    if(flag == 0)
    {
        printf("\n>>> Record Not Found <<< \n\n");
    }

    fflush(stdin);
    
    if(nameSearcher != 3)
    {
        printf("Press any key to redirect back to Panel.");
        getch();
        userPanel();
    }
    else if(nameSearcher == 3 && flag == 1)
    {
        return 5;
    }
}

// deletes the user information from user_Records.txt file 
void deleteUser(){

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    char fname1[255], lname1[255], gender1[5];
    double sid, sid1, phone, phone1;

    int compare, flag=0;

    char find[255];
    printf("Enter the name of the person you want to delete the detail: ");
    gets(find);

    fflush(stdin);

    FILE *pF = fopen("user_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        compare = strcmp(find, fname);
        if(compare == 0)
        {
            printf("\n---------------------------------------------\n");
            printf(">>> Record Deleted <<<\n");
            printf("-----------------------------------------------\n\n");
            printf("Redirecting to User Panel...");


            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname, lname, gender, sid, phone);
        }
    }

    fclose(pF);
    fclose(pT);

    fflush(stdin);

    pF = fopen("user_Records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>> Record Not Found <<<\n");
        printf("-------------------------------\n\n");
        printf("Redirecting to User Panel...");
    }

    pF = fopen("user_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", fname, lname, gender, sid, phone);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    fflush(stdin);

    Sleep(2000);
    userPanel();
}

// Book Functions 
// add the books record in book_Records.txt file 
void addBook(){

label3:

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;

    FILE *pF = fopen("book_Records.txt", "ab+");

    if(pF != NULL)
    {
        printf("Enter Book Name: ");
        gets(name);

        printf("Enter Book Author: ");
        gets(author);

        printf("Enter Book Publisher: ");
        gets(publisher);

        fflush(stdin);

        printf("Enter Book ID: ");
        scanf("%lf",&bookid);

        printf("Enter Book Quantity: ");
        scanf("%lf",&quantity);

        fprintf(pF, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);

        printf("\n>>> Book Record Added Successfully <<< \n");
    }
    else
    {
        printf("Unable to open/locate the file.");
    }

    fclose(pF); 

    fflush(stdin);

    char input;
    printf("\nDo you wanna enter more records [y/N]: ");
    scanf("%c",&input);

    if(input == 'y' || input=='Y')
    {
        goto label3;
    }
    else if(input=='n' || input=='N')
    {
        printf("\nRedirecting to Book Panel.");
        Sleep(2000);
        bookPanel();
    }
    else
    {
        printf("\nInvaild input. Redirecting to Book Panel.");
        Sleep(2000);
        bookPanel();
    }
}

// edits the book details according to you and saves it again 
int modifyBook(int rentModifier){
    
    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;

    char name1[255], author1[255], publisher1[255];
    double bookid1, quantity1;

    int flag=0;
    int compare;
    char find[255];

    if (rentModifier != 5)
    {
        printf("Enter the name of the book you want to see the detail: ");
        gets(find);
        fflush(stdin);
    }
    else
    {
        strcpy(find, bookName);
    }
    
    FILE *pF = fopen("book_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);

        if(compare == 0)
        {
            if(rentModifier != 5)
            {
                printf("\n---------------------------------------------\n");
                printf(">>> Record Found, Allowing Modifications <<<\n");
                printf("-----------------------------------------------\n\n");

                printf("> Enter Book Name: ");
                gets(name1);

                printf("> Enter Authour: ");
                gets(author1);

                printf("> Enter Publisher: ");
                gets(publisher1);

                fflush(stdin);

                printf("> Enter Book ID: ");
                scanf("%lf",&bookid1);

                printf("> Enter Quantity: ");
                scanf("%lf",&quantity1);

                fprintf(pT, "%s %s %s %.0lf %.0lf \n", name1, author1, publisher1, bookid1, quantity1);
                printf("\n\nProcessing your changes....");
            }
            else
            {
                quantity = bookStock;
                fprintf(pT, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
            }
            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
        }
    }

    fclose(pF);
    fclose(pT);
 
    fflush(stdin); 

    pF = fopen("book_Records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>> Record Not Found <<<\n");
        printf("-------------------------------\n\n");
        printf("Redirecting to Book Panel...");
    }

    pF = fopen("book_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    if(rentModifier != 5)
    {
        Sleep(2000);
        bookPanel();
    }
}

// lists all the book record from the book_Records.txt file 
void listBook(){

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double quantity, bookid;
    int counter=0;

    FILE *pF = fopen("book_Records.txt", "r");

    printf("-------------------------------\n");
    printf(">>> List of Books Record <<< \n");
    printf("-------------------------------\n\n");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        printf("-------------------------------\n");
        printf("> Book Name: %s \n", name);
        printf("> Auhtor: %s \n", author);
        printf("> Publisher: %s\n", publisher);
        printf("> Book ID: %.0lf \n", bookid);
        printf("> Quantity: %.0lf \n", quantity);
        printf("-------------------------------\n\n\n");
        counter++;
    }

    fclose(pF);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("There is no book records added yet...\n");
        printf("--------------------------------------\n\n");
    }

    printf("Press any key to get back to Book Panel.\n");
    getch();
    bookPanel();
}

// Book Rental function
// first it checks whether the user is already registered in the user_Records.txt or not 
// second it checks whether the book exists in the book_Records.txt or not 
// third it checks if the book quantity is atleast 1, throws error if the book is OUT OF STOCK -- it also reduces book quantity by 1 from book_Recprds.txt 
// fourth it registers the user name & book name in a new file rent_Records.txt and saves it :) 
void rentBook(){

    int terminator=1, nameFound, bookFound;

label5: 

    fflush(stdin);

    // check if user exists
    nameFound = searchUser(3);

    if(nameFound != 5 && terminator != 4)
    {
        printf("Press any key to re-enter the name. \n");
        getch();
        (terminator == 3) ? bookPanel() : terminator++;
        goto label5;
    }
    else if(nameFound == 5)
    {
        printf("\nUser Found in Records! \nPlease wait... \n");
        terminator = 1;
        Sleep(2000);
    }

label6: 

    fflush(stdin);

    // check if book exists
    bookFound = searchBook(3);

    if(bookFound != 5 && terminator != 4)
    {
        printf("Press any key to re-enter the name. \n");
        getch();
        (terminator == 3) ? bookPanel() : terminator++;
        goto label6;
    }
    else if(bookFound == 5)
    {
        // check if book quantity is > 0
        if(bookStock > 0)
        {
            printf("\nBook Found & In-Stock! \nPlease wait... \n");
        }
        else
        {
            printf("\nSorry, Out of Stock! \nPlease wait... ");
            Sleep(2000);
            (terminator == 3) ? bookPanel() : terminator++;
            goto label6;
        }
    }

    fflush(stdin);

    /* printf("\n---------------------------------------------\n");
    printf("User Searcher: %d \n", nameFound);
    printf("Book Searcher: %d \n", bookFound);
    printf("User Name: %s \n", rentName);
    printf("Book Name: %s \n", bookName);
    printf("---------------------------------------------\n\n"); */

    if(nameFound == 5 && bookFound == 5)
    {
        // Adding record in rent_Records.txt file
        FILE *pF = fopen("rent_Records.txt", "ab+");

        if(pF != NULL)
        {
            fprintf(pF, "%s %s \n", rentName, bookName);
        }
        else
        {
            printf("Unable to open/locate the file.");
        }

        fclose(pF);

        // reducing quantity of book by 1 
        bookStock--;
        modifyBook(5);

        printf("---------------------------------------------\n");
        printf(">>> Rent Record Added Successfully <<< \n");
        printf("---------------------------------------------\n");

        printf("\nRedirecting to Book Panel...\n");
        Sleep(3500);
        bookPanel();
    }
}

// lists all the username & booknames which are rented to someone in registered files 
void rentList(){

    system("cls");
    fflush(stdin);
    
    char rentListUser[255], rentListBook[255];
    int counter = 0;

    FILE *pF = fopen("rent_Records.txt", "r");
    
    printf("-------------------------------\n");
    printf(">>> List of Books Rental <<< \n");
    printf("-------------------------------\n\n");

    while(fscanf(pF, "%s %s \n", rentListUser, rentListBook) != EOF)
    {
        printf("> Rent User: %s \n", rentListUser);
        printf("> Rent Book(s): %s \n\n", rentListBook);
        
        counter++;
    }

    fclose(pF);
    fflush(stdin);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("There is no rent records added yet...\n");
        printf("--------------------------------------\n\n");
    }

    printf("\nPress any key to get back to User Panel.\n");
    getch();
    userPanel();
}

// searches for the book details by book name from the txt file 
int searchBook(int bookSearcher){

label4:

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;

    int flag=0;
    int compare;
    
    char find[255];

    (bookSearcher != 3) ? printf("Serach the book by Author name or Book name: ") : printf("Serach the book by Author name or Book name: ");
    gets(find);

    FILE *pF = fopen("book_Records.txt", "r");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);
        compare = strcmp(find, author);

        if(compare == 0)
        {
            if(bookSearcher != 3)
            {
                printf("\n-------------------------\n");
                printf(">>> Record Found <<< \n");
                printf("-------------------------\n\n");

                printf("-------------------------------\n");
                printf("> Book Name: %s \n", name);
                printf("> Auhtor: %s \n", author);
                printf("> Publisher: %s\n", publisher);
                printf("> Book ID: %.0lf \n", bookid);
                printf("> Quantity: %.0lf \n", quantity);
                printf("-------------------------------\n\n");
            }
            strcpy(bookName, name);
            bookStock = quantity;
            flag=1;
        }
    }
    
    fclose(pF);
    
    fflush(stdin);
    
    if(flag == 0)
    {
        printf("\n>>> Record Not Found <<< \n\n");
    }

    if(bookSearcher != 3)
    {
        printf("Press any key to redirect to Book Panel.");
        getch();
        bookPanel();
    }
    else if(bookSearcher == 3 && flag == 1)
    {
        return 5;
    }

}

// deletes the book records from .txt file 
void deleteBook(){

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;

    char name1[255], author1[255], publisher1[255];
    double bookid1, quantity1;

    int flag=0;
    int compare;

    char find[255];
    printf("Enter the name of the book you want to delete the detail: ");
    gets(find);

    fflush(stdin);

    FILE *pF = fopen("book_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);

        if(compare == 0)
        {
            printf("\n---------------------------------------------\n");
            printf(">>> Record Deleted <<<\n");
            printf("-----------------------------------------------\n\n");
            printf("Redirecting to Book Panel...");

            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
        }
    }

    fclose(pF);
    fclose(pT);
 
    fflush(stdin); 

    pF = fopen("book_Records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>> Record Not Found <<<\n");
        printf("-------------------------------\n\n");
        printf("Redirecting to Book Panel...");
    }

    pF = fopen("book_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    Sleep(2000);
    bookPanel();
}
// Program Ends here -- Have a nice day! 
