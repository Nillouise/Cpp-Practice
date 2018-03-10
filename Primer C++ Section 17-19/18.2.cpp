#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void exercise(int *b,int *e)
{
    vector<int> v(b,e);
    // int *p = new int[v.size()];
    // unique_ptr<int> p(new int[v.size()]);
    unique_ptr<int[]> p(new int[v.size()]);
    shared_ptr<int> sp(new int[v.size()],[](int* sp){delete[] sp;});
    
    ifstream in("ints");
    // unique_ptr<ifstream,decltype([](ifstream *is)> up(&in,[](ifstream* is){is->close();});// 错的
    // unique_ptr<ifstream> up(&in);
    
}


int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}