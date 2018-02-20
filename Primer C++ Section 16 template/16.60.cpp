#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

template<typename T,typename...Args>
shared_ptr<T> makeS(Args&&...args)
{
    return shared_ptr<T>(new T(forward<Args>(args)...));
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    shared_ptr<vector<string>> vec = makeS<vector<string>>(10,"off");
    
    for(auto a:*vec)
    {
        cout<<a<<endl;
    }
    
    
    return 0;
}
