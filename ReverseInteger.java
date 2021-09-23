class Solution {
public:
    int reverse(int x) {
        // lets say we have 1234, we want 4321.
        
        int results = 0;
        int prev = 0;
            
            while (x != 0) {
                int cur = x % 10;//first number will be 4, then 3, 2, 1
                x /= 10; // First number will be 123, then 23, then 4.
                
                //now we need results to be results * 10 + cur
                //for example, results = 0 * 10 + 4 initially to get the first
                //reverse number of 4.
                results = results * 10 + cur; 
                if ((results - cur) / 10 != prev) return 0;
                    prev = results;
            }
        return results;   
    }
};
