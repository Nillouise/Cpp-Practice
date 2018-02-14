#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class QueryResult;

class TextQuery
{
public:
    TextQuery(ifstream& in);
    QueryResult query(const string &s);
private:
    map<string,set<int>> but;
    vector<string> text;     
};

TextQuery::TextQuery(ifstream& in)
{
    string s;
    for(int i = 0;getline(in,s);i++)
    {
        stringstream ss(s);
        string word;
        text.push_back(s);
        while(ss>>word)
        {
            but[word].insert(i);
        }
    }
}

class QueryResult
{
public:
    shared_ptr<set<int>> pSet;
    shared_ptr<vector<string>> pVec;
    shared_ptr<ifstream> file;
    
    set<int>::iterator begin();
    set<int>::iterator end();
    
    shared_ptr<ifstream> get_file();
};

shared_ptr<ifstream> QueryResult::get_file()
{
    return file;
}

set<int>::iterator QueryResult::begin()
{
    if(!pSet)
    {
        pSet = shared_ptr<set<int>>(new set<int>);
    }
    return pSet->begin();
}
set<int>::iterator QueryResult::end()
{
    if(!pSet)
    {
        pSet = shared_ptr<set<int>>(new set<int>);
    }
    return pSet->end();
}

QueryResult TextQuery::query(const string &s)
{
    QueryResult res;
    // res.pVec = make_shared<vector<string>>(&text,[](vector<string>* p){});
    // res.pSet = make_shared<set<int>>(&but[s],[](set<int>*p){});
    res.pVec = shared_ptr<vector<string>>(&text,[](vector<string>* p){});
    res.pSet = shared_ptr<set<int>> (&but[s],[](set<int>*p){});
    return res;
}

ostream& operator<<(ostream&out,const QueryResult &q)
{
    for(auto a :*q.pSet)
    {
        out<<(*q.pVec)[a]<<endl;
    }
    return out;
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while(true)
    {
        cout<<"enter word to look for, or q to quit: ";
        string s;
        if(!(cin>>s)||s=="q")
            break;
        cout<<tq.query(s);
        // print(cout<<tq.query(s))<<endl;
    }
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    ifstream f("12.26.cpp");
    runQueries(f);
    
    
    return 0;
}
