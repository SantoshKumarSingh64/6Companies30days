// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    class Node{
        public:
            bool wordEnd;
            unordered_map<char, Node*>mp;
            Node(){
                wordEnd = 0;
            }
    };
    void addWord(string &word, Node* root) {
        Node* curr = root;
        int i = 0;
        while(i<word.size()){
            if(curr->mp.find(word[i])==curr->mp.end()){
                curr->mp[word[i]] = new Node();
            }
            curr = curr->mp[word[i]];
            i++;
        }
        curr->wordEnd = 1;
    }
    void dfs(Node* curr, vector<string>&res, string &form){
        
        if(curr->wordEnd) res.push_back(form);
        char c;
        for(int i=0; i<26; i++){
            c = char('a'+i);
            if(curr->mp.find(c)==curr->mp.end()) continue;
            form.push_back(c);
            dfs(curr->mp[c], res, form);
            form.pop_back();
        }
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Node* root = new Node();
        for(int i=0; i<n; i++){
            addWord(contact[i], root);
        }
        vector<vector<string>>res;
        string prefix;
        Node* curr = root;
        for(auto c: s){
            prefix.push_back(c);
            if(curr->mp.find(c)==curr->mp.end()) break;
            else curr = curr->mp[c];
            vector<string>temp;
            dfs(curr, temp, prefix);
            if(temp.empty()) break;
            else res.push_back(temp);
        }
        while(res.size()<s.size()){
            res.push_back({"0"});
        }
        delete(root);
        return res;
    }
};
     

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
