#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<dos.h>
#include<cstdio>
#define max 25

using namespace std;

struct employee
{
	char name[25];
	long int id;
	char designation[40];
	int expe;
	int age;
};

int num;
employee empl[max];
employee tempempl[max];
employee sortempl[max];
employee sortempl1[max];


int main()
{
	system("cls");
	void menu();
	void addlist();
	void list();
	void insert();
	void deleted();
	void edit();
	void search();
	void sort();
	menu();
	char option;
	while((option=cin.get())!='q')
	{
		switch(option)
		{
			case 'b':	addlist();
						break;

			case 'l':	list();
						break;

			case 'i':	insert();
						break;

			case 'd':	deleted();
						break;

			case 'e':	edit();
						break;

			case 's': 	search();
						break;

			case 'n':	sort();
						break;
		}
		menu();
	
	}
	return 0;
}

void menu()
{
	system("cls");
	cout<<"          ";	
	printf("\n\t\t\t\t\t*****  EMPLOYEE MANAGEMENT SYSTEM ***** ");
	cout<<endl;
	cout<<"             ";
    cout<<"\n\n\n\t\t Press  b---->Add list of Employees to The Employee Table ";
	cout<<"             ";
	cout<<"\n\t\t Press  l---->List The Employee Table  ";
	cout<<"             ";
	cout<<"\n\t\t Press  i---->Insert New Entry to table       ";
	cout<<"             ";
	cout<<"\n\t\t Press  d---->Delete An Entry from table        ";
	cout<<"             ";
	cout<<"\n\t\t Press  e---->Edit An Entry in a table          ";
	cout<<"             ";
	cout<<"\n\t\t Press  s---->Search Employee Record in a table         ";
	cout<<"             ";
	cout<<"\n\t\t Press  n---->Sort The Employee Table          ";
	cout<<"             ";
	cout<<"\n\t\t Press  q---->QUIT Application            ";
	cout<<"             ";
	cout<<"\n\n \t\t Select any above Option Please ====> ";
}

void addlist()
{
	system("cls");
	printf("\n\n\t\t\t\t\t ***Add List of employees to the table***");
	cout<<endl;
	cout<<"\n\n\t\t\tmaximum number of entries to add ----->  20"<<endl;
	cout<<"\n\n\t\t\tNo. of Entries you want to Add   ----->";
	cin>>num;
	cout<<"\n\n\t\t\t\tEnter The Following Details"<<endl;
	
	for(int i=0;i<=num-1;i++)
	{
		cout<<"\n\t\t\t\tName  :";
		cin>>empl[i].name;
		cout<<"\t\t\t\tID  :";	
		cin>>empl[i].id;
		cout<<"\t\t\t\tDesignation  :";
		cin>>empl[i].designation;
		cout<<"\t\t\t\tYears of Experience  :";
		cin>>empl[i].expe;
		cout<<"\t\t\t\tAge  :";
		cin>>empl[i].age;
	}
	cout<<"going back to main menu";
	Sleep(500);
}

void  list()
{
	system("cls");
	printf(" \n\n\t\t\t\t  ******** Table Of List of Employees ********");
	cout<<endl;
	cout<<"\n\n     Name     ID       Designation     Years(EXP)     Age "<<endl;
	cout<<"    ------------------------------------------------------"<<endl;

	for(int i=0;i<=num-1;i++)
	{
		cout<<setw(13)<<empl[i].name;
		cout<<setw(6)<<empl[i].id;
		cout<<setw(15)<<empl[i].designation;
		cout<<setw(10)<<empl[i].expe;
		cout<<setw(15)<<empl[i].age;
		cout<<endl;
	}
	cout<<"\n\n\n\n\n\n\n\t\t\t\t To go back to main menu press enter";
	getch();
 }

 void insert()
{
	system("cls");
	int i=num;
	num+=1;
	printf("\n\n\t\t\t\t *****Insert New Record To existing Table*****");
	cout<<endl;
	cout<<"\n\n\t\t\tEnter The Following Details"<<endl;
	cout<<"\n\t\t\tName:  ";
	cin>>empl[i].name;
	cout<<"\t\t\tID:  ";
	cin>>empl[i].id;
	cout<<"\t\t\tDesignation:  ";
	cin>>empl[i].designation;
	cout<<"\t\t\tYears of Experience:  ";
	cin>>empl[i].expe;
	cout<<"\t\t\tAge:  ";
	cin>>empl[i].age;
	cout<<endl<<endl;
	cout<<"\n\ngoing back to main menu";
  
	Sleep(500);
}

