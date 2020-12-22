#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<unistd.h>
unsigned long amount[5]={1000,10000,3000,7000,100000},pamount[10],rono,ono,ano,anum[5]={12345678,2345678,3456789,4567890,5678901},fcash[10],d[10],awith[10],deposit;
int check(int chance);
int crt_time();

int withdrawn(int count);
int balance(int count);
int deposit_cash(int count);
int fast_cash(int count);
void mini(int count,char nname[10],int rm,unsigned long rono,int flag2,int j);
int menu(int found,int count,char nname[10],char npass[10]);
char name[15];
 //   char pass[10];
int j=0;
 char nname[10],npass[10];
void hide()
{
  int i=0;
  char c=' ';
  while(i<4)
  {
  npass[i]=getch();
  c=npass[i];
  if(c==13)
    break;
  else{
    printf("*");
    i++;
  }
  }
  printf("\n");
  npass[i]='\0';
}  

typedef struct{
    char name[15];
    char pass[10];
}user;


void login(char nname[],char npass[])
{
    FILE* fp=fopen("myfile.txt","r");
    int i,found,count=0;
   
    user u[15];
    fread(u,sizeof(user),15,fp);
	 system("color E");
          printf("\n\t\t*********************************************       \n");
	sleep(1);
          printf("\n\t\t   $$$$$$<<<<<WELCOME  TO ATM>>>>>$$$$$$\n\n");
	sleep(1);
	  printf("\n\t\t*********************************************       \n");
          crt_time();
	
    printf("\n\n\n\t\t\tEnter Username :: ");
    scanf("%s",nname);
    printf("\n\n\n\t\t\tEnter Password(PIN) :: ");
    //scanf("%s",npass);
    hide();
    for(i=0;i<15;i++)
    {
        if(strcmp( nname,u[i].name)==0 && strcmp(npass,u[i].pass)==0)
	{
             count=count+1;
            found = 1;
           sleep(1);          
           printf("\n\n\t\tSuccessfully logged In.......\n");
	   sleep(3);
          system("cls");
           menu(found,count,nname,npass);  
	
           break;
        }
     
    }
}

