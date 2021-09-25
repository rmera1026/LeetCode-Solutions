class Solution {
public:
    int myAtoi(string str) {
        //if the string is empty than we cant make an integer.
        if (str.empty()) return 0;
        
        // here are simple initializations
        int len = str.length(), i = 0, sign = 1;
        
        // while i in less than the length of len AND
        // the current i in str is ' ' we go to the next char
        while (i < len && str[i] == ' ')
        i++;
        
        // when i has reached the end of the string we are done.
        if (i == len)
            return 0;
        
        // if the current i at str shows a negative sign then
        // sign is 0 which indicates negative and we go to the next i on str.
        if(str[i] == '-'){
            sign = 0;
            i++;
        }
        
        // if current i on str is positive go to the next
        // i in str
        else if (str[i] == '+')
            i++;
        
        long int out = 0;
        
        // while i is from 0-9 
        while (str[i] >= '0' && str[i] <= '9'){
            // Lets use 42 as an example: out will be 0 * 10 so out = 0;
            out = out * 10;
            if (out <= INT_MIN || out >= INT_MAX)
                break;
            // Here, the first iteration on line 36 says 
            // out = 0 so 0 + 4 - '0'
            out = out + (str[i] - '0');
            i++;
        }
        
        if (sign == 0) // if sign is negative (0 indicates sign is negative)
            // make the number negative by multiplying it by -1.
            out = -1 * out; 
        //INT_MIN = -2147483648
        //INT_MAX = 2147483647
        
        //if less than or equal to INT_MIN than return INT_MIN
        if (out <= INT_MIN)
            return INT_MIN;
        //if greater than or equal to INT_MAX than return INT_MAX
        if (out >= INT_MAX)
            return INT_MAX;
        
        //we need to cast out variable as int because we decalred it as a long int.
        return (int)out;
    }
};
