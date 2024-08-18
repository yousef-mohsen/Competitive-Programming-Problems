//
//  main.cpp
//  E. IT Restaurants
//
//
//
# include <iostream>
# include <vector>
# include <utility>
# include <bitset>
 
using namespace std;
 
int n;
vector<vector<int>> adj;
vector<long long> d;
vector <bool> visited;


bitset<5000> sol;
 
void dfs (int m)
{
    bitset<5000> tmp;
    d[m] = 1;
    tmp[0] = 1;
    
    for(auto l: adj[m])
        {
            if(!visited [l])
            {
                visited[l] = 1;
                dfs(l);
                d[m] += d[l];
                tmp |= (tmp << d[l]);
               
            }
        }
   
    tmp |= (tmp << (n - d[m]));
    sol|= tmp;
}
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b;
    cin>>n;
    
    adj = vector<vector<int>> (n + 2);
    d = vector<long long> (n+1);
    visited = vector <bool>(n+1, false);
    int p =n;
    while(--n)
    {
        cin >>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    n=p;
    
    visited[a] = 1;
    dfs(a);
    
    int counter = 0;
    
    for(int i = 1; i < n - 1; i++)
    {
        if(sol[i])
        {
            counter ++;
        }
    }
    cout<<counter<<"\n";
    
    for(int i = 1; i < n - 1; i++)
    {
        if(sol[i])
        {
            cout<<i<<" "<< n - i - 1<<"\n";
        }
    }

    
    
    return 0;
}
