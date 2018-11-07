#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_


// BankAccount is the same version posted under resources on TRACS
// No modifications were made other than those defined in the email,
// and using the default formatter with eclipse in Linux
#include <string>

// Enum month used for incrementing month
enum MONTH {
	JANUARY,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

class BankAccount {
private:
	// Attributes
	int balance;
	int numberOfDeposits;
	int numberOfWithdrawals;

protected:

	// Processing Methods
	virtual void processMonthEnd();
	virtual void calculateInterest();
	virtual void calculateServiceCharge();
	int convertToCents(double);
	double convertToDollars(int);

	// Setters
	void setBalance(double);
	void setNumberOfDeposits(int);
	void setNumberOfWithdrawals(int);

	// Default first month is January
	MONTH month = JANUARY;

public:
	// Constructor
	BankAccount(double);

	// Deposit and Withdraw Methods
	virtual void deposit(double);
	virtual double withdraw(double);

	// Getters
	double getBalance();
	int getNumberOfDeposits();
	int getNumberOfWithdrawals();

	// Display Data
	virtual void printMonthlyStatement();

	// Moves the "Clock" Forwards Month and Processes Monthly Values
	void clockTick();

	// Destructor
	virtual ~BankAccount();

	// Static Variables
	const static double ANNUAL_INTEREST_RATE;
	const static double MONTHLY_SERVICE_CHARGE;
};

#endif /* BANKACCOUNT_H_ */
