class Solution {
public:
    long long countCommas(long long n) {
        long long p = 1000;
        long long c = 0;
        while(n>=p){
            c = c + (n-p+1);
            p = p*1000;
        }
        return c;
        
    }
};