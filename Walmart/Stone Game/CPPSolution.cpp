class Solution {
public:
    
    int helper(vector<int>&v,int start,int end,vector<vector<int>>&dp)
    {
        
        if(start > end)
        {
            return 0;
        }
        
        if(start == end)
        {
            return dp[start][end] = v[start];
        }
        
        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }
        
        int first = v[start] + min(helper(v,start+1,end-1,dp),helper(v,start+2,end,dp));
        int second = v[end] + min(helper(v,start+1,end-1,dp),helper(v,start,end-2,dp));
        
        return dp[start][end] = max(first,second);
    }
    
    
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        int sum  = 0;
        for(int i=0;i<n;i++){
            sum += piles[i];
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int Alice_sum = helper(piles,0,n-1,dp);
        int Bob_sum = sum - Alice_sum;
        
        return (Alice_sum > Bob_sum);        
    }
};
