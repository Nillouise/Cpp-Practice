#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

namespace Ex{
    int ivar = 0;
    double dvar = 0;
    const int limit = 100;
}

int ivar=0;

// using Ex::ivar;//会跟上面的声明冲突
// using Ex::dvar;
// using Ex::limit;

// using namespace Ex;//不使用的时候，就不会提示冲突

int main()
{
    ios::sync_with_stdio(false);
    
    // using Ex::ivar;
    // using Ex::dvar;//会跟下面的声明冲突
    // using Ex::limit;//会跟下面的声明冲突
    
    using namespace Ex;
    
    double dvar = 3.1416;
    int iobj = limit+1;
    // ++ivar;
    ++::ivar;
    
    
    return 0;
}