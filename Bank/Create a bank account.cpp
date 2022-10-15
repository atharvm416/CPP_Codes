#include <iostream>
#include <fstream>
using namespace std;
class Account
{
	int acno;
	char acnm[15];
	int acbal;
	int state;
	public:
		Account()
		{
			acno=acbal=0;
			acnm[0]='\0';
			state=1;
		}
		~Account(){}
		int getno(){return acno;}
		int getstate(){return state;}
		int getbal(){return acbal;}
		void delrecord()
		{
			state=0;
		}
		void setdata(int no)
		{
			acno=no;
			cout<<"\nA/C NAME :";
			cin>>acnm;
			cout<<"\nOpning Balance :";
			cin>>acbal;
			state=1; 
		}
		void display()
		{
			cout<<"\nA/C Data\n No :"<<acno<<"\nName :"<<acnm<<"\nOpening Balance :"<<acbal<<"\nState :"<<state;
		}
};
class AccAMD
{
	fstream fa;
	Account obj;
	public:
		AccAMD()
		{
			fa.open("Acc.DAT",ios::in|ios::out|ios::binary);
			if(!fa)
			{
				ofstream tmp("Acc.DAT",ios::out|ios::binary);
				tmp.close();
				fa.open("Acc.DAT",ios::in|ios::out|ios::binary);
			}
		}
		~AccAMD()
		{
			fa.close();
		}
		int search(int);
		void add();
		void mod();
		void del();
		void displayAll();
		void menu();
};
int AccAMD::search(int no)
{
	int pos=0;
	fa.seekg(0,ios::beg);
	while(1)
	{
		fa.read((char *)&obj,sizeof(obj));
		if(fa.eof())
		{
			fa.clear();
			pos=-1;
			break;
		}
		if(obj.getno()==no)
			break;
		pos=fa.tellg();
	}
	return pos;
}
void AccAMD::add()
{
	int pos=0,no;
	cout<<"\nEnter A/C No :";
	cin>>no;
	pos=search(no);
	if(pos>=0)
	{
		cout<<"\nRecord Found";
		return;
	}
	obj.setdata(no);
	fa.seekp(0,ios::end);
	fa.write((char *)&obj,sizeof(obj));
}
void AccAMD::mod()
{
	int pos=0,no;
	cout<<"\nEnter A/C No :";
	cin>>no;
	pos=search(no);
	if(pos==-1||obj.getstate()==0)
	{
		cout<<"\nRecord Not Exist";
		return;
	}
	obj.setdata(no);
	fa.seekp(pos,ios::beg);
	fa.write((char *)&obj,sizeof(obj));
}
void AccAMD::del()
{
	int pos=0,no;
	cout<<"\nEnter A/C No :";
	cin>>no;
	pos=search(no);
	if(pos==-1||obj.getstate()==0)
	{
		cout<<"\nRecord Not Exist";
		return;
	}
	obj.delrecord();
	fa.seekp(pos,ios::beg);
	fa.write((char *)&obj,sizeof(obj));
}
void AccAMD::displayAll()
{
	fa.seekg(0,ios::beg);
	while(1)
	{
		fa.read((char *)&obj,sizeof(obj));
		if(fa.eof())
		{
			fa.clear();
			break;
		}
		obj.display();
	}
}
void AccAMD::menu()
{
	int opt;
	while(1)
	{
		cout<<"\nMenu\n1.Add\n2.Mod\n3.Delete\n4.Display\n5.Exit\nOption :";
		cin>>opt;
		if(opt>4)
			break;
		switch(opt)
		{
			case 1:
				add();
				break;
			case 2:
				mod();
				break;
			case 3:
				del();
				break;
			case 4:
				displayAll();
		}
	}
}
int main()
{
	AccAMD a;
	a.menu();	
}
