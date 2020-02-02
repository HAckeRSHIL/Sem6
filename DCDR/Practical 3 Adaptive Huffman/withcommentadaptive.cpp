//Problematic Test case : AARDVARK  (FIX THIS)

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
typedef struct node
{
	int weight,num;
	char ch;
	struct node *left;
	struct node *right;
}node;

//GLOBAL DEFINATIONS
typedef node* branch;
branch root=NULL;
string encoded,input,decoded,ans;
vector<char> v;
int flag=0;
char lastch;
branch new_branch()      //alloting memory
{
	branch nn;
	nn=new node();
	nn->left=NULL;
	nn->right=NULL;
	nn->weight=1;
	nn->ch='*';
	return nn;
} 
void NodePath(branch temp,char c, string &str)			//str is saved to store path of needed character
{
//	cout<<endl<<temp->ch<<endl;
	if(c==temp->ch)
	{
		if(c=='#')
		{
			branch l=new_branch();
			branch r=new_branch();
			temp->left=l;
			temp->right=r;
			temp->ch='*';
			temp->right->ch=lastch;
			temp->left->ch='#';
			temp->left->weight=0;
			//cout<<"TEMP num : "<<temp->num;
			l->num=temp->num-2;
			r->num=temp->num-1;
		}
		else
			temp->weight++;
		flag=1;
	}
	if(temp->left!=NULL && flag==0)
	{
		str+="0";
		NodePath(temp->left,c,str);
	}
	if(temp->right!=NULL && flag==0)
	{
		if(str.substr(str.size()-1)=="1")
			str=str.substr(0,str.size()-1);
		str=str.substr(0,str.size()-1);
		str+="1";
		NodePath(temp->right,c,str);
	}
}

string getbinary(int n,int bit)   //converting int to 8 bit binary
{
	string str;
    for (int i=(bit-1);i>=0;i--)
    { 
        int k=n>>i; 
        if(k&1) 
          	str+="1"; 
        else
            str+="0"; 
    }
    return str;
}
string findcode(char c)
{
	int x=c;
	string code;
	if(x>=65 && x<=92)
	{
		x=x-65;
		code=getbinary(x,6);
	}
	else if(x>=97 && x<=110 )
	{
		x=x-71;
		code=getbinary(x,6);
	}
	else
	{
		x=x-91;
		code=getbinary(x,5);
	}
	return code;
}
char findchar(int v,int k)
{
	 if(k==5)
		v+=91;
	else if(v<=25 && k==6)
		v+=65;
	else if(v>=26 && k==6)
		v+=71;
	return char(v);
}
void createtree()
{
	branch nn=new_branch();      //alloting memory for new node
	nn->weight=0;
	nn->ch='#';
	encoded+=findcode(input[0]);
	branch par=new_branch();
	branch child=new_branch();
	par->left=nn;
	par->right=child;
	par->weight=1;
	par->num=103;
	par->left->num=101;
	par->right->num=102;
	child->ch=input[0];
	root=par;
	cout<<"New Tree Created with node characters : '*'(Internal Node) , '#'(NYT Node), "<<input[0]<<"(First character Node)"<<endl;
	v.push_back(input[0]);
}
int isfound(char c)
{
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==c)
			return true;
	}
	return false;
}
bool entry=false;
void Rebalance(branch temp)
{
	if(temp->left->left!=NULL && temp->left->right!=NULL)		//only go to the node if it have childs
		Rebalance(temp->left);
	if(temp->right->left!=NULL && temp->right->right!=NULL)		//in other words dont go to leaf nodes 
		Rebalance(temp->right);
	if(temp->left->ch=='#')      //NYT found so start summing the nodes from there
		entry=true;
	if(entry)				//if NYT is discovered then start taking some of node and add them in parent
	{
		temp->weight=temp->left->weight+temp->right->weight;
		if(temp->left->weight > temp->right->weight)
			{
				cout<<"\n\t\t\t\t\tSWAPPING  "<<temp->left->weight<<" with "<<temp->right->weight;
				swap(temp->left , temp->right);
				swap(temp->left->num , temp->right->num);
			}
		cout<<"\n\t\t\t\t\tSUM of "<<temp->left->ch<<" and "<<temp->right->ch<< " is "<<temp->weight;
	}
}

