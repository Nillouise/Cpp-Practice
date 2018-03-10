#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void del(ifstream *p)
{
    
}

void exercise(int *b,int *e)
{
    vector<int> v(b,e);
    // int *p = new int[v.size()];
    // unique_ptr<int> p(new int[v.size()]);
    unique_ptr<int[]> p(new int[v.size()]);
    shared_ptr<int> sp(new int[v.size()],[](int* sp){delete[] sp;});
    
    ifstream in("ints");
    auto lam = [](ifstream*is){
        is->close();
        cout<<"close ifstream"<<endl;
    };
    unique_ptr<ifstream,decltype(lam)>up(&in,lam);//这里好像不必传入lambda的指针。
    // unique_ptr<ifstream,decltype([](ifstream *is)->void {return;})*> up(&in,&[](ifstream* is){is->close();});// 错的
    // unique_ptr<ifstream,decltype(del)*> up(&in,del);// 错的
    // unique_ptr<ifstream> up(&in);
    
}


int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    exercise(nullptr,nullptr);
    
    
    return 0;
}