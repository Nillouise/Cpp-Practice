#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void e4_37()
{
    //4.37
    int i;
    double d;
    const string *ps;
    char *pc;
    void *pv;
    
    pv = (void*)ps;
    i=int(*pc);
    pv = &d;
    pc = (char*) pv;
    
    pv = static_cast<void*>(const_cast<string*>(ps));
    //上面的语句可以直接写成：
    pv = const_cast<string*>(ps);
    i = static_cast<int>(*pc);
    pv = static_cast<void*> (&d);
    pc = static_cast<char*>(pv);
    
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    // 4.36
    int i;
    double d;
    i*=static_cast<int>(d);
    cout<<i;
    
    e4_37();
    
    return 0;
}
