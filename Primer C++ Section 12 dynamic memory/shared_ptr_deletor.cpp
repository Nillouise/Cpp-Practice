#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    shared_ptr<string> ptr = make_shared<string>("ok");
    //好像make_shared定义不了删除器,allocate_shared才可以
    shared_ptr<string> np(ptr.get(),[](string *s){cout<<"delete "<<*s<<endl;delete s;});
    // shared_ptr<string> np(ptr,[](){cout<<*s<<endl;delete s;});
    // shared_ptr<string> np(new string(),[](string*s){cout<<*s<<endl;delete s;});
    cout<<*ptr<<endl;//
    
    
    return 0;
}
