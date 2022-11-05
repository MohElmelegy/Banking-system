#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_Types.h"
#include<conio.h>


#define size_of_Client 100


typedef struct
{
    u8 Name [100];
    u8 Address [100];
    u8 Age;
    u32 National_ID;
    u32 Guardian_National;
    u32 Balance;
    u32 Password ;
    u32 account_ID;


} Client;


Client arr[size_of_Client];

void main(void)
{

    u8 pointer=0;
    u8 input;
    u8 input2;
    u32 newValue;
    u8 newAge;
    u8 newName[50];
    u8  ExitFlag = 0;
    u8 ExitFlag2 =0;



    u8 Right_Username_Flag=0;
    u8 Right_PW_Flag=0;




   printf("\t   Welcome in Bank program...\n ");

    printf("\n1-Admin Window                      2-Client Window\n");

    printf("\nYour Choice: ");
    scanf(" %d",&input);

    if (input==1)
    {
        while(Right_Username_Flag==0)
        {

            char username[15];
            char password [10];

            printf("\nEnter the ****username: ");
            scanf("%s", &username);
            fflush(stdin);

            printf("\nEnter the password: ");
            scanf("%s", &password);

            if(strcmp(username, "admin") == 0)
            {

                if(strcmp(password, "admin") == 0)
                {

                    Right_Username_Flag=1;
                    //password verification also successful
                    printf("\n                        User successfully logged in...\n");
                    printf("\n***********************************\n");
                }

                else
                {
                    printf("\nPassword entered is invalid\n");
                }
            }
            else
            {
                //invalid username. Report it
                printf("\nUsername entered is invalid\n");
            }

        }
    }
    /*___________________________________________________________________*/



    if (Right_Username_Flag==1)
    {
        while(ExitFlag2==0)
        {

            printf("\nCreate New Account: 0                     Open Existing Account: 1                      To exit press to: 2\n");

            scanf(" %d",&input2);





//The Frist choose ( Create New Account )

            if(input2==0)
            {
                printf("Enter Client's Name: ");
                scanf(" %c", &arr[pointer].Name);
                fflush(stdin);
                printf("Enter Client's Addres: ");
                gets(arr[pointer].Address);
                printf("Enter Client's Age: ");
                scanf(" %d", &arr[pointer].Age);

                if (arr[pointer].Age<21)
                {
                    printf("Enter Client's Guardian National ID: ");
                    scanf(" %d", &arr[pointer].Guardian_National);

                }
                else
                {
                    printf("Enter Client's National ID: ");
                    scanf(" %d", &arr[pointer].National_ID);

                }

                printf("Enter Client's National Balance: ");
                scanf(" %d", &arr[pointer].Balance);



                arr[pointer].Password=arr[pointer].Balance+arr[pointer].Age;





                arr[pointer].account_ID=1000000000+pointer;

                printf("\n***********************************************************\n");
                printf("ID Account: %d\n", arr[pointer].account_ID);
                printf("password Acount: %d\n", arr[pointer].Password);






                pointer++;


            }




    //The second choose ( Open Existing Account )

            else if (input2==1)
            {
                u8 flag_RightID=0;
                u32 ID_Account_Test;

                printf("Enter ID Account: ");
                scanf("%d", &ID_Account_Test);

                for (u8 i=0; i<pointer; i++)
                {
                    if (ID_Account_Test== arr[i].account_ID)
                    {
                        printf("\nRight ID Account\n");
                        printf("Name: %s\n", arr[i].Name);
                        printf("Address: %s\n", arr[i].Address);
                        printf("Age: %d\n", arr[i].Age);
                        printf("Balance: %d\n", arr[i].Balance);
                        flag_RightID=1;

                        break;
                    }
                }


                if (flag_RightID==0)
                {

                    printf("Wrong ID Account");


                }




            }

        }

    }


}





