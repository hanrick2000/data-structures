#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
/*
string getString(int num)
{
	switch(num)
	{
		case 0: return "";
		case 1: return ",";
		case 2: return "abc";
		case 3: return "def";
		case 4: return "ghi";
		case 5: return "jkl";
		case 6: return "mno";
		case 7: return "pqrs";
		case 8: return "uvw";
		case 9: return "xyz";
        default: return " ";
	}
}*/
/*
    Method 1:This returns all  strings.
  
*/

 

// void generatePatterns2(vector<char> v[5],vector<string> &res,int* a,int subIndex,int index,int len)
// {
//     if(index==len)
//     {
//        temp[index]='\0';
//        string x=str(temp);
//        cout<<x<<endl;
//        res.push_back(x);
//        return;
//     }
    
//     vector<char> :: iterator it;
//     for(it=v[a[index]].begin();it!=v[a[index]].end();it++)
//     {
//     	temp[subIndex+1]=*it;
//     	generatePatterns2(v,res,a,subIndex+1,index+1,len);
//     }	

// }




string getString(int n) {
  if (n == 2) {
    return "abc";
  } 
  if (n == 3) {
    return "def";
  }
  if (n == 4) {
    return "ghi";
  }
  return " ";
}

void printCombinations(int input, string output) {
  if (input == 0) {
    cout << output << endl;
    return;
  }

  string lastDigitOption = getString(input % 10);
  for (int i = 0; i < lastDigitOption.size(); i++) 
  {
    printCombinations(input/10, lastDigitOption[i] + output);
  }
}

vector<string>* getCombinations(int input) 
{
  if (input == 0) {
    vector<string>* output = new vector<string>();
    output->push_back("");
    return output;
  }
  vector<string>* smallerOutput = getCombinations(input/10);
  string lastDigitOption = getString(input % 10); 
  vector<string>* output = new vector<string>();

  for (int i = 0; i < smallerOutput->size(); i++) {
    for (int j = 0; j < lastDigitOption.size(); j++) {
      output->push_back(smallerOutput->at(i) + lastDigitOption[j]);
    }
  }
  delete smallerOutput;
  return output;
} 

 
 

int main()
{
	int input=234 ;

  // vector<string> *permutations = getCombinations(input);
  // for(typename vector<string>::iterator it=permutations->begin();it!=permutations->end();it++)
  // {
  //   cout<<*it<<endl;
  // }

    string output="";
	 printCombinations(input,output);
  // generateSPatterns1(input,output);

	// vector<char> v[3];
 //    vector<string> res;
 //    char temp[10];
 //    int ch='a';
 //    int a[]={2,3,4};
 //    for(int i=2;i<=5;i++)
 //    {
 //       int count=3;
 //       while(count--)
 //       {
 //          v[i].push_back(ch);
 //          ch++;
 //       } 
 //    } 

 //    generateSubsequences1(v,res,temp,a,-1,0,3);
	return 0;
}