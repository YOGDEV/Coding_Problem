//https://leetcode.com/problems/implement-trie-prefix-tree/

//code

class Trie {
    struct Node {
        Node * child[26]={nullptr};
        bool isWord=false;
    };
    Node * root=new Node();
public:
    Trie() {
         //constructor is only called when object is created
        //for each object a struct Node "structure " id created /.....
    }
    
    void insert(string word) {
      int n=word.length();
        Node *temp=root;
        for(int i=0;i<n;i++)
        {
          if(!temp->child[word[i]-'a'])
              temp->child[word[i]-'a']=new Node();
           temp= temp->child[word[i]-'a'];
        }
         temp->isWord=true;  
    }
    
    bool search(string word) {
         Node *temp=root;
        int n=word.length();
        for(int i=0;i<n;i++)
        {
            if(!temp->child[word[i]-'a'])return false;
            temp=temp->child[word[i]-'a'];
        }
        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        Node *temp=root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!temp->child[prefix[i]-'a'])return false;
            temp=temp->child[prefix[i]-'a'];
        }
        return true;
    }
};


    
    
    
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
