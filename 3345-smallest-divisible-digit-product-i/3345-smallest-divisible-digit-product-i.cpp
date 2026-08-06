class Solution {
public:
    int solve(int n){
        int product = 1;

        while(n > 0){
            product *= n % 10;
            n /= 10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            int product = solve(n);

            if (product % t == 0){
                return n;
            }else{
                n++;
            }
        }
        
    }
};