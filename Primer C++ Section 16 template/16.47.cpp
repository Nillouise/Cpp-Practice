#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void refswap(int &a,int &b)
{
    int t = a;
    a=b;
    b=t;
}
//注意上面的函数跟下面的函数会造成重载冲突，所以要改名字
void refswapr(int &&a,int &&b)
{
    cout<<"rval refswap" <<a<<" "<<b<<endl;
}

template<typename F,typename T1,typename T2>
void flip(F f,T1 &&t1,T2 &&t2)
{
    f(std::forward<T2>(t2),std::forward<T1>(t1));
}



int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int a=10,b=100;
    flip(refswap,a,b);    
    cout<<a<<" "<<b<<endl;//
    flip(refswapr,4,5);
    
    
    return 0;
}
