
void print_prompt(char *home){
    // printf("ghjk");
    char username[100];
    struct utsname uts;
    char* curr = getcwd(NULL , 0);
    // printf("%s" , curr) ;
    int i;
    int flg = 1;
    for (i = 0; i < strlen(home); i++)
    {
       if(home[i] != curr[i])
            flg = 0;
    }
    // printf("%s\n" , curr);
    char curr1[500];
    if(flg  == 1){
        
        curr1[0] = '~';
        int index = 1;
        for(i = strlen(home); i < strlen(curr) ; i++)
            curr1[index++] = curr[i];
        strcpy(curr,curr1);
    }
    // printf("%s\n" , curr1);
    if (getlogin_r(username, 100) == 0){
        if (uname(&uts) == 0){
                printf("%s@%s:%s $ " , username, uts.nodename, curr);
                // print_path();
        }       
    }

}

