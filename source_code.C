#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

void add();  
void list();
void edit();  
void delete1();
void search();
void bill(int , int);

void login()
{

    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10];
    char user[10]="user";
    char pass[10]="password";
    do
    {
	system("cls");
	printf("\n  **************************  LOGIN FORM  **************************  ");
	printf(" \n\n\n                     ENTER USERNAME:-	");
	scanf("%s", &uname);
	printf(" \n                     ENTER PASSWORD:-	");
	for(i=0;i<10;i++)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13)
		break;
	    else if((i) && c==8)
	    {
		printf("\b");
		i-=2;
	    }
	    else
		printf("*");
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
		printf("\n\n\n     WELCOME !!!! LOGIN IS SUCCESSFUL");
		printf("\n\n\n  ******************************************************************  ");
		printf("\n\n     Press any key to continue: ");
		getch();
		break;
	}
	else
	{
		printf("\n\n\n     SORRY !!!! LOGIN IS UNSUCESSFUL");
		printf("\n\n\n  ******************************************************************  ");
		printf("\n\n     PLEASE TRY AGAIN \n");
		a++;
		getch();
	}
    }
    while(a<=2);
	if (a>2)
	{
		printf("\n\n\n  ******************************************************************  ");
		printf("\n\n     Sorry! You have entered the wrong username and password too many times!!!");
		getch();
		exit(0);
	}
	system("cls");
}

struct CustomerDetails   
{
	char custid[10];
	int bookno;
	char name[20];
	char address[25];
	char phonenumber[15];
	char email[20];
	int roomno;
	int period;
	char arrivaldate[10];
}s, sr;

