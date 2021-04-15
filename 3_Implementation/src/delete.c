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
        printf("4. Delete Records"); 
        gotoxy(30,18);
        printf("Your Choice: "); 
        fflush(stdin); 
        choice  = getche(); 
        switch(choice)
        {
        case '4':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of employee to delete: ");
                scanf("%s",empname);
                ft = fopen("Temp.dat","wb");  
                rewind(fp); 
                while(fread(&e,recsize,1,fp) == 1)  
                {
                    if(strcmp(e.name,empname) != 0)  
                    {
                        fwrite(&e,recsize,1,ft); 
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("EMP.DAT"); 
                rename("Temp.dat","EMP.DAT"); 
                fp = fopen("EMP.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        }
    }
    return 0;
}