#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    list<int> lis;
    copy(vec.begin()+3,vec.begin()+7,front_inserter(lis));
    // 或者
    copy(vec.begin()+3,vec.begin()+7,lis.rbegin());
    
    for(auto a:lis)cout<<a<<" ";
    
    return 0;
}
