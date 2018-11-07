#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "BankAccount.h"
#include "SavingsAccount.h"

// Constants
const double BankAccount::ANNUAL_INTEREST_RATE = 0.08;
const double BankAccount::MONTHLY_SERVICE_CHARGE = 5.00;

// Constructor
BankAccount::BankAccount(double beginningBalance) {
	balance = convertToCents(beginningBalance);
	numberOfDeposits = 0;
	numberOfWithdrawals = 0;
}

/*
 *  deposit is a virtual function that checks to see if the amount is negative
 *  if it is, it won't withdraw the amount
 */
void BankAccount::deposit(double amount) {
	if (amount <= 0) {
		std::cout << "***ERROR: invalid deposit amount " << amount << std::endl;
		return;
	}
	numberOfDeposits++;
	balance = balance + convertToCents(amount);
}

/*  withdraw is a virtual function that checks to see if the amount is negative
 *  if it is, it won't withdraw the amount. It also checks to see if the amount
 *  trying to be withdrawn brings the account to <= 0. If it does, it won't
 *  withdraw.
 */
double BankAccount::withdraw(double amount) {
	if (amount <= 0) {
		std::cout << "***ERROR: invalid withdraw amount " << amount
				<< std::endl;
		return 0;
	}
	int amountInCents = convertToCents(amount);
	if ((balance - amountInCents) <= 0) {
		std::cout
				<< "***ERROR: overdraw request: withdrawal would zero your "
					"account "
				<< std::endl << "       amount of withdrawal  requested: "
				<< amount << std::endl;
		return 0;
	}
	balance = balance - amountInCents;
	numberOfWithdrawals++;
	return amount;
}

// Getters
double BankAccount::getBalance() {
	return convertToDollars(balance);
}
int BankAccount::getNumberOfDeposits() {
	return numberOfDeposits;
}
void BankAccount::setBalance(double amount) {
	balance = convertToCents(amount);
}
int BankAccount::getNumberOfWithdrawals() {
	return numberOfWithdrawals;
}
void BankAccount::setNumberOfDeposits(int n) {
	numberOfDeposits = n;
}
void BankAccount::setNumberOfWithdrawals(int n) {
	numberOfWithdrawals = n;
}

// processMonthEnd resets values and calculates interest and charges
void BankAccount::processMonthEnd() {
	calculateInterest();
	calculateServiceCharge();
	setNumberOfDeposits(0);
	setNumberOfWithdrawals(0);
}

// Adds the monthly interest to the bank account
void BankAccount::calculateInterest() {
	double monthlyInterestRate = ANNUAL_INTEREST_RATE / 12;
	int monthlyInterest = balance * monthlyInterestRate;

	std::cout << "   Monthly Interest Rate:    " << monthlyInterestRate
			<< std::endl;
	std::cout << "   Interest Earned:          "
			<< convertToDollars(monthlyInterest) << std::endl;
	balance = balance + monthlyInterest;
}

// BankAccount should not have a service charge
void BankAccount::calculateServiceCharge() {

}

// This should be written in derived classes
void BankAccount::printMonthlyStatement() {

}

// Advances the month forward
void BankAccount::clockTick() {
	processMonthEnd();
	if (month == DECEMBER) {
		month = JANUARY;
	} else {
		int intMonth = month;
		intMonth++;
		month = static_cast<MONTH>(intMonth);
	}
}

// Converts dollars and cents to cents to avoid rounding errors
int BankAccount::convertToCents(double dollarsAndCents) {
	int cents = (dollarsAndCents + .005) * 100; // +.005 for round errors
	return cents;
}

// Converts the cents back to dollars and cents
double BankAccount::convertToDollars(int cents) {
	return cents / 100.0;
}

BankAccount::~BankAccount() {

}
