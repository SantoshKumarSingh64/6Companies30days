class Solution {
public:
    int getMoneyAmount(int n) {
        
        /*
            In this question we have to find the minimum amount of money required to win the game given some constraints. So this problem can easily be broken into subproblems. 
            For each of the number between 1-n we will consider the case where this number is choosen by the player first and we will always consider this as a wrong choice. 
            For example when n = 10 and the player guess the 1 as the first number then cost is 1 and again he have to choose from the range of 2-10. So to generalize this

            1....... i........ n. Suppose i is any number between 1 to n. Then if player choose i as first number (which we will consider as wrong choice because 
            we want to consider the worst case to find our answer), then we will be left with two choice either our answer is in range (1..... i-1) or (i+1 ..... n). 
            So we have to consider max amoung these two cases.
        */
        vector<vector<int>> dp(n+2, vector<int>(n+2));
        for(int len = 2;len <= n; ++len){
            int l = 1, r = len;
            while(r <= n) {
                int ans = INT_MAX;
                for(int i=l; i<=r; i++){
                    ans = min(ans, i + max(dp[l][i-1], dp[i+1][r]));
                }
                dp[l][r] = ans;
                l++, r++;
            }
        }
        return dp[1][n];
    }
};
