/*
 * CollegeKey.cpp
 *
 *  Created on: Aug 13, 2017
 *      Author: T
 */
// This program determines the college bill of a student.
// The tuition is $3000 for in state and $4500 for out-of-state students
// Room and Board is $2500 for in-state and $3500 for out-of-state students

#include <iostream>
#include <iomanip>
using namespace std;

const float IN_STATE_TUITION = 3000;
const float OUT_STATE_TUITION = 4500;
const float IN_STATE_ROOM = 2500;
const float OUT_STATE_ROOM = 3500;

int main()
{
   int totalBill = 0;     // the total bill (tuition and room & board)
   char status;           // status of in or out-of-state
   char room;             // status of on campus or off campus student

   cout <<"Please input 'I' if you are in-state or 'O' if you are out-of-state" << endl;
   cin >> status;

   cout << "Please input 'Y' if you require room and board and 'N' if you do not" << endl;
   cin >> room;

   if (status =='I' && room == 'Y')
   {
      totalBill =  IN_STATE_TUITION +IN_STATE_ROOM;
      cout << "Your total bill for this semester is $" << totalBill << endl;
   }
   else if (status =='O' && room == 'Y')
   {
      totalBill =  OUT_STATE_TUITION + OUT_STATE_ROOM;
      cout << "Your total bill for this semester is $" << totalBill << endl;
   }
   else if (status == 'I' && room == 'N')
   {
      totalBill = IN_STATE_TUITION;
      cout << "Your total bill for this semester is $" << totalBill << endl;
   }
   else if (status =='O' && room == 'N')
   {

      totalBill = OUT_STATE_TUITION;
      cout << "Your total bill for this semester is $" << totalBill << endl;
   }
   else
      cout << "You did not input valid data" << endl;

   return 0;
}



