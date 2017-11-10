#include <iostream>
#include "Money.h"
#include "Bank.h"
#include "Wallet.h"
#include  <vector>
using namespace std;


void Bank::giveStartingMoney(Wallet& p)
{
	p.deposit(1500);
}
