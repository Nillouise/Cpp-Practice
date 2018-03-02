#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    list<char*> list= {"ok","fff","ddd"};
    vector<string> vec;
    vec.assign(list.begin(),list.end());
    for(auto a:vec){
        cout<<a<<endl;
    }
    
    return 0;
}
