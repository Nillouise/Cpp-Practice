#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Function
{
public:
    int operator()(int statement,int i,int j)
    {
        return statement?i:j;
    }
};


class PrintString
{
public:
    PrintString(istream &stream):stream(stream){}
    string operator()()
    {
        string s;
        stream>>s;
        return s;
    }
private:
    istream &stream;
};

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    Function obj;
    cout<<obj(1,1,2);
    PrintString ps(cin);
    vector<string> vec;
    for(string s=ps();!s.empty();s = ps())
    {
        vec.push_back(s);
    }
    for(auto a:vec)
    {
        cout<<"vec : "<<a<<endl;
    }
    cout<< ps();
    cout<<ps();
    
    return 0;
}
