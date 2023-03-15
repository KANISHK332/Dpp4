//0-1 knapsack
 public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1,vector<int> (w+1,0));
       
       for(int i=1;i<=n;i++){
           for(int j=1;j<=w;j++){
               if(wt[i-1]>j){
                   dp[i][j]= dp[i-1][j];
               }
               else dp[i][j]= max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
           }
       }
       return dp[n][w];
       
    //LCS
    class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    //   int memo[1001][1001];
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
          vector<vector<int>> memo(x+1,vector<int>(y+1,0));
          for(int i=1;i<=x;i++){
              for(int j=1;j<=y;j++){
                  if(s1[i-1]==s2[j-1]){
                      memo[i][j]= 1+memo[i-1][j-1];
                  }
                  else{
                      memo[i][j]= max(memo[i-1][j],memo[i][j-1]);
                  }
              }
          }
          return memo[x][y];
    }class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    //   int memo[1001][1001];
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
          vector<vector<int>> memo(x+1,vector<int>(y+1,0));
          for(int i=1;i<=x;i++){
              for(int j=1;j<=y;j++){
                  if(s1[i-1]==s2[j-1]){
                      memo[i][j]= 1+memo[i-1][j-1];
                  }
                  else{
                      memo[i][j]= max(memo[i-1][j],memo[i][j-1]);
                  }
              }
          }
          return memo[x][y];
    }
    
    //MCM
    class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i=0;i<n-1;i++) dp[i][i+1]=0;
        
        for(int gp=2;gp<n;gp++){
            for(int i=0;i+gp<n;i++){
                int j= i+gp;
                dp[i][j]= INT_MAX;
                for(int k=i+1;k<j;k++){
                    dp[i][j]= min(dp[i][j],dp[i][k]+dp[k][j]+ arr[i]*arr[k]*arr[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
