/*SaiSaket Potluri 
 *C++ Online Course Foothill Assignment 4
 *This program will simulate a chocolate bar shop in which the user can 
 *buy chococolate bars and consume them. 
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
   //variables
   string input = "Y";
   int availBars = 15;
   int debtBalance = 15;
   cout << "Initial Account Settings" << endl;
   cout << " Cost (so far) this month: $" << debtBalance << endl;
   do {
      cout << " Available Bars: " << availBars << endl;
      cout << "Menu:" << endl;
      cout << "  B (show Bill and start new month) " << endl;
      cout << "  A (show Available number of bars for the current month)" << endl;
      cout << "  C (Consume bars now)" << endl;
      cout << "  P (Purchase additional bars for current month" << endl;
      cout << "  Q (show bill and Quit)" << endl;
      cout << "  Your choice: ";
      cin >> input;
      if (tolower(input[0]) == 'b') {
         cout << " Closing bill for the month:" << endl;
         cout << "  Unused bars (lost): " << availBars << endl;
         cout << "  Final amount due immediately: " << debtBalance << '\n' << endl;
         cout << "  Starting new month ...Available bars: 15" << endl;
         availBars = 15;
         debtBalance = 15;
      }
      else if (tolower(input[0]) == 'c') {
         int numberConsumed = 0;
         cout << '\n' << "  Number of bars you want to Consume: " << endl;
         cin >> numberConsumed;
         if (cin) {
            if (numberConsumed > 10 || numberConsumed <= 0) {
               cout << "Sorry numbers must between 1 and 10" << endl;
            }else {
               if (numberConsumed > availBars) {
                  debtBalance += 15;
                  availBars += 10;
               } 
               availBars -= numberConsumed;
            }
         }
         else {
            cout << "Integer amount not entered, please try again" << endl;
         }
      }
      else if (tolower(input[0]) == 'a') {
         //do nothing
      }
      else if (tolower(input[0]) == 'p') {
         int setsPurchased = 0;
         cout << '\n' << "Purchase additional bars in sets of 10 (1 - 3) : " << endl;
         cin >> setsPurchased;
         if (cin) {
            if (setsPurchased >= 1 && setsPurchased <= 3) {
               availBars += 10 * setsPurchased;
               debtBalance += 11 * setsPurchased;
            }
            else {
               cout << "You can only buy between 1 and 3 sets of bars, pleas enter again" << endl;
            }
         }
         else {
            cout << "Integer amount not entered, please try again" << endl;
         }
      }
      else {
         cout << "Input not understood, please enter a valid choice" << endl;
      }
   } while (tolower(input[0]) != 'q');
   if (tolower(input[0]) == 'q') {
      //print out final report
      cout << "Closing bill for the month: $" << debtBalance << endl; 
   }
}