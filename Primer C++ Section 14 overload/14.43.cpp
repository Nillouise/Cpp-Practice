#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    vector<int> vec{10,10,1};
    int mod = 10;
    auto a = bind(modulus<int>(),placeholders::_1,mod);
    // auto b = bind(not_equal_to<int>());
    // find(vec.begin(),vec.end(),bind(not_equal_to<int>(),bind(modulus<int>(),placeholders::_1,mod),placeholders::_1,0));
    int cnt = find_if(vec.begin(),vec.end(),a)==vec.end();
    cout<<cnt<<endl;
    
    return 0;
}
