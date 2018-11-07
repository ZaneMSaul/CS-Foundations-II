#include <string>
#include <iostream>
#include "BankAccount.h"

int main() {
	const double beginningBalance = 200.00;
	BankAccount *bankAccount = new BankAccount(beginningBalance);

	try {
		bankAccount->deposit(5.00);
		bankAccount->withdraw (-5.00);

	} catch (BankAccount::InvalidAmount  &e) {
		std::cout << "***Error! Invalid amount for deposit or withdrawal " << std::endl;
   }

	return 0;
}

