#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
//log in page function start
#define MAX_USERS 100
#define FILENAME "database.txt"


struct details {
    char uname[100];
    int age;
    char password[100];
    char email[100];
    char mobile[10];
};

void signup();
void login();
int validate();
void save_user(struct details user);
int load_users();


struct details users[MAX_USERS];
int user_count = 0;
char temp_name[100], temp_password1[100], temp_password2[100];
char temp_email[100], temp_mobile[100];
int temp_age;
//log in end
void returnfunc(void);
void payment(void);
void mainmenu(void);

void administration(void);
void customer(void);

void addrecord(void);
void deleterecord(void);
void searchrecord(void);
void viewrecord(void);

void vegetarian(void);
void nonvegetarian(void);
void details(void);
void aboutus(void);

void Password(void);
void admin_back(void);
int getdata();
void otp(void);

struct employee
{

	char name[30];
	int id;
	//char DOB[10];
	int dd; int mm; int yyyy;
	int YOJ;
	char place[20];
	float salary;
	char department[20];

	int quantity;
};
struct employee e;

FILE *fp,*ft,*dp,*dt;

int s;
char findrecord;
int again;
int quantity;
double total=0;

int t;
//char password[10]="foodiegoodie";

int main() {
    while (1) {
        printf("\n\n********************Welcome to Food Ordering System**************** ");
        printf("\n\n1) SIGNUP\n");
        printf("2) LOGIN\n");
        printf("3) EXIT\n\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("\n********************** Thank you for visiting. *******************\n");
                exit(0);
            default:
                printf("\nPlease Enter a valid choice\n");
                break;
        }
    }
    return 0;
}


void mainmenu(void)
{
	system("cls");
	printf("                                 **************************************************************************\n");
	printf("                                                     WELCOME TO FOOD ORDER SYSTEM\n");
	printf("                                 **************************************************************************\n\n\n");
	printf("          1. ADMINISTRATION SECTION--> \n\n          2. CUSTOMER SECTION--> \n\n          3. ABOUT US--> \n\n          4. Exit--> \n\n\n             Enter Your Choice --->");
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
	    int pass;
	    printf("Enter Admin PANEL PASSWORD:");
	    scanf("%d",&pass);
	    if(pass==12345)
        {
          administration();
        }
        else
        {
            printf("\n\n\t\t\t\t\WRONG PASSWORD!!!!!!!");
            sleep(2);
            mainmenu();

        }

	}
	else if(choice==2)
	{
		customer();
	}
	else if(choice==3)
	{
		aboutus();
	}
	else if(choice==4)
	{
		system("cls");
		printf("\n\n\n");
		printf("*******************************THANK YOU**************************************\n");

		printf("*********Feeling HUNGRY ? Call or Walk-In FOODIE GOODIE KITCHEN***************\n\n");
		exit(0);
	}
}

void administration(void)
{
	system("cls");
	printf("**************************************WELCOME TO THE EMPLOYEE SECTION************************************************\n\n");
	printf("          1. Add New Record\n\n          2. Search Record\n\n          3. Delete Record\n\n          4. View THe Records\n\n          5. View previous orders placed\n\n          6. Back To Main Menu \n\n             Enter Your Choice --->");
	int n;
	scanf("%d",&n);
		printf("\n\n");
	int wait;
	//printf("In progress :");
	for(wait=0;wait<=1000;wait++)
	{
		printf("\rIn progress : %d",wait/1000);
	}
	printf("\n\n");
	if(n==1)
	{
		addrecord();
	}
	else if(n==2)
	{
		searchrecord();
	}
	else if(n==3)
	{
		deleterecord();
	}
	else if(n==4)
	{
		viewrecord();
	}
		else if(n==5)
	{
		FILE *view;
		char viw;
		view = fopen("order.txt","rt");
		while((viw=fgetc(view))!=EOF)
		{
			printf("%c",viw);
		}
		fclose(view);
		admin_back();
	}
	else if(n==6)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		printf("Wrong Input !! PLease Re-enter The Correct Option");
		if(getch())
		administration();
	}

}

