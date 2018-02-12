#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    istream_iterator<int> is(cin),eof;
    ostream_iterator<int> out(cout);
    vector<int> vec(is,eof);
    sort(vec.begin(),vec.end());
    copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
    
    unique_copy(vec.begin(),vec.end(),out);
    
    return 0;
}