void deleted()
{
	system("cls");
	int id;
    int check;
	int i;
    printf("\n\n\t\t\t\t ***** Delete An Entry *****");
	cout<<endl;
	cout<<"\n\n\t\t\tEnter An Job ID To Delete  ";
	cin>>id;
	for(i=0;i<=num-1;i++)
    {
		if(empl[i].id==id)
		{
			check=i;
		}
	}

	for(i=0;i<=num-1;i++)
	{
		if(i==check)
		{
			continue;
		}

		else
		{
			if(i>check)
			{
				tempempl[i-1]=empl[i];
			}
			else
			{
				tempempl[i]=empl[i];
			}
		}
    }

	num--;

	for(i=0;i<=num-1;i++)
	{
		empl[i]=tempempl[i];
	}
 }
 
void edit()
{
	system("cls");
	int jobcode;
	
	void editmenu();
	void editname(int);
	void editid(int);
	void editdesig(int);
	void editexpe(int);
	void editage(int);

	printf("\n\n\t\t\t\t\t ***** Edit Information of an Employee *****");
	cout<<endl;
	cout<<endl;

	int i;
	char option;

	cout<<"\n\n\t\t\tEnter An Job ID To Edit An Entry---->  ";
	cin>>jobcode;
	editmenu();
	
	for(i=0;i<=num-1;i++)
	{
		if(empl[i].id==jobcode)
		{
			while((option=cin.get())!='q')
			{
				switch(option)
				{

					case 'n':	editname(i);
								break;

					case 'c':	editid(i);
								break;

					case 'd':   editdesig(i);
								break;

					case 'e':	editexpe(i);
								break;
								
					case 'a':	editage(i);
								break;
								

				}

				editmenu();

			}
		}
	}
 }
 
void editmenu()
{
	system("cls");
	
	
	cout<<"\n\n\t\t\t\t\t *** What Do You Want To edit**";
	cout<<"\n\n\t\t\t n--------->Name ";
	cout<<"\n\t\t\t c--------->ID ";
	cout<<"\n\t\t\t d--------->Designation";
	cout<<"\n\t\t\t e--------->Experience ";
	cout<<"\n\t\t\t a--------->Age    ";
	cout<<"\n\t\t\t q--------->  main menu     ";
	//cout<<"\n\t\t\t m---------> Main menu";
	cout<<"\n\n\t\t\t Your Option Please ---->>>  ";

}

void editname(int i)
{
	cout<<"Enter New Name of The Employee----->  ";
    cin>>empl[i].name;
}

void editid(int i)
{
   cout<<"Enter New Job ID of the employee----->  ";
   cin>>empl[i].id;
}

void editdesig(int i)
{
   cout<<"enter new designation of the employee----->  ";
   cin>>empl[i].designation;
}
  
void editexpe(int i)
{
   cout<<"Enter new Years of Experience For the employee----->";
   cin>>empl[i].expe;
}

void editage(int i)
{
   cout<<"Enter new Age of the employee-----> ";
   cin>>empl[i].age;
}

