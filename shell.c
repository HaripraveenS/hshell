#include "header.h"
#include "prompt.h"
#include "cd.h"
#include "ls.h"
char * HOME;
void excecute( char **input1){
    char cmd[1000][100]; 
        // printf("ghjk%s12345" , cmd);
    int i,j,ctr = 0;
    char input[1000];
    strcpy(input, *input1);
    for(i = 0; i <= strlen(input) ; i++)
    {
        if(input[i] != ' ')
            break;

    }
    for(;i<=(strlen(input));i++)
    {
        if(input[i]==' '||input[i]=='\0' || input[i] == '\n')
        {
            cmd[ctr][j]='\0';
            ctr++;  
            j=0;   
        }
        else
        {
            cmd[ctr][j]=input[i];
            j++;
        }
    }
//    printf("%s" , cmd[0]);
    if(strcmp(cmd[0],"pwd") == 0)
    {
        // printf("ghusa");
        char cwd[1000];
        if(cmd[1] == NULL){
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("%s\n", cwd);
            }
            else {
                perror("error : pwd");   
            }
        }
        else perror("pwd:Too many arguments");
    }
    else if(strcmp(cmd[0],"cd") == 0){

        // char *dest = strtok(NULL," ");
        // printf("%s" , cmd[1]);
        go_to_dir(HOME,cmd[1]);        
        // if(chdir(cmd[1]) != 0)
        //     perror("cd : Command failed")
        //chdir(dest);

    }
    else if(strcmp(cmd[0],"ls") == 0){
        if(cmd[1][0] != '-' && cmd[2][0] != '-'){
            if(strlen(cmd[1]) == 0)
                strcpy(cmd[1] , ".");
            list_main(HOME,cmd[1],cmd[2],0  );
        }
        if(cmd[1][0] == '-'){
            if(strlen(cmd[2]) == 0)
                strcpy(cmd[2] , ".");
            if(cmd[1][1] == 'l'){
                if(cmd[1][2] == 'a'){
                    list_l(HOME, cmd[2], 1);
                }
                else
                    list_l(HOME, cmd[2], 0);
            } 
            if(cmd[1][1] == 'a'){
                if(cmd[1][2] == 'l')
                    list_l(HOME, cmd[2], 1);
                else list_basic(HOME,cmd[2],1);
            }


            
        }
        if(cmd[2][0] == '-'){
            printf("ghusa");
            if(strlen(cmd[1]) == 0)
                strcpy(cmd[1] , ".");
            if(cmd[2][1] == 'l'){
                printf("ghusa");
                if(cmd[2][2] == 'a'){
                    printf("%s" , cmd[1]);
                    list_l(HOME, cmd[1], 1);
                }
                else
                    list_l(HOME, cmd[1], 0);
            } 
            if(cmd[2][1] == 'a'){
                if(cmd[2][2] == 'l')
                    list_l(HOME, cmd[1], 1);
                else list_basic(HOME,cmd[1],1);
            }


            
        }
        
        
    }

}


int main(int argc, char const *argv[]){

HOME = getcwd(NULL, 0);
permissions("shell.c");

//printf("ghjk");
char * temp_1 = getcwd(HOME, sizeof(HOME));

while(1){
  //  printf("56");
    print_prompt(HOME);
    char *input;
    size_t size_i = 32;
    input = (char *)malloc(size_i * (sizeof(char)));
    int check_in;
    check_in = getline(&input, &size_i , stdin);
    excecute(&input);


}



return 0;
}