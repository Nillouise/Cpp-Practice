#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    vector<int> vec(10);
    // fill_n(back_inserter(vec),vec.size(),5);
    // fill_n(vec.begin(),vec.size(),5);
    for(int i=0;i<5;i++){
        auto a = back_inserter(vec);
        int val;
        cin>>val;
        a=val;
    }
    for(auto a:vec){
        cout<<a<<" ";
    }
    
    return 0;
}
// 汗-_-||
// Exercise 10.8:
// We said that algorithms do not change the size of the containers over which they operate. Why doesn’t the use of back_inserter invalidate this claim?
// answer: Inserters like back_inserter is part of <iterator> rather than <algorithm>.
