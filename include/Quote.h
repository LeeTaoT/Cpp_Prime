#ifndef QUOTE_H
#define QUOTE_H


#include <memory>
#include <iostream>
#include <string>
#include <cstddef>

class Quote{
    friend std::istream& operator>>(std::istream&, Quote&);
    friend std::ostream& operator<<(std::ostream&, const Quote&);

public :
    Quote() = default;
    Quote(const std::string &book, double sales_price):
                    bookNo(book), price(sales_price){ }

    virtual ~Quote() = default;

    std::string isbn() const { return bookNo ;}    

    virtual double net_price(std::size_t n) const
        { return n * price ;}

private:
    std::string bookNo;
protected:
    double price = 0.0;

};

class Disc_quote : public Quote {

public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
                Quote(book,price),quantity(qty) , discount(disc) { }
    
    double net_price(std::size_t) const = 0;
    std::pair<size_t,double> double_policy() const
        { return {quantity,discount};}

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};



class Bulk_quote : public Disc_quote {

public:
    Bulk_quote() = default;
    Bulk_quote( const std::string book, double p, std::size_t qty ,double disc):
                Disc_quote(book, p , qty,disc){ }
    double net_price(std::size_t) const override;
};


class Lim_quote : public Disc_quote{

public :
    Lim_quote(const std::string& book = "",
                double sales_price = 0.0 ,
                std::size_t qty = 0 , double disc_rate = 0.0):
                    Disc_quote(book, sales_price,qty, disc_rate){ }
    double net_price(std::size_t) const;
};

double print_total(std::ostream &, const Quote&, std::size_t);

#endif