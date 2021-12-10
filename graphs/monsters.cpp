  //Monsters -> BFS on a grid
  //Approach: 
  //- We start a multisource BFS from all the monsters
  //to find the min seconds any of the monster needs 
  //to reach the boundary and store it in monster_dist array

  //-We also start a BFS from the start i.e 'A' which gives
  //the min seconds needed to reach a boundary

  //If for any valid boundary, the timeofA < timeofMonster
  //then we have a solution. else print "NO"

const int N = 1e3+1;
int n, m;
vector<pair<int,int>> movements = {
  {0,1},{0,-1},{1,0},{-1,0}
};
vector<string> grid;
vector<vi> monster_dist(N, vi(N,MOD)), src_dist(N, vi(N,MOD)), dist(N, vi(N,MOD));
vector<vector<pair<int,int>>> parent(N, vector<pair<int,int>>(N, {-1,-1})), srcparent(N, vector<pair<int,int>>(N, {-1,-1}));
bool isValid(int v_x, int v_y){
  if(v_x<0 || v_x>=n || v_y<0 || v_y>=m) return false;
  if(grid[v_x][v_y]=='#') return false;
  return true;
}
void bfs(queue<pair<int,int>> q){
  while(!q.empty()){
    pair<int,int> cur = q.front();
    int u_x = cur.ff, u_y = cur.ss;
    q.pop();
    for(auto movement : movements){
      int v_x = movement.ff + u_x;
      int v_y = movement.ss + u_y;
      if(!isValid(v_x, v_y)) continue;
      if(dist[v_x][v_y]!=MOD) continue;
      q.push({v_x,v_y});
      dist[v_x][v_y] = 1 + dist[u_x][u_y];
      parent[v_x][v_y] = {u_x,u_y};
    }
  }
}
void Rasengan(){
 //full chakra | Chunking, DP
  cin >> n >> m;
  FOR(i,0,n){
    string s; cin >> s;
    grid.pb(s);
  }
  //Let's first do a regular BFS from the source
  pair<int,int> src;
  FOR(i,0,n){
    FOR(j,0,m){
      if(grid[i][j]=='A'){
        src.ff = i, src.ss = j; 
        dist[src.ff][src.ss] = 0;
        break;
      }
    }
  }
  queue<pair<int,int>> q;
  q.push(src);
  bfs(q);
  srcparent = parent;
  q.pop();
  src_dist = dist; 
  dist = monster_dist;
  FOR(i,0,n){
    FOR(j,0,m){
      if(grid[i][j]=='M'){
        q.push({i,j});
        dist[i][j] = 0;
      }
    }
  }
  bfs(q);
  monster_dist = dist;
  bool found = false;
  pair<int, int> ans;
  //upper row
  FOR(i,0,m){
    if((grid[0][i]=='.' || grid[0][i]=='A')&& src_dist[0][i] < monster_dist[0][i]){
      found = true;
      ans.ff = 0, ans.ss = i;
      break;
    }
    if((grid[n-1][i]=='.' || grid[n-1][i]=='A')&& src_dist[n-1][i] < monster_dist[n-1][i]){
      found = true;
      ans.ff = n-1, ans.ss = i;
      break;
    }
  }
  FOR(i,0,n){
    if((grid[i][0]=='.' || grid[i][0]=='A' )&& src_dist[i][0] < monster_dist[i][0]){
      found = true;
      ans.ff = i, ans.ss = 0;
      break;
    }
    if((grid[i][m-1]=='.' || grid[i][m-1]=='A')&& src_dist[i][m-1] < monster_dist[i][m-1]){
      found = true;
      ans.ff = i, ans.ss = m-1;
      break;
    }
  }
  if(!found){
    cout << "NO" << nline; return;
  }
  cout << "YES" << nline;
  cout << src_dist[ans.ff][ans.ss] << nline;
  string final = "";
  auto temp = ans;
  pair<int,int> cmp = {-1,-1};
  //return;
  while(srcparent[temp.ff][temp.ss]!=cmp){
  debug(srcparent[temp.ff][temp.ss])
    pair<int,int> v = temp;
    pair<int,int> u = srcparent[temp.ff][temp.ss];
    if(u.ff == v.ff && v.ss > u.ss){
      final+='R';
    }
    else if(u.ff == v.ff && v.ss < u.ss){
      final+='L';
    }
    else if(v.ss == u.ss && u.ff < v.ff){
      final+='D';
    }
    else{
      final+='U';
    }
    temp = srcparent[temp.ff][temp.ss];
  }
  reverse(all(final));
  cout << final << nline;
}//no chakra
