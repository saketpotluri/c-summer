#include <iostream>
#include <math.h>
using namespace std;

double factorial(int num) {
   double result = 1;
   for (int i = 1; i < num; i++) {
      result *= (i + 1);
   }
   return result;
}


double stirling(int num) {
   double pi = atan(1) * 4;
   return pow((num / exp(1)), num) * pow(2 * pi * num, 0.5);
}

double percentError(double actual, double estimate) {
   return abs((actual - estimate) / actual) * 100.00;
}

int main()
{
   std::cout.precision(4);
   cout << "n        n!" << "           Stirling" << "      Error" <<
      std::scientific << endl;
   for (int i = 1; i < 101; i++) {
      double accurate = factorial(i);
      double stir = stirling(i);
      double error = percentError(accurate, stir);
      cout << i << "    " << accurate << "     " << stir << "    " << error << endl;


   }
   cout << "n! " << " Stirling Log" << "  Error" << endl;

   /*
   for (int i = 100; i < 301; i++) {
      double accurateLog = stirlingLog(i);
      double stirLog = stirlingApproximation(i);
      double error = percentError(accurateLog, stirLog); 
      cout << accurateLog << " " << stirLog << " " << error << endl;
   }
   */

}

