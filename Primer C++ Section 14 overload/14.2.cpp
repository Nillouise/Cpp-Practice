#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend ostream& operator<<(ostream& stream,const Sales_data&);
friend istream& operator>>(istream& stream,const Sales_data&);
public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);
    //这是错的，因为+运算符应该在类外重载，这样当我们定义了强转后，就能自动+其他数据了
    Sales_data operator+(const Sales_data &rhs)const
    {
        if(bookNo==rhs.bookNo)
        {
            Sales_data ndata;
            ndata.bookNo = bookNo;
            ndata.units_sold = rhs.units_sold+units_sold;
            ndata.revenue = ndata.revenue+ndata.revenue;
            return ndata;
        }else{
            return Sales_data();
        }
    }
    Sales_data& operator+=(const Sales_data&rhs)
    {
        if(bookNo==rhs.bookNo)
        {
            units_sold+=rhs.units_sold;
            revenue += rhs.revenue;
        }
        return *this;
    }
    
	// operations on Sales_data objects
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

ostream& operator<<(ostream& stream,const Sales_data& data)
{
    print(stream,data);
    return stream;
}

istream& operator>>(istream& stream,Sales_data& data)
{
    read(stream,data);
    return stream;
}


// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

// used in future chapters
inline 
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}
Sales_data::Sales_data(std::istream &is) 
{
	// read will read a transaction from is into this object
	read(is, *this);
}

double 
Sales_data::avg_price() const {
	if (units_sold)
		return revenue/units_sold;
	else
		return 0;
}

// add the value of the given Sales_data into this object
Sales_data& 
Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold; // add the members of rhs into 
	revenue += rhs.revenue;       // the members of ``this'' object
	return *this; // return the object on which the function was called
}

Sales_data 
add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;  // copy data members from lhs into sum
	sum.combine(rhs);      // add data members from rhs into sum
	return sum;
}

// transactions contain ISBN, number of copies sold, and sales price
istream&
read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream&
print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}



int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    Sales_data d;
	cout<<d;
    
    
    return 0;
}
