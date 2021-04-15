#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <string.h>  
COORD coord = {0,0}; 
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
    FILE *fp, *ft; 
    char another, choice;
    struct emp
    {
        char name[40]; 
        int DOB;
        int age;
		char ms[40];
		char qualification[40];
		char employement[40]; 
        float bs; 
    };
    struct emp e; 
    char empname[40]; 
    long int recsize; 
    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
    recsize = sizeof(e);
    while(1)
    {
        system("cls"); 
        gotoxy(30,10); 
        printf("1. Add Record"); 
        gotoxy(30,12);
        printf("Your Choice: "); 
        fflush(stdin); 
        choice  = getche(); 
        switch(choice)
        {
        case '1':  
            system("cls");
            fseek(fp,0,SEEK_END); 
            another = 'y';
            while(another == 'y')  
            {
                printf("\nEnter name: ");
                scanf("%s",e.name);
                printf("\nEnter date of birth: ");
                scanf("%d", &e.DOB);
                printf("\nEnter age: ");
                scanf("%d", &e.age);
                printf("\nEnter marital status: ");
                scanf("%s",e.ms);
                printf("\nEnter academic qualifications: ");
                scanf("%s",e.qualification);
                printf("\nEnter  previous employment details: ");
                scanf("%s",e.employement);
                printf("\nEnter basic salary: ");
                scanf("%f", &e.bs);
                fwrite(&e,recsize,1,fp); 
                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
            }
            break;
        }
    }
    return 0;
}