int menu(int found,int count,char nname[10],char npass[10]){

    int i, n,m, key;
    int z,q;
    int flag,flag2,flag1,pnew,rm;
    if(found==1)
    {
          system("cls");
          system("color F1");
         sleep(1);
          printf("\n\n\t\t   *********************************************       \n");
	sleep(1);
          printf("\n\t\t       $$$$$$<<<<<WELCOME  TO ATM>>>>>$$$$$$\n\n");
	sleep(1);
	  printf("\n\t\t   *********************************************       \n\n");
	
        
        do{
        
         
          crt_time();
        printf("\n\n\n\t\t********!!!!!!!!!!<<<<<MENU>>>>>!!!!!!!!!!********\n\t");
        sleep(1);
         printf("\n\t\t       **           1.Deposit              **\n\t");
	sleep(1);
         printf("\n\t\t       **           2.Withdraw             **\n\t");
	sleep(1);
         printf("\n\t\t       **           3.CheckBalance         **\n\t");
sleep(1);
         printf("\n\t\t       **           4.Fastcash             **\n\t");
sleep(1);
         printf("\n\t\t       **           5.MiniStatement        **\n\t");
sleep(1);
         printf("\n\t\t       **           6.Transfer             **\n\t");
sleep(1);
         printf("\n\t\t       **           7.Exit                 **\n\t");
sleep(1);
          printf("\n\t\t*****************************************************       \n");

        printf("\n\n\tEnter your choice :: ");
        scanf("%d",&key);
        switch(key){
           case 1: sleep(3);
			system("cls");
			deposit_cash(count);
		    sleep(3);
   		   printf("\n\n*********************************************************************       \n");
  		   printf("\n\n\n\t\tDo You want to go to main menu\n");
			printf("\n\n\t\t1.Yes \t 2.No\n");
			printf("\n\t\tEnter :: ");
			scanf("%d",&q);
                        
 		     switch(q){
     		      case 1: sleep(2);
				system("cls");
			
			      menu(found,count,nname,npass);
			      break;
			case 2:printf("\n\n\n\t\tThank you!!!!!!\n");
				sleep(2);
                               system("cls");
                               login(nname,npass);			
                               break;
 			default:printf("Invalid choice");
		          }
			break;
                  
            case 2:sleep(3);
			system("cls");
			
		withdrawn(count);
sleep(3);
   		   printf("\n\n********************************************************************       \n");
			  printf("\n\n\n\t\tDo You want to go to main menu\n");
			printf("\n\n\t\t1.Yes \t 2.No\n");
			printf("\n\n\tEnter :: ");
			scanf("%d",&q);
                        
 		      switch(q){
     		      case 1:
				sleep(2);
			 system("cls");
			       menu(found,count,nname,npass);
			      break;
			case 2:printf("\n\n\n\tThank you!!!!!!\n");
				sleep(2);
                               system("cls");
                               login(nname,npass);			
                               break;
 			default:printf("Invalid choice");
 			}
                         
            case 3:sleep(3);
			system("cls");
		 balance(count);
sleep(3);
   		   printf("\n\n**********************************************************************       \n");
			  printf("\n\n\n\t\tDo You want to go to main menu\n");
			printf("\n\n\t\t1.Yes \t 2.No\n");
			printf("\n\n\tEnter :: ");
			scanf("%d",&q);
                        
 		     switch(q){
     		      case 1: sleep(2);
			system("cls");
			  menu(found,count,nname,npass);
			break;
			case 2:
				printf("\n\n\n\t\tThank you!!!!!!\n");
				sleep(2);
                               system("cls");
                               login(nname,npass);			
                               break;
 			default:printf("Invalid choice");
			}
                  
            case 4:sleep(3);
			system("cls");
			 fast_cash(count);
sleep(3);
   		   printf("\n\n***********************************************************************       \n");
 printf("\n\n\n\t\tDo You want to go to main menu\n");
			printf("\n\n\t\t1.Yes \t 2.No\n");
			printf("\n\n\tEnter :: ");
			scanf("%d",&q);
                        
 		     switch(q){
     		      case 1:sleep(2);
			 system("cls");
			  menu(found,count,nname,npass);
			break;
			case 2:printf("\n\n\n\n\tThank you!!!!!!\n");
				sleep(2);
                               system("cls");
                               login(nname,npass);			
                               break;
 			default:printf("Invalid choice");
			}
                
            case 5: sleep(3);
			system("cls");
			mini(count,nname,rm,rono,flag2,j);
			sleep(3);
   		   printf("\n\n************************************************************************       \n");
			   printf("\n\n\n\t\tDo You want to go to main menu\n");
			printf("\n\n\t\t1.Yes \t 2.No\n");
			printf("\n\n\tEnter :: ");
			scanf("%d",&q);
                        
 		     switch(q){
     		      case 1: sleep(2);
			system("cls");
			  menu(found,count,nname,npass);
			break;
			case 2:printf("\n\n\n\t\tThank you!!!!!!\n");
				sleep(2);
                               system("cls");
                               login(nname,npass);			
                               break;
 			default:printf("Invalid choice");
			}
                 
            case 6: sleep(3);
			system("cls");
	 system("color B4");
		  printf("\n\n\t\t   *********************************************       \n");
	sleep(1);
          printf("\n\t\t       $$$$$$<<<<<WELCOME  TO ATM>>>>>$$$$$$\n\n");
	sleep(1);
	  printf("\n\t\t   *********************************************       \n\n");
	sleep(1);
 			crt_time();
		printf("\n\t\t!!!!!!!!!!!!!!<<<! TRANSFER !>>>!!!!!!!!!!!!!!\n\n");
                        sleep(1);
			printf("\n\n\tEnter Your account number :: ");
                    scanf("%lu",&ano);
                    printf("\n\n\tEnter another account number to transfer :: ");
                    scanf("%lu",&ono);
                    printf("\n\n\tEnter amount :: ");
                    scanf("%d",&m);
                    
                    if(m%100!=0)
                    {
                        printf("\nmultiples of 100");
                       printf("\n\n\tDo you want to go to main menu");
			       printf("\n\n\t1.Yes \t 2.No :: ");
			       scanf("%d",&z);
			       switch(z)
			       {
			           case 1 : system("cls");
			                    break;
			          case 2 : system("cls");
			                   login(nname,npass);
			                   check(3);
			                   break;
			       }
                       // flag2=flag2+0;
                      //  j=j+0;
                    }
                    else if(m>amount[count])
                    {
                        printf("\nInsufficient Balance");
                        printf("\n\n\tDo you want to go to main menu");
			       printf("\n\n\t1.Yes \t 2.No :: ");
			       scanf("%d",&z);
			       switch(z)
			       {
			           case 1 : system("cls");
			                    break;
			          case 2 : system("cls");
			                   login(nname,npass);
			                   check(3);
			                   break;
			       }
                      
                   }
                    else{
                        
                        for(int i=0;i<5;i++)
                        {
                            if(anum[i]==ono && ano==anum[count])
                            {
                               flag1=1;
                              
                                break;
                            }
                        }
                        if(flag1==1)
                        {
                            rono=ono;
                            j=j+1;
                            rm=m;
                            flag2=1;
                            amount[count]=amount[count]-rm;
                            printf("\n\n\tSuccesfully Transfered\n");
                            printf("\n\n\tDo you want to go to main menu");
			       printf("\n\n\t1.Yes \t 2.No :: ");
			       scanf("%d",&z);
			       switch(z)
			       {
			           case 1 : system("cls");
			                    break;
			          case 2 : system("cls");
			                   login(nname,npass);
			                   check(3);
			                   break;
			       }
                        }
                        else{
                         printf("Invalid account number");
 printf("\n\n\tDo you want to go to main menu");
			       printf("\n\n\t1.Yes \t 2.No :: ");
			       scanf("%d",&z);
			       switch(z)
			       {
			           case 1 : system("cls");
			                    break;
			          case 2 : system("cls");
			                   login(nname,npass);
			                   check(3);
			                   break;
			       }
                              
                        }
                    }
                
                  
                    break;
          
                   
            case 7:printf("\n\n\n\t\t**** Thank youuu!!! visit again... ****\n \n \n \n");
                   sleep(2);
                   system("cls");
                   login(nname,npass);
                   
                   check(3);
                   break;
            default:printf("\n\t Your choosen option is not there \n\n");
                   sleep(1);
                   system("cls");

       
        }
        }while(key>0);
    }
   
}
int main(){
 system("cls");
 
 login(nname,npass);
 check(3); 
 return 0;
}