void addrecord(void)
{
	system("cls");
	fp=fopen("record1.txt","a");
	if(getdata()==1)
	{
		fseek(fp,0,SEEK_END);
		fwrite(&e,sizeof(e),1,fp);
		fclose(fp);
		printf("\n\n");
		printf("The Record Is Successfully Saved ! !\n\n");
		printf("Save any more?(Y / N): ");
		if(getch()=='n')
	    	administration();
		else
	    	system("cls");
	    	addrecord();
	}
    admin_back();
}

void deleterecord(void)
{
	system("cls");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
	system("cls");
	printf("                Enter The Employee ID To Delete :");
	scanf(" %d",&d);
	fp=fopen("record1.txt","r+");
	rewind(fp);
	while(fread(&e,sizeof(e),1,fp)==1)
	{
	    if(e.id==d)
	    {
			printf("\n\n");
			printf("                               .....................The Employee Record Is Available....................\n\n");
			printf("               Employee Name Is %s\n\n",e.name);
			printf("               Employee's Date  OF Birth Is %d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
			findrecord='t';
	    }
	}
	if(findrecord!='t')
	{
	    printf("                                    .........................No record is found modify the search..........................\n\n");
	    if(getch())
	    administration();
	}
	if(findrecord=='t' )
	{
	    printf("Do You Want To Delete THe Record ? (Y/N) ");
	    if(getch()=='y')
	    {
			ft=fopen("test1.txt","w");  //temporary file for delete
			rewind(fp);
			while(fread(&e,sizeof(e),1,fp)==1)
			{
		    	if(e.id!=d)
		    	{
					fseek(ft,0,SEEK_CUR);
					fwrite(&e,sizeof(e),1,ft); //write all in tempory file except that
		    	}                              //we want to delete
			}
			fclose(ft);
			fclose(fp);
			remove("record1.txt");
			rename("test1.txt","record1.txt"); //copy all item from temporary file to fp except that
			fp=fopen("record1.txt","r");    //we want to delete
			if(findrecord=='t')
			{
		    	printf("        THE RECORD IS SUCCESSFULLY DELETED.\n\n");
		    	printf("        Delete Another Record ? (Y/N) : ");
			}
	    }
		else
		administration();
		fflush(stdin);
		another=getch();
	}
}
administration();
}

