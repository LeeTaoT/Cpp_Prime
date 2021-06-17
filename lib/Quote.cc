#include "Quote.h"

#include <algorithm>
using std::min;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::ostream ; using std::endl;
using std::cout;

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n) ;
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
double Bulk_quote::net_price(size_t cnt) const
{
    if(cnt >= quantity)
    {
        return cnt * (1 - discount) * price;
    }
    else
    {
        return cnt * price;
    }
}

double Lim_quote::net_price(size_t cnt) const
{
    size_t discount = min(cnt ,quantity);
    size_t undiscount = cnt - discount;
    return discount * ( 1 - discount ) * price + undiscount * price;
}
