#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    ifstream in("10.1cpp");
    istream_iterator<int> itin(in),eof;
    ostream_iterator<int> odd(cout," "),even(cout,"\n");
    while(itin!=eof){
        int a = *itin;
        if(a%2 ){
            *odd++=a;
        }else{
            *even++=a;
        }
    }
    
    return 0;
}
