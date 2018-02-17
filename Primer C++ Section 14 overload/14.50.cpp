#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct LongDouble
{
    LongDouble(double val= 0.0):val(val){};
    operator double(){return val;};
    operator float(){return val;};
    double val;
};



int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LongDouble ldObj;
    // int ex1 = ldObj;
    int ex1 = ldObj.operator double();
    // float ex2 = ldObj;
    // double ex3 = ldObj;
    
    return 0;
}
