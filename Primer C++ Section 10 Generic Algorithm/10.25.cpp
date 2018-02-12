#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


bool isTrue(const string &s)
{
    return s.size()>=5;
}
bool check_size(const string &s,int sz){
    return s.size()>=sz;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    vector<string> words={"1","444","apple","no ok"};
    auto trueend = partition(words.begin(),words.end(),bind(check_size,placeholders::_1,5));
    for_each(words.begin(),trueend,[](const string &s){
        cout<<s<<" ";
    });
    
    
    return 0;
}
