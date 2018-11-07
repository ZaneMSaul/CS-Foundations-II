//
//  SavingsAccount.cpp
//  Assignment7
//
//  Created by zane saul on 11/8/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#include "SavingsAccount.hpp"
#include <iostream>
#include <sstream>

SavingsAccount::SavingsAccount( double beginningBalance ) : BankAccount( beginningBalance ){
    BankAccount( getBalance( ) );
}
void SavingsAccount::deposit( double amount ){
    status( );
    BankAccount::deposit( amount );
    if( getBalance( ) >= 25 )
        active = 1;
}
double SavingsAccount::withdraw( double amount ){
    if( !status( ) ){
        std::cout << "***Error: Account Inactive " << active
                  << std::endl;
        return 0;
    }
    amount = BankAccount::withdraw( amount );
    return amount;
}
void SavingsAccount::processMonthEnd( ){
    if( getNumberOfWithdrawals( ) > 4 ){
        int charge = ( getNumberOfWithdrawals( ) - 4 ) *
                       WITHDRAWAL_SERVICE_CHARGE;
        SavingsAccount::withdraw( charge );
    }
    std::cout << "Number of Withdrawals: " << getNumberOfWithdrawals()
    << std::endl
    << "Number of Deposits: " << getNumberOfDeposits()
    << std::endl
    << "Interest Earned: " << ANNUAL_INTEREST_RATE / 12
    * getBalance() << std::endl
    << "Interest Rate: " << ANNUAL_INTEREST_RATE / 12
    << std::endl;
    SavingsAccount::status( );
    BankAccount::processMonthEnd( );
    std::cout << "Balance: " << getBalance() << std::endl;
}
void SavingsAccount::printMonthlyStatement( ){

}
bool SavingsAccount::status( ){
    if( getBalance( ) < 25 )
        return 0;
    return 1;
}
void SavingsAccount::calculateServiceCharge( ){
    setBalance( getBalance( ) - MONTHLY_SERVICE_CHARGE );
}
