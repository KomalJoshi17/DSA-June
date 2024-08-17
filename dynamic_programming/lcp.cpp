
class Solution {
public:
    class Trie {
        public:
        Trie *pre[10];
        bool leaf;
        Trie() {
            this->leaf=false;
            for(int i=0;i<10;i++)
            {
                this->pre[i]=NULL;
            }
        }
    };
    int longestCommonPrefix(vector<int>& v1, vector<int>& v2) {
        vector<string>s1,s2;
        int n=v1.size(),m=v2.size();
        for(int i=0;i<n;i++) {
            string s=to_string(v1[i]);
            s1.push_back(s);
        }
        for(int i=0;i<m;i++) {
            string s=to_string(v2[i]);
            s2.push_back(s);
        }
        Trie *root= new Trie();
        for(int i=0;i<n;i++) {
            Trie *d=root;
            for(auto j:s1[i]) {
                char ch=j-'0';
                if(d->pre[ch]==NULL) {
                    d->pre[ch]=new Trie();
                }
                d=d->pre[ch];
            }
        }
        int ans=0;
        for(int i=0;i<m;i++) {
            Trie *d=root;
            int c=0;
            for(auto j:s2[i]) {
                char ch=j-'0';
                if(d->pre[ch]!=NULL) {
                    d=d->pre[ch];
                    c++;
                }
                else
                    break;
            }
            ans=max(ans,c);
        }
        return ans;
    }
};