#include<iostream>
#include<cstring>
using namespace std;

class account
{
private:
	int accno;
	float balance;
public:
	void getdata()
	{
		cout<<"Enter the account no. for acc object\n";
		cin>>accno;
		cout<<"Enter balance"<<endl;
		cin>>balance;
	}

	void setData(int accno)
	{
		this->accno=accno;
		balance=0;
	}

	void setData(int accno,float balance)
	{
		this->accno=accno;
		this->balance=balance;
	}

	void display()
	{
		cout<<"The account number is "<<accno<<endl;
		cout<<"The balance is "<<balance<<endl;
	}

 //    void  MoneyTransfer(account acc,float amount)  /*In this case the ammount trnsferred is not reflected,only amount gets deducted*/
	// {
	// 	balance=balance-amount;
	// 	acc.balance=acc.balance+amount;
	// }

	// void  MoneyTransfer(account &acc,float amount) /*Amount transferred is reflected*/
	// {
	// 	balance=balance-amount;
	// 	acc.balance=acc.balance+amount;
	// }


	void  MoneyTransfer(account *acc,float amount)   /*Amount transferred is reflected*/
	{
		balance=balance-amount;
		acc->balance=acc->balance+amount;
	}
	
};

int main()
{
	account acc1,acc2,acc3;
	acc1.getdata();
	acc2.setData(10);
	acc3.setData(20,750);
	cout<<"Account information ... "<<endl;
	acc1.display();
	acc2.display();
	acc3.display();
	// acc3.MoneyTransfer(acc1,300);
	acc3.MoneyTransfer(&acc1,300);
	acc1.display();
	acc2.display();
	acc3.display();

	return 0;
}