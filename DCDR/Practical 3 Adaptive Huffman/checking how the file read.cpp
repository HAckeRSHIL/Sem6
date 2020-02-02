//this works perfect
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i=0;
	ofstream outFile;
	outFile.open("allansiisavedhere.txt"); 
	for(i=0;i<256;i++)
	{
		outFile<<(char)i;
	}
	outFile.close();
	ifstream inFile("allansiisavedhere.txt",ios::in|ios::binary);
	inFile>>std::noskipws;
	char c;
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
				cout<<256-i<<"    "<<y<<endl;
		i--;
	}
	inFile.close();
}
