#include <iostream>
using std::cout ; using std::ostream;

#include "Quote.h"

int main()
{
   Quote base("0-201-82470-1", 50) ;
   print_total(cout , base , 10);

   Bulk_quote derived("0-201-82470-1",50, 5, .19);
   print_total(cout , derived, 10);

   Quote  *pBase = &derived;
   double undiscounted = pBase->Quote::net_price(42);

   return 0;
}