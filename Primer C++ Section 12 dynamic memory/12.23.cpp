#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void string_version()
{
    string a = "ok";
    string b = "no";
    char * res = new char[a.size()+b.size()+1];
    int t=0;
    for(auto c:a)res[t++]=c;
    for(auto c:b)res[t++]=c;
    res[t]=0;
    cout<<res<<endl;
}

void book_version()
{
    // dynamically allocated array of char
    char *concatenate_string = new char[strlen("hello " "world") + 1]();
    strcat(concatenate_string, "hello ");
    strcat(concatenate_string, "world");
    std::cout << concatenate_string << std::endl;
    delete [] concatenate_string;

    // std::string
    std::string str1{ "hello " }, str2{ "world" };
    std::cout << str1 + str2 << std::endl;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    const char * a = "ok";
    const char * b = "no";
    
    int cnt = 0;
    for(int i=0;a[i]!=0;i++)cnt++;
    for(int i=0;b[i]!=0;i++)cnt++;
    char * res = new char[cnt+1];
    int t = 0;
    for(int i=0;a[i]!=0;i++)res[t++]=a[i];
    for(int i=0;b[i]!=0;i++)res[t++]=b[i];    
    res[cnt] = 0;
    cout<<res<<endl;
    string_version();
    book_version();
    return 0;
}
