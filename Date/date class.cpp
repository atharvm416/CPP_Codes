#include <iostream>
using namespace std;
class date2;
class date1
{
		int day,mon,year;
	public:
		void setDate()
		{
			cout<<"\nEnter Year:";
			cin>>year;
			while(1)
			{
				cout<<"\nEnter Month:";
				cin>>mon;
				if(mon>=1&&mon<=12)
					break;
			}
			while(1)
			{
				cout<<"\nEnter Day:";
				cin>>day;
				if(day<1||day>31)
					continue;
				if(day>=1&&day<=28)
					break;
				else
				{
					if(day==31&&(mon==2||mon==4||mon==6||mon==9||mon==11))
						continue;
					else
					{
						if(day<=31&&mon!=2)
							break;
						else
						{
							if(year%4==0&&mon==2&&day<=29)
								break;
							else
								continue;
						}
					}
				}
			}
		}
		void printDate()
		{
			cout<<day<<'/';
			cout<<mon<<'/';
			cout<<year<<endl;
		}
		void incDate()
		{
			day++;
		}
		void decDate()
		{
			day--;
		}
		friend void diff(date1 &,date2 &);
};
class date2
{
		int day,mon,year;
	public:
		void setDate()
		{
			cout<<"\nEnter Year:";
			cin>>year;
			while(1)
			{
				cout<<"\nEnter Month:";
				cin>>mon;
				if(mon>=1&&mon<=12)
					break;
			}
			while(1)
			{
				cout<<"\nEnter Day:";
				cin>>day;
				if(day<1||day>31)
					continue;
				if(day>=1&&day<=28)
					break;
				else
				{
					if(day==31&&(mon==2||mon==4||mon==6||mon==9||mon==11))
						continue;
					else
					{
						if(day<=31&&mon!=2)
							break;
						else
						{
							if(year%4==0&&mon==2&&day<=29)
								break;
							else
								continue;
						}
					}
				}
			}
		}
		void printDate()
		{
			cout<<day<<'/';
			cout<<mon<<'/';
			cout<<year<<endl;
		}
		void incDate()
		{
			day++;
		}
		void decDate()
		{
			day--;
		}
		friend void diff(date1 &,date2 &);
};
void diff(date1 &x,date2 &y)
{
	int tday[2];
		if(x.year>=2001)
		{
			tday[0]=x.day;
			for(int i=x.mon-1;i>=1;i--)
			{
				if(i==3||i==5||i==7||i==8||i==10||i==12)
					tday[0]=tday[0]+31;
				else
				{
					if(i!=2)
						tday[0]=tday[0]+30;
					else
					{
						if(x.year%4==0)
							tday[0]=tday[0]+29;
						else
							tday[0]=tday[0]+28;
					}
				}
			}
			for(int i=x.year;i>2001;i--)
			{
				if(i%4==0)
					tday[0]=tday[0]+366;
				else
					tday[0]=tday[0]+365;
			}
		}
		else
		{
			if(x.mon==1||x.mon==3||x.mon==5||x.mon==7||x.mon==8||x.mon==10||x.mon==12)
				tday[0]=30-x.day;
			else
			{
				if(x.mon!=2)
					tday[0]=29-x.day;
				else
				{
					if(x.year%4==0)
						tday[0]=28-x.day;
					else
						tday[0]=27-x.day;
				}
			}
			for(int i=x.mon+1;i<=12;i++)
			{
				if(i==3||i==5||i==7||i==8||i==10||i==12)
					tday[0]=tday[0]+31;
				else
				{
					if(i!=2)
						tday[0]=tday[0]+30;
					else
					{
						if(x.year%4==0)
							tday[0]=tday[0]+29;
						else
							tday[0]=tday[0]+28;
					}
				}
			}
			for(int i=x.year+1;i<2001;i++)
			{
				if(i%4==0)
					tday[0]=tday[0]+366;
				else
					tday[0]=tday[0]+365;
			}
		}
	if(y.year>=2001)
		{
			tday[1]=y.day;
			for(int i=y.mon-1;i>=1;i--)
			{
				if(i==3||i==5||i==7||i==8||i==10||i==12)
					tday[1]=tday[1]+31;
				else
				{
					if(i!=2)
						tday[1]=tday[1]+30;
					else
					{
						if(y.year%4==0)
							tday[1]=tday[1]+29;
						else
							tday[1]=tday[1]+28;
					}
				}
			}
			for(int i=y.year;i>2001;i--)
			{
				if(i%4==0)
					tday[1]=tday[1]+366;
				else
					tday[1]=tday[1]+365;
			}
		}
		else
		{
			if(y.mon==1||y.mon==3||y.mon==5||y.mon==7||y.mon==8||y.mon==10||y.mon==12)
				tday[1]=30-x.day;
			else
			{
				if(y.mon!=2)
					tday[1]=29-y.day;
				else
				{
					if(y.year%4==0)
						tday[1]=28-y.day;
					else
						tday[1]=27-y.day;
				}
			}
			for(int i=y.mon+1;i<=12;i++)
			{
				if(i==3||i==5||i==7||i==8||i==10||i==12)
					tday[1]=tday[1]+31;
				else
				{
					if(i!=2)
						tday[1]=tday[1]+30;
					else
					{
						if(y.year%4==0)
							tday[1]=tday[1]+29;
						else
							tday[1]=tday[1]+28;
					}
				}
			}
			for(int i=y.year+1;i<2001;i++)
			{
				if(i%4==0)
					tday[1]=tday[1]+366;
				else
					tday[1]=tday[1]+365;
			}
		}
	if((x.year>=2001&&y.year>=2001)||(x.year<2001&&y.year<2001))
	{
		if(tday[0]>tday[1])
			printf("\nDate difference is %ld",(tday[0]-tday[1]));
		else
			printf("\nDate difference is %ld",(tday[1]-tday[0]));
	}
	else
		printf("\nDate difference is %ld",(tday[0]+tday[1]));
}
int main()
{
	date1 p;
	date2 q;
	p.setDate();
	q.setDate();
	p.printDate();
	q.printDate();
	p.incDate();
	q.decDate();
	p.printDate();
	q.printDate();
	diff(p,q);
	return 0;
}