void travel(branch temp)
{
	if(temp!=NULL)
	{
		printf("%d  ",temp->num);
		travel(temp->right);	
		travel(temp->left);
	}
}
char finder(int &i)
{
	int sum=0,k=6;
	
	if(decoded[i]=='1' && (decoded[i+1]=='1'||decoded[i+2]=='1'))
		k=5;
	string code=decoded.substr(i,k);
	cout<<endl<<code;
	i+=k;
	for(int j=0;j<k;j++)
	{
		if(code[j]=='1')
			sum+=pow(2,k-1-j);		//find the decimal of corrosponding binary string
	}
	cout<<"k : "<<k;
	char c=findchar(sum,k);
	ans+=c;
	cout<<"\nFound : "<<c;
	return c;
}
void gotopath(string &path,branch temp,int &i)
{
	cout<<"\nPath : "<<path;
	for(int j=0;j<path.size();j++)
	{
		if(path[j]=='1')
			temp=temp->right;
		else if(path[j]=='0')
			temp=temp->left;
	}
	cout<<"Reached to the ";
	if(temp->ch=='#')
	{
		cout<<" reached to NYT";
		i++;
		branch l=new_branch();
		branch r=new_branch();
		temp->left=l;
		temp->right=r;
		temp->ch='*';
		temp->right->ch=finder(i);
		temp->left->ch='#';
		temp->left->weight=0;
		l->num=temp->num-2;
		r->num=temp->num-1;
		path.clear();
	}
	else if(temp->ch!='*')
	{
		cout<<"reached";
		i++;
		temp->weight++;
		cout<<temp->ch<<" incremented : "<<temp->weight;
		ans+=temp->ch;
		path.clear();
	}
	else
		i++;
	Rebalance(root);
}
int main()
{
	ifstream inFile;
	inFile.open("Originaladaptive.txt");
	char t;
	while(inFile>>t)
	{
		input+=t;
	}
	createtree();
	for(int i=1;i<input.length();i++)
	{
		flag=0;
		string strcode;
		if(isfound(input[i]))
		{
			NodePath(root,input[i],strcode);
			encoded+=strcode;
			cout<<"\nPath to "<<input[i]<<" : "<<strcode;	
		}
		else 
		{
			lastch=input[i];			//variable saved show recent found char(will be used in NodePath)
			v.push_back(input[i]);		//save in the discovered char vector
			NodePath(root,'#',strcode);
			cout<<"\nPath to NYT for finding "<<input[i]<< " : "<<strcode;
			encoded+=strcode;
			string charcode=findcode(input[i]);
			encoded+=charcode;
			cout<<"\nAdd new character "<<input[i]<<" of code : "<<charcode;			
		}
		Rebalance(root);
		entry=false;	
	}
	cout<<endl<<"Tree Travsersal : ";
	travel(root);
	cout<<endl;
	cout<<"\nSet : ";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<"  ";
	}
	cout<<"\nEncoded : "<<encoded;
	int i=0;
	inFile.close();
	ofstream outFile;
	outFile.open("Compressedadaptive.txt");
	int repeat=encoded.size()/8;
	int len=repeat;
	int remained=encoded.size()%8;
	while(repeat--)
	{
		int sum=0;
		string chopped=encoded.substr(i,8);
		for(int j=0;j<8;j++)
		{
			if(chopped[j]=='1')
				sum+=pow(2,7-j);		//find the decimal of corrosponding binary string
		}
		i+=8;					//for next 8 bits
	
		cout<<"\nChopped String : "<<chopped<<" Decimal : "<<sum;
		char c=sum;
		outFile<<c;
	}
	int sum=0;
	string chopped=encoded.substr(i);
	for(int j=0;j<remained;j++)
	{
		if(chopped[j]=='1')
			sum+=pow(2,7-j);
	}
	cout<<"\nChopped String : "<<chopped<<" Decimal : "<<sum;
	char c=sum;
	outFile<<c;
	cout<<"\n--------------------End of encoding--------------------\n";
	outFile.close();
	inFile.close();
	inFile.open("Compressedadaptive.txt",ios::in | ios::binary);
	outFile.open("Outputadaptive.txt");
	inFile>>std::noskipws;
	while(!inFile.eof())
	{
		char x;
		int y;
		inFile>>x;
		if(inFile.eof())
			break;
		if((int)x<0)
			y=(int)x+256;
		else if(x==13)
		{
			if(inFile.peek()==10)
				inFile>>x;
			y=(int)x;
		}
		else
			y=(int)x;
			cout<<"\nChopped String : "<<getbinary(y,8)<<" Decimal : "<<y;
			decoded+=getbinary(y,8);
	}
	/*while(inFile>>c)
	{
		int dec=c;
			if(dec<0)
			dec+=256;
		cout<<"\nChopped String : "<<getbinary(dec,8)<<" Decimal : "<<dec;
		decoded+=getbinary(dec,8);
	}*/
	decoded=decoded.substr(0,8*len+remained);
	cout<<endl<<"Decoded : "<<decoded;
	i=0;
	char x=finder(i);
	branch nn=new_branch();      //alloting memory for new node
	nn->weight=0;
	nn->ch='#';
	branch par=new_branch();
	branch child=new_branch();
	par->left=nn;
	par->right=child;
	child->ch=x;
	root=par;
	par->num=103;
	child->num=102;
	nn->num=101;
	string path;
	while(1)
	{	
		if(input.length()==ans.length())
			break;
		path+=decoded[i];
		gotopath(path,root,i);
		if(i>=decoded.length())
			break;
	}
	travel(root);
	cout<<endl<<ans;
	outFile<<ans;
}
