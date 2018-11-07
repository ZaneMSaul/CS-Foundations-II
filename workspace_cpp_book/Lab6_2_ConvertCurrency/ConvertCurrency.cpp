/*
 * ConvertCurrency.cpp
 *
 */
// This program will input American money and convert it to foreign currency

// Dean DeFino

#include <iostream>
#include <iomanip>
using namespace std;

const double EUROSEXCHANGE = 1.06;
const double PESOSEXCHANGE = 9.73;
const double YENEXCHANGE = 124.35;

struct DollarConversions{
	float dollars;
	float euros;
	float pesos;
	float yen;
};

// Prototypes of the functions
void  convertMulti(float dollars, float& euros, float& pesos);
void  convertMulti(float dollars, float& euros, float& pesos, float& yen);
float convertToYen(float dollars);
float convertToEuros(float dollars);
float convertToPesos(float dollars);

int main ()
{
   float dollars;
   float euros;
   float pesos;
   float yen;

   cout << fixed << showpoint << setprecision(2);

   cout << "Please input the amount of American Dollars you want converted "
        << endl;
   cout << "to euros and pesos" << endl;
   cin >> dollars;

   convertMulti(dollars, euros, pesos);

   cout << "$" << dollars << " is converted to " << euros << " euros and "
        << pesos << " pesos." << endl << endl;

   cout << "Please input the amount of American Dollars you want converted\n";
   cout << "to euros, pesos and yen" << endl;
   cin >> dollars;


   convertMulti(dollars, euros, pesos, yen);
   cout << "$" << dollars << " is converted to " << euros << " euros and "
        << pesos << " pesos and " <<  yen << " yen" << endl << endl;

   cout << "Please input the amount of American Dollars you want converted\n";
   cout << "to yen" <<endl;
   cin >> dollars;

   yen = convertToYen(dollars);
   cout << "$" << dollars << " is converted to " << yen << " yen "
        << endl << endl;


   cout << "Please input the amount of American Dollars you want converted\n";
   cout << " to euros" << endl;
   cin  >> dollars;

   euros = convertToEuros(dollars);
   cout << "$" << dollars << " is converted to " << euros << " euros "
        << endl << endl;


   cout << "Please input the amount of American Dollars you want converted\n";
   cout << " to pesos " << endl;
   cin >> dollars;

   pesos = convertToPesos(dollars);
   cout << "$" << dollars << " is converted to " << pesos << " pesos\n\n";

   return 0;
}

// All of the functions are stubs that just serve to test the functions
// Replace with code that will cause the functions to execute properly

//  ************************************************************************
//                           convertMult
//
//   task:     This function takes a dollar value and converts it to euros
//             and pesos
//   data in:  dollars
//   data out: euros and pesos
//
//   ***********************************************************************
void  convertMulti(float dollars, float& euros, float& pesos)
{
      euros = dollars * EUROSEXCHANGE;
      pesos = dollars * PESOSEXCHANGE;
}

//  ************************************************************************
//                           convertMult
//
//   task:     This function takes a dollar value and converts it to euros
//                pesos and yen
//   data in:  dollars
//   data out: euros pesos yen
//
//   ***********************************************************************
void  convertMulti(float dollars, float& euros, float& pesos, float& yen)
{
      euros = dollars * EUROSEXCHANGE;
      pesos = dollars * PESOSEXCHANGE;
      yen = dollars * YENEXCHANGE;
}

//  ************************************************************************
//                           convertMulti
//
//   task:     This function takes a dollar value and returns a struct with equivalent
//                   values for euros, pesons, and yen
//
//
//   ***********************************************************************
DollarConversions covertMulti (float dollars, float euros, float pesos, float yen) {
	DollarConversions conversions;
     conversions.euros = dollars * EUROSEXCHANGE;
     conversions.pesos = dollars * PESOSEXCHANGE;
     conversions.yen = dollars * YENEXCHANGE;
     return conversions;
}


//  ****************************************************************************
//                           convertToYen
//
//   task:          This function takes a dollar value and converts it to yen
//   data in:       dollars
//   data returned: yen
//
//   ***************************************************************************
float convertToYen(float dollars)
{
   return dollars * YENEXCHANGE;
}

//  ****************************************************************************
//                           convertToEuros
//
//   task:          This function takes a dollar value and converts it to euros
//   data in:       dollars
//   data returned: euros
//
//   ***************************************************************************
float convertToEuros(float dollars)
{
   return  dollars * EUROSEXCHANGE;
}

//  *****************************************************************************
//                           convertToPesos
//
//   task:          This function takes a dollar value and converts it to pesos
//   data in:       dollars
//   data returned: pesos
//
//   ****************************************************************************
float convertToPesos(float dollars)
{
   return  dollars * PESOSEXCHANGE;
}



