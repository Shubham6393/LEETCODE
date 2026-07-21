class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes = 0;
        for(char ch : s){
            if(ch=='1'){
                totalOnes++;
            }
        }
        vector<pair<char,int>> m;
        int count = 1;
        for(int i = 1;i<s.length();i++){
            if(s[i] == s[i-1]) count++;
            else{
                m.push_back({s[i-1],count});
                count = 1;
            }
        }
        m.push_back({s.back(),count});
        int ans = 0;
        for(int i =1;i+1<m.size();i++){
            if(m[i].first == '1' && m[i-1].first == '0' && m[i+1].first == '0'){
                int zero = m[i-1].second + m[i+1].second;
                ans = max(zero,ans);
            }
        }
        return totalOnes + ans;
        
    }
};