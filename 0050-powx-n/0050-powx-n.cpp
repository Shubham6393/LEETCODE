class Solution {
public:
    double solve(double x, long long n){
        // base case handle
        if(n==0){
            return 1;
        }
        // aadha kr diye O(log n)
        double half = solve(x, n/2);
        // check kr rhe h even or odd ke liye 
        if(n % 2 == 0){
            return half * half;
        }
        return x * half * half;
    }
    double myPow(double x, int n) {
        // int overflow se bachne ke liye long long use kiye 
        long long N = n;  
        // handle negative case 
        if(N<0){
            x = 1/x;
            N = -N;
        }
        return solve(x,N);
        
    }
};