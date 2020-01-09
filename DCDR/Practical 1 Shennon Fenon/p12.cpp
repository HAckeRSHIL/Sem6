#include<iostream>
#include<vector>
using namespace std;
vector<string> v;
int main()
{
	
	bool f1=0,f2=0;
	int n;
	string temp,s;
	cout<<"How many numbers you want to enter :";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<") : ";
		cin>>temp;
		v.push_back(temp);	
	}	
	for(int i=0;i<n;i++)
	{
		int l;
		l=v[i].length();
		for(int j=0;j<n;j++)
		{
			if(v[j].substr(0,l)==v[i] && i!=j && f1==false)
			{
				int len=v[j].length();
				s=v[j].substr(l,len);
				f1=true;
				break;	
			}	
		}
	}
	
	if(f1==true)
	{
		int ln=s.length(),l2;	
		for(int i=0;i<n;i++)
		{
			if(v[i].substr(0,ln)==s)
			{
				l2=v[i].length();
				for(int j=0;j<n;j++)
				{
				if(v[i].substr(ln,l2)==v[j] && f2==false)
				{
					f2=true;			
					cout<<"--------------Not Uniquely decodable-------------------";
					break;
				}
				}
			}
		}
	}
	if(f2==false)
	{
		cout<<"-------------Uniquely Decodable---------------";
	}
}	

