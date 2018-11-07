#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_

#include <string>

class SavingsAccount: public BankAccount {

private:
	bool status; // Indicates whether the account is active or not

protected:
	virtual void processMonthEnd();

public:
	// Constructor
	SavingsAccount(double beginningBalance);

	// Deposit & Withdraw
	virtual void deposit(double);
	virtual double withdraw(double);

	// Getter
	double getInterest();

	virtual ~SavingsAccount();

	// Static Const Variables
	static const double MINIMUM_ACTIVE_AMOUNT;
	static const int MAXIMUM_WITHDRAWALS;
	static const double CHARGE_FOR_WITHDRAWALS;
	static const double SERVICE_FEE;
};

#endif /* SAVINGSACCOUNT_H */
