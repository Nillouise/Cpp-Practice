#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

//应该用const
template<typename T>
void prin(T& vec)
{
    for(typename T::size_type i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
}

//应该用const
template<typename T>
void prinv2(T& vec)
{
    for(auto a = vec.begin();a!=vec.end();a++)
    {
        cout<<*a<<" ";
    }
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<int> vec ={1,2,3};
    prinv2(vec);
    
    
    
    return 0;
}
