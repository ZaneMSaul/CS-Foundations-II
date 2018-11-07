
//  This program demonstrates the use of characters and strings

//  Dean DeFino

#include <iostream>
#include <string>
using namespace std;

// Declaration of constants
const string FAVORITE_SODA = "Dr. Dolittle";  // use double quotes for strings
// const char   BEST_RATING = 'A';                 // use single quotes for characters
const string    BEST_RATING = "A";

int main()
{
//	char rating;                     // 2nd highest product rating
   string  rating;                     // 2nd highest product rating
   string favoriteSnack;            // most preferred snack
   int numberOfPeople;              // the number of people in the survey
   int topChoiceTotal;              // the number of people who prefer the top choice

   favoriteSnack = "crackers";
   rating = 'B';
   numberOfPeople = 250;
   topChoiceTotal = 148;

   cout << "The preferred soda is " << FAVORITE_SODA << endl;
   cout << "The preferred snack is " << favoriteSnack << endl;
   cout << "Out of " << numberOfPeople << " people "
        << topChoiceTotal << " chose these items!" << endl;
   cout << "Each of these products were given a rating of " << BEST_RATING;
   cout << " from our expert tasters" << endl;
   cout << "The other products were rated no higher than a " << rating
        << endl;

   return 0;
}




