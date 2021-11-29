void Rasengan(){
 //full chakra 
  //CSES DP Section
  ll n, sum; cin >> n >> sum;
  vll coins(n);
  FOR(i,0,n) cin >> coins[i];
  //Task: Minimize the number of coins needed to form sum
  //      If it isn't possible, print -1
  //State: dp[i] = min coins needed to form i
  //Base case: dp[0] = 0
  //Transition: dp[i] = min(dp[i-c[0]], dp[i-c[1]]..dp[i-c[n-1]]) + 1
  vll dp(sum+1,MOD);
  dp[0] = 0;
  FOR(i,1,sum+1){
    FOR(j,0,n){
      if(i-coins[j]>=0){
        dp[i] = min(dp[i], dp[i-coins[j]]);
      }
    }
    if(dp[i]!=MOD) dp[i]++;
  }
  cout << (dp[sum]==MOD? -1 : dp[sum]) << nline;
}//no chakra
