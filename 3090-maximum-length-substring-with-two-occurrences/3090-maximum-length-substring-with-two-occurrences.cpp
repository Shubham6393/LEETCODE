class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int> mp;
        int n = s.length();
        int l = 0;
        int maxi = INT_MIN;
        for(int j = 0; j<n; j++){
            mp[s[j]]++;
            while(mp[s[j]] > 2){
                mp[s[l]]--;
                l++;
            }
            maxi = max(j-l+1, maxi);
        }
        return maxi;
    }
};