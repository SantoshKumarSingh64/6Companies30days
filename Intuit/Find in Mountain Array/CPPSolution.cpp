/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int low = 0;
        map<int,int>m;
        int n = mountainArr.length();
        int high = n-1;
        
        int mountain_index = -1;
        while(low <= high){
            
            
            int mid = low + (high-low)/2;
            if(mid == 0){
                mountain_index = 1;
                break;
            }
            if(mid == n-1){
                mountain_index = n-2;
                break;
            }
            //cout<<low<<"  "<<mid<<"  "<<high<<endl;
            if(m.find(mid) == m.end())
                m[mid] = mountainArr.get(mid);
            if(m.find(mid-1) == m.end())
                m[mid-1] = mountainArr.get(mid-1);
            if(m.find(mid+1) == m.end())
                m[mid+1] = mountainArr.get(mid+1);
            
            if(m[mid] > m[mid-1] && m[mid] > m[mid+1]){
                mountain_index = mid;
                break;
            }
            
            if(m[mid] < m[mid+1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        low = 0;
        high = mountain_index;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            if(m.find(mid) == m.end())
                m[mid] = mountainArr.get(mid);
            
            if(m[mid] == target){
                return mid;
            }
            if(m[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        low = mountain_index+1;
        high = n-1;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            if(m.find(mid) == m.end())
                m[mid] = mountainArr.get(mid);
            
             if(m[mid] == target){
                return mid;
            }
            if(m[mid] < target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return -1;
    }
};
