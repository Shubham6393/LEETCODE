class Solution {
public:

    const int INT_MAX_VAL = 2147483647;
    const int INT_MIN_VAL = -2147483648;
    
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
    int myAtoi(string s) {

        // "    123" -> 123
        // "   -23"  -> -23
        // "   +123" -> 123
        // "   -042" -> -42
        //"   -0b4c2" -> -4

        int i  = 0;
        int num = 0; // storing the result

        int sign = 1; // default is positive, -1 for negative

        // Case 1 -> Ignore leading Whitespace

        // e.g -> "   -0b4c2"
        //            i

        while(i<s.length() && (s[i] == ' ')){
            i++;
        }
        
        // Case 2 -> Check for Signed

        // e.g -> "    +123"
        //             i

        if(i<s.length()){
            if(s[i] == '-'){
                sign = -1;
                i++;
            }else if(s[i] == '+'){
                i++;
            }
        }

        // Case 3 -> Conversion

        // e.g -> "    -23sc"
        //              i

        while(i<s.length() && isDigit(s[i])){
            int digit = s[i] - '0'; // '2' - '0' => 2

            // Case 4 -> Rounding or Overflow condition
            // -IM ....... 0 .........+IM
            // 2,147,483,647, agar mai 10 se divide kr du -> 2,147,483,64
            // -2,147,483,647, agar mai 10 se divide kr du -> -2,147,483,64

            if(num == INT_MAX_VAL / 10){
                if(sign == 1){
                    if(digit >= 7){
                        return INT_MAX_VAL;
                    }
                }else if(sign == -1){
                    if(digit >= 8){
                        return INT_MIN_VAL;
                    }
                }
            }
            if(num > INT_MAX_VAL / 10){
                if(sign == 1){
                    return INT_MAX_VAL;
                }else{
                    return INT_MIN_VAL;
                }
            }
            num = num * 10 + digit; 
            i++;

        }
        return sign * num;
    }
};