int main(){     
	int i=0;
	char choice;
	time_t t;
	time(&t);
	system("cls");   
	printf(" \n\n\n");
	for(i=0;i<80;i++)
	printf("-");
	printf("\n\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*    ------------------------------------       *\n");
	printf("\t\t*     WELCOME TO HOTEL MANAGEMENT SYSTEM        *\n");
	printf("\t\t*    ------------------------------------       *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*     Brought To You By Team-1 (MPHT)           *\n");
	printf("\t\t*     MANIPAL UNIVERSITY JAIPUR                 *\n");
	printf("\t\t*     CONTACT US: 12-3456 7890                  *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*************************************************\n\n\n");
	for(i=0;i<80;i++)
		printf("-");
	printf("\n Current date and time : %s",ctime(&t));
	for(i=0;i<80;i++)
		printf("-");
	printf(" \n Press any key to continue: ");
	getch();
	system("cls");
	login();
	system("cls");
	while (1)     
	{
		system("cls");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\t\t *Please Enter your Choice for Menu*:");
		printf("\n\n");
		printf("\n Enter 1 -> Create a Customer Record OR Book a Room");
		printf("\n---------------------------------------------------");
		printf("\n Enter 2 -> View all Customer/Booking Records");
		printf("\n---------------------------------------------");
		printf("\n Enter 3 -> Delete a Customer Record (All Bookings)");
		printf("\n---------------------------------------------------");
		printf("\n Enter 4 -> Search a Customer/Booking Record OR Print the Bill");
		printf("\n--------------------------------------------------------------");
		printf("\n Enter 5 -> Edit a Customer/Booking Record");
		printf("\n------------------------------------------");
		printf("\n Enter 6 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
			printf("-");
		printf("\nCurrent Date and Time : %s",ctime(&t));
		for(i=0;i<80;i++)
			printf("-");
		choice=getche();
		getch();
		 choice=toupper(choice);
		switch(choice)
		{
			case '1':
				add(); break;
			case '2':
				list(); break;
			case '3':
				delete1(); break;
			case '4':
				search(); break;
			case '5':
				edit(); break;
			case '6':
				system("cls");
				printf("\n\n\t ******THANK YOU******");
				printf("\n\t FOR USING OUR PROGRAM");
				exit(0);
				break;
			default:
				system("cls");
				printf("\n Incorrect Input");
				printf("\n\n\n Press any key to continue: ");
				getch();
		}
	}
}

void add()
{
	FILE *f;
	char test, c, c_id[20];
	int flag;
	f=fopen("add.txt","a+");
	if(f==0)
	{
		system("cls");
		printf("NO Database Found!!");
		printf("\nPlease hold on while we set our database in your computer!!");
		f=fopen("add.txt","w+");
		system("cls");
		printf("\nProcess completed press any key to continue...");
		getch();
	}
	while(1)
	{
	while(1)
	{
		system("cls");
		printf("\nEnter Customer Details:");
		printf("\n**************************");
		printf("\nNew Customer?");
		printf("\nEnter Y/N:\t");
		scanf("%s",&c);
		if(c=='Y' || c=='y')
		{
			printf("\nEnter The Freshly Alloted Customer ID:\t");
			scanf("%s",s.custid);
			printf("Enter Name:\t");
			scanf("%s[^\n]%*c",s.name);
			fflush(stdin);
			printf("Enter Address:\t");
			scanf("%s[^\n]%*c",s.address);
			fflush(stdin);
			printf("Enter Phone Number:\t");
			scanf("%s",s.phonenumber);
			printf("Enter Email:\t");
			scanf("%s",s.email);
			s.bookno=1;
			break;
		}
		else if(c=='N' || c=='n')
		{
			flag=0;
			printf("\nEnter Existing Customer ID:\t");
			scanf("%s", c_id);
			printf("\n\nPlease wait while we check the database for the Customer ID...");
			fseek(f,0,SEEK_SET);
			while(fread(&s,sizeof(s),1,f)==1)
			{
				if(strcmp(s.custid,c_id)==0)
				{
					flag++;
					if(flag>1)
					{
						sr.bookno++;
						continue;
					}
					printf("\n\nRecord for the Customer ID:  %s  exists!!\n", s.custid);
					strcpy(sr.custid,s.custid);
					strcpy(sr.name,s.name);
					strcpy(sr.address,s.address);
					strcpy(sr.phonenumber,s.phonenumber);
					strcpy(sr.email,s.email);
					sr.bookno=s.bookno;
					sr.bookno++;
				}
			}
			if(flag>0)
			{
				fseek(f,0,SEEK_END);
				strcpy(s.custid,sr.custid);
				strcpy(s.name,sr.name);
				strcpy(s.address,sr.address);
				strcpy(s.phonenumber,sr.phonenumber);
				strcpy(s.email,sr.email);
				s.bookno=sr.bookno;
				printf("\n\nPress any key to continue...");
				getch();
			}
			if(flag==0)
			{
				printf("\n\nRecord for the Customer ID:  %s  does not exist!!\n", c_id);
				printf("\n\nPlease create a new Customer ID to proceed...");
				getch();
				continue;
			}
			break;
		}
		else
		{
			printf("\nPlease Enter The Correct Option!!\n");
			printf("\nPress esc key to exit,  any other key to try again...");
			test=getche();
			if(test==27)
			{
				fclose(f);
				return;
			}
		}
	}
		system("cls");
		printf("Enter Details for Booking No- %d:", s.bookno);
		printf("\n**************************");
		printf("\nEnter Room Number:\t");
		scanf("%d",&s.roomno);
		printf("Enter Period(\'x\'days):\t");
		scanf("%d",&s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\t");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		printf("\n\n Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to book another room...");
		test=getche();
		if(test==27)
			break;
	}
	fclose(f);
}


void list()
{
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("CUSTOMER ID\t");
	printf("NAME\t");
	printf("\tBOOKING NO");
	printf("\tROOM NO");
	printf("\tPERIOD");
	printf("\tARRIVALDATE \n");
	for(i=0;i<80;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{	printf("\n%s\t\t%s\t%d\t\t%d\t%d  \t%s",s.custid, s.name, s.bookno, s.roomno, s.period, s.arrivaldate);
	}
	printf("\n");
	for(i=0;i<80;i++)
		printf("-");
	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=1;
	char custid[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Customer ID to be deleted from the database: \n");
	scanf("%s",custid);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.custid,custid)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{
		printf("\n\n Record of Customer is not found!!");
		getch();
		fclose(f);
		fclose(t);
		return;
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nThe Customer Record is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
	FILE *f;
	char t, custid[20];
	int flag=0, b;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	system("cls");
	printf("Enter Customer ID of the customer to search the details: \n");
	scanf("%s", custid);
	printf("\nEnter Booking NO for a particular booking (0 for all):\n");
	scanf("%d", &b);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.custid,custid)==0 && (b==0 || b==s.bookno))
		{
			flag++;
			system("cls");
			printf("\nRecord Found for Customer ID:\t%s\n", s.custid);
			printf("And Booking NO:\t%d\n", s.bookno);
			printf("\n------------------------------------\n");
			if(flag==1)
			{
				printf("\nName:\t%s",s.name);
				printf("\nAddress:\t%s",s.address);
				printf("\nPhone number:\t%s",s.phonenumber);
				printf("\nEmail:\t%s",s.email);
				printf("\n------------------------------------\n");
			}
			printf("\nRoom Number:\t%d",s.roomno);
			printf("\nPeriod:\t%d",s.period);
			printf("\nArrival date:\t%s",s.arrivaldate);
			printf("\n------------------------------------\n");
			printf("\n\nEnter 'P' to print the bill for this booking\n");
			printf("\nEnter any other key to continue...");
			t=getche();
			if(t=='P' || t=='p')
			{
				printf("\n\nYou have chosen to print the bill!");
				printf("\n------------------------------------\n");
				printf("\n\nPress any key to continue...");
				getch();
				system("cls");
				printf("The bill for Cust ID:  %s, Booking NO:  %d :-", s.custid, s.bookno);
				printf("\n\n------------------------------------\n");
				bill(s.roomno, s.period);
				printf("\n\n------------------------------------\n");
				printf("\n\nPress any key to continue...");
				getch();
			}
			if(b)
				break;
		}
	}
	if(flag==0)
	{
		printf("\n\tRequested Customer Record could not be found!");
		getch();
	}
	fclose(f);
}

void edit()
{
	FILE *f;
	int k=0,b;
	char custid[20];
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Customer ID of the customer to edit:\n");
	scanf("%s", custid);
	printf("\n\nEnter the number of booking to edit:\n");
	printf("\n(Eg: Enter 1 for first booking)\n");
	scanf("%d", &b);
	while(fread(&s,size,1,f)==1)
	{
		if(strcmp(s.custid,custid)==0 && s.bookno==b)
		{
			k++;
			printf("\nEnter Name:\t");
			scanf("%s[^\n]%*c",s.name);
			fflush(stdin);
			printf("\nEnter Address:\t");
			scanf("%s[^\n]%*c",s.address);
			fflush(stdin);
			printf("\nEnter Phone number:\t");
			scanf("%s",&s.phonenumber);
			printf("\nEnter Email:\t");
			scanf("%s",&s.email);
			printf("\nEnter Room Number:\t");
			scanf("%d",&s.roomno);
			printf("\nEnter Period:\t");
			scanf("%d",&s.period);
			printf("\nEnter Arrival date:\t");
			scanf("%s",&s.arrivaldate);
			fseek(f,size,SEEK_CUR);  
			fwrite(&s,size,1,f);
			fclose(f);
			printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
			break;
		}
	}
	if(k==0)
	{
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
	}
	getch();
}

void bill(int rno, int per)
{
	int pstd= 1000, pdel= 2500, floor, occupancy, price, rate;
	char rtype;
	double tax=0.18, cost;
	floor= rno/100;
	occupancy= (rno/10)%10;
	if(floor>0 && floor<7)
	{	
		rtype= 's';
		rate= pstd*occupancy;
	}
	else if(floor>6 && floor<11)
	{
		rtype= 'd';
		rate= pdel*occupancy;
	}
	else
	{
		printf("\nERROR!!\n");
		printf("\nThe floor does not exist. Please check the Room No in the database");
		return;
	}
	price= rate*per;
	cost= price +(price*tax);
	printf("\nROOM NO:			%d\n", rno);
	printf("\nROOM TYPE:		");
	if(rtype=='s')
		printf("Standard\n");
	else if(rtype=='d')
		printf("Deluxe\n");
	else
	{
		printf("INVALID!");
		return;
	}
	printf("\nROOM OCCUPANCY:	");
	if(occupancy==1)
		printf("Single\n");
	else if(occupancy==2)
		printf("Double\n");
	else
	{
		printf("INVALID!");
		return;
	}
	printf("\nROOM RATE:		%d\n", rate);
	printf("\nTOTAL ROOM COST:	%d\n", price);
	printf("\nTAX APPLICABLE:	%f%%\n", tax*100);
	printf("\nFINAL AMOUNT DUE:	%f\n", cost);
	printf("\n\nTHANK YOU FOR YOUR STAY!!\nDO VISIT US AGAIN!!\n");
}