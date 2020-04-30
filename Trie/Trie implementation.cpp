#include<bits/stdc++.h>
using namespace std;

struct Trie
{

    bool isLeaf;
    unordered_map<char,Trie*>mp;

};
/// function that returns a new trie node
Trie* getNewTrieNode()
{

    Trie* node = new Trie;
    node->isLeaf=false;

    return node;

}

void insert(Trie*& head, char* str)
{

    if(head==nullptr)
    {
        head=getNewTrieNode();
    }
        /// start form root node;
        Trie* cur =head;
        while(*str)
        {
            /// Create new node if path does not exists
            if(cur->mp.find(*str)==cur->mp.end())
            {
                cur->mp[*str]=getNewTrieNode();
            }
            /// go to next node.
            cur = cur->mp[*str];

            str++; /// move to next character.

        }
        cur->isLeaf=true;

}

bool havechildren(Trie const* cur)
{

    for(auto it : cur->mp)
    {
        if(it.second!=nullptr)
            return true;
    }
    return false;

}
bool deletion(Trie*& cur, char* str)
{
/// if trie is empty
    if(cur==nullptr)
        return false;

    if(*str)
    {
        if(cur!=nullptr && cur->mp.find(*str)!=cur->mp.end() && deletion(cur->mp[*str],str+1) && cur->isLeaf==false)
        {
            if(!havechildren(cur))
            {
                delete cur;
                cur=nullptr;
                return false;

            }
            else
            {
                return false;
            }
        }
    }
    if(*str=='\0' && cur->isLeaf)
    {
        if(!havechildren(cur))
        {
            delete cur;
            cur = nullptr;
            return true;
        }
        else
        {
            cur->isLeaf =false;
            return false;
        }
    }
    return false;
}

bool search(Trie* head, char* str)
{

    if(head==nullptr)
    {
        return false;
    }

    Trie* cur = head;

    while(*str)
    {
        cur = cur->mp[*str];
        if(cur==nullptr)
            return false;
        str++;
    }

    return cur->isLeaf;
}

int main()
{

Trie* head = nullptr;

insert(head,"hello");
insert(head,"helo");
cout << search(head ,"helo") << '\n'; /// 1

deletion(head,"helo");
cout << search(head,"helo") << '\n'; /// 0
cout << search(head,"hello") << '\n'; /// 1

}
