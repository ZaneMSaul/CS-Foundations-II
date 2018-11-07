#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "BankAccount.h"
#include "SavingsAccount.h"

// Constants
const double SavingsAccount::MINIMUM_ACTIVE_AMOUNT = 25.00;
const int SavingsAccount::MAXIMUM_WITHDRAWALS = 4;
const double SavingsAccount::CHARGE_FOR_WITHDRAWALS = 1.00;
const double SavingsAccount::SERVICE_FEE = 5.00;

// Constructor
SavingsAccount::SavingsAccount(double beginningBalance) :
		BankAccount(beginningBalance) {
	// Check if the deposit meets the minimum account,
	//	if it is active is set to true, otherwise it is set to false
	if (getBalance() > MINIMUM_ACTIVE_AMOUNT) {
		status = true;
		std::cout << "Your savings account is now active." << std::endl;
	} else {
		status = false;
		std::cout << "Your savings account is inactive because it contains $"
				<< std::fixed << std::setprecision(2) << MINIMUM_ACTIVE_AMOUNT
				<< " or less." << std::endl;
	}
}

/*  Deposit is a virtual function that checks if the account is inactive before
 *  a deposit is made.If the account is inactive and the deposit brings the
 *  account above $25, the account becomes active, again.
 *  The deposit is made by calling the super class method in BankAccount.
 */
void SavingsAccount::deposit(double amount) {
	if (!status && (getBalance() + amount) > MINIMUM_ACTIVE_AMOUNT) {
		status = true;
		std::cout << "Your savings account is now active." << std::endl;
	}
	BankAccount::deposit(amount);
}

/*  withdraw is a virtual function that checks if the account is inactive before
 *  a withdraw  is made. If the account is inactive, no withdraw is allowed.
 *  Does not allow withdrawals that result in a negative balance.
 *  It invokes the base class BankAccount to perform the withdrawals.
 */
double SavingsAccount::withdraw(double amount) {
	// Check if the account is active
	if (!status) {
		std::cout
				<< "Sorry, your account is inactive and cannot make a "
				   "withdrawal." << std::endl;
		return 0.0;
	}

	// Check if withdrawal will result in negative balance
	if ((getBalance() - amount) < 0) {
		std::cout
				<< "Sorry, this withdrawal is not allowed because it will "
				   "bring your account below $0.00." << std::endl;
		return 0.0;
	}

	BankAccount::withdraw(amount);
	return amount;
}

/*  processMonthEnd is a virtual function that checks the number of withdrawals
 *  for the month. If there are more than 4 withdrawals, a service charge of $1
 *  is added for each withdrawal over 4.It also checks if the balance after
 *  service fees falls below the $25 amount, rendering the account inactive.
 *  The superclass method in BankAccount is used to calculate the end month
 *  charges and credits.
 */
void SavingsAccount::processMonthEnd() {
	// Checks if the account exceeds the maximum withdrawals to apply a charge
	if (getNumberOfWithdrawals() > MAXIMUM_WITHDRAWALS) {
		// Charge is the amount of withdrawals over maximum number of
		//withdrawals before a fee multiplied by the withdrawal fee
		double charge = (MAXIMUM_WITHDRAWALS - getNumberOfWithdrawals())
				* CHARGE_FOR_WITHDRAWALS;
		std::cout << "Your withdrawals exceeded " << MAXIMUM_WITHDRAWALS
				<< ". Your account will be charged $"
				<< charge << "." << std::endl;
		setBalance(getBalance() - charge); // Adjusts the balance
	}

	std::cout << std::endl << "   Monthly Report: " << std::endl;
	// Display Number of Withdrawals/Deposits before Resetting
	std::cout << "   Number of Withdrawals:    " << getNumberOfWithdrawals()
			  << std::endl;
	std::cout << "   Number of Deposits:       " << getNumberOfDeposits()
			  << std::endl;

	// Processes the month end using the superclass BankAccount
	BankAccount::processMonthEnd();

	// Adjust precision for dollars
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "   Service Fee:              " << SERVICE_FEE << std::endl;
	setBalance(getBalance() - SERVICE_FEE);
	// If the  bank account falls below the minimum amount to keep it active,
	// status is set to false and it notifies the user
	if (getBalance() < MINIMUM_ACTIVE_AMOUNT) {
		status = false;
		std::cout << "Your savings account is inactive because it contains $"
				<< MINIMUM_ACTIVE_AMOUNT << " or less." << std::endl;
	}

	// Display Balance After Processing
	std::cout << "   Account Balance:          " << getBalance() << std::endl;
}

// Calculates the monthly interest
double SavingsAccount::getInterest() {
	double monthlyInterestRate = ANNUAL_INTEREST_RATE / 12;
	return getBalance() * monthlyInterestRate;
}

SavingsAccount::~SavingsAccount() {

}

