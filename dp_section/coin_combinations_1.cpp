void Rasengan(){
 //full chakra | Chunking, DP   for coin in coins:
  //CSES DP Section
  //Task: Number of ways to form sum using the coins
  ll n, sum; cin >> n >> sum;
  vll coins(n); 
  FOR(i,0,n) cin >> coins[i];
  vll dp(sum+1,0);
  dp[0] = 1;
  FOR(i,1,sum+1){
    FOR(j,0,n){
      if(i-coins[j]>=0)
        dp[i] = (dp[i-coins[j]] + dp[i])%MOD;
    }
  }
  cout << dp[sum] << nline;
}//no chakra
