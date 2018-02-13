#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> * factory()
{
    return new vector<int>;
}

void input(vector<int>*v)
{
    istream_iterator<int> eof;
    copy(istream_iterator<int>(cin),eof,back_inserter(*v));
}

void prin(vector<int>*v)
{
    copy(v->begin(),v->end(),ostream_iterator<int>(cout," "));
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    auto a = factory();
    input(a);
    prin(a);
    delete a;
    
    
    return 0;
}
