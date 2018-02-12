#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<int> vec={13,22,13,5,77};
    list<int> lis;
    sort(vec.begin(),vec.end());
    unique_copy(vec.begin(),vec.end(),back_inserter(lis));
    for_each(lis.begin(),lis.end(),[](int i){cout<<i<<" ";});
    
    return 0;
}
