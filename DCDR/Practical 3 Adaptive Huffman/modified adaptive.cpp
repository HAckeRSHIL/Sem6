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
branch root=NULL,save=NULL;
string encoded,input,decoded,ans;
vector<char> v;
int flag=0,child=-1;
char lastch;
bool entry=false;

//FUNCTION DECLARATION
branch new_branch(char,int,int);
void NodePath(branch,char , string &);
string getbinary(int,int);
string findcode(char);
char findchar(int,int);
void createtree();
int isfound(char);
void travel(branch);
void Rebalance(branch);
char getChar(int &);
void gotopath(string &,branch,int &);
void deletetree(branch);
void largestInBlock(branch,int,int&);

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
	branch temp;
	for(int i=1;i<input.length();i++)
	{
		flag=0;
		temp=root;
		string strcode;
		if(isfound(input[i]))
		{
			NodePath(temp,input[i],strcode);
			encoded+=strcode;
			cout<<"\nPath to "<<input[i]<<" : "<<strcode;	
		}
		else 
		{
			lastch=input[i];
			v.push_back(input[i]);
			NodePath(temp,'#',strcode);
			cout<<"\nPath to NYT for finding "<<input[i]<< " : "<<strcode;
			encoded+=strcode;
			string charcode=findcode(input[i]);
			encoded+=charcode;
			cout<<"\nAdd new character "<<input[i]<<" of code : "<<charcode;			
		}
		Rebalance(root);
		entry=false;	
	}
	cout<<endl<<"Traversal In Tree(node->num) : ";
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
	outFile<<(char)sum;
	cout<<"\n--------------------End of encoding--------------------";
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
	cout<<"\n--------------------End of Decoding--------------------";
	deletetree(root);
	decoded=decoded.substr(0,8*len+remained);
	cout<<endl<<"Decoded : "<<decoded;
	i=0;
	char x=getChar(i);
	branch nn=new_branch('*',0,101);      //alloting memory for new node
	nn->weight=0;
	nn->ch='#';
	branch par=new_branch('*',1,103);
	branch child=new_branch(x,1,102);
	par->left=nn;
	par->right=child;
	root=par;
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
	
	cout<<endl<<"Traversal In Tree(node->num) : ";	
	travel(root);
	cout<<endl<<"Decoded : "<<ans;
	outFile<<ans;
	if(decoded==encoded)
		cout<<"\nSTATUS[OK]      : The Decoded binary 100% matches with Encoded binary.......";
	else
		cout<<"\nSTATUS[FAIL] : Decoded binary does match with encoded binary........";
	if(input==ans)
		cout<<"\nSTATUS[SUCCESS] : The Decoded string 100% matches with Encoded string.......";
	else
		cout<<"\nSTATUS[FAIL] : Decoded string does match with encoded string........";
}


