#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;



/*
  Returning the subsequences.
*/
void generateSubsequences1(vector<vector<char> > &subsequences,char str[],int index)
{
    if(index<0)
    {
        subsequences.push_back(vector<char>());
        return;
    }    

    generateSubsequences1(subsequences,str,index-1);

    int v_size=subsequences.size();
    for(int i=0;i<v_size;++i)
    {
        vector<char> subsubsequences(subsequences[i]);
        subsubsequences.push_back(str[index]);
        subsequences.push_back(subsubsequences);
    }    
}
 
void printSubSequences(vector<vector<char> > v)
{
    int size1=v.size();
    for(int i=0;i<size1;++i)
    {
        for(int j=0;j<v[i].size();++j)
        {
            cout<<v[i][j];
        }    

        cout<<endl;
    }    
}


/*
   printing along
*/
void generateSubsequences(char* s,char* temp,int startIndex,int tempIndex,int len)
{
    if(startIndex==len)
    {
    	cout<<temp<<endl;
    	return;
    }	

    temp[tempIndex+1]=s[startIndex];
    generateSubsequences(s,temp,startIndex+1,tempIndex+1,len);

    temp[tempIndex+1]='\0';/*	terminate the string 	*/
    generateSubsequences(s,temp,startIndex+1,tempIndex,len);


}

int main()
{

    char str[4]="abc";
    char temp[4]; 
    int len=strlen(str);
    generateSubsequences(str,temp,0,-1,strlen(str));
    // vector<vector<char> > v;

    // generateSubsequences1(v,str,len-1);
    // printSubSequences(v);
 


	return 0;
}