#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class TreeNode
{
public:
    TreeNode():
        value(""),
        count(0),
        left(nullptr),
        right(nullptr)
    {
    }
    
    TreeNode(const TreeNode &t):
        value(t.value),
        count(t.count),
        left(nullptr),
        right(nullptr)
    {
        if(t.left!=nullptr)
        {
            left = new TreeNode(*t.left);
        }
        if(t.right!=nullptr)
        {
            right = new TreeNode(*t.right);
        }
    }
    
    TreeNode& operator=(const TreeNode &t)
    {
        TreeNode* t1 = nullptr,*t2 = nullptr;
        if(t.left!=nullptr)
        {
            t1 = new TreeNode();
            *t1 = *t.left;
        }
        if(t.right!=nullptr)
        {
            t2 = new TreeNode();
            *t2 = *t.right;
        }
        delete left;
        delete right;
        left = t1;
        right = t2;
        value=t.value;
        count = t.count;
        return *this;
    }
    ~TreeNode()
    {
        delete left;
        delete right;
    }
private:
    string value;
    int count;//书上错了，应该是int *count，但我都写完了才知道书上是错的= =
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree
{
public:
    BinStrTree():root(nullptr)
    {
    }
    BinStrTree(const BinStrTree& rhs)
    {
        root = new TreeNode();
        *root = *rhs.root;
    }
    BinStrTree& operator=(const BinStrTree& rhs)
    {
        TreeNode *t1 = new TreeNode();
        *t1 = *rhs.root;
        delete root;
        root = t1;
        return *this;
    }
    ~BinStrTree()
    {
        delete root;
    }
private:
    TreeNode *root;
};


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
