#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string ans;
  int n = src.size();
  int count = 1;
  for(int i=1;i<n;i++){
      if(src[i] == src[i-1]){
          count++;
      }
      else{
          ans = ans + src[i-1] + to_string(count);
          count = 1;
      }
  }
  ans = ans + src[n-1] + to_string(count);
  return ans;
}     
