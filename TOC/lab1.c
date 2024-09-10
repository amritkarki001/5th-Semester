//WAP TO TAKE STRING AS INPUT AND PRINT ITS SUFFIXES
/*
INPUT: apple
OUTPUT: 
apple
pple
ple
le
e 
*/
 
#include <string.h>
#include<conio.h>
#include<stdio.h>

void printsuffix(char[]);
void printprefix(char[]);

void main()
{
    char str[20];
    printf("Enter a word: ");
    gets(str);
    printsuffix(str);
    printf("\n---------------------------\n");
    printprefix(str);
}

void printsuffix(char w[])
{
    int len=strlen(w);
    int i,j;
    for(i=0; i<len; i++)
    {
        for(j=i; j<len; j++)
        {
            printf("%c",w[j]);
        }
    printf("\n");
    }
}


void printprefix(char w[])
{
    int len=strlen(w);
    int i,j;
    for(i=len; i>=0; i--)
    {
        for(j=0; j<=i; j++)
        {
            printf("%c",w[j]);
        }
        printf("\n");
    }
}
