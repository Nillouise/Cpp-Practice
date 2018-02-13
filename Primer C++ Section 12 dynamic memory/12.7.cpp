#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

shared_ptr<vector<int>> factory()
{
    return make_shared<vector<int>>();
}

void input(shared_ptr<vector<int>> p)
{
    int a;
    while(cin>>a)
    {
        p->push_back(a);    
    }
}

void prin(shared_ptr<vector<int>>p)
{
    for(auto a:*p)
    {
        cout<<a<<" ";    
    }    
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    shared_ptr<vector<int>> p = factory();
    input(p);
    prin(p);
    
    
    return 0;
}
