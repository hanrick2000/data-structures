#include <iostream>
#include<cstring>
#include<map>
#include<cstdio>
using namespace std;

int main()
{
    
    char ch[1000];
    string ch1,ch2;
    gets(ch);
    cin>>ch1;
    cin>>ch2;
    int count=0;
    map<int,string> my_map;
    
    for(int i=0;ch[i]!='\0';i++)
    {
        if(ch[i]==' ')
          count++;
        else
          my_map[count]+=ch[i];
    }
    
    //cout<<"The value of count is "<<count<<endl;
    int swap1,swap2;
    
    for(int i=0;i<=count;i++)
    {
        if(my_map[i].compare(ch1)==0)
        {
            swap1=i;
        }
        else if(my_map[i].compare(ch2)==0)
        {
            swap2=i;
        }
        
    }
    
    //cout<<swap1<<swap2<<endl;
    
    string temp=my_map[swap1];
    my_map[swap1]=my_map[swap2];
    my_map[swap2]=temp;
    
    
    for(int i=0;i<=count;i++)
    {
        cout<<my_map[i]<<' ';
    }
    
    
    
    return 0;
}