void search()
{
	system("cls");
	printf(" \n\n\t\t\t\t **** searching Of Employee Database **** ");
	cout<<endl;
	cout<<endl;
	int jobcode;
	cout<<"\n\n\n\t\t\t\t You Can Search Only By Job ID Of An Employee";
	cout<<"\n\n\t\t\t\tEnter ID Of An Employee--------> ";
	cin>>jobcode;
	for(int i=0;i<=num-1;i++)
	{
		if(empl[i].id==jobcode)
		{
			cout<<" \n\n\tName       ID      Designation     Years(EXP)       Age "<<endl;
			cout<<"\t--------------------------------------------------------- "<<endl;
			cout<<setw(13)<<empl[i].name;
			cout<<setw(6)<<empl[i].id;
			cout<<setw(15)<<empl[i].designation;
			cout<<setw(10)<<empl[i].expe;
			cout<<setw(15)<<empl[i].age;
			cout<<endl;
		}
	}
    cout<<"\n\n\t\t\tgoing back to main menu";
	getch();
}

void sort()
{
	system("cls");
	printf("Sort The Databse By Job ID");

	void sortmenu();
	void sortname();
	void sortid();
	void sortdesig();
	void sortexpe();
	void sortage();
	char option;
	
	cout<<endl;
	cout<<endl;
	sortmenu();
	while((option=cin.get())!='q')
	{
		switch(option)
		{
			case 'n':	sortname();
                        break;

			case 'c':   sortid();
						break;

			case 'd':	sortdesig();
						break;

			case 'e':	sortexpe();
						break;

			case 'a':	sortage();
						break;

		}

		sortmenu();

	}
 }

void sortmenu()
{
    system("cls");
	cout<<"\n\n\t\t\t\t **** What Do You Want To edit ****";
	cout<<"\n\n\t\t\t n--------->Name ";
	cout<<"\n\t\t\t c--------->ID";
	cout<<"\n\t\t\t d--------->Designation ";
	cout<<"\n\t\t\t e--------->Experience   ";
	cout<<"\n\t\t\t a--------->Age          ";
	cout<<"\n\t\t\t q----->QUIT            ";
	cout<<"\n\n\t\t\t Options Please ---->>>  "; 
}

void sortname()
{
	system("cls");
	int i,j;
	struct employee temp[max];
	
	for(i=0;i<=num-1;i++)
	{
		sortempl1[i]=empl[i];
	}

	for(i=0;i<=num-1;i++)
	{
		for(j=0;j<=num-1;j++)
		{
			if(strcmp(sortempl1[i].name,sortempl1[j].name)<=0)
			{
				temp[i]=sortempl1[i];
				sortempl1[i]=sortempl1[j];
				sortempl1[j]=temp[i];
			}
		}
	}
	
	for( i=0;i<=num-1;i++)
	{
		cout<<"\n\n\tName      ID      Designation     Years(EXP)     Age "<<endl;
		cout<<"\n\t------------------------------------------------------"<<endl;
		
		for( i=0;i<=num-1;i++)
		{
			cout<<setw(13)<<sortempl1[i].name;
			cout<<setw(6)<<sortempl1[i].id;
			cout<<setw(15)<<sortempl1[i].designation;
			cout<<setw(10)<<sortempl1[i].expe;
			cout<<setw(15)<<sortempl1[i].age;
			cout<<endl;
		}

		cout<<"\n\n\n\t\tpress Any Key To Go Back";
		getch();
	} 
}

//code by sumukha

void sortid()
{
	system("cls");
	int i,j;
	struct employee temp[max];
	
	for(i=0;i<=num-1;i++)
	{
		sortempl1[i]=empl[i];
	}
	
	for(i=0;i<=num-1;i++)
	{
		for(j=0;j<=num-1;j++)
		{
			if(sortempl1[i].id<sortempl1[j].id)
			{
				temp[i]=sortempl1[i];
				sortempl1[i]=sortempl1[j];
				sortempl1[j]=temp[i];
			}
		}
	}

	for( i=0;i<=num-1;i++)
	{
		cout<<"\n\n\t Name     ID     Designation     Years(EXP)     Age "<<endl;
		cout<<"\n\t ------------------------------------------------------"<<endl;
		
		for( i=0;i<=num-1;i++)
		{
			cout<<setw(13)<<sortempl1[i].name;
			cout<<setw(6)<<sortempl1[i].id;
			cout<<setw(15)<<sortempl1[i].designation;
			cout<<setw(10)<<sortempl1[i].expe;
			cout<<setw(15)<<sortempl1[i].age;
			cout<<endl;
		}
		cout<<"\n\n\n\t\t Press Any Key To Go Back";
		getch();
	} 
}

