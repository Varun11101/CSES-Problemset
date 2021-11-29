void Rasengan(){
 //full chakra | Chunking, DP
  //CSES DP Section
  //Task: Find the number of ways to form n using
  //any number of throws
  //State: dp[i] = the number of ways to form i 
  //Base case: dp[0] = 1
  //Transition: dp[i] = dp[i-1] + dp[i-2] + dp[i-3] .. + dp[i-6]
  ll n; cin >> n;
  vll dp(n+1);
  dp[0] = 1;
  FOR(i,1,n+1){
    FOR(j,1,7){
      if(i-j>=0)
        dp[i] += dp[i-j];
      if(dp[i]>MOD) dp[i]-=MOD;
    }
  }
  cout << dp[n] <<nline;
}//no chakra
