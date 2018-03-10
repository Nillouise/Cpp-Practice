#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


class E
{
public:
    E(const E& e){
        // throw 1;
    }
    E(){
        throw 2;
    }
};

class C
{
public:
    C()try{    
    }
    // catch(int i){
    //     cout<<i<<endl;
    // }
    catch(...){
        cout<<"not end"<<endl;
    }
    
    E e;
};

// C::C() try{
// 
// }catch(...){
// 
// }


int main()
{
    try{
        ios::sync_with_stdio(false);
        
    }catch(...){
        
        abort();    
    }
    
    typedef int EXCPTYPE;
    
    try{
        throw EXCPTYPE();
    }catch(EXCPTYPE e){
        cout<<e<<endl;
    }
    try{
        
        C c;
    }catch(int a){
        cout<<"end with a="<<a<<endl;
    }
    
    return 0;
}
