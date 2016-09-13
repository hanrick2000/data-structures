#include <iostream>
using namespace std;

bool checkOppositeSigns(int x,int y)
{
	return ((x^y)<0)
}

int main()
{
	int x,y;
	cin>>x>>y;
	cout<<checkOppositeSigns(x,y);
	return 0;
}