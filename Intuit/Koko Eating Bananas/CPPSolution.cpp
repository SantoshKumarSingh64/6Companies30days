class Solution {
public:
    
    int findReqTime(int k, int n, vector<int>piles){
        
        int hrs = 0;
        for(int i=0;i<n;i++){
            if(piles[i]%k == 0){
                hrs += (piles[i]/k);
            }
            else{
                hrs += (piles[i]/k+1);
            }
        }
        //cout<<k<<"  "<<hrs<<endl;
        return hrs;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxi = INT_MIN;
        int mini = 1;
        int n = piles.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,piles[i]);
        }
        
        
        while(mini <= maxi){
            
            int mid = mini + (maxi-mini)/2;
            int req_hrs = findReqTime(mid,n,piles);
            if(req_hrs <= h){
                maxi = mid-1;
            }
            else{
                mini = mid+1;
            }
        }
        return mini;
    }
};
