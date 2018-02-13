#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    unique_ptr<string> up(new string("ok"));
    cout<<*up<<endl;
    //这里会提示这个构造函数已经被删除了
    auto p = up;
    
    int ix = 1024,*pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;
    IntP p0(ix);//wrong
    IntP p1(pi);//right,but undefined
    IntP p2(pi2);//right,but practice incorrect
    IntP p3(&ix);//right
    IntP p4(new int(2048));//right
    IntP p5(p2.get());//right,but latency error
    
    return 0;
}
