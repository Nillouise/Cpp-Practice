#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int i=0,&r=i;
auto a = r; //int a=42

const int ci = i,&cr = ci;
auto b = ci;//int b = 42;//顶层const被去掉了
auto c = cr;//int c = 42//const引用也是没用的
auto d = &i;//这是错的吧，不能把int赋值给int*
auto e = &ci;//const int* e = &ci,这样应该不能给e赋值42如e=42 这是错的
auto &g = ci;//const int &g=ci,不能被赋值




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    return 0;
}
