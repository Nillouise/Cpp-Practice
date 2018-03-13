#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<string> vec={"ffdd","","faa"};
    int n = count_if(vec.begin(),vec.end(),mem_fn(&string::empty));
    n = count_if(vec.begin(),vec.end(),bind(&string::empty,placeholders::_1));
    function<bool(const string&)> f= &string::empty;
    n = count_if(vec.begin(),vec.end(),f);
    cout<<n<<endl;
    
    return 0;
}