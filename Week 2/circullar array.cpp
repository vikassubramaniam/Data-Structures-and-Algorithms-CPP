#include<iostream>
using namespace std;
#define max 100
int main()
{
	int a[max];
	int first=-1;
	int last=-1;
	int n,x,i;
	for(i=0;i<max;i++)
		a[i]=-1;
	while(1)
	{
		cout<<"\n1.Insert at beginning\n2.Insert at end\n3.Delete at beginning\n4.Delete at end\n5.Print\n6.Exit\nEnter your choice: ";
		cin>>n;
		switch(n)
		{
			case 1: cout<<"\nEnter the number: ";
					cin>>x;
					if(first==-1) //empty
					{
						first=last=0;
						a[first]=x;
					}
					else
					{
						if(first==0)
						{
							if(a[max-1]!=-1)
							{
								cout<<"\nArray is full";
							}	
							else
							{
								first=max-1;
								a[first]=x;
							}
						}
						else
						{
							if(a[first-1]!=-1)
							{
								cout<<"\nArray is full";
							}
							else
							{
								first=first-1;
								a[first]=x;
							}
						}
					}
					break;
			case 2: cout<<"\nEnter the number: ";
					cin>>x;
					if(last==-1) //empty
					{
						first=last=0;
						a[last]=x;
					}
					else
					{
						if(last==max-1)
						{
							if(a[0]!=-1)
							{
								cout<<"\nArray is full";
							}	
							else
							{
								last=0;
								a[last]=x;
							}
						}
						else
						{
							if(a[last+1]!=-1)
							{
								cout<<"\nArray is full";
							}
							else
							{
								last=last+1;
								a[last]=x;
							}
						}
					}
					break;
			case 3: if(first==-1)
					{
						cout<<"\nEmpty";
					}
					else if(first==last)
					{
						a[first]=-1;
						first=last=-1;
					}
					else
					{
						if(first==max-1)
						{
							a[first]=-1;
							first=0;
						}
						else
						{
							a[first]=-1;
							first=first+1;
						}
					}
					break;
			case 4: if(last==-1)
					{
						cout<<"\nEmpty";
					}
					else if(first==last)
					{
						a[last]=-1;
						first=last=-1;
					}
					else
					{
						if(last==0)
						{
							a[last]=-1;
							last=max-1;
						}
						else
						{
							a[last]=-1;
							last=last-1;
						}
					}
					break;
			case 5: if(first==-1)
					{
						cout<<"\nEmpty";
					}
					else
					{
						if(first<=last)
						{
							cout<<"\n";
							for(i=first;i<=last;i++)
								cout<<a[i]<<" ";
						}
						else
						{
							cout<<"\n";
							for(i=first;i<=max-1;i++)
								cout<<a[i]<<" ";
							for(i=0;i<=last;i++)
								cout<<a[i]<<" ";
						}
					}
					break;
			case 6: exit(1);
		}
	}	
	return 0;
}
