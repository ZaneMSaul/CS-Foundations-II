#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <string>

enum MONTH {JANUARY, FEBRUARY, MARCH, APRIL, MAY,JUNE,
                	JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

class BankAccount {
	private:
	  int        balance;
	  int        numberOfDeposits;
	  int        numberOfWithdrawals;


protected:
	  virtual void processMonthEnd ();
	  virtual void calculateInterest ();
	  virtual void calculateServiceCharge();
	  int                 convertToCents (double);
	  double          convertToDollars (int);

	  MONTH month = JANUARY;

public:
	const static double  ANNUAL_INTEREST_RATE         = 0.08;
	const static double  MONTHLY_SERVICE_CHARGE   =  5.00;


	BankAccount(double);

	virtual void deposit(double);
	virtual double withdraw (double);

	double getBalance ();
	int         getNumberOfDeposits();
	int         getNumberOfWithDrawals ();

	void      setNumberOfDeposits(int);
	void      setNumberOfWithdrawals (int);

	virtual void printMonthlyStatement ();

	void      clockTick();

	virtual ~BankAccount();


};

#endif /* BANKACCOUNT_H_ */
