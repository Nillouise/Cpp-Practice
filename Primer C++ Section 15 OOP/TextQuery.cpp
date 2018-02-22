#include<bits/stdc++.h>
using namespace std;
typedef long long LL;



class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	typedef std::vector<std::string>::size_type line_no;
	typedef std::set<line_no>::const_iterator line_it;
	QueryResult(std::string s, 
	            std::shared_ptr<std::set<line_no>> p, 
	            std::shared_ptr<std::vector<std::string>> f):
		sought(s), lines(p), file(f) { }
	std::set<line_no>::size_type size() const  { return lines->size(); }
	line_it begin() const { return lines->cbegin(); }
	line_it end() const   { return lines->cend(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
	std::string sought;  // word this query represents
	std::shared_ptr<std::set<line_no>> lines; // lines it's on
	std::shared_ptr<std::vector<std::string>> file;  //input file
};

std::ostream &print(std::ostream&, const QueryResult&);

class QueryResult; // declaration needed for return type in the query function
class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const; 
    void display_map();        // debugging aid: print the map
private:
    std::shared_ptr<std::vector<std::string>> file; // input file
    // maps each word to the set of the lines in which that word appears
    std::map<std::string, 
	         std::shared_ptr<std::set<line_no>>> wm;  

	// canonicalizes text: removes punctuation and makes everything lower case
    static std::string cleanup_str(const std::string&);
};
// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while (getline(is, text)) {       // for each line in the file
		file->push_back(text);        // remember this line of text
		int n = file->size() - 1;     // the current line number
		istringstream line(text);     // separate the line into words
		string word;               
		while (line >> word) {        // for each word in that line
            word = cleanup_str(word);
            // if word isn't already in wm, subscripting adds a new entry
            auto &lines = wm[word]; // lines is a shared_ptr 
            if (!lines) // that pointer is null the first time we see word
                lines.reset(new set<line_no>); // allocate a new set
            lines->insert(n);      // insert this line number
		}
	}
}

// not covered in the book -- cleanup_str removes
// punctuation and converts all text to lowercase so that
// the queries operate in a case insensitive manner
string TextQuery::cleanup_str(const string &word)
{
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it) {
        if (!ispunct(*it))
            ret += tolower(*it);
    }
    return ret;
}

QueryResult
TextQuery::query(const string &sought) const
{
	// we'll return a pointer to this set if we don't find sought
	static shared_ptr<set<line_no>> nodata(new set<line_no>); 

    // use find and not a subscript to avoid adding words to wm!
    auto loc = wm.find(cleanup_str(sought));

	if (loc == wm.end()) 
		return QueryResult(sought, nodata, file);  // not found
	else 
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream & os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << "times" << endl;

    // print each line in which the word appeared
	for (auto num : *qr.lines) // for every element in the set 
		// don't confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") " 
		   << *(qr.file->begin() + num) << endl;

	return os;
}

// debugging routine, not covered in the book
void TextQuery::display_map()
{
    auto iter = wm.cbegin(), iter_end = wm.cend();

    // for each word in the map
    for ( ; iter != iter_end; ++iter) {
        cout << "word: " << iter->first << " {";

        // fetch location vector as a const reference to avoid copying it
        auto text_locs = iter->second;
        auto loc_iter = text_locs->cbegin(),
                        loc_iter_end = text_locs->cend();

        // print all line numbers for this word
        while (loc_iter != loc_iter_end)
        {
            cout << *loc_iter;

            if (++loc_iter != loc_iter_end)
                 cout << ", ";

         }

         cout << "}\n";  // end list of output this word
    }
    cout << endl;  // finished printing entire map
}




class Query_base
{
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&)const = 0;
    virtual string rep()const = 0;
};


class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query&,const Query&);
    friend Query operator&(const Query&,const Query&);
public:
    Query(const string&);
    QueryResult eval(const TextQuery &t)const
        {return q->eval(t);}
    string rep()const
    {
        return "[Query rep]"+q->rep();
    }
private:
    Query(shared_ptr<Query_base> query):q(query){}
    shared_ptr<Query_base> q;
};

ostream&
operator<<(ostream &os,const Query &query)
{
    return os<<query.rep();
}

class WordQuery: public Query_base
{
    friend class Query;
    WordQuery(const string&s):query_word(s){}
    QueryResult eval(const TextQuery &t)const
    {
        return t.query(query_word);
    }
    string rep()const{
        return query_word;
    }
    string query_word;
};

inline
Query::Query(const string &s):q(new WordQuery(s)){
    cout<<"Query::Query(const string &s):q(new WordQuery(s))"<<endl;
}

class NotQuery:public Query_base
{
    friend Query operator~(const Query&);
    NotQuery(const Query &q):query(q){}
    string rep()const
    {
        return "~("+query.rep()+")";
    }
    QueryResult eval(const TextQuery& text)const override
    {
        auto result = query.eval(text);
        auto ret_lines = make_shared<set<line_no>>();
        auto beg = result.begin(),end = result.end();
        auto sz = result.get_file()->size();
        for(size_t n = 0;n!=sz;++n)
        {
            if(beg==end||*beg!=n)
                ret_lines->insert(n);
            else if(beg!=end)
                ++beg;
        }
        return QueryResult(rep(),ret_lines,result.get_file());
    }
    Query query;
};

inline Query operator~(const Query &operand)
{
    //注意这里用了隐式转换
    return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery:public Query_base
{
protected:
    BinaryQuery(const Query&l,const Query &r,string s):
            lhs(l),rhs(r),opSym(s){}
    string rep() const
    {
        return "("+lhs.rep()+" "
                +opSym+" "
                +rhs.rep()+")";
    }
    Query lhs,rhs;
    string opSym;
};

class AndQuery: public BinaryQuery{
    friend Query operator&(const Query&,const Query&);
    AndQuery(const Query &left,const Query &right):
        BinaryQuery(left,right,"&"){}
        //这里必须放一个空的函数体才行，不然继承自抽象基类会让编译器检查这玩意有没有被定义（即使没有调用这个函数）
    QueryResult eval(const TextQuery& text)const override
    {
        auto left = lhs.eval(text),right = rhs.eval(text);
        auto ret_lines = make_shared<set<line_no>>();
        set_intersection(left.begin(),left.end(),
                        right.begin(),right.end(),
                        inserter(*ret_lines,ret_lines->begin()));
        return QueryResult(rep(),ret_lines,left.get_file());
    }
};

inline Query operator&(const Query &lhs,const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

class OrQuery:public BinaryQuery
{
    friend Query operator|(const Query&,const Query&);
    OrQuery(const Query &left,const Query &right):
        BinaryQuery(left,right,"|"){}
    QueryResult eval(const TextQuery &text)const override
    {
        auto right = rhs.eval(text),left = lhs.eval(text);
        auto ret_lines = make_shared<set<line_no>>(left.begin(),left.end());
        ret_lines->insert(right.begin(),right.end());
        return QueryResult(rep(),ret_lines,left.get_file());
    }
};
inline Query operator|(const Query &lhs,const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    // Query q = Query("fiery")&Query("bird")|Query("wind");
    // // Query q = Query("fiery")&Query("bird");
    // // Query q = ~Query("firy");
    // cout<<q;
    // cout<<q.
    
    std::ifstream file("Quoto.cpp");

    TextQuery tQuery(file);

    Query q = Query("class")  | Query("double");
    // Query q = Query("double");
    QueryResult re = q.eval(tQuery);
    print(cout,re);
    // cout<<re;
    // std::cout << q.eval(tQuery);
    
    return 0;
}
