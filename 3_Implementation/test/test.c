#include<stdio.h>
#include"employee.h"
//#include "unity.h"
void setUp()
{
}
void tearDown()
{
}
void add();
void delete();
void modify();
void list();
void exit();
int main()
{
    FILE *fp, *ft; 
    char another, choice;
    struct emp
    {
        char name[40]; 
        int DOB,age;
		char ms[40];
		char qualification[40];
		char employement[40]; 
        float bs; 
    };
/*  struct emp e; 
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
    recsize = sizeof(e);*/
    switch(a)
    {
      case 1:
      add( );
      break;
      case 2:
      delete(); 
      break;
      case 3:
      modify();
      break;
      case 4:
      list();
      break;
      case 4:
      exit();
      break;

    }    
     
}