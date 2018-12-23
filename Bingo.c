#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 int bingo[10][10],clcount=0,mbcount,call[3000];
 void Matrix()
 {
     mbcount++;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            bingo[i][j]=rand()%1000;


    }
 }
void print(int a[10][10])
{

 for(int i=0;i<10;i++)
    {
        printf("\n");
        if(i==1)
            printf("B\n");
        else if(i==3)
            printf("I\n");
        else if(i==5)
            printf("N\n");
        else if(i==7)
            printf("G\n");
        else if(i==9)
            printf("O\n");
        else
            printf("\n");
        printf("\t");
        for(int j=0;j<10;j++)
        {
                if(i==5&&j==5)
                {
                    printf("FREE\t");
                }
                else
                    printf("%d\t",a[i][j]);
        }

    }
}
int generate()
{
     int x=rand()%1000,y=0;
     while(y<=clcount)
     {
     if(x==call[y])
        generate();
     y++;
     }

     call[clcount]=x;
     printf("%d\n",call[clcount]);
     clcount++;
    return clcount;
}
void printcall()
{

}
int main()
{
    int ch,k=0;
    while(k==0)
    {
        printf("Please Select The option from the List below:\n 1: Get Sheet \n 2: Call Number \n 3: List all CALLED Numbers \n 4: Display the number of Players \n 5: GAME RULES \n 6: Exit \n ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                Matrix();
                print(bingo);
                printf("\n");
                break;
            case 2:
                printf("The Number is: \n");
                clcount=generate();
                printf("\n");
                break;
            case 3:
                    printf("The numbers called out so far are: \n");
                    for(int i=0;i<clcount;i++)
                       {
                         printf("\t\t%d\n",call[i]);
                       }
                    printf("No. of Numbers called out = %d\n",clcount);
                    printf("So please check if you got all your numbers crossed off\n");
                    printf("\n");
                    break;
            case 4:printf("No. of playing members = %d\n",mbcount);
                    printf("\n");
                    break;
            case 5:printf("Each bingo card contains 99 numbers and a blank square, situated on a 10 by 10 grid.\n When the game starts, random numbers are drawn and whoever of the players participating in the game completes a bingo pattern first,\n wins the prize (10 lines with ten numbers in diagonal, horizontal or vertical row).\n The numbers on the cards are randomly assigned to the squares on the card.\n Each player will be assigned a random card.\n Every card is unique and there are series of 6000 and even 9000 unique cards available.\n In other words, there is no way two players to have identical cards.\nDuring the bingo game random numbers are drawn and announced by the caller.\n After a number is announced, every player needs to check his bingo card/s for the announced number and if he has it on one or more of his cards - he needs to mark it accurately on the cards where the number is present.\n This is done until one or more players claim BINGO.\n Then the game stops, the numbers are verified and the prize is given to the winner.\n");
                    break;
            case 6:exit(0);
            default:printf("INVALID SELECTION! PLEASE TRY AGAIN:\n");
                    break;
        }
    }

    return 0;
}
