#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int res(int a,int b)
{
    if(b==0){
        throw runtime_error("0 division");
    }
    return a/b;
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int a,b;
    cin>>a>>b;
    
    try{
        cout<<res(a,b);    
    }catch(runtime_error e){
        cout<<e.what()<<endl;
        cout<<"catch exception"<<endl;
    }
    
    return 0;
}
