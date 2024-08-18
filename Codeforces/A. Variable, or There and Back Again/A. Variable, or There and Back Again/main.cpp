 //
 //  main.cpp
 //  A. Variable, or There and Back Again
 //
 //  Created by y.m on 28.08.20.
 //
  
 #include <iostream>
 #include <vector>
 #include <set>
 using namespace std;
  
 vector <vector<int>> adj;
 vector <bool> in;
 vector <int> state;
 set<int> visited;

 int start;
  
 void dfs(int a)
 {
     if(state [a] == 2)
         in[a] = 1;
     
     visited.insert(a);
     int s = state[a];
     
     for(auto k: adj[a])
     {
         if(s == 2)
         {
             if(state[k] == 2 || state[k] == 0)
             {
                 if(visited.count(k)==0)
                     dfs(k);
             }
         }
         else if(s == 0)
         {
             if(state[k] == 0 || state[k] == 2)
             {
                 if(visited.count(k)==0)
                 dfs(k);
                 in[a] = (in[a] || in[k]);
             }
         }
         else
         {
             if((state[k] == 0 || state[k] == 2) && a == start)
             {
                 
                 if(visited.count(k) == 0)
                 dfs(k);
                 in[a] = (in[a] || in[k]);
             }
         }
     }
     
         
 }
  
 int main(int argc, const char * argv[]) {
     ios::sync_with_stdio(0); cin.tie(0);
     int n, m, a, b;
     cin>>n>>m;
     state = vector <int> (n + 1);
     adj = vector<vector<int>> (n + 1);
     in = vector <bool>(n + 1, false);
     
     for(int i = 1; i <= n; i++)
     {
         cin>>state[i];
     }
     for(int i = 1; i <= m; i++)
     {
         cin>>a>>b;
         adj[a].push_back(b);
     }
     
     for(int i = 1; i <= n; i++)
     {
         if(state[i] == 1)
         {
             if(visited.size()!=0)
                 visited.erase(visited.begin(),visited.end());
             start = i;
             dfs(i);
         }
     }
     
     
     for(int i = 1; i <= n; i++)
     {
         cout<<in[i]<<"\n";
     }
     
     
     return 0;
 }
