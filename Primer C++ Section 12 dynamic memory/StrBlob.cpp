#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

class StrBlob{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const {return data->size();}
    bool empty()const{return data->empty();}
    void push_back(const string &t){data->push_back(t);}
    void pop_back();
    string& front();
    string& back();
    //练习12.2
    const string& front();
    const string& back();
    
// private:
    shared_ptr<vector<string>> data;
    void check(size_type i,const string &msg)const;
};

StrBlob::StrBlob():data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string>il):
                data(make_shared<vector<string>>(il)){}
void StrBlob::check(size_type i,const string &msg)const
{
    if(i>=data->size())
        throw out_of_range(msg);
}

string& StrBlob::front()
{
    check(0,"front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0,"back on empty StrBlob");
    return data->back();
}

const string& StrBlob::front()
{
    check(0,"front on empty StrBlob");
    return data->front();
}

const string& StrBlob::back()
{
    check(0,"back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    ios::sync_with_stdio(false);
    //联系12.1
    StrBlob b1;
    {
        StrBlob b2 = {"a","an","the"};
        b1 = b2;
        b2.push_back("about");
    }    
    for(auto a:*b1.data){
        cout<<a<<endl;
    }
    
    return 0;
}
