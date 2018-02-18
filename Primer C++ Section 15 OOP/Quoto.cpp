#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
class Disc_quote;
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
    virtual void debug()const
    {
        cout<<"bookNo "<<bookNo<<" price "<<price<<endl;
    }
private:
    string bookNo;
protected:
    double price = 0.0;        
};
class Disc_quote: public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string&book,double price,size_t qty,double disc):
        Quote(book,price),
        quantity(qty),
        discount(disc){}
    double net_price(size_t)const = 0;//纯虚函数
protected:
    size_t quantity = 0;
    double discount =0.0;
};
class Bulk_quote: public Disc_quote
{
public:
    Bulk_quote()=default;
    Bulk_quote(const std::string&,double,size_t,double);
    double net_price(size_t)const override;
    void debug()const override
    {
        // cout<<"min_qty "<<min_qty<<" discount "<<discount<<endl;
    }
private:
};

Bulk_quote::Bulk_quote(const string& s,double sales_price, size_t qty,double dis):
    Disc_quote(s,sales_price,qty,dis)
{
    
}

double Bulk_quote::net_price(size_t n)const 
{
    return n * price * ( n >= quantity ? 1 - discount : 1);
}

double print_total (std::ostream& os, const Quote& item, size_t n);

class Limit_quote:public Disc_quote
{
public:
    Limit_quote(const string &book,double sales_price,int max_number,double disscount):
        Disc_quote(book,sales_price,max_number,disscount){}
    virtual double net_price(size_t n)const override
    {
        if(n<=quantity)
            return n*discount*price;
        else
            return quantity*discount*price+(n-quantity)*discount*price;
    }
    void debug()const override
    {
        // cout<<"max_number "<<max_number<<" disscount "<<disscount<<endl;
    }
private:
    
};


double Disc_quote::net_price(size_t t)const
{
    cout<<t<<endl;
    return 0.0;
}

int main()
{
    // ex15.6
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);
    q.debug();
    bq.debug();
    print_total(std::cout, q, 12);
    print_total(std::cout, bq, 12);
    // Disc_quote d;
    // d.net_price(0);
    
    return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);

    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << std::endl;

    return ret;
}
