#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    list<string> but={"two","two","two"};
    but.push_back("one");
    but.push_back("two");
    but.push_back("one");
    int cnt = count(but.begin(),but.end(),"two");
    cout<<cnt<<endl;//
    //最好用cbegin和cend，因为你不打算改变元素的内容
    auto sum = accumulate(but.cbegin(),but.cend(),string());
    cout<<sum<<endl;
    
    return 0;
}
