#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<string> vec={"144","fdsf","123456","1234567"};
    int cnt = count_if(vec.begin(),vec.end(),[](const string&s){
        return s.size()>=6;
    });
    cout<<cnt<<endl;//
    
    return 0;
}
