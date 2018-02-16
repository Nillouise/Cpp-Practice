#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class CheckLen
{
public:
    CheckLen(int n):n(n){}
    bool operator()(const string&s)
    {
        return s.size()==n;
    }
private:
    int n;
};


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<CheckLen> vec;
    for(int i=1;i<=10;i++)
    {
        vec.push_back(CheckLen(i));
    }
    int somebody=10;
    
    auto pval = [somebody](){
        // cout<<somebody--;//注意这是错的,值捕获的变量不能被改变（除非被声明成mutable
    };
    
    auto pmut = [somebody]()mutable{
        cout<<somebody--;
    };
    for(int i=0;i<10;i++)
    {
        pval();
    }
    for(int i=0;i<10;i++)
    {
        pmut();
    }
    
    return 0;
}
