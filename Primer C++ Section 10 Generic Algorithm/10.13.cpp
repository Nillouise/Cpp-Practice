#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


bool isTrue(const string &s)
{
    return s.size()>=5;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    vector<string> words={"1","444","apple","no ok"};
    auto trueend = partition(words.begin(),words.end(),isTrue);
    for(auto a = words.begin();a!=trueend;a++)
    {
        cout<<*a<<endl;
    }
    
    
    return 0;
}
