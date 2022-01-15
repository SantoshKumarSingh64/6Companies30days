#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int top = 0;
        int down = r-1;
        int left = 0;
        int right = c-1;
        
        vector<int>ans;
        
        int cs = 0;
        while(left <= right && top <= down){
            
            if(cs == 0){
                //cout<<"Top Left to Top Right"<<"->";
                for(int i=left;i<=right;i++){
                    //cout<<matrix[top][i]<<",";
                    ans.push_back(matrix[top][i]);
                }       
                top++;
                //cout<<endl;
            }
            else if(cs == 1){
                //cout<<"Right Top to Right Bottom->";
                for(int i=top;i<=down;i++){
                    //cout<<matrix[i][right]<<",";
                    ans.push_back(matrix[i][right]);
                }
                right--;
                //cout<<endl;
            }
            else if(cs == 2){
                //cout<<"Down Right to Down Left->";
                for(int i=right;i>=left;i--){
                    //cout<<matrix[down][i]<<",";
                    ans.push_back(matrix[down][i]);
                }
                //cout<<endl;
                down--;
            }
            else{
                //cout<<"Left Down to Left Top->";
                for(int i=down;i>=top;i--){
                    //cout<<matrix[left][i]<<",";
                    ans.push_back(matrix[i][left]);
                }
                //cout<<endl;
                left++;
            }
            
            cs = (cs+1)%4;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
