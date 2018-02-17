#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int a=30;
    //这样可以找到第一个比前一个元素大的元素
    auto f = [a](const int x)mutable ->bool
    {
        int t = a;
        a=x;
        return x>t;
    };
    vector<int> vec={10,9,7,8,100};
    auto it = find_if(vec.begin(),vec.end(),f);
    cout<<*it<<endl;
    
    return 0;
}
