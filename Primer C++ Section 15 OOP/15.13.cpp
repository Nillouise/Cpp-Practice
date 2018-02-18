#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class base
{
public:
    string name()
    {
        return basename;
    }
    virtual void print(ostream &os)
    {
        os<<basename;
    }
private:
    string basename;
};

class derived:public base
{
public:
    void print(ostream &os)
    {
        cout<<"recursion ";
        base::print(os);
        //下面这句会递归，然后被爆栈
        // print(os);
        os<<" "<<i;
    }
private:
    int i;
};


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    derived d;
    d.print(cout);
    
    
    return 0;
}
