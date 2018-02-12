#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

bool isShort(const string& s,int sz)
{
    return s.size()<=sz;
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    vector<string> vec={"ok","ffff","123456","987654321"};
    int cnt = count_if(vec.begin(),vec.end(),bind(isShort,placeholders::_1,6));
    cout<<cnt<<endl;//
    
    return 0;
}
