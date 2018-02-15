#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Employee
{
    static int seed;
public:
    string name;
    int id;
    Employee(){seed++;id=seed;}
    Employee(const string &name):name(name),id(seed++){}    
    const int& getId()const{return id;}
};

int Employee::seed = 0;

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    Employee ee;
    const int& kr = ee.getId();
    cout<<kr<<endl;
    cout<<ee.getId();
    
    
    return 0;
}
