#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

namespace std
{
    template<>
    struct hash<vector<int>>
    {
        typedef size_t result_type;
        typedef vector<int> argument_type;
        size_t operator()(const vector<int>& s)const;
    };
    size_t
    hash<vector<int>>::operator()(const vector<int>&s)const
    {
        size_t res = 0;
        for(auto a:s)
        {
            res^=hash<int>()(a);
        }
        return res;
    }
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    unordered_multiset<vector<int>> svec;
    vector<int> vec;
    for(int i=0;i<5;i++)
    {
        vec.push_back(i);
        svec.insert(vec);
    }
    
    for(auto a:svec)
    {
        for(auto b:a)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
