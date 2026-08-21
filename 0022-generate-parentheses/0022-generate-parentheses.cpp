class Solution {
public:
    void solve(int n, string s,vector<string>& ans,int o, int c){
        if(o==n && c==n){
            ans.push_back(s);
            return;
        }

        // add karenge open bracket
        if(o<n){
            solve(n,s+'(',ans,o+1,c);
        }
        // nhi toh close ke liye call karo
        if(c<o){
            solve(n,s+')',ans,o,c+1);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,"",ans,0,0);
        return ans;

        
    }
};