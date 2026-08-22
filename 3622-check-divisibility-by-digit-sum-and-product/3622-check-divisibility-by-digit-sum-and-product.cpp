class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int temp = n;
        int r;
        while(n>0){
            r = n% 10;
            sum += r;
            product *= r;
            n = n/10;

        }
      
        int ans = sum + product;
        if(temp % ans == 0){
            return true;
        }else{
            return false;
        }

        
    }
};