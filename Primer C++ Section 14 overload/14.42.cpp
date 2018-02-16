#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    vector<int> vec{10,1055};
    int cnt = count_if(vec.begin(),vec.end(),bind(greater<int>(),placeholders::_1,1024));
    cout<<cnt<<endl;
    vector<string>strs;
    find_if(strs.begin(),strs.end(),bind(not_equal_to<string>(),placeholders::_1,"pooh"));
    
    return 0;
}
