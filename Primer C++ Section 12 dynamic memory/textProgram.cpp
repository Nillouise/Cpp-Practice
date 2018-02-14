#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while(true)
    {
        cout<<"enter word to look for, or q to quit: ";
        string s;
        if(!(cin>>s)||s=="q")
            break;
        print(cout<<tq.query(s))<<endl;
    }
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
