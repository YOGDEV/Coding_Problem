//https://leetcode.com/problems/design-add-and-search-words-data-structure/

//code

class WordDictionary {
    struct Node{
        bool end=false;
        Node* child[26]={nullptr};
    };
       Node* root=new Node();    
public:
    WordDictionary() {

    }
    
    void addWord(string word) {
        int n=word.length();
        Node*p=root;
        for(int i=0;i<n;i++)
        {
            if(!p->child[word[i]-'a'])p->child[word[i]-'a']=new Node();
            p=p->child[word[i]-'a'];
        }
        p->end=true;
    }
    bool dfs(string word,Node* node)
    {
        for(int i=0;i<word.length();i++)
        {   
            char ch=word[i];
            if(ch=='.')
            {
                for(auto c:node->child)
                {
                    if(c && dfs(word.substr(i+1),c))return true;
                    
                }
                return false;
            }
            int ind=word[i]-'a';
            if(!node->child[ind])return false;
            node=node->child[ind];
        }
        return node->end;
    }

    bool search(string word) {
        return dfs(word,root);
    }
    };
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
