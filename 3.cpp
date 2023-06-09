class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int a, int b, int c)
    {
        //Your code here
        // vector<int> dp(n+1,0);
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=-1;
            if((i-a)>=0) dp[i]= max(dp[i],dp[i-a]);
            if((i-b)>=0) dp[i]= max(dp[i],dp[i-b]);
            if((i-c)>=0) dp[i]= max(dp[i],dp[i-c]);
            
            if(dp[i]!=-1){
              dp[i]++;
            }
        }
        if(dp[n]==-1){
            dp[n]=0;
        }
        return dp[n];
    }
};
