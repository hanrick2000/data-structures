#include<iostream>
#include<cstdio>
using namespace std;

 /*
    Reverse a string keeping the words intact. e.g. Welcome to Coding Blocks ­> Blocks 
    Coding to Welcome.
	T.C.-O(n)  
 */

 void reverse(char* s,char *t)
 {
    while(s<t)
    {
        char temp=*s;
        *s++=*t;
        *t--=temp; 
    }    
 }

void reverseString(char *a)
{
    char *temp=a;
    char *start=a; 
    while(*temp)
    {
        temp++;
        //endIndex++;
        if(*temp==' ')
        {
            reverse(start,temp-1);
            start=temp+1;
        } 
        else if(*temp=='\0')
        {
            reverse(start,temp-1);
        }   
    }  

    reverse(a,temp-1);  
}

void reverseWords(string &s) {
            string ans = "";
            string cur = "";
            for (int i = s.length() - 1; i >= 0; i--) {
                if (s[i] == ' ') {
                    if (cur.length() == 0) {
                        continue;
                    }
                    // found a word 
                    reverse(cur.begin(), cur.end());
                    if (ans.length() > 0) { 
                        ans.push_back(' ');
                    }
                    ans += cur;
                    cur = "";
                    continue;
                }
                cur.push_back(s[i]);
            }
            if (cur.length() > 0) {
                reverse(cur.begin(), cur.end());
                if (ans.length() > 0) { 
                    ans.push_back(' ');
                }
                ans += cur;
            }
            s = ans;
            return;
        }
int main()
{
    char a[100]="Welcome to this world"; 
    cout<<"Intially "<<a<<endl;
    reverseString(a);
    cout<<"Finally "<<a<<endl;
    

	return 0;
}
