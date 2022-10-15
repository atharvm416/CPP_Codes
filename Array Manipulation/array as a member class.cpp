#include <iostream>
#define M 5
using namespace std;
class Array
{
		int x[M];
	public:
		void init();
		void setdata();
		void display();
		int caltot();
		int calavg()
		{
			return caltot()/M;
		}
		int findmax();
		int findmin();
		int search(int sv);
		void findrepl(int sv,int rv);
		int isordered();
};
void Array::init()
{
	int i=0;
	while(i<M)
	{
		x[i]=0;
		i++;
	}
}
int Array::caltot()
{
	int i,tot=0;
	for(i=0;i<M;i++)
	{
		tot=tot+x[i];
	}
	return tot;
}
void Array::display()
{
	cout<<"\nData:";
	for(int i=0;i<M;i++)
	{
		cout<<" "<<x[i];
	}
}
void Array::setdata()
{
	cout<<"\nData:";
	for(int i=0;i<M;i++)
		cin>>x[i];
}
int Array::findmax()
{
	int max=x[0],i=1;
	while(i<M)
	{
		if(x[i]>max)
			max=x[i];
		i++;
	}
	return max;
}
int Array::findmin()
{
	int min=x[0],i=1;
	while(i<M)
	{
		if(x[i]<min)
			min=x[i];
		i++;
	}
	return min;
}
int Array::search(int sv)
{
	int i=0;
	while(i<M)
	{
		if(x[i]==sv)
			return 1;
		i++;
	}
	return 0;
}
void Array::findrepl(int a,int b)
{
	int i=0;
	while(i<M)
	{
		if(x[i]==a)
		{
			x[i]=b;
			cout<<"Number Replaced";
			break;
		}
		i++;
	}
	if(i==M)
		cout<<"Not found";
}
int Array::isordered()
{
	int i=1;
	while(i<M)
	{
		if(x[i]<x[i-1])
			break;
		i++;
	}
	return (i==M);
}
int main()
{
	Array d;
	int opt,a,b;
	d.setdata();
	d.display();
	if(d.isordered()==1)
		cout<<"\nOrdered";
	else
		cout<<"\nUnordered";
		while(1)
		{
			cout<<"\n\nMenu\n1. Enter New Data\n2. Display\n3. Total\n4. Average\n5. Find Max\n6. Find Min\n7.Find and Replace\n8.Exit\nOptions :";
			cin>>opt;
			if(opt==8)
				break;
			switch(opt)
			{
				case 1:
					d.setdata();
					d.display();
					break;
				case 2:
					d.display();
					break;
				case 3:
					cout<<"\nTotal:"<<d.caltot();
					break;
				case 4:
					cout<<"\nAverage:"<<d.calavg();
					break;
				case 5:
					cout<<"\nMaximum value is :"<<d.findmax();
					break;
				case 6:
					cout<<"\nMinimum value is :"<<d.findmin();
					break;
				case 7:
					cout<<"\nEnter a number to find :";
					cin>>a;
					cout<<"\nEnter a number to Replace :";
					cin>>b;
					d.findrepl(a,b);
					break;
				default:
					cout<<"\n You Have Entered Wrong Number";
			}
		}
	return 0;
}
