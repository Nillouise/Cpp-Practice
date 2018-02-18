#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Quote{
public:
    Quote() = default;
    Quote(const string &book,double sales_price):
            bookNo(book),price(sales_price){}
    string isbn()const
    {
        return bookNo;
    }
    virtual double net_price(size_t n)const
    {
        return n*price;
    }
    virtual ~Quote()=default;
    
private:
    string bookNo;
protected:
    double price = 0.0;        
};

class Bulk_quote: public Quote
{
public:
    Bulk_quote()=default;
    Bulk_quote(const std::string&,double,size_t,double);
    double net_price(size_t)const override;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

Bulk_quote::Bulk_quote(const string& s,double sales_price, size_t qty,double dis):
    Quote(s,sales_price),
    min_qty(qty),
    discount(dis)
{
    
}

double Bulk_quote::net_price(size_t n)const 
{
    return n * price * ( n >= min_qty ? 1 - discount : 1);
}

double print_total (std::ostream& os, const Quote& item, size_t n);

class Limit_quote:public Quote
{
public:
    Limit_quote(const string &book,double sales_price,int max_number,double disscount):
        Quote(book,sales_price),
        max_number(max_number),
        disscount(disscount){}
    virtual double net_price(size_t n)const override
    {
        if(n<=max_number)
            return n*disscount*price;
        else
            return max_number*disscount*price+(n-max_number)*disscount*price;
    }
private:
    int max_number;
    double disscount;
};



int main()
{
    // ex15.6
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);

    print_total(std::cout, q, 12);
    print_total(std::cout, bq, 12);

    return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);

    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << std::endl;

    return ret;
}
