class Solution {
public:
    
    int gcd(int a, int b)
    {
        // Base Case
        if (b == 0)
        {
            return a;
        }
        
        // Recursive Case
        return gcd(b, a%b);
    }
    
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        
        int tLength = gcd(n1, n2);
        
        int segments1 = n1 / tLength;
        int segments2 = n2 / tLength;
        
        int segmentIndex = 0;
        bool sequenceRejected = false;
        
        // If their lengths are same
        if (n1 == n2)
        {
            for (int i = 0; i < n1; i++)
            {
                if (str1[i] != str2[i])
                {
                    return "";
                }
            }
        }
        
        // Checking in the 1st string
        for (int i = tLength; i < n1; i++)
        {
            if (segmentIndex == tLength)
            {
                segmentIndex = 0;
            }
            
            if(str1[segmentIndex] != str1[i])
            {
                return "";
            }
            
            segmentIndex++;
        }

        
        segmentIndex = 0;
        
        // Checking in the 2nd string
        for (int i = tLength; i < n2; i++)
        {
            if (segmentIndex == tLength)
            {
                segmentIndex = 0;
            }
            
            if(str1[segmentIndex] != str2[i])
            {
                return "";
            }
            
            segmentIndex++;
        }
        
        string s; 
        // Printing the final answer if the strings have a valid gcd
        for (int i = 0; i < tLength; i++)
        {
            s.push_back(str1[i]);
        }
            
        return s;
    }
};