void searchrecord(void)
{
	system("cls");
    int d;
    printf("                                          *****************************Search Employees Record*********************************\n\n");
    printf("                  1. Search By ID\n");
    printf("                  2. Search By Name\n\n");
    printf("                  Enter Your Choice---> ");
    fp=fopen("record1.txt","r"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
	  case '1':
		{
	    	system("cls");
	    	printf("                                   **************Search Record By Id****************\n\n");
	    	printf("                Enter The Employee ID : ");
	    	scanf(" %d",&d);
	    	printf("\n\n");
			printf("Searching........");
	    	while(fread(&e,sizeof(e),1,fp)==1)
	    	{
				if(e.id==d)
				{
		    		printf("\n\n");
					printf("...........................The Record is available............................\n\n");
				    printf("       ID : %d\n\n",e.id);
				    printf("       Name : %s\n\n",e.name);
				    printf("       Date OF Birth :%d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
				    printf("       Year Of Joining :%d\n\n",e.YOJ);
				    printf("       Department :%s\n\n",e.department);
				    printf("       Place :%s\n\n",e.place);
				    findrecord='t';
				}

	    }
	    if(findrecord!='t')  //checks whether conditiion enters inside loop or not
	    {
	    	printf("\aNo Record Found\a");
	    }
	    printf("Try Another Search ? (y/n)");
	    if(getch()=='y')
	    searchrecord();
	    else
	    administration();
	    break;
	}
	case '2':
	{
	    char s[15];
	    system("cls");
	    printf("                                   **********************Search Employees By Name***************************\n\n");
	    printf("               Enter Employee Name : ");
	    scanf(" %s",s);
	    int d=0;
	    while(fread(&e,sizeof(e),1,fp)==1)
	    {
		if(strcmp(e.name,(s))==0) //checks whether a.name is equal to s or not
		{
		    printf("                               .........................The Record is available...........................\n\n\n");
			printf("       ID : %d\n\n",e.id);
			printf("       Name : %s\n\n",e.name);
			printf("       Date OF Birth :%d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
			printf("       Year Of Joining :%d\n\n",e.YOJ);
			printf("       Department :%s\n\n",e.department);
			printf("       Place :%s\n\n",e.place);
		    d++;
		}

	    }
	    if(d==0)
	    {
	    	printf("\aNo Record Found\a");
	    }
	    printf("Try Another Search ? (Y/N)");
	    if(getch()=='y')
	    searchrecord();
	    else
	    administration();
	    break;
	}
	default :
	getch();
	searchrecord();
    }
    fclose(fp);
     admin_back();
}

void viewrecord(void)
{
    system("cls");
    printf("                              ******************** Employee Details**********************\n\n");
    printf("                 DEPARTMENT        ID        EMPLOYEE NAME        D.O.B        Y.O.J        PLACE\n\n");

    fp=fopen("record1.txt","r");
    while(fread(&e,sizeof(e),1,fp)==1)
    {
		printf("                 %s",e.department);
		printf("        %d",e.id);
		printf("        %s",e.name);
		printf("        %d/%d/%d",e.dd,e.mm,e.yyyy);
		printf("        %d",e.YOJ);
		printf("        %s",e.place);
		printf("\n\n");
	}

      fclose(fp);
      admin_back();
}

/*void returnfunc(void)
{
    {
		printf(" Press ENTER to return to main menu");
    }
    e:
    if(getch()==13) //allow only use of enter
    administration();
    else
    goto e;
}*/

int checkid(int c)  //check whether the record is exist in list or not
{
	rewind(fp);
	while(fread(&e,sizeof(e),1,fp)==1)	if(e.id==c)

	return 0;  //returns 0 if employee exits

	return 1; //return 1 if it not
}
int getdata()
{
	//*int t;
	printf("        Employee ID :\t");
	scanf("%d",&t);
	if(checkid(t)==0)
	{
		printf("\n\n");
		printf("\a                        The Employee Record Already Exists !!!\a");
		getch();
		mainmenu();
		return 0;
	}
	e.id=t;
	printf("        Employee Name : ");
	scanf("%s",e.name);
	printf("        Date Of Birth (dd/mm/yyyy) :");
	scanf("%d/%d/%d",&e.dd,&e.mm,&e.yyyy);
	printf("        Year OF Joining :");
	scanf("%d",&e.YOJ);
	printf("        Place :");
	scanf("%s",e.place);
	printf("        Department :");
	scanf("%s",e.department);
	return 1;
}
void customer(void)
{

	system("cls");
	printf("                    ************************************************\n                                      WELCOME\n                    ************************************************\n\n");
	printf("               YOU ARE--->\n\n               1. Vegetarian\n\n               2. Non Vegetarian\n\n                      OR\n\n               3. Back To Main Menu\n\n   Enter Your Choice  -->");
	int k;
	scanf("%d",&k);
		int wait;
	//printf("In progress :");
	for(wait=0;wait<=50000;wait++)
	{
		printf("\rIn progress : %d",wait/500);
	}
	if(k==1)
	{
		system("cls");
		vegetarian();
	}
	else if(k==2)
	{
		system("cls");
		nonvegetarian();
	}
	else if(k==3)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		printf("Wrong Input !Please Re-enter The Correct Option......\n\n");
		customer();
	}
}
void vegetarian(void)
{
    system("cls");
	int choice;
	int again;
	int quantity;

	double price=0;

	printf("                    ****************************************\n                                  VEGETARIAN MENU\n                    ****************************************\n\n");
	printf("      1. Burger               40/-\n      2. Noodles              60/-\n      3. Sandwich             45/-\n      4. Beverages            35/-\n      5. Veg. Thaali          150/-\n         -->Dal\n         -->Paneer\n         -->Chapati\n         -->Rice\n         -->Papad\n      6. Back To Main Menu\n\n Enter Your Choice-->  ");
	char v;
	FILE *vmenu;

    vmenu=fopen("vegmenu.txt","rt");
	while((v=getc(vmenu))!=EOF)
        {
        	printf("%c",v);
		}
         fclose(vmenu);
    printf("\n\nEnter What You Want :");
	printf("\n\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 40*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		printf("\n");
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);

			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 60*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);

			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 45*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);

			details();
		}
	}
	else if(choice==4)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 35*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);

			details();
		}
	}
	else if(choice==5)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 150*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);

			details();
		}

	}
	else if(choice==6)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		if(getch())
		vegetarian();
	}
}


