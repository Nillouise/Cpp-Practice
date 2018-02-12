#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(10);
    int cnt = count(vec.begin(),vec.end(),10);
    cout<<cnt<<endl;//
    
    return 0;
}
