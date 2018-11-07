//
//  SavingsAccount.hpp
//  Assignment7
//
//  Created by zane saul on 11/8/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#ifndef SavingsAccount_hpp
#define SavingsAccount_hpp

#include <stdio.h>
#include <vector>
#include "BankAccount.hpp"

class SavingsAccount: public BankAccount {
private:
    const int WITHDRAWAL_SERVICE_CHARGE = 1;
    bool active;
    
    double DepositAmount,
           WithdrawalAmount;
    
    void calculateServiceCharge( );
    virtual void printMonthlyStatement( );
    bool status( );
    
public:
    SavingsAccount( double );
    virtual void deposit( double );
    virtual double withdraw( double );
    virtual void processMonthEnd( );
};

#endif /* SavingsAccount_hpp */
