#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int ia[] = {10,200,1,4,5,11,80};
    int val = 555;
    //这里的begin和end 获得的是数组开头和结尾后一个元素的指针
    int* result = find(begin(ia),end(ia),val);
    cout<<*result<<endl;//
    bool a =  result == end(ia);
    cout<<a<<endl;
    cout<<(0?"no match":"match")<<endl;
    
    vector<int> vec = {10,200,1,4,5,11,80};
    fill(vec.begin(),vec.begin()+vec.size()/2,0);
    
    
    return 0;
}
