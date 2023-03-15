// Coin Change - Minimum number of coins
class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    long long minimumNumberOfCoins(int coins[],int n,int val)
    {
        // your code here
        long long dp[val+1];
        // memset(dp,INT_MAX,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=val;i++) dp[i]= INT_MAX;
        for(int i=1;i<=val;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                   long long res= dp[i-coins[j]];
                
                if(res!=INT_MAX){
                    dp[i]= min(dp[i],res+1);
                }
                }
            }
        }
        if(dp[val]!=INT_MAX){
        return dp[val];
        }
        else return -1;
    }
};

// Coin Change - Number of ways
class Solution
{
    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    long long numberOfWays(int v[],int n,int s)
    {
       vector<vector<long long>> dp(n+1,vector<long long> (s+1,0));
       
       for(int i=0;i<=n;i++) dp[i][0]=1;
       
       for(int i=1;i<=n;i++){
           for(int j=1;j<=s;j++){
               dp[i][j]= dp[i-1][j];
               if(v[i-1]<=j){
                   dp[i][j]+= dp[i][j-v[i-1]];
               }
           }
       }
       
       return dp[n][s];
        
    }
};
