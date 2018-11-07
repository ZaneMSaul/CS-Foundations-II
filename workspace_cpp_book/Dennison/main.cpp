/* Name: Michael Dennison
 * Due Date: 22 November 2017
 * Assignment: #7 (Savings Account)
 * Note: I talked to you about us adjusting for precision since my computer
 * was printing different results. We had to add .005 in BankAccount.
 * Description:
 * This program uses a base class BankAccount and a derived class SavingsAccount
 * to keep track of deposits and withdrawals. Savings account accrues interest
 * every month. After applying interest, the savings account has a monthly
 * service fee of and charges per withdrawal if the number of withdrawals
 * exceeds a certain amount per month. Once a new month arrives, it resets the
 * data except for the users balance. */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "BankAccount.h"
#include "SavingsAccount.h"

// Main is a series of test values defined in an email sent to the class
int main() {

	std::cout << std::endl << std::endl << "Testing SavingsAccount "
			<< std::endl;
	std::cout << "1. Initial Deposit in Account 100.00 " << std::endl;
	BankAccount *savingsAccount = new SavingsAccount(100.0);
	std::cout << "   Savings Account balance: " << savingsAccount->getBalance()
			<< std::endl;


	std::cout << "2. Testing overdraft withdrawal " << std::endl;
	double withdrawFromSavings = savingsAccount->withdraw(200.00);
	std::cout << "   Savings Account withdraw " << withdrawFromSavings
			<< ", current balance: " << savingsAccount->getBalance()
			<< std::endl;

	std::cout << "3. Testing  withdrawal " << std::endl;
	withdrawFromSavings = savingsAccount->withdraw(25.00);
	std::cout << "   Savings Account withdraw " << withdrawFromSavings
			<< ", current balance: " << savingsAccount->getBalance()
			<< std::endl;

	std::cout << "4. Testing  withdrawal " << std::endl;
	withdrawFromSavings = savingsAccount->withdraw(7.95);
	std::cout << "   Savings Account withdraw " << withdrawFromSavings
			<< ", current balance: " << savingsAccount->getBalance()
			<< std::endl;

	std::cout << "5. Testing  withdrawal " << std::endl;
	withdrawFromSavings = savingsAccount->withdraw(25.77);
	std::cout << "   Savings Account withdraw " << withdrawFromSavings
			<< ", current balance: " << savingsAccount->getBalance()
			<< std::endl;

	std::cout << "6. Testing  number of withdrawals " << std::endl;
	std::cout << "   Savings Account withdrawals "
			<< savingsAccount->getNumberOfWithdrawals() << std::endl;

	std::cout << "7. Testing  number of deposits " << std::endl;
	std::cout << "   Savings Account deposits "
			<< savingsAccount->getNumberOfDeposits() << std::endl;

	std::cout << "8. Testing  deposit " << std::endl;
	savingsAccount->deposit(103.22);
	std::cout << "   Savings Account deposit 103.22,  current balance: "
			<< savingsAccount->getBalance() << std::endl;

	std::cout << "9. Testing  number of deposits " << std::endl;
	std::cout << "   Savings Account deposits "
			<< savingsAccount->getNumberOfDeposits() << std::endl;

	savingsAccount->clockTick();

	return 0;
}