int crt_time() { 
  time_t t = time(NULL); 
  struct tm tm = *localtime(&t);

 printf("\n\n\n\tYear: %d - Month: %02d - Date: %02d \t hours : %02d - mins : %02d - secs : %02d\n\n\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    
 
}
int check(int chance){
    
   while(1){
    if(chance>0 && chance<=3 ){
        printf("\n\n\n\tYou only have %d chances..... \n",chance);
        
        sleep(1);
        system("cls");
        login(nname,npass);
       chance=chance-1;
    }
    else{
       printf("\n\n\n\t\tYour card has been blocked!!! Contact to the respective bank...\nThank you!!!\n \n \n");
        main();
    }

   }
}

 
int deposit_cash(int count)
{
                        sleep(1);
			 system("color E4");
          printf("\n\n\t\t   *********************************************       \n");
	sleep(1);
          printf("\n\t\t       $$$$$$<<<<<WELCOME  TO ATM>>>>>$$$$$$\n\n");
	sleep(1);
	  printf("\n\t\t   *********************************************       \n\n");
	sleep(1);
 			crt_time();
                        sleep(1);
			printf("\n\t\t!!!!!!!!!!!!!!<<<! DEPOSIT !>>>!!!!!!!!!!!!!!\n\n");
                 	sleep(1);
  			  printf("\n\n\n\t Enter amount to deposit :: ");
			scanf("%lu", &deposit);
			if(deposit%100 !=0)
			{
			    printf("\n\n\n\tDeposition money should be in the Multiples of 100 ");
			}
			else{
                         amount[count] = amount[count]+ deposit;
			printf("\n\n\t Your current balance is  %lu", amount[count]);
                        d[count]=d[count]+deposit;
			}
}
int withdrawn(int count)
{
    unsigned long withdraw;
    int flag;
	 system("color F5");		
          printf("\n\n\t\t   *********************************************       \n");
	sleep(1);
          printf("\n\t\t       $$$$$$<<<<<WELCOME  TO ATM>>>>>$$$$$$\n\n");
	sleep(1);
	  printf("\n\t\t   *********************************************       \n\n");
	sleep(1);
 			crt_time();
                        sleep(1);
			printf("\n\t\t!!!!!!!!!!!!!!<<<! WITHDRAW !>>>!!!!!!!!!!!!!!\n\n");
                 	sleep(1);
  		
    printf("\n\n\n\t Enter the amount to withdraw :: ");
		scanf("%lu", &withdraw);
			if(withdraw>10000)
			{
			    printf("\n\n\tWithdrawn amount should not exceed 10000");
			  
			}
			else if (withdraw % 100 != 0)
			{
				printf("\n\n\n\tPlease enter the amount in multiples of 100\n");
			
			}
			else if (withdraw >amount[count])
			{
				printf("\n\n\n\tInsufficient balance in your account\n");
			 
			}
			else
			{
				amount[count] = amount[count] - withdraw;
				printf("\n\n\n\t%lu is withdrawn\n",withdraw);
				printf("\n\n\n\tYour current balance is  :: %lu \n ", amount[count]);
			    printf("\n\n\n\t Please Collect Your Cash......\n\n\n");
			    awith[count]=awith[count]+withdraw;
			   
			    
			}
		
			
}
int balance(int count)
{
   	 system("color A0");	
          printf("\n\n\t\t   *********************************************       \n");
	sleep(1);
          printf("\n\t\t       $$$$$$<<<<<WELCOME  TO ATM>>>>>$$$$$$\n\n");
	sleep(1);
	  printf("\n\t\t   *********************************************       \n\n");
	sleep(1);
 			crt_time();
                        sleep(1);
			printf("\n\t\t!!!!!!!!!!!!!!<<<! BALANCE ENQUIRY !>>>!!!!!!!!!!!!!!\n\n");
                 	sleep(1);
  		
        printf("\n\n\tYour current balance is :: %lu\n\n\n",amount[count]);
     
        
}
int fast_cash(int count)
{
    int n;
	 system("color E2");		
          printf("\n\n\t\t   *********************************************       \n");
	sleep(1);
          printf("\n\t\t       $$$$$$<<<<<WELCOME  TO ATM>>>>>$$$$$$\n\n");
	sleep(1);
	  printf("\n\t\t   *********************************************       \n\n");
	sleep(1);
 			crt_time();
                        sleep(1);
			printf("\n\t\t!!!!!!!!!!!!!!<<<! FAST CASH !>>>!!!!!!!!!!!!!!\n\n");
                 	sleep(1);
  		
    printf("\n\n\n\t 1.100  \t2.500 \n\n\n\t 3.1000 \t4.5000 \n\n\n\t 5.8000 \t6.10000 \n");
    printf("\n\n\tEnter amount :: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:if(amount[count]<100)
              {
                  printf("\n\n\tInsufficient Amount in Your bank account");
              }
              else{
                amount[count]=amount[count]-100;
              
                  printf("\n\n\t100 is withdrawn \n\n\t Please Collect Your Cash....... \n\n\t THANK YOU !!!!!!!");
              
         
                fcash[count]=fcash[count]+100;
              }
                 break;
        case 2:if(amount[count]<500)
               {
                   printf("\n\n\tInsufficient Amount in your bank account");
               }
               else{
                  amount[count]=amount[count]-500;
                  printf("\n\n\t500 is withdrawn \n\n\t Please Collect Your Cash.......\n\n\t THANK YOU !!!!!!!");
               
               fcash[count]=fcash[count]+500;
               }
         
                break;
        case 3: if(amount[count]<1000)
                {
                    printf("\n\n\tInsufficient Balance\n");
                }
                else{
                   amount[count]=amount[count]-1000;
                   printf("\n\n\t1000 is withdrawn \n\n\t Please Collect Your Cash......\n\n\t THANK YOU !!!!!!!");
                    
                
                fcash[count]=fcash[count]+1000;
              
                }
                break;
        case 4: if(amount[count]<5000)
               {
                 printf("\n\n\tInsufficient Balance\n");
                }
                else{
                amount[count]=amount[count]-5000;
                
                    printf("\n\n\t5000 is withdrawn \n\n\t Please Collect Your Cash......\n\n\t THANK YOU !!!!!!!");
                
                fcash[count]=fcash[count]+5000;
                }
             
                break;
        case 5:if(amount[count]<8000){
               printf("Insufficient Balance\n");
               }
               else{
               amount[count]=amount[count]-8000;
                printf("\n\n\t8000 is withdrawn \n\n\t Please Collect Your Cash......\n\n\t THANK YOU !!!!!!!");
               
               fcash[count]=fcash[count]+8000;
               }
             
                break;
        case 6:if(amount[count]<10000)
               {
                   printf("\n\n\n\tInsufficient Balance\n");
                   
               }
               else{
               amount[count]=amount[count]-10000;
               
                   printf("\n\n\t10000 is withdrawn \n\n\t Please Collect Your Cash......\n\n\t THANK YOU !!!!!!!");
               
               fcash[count]=fcash[count]+10000;
               }
             
                break;
        default:printf("Invalid Option");
    }

    
}


void mini(int count,char nname[10],int rm, unsigned long rono,int flag2,int j)
{
     system("color D0");
      printf("\n\n\t\t   *********************************************       \n");
	sleep(1);
          printf("\n\t\t       $$$$$$<<<<<WELCOME  TO ATM>>>>>$$$$$$\n\n");
	sleep(1);
	  printf("\n\t\t   *********************************************       \n\n");
	sleep(1);
 			crt_time();
                        sleep(1);
    int a=6;
    FILE *fp;
    fp=fopen("bank.txt","a+");
    fprintf(fp,"\nAccount name:%s",nname);

               fprintf(fp,"\nAccount no. is %lu",anum[count]);
               fprintf(fp,"\n\nYou have deposited amount is %lu",d[count]);
               fprintf(fp,"\nYou have withdrawn amount is %lu",awith[count]); 
               fprintf(fp,"\nYou have withdrawn amount through fast cash is %lu",fcash[count]);
               fprintf(fp,"\nYour current balance is %lu ",amount[count]); 
             //  amount[count]=amount[count]-rm;
               if(flag2==1){
                 fprintf(fp,"\nYour latest transaction Rs %d from %lu to %lu ", rm,anum[count],rono);
              if(j>=1)
                   fprintf(fp,"\nYou have done %d transactions\n",j);
}
                else
                  fprintf(fp,"\nYou have not done any transaction ");
    fclose(fp);
    int k;
    struct detail *s;
    printf("\n\n\tDo you want the Mini statement ");
    printf("\n\n\t 1.Yes \t 2.No :: ");
    scanf("%d",&k);
    switch(k)
    {
        case 1:printf("\n\n\n\t\t!!!!!**********!!! MINI STATEMENT !!!**********\n\n");
               printf("\n\t\t!!\t Account name :: %s                            ",nname);
               printf("\n\t\t!!\t Account no. is %lu",anum[count]);
               printf("\n\t\t!!\t You have deposited amount is %lu",d[count]);
               printf("\n\t\t!!\t You have withdrawn amount is %lu",awith[count]); 
               printf("\n\t\t!!\t You have withdrawn amount through fast cash is %lu",fcash[count]);
             //  amount[count]=amount[count]-rm;
               if(flag2==1){
                 printf("\n\t\t!!\t Your latest transaction Rs %d from %lu to %lu ", rm,anum[count],rono);
               //  fprintf(fp,"\nYour latest transaction Rs %d from %lu to %lu ", rm,anum[count],rono);
               }
               if(flag2==1 && j>=1){
                   printf("\n\t\t!!\t You have done %d transactions",j);
               }
               
               else
               {
                   printf("\n\t\t!!\t You haven't performed any transaction");
               }
               printf("\n\t\t!!\t Your current balance is %lu ",amount[count]);  
               printf("\n\n\t\t  Thank You for visiting");
		
               break;
        case 2: printf("\n\n\t\t Thank you!!! \n");
               break;
        default:printf("Invalid choice");
    }
}

            
















