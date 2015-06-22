#include <iostream>
#include <math.h>
using namespace std;


double stirlingApproximation(int num) {
   return num  * log(num) - num;
}

double percentError(double actual, double estimate) {
   return abs((actual - estimate) / actual) * 100.00;
}



int main()
{
   std::cout.precision(4);
   cout << "n        n!" << "           Stirling" << "      Error" <<
      std::scientific << endl;
   cout << "n! " << " Stirling Log" << "  Error" << endl;

   double stirlingLog(int num) {
      double total = 0.0;
      for (int i = 1; i < num + 1; i++) {
         total += log(i);
      }
      return total;
   }

   for (int i = 100; i < 301; i++) {
      double accurateLog = stirlingLog(i);
      double stirLog = i * log(i) - i;
      double error = percentError(accurateLog, stirLog);
      cout << accurateLog << " " << stirLog << " " << error << endl;
   }


}
