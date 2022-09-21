// https://leetcode.com/problems/longest-common-prefix/
/*
  1.Insert all string in trie
  2.where trie divides in paths return cnt till that
  
  a.preprocessing O(S), where S is the number of all characters in the array, LCP query O(m)
  b.Trie build has O(S) time complexity. To find the common prefix of q in the Trie takes in the worst case O(m)
  c.S.C : O(S)
*/
class Node{
  public:
    char data;
    unordered_map<char,Node*>children;
    bool isEnd=false;
    Node(){}
    Node(char d){
        data=d;
    }
};
class Trie{
    Node* root;
 public:
    Trie(){
        root=new Node();
    }   
    Node* getTrie(){
        return root;
    }
    void insert(string word){
        Node* temp=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(temp->children.count(ch)==0){
                temp->children[ch]=new Node(ch);
                temp=temp->children[ch];
            }else{
                temp=temp->children[ch];
            }
        }
        temp->isEnd=true;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t=new Trie();
        for(int i=0;i<strs.size();i++){
            t->insert(strs[i]);
        }
        Node* temp=t->getTrie();
        string final="";
        while(temp and !temp->isEnd and temp->children.size()==1){
            auto it=temp->children.begin();
            final+=it->first;
            temp=it->second;
        }
        return final;
    }
};
