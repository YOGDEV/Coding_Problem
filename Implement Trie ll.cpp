//https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

//code

#include <bits/stdc++.h> 
class Trie{
    struct Node{
       Node* child[26]={nullptr};
       int isWord=0;
       int isprefix=0;
    };
    Node *root;
    public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node * curr=root;
        for(int i=0;i<word.length();i++)
        {
            if(curr->child[word[i]-'a']==nullptr)
            curr->child[word[i]-'a']=new Node();

            curr=curr->child[word[i]-'a'];
            curr->isprefix++;
        }
        curr->isWord++;
    }

    int countWordsEqualTo(string &word){
        Node * curr=root;
        for(int i=0;i<word.length();i++)
        {
            if(curr->child[word[i]-'a']==nullptr)return 0;

            curr=curr->child[word[i]-'a'];
        }
        return curr->isWord;
    }

    int countWordsStartingWith(string &word){
        Node * curr=root;
        for(int i=0;i<word.length();i++)
        {
            if(curr->child[word[i]-'a']==nullptr)return 0;

            curr=curr->child[word[i]-'a'];

        }
        return curr->isprefix;
    }

    void erase(string &word){
        Node * curr=root;
        for(int i=0;i<word.length();i++)
        {
            if(curr->child[word[i]-'a']==nullptr)return;

            curr=curr->child[word[i]-'a'];
            curr->isprefix--;
        }
        curr->isWord--;
    }
};
