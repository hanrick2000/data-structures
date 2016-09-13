#include<iostream>
#include<cstring>
#include<map>
using namespace std;

bool checkIfHighVowel(string str)
{
	map<char,bool> my_map;
	my_map['a']=true;
	my_map['e']=true;
	my_map['i']=true;
	my_map['o']=true;
	my_map['u']=true;
	int vowels=0,consonant=0;
	for(int i=0;i<str.length();i++)
	{
		if(my_map[str[i]]==true)
		{
			vowels++;
		}	
		else
		{
			consonant++;
		}	
	}	

	//cout<<vowels<<" "<<consonant<<" "<<endl;

	if(vowels<consonant)
	{
		return false;
	}	

	int flag=0;

	for(int i=0;i<str.length()-1;i++)
	{
		if(my_map[str[i]]==true && my_map[str[i+1]]==true)
		{
			flag=1;
			return true;
		}
	}	

	if(flag==0)
		return false;


}

int main()
{
	string str;
	cin>>str;
	bool val=checkIfHighVowel(str);
	cout<<val<<endl;
	return 0;
}