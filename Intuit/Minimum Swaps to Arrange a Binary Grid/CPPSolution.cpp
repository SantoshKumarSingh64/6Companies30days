class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<int>dp(n);
        
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j] == 1){
                    break;
                }
                count++;
            }
            dp[i] = count;
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            
            int req_trailing_zero = n-i-1;
            if(dp[i] >= req_trailing_zero){
                continue;
            }
            int temp = dp[i];
            int j = i+1;
            for(;j<n;j++){
                int temp2 = dp[j];
                dp[j] = temp;
                temp  = temp2;
                
                if(temp >= req_trailing_zero){
                    break;
                }
            }
            if(j == n){
                return -1;
            }
            ans += (j-i);
            dp[i] = temp;
        }
        return ans;
    }
};
