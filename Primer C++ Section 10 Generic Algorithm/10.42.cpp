#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    list<string> lst{"aa","bb","aa","bb"};
    lst.sort();
    lst.unique();
    for(auto &a:lst)
    {
        cout<<a<<" ";    
    }
    
    return 0;
}
