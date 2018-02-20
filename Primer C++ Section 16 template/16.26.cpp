#include<bits/stdc++.h>
using namespace std;
typedef long long LL;



class NoDefault
{
public:
    NoDefault()=delete;
};

//这是不可以的
template class vector<NoDefault>;

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<NoDefault> vec;    
    
    
    return 0;
}
