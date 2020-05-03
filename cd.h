void go_to_dir(char * home, char *cmd){

    // printf("%ld" , strlen(cmd)); 
    char temp[1000];
    if(strlen(cmd) == 0){
        if(chdir(home) != 0)
            perror("cd : Error");
        return;
    }
    if(cmd[0] == '~'){
        strcpy(temp,home);
        int i,len = strlen(home);
        
        for(i = 1;i < strlen(cmd);i++){
            temp[len++] = cmd[i];
        }

        strcpy(cmd,temp);
    }

    if(chdir(cmd) != 0)
        perror("cd : directory doesn't exit");


}