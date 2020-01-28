#include <bits/stdc++.h>
using namespace std;

struct bind
{
	char c;
	float val;
	string code;
	int left,right;
}data[100];

int first=0,n=0;
vector<int> v,avoid;

int isfound(int value)
{
	for(int i=0;i<avoid.size();i++)
	{
		if(avoid[i]==value)
			return true;
	}
	return false;
}
int check(string matchit)
{
	for(int i=0;i<v.size();i++)
	{
		if(matchit==data[v[i]].code)
			return v[i];
	}
	return -1;
}
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

string getbinary(int n)   //converting int to 8 bit binary
{
	string str;
    for (int i = 7; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
          	str+="1"; 
        else
            str+="0"; 
    }
    return str;
}

void assign(int index,string s)
{
	data[index].code=s+data[index].code;
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
			if(data[j].val > data[j+1].val || data[j+1].val==data[j].val && data[j].c!=NULL && data[j+1].c==NULL)
				swap(data[j],data[j+1]);
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
	cout<<"\nAppended "<<data[n].val<<" left index : "<<data[n].left<<" right index : "<<data[n].right<<endl;
	assign(first,"0");			//assign 0s to left part children
	assign(first+1,"1");		//assign 1s to right part children
	first+=2;				
	n++;			
	huffman();
}

int main()
{	
	
	ifstream inFile;
	ofstream OutFile;
	std::map<char,int> trace;	//dict type data structure
	char text;
	int count=0;
    inFile.open("original.txt");
    if (!inFile) 
	{
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    inFile>>std::noskipws;
    while (inFile >> text)    //read char and save to text
	{
		count++;
        trace[text]++;     //key=text for occcurence count (increment for every occurence)
    }
    int i=0;
    map<char, int>::iterator itr;  
    cout << " KEY\tOCCURENCE\n"; 
    for (itr = trace.begin(); itr != trace.end(); ++itr) { 
       /* cout <<" "<< itr->first 
             <<"\t   " << itr->second << '\n'; */
        data[i].left=-1;
		data[i].right=-1;
		data[i].c=itr->first;			//assigning it to structure defined for process
		data[i++].val=itr->second;  
		n++;   
		cout <<" "<< data[i-1].c 
             <<"\t   " << data[i-1].val << '\n'; 
    } 
    inFile.close();
	printlist();
	huffman();
	std::map<char,string> findcode;			//for mapping purpose
	int k=0;
	cout<<"\nCharacter\tCodeword\n";
	for(int i=n;i>=0;i--)
	{
		if(data[i].left==-1 && data[i].right==-1)
		{
			findcode[data[i].c]=data[i].code;
			cout<<data[i].c<<"\t\t"<<findcode[data[i].c]<<endl;			//saving code in index as character so we can use later for retreival purpose  
			v.push_back(i);						//saving indexes of leaf nodes so we can easily traverse using vector
		}
	}
	ofstream outFile;
	outFile.open("Compressed.txt");
	inFile.open("original.txt");
	string str;
	int test=0;
	while(inFile>>text)
	{
		str+=findcode[text];		//add corrosponding code of character to string(binary)
		if(str.length()>8)			//if length exceeds 8 then start processing data
		{
			int sum=0;
			string w=str.substr(0,8);		//take first 8 characters of binary
			cout<<endl<<++test<<"   Chopped string : "<<w;
			for(int i=0;i<8;i++)
			{
				if(w[i]=='1')
					sum+=pow(2,7-i);		//find the decimal of corrosponding binary string
			}
			cout<<"\t Decimal : "<<sum;
			if(sum==26)						//avoid adding this element because it will cause end of file later on
			{	
				cout<<"  Skipped";
				avoid.push_back(test);
			}
			else
				outFile<<(char)sum;	
			str=str.substr(8);
		}
	}
	int sum=0;   //for remaining last characters which is less than 8
	cout<<endl<<++test<<"   Chopped string : "<<str;
	int cut=str.length();
	for(i=0;i<cut;i++)
		{
			if(str[i]=='1')
				sum+=pow(2,7-i);
		}
		cout<<"\t Decimal : "<<sum;
	outFile<<(char)sum;	
	inFile.close();
	outFile.close();
	inFile.open("compressed.txt");
	outFile.open("output.txt");
	string matchit;
	int dlen=0;
	int test2=0;
	while(inFile>>text)
	{
	
			int deci=(int)text;
			if(deci<0)
				deci+=256;
			string str=getbinary(deci);    //get binary of ansi value of recently read characters
			if(test-1==test2)			//if it the last character then cut according the previous data
				str=str.substr(0,cut);
			cout<<endl<<++test2<<"   Binary decoded : "<<str;
			cout<<"\tDecimal value : "<<deci;
			up:
			for(int i=0;i<8;i++)
			{
				matchit+=str[i];		//add characters and continue matching the code with table
				int index=check(matchit);		//-1 means not matched with any previous table
				if(index!=-1)
					{
						outFile<<data[index].c;	 dlen++;		//if found then add into output using the index returned from funcion
						matchit.clear();	
					}		
			}
			if(isfound(test2+1))			//check that is it need to add the avoided character to the string
				{
				 test2++;
				str="00011010";				//binary string of 26
				goto up;					//jump to the finding logic with new string
				}
	}
	cout<<"\nSize : "<<count<<"  Decoded Size : "<<dlen;			//to check all the characters decoded or not
}
