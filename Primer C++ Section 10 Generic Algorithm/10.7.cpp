#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<int> vec;list<int> lst;int i;
    while(cin>>i)
        lst.push_back(i);
    //vec.begin是错的，要如何修正?
    copy(lst.cbegin(),lst.cend(),vec.begin());
    //这是无意义的，想想为什么？
    vector<int> vec;
    vec.reverse(10);
    fill_n(vec.begin(),10,0);
    
    return 0;
}
