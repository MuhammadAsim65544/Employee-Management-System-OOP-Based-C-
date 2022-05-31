#include <iostream>
#include <string.h>
#define MAX 10
using namespace std;
class employee
{
 	protected:
	 int eno;
	 string enam;
	 string cnic;	
	 public:
	 	//employee(int no,string s,long int cn):eno(no),enam(s),cnic(cn){ }
	 	virtual void setter()
	 	{
	 	cout<<"No of employee: ";
		 cin>>eno;
		 cout<<"Enter name: ";
		 cin.ignore(10, '\n');
		 getline(cin,enam);
		 cout<<"CNIC NO: ";
		 cin>>cnic;
		}
	 	virtual void getter()
	 	{
	 	cout<<"No of employee: ";
		cout<<eno;
		 cout<<"\nEmployee name: ";
		 cout<<enam;
		 cout<<"\nCNIC NO: ";
		 cout<<cnic<<endl;
		}
	 	virtual void isoutstanding(){   }
};
class manager:public employee
{
	string tittle;
     float clubdues;
     public:
     	//manager(int no,string s,long int cn,string tit,float club):employee(no,s,cn),tittle(tit),clubdues(club){ }
     	void setter()
     	{
     		employee::setter();
     		cout<<"Enter tittle: ";
     		cin.ignore(10, '\n');
		 	getline(cin,tittle);
		 	cout<<"Enter club dues: ";
		 	cin>>clubdues;	
		}
		void getter()
		{
			cout<<"   Manager_info\n";
			employee::getter();
			cout<<"Tittle is: ";
			cout<<tittle;
			cout<<"\nClub dues are: ";
			cout<<clubdues<<endl;
		}
		void isoutstanding()
		{  
			if(clubdues>=500) 
			{
				cout<<"Outstaning_manager\n";
			}
			else if(clubdues<500)
			{
				cout<<"NOT Outstaning_manager\n";
			}
		}
	
};
class scitentist:public employee
{
	string field;
	int nOpbooks;
	public:
		//scitentist(int no,string s,long int cn,string f,int nob):employee(no,s,cn),field(f),nOpbooks(nob){ }
		void setter()
		{
			employee::setter();
			cout<<"Enter field: ";
			cin.ignore(10, '\n');
			getline(cin,field);
			cout<<"No of published books: ";
			cin>>nOpbooks;
				
		}
		void getter()
		{
			cout<<"   Scitenist_info\n";
			employee::getter();
			cout<<"Rearch field is: "<<field;
			cout<<"\nNo of published books: "<<nOpbooks<<endl;
			
		}
	 void isoutstanding()
		{  
			if(nOpbooks>=5) 
			{
				cout<<"Outstaning_scitentist\n";
			}
			else if(nOpbooks<5)
			{
				cout<<"NOT Outstaning_scitentist\n";
			}
		}
};
class labour:public employee
{
	protected:
   int shift,ch;
   float hrs_worked,hrs_rate;
   public:
   	//labour(int no,string s,long int cn,int sf,float wrk,float,float rate,int chh):employee(no,s,cn),shift(sf),hrs_worked(wrk),hrs_rate(rate),ch(chh){ }
   void setter()
   {
   	employee::setter();
  	cout<<"What's your shift? \n";	
   	cout<<" 1.Morning\n";
   	cout<<" 2.Evening\n";
   	cout<<" 3.Night\n";
   	cout<<"Enter your choice: ";
   	cin>>ch;
   	if(ch>3 || ch<0)
	{
		cout<<"Invalid choice! Enter again: ";
		cin>>ch;
	}
   	cout<<"Enter hours worked: ";
   	cin>>hrs_worked;
   	cout<<"Enter hour rate: ";
   	cin>>hrs_rate;
	}	
	void getter()
	{
		cout<<"   Labour_info\n";
		employee::getter();
		cout<<"Shift is ";
		if(ch==1)
		cout<<"Morning\n";
		else if(ch==2)
		cout<<"Evening\n";
		else 
		cout<<"Night\n";
		cout<<"Hours worked are: "<<hrs_worked;
		cout<<"\nHour rate is: "<<hrs_rate<<endl;
	}
	void isoutstanding()
		{  
			if(hrs_worked>=8) 
			{
				cout<<"Outstaning_Labour\n";
			}
			else if(hrs_worked<8)
			{
				cout<<"NOT Outstaning_Labour\n";
			}
		}
};
class forman:public labour
{
   int nO_man;
   public:
   public:
   		void setter()
		   {
		   		labour::setter();
		   		cout<<"Enter the no of person working under forman: ";
		   		cin>>nO_man;
			}	
		void getter()
			{
				cout<<"   Forman_info\n";
				labour::getter();
				cout<<"No of person working under forman: "<<nO_man<<endl;
			}
		void isoutstanding()
		{  
			if(nO_man>=10) 
			{
				cout<<"Outstaning_Forman\n";
			}
			else if(nO_man<10)
			{
				cout<<"NOT Outstaning_Forman\n";
			}
		}
};
int main()
{
	   int ch,counter=0;
	   int manager_count=0,sci_count=0,lab_count=0,forman_count=0;
	   employee *e[MAX];
	do
	{
	cout<<"           Main Menu  \n";
	cout<<"    1.Manager\n";
	cout<<"    2.Scitenist\n";
	cout<<"    3.Labour\n";
	cout<<"    4.Forman\n";
	cout<<"    5.Display all results\n";
	cout<<"    6.Statistic\n";
	cout<<"    7.Exit\n";
	cout<<"Enter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			e[counter]=new manager;
			e[counter++]->setter();
			manager_count++;
			break;
		case 2:
			e[counter]=new scitentist;
			e[counter++]->setter();
			sci_count++;
	        break;
	    case 3:
	    	e[counter]=new labour;
			e[counter++]->setter();
			lab_count++;
	    	break;
	    case 4:
	    	e[counter]=new forman;
			e[counter++]->setter();
			forman_count++;
	    	break;
	    case 5:
			for(int i=0;i<counter;i++)
			{
				e[i]->getter();
				e[i]->isoutstanding();
			}
	    	break;
	    case 6:
	    	cout<<"\nNo of Employees are: "<<counter<<endl;
	    	cout<<"No of Manager: "<<manager_count<<endl;
	    	cout<<"No of Scitenist: "<<sci_count<<endl;
	    	cout<<"No of Labour: "<<lab_count<<endl;
	    	cout<<"nNo of Forman: "<<forman_count<<endl;
	    	break;
	    case 7:
	    	exit(-1);
	}
	}while(1);
	return 0;
}

