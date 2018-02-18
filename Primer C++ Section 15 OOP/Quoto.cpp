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



int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
