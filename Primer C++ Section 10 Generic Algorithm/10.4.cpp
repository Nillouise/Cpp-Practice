#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    vector<double> vec={1.5,2.6};
    //第三个参数为int类型，会导致double类型都自动转换成int类型，导致损失精度
    double sum = accumulate(vec.cbegin(),vec.cend(),0);
    cout<<sum<<endl;
    
    return 0;
}
