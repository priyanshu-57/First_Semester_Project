#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>

void login()
{

char username[] = "user";
    char password[] = "pass";
	//	FILE *p;
    char enteredUsername[50];
    char enteredPassword[50];
   /* p=fopen("login.txt","w");
			if(p==NULL)
			{
				printf("ERROR!!...FILE COULDNOT BE OPENED");
				exit(0);
			} */
    
    printf("Enter your username: ");
    scanf("%s", enteredUsername);

    if (strcmp(enteredUsername, username) == 0) {
        printf("Enter your password: ");
        
        // Clear any remaining newline characters from the input buffer
        while (getchar() != '\n');

        // Read the password character by character without displaying them
        int i = 0;
        char ch;
        while (i<50) {
            ch = getch();  // Use getch() to read characters without echoing
            if (ch == '\n' || ch == '\r') {
                enteredPassword[i] = '\0';  // Null-terminate the password
                break;
            } else {
                enteredPassword[i++] = ch;
                printf("*");  // Display an asterisk for each character
            }
        }

        if (strcmp(enteredPassword, password) == 0) {
            printf("\nLogin successful!\n");
        	//fclose(p);
        } else {
            printf("\nLogin failed. Incorrect password.\n");
        }

        // Clear the enteredPassword array to remove the actual password from memory
       // memset(enteredPassword, 0, sizeof(enteredPassword));
    } else {
        printf("Login failed. Incorrect username.\n");
    }
}
struct contact

{

    char name[20];
	char add[20];
	char email[30];
    long ph;

} list;
    char query[20];
    char name[20];
 FILE *fp, *ft;
    int i,n,ch,l,found;
    
int main()
{


	system("cls");
	
	system("cls");
    printf("\n\n\n\n\t\t\t\t\t\t************************************************\n");
    printf("\t\t\t\t\t\t|                                               |\n");
    printf("\t\t\t\t\t\t|       ------------------------------          |\n");
    printf("\t\t\t\t\t\t|       **Contact Management System**           |\n");
    printf("\t\t\t\t\t\t|       ------------------------------          |\n");
    printf("\t\t\t\t\t\t|                                               |\n");
    printf("\t\t\t\t\t\t|                                               |\n");
    printf("\t\t\t\t\t\t|                                               |\n");
    printf("\t\t\t\t\t\t************************************************\n\n\n");
    printf(" \n\t\t\t\t Press any key to continue:");
    getch();

    system("cls"); 
	login();
	system("cls");  
main:
	                   /* ***********Main menu **********************  */

    printf("\n\n\t ** Welcome to Contact Management System **");

    printf("\n\n\n\t\t\t**MAIN MENU** ");
    printf("\n\t\t**************************");
    printf("\n\t\t[1] Add a new Contact");
    printf("\n\t\t[2] List all the Contacts");
    printf("\n\t\t[3] Search for contact");
    printf("\n\t\t[4] Edit a Contact");
    printf("\n\t\t[5] Delete a Contact");
    printf("\n\t\t[0] Exit");
    printf("\n\t\t**************************\n\t\t");
    printf("Enter your  choice Between (0-5): ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

        /* ********************Add new contacts***********  */

    case 1:

        system("cls");

        fp=fopen("contact.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("\n\n\n\tTo get exit option enter blank space in the name input");
            printf("\n\tName (Use identical):");
            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
               break;

            fflush(stdin);

            printf("\tPhone:");
            scanf("%ld",&list.ph);

            fflush(stdin);

            printf("\taddress:");
            scanf("%[^\n]",&list.add);

            fflush(stdin);

            printf("\temail address:");
            gets(list.email);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);

        break;

        /* ********************list of the contacts************************  */

    case 2:

        system("cls");

        printf("\n\t\t======================================");
        printf("\n\t\t\t **LIST OF CONTACTS** ");
        printf("\n\t\t======================================");
        printf("\n\nName\t\tPhone No\t    Address\t\tE-mail ad.");
        printf("\n=================================================================\n\n");
        
        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("contact.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,list.ph,list.add,list.email);
                    found++;

                }

            }

            if(found!=0)

            {
                printf("=================================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }

        break;

        /* ******************search contacts*********************  */

    case 3:

        system("cls");

        do

        {

            found=0;

            printf("\n\n\t\t**CONTACT SEARCH**");
            printf("\n\t\t =========================== ");
            printf("\n\t\t Name of contact to search: ");
            
            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("contact.dll","r");

            system("cls");

            printf("\n\n\t\t Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);

                    found++;

                    if (found%4==0)

                    {

                        printf("\t\t Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n\tNo match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n\tTry again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&ch);

        }
        while(ch==1);

        break;

        /**********************edit contacts************************/

    case 4:

        system("cls");

        fp=fopen("contact.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("\n\n\t\t **Edit Contact** ");
        printf("\n\n\t===============================");
        printf("\n\t Enter the name of contact to edit: ");
        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n Editing '%s'\n\n",name);

        printf("Name(Use identical):");
        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::Phone:");
         scanf("%ld",&list.ph);

        fflush(stdin);

        printf("..::address:");
        scanf("%[^\n]",&list.add);

        fflush(stdin);

        printf("..::email address:");
        gets(list.email);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.dll");

        rename("temp.dat","contact.dll");

        break;

        /* ********************delete contacts**********************/

    case 5:

        system("cls");

        fflush(stdin);

        printf("\n\n\t **DELETE A CONTACT** ");
        printf("\n\t==========================");
        printf("\n\t..::Enter the name of contact to delete:");
        scanf("%[^\n]",&name);

        fp=fopen("contact.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.dll");

        rename("temp.dat","contact.dll");

        break;

    default:

        printf("Invalid choice");

        break;

    }

    printf("\n\n\t\tEnter the Choice:");
    printf("\n\n\t\t[1] Main Menu");
    printf("\n\n\t\t[0] Exit\n");
    scanf("%d",&ch);

    switch (ch)

    {

    case 1:

        goto main;

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;

    }

    return 0;

}
