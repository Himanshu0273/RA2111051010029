#include <stdio.h>
#include <math.h>

/*
restraurant management system:-

display menu with number
using item number place order 
make bill according to the dishes selected
give any discounts if possible 
signup for membership or check if you have any

*/

int s=0,hadmem=0;
float discount,newcost;
void menu() //menu of the restaurant
    {
         printf("\n\t\t\t\t**** WELCOME TO RESTAURANT ****\n\n");
        printf("\nMENU CARD\n");
        printf("\n\tPRODUCT\t\t\t\tPRICE\n\n1. ORANGE JUICE\t\t\t\tRs.20.00\n2. MILK SHAKE\t\t\t\tRs.50.00\n3. COFFEE\t\t\t\tRs.30.00\n4. Pasta\t\t\t\tRs.100.00\n5. Pizza\t\t\t\tRs.140.00\n\nSELECT ANYONE : ");
    
    }
int order() // customer's order and get basic bill
    {
        int price,order = 1;
        extern int s;
        while (order == 1)
        {
            printf ("Now type the item id to select:- ");
            int ono,qty;
            scanf ("%d",&ono);
            switch (ono)
                {
                    case 1:
                        printf("ORANGE JUICE SELECTED, PLEASE! Enter the Quantity : ");
                        scanf("%d", &qty);
                        price = qty * 20;
                        s = s + price;
                        printf("Total Amount For Pay : %d\n", price);
                        break;
                    case 2:
                        printf("MILK SHAKE SELECTED, PLEASE! Enter the Quantity : ");
                        scanf("%d", &qty);
                        price = qty * 50;
                        printf("Total Amount For Pay : %d\n", price);
                        s = s + price;
                        break;
                    case 3:
                        printf("COFFEE SELECTED, PLEASE! Enter the Quantity : ");
                        scanf("%d", &qty);
                        price = qty * 30;
                        printf("Total Amount For Pay : %d\n", price);
                        s = s + price;
                        break;
                    case 4:
                        printf("PASTA SELECTED, PLEASE! Enter the Quantity : ");
                        scanf("%d", &qty);
                        price = qty * 100;
                        printf("Total Amount For Pay : %d\n", price);
                        s = s + price;
                        break;
                    case 5:
                        printf("PIZZA SELECTED, PLEASE! Enter the Quantity : ");
                        scanf("%d", &qty);
                        price = qty * 140;
                        printf("Total Amount For Pay : %d\n", price);
                        s = s + price;
                        break;
                    default:
                        printf("Thank you for ordering.");
                        order = 0;
                        break;
                }
        }
        printf ("\nTotal Bill(without discount) = %d\n",s);
        return s;
    }
int membership() //check if customer has membership or not
    {
        int check,wantmem;
        extern int hadmem ;
        char name[100];
        long int pno;
        printf ("Do you have a membership?\nPress '1' for yes and '0' no.\n");
        scanf ("%d",&check);
        if (check == 1)
            {
                printf ("You are entitled to 20 percent discount.\n");
                hadmem = 1;
            }
        else if (check == 0)
            {   
                printf ("Do you want a membership?\nFor yes enter '1' and get an instant discount of 30 percent and a normal 20 percent from next time or enter '0' for no.\n");
                scanf ("%d",&wantmem);
                if (wantmem == 1)
                    {
                        printf ("Thank you for becoming a new member!\n");
                        printf ("Enter your name : ");
                        scanf ("%s",name);
                        printf ("\nEnter your phone number : ");
                        scanf ("%ld",&pno);
                        printf ("\nPlease pay Rs.500 extra to the total bill to become a member.\n");
                        hadmem = 2;
                    }
                else
                    hadmem = 0;
            } 
        else
            printf ("Wrong choice");
        return hadmem;
    }
int new_bill() //New bill that is to be paid.
    {
        extern float discount,newcost;
        extern int s,hadmem;
        if (hadmem == 1)        
            {
                discount = (20.0/100.0) * s;
                newcost = s - discount;
            }
        else if (hadmem == 2)
            {
                discount = (30.0/100) * s;
                newcost = s - discount + 500;
            }
        else    
            newcost = s;
        
        printf ("Your Final Bill is :- Rs.%0.2f .\n",newcost);
        printf ("We hope you liked our service and food and we hope to see you again");
        
        return 0;
    }

int main ()
    {
        menu();
        order();
        membership();
        new_bill();
        return 0;
    }