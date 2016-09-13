#include<iostream>
#include<cstring>
using namespace std;

/*
	This converts to postfix and also calculates the values!
*/





int main()
{
	vector<string> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		v.push_back(str);
	}	

	vector<string> result=convertToPostfix()

	return 0;
}