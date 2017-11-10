/*
**Made by Kartik Patel Date: 23/oct/2017
**Feel free to add any more cases to test.
*/
#include "Wallet.h"
#include "Money.h"
#include "Bank.h"
#include <iostream>
using namespace std;

int main()
{
	Bank Scotia = Bank();
	Bank RBC = Bank();
	
	//Player1
	Wallet p1 = Wallet(Scotia);

	//Player2
	Wallet p2 = Wallet(RBC);

	//Expected output should be 0 and 0 
	cout<<"Before starting cash should be initialized to 0,"<<endl;
	cout<<"p1 Net worth(Scotia): "<<p1.netWorth()<<endl;
	cout<<"p2 Net worth(RBC): "<<p2.netWorth()<<endl;


	//This should initialize p1 and p2 with 1500
	Scotia.giveStartingMoney(p1);
	RBC.giveStartingMoney(p2);

	//Expected output should be 1500
	cout<<endl<<"p1 Net worth(Scotia): "<<p1.netWorth()<<endl;
	cout<<"p2 Net worth(RBC): "<<p2.netWorth()<<endl;

	//Deposits
	p1.deposit(500);
	p2.deposit(100);
	
	//Expected output should be 2000 an 1600
	cout<< endl << "Should bee 2000 and 1600" << endl;
	cout<<"Deposited money,"<<endl;
	cout<<"p1 Net worth(Scotia): "<<p1.netWorth()<<endl;
	cout<<"p2 Net worth(RBC): "<<p2.netWorth()<<endl;

	//Withdraw
	cout<<endl<<"Output 1 if able to withdraw(100): "<<p1.withdraw(100)<<endl;
	cout<<"Output 1 if able to withdraw(100): "<<p2.withdraw(100)<<endl;
	cout<<endl<<"Trying to withdraw(20000) more than net worth(Output should be 0):"<<p2.withdraw(20000)<<endl;
	
	//Withdraw -ve number
	//cout<<endl<<"Trying to withdraw(-500), output should be 0: "<<p2.withdraw(-500)<<endl;


	//Expected output should be 1900 and 1500
	cout << endl <<  "should be 1900 and 1500" << endl;
	cout<<"Withdrawn money,"<<endl;
	cout<<"p1 Net worth(Scotia): "<<p1.netWorth()<<endl;
	cout<<"p2 Net worth(RBC): "<<p2.netWorth()<<endl;

	//TransferTo
	p1.transferTo(500,p2);
	
	//Expected output should be 1400 and 2000
	cout<<"should be 1400 and 2000" << endl;
	cout<<"Transferring from p1 to p2, 500"<<endl; 
	cout<<"p1 Net worth(Scotia): "<<p1.netWorth()<<endl;
	cout<<"p2 Net worth(RBC): "<<p2.netWorth()<<endl;

	p2.transferTo(500,p1);

	//Expected output should be 1900 and 1500
	cout<<endl<<"Transferring from p2 to p1, 500 (should be 1900 and 1500"<<endl;
	cout<<"p1 Net worth(Scotia): "<<p1.netWorth()<<endl;
	cout<<"p2 Net worth(RBC): "<<p2.netWorth()<<endl;

	//Trying to deposit -ve number. (Output:1400)
	//Don't worry even if it deposits a -ve amount
	//basically removing money from cash, but House said
	//he's not going to test us by passing negative
	//number. This is just to see that, even when
	//method takes in the argument as a unsigned int
	//it still uses as a negative number to deposit.
	p1.deposit(-500);
	cout<<endl<<"Depositing -ve number:"<<endl;
	cout<<"p1 Net Worth(Scotia): "<<p1.netWorth()<<endl;

	return 0;
}
