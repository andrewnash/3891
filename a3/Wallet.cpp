#include <iostream>
#include "Money.h"
#include "Bank.h"
#include "Wallet.h"
#include <vector>
using namespace std;

//note this code interprits the problem as if each value in the cash vector is the number of how many of each bill we have

const vector<Money> billTypes = {500, 100, 50, 20, 10, 5, 1}; //Vector containing each type of bill, each billTypes position is equal to the cash position 

Wallet::Wallet(Bank& banker) : theBank(banker)
{
	for(int i = 0; i < 7; i++) //This for loop initializes the cash vector to be empty
	{
		cash.push_back(0);
	}
}


void Wallet::deposit(Money amt)
{
	for(int i = 0; i < billTypes.size(); i++) //i starts at the largest bill so the least bills are used rather than just one dollar bills
	{
		while(amt >= billTypes[i]) //A while loop is used incase multiple of one bill are needed 
		{
			amt -= billTypes[i];
			cash[i]++;
		}
	
	}
}
    

bool Wallet::withdraw(Money amt)
{
	if(amt > netWorth()) //first check if we have enough money
	{
		return false;
	}
	else
	{
		while(amt != 0) //This will never be an infinite loop becuase of our pevious check 
		{
			for(int i = 0; i < billTypes.size(); i++) //this for loop will try to make amt 0 by subtracting bills of smaller sizes
			{
				while(amt >= billTypes[i] and cash[i] > 0)
				{
						amt -= billTypes[i]; 
						cash[i]--;
				} 
			}
			if(amt > 0) //if amt is not zero by this point then we need to make change for our bills, this algothrim will split every bill down one
			{
				for(int i = 0; i < 6; i++)
				{
					if(cash[i] > 0 && i != 2)//The equivilent of bills of the lower teir is equal to them divided (ie 500/100 = 5 so 5, 100 bills is equal to 1 500 bill)
					{
						cash[i]--;
						cash[i+1] += billTypes[i]/billTypes[i+1];
					}
					else if(cash [i] > 0 && i == 2) //THe above algorithm works for all cases but 50/20 so we hard code this conversion
					{
						cash[i]--;
						cash[i+1] += 2;
		 				cash[i+2]++;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
	return true;
}
    

bool Wallet::transferTo(Money amt, Wallet& payee)
{
	if(amt < netWorth()) //check if we have enough money, then use other Methods to transfer
	{
		withdraw(amt);
		payee.deposit(amt);
		return true;
	}
	return false;
}
    

Money Wallet::netWorth() const
{
	Money sum = 0;
	for(int i = 0; i < cash.size(); i++)//simply multipling how many bills we have by the value of that bill and summing it
	{
		sum += cash[i]*billTypes[i]; 
	}
	return sum;
}