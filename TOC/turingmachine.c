// Implement Turing Machine for following language:
// L={0^n 1^n | n>=1}
// L={01,0011,000111,.........}

#include <stdio.h>
#include <conio.h>
#include <string.h>

int current=0;


void main()
{
    char inputstr[20],c;
    int i=0;
    for (i=0;i<strlen(inputstr);i++)
    {
        inputstr[i]='\0';        
    }    
    printf("Enter a input string: ");
    gets(inputstr);
    i=0;
    while(1)
    {
        c=inputstr[i];
        switch(current)
        
        {
            case 0:
            if(c=='0')
             {
                 inputstr[i]='X';
                 i++;
                    current=1;
            }
            else if(c=='Y')
            {
                i++;
                current=3;
            }
         else
            {
                current=-1;  //invalid character is encountered.
            }
             break;
    
            case 1:
         if(c==0)
            {
                i++;
                current=1;
            }
            else if(c=='Y')
            {
                i++;
                current=3;
            }  
         else
            {
                current=-1;  //invalid character is encountered.
            }
            break;  


         case 2:
         if(c==0)
         {
            i--;
            current=2;
         }
            else if(c=='Y')
         {
            i--;
            current=3;
         }
         else if(c=='X')
         {
            i++;
            current=0;
         }
            else {current=-1;}
            break;

         case 3:
            if(c=='Y')
            {
             i++;
             current=3;
             }
         else if(c=='\0')
            {
             current=4;
            }
            else {current=-1;}
         break;
        }
        if(current==-1 || current==4)
        {
            break;
        }
    }
    if(current==4)
    {
        printf("\nAccepted.");
    }
    else{
        printf("\nRejected.");
    }
    getch();

}

