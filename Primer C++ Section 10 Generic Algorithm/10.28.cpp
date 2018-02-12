#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

// Exercise 10.26:
// Explain the differences among the three kinds of insert iterators.

// back_inserter uses push_back.
// front_inserter uses push_front.
// insert uses insert
// This function takes a second argument, which must be an iterator into the given container. Elements are inserted ahead of the element denoted by the given iterator.

void prin(const list<int>&v)
{
    for_each(v.begin(),v.end(),[](const int &i){cout<<i;});
    cout<<endl;
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    list<int> ori;
    for(int i=1;i<=9;i++)
        ori.push_back(i);
    list<int> ins;
    list<int> bac;
    list<int> fro;
    //据我看，这个inserter指定的元素是固定的那一个，而不是固定的位置。
    copy(ori.begin(),ori.end(),inserter(ins,ins.begin()));
    prin(ins);
    copy(ori.begin(),ori.end(),back_inserter(bac));
    prin(bac);
    copy(ori.begin(),ori.end(),front_inserter(fro));
    prin(fro);
    
    return 0;
}
