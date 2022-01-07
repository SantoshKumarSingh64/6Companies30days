class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ret = 0;
      int n = A.size();
      int j;
      for(int i = 0; i < n; i = j + 1){
         j = i;
         bool down = false;
         bool up = false;
         while(j + 1 < n && A[j + 1] > A[j]) {
            up = true;
            j++;
         }
         while(up && j + 1 < n && A[j + 1] < A[j]){
            down = true;
            j++;
         }
         if(up && down){
            ret = max(j - i + 1, ret);
            j--;
         }
      }
      return ret;
    }
};
