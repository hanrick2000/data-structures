#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

/*
   return the generated subsets
*/

void generateSubsets1(vector<vector<int> > &subsets,int str[],int index)
{
    if(index<0)
    {
        subsets.push_back(vector<int>());
        return;
    }    

    generateSubsets1(subsets,str,index-1);

    int v_size=subsets.size();
    for(int i=0;i<v_size;++i)
    {
        vector<int> subsubsets(subsets[i]);
        subsubsets.push_back(str[index]);
        subsets.push_back(subsubsets);
    }    
}
 
void printSubsets(vector<vector<int> > v)
{
    int size1=v.size();
    for(int i=0;i<size1;++i)
    {
        cout<<"[ ";
        for(int j=0;j<v[i].size();++j)
        {
            cout<<v[i][j]<<" ";
        }    
        cout<<" ]";
        cout<<endl;
    }    
}

/*
  Simply prints the subsets.
*/

void generateSubsets2(int arr[],int temp[],int startIndex,int tempIndex,int len)
{
    if(startIndex==len)
    {
        cout<<"[ ";
        for(int i=0;i<tempIndex;i++)
        {
            cout<<temp[i]<<" ";
        }    
        cout<<"]"<<endl;
        return;
    }    

    temp[tempIndex]=arr[startIndex];
    
    generateSubsets2(arr,temp,startIndex+1,tempIndex+1,len);

    temp[tempIndex]=0;

    generateSubsets2(arr,temp,startIndex+1,tempIndex,len);

}



int main()
{
    int arr[]={1,2,3,4};
    int temp[4];
    int size=sizeof(arr)/sizeof(arr[0]);
    generateSubsets2(arr,temp,0,0,size);
    return 0;
}



