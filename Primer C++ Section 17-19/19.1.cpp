#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void * operator new(size_t sz)
{
    void* r =  malloc(sz);
    if(r==0){
        throw bad_alloc();
    }else{
        return r;
    }
}

void operator delete(void * p) noexcept//记得这里要写noexcept
{
    free(p);
}


int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}