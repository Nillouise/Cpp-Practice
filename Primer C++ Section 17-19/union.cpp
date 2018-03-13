#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Sales_data{
public:
    Sales_data() = default;
    ~Sales_data() = default;
    Sales_data(int i):a(i){}
    Sales_data(const Sales_data &rhs):a(rhs.a){}
    Sales_data& operator=(const Sales_data&rhs){
        a = rhs.a;
        return *this;
    }
private:
    int a = 0;
};

class Token{
public:
    Token():tok(INT),ival{0}{}
    Token(const Token &t):tok(t.tok){copyUnion(t);}
    Token(Token&& t);
    Token &operator=(const Token&);
    
    ~Token(){
        if(tok==STR)sval.~string();
        if(tok==SDAT)sdat.~Sales_data();
    }
    Token &operator=(const string&);
    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);
    Token &operator=(const Sales_data &rhs);
    Token &operator=(Token&& t);
private:
    enum{INT,CHAR,DBL,STR,SDAT}tok;
    union{
        char cval;
        int ival;
        double dval;
        string sval;
        Sales_data sdat;
    };
    void copyUnion(const Token&);
};



Token::Token(Token&&t){
    if(t.tok==STR){
        new (&sval) string(std::move(t.sval));
    }else if(t.tok==SDAT){
        new (&sdat) Sales_data(std::move(t.sdat)); 
    }else{
        copyUnion(t);
    }
}

Token &Token::operator=(int i)
{
    if(tok==STR) sval.~string();
    ival = i;
    tok = INT;
    return *this;
}

Token &Token::operator=(const string &s)
{
    if(tok==STR)
        sval = s;
    else
        new(&sval) string(s);
    tok = STR;
    return *this;
}



void Token::copyUnion(const Token &t)
{
    switch(t.tok){
        case Token::INT: ival = t.ival;break;
        case Token::CHAR: cval = t.cval;break;
        case Token::DBL: dval = t.dval;break;
        case Token::STR: new (&sval) string(t.sval);break;
        case Token::SDAT: new (&sdat) Sales_data(t.sdat);break;
    }
}


Token &Token::operator=(const Token &t)
{
    if(tok == STR&&t.tok!=STR)sval.~string();
    if(tok == SDAT&&t.tok!=SDAT)sdat.~Sales_data();
    if(tok==STR&&t.tok==STR)
        sval = t.sval;
    else if(tok==SDAT&&t.tok==SDAT)
        sdat = t.sdat;
    else
        copyUnion(t);
    tok = t.tok;
    return *this;
}

Token& Token::operator(Token && t){
    if(tok == STR&&t.tok!=STR)sval.~string();
    if(tok == SDAT&&t.tok!=SDAT)sdat.~Sales_data();
    if(tok==STR&&t.tok==STR)
        sval = std::move(t.sval);
    else if(tok==SDAT&&t.tok==SDAT)
        sdat = std::move(t.sdat);
    else
        copyUnion(t);
    tok = t.tok;
    return *this;
}

Token& Token::operator=(const Sales_data &rhs){
    if(tok==STR){
        sval.~string();
    }else if(tok==SDAT){
        sdat.~Sales_data();
    }
    
    tok = SDAT;
    sdat = rhs;
    return *this;
}

int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}