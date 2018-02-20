#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


template<typename It>
auto fcn2(It beg,It end)->
    typename remove_reference<decltype(*beg)>::type
{
    return *beg;    
}



int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<int> vec(10,1);
    int a = fcn2(vec.begin(),vec.end());
    cout<<a<<endl;
    
    return 0;
}
