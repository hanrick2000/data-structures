#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

class student
{
  private:
  int rollno;
  vector<int> *assignments;
  char* name;		

  public:
  	// student()
  	// {
  	// 	assignments=new vector<int>();
  	// };

	student(char* name)
	{
		assignments=new vector<int>();
		//this->name=name;
		this->name=new char[strlen(name)+1];
		strcpy(this->name,name);

	};
	~student()
	{
		delete assignments;
		delete[] name;
	};

	void setname(char* name)
	{
		delete[] this->name;
		this->name=new char[strlen(name)+1];
		strcpy(this->name,name);
	}
 
    char* getname()
    {
    	return name;
    }

	
};


int main()
{
	char a[]="abcd";
	student s(a);
	cout<<s.getname()<<endl;
	a[2]='x';
	s.setname(a);
	cout<<s.getname()<<endl;
	student *s1=new student(a);
	a[0]='g';
	s1->setname(a);
	cout<<s1->getname()<<endl;

}