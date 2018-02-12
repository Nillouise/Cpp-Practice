#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    vector<int> vec{1,2,3,4,5,6};
    for(auto it = vec.rbegin();it!=vec.rend();it++)
    {
        cout<<*it<<" ";    
    }
    cout<<endl;
    for(auto it = vec.end();it!=vec.begin();)
    {
        cout<<*--it<<" ";
    }
    cout<<endl;
    
    return 0;
}
