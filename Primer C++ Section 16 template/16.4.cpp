#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


template<typename T,typename U>
T myfind(T b,T e,U u)
{
    for(T i = b;i!=e;i++)
    {
        if(*i == u)
            return i;
    }
    return e;
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<int> vec{1,2,3,4,5};
    list<string> lst{"a","b","c","d"};
    auto itv = myfind(vec.begin(),vec.end(),3);
    auto itl = myfind(lst.begin(),lst.end(),"cl");
    if(itv!=vec.end())
    {
        cout<<*itv<<endl;
    }
    if(itl!=lst.end())
    {
        cout<<*itl<<endl;
    }
    
    
    return 0;
}
