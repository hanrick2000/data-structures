#include <iostream>
#include <cstring>
using namespace std;

/*
Assume   that   value   of   a=1,   b=2,   c=3,   d=4,   ....   z=26.   You   are   given   a   numeric   string  
S.   Write   a   program   to   find   and   print   list   of   all   possible   codes   that   can   be   generated  
from the given string. E.g. 1123  aabc, kbc, alc, aaw, kw  


*/


string decoder(string val)
{
	 
		// case "1": return "a";
		// case "2": return "b";
		// case "3": return "c";
		// case "4": return "d";
		// case "5": return "e";
		// case "6": return "f";
		// case "7": return "g";
		// case "8": return "h";
		// case "9": return "i";
		// case "10": return "j";
		// case "11": return "k";
		// case "12": return "l";
		// case "13": return "m";
		// case "14": return "n";
		// case "15": return "o";
		// case "16": return "p";
		// case "17": return "q";
		// case "18": return "r";
		// case "19": return "s";
		// case "20": return "t";
		// case "21": return "u";
		// case "22": return "v";
		// case "23": return "w";
		// case "24": return "x";
		// case "25": return "y";
		// case "26": return "z";
		// default:return " ";
	
	if(val=="1")
		return "a";
	else if(val=="2")
		return "b";
	else if(val=="3")
		return "c";
	else if(val=="4")
		return "d";
	else if(val=="5")
		return "e";
	else if(val=="6")
		return "f";
	else if(val=="7")
		return "g";
	else if(val=="8")
		return "h";
	else if(val=="9")
		return "i";
	else if(val=="10")
		return "j";
	else if(val=="11")
		return "k";
	else if(val=="12")
		return "l";
	else if(val=="13")
		return "m";
	else if(val=="14")
		return "n";
	else if(val=="15")
		return "o";
	else if(val=="16")
		return "p";
	else if(val=="17")
		return "q";
	else if(val=="18")
		return "r";
	else if(val=="19")
		return "s";
	else if(val=="20")
		return "t";
	else if(val=="21")
		return "u";
	else if(val=="22")
		return "v";
	else if(val=="23")
		return "w";
	else if(val=="24")
		return "x";
	else if(val=="25")
		return "y";
	else 
		return "z";
}	

int generateCodesHelper(string input,int start,string output)
{
	if (start==input.length())
	{
		cout<<output<<endl;	
		return 0; 		
	}

	int ans=0;
	if(start<input.length()-1 && input[start+1] <='6' && input[start] > '0' && input[start] <= '2')
	{

		string str=decoder(input.substr(start,2));
		//string str=input.substr(start,2);

		ans+=generateCodesHelper(input,start+2,output+str);
	} 
    
    if (input[start]!='0')
    {
    	string str1=decoder(input.substr(start,1));
	    ans+=generateCodesHelper(input,start+1,output+str1);
    }
	


}

int generateCodes(string input)
{	

	 return generateCodesHelper(input,0," ");
}
 
//Code below erronous 

int countHelper(string str,int len)
{
	if(len==0 || len==1)
		return 1;

	if (str[len-1] > '0')
	{
		return 1+countHelper(str,len-1);
	}

	if((str[len-2]<'2') || (str[len-2]=='2' && str[len-1]<'7'))
	{
		return 2+ countHelper(str,len-2);
	}	
}

int count(string str)
{
	int len=str.length();
	return countHelper(str,len);
}

  // public int NumDecodings(string s)
  //       {
  //           if (string.IsNullOrEmpty(s))
  //           {
  //               return 0;
  //           }
  //           int* dp = new int[s.length() + 1];
  //           dp[0] = 1;

  //           for (int i = 1; i < s.length() + 1; i++)
  //           {       
  //           	dp[i]=0;          
  //               if (i > 1 && s[i - 2] != '0' && int.Parse(s.Substring(i - 2, 2)) <= 26)
  //               {
  //                   dp[i] += dp[i - 2];
  //               }
                
  //               if (s[i - 1] != '0')
  //               {
  //                   dp[i] += dp[i - 1];
  //               }
  //           }

  //           return dp[s.length()];
  //       }
 

int main()
{
	// string input;
	// cin>>input;
	// int len=input.length()();
	string input="103";
	generateCodes(input);
	 cout<<count(input);

	 
	return 0;
}