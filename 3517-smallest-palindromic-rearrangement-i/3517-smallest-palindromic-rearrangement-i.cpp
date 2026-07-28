class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string fh = "";
        int i = 0;
        while(i<n/2){
            fh += s[i];
            i++;
        }
        sort(fh.begin(),fh.end());
        string sh = fh;
        reverse(sh.begin(),sh.end());
        if (n % 2 == 0) {
            return fh + sh;
        } else {
            return fh + s[n / 2] + sh;
        }
    }
    
};