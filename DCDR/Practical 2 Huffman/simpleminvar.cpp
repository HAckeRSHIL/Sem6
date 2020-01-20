#include <bits/stdc++.h>
using namespace std;
struct bind
{
	char c;
	float val;
	string code;
	int left,right;
}data[100];
int first=0,n,capacity;
void printlist()
{
	cout<<"\nList : ";
	for(int i=0;i<n;i++)
	{
		if(i==first)
			cout<<" | ";
		cout<<data[i].val<<" ";
	}
}
void assign(int index,string s)
{
	data[index].code+=s;
	if(data[index].left!=-1)
		assign(data[index].left,s);
	if(data[index].right!=-1)
		assign(data[index].right,s);
}
void huffman()
{
	if(data[first+1].val==0 || (data[first].val==0 && first!=0))
		return;
	for(int i=0;i<n-1;i++)		//sorting
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(data[j].val > data[j+1].val )
			{
				swap(data[j],data[j+1]);
			}
		}
	}
	printlist();
	float temp;
	cout<<endl<<data[first].val<<" + "<<data[first+1].val<<" = ";
	
	temp=data[first+1].val+data[first].val; //taking sum of 2 smallest number  
	cout<<temp;
	data[n].left=first;
	data[n].right=first+1;
	data[n].val=temp;				//making a new entry in array of struct 
	cout<<"\nNew Added "<<data[n].val<<" left index : "<<data[n].left<<" right index : "<<data[n].right<<endl;
	assign(first,"0");			//assign 0s to left part children
	assign(first+1,"1");		//assign 1s to right part children
	first+=2;				
	n++;			
	cout<<"first : "<<first<<" capacity : "<<capacity<<endl;
	huffman();
}
int main()
{
	cout<<"How many number you want to enter : ";cin>>n;
	capacity=n;
	for(int i=0;i<n;i++)
	{
		cout<<"Character : ";cin>>data[i].c;
		cout<<"Frequency : ";cin>>data[i].val;
		data[i].left=-1;
		data[i].right=-1;
	}
	printlist();
	huffman();
	cout<<"\nCharacter\tCodeword\n";
	for(int i=n;i>=0;i--)
	{
		if(data[i].c!=NULL)
		{
		reverse(data[i].code.begin(), data[i].code.end()); 
		cout<<data[i].c<<"\t\t"<<data[i].code<<endl;
		}
	}
}
