#include "BankAccount.h"
#include <iostream>
#include <iomanip>
#include <sstream>

const double  BankAccount::ANNUAL_INTEREST_RATE         = 0.08;
const double BankAccount::MONTHLY_SERVICE_CHARGE    =  5.00;

BankAccount::BankAccount(double beginningBalance) {
	balance                         = convertToCents(beginningBalance);
	numberOfDeposits       = 0;
	numberOfWithdrawals = 0;
}

void BankAccount::deposit(double amount) {
	 if (amount <= 0)  throw InvalidAmount ();

	 numberOfDeposits++;
	 balance = balance + convertToCents(amount);
}

double BankAccount::withdraw (double amount){
	 if (amount <= 0)  throw InvalidAmount ();

	 int amountInCents = convertToCents(amount);
	 if ((balance - amountInCents) <= 0) throw overdraftWithdrawal();

	 balance = balance - amountInCents;
	 numberOfWithdrawals++;
	 return amount;
}

double BankAccount::getBalance () {
	return convertToDollars(balance);
}

int BankAccount::getNumberOfDeposits() {
	return numberOfDeposits;
}

void BankAccount::setBalance (double amount) {
      balance = convertToCents(amount);
}

int BankAccount::getNumberOfWithdrawals () {
	return numberOfWithdrawals;
}

void  BankAccount::setNumberOfDeposits(int n) {
	numberOfDeposits = n;
}

void  BankAccount::setNumberOfWithdrawals (int n) {
	numberOfWithdrawals = n;
}

void BankAccount::processMonthEnd () {
    calculateInterest();
    calculateServiceCharge();
    setNumberOfDeposits (0);
    setNumberOfWithdrawals (0);
}

 void BankAccount::calculateInterest () {
	   double monthlyInterestRate      = ANNUAL_INTEREST_RATE / 12;
	//  std::cout << "calculateInterest monthlyInterestRate  " << monthlyInterestRate << std::endl;
	  int monthlyInterest = balance * monthlyInterestRate;
	//  std::cout << "calculateInterest montlyInterest in cents  " << monthlyInterest << std::endl;
	  balance = balance + monthlyInterest;
}

 void BankAccount::calculateServiceCharge () {
       // don't charge for this
 }

void BankAccount::printMonthlyStatement () {

}

void BankAccount::clockTick () {
	processMonthEnd();
	if (month == DECEMBER) {
		month = JANUARY;
	} else {
		int intMonth = month;
		intMonth++;
		month =static_cast<MONTH> (intMonth);
	}
}

int BankAccount::convertToCents (double dollarsAndCents) {
	int cents = dollarsAndCents * 100;
	return cents;
}

double BankAccount::convertToDollars (int cents) {
	 return cents / 100.0;
}

BankAccount::~BankAccount() {

}