void nonvegetarian(void)
{
    system("cls");
	int choice;
	int again;
	int quantity;
	double price=0;
	printf("                                    **********************************************\n");
	printf("                                                  Non Veg. Menu\n");
	printf("                                    **********************************************\n");
    printf("1. Dry Chicken            100-\n\n2. Gravy Chicken          120-\n\n3. Chicken Biryani        85-\n\n4. Beverages              35-\n\n5. Back To Main Menu\n\n\nEnter Your Choice");
	char n;
	FILE *nmenu;
	nmenu = fopen("nonveg.txt","rt");
	while((n=getc(nmenu))!=EOF)
	{
		printf("%c",n);
	}
	printf("\n\nEnter What You Want :");
	printf("\n\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Quantity : ");
		scanf(" %d",&quantity);
		total=total + 100*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity :");
		scanf(" %d",&quantity);
		total=total + 120*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity :");
		scanf(" %d",&quantity);
		total=total + 85*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==4)
	{
		printf("Quantity :");
		scanf(" %d",&quantity);
		total=total + 35*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==5)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		nonvegetarian();
	}
}
void details(void)
{
	char name1[20];
	char name2[20];
	long long int phone;
	char address[40];
	char landmark[30];
	printf("Please Give Your Contact Details \n");
	printf(" First Name : ");
	scanf("%s",name1);
	printf("Last Name : ");
	scanf("%s",name2);
	printf("Phone : ");
	scanf("%lld",&phone);
	printf("Address : ");
	scanf("%s",address);
	printf("Landmark : ");
	scanf("%s",landmark);
	printf("\n\n");
	system("cls");
	printf("Your Entered Details Are --->\n");
	FILE *cust;
	cust = fopen("order.txt","a");
	fprintf(cust,"Order Placed By : %s %s\nPhone number : %lld\n",name1,name2,phone);
	fclose(cust);
	printf("    -->First Name :  %s\n    -->Last Name   :  %s\n    -->Phone     :%lld \n    -->Address  :%s \n    -->Landmark  :%s \n",name1,name2,phone,address,landmark);
	printf("\n\n\n");
	payment();
	printf("                       *********************************************************************************************\n");
	printf("                                             Your Order Will Be At Your Door In 30 minutes.\n");
	printf("                                                       .....HAPPY ORDERING.....\n");
	printf("                       *********************************************************************************************\n");

	printf("Press Any To The MainMenu.");
	if(getch())
	customer();
}

void aboutus(void)
{
	system("cls");
	printf("PEOPLE BEHIND THIS PROJECT :\n\n   -->SIFATH HOSSAIN\n\n   -->MAHATHIR MOHAMMAD RAHIM\n\n   -->FHAMID KHONDOKAR\n\n   -->RYIN AKAND\n\n   -->HASAN MIA\n\n                       ****************************THANK YOU****************************");
	printf("\n\n");
	printf("    Press Any Key To Go Back.");
	if(getch())
	mainmenu();
}

void admin_back(void)
{
    int n;
    printf("1.press 1 back to administration panel:\n");
    printf("2.press any key back to main menu:\n");
    scanf("%d", &n);
    if(n==1)
    {
       administration();
    }
    else
    {
       mainmenu();
    }
}

//log in system
void signup() {
    system("cls");
    printf("\n\n************ Welcome to Signup Page *************\n");
    printf("\tEnter Your Name: ");
    scanf("%s", temp_name);

    printf("\tEnter Your Age: ");
    scanf("%d", &temp_age);

    printf("\tEnter Your Email: ");
    scanf("%s", temp_email);

    printf("\tEnter Password: ");
    scanf("%s", temp_password1);

    printf("\tConfirm Password: ");
    scanf("%s", temp_password2);

    printf("\nEnter Your Mobile Number: ");
    scanf("%s", temp_mobile);


    int is_valid = validate();
    if (is_valid) {

        struct details new_user = {0};
        strcpy(new_user.uname, temp_name);
        new_user.age = temp_age;
        strcpy(new_user.password, temp_password1);
        strcpy(new_user.email, temp_email);
        strcpy(new_user.mobile, temp_mobile);

        save_user(new_user);
        printf("\nAccount Successfully Created!!\n");
    }
}


int validate() {

    int count = 0;
    for (int i = 0; temp_email[i] != '\0'; i++) {
        if (temp_email[i] == '@' || temp_email[i] == '.') count++;
    }
    if (count < 2 || strlen(temp_email) < 5) {
        printf("\nPlease Enter a valid Email\n");
        return 0;
    }


    if (strcmp(temp_password1, temp_password2) != 0) {
        printf("\nPassword Mismatch\n");
        return 0;
    }


    int caps = 0, small = 0, numbers = 0, special = 0;
    for (int i = 0; temp_password1[i] != '\0'; i++) {
        if (temp_password1[i] >= 'A' && temp_password1[i] <= 'Z') caps++;
        else if (temp_password1[i] >= 'a' && temp_password1[i] <= 'z') small++;
        else if (temp_password1[i] >= '0' && temp_password1[i] <= '9') numbers++;
        else if (temp_password1[i] == '@' || temp_password1[i] == '&' || temp_password1[i] == '#' || temp_password1[i] == '*') special++;
    }
    if (!(caps >= 1 && small >= 1 && numbers >= 1 && special >= 1)) {
        printf("\nPassword must contain at least one uppercase, one lowercase, one digit, and one special character.\n");
        return 0;
    }


    if (strlen(temp_mobile) != 11) {
        printf("\nPlease Enter a valid 10 digit mobile number\n");
        return 0;
    }

    return 1;
}


void save_user(struct details user) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("\nError opening file for writing\n");
        return;
    }

    fprintf(file, "%s %d %s %s %s\n", user.uname, user.age, user.password, user.email, user.mobile);
    fclose(file);
}

int load_users() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return 0;
    }

    user_count = 0;
    while (fscanf(file, "%s %d %s %s %s\n", users[user_count].uname, &users[user_count].age,
                  users[user_count].password, users[user_count].email, users[user_count].mobile) != EOF) {
        user_count++;
        if (user_count >= MAX_USERS) break;
    }

    fclose(file);
    return user_count;
}

void payment()
{
    int method;
    printf("SELECT BILL PAYMENT MATHOD\n\n\n");
    printf("1.BKASH\n2.NOGOD\n3.ACCOUNT NUMBER\n\n\n");
    printf("SELECT METHOD\n");
    scanf("%d",&method);
    if(method==1)
    {
        printf("OUR BKASH NUMBER:01701447112\n\nPAY YOUR BILL IN THIS BKASH NUMBER\n\n");
        otp();
    }
    else if(method==2)
    {
        printf("OUR NOGOD NUMBER:01701447112\n\nPAY YOUR BILL IN THIS NOGOD NUMBER\n\n");
        otp();
    }
     else
    {
        printf("OUR account NUMBER:0170144745777\n\nPAY YOUR BILL IN THIS ACCOUNT NUMBER\n\n");
        otp();
    }
}
void otp()
{
    sleep(5);
    int wait;
	for(wait=0;wait<=50000;wait++)
	{
		printf("\rIn progress : %d",wait/500);
	}
	 printf("\n\nTHATS YOUR OTP:");
    srand(time(0));

    int random_number = rand() % 100000+ 1;

    printf("%d\n", random_number);
    sleep(3);
    printf("\n\n\nWHEN THE DELIVARYMAN WILL COME TO DELIVER YOUR ORDERING FOOD YOU MUST BE SHOWED YOUR OTP\n\n\n\n");
}

void login() {
     system("cls");
    printf("\n\n************** Welcome to Login Page ****************\n\n");
    printf("\tEnter Your Email: ");
    scanf("%s", temp_email);
    printf("\tEnter Your Password: ");
    scanf("%s", temp_password1);


    load_users();


    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].email, temp_email) == 0) {
            if (strcmp(users[i].password, temp_password1) == 0) {
                printf("\n\nWelcome %s, you are successfully logged in.\n", users[i].uname);
                mainmenu();

                return;
            } else {
                printf("\nIncorrect password. Please try again.\n");
                return;
            }
        }
    }

    printf("\nUser not found. Please sign up.\n");
}



