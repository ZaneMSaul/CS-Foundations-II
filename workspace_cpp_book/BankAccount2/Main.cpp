#include <string>
#include <iostream>
#include "BankAccount.h"

int main() {
	const double beginningBalance = 10.00;
	const double depositAmount1    = 5.00;
	const double depositAmount2    = 1.75;
	const double depositAmount3    = 0.03;

	const double expectedBalance2 = 15.00;
	const double expectedBalance3 = 16.75;
	const double expectedBalance4 = 17.05;

	const double monthlyInterestRate = BankAccount::ANNUAL_INTEREST_RATE / 12.0;
	const double expectedInterest = 0.11;

	const int eNumberOfDeposits = 12;

	BankAccount *bankAccount = new BankAccount(beginningBalance);

	std::cout << "Testing beginning balance amount " << beginningBalance
			<< std::endl;
	double balance = bankAccount->getBalance();
	if (balance != beginningBalance) {
		std::cout << "***Failed:  expected " << beginningBalance << " found :"
				<< balance << std::endl;
	} else {
		std::cout << "...Passed " << std::endl;
	}

	bankAccount->deposit(depositAmount1);
	std::cout << "Testing deposit amount " << depositAmount1 << std::endl;
	balance = bankAccount->getBalance();
	if (balance != expectedBalance2) {
		std::cout << "***Failed:  expected " << expectedBalance2 << " found: "
				<< balance << std::endl;
	} else {
		std::cout << "...Passed " << std::endl;
	}

	bankAccount->deposit(depositAmount2);
	std::cout << "Testing deposit amount " << depositAmount2 << std::endl;
	balance = bankAccount->getBalance();
	if (balance != expectedBalance3) {
		std::cout << "***Failed:  expected " << expectedBalance3 << " found: "
				<< balance << std::endl;
	} else {
		std::cout << "...Passed " << std::endl;
	}

	std::cout << "Testing deposit amount " << depositAmount3 << " * 10 "
			<< std::endl;
	for (int i = 0; i < 10; i++) {
		bankAccount->deposit(depositAmount3);
	}
	balance = bankAccount->getBalance();
	if (balance != expectedBalance4) {
		std::cout << "***Failed:  expected " << expectedBalance4 << " found: "
				<< balance << std::endl;
	} else {
		std::cout << "...Passed " << std::endl;
	}

	std::cout << "Testing number of deposits  " << std::endl;
	int nDeposits = bankAccount->getNumberOfDeposits();
	if (nDeposits != eNumberOfDeposits) {
		std::cout << "***Failed:  expected " << eNumberOfDeposits << " found: "
				<< nDeposits << std::endl;
	} else {
		std::cout << "...Passed " << std::endl;
	}

	std::cout << "Testing interest accrued at month end  " << std::endl;

	bankAccount->clockTick();
	balance = bankAccount->getBalance();
	if (balance != expectedBalance4 + expectedInterest) {
		std::cout << "***Failed:  expected " << expectedInterest << " found: "
				<< balance - expectedBalance4 << std::endl;
	} else {
		std::cout << "...Passed " << std::endl;
	}

	std::cout << "Testing number of deposits  after month end" << std::endl;
	nDeposits = bankAccount->getNumberOfDeposits();
	if (nDeposits != 0) {
		std::cout << "***Failed:  expected " << 0 << " found: "
				<< nDeposits << std::endl;
	} else {
		std::cout << "...Passed " << std::endl;
	}
	return 0;
}

