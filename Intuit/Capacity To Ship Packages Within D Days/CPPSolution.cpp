class Solution {
public:
    
    bool isPossible(int mid, int n, vector<int>weights, int days){
        
        int req_d = 1;
        int sum = 0;
        
        for(int i=0;i<n;i++){
            
            if(sum+weights[i] <= mid){
                sum += weights[i];
            }
            else{
                
                if(weights[i] > mid){
                    return false;
                }
                
                sum = weights[i];
                req_d++;
            }
        }
        
        return (req_d <= days);
        
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        int low = 1;
        int high = 0;
        for(int i=0;i<n;i++){
            high += weights[i];
        }
        int res = 0;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            if(isPossible(mid,n,weights,days)){
                
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return res;
    }
};