branch new_branch(char c,int w,int n)      //alloting memory
{
	branch nn;
	nn=new node();
	nn->left=NULL;
	nn->right=NULL;
	nn->weight=w;
	nn->num=n;
	nn->ch=c;
	return nn;
} 
void NodePath(branch temp,char c, string &str)
{
	if(c==temp->ch)
	{
		if(c=='#')
		{
			branch l=new_branch('#',0,temp->num-2);
			branch r=new_branch(lastch,1,temp->num-1);
			temp->left=l;
			temp->right=r;
			temp->ch='*';		//overwrite the old nyt(#) with *(internal node)
		}
		else
		{
			temp->weight++;
			int largest=-1;
			cout<<"\nCheck for : "<<temp->weight-1;
			largestInBlock(root,temp->weight-1,largest);
			cout<<"\nLARGEST FOUND : "<<largest-52;
			if(largest>temp->num &&temp!=root )
			{
				cout<<"\nSTATUS[REFRESH] : change the nodes "<<temp->num-52<<"  ";
				if(child==0)
				{
					cout<<save->left->num-52;
					branch t;
					t=save->left;
					save->left=temp;
					temp=t;
					int te;
					te=save->left->num;
					save->left->num=temp->num;
					temp->num=te;
				//	temp=save->left;
					
				}
				else
				{
					cout<<save->right->num-52;
					branch t;
					t=save->left;
					save->left=temp;
					temp=t;
					
					int te;
					te=save->left->num;
					save->left->num=temp->num;
					temp->num=te;
				//	temp=save->right;
				}	
			}	
			save=NULL;
			child=-1;
		}
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
	branch nn=new_branch('#',0,101);      //alloting memory for new node
	encoded+=findcode(input[0]);
	branch par=new_branch('*',1,103);
	branch child=new_branch(input[0],1,102);
	par->left=nn;
	par->right=child;
	root=par;
	cout<<"New Tree Created with node characters : '*'(Internal Node) , '#'(NYT Node), "<<input[0]<<"(First character Node)";
	cout<<"\nFor Next character...";
	v.push_back(input[0]);		//saving discovered char in vector
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
void Rebalance(branch temp)
{
	if(temp->left->left!=NULL )		//only go to the node if it have childs
		Rebalance(temp->left);
 if(temp->right->left!=NULL )		//in other words dont go to leaf nodes 
		Rebalance(temp->right);
 if(temp->left->ch=='#')      //NYT found so start summing the nodes from there
		entry=true;
	if(entry)				//if NYT is discovered then start taking some of node and add them in parent
	{
		temp->weight=temp->left->weight+temp->right->weight;
		cout<<"\n\t\t\t\t\tSUM of "<<temp->left->ch<<" and "<<temp->right->ch<< " is "<<temp->weight;
		cout<<"\n\t\t\t\t\tNUM of "<<temp->left->num-52<<" and "<<temp->right->num-52<< " is "<<temp->weight;
		
		if(temp->left->weight > temp->right->weight)
			{
				cout<<"\n\t\t\t\t\tSWAPPING  "<<temp->left->weight<<" with "<<temp->right->weight;
				swap(temp->left->num , temp->right->num);
				swap(temp->left , temp->right);
			//	swap(temp->left->num , temp->right->num);
			}
		else
		{	
		if(temp->weight>1 && temp!=root)
		{
		int largest=-1;
			cout<<"\nCheck for : "<<temp->weight-1;
			largestInBlock(root,temp->weight-1,largest);
			cout<<"\nLARGEST FOUND : "<<largest-52;
			if(largest>temp->num )
			{
				cout<<"\nSTATUS[REFRESH] : change the nodes "<<temp->weight<<"  ";
				if(child==0)
				{
					cout<<save->left->weight;
					branch t;
					t=save->left;
					save->left=temp;
					temp=t;
					
//					int te;
//					te=save->left->num;
//					save->left->num=temp->num;
//					temp->num=te;
//					temp=save->left;
					
				}
				else
				{
					cout<<save->right->weight;
						branch t;
					t=save->left;
					save->left=temp;
					temp=t;
					
//					int te;
//					te=save->left->num;
//					save->left->num=temp->num;
//					temp->num=te;
//				//	temp=save->right;
				}	
			}	
			save=NULL;
			child=-1;
		}
	}
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
char getChar(int &i)
{
	int sum=0,k=6;
	if(decoded[i]=='1' && (decoded[i+1]=='1'||decoded[i+2]=='1'))
		k=5;
	string code=decoded.substr(i,k);
	i+=k;
	for(int j=0;j<k;j++)
	{
		if(code[j]=='1')
			sum+=pow(2,k-1-j);		//find the decimal of corrosponding binary string
	}
	char c=findchar(sum,k);
	cout<<endl<<"STATUS[MATCHED] : "<<code<<" matches with "<<c<<" where k = "<<k;
	ans+=c;
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
	if(temp->ch=='#')
	{
		cout<<" reaches to NYT means the next k bits shows new character.";
		i++;
		branch l=new_branch('#',0,temp->num-2);
		branch r=new_branch(getChar(i),1,temp->num-1);
		temp->left=l;
		temp->right=r;
		temp->ch='*';  //overwrites old nyt data to make internal node
		path.clear();
	}
	else if(temp->ch!='*')		//if it not a internal node(means it is leafnode)
	{
		i++;
		temp->weight++;
		cout<<" reached to Leaf Node where character saved is "<<temp->ch<<"  and weight increaded to the "<<temp->weight;
		ans+=temp->ch;
		cout<<"\nSTATUS[CLEANING] : Clear Old Path Data";
		path.clear();
	}
	else
	{
		cout<<" leads to internal node.\nSTATUS[TRY AGAIN] :  by adding next bit in the path string.";
		i++;
	}
	Rebalance(root);
}
void largestInBlock(branch temp,int v,int &largest)
{
	if(temp->left!=NULL)
	{
	//	cout<<"\nWEIGHT : "<<temp->weight <<"  Largest : "<<largest<<"  temp->num : "<<temp->num;
		if(v==temp->left->weight && largest < temp->left->num )
		{
			largest=temp->left->num;
			save=temp;
			child=0;
	//		cout<<"  MODIFIED";
		}
		if(v==temp->right->weight && largest < temp->right->num )
		{
			largest=temp->right->num;
			save=temp;
			child=1;
	//		cout<<"  MODIFIED";
		}
		largestInBlock(temp->left,v,largest);
		largestInBlock(temp->right,v,largest);
	}
}
void deletetree(branch tree)
{
	if(tree!=NULL)
	{
		deletetree(tree->left);
		deletetree(tree->right);
		free(tree);
	}
}

