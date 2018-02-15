#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Folder;
class Message
{
    friend class Folder;
    friend void swap(Message&lhs,Message &rhs);
public:
    explicit Message(const string &str=""):
        contents(str){}
    Message(const Message &);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void addFolder(Folder *f);
    void remFolder(Folder *f);
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

class Folder
{
    friend class Message;
public:
    void addMsg(Message *msg);
    void remMsg(Message *msg);
    Folder() = default;
    Folder(const Folder &f);
    Folder& operator=(const Folder& f);
    ~Folder()
    {
        remove_from_Messages();
    }
private:
    set<Message*> msgs;
    void add_to_Messages(const Folder&);
    void remove_from_Messages();
};

void Message::addFolder(Folder *f)
{
    folders.insert(f);
}

void Message::remFolder(Folder *f)
{
    folders.erase(f);
}

Folder::Folder(const Folder &f)
{
    add_to_Messages(f);
    msgs = f.msgs;
}

Folder& Folder::operator=(const Folder& f)
{
    remove_from_Messages();
    add_to_Messages(f);
    msgs = f.msgs;
    return *this;
}

void Folder::add_to_Messages(const Folder& f)
{
    for(auto a:f.msgs)
    {
        a->addFolder(this);
    }
}

void Folder::remove_from_Messages()
{
    for(auto a:msgs)
    {
        a->remFolder(this);
    }
}

void Folder::addMsg(Message *msg)
{
    msgs.insert(msg);
}

void Folder::remMsg(Message *msg)
{
    msgs.erase(msg);
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for(auto f:m.folders)
        f->addMsg(this);
}

Message::Message(const Message&m):
    contents(m.contents),folders(m.folders)
{
    add_to_Folders(m);
}
void Message::remove_from_Folders()
{
    for(auto f:folders)
        f->remMsg(this);
}

Message::~Message()
{
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message&lhs,Message &rhs)
{
    using std::swap;
    for(auto f:lhs.folders)
        f->remMsg(&lhs);
    for(auto f:rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders,rhs.folders);
    swap(lhs.contents,rhs.contents);
    for(auto f:lhs.folders)
        f->addMsg(&lhs);
    for(auto f:rhs.folders)
        f->addMsg(&rhs);
}



int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
