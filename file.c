#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int l=0;
void signup();
void login(char name[],char pass[]);
//int register=0;
typedef struct{
    char name[15];
    char pass[10];
}user;
int main(char name[],char pass[])
{
    int q;
   
    do{
     printf("1.S 2.L");
    scanf("%d",&q);
    switch(q){
        case 1 :signup();
                break;
        case 2 : login(name,pass);
                break;
                
        default: printf("invalid");
    }
    }while(q>0);
  
    return 0;
}
	
void signup()
{
    int registerchoice;
    char name[15];
    char pass[10];
    char cpass[10];
    int match,l;
    printf("\nEnter Username");
    scanf("%s",name);
    printf("\nEnter pass");
    scanf("%s",pass);
    printf("\nconfirm password");
    scanf("%s",cpass);
    if(strcmp(pass,cpass)==0)
    {
        FILE *fp=fopen("myfile.txt","a+");
        if(fp==NULL)
        {
            printf("Error");
            
        }
        user u;
        strcpy(u.name,name);
        strcpy(u.pass,pass);
        fwrite(&u,sizeof(user),1,fp);
        fclose(fp);
        //register=1;
        printf("Account success");
    }
}
void login(char name[],char pass[])
{
    FILE* fp=fopen("myfile.txt","r");
    int i,l,flag;
    char nname[10],npass[10];
    user u[15];
    fread(u,sizeof(user),15,fp);
    printf("Enter user");
    scanf("%s",nname);
    printf("Pass");
    scanf("%s",npass);
    for(i=0;i<15;i++)
    {
        if(strcmp( nname,u[i].name)==0 && strcmp(npass,u[i].pass)==0){
            flag=0;
            l=1;
            printf("\nlogin success");
            
        }
    }
}

