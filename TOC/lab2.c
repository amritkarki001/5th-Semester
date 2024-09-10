//WAP to Implement following DFA accepting L={w | w=>{0.1}*, |w|>=2 }
void main()
{
    char w[20];
    int i,len;
    char cur_state='0',c;
    printf("Enter a string:");
    gets(w);
    len=strlen(w);
    for(i=0; i<len; i++)
    {
        c=w[i];
        switch(cur_state)
        {
            case '0': cur_state='1'; break;
            case '1': cur_state='2'; break;
            case '2': cur_state='2';
            default: printf("Invalid state!!");
            getch();
            return;
        }
    }
    if(cur_state=='2')
    {
        printf("\nString accepted.\n");
    }
    else{printf("\nString rejected...");}
}