void sortdesig()
{
	system("cls");
	int i,j;
	struct employee temp[max];

	for(i=0;i<=num-1;i++)
	{
		sortempl1[i]=empl[i];
	}

	for(i=0;i<=num-1;i++)
	{
		for(j=0;j<=num-1;j++)
		{
			if(strcmp(sortempl1[i].designation,sortempl1[j].designation)<=0)
			{
				temp[i]=sortempl1[i];
				sortempl1[i]=sortempl1[j];
				sortempl1[j]=temp[i];
			}
		}
	}

	for( i=0;i<=num-1;i++)
	{
		cout<<"\n\n\t Name     ID     Designation     Years(EXP)     Age"<<endl;
		cout<<"\n\t ------------------------------------------------------"<<endl;

		for( i=0;i<=num-1;i++)
		{
			cout<<setw(13)<<sortempl1[i].name;
			cout<<setw(6)<<sortempl1[i].id;
			cout<<setw(15)<<sortempl1[i].designation;
			cout<<setw(10)<<sortempl1[i].expe;
			cout<<setw(15)<<sortempl1[i].age;
			cout<<endl;
		}

		cout<<"\n\n\n\t\t\t Press Any Key To Go Back";
		getch();
	}
}

void sortexpe()
{
	system("cls");
	int i,j;
	struct employee temp[max];
	for(i=0;i<=num-1;i++)
	{
		sortempl1[i]=empl[i];
	}
	
	for(i=0;i<=num-1;i++)
    {
		for(j=0;j<=num-1;j++)
		{
			if(sortempl1[i].expe<sortempl1[j].expe)
			{
				temp[i]=sortempl1[i];
				sortempl1[i]=sortempl1[j];
				sortempl1[j]=temp[i];
			}
		}
	}

	for( i=0;i<=num-1;i++)
	{
		cout<<"\n\n\t Name     ID       Designation     Years(EXP)     Age "<<endl;
		cout<<"\n\t ------------------------------------------------------ "<<endl;

		for( i=0;i<=num-1;i++)
		{
			cout<<setw(13)<<sortempl1[i].name;
			cout<<setw(6)<<sortempl1[i].id;
			cout<<setw(15)<<sortempl1[i].designation;
			cout<<setw(10)<<sortempl1[i].expe;
			cout<<setw(15)<<sortempl1[i].age;
			cout<<endl;
		}

		cout<<"\n\n\n\t\t Press Any Key To Go Back";
		getch();
	} 
}

void sortage()
{
	system("cls");
	int i,j;
	struct employee temp[max];

	for(i=0;i<=num-1;i++)
	{
		sortempl1[i]=empl[i];
	}

	for(i=0;i<=num-1;i++)
	{
		for(j=0;j<=num-1;j++)
		{
			if(sortempl1[i].age<sortempl1[j].age)
			{
				temp[i]=sortempl1[i];
				sortempl1[i]=sortempl1[j];
				sortempl1[j]=temp[i];
			}
		}
	}
	
	for( i=0;i<=num-1;i++)
	{
		cout<<"\n\n\t Name     ID       Designation     Years(EXP)     Age"<<endl;
		cout<<"\n\t------------------------------------------------------"<<endl;

		for( i=0;i<=num-1;i++)
		{
			cout<<setw(13)<<sortempl1[i].name;
			cout<<setw(6)<<sortempl1[i].id;
			cout<<setw(15)<<sortempl1[i].designation;
			cout<<setw(10)<<sortempl1[i].expe;
			cout<<setw(15)<<sortempl1[i].age;
			cout<<endl;
		}

		cout<<"Press Any Key To Go Back";
		getch();
	}
}	



//code by sumukha
