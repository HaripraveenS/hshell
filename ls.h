
void list_basic(char * home,char * cmd, int a){
    // printf("ghusa");
    struct dirent *de;  
    // printf("%s" , cmd);
    DIR *dr = opendir(cmd); 
  
    if (dr == NULL)  
    { 
        printf("Could not open current directory" ); 

    } 
    while ((de = readdir(dr)) != NULL) 
        if(de->d_name[0] != '.' || a)
            printf("%s\n", de->d_name); 
  
    closedir(dr);     


}
void permissions(char *file){
    
    struct stat st,buf;
    char *time = (char *)malloc(100*sizeof(char));
	char *month = (char *)malloc(100*sizeof(char));
	char *day = (char *)malloc(100*sizeof(char));
	char *ti = (char *)malloc(100*sizeof(char));
    char *modeval = malloc(sizeof(char) * 9 + 1);
    char s;
    if(S_ISREG(st.st_mode))
        s = '-';
    else if(S_ISDIR(st.st_mode))
        s = 'd';
    else if(S_ISCHR(st.st_mode))
        s = 'c';
    else if(S_ISBLK(st.st_mode))
        s = 'b';
    else if(S_ISFIFO(st.st_mode))
        s = 'f';
    else if(S_ISLNK(st.st_mode))
        s = 'l';
    else
        s = 's';
    if(stat(file, &st) == 0){
        mode_t perm = st.st_mode;
        modeval[0] = (perm & S_IRUSR) ? 'r' : '-';
        modeval[1] = (perm & S_IWUSR) ? 'w' : '-';
        modeval[2] = (perm & S_IXUSR) ? 'x' : '-';
        modeval[3] = (perm & S_IRGRP) ? 'r' : '-';
        modeval[4] = (perm & S_IWGRP) ? 'w' : '-';
        modeval[5] = (perm & S_IXGRP) ? 'x' : '-';
        modeval[6] = (perm & S_IROTH) ? 'r' : '-';
        modeval[7] = (perm & S_IWOTH) ? 'w' : '-';
        modeval[8] = (perm & S_IXOTH) ? 'x' : '-';
        modeval[9] = '\0';
     
    }

    printf("%c%s " , s,modeval);

    lstat(file,&buf);
    printf("%ld " , buf.st_nlink);
    
    struct passwd *pwd;
    pwd = getpwuid(buf.st_uid);
    printf("%s ", pwd->pw_name);
    struct group *group_id= getgrgid(buf.st_gid);
    printf("%s " , group_id->gr_name);
    printf("%ld ",buf.st_size);
    strcpy(time, ctime(&buf.st_mtime));
	int i=0, l1=0;
	while(time[i]!=' ')
		i++;
	i++;
	while(time[i]!=' ')
		month[l1++] = time[i++];
	month[3] = '\0';
	i++;
	l1=0;
	while(l1<2)
	{	
		day[l1++] = time[i++];
	}
	day[2] = '\0';
	i++;
	l1=0;
	while(l1<5)
		ti[l1++] = time[i++];
	ti[5] = '\0';
    int index = 0;
    for(i = strlen(file) - 1;i >=0 ; i--)
        if(file[i] == '/'){
            index = i;
            break;
        }
    // for (i = index; i < strlen(file); i++)
    // {
    //     /* code */
    // }
    // printf("%s\n\n" , file);
    printf("%s %s %s %s\n" , month,day,ti,&(file[index+ 1]));
}
    // printf("\t%s",di->d_name);



void list_l(char * home,char * cmd, int a){
    char temp[1000];
    if(cmd[0] == '~'){
        strcpy(temp,home);
        int i,len = strlen(home);
        
        for(i = 1;i < strlen(cmd);i++){
            temp[len++] = cmd[i];
        }

        strcpy(cmd,temp);
    }
    struct dirent *de;  
    // printf("%s" , cmd);
    DIR *dr = opendir(cmd); 
  
    if (dr == NULL)  
    { 
        printf("Could not open current directory" ); 

    } 
    char temp1[1000];
    while ((de = readdir(dr)) != NULL) 
        if(de->d_name[0] != '.' || a){
            strcpy(temp1,cmd);
            strcat(temp1,"/");
            strcat(temp1,de->d_name);
            // printf("%s \n" , temp1);
            // strcpy(temp1,de->d_name);
            permissions(temp1);

        }
  
    closedir(dr);  

}


void list_main(char * home , char * cmd , char * arg , int a){

    char temp[1000];
    if(cmd[0] == '~'){
        strcpy(temp,home);
        int i,len = strlen(home);
        
        for(i = 1;i < strlen(cmd);i++){
            temp[len++] = cmd[i];
        }

        strcpy(cmd,temp);
    }
    // printf("%s %s"  , cmd , arg);
    if(strlen(arg) == 0)
        list_basic(home,cmd,a);



}
