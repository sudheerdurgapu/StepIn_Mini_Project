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
        printf("3. Modify Records");
        gotoxy(30,16);
        printf("Your Choice: "); 
        fflush(stdin); 
        choice  = getche(); 
        switch(choice)
        {
        case '3':  
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the employee name to modify: ");
                scanf("%s", empname);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)  
                {
                    if(strcmp(e.name,empname) == 0) 
                    {
                        printf("\nEnter new name,dob, age,ms,qualification,employement and bs: ");
                        scanf("%s %d %d %s %s %s %.2f",e.name,e.DOB,e.age,e.ms,e.qualification,e.employement,e.bs);
                        fseek(fp,-recsize,SEEK_CUR); 
                        fwrite(&e,recsize,1,fp); 
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        }
    }
    return 0;
}