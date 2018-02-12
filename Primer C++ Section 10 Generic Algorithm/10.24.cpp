#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


bool check_size(const string &s,int sz){
    return s.size()>=sz;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    string s = "chosestring";
    vector<int> vec={100,4,160};
    auto v = find_if(vec.begin(),vec.end(),bind(check_size,s,placeholders::_1));
    cout<<*v<<endl;
    
    return 0;
}
