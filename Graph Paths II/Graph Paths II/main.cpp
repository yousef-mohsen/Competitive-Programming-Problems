//
//  main.cpp
//  Graph Paths II
//
//  Created by Yousef on 09.10.20.
//

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll mo = 1e9 + 7;

 
void mul(vector<vector<ll>> &a, vector<vector<ll>> &b, vector<vector<ll>> &c)
{
    int l = a.size(), r = b[0].size();
        
    for(int i = 1; i < l; i++)
        for(int k = 1; k < r; k++)
        {
            long long temp = (2e18);
            for(int q = 1; q < a[0].size(); q++)
            {
                temp = min(temp,a[i][q] + b[q][k]);
                
            }
            if(temp >2e18)
                temp = 2e18;
            c[i][k] = temp;
        }
}
 
 void modpow (long long power, vector<vector<ll>>&x, vector<vector<ll>>&f, vector<vector<ll>>&g)
 {
     if(power <= 1)
         return;
     modpow(power / 2, x, g, f);
     mul(f, f, g);
     
     if((power & 1) == 1)
     {
         mul(g, x, f);
         f.swap(g);
         return;
     }
     return;
 }
 
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    long long n, m, k, a, b, c;
    cin>>n>>m>>k;
    vector<vector<ll>> x(n + 1, vector<ll> (n + 1, 2e18));
    vector<vector<ll>> f(n + 1, vector<ll> (n + 1, 2e18));
    vector<vector<ll>> g(n + 1, vector<ll> (n + 1, 2e18));
    for(int i = 1; i <= m; i++)
    {
        cin>>a>>b>>c;
        x[a][b] = min(x[a][b],c);
        f[a][b] = min(f[a][b],c);
        g[a][b] = min(g[a][b],c);
    }
    modpow(k, x, f, g);
    if(g[1][n] >= 2e18)
        cout<<-1;
    else
    cout<<g[1][n];
   
 
    return 0;
}
