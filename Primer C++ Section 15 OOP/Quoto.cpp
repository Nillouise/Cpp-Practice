#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
class Disc_quote;
class Quote{
public:
    //感觉这里写错了 // 果然是错的
    // Quote():bookNo(string()),price(0.0)
    //这样就可以了，编译器会帮我们初始化没在构造函数里初始化的成员变量
    Quote()
    {
        cout<<"Quote::Quote()"<<endl;
    }
    Quote(const Quote&q):bookNo(q.bookNo),price(q.price)
    {
        cout<<"Quote::Quote(const Quote&q)"<<endl;
    }
    
    Quote(Quote&&q) noexcept:bookNo(std::move(q.bookNo)),price(std::move(q.price))
    {
        cout<<"Quote::Quote(Quote&&q)"<<endl;
    }
    
    //我看答案会比较一下是不是自赋值，编译器也会比较自赋值吗？
    Quote& operator=(const Quote& q)
    {
        cout<<"Quote& operator=(const Quote& q)"<<endl;
        bookNo=q.bookNo;
        price=q.price;
        return *this;
    }
    
    //移动赋值通常不会抛出异常(因为没有进行内存申请)，声明为noexcept 比较好
    Quote& operator=(Quote&& q) noexcept
    {
        cout<<"Quote& operator=(Quote&& q)"<<endl;
        bookNo = std::move(q.bookNo);
        price = std::move(q.price);
        return *this;
    }
    
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
    //析构函数要为虚函数
    virtual ~Quote()
    {
        cout<<"Quote::~Quote()"<<endl;
    }
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
    // Disc_quote(const Disc_quote&)noexcept= default;
    // Disc_quote& operator=(Disc_quote&&)noexcept= default;
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
    // Bulk_quote()=default;
    // Bulk_quote():Disc_quote()
    //不需要像上面那样显示调用Disc_quote()，编译器会帮你调用的
    Bulk_quote()
    {
        cout<<"Bulk_quote::Bulk_quote()"<<endl;
    }
    
    Bulk_quote(const Bulk_quote& q):Disc_quote(q)
    {
        cout<<"Bulk_quote(const Bulk_quote& q):Disc_quote(q)"<<endl;
    }
    
    Bulk_quote(Bulk_quote&& q)noexcept :Disc_quote(std::move(q))
    {
        cout<<"Bulk_quote(Bulk_quote&& q):Disc_quote(std::move(q))"<<endl;
    }
    
    Bulk_quote& operator=(const Bulk_quote& q)
    {
        //大坑
        Disc_quote::operator=(q);
        cout<<"大坑 Bulk_quote& operator=(const Bulk_quote& q)"<<endl;
        return *this;
    }
    
    Bulk_quote& operator=(Bulk_quote &&q)noexcept
    {
        Disc_quote::operator=(std::move(q));
        cout<<"Bulk_quote& operator=(Bulk_quote &&q)"<<endl;
        return *this;
    }
    ~Bulk_quote()
    {
        cout<<"~Bulk_quote()"<<endl;
    }
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
    // Quote q;
    Bulk_quote bq,bq2;
    
    bq = std::move(bq2);
    
    // ex15.6
    // Quote q("textbook", 10.60);
    // Bulk_quote bq("textbook", 10.60, 10, 0.3);
    // q.debug();
    // bq.debug();
    // print_total(std::cout, q, 12);
    // print_total(std::cout, bq, 12);
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
