#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

// Exercise 16.40:
// Is the following function legal? If not, why not? If it is legal, what,
// if any, are the restrictions on the argument type(s) that can be passed,
// and what is the return type?
// legal.
// As shown below, only type that support this + 0 operation can be passed.
// the return type depends on the what type the operator + returns. In the case
// below, the return type is Bar.



class Bar{ };

Bar operator +(Bar lhs, int)
{
    return lhs;
}

template <typename It>
//可以看到，这里后置返回值有操作空间
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
    return *beg;  // return a copy of an element from the range
}

int main()
{
    std::vector<Bar> v;
    v.push_back(Bar());
    Bar b = fcn3(v.begin(), v.end());
    ;
    ;
}
