class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 0)
        return 1;

        if(n == 1)
        return 1;

        // int ans = climbStairs(n-1) + climbStairs(n-2);
        //return ans

       int prev1 = 1;
       int prev2 = 0;
       int curr;

       for(int i = 1; i<= n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
       }
       return prev1;
    }
};