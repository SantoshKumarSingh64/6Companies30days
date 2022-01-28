class Solution {
public:
    // comparison logic to build a min-heap of strings
    struct comparator {
        bool operator()(string &s1,string &s2) {
            // if length of first string is greater that means first string denotes greater number hence it should come next to lesser string. Hence swapping should be done
            if(s1.length()>s2.length()) {
                return true;
            }
            
            // if length of first string is lesser that means first string denotes smaller number hence ordering is fine. No need to swap. 
            else if(s1.length()<s2.length()) {
                return false;
            }
            
            // if lengths are equal then we have to iterate them
            else {
                for(int i=0;i<s1.length();i++) {
                    // if at a particular index digits vary then decide which one is greater or lesser and return 
                    if(s1[i]-'0'>s2[i]-'0') {
                        return true;
                    }
                    else if(s1[i]-'0'<s2[i]-'0') {
                        return false;
                    }
                }
                return false;
            }
        }
    };
  
    string kthLargestNumber(vector<string>& nums, int k) {
        // declare a min-heap of strings
        priority_queue<string,vector<string>,comparator>q;
        
        // iterate the vector 
        for(auto it:nums) {
            q.push(it);
            
            // whenever the size becomes greater than k remove the smallest string available in the heap.
            if(q.size()>k) {
                q.pop();
            }
        }
        
        // k'th smallest string will be the topmost string of the heap since it's a min-heap
        return q.top();
    }
};
