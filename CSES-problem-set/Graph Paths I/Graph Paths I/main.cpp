//
//  main.cpp
//  Graph Paths I
//
//  Created by Yousef on 08.10.20.
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
            c[i][k] = 0;
            for(int q = 1; q < a[0].size(); q++)
            {
                c[i][k] += a[i][q] * b[q][k];
                if(c[i][k] >= mo)
                    c[i][k] %= mo;
            }
        }
}
 
 
void modpow (long long power, vector<vector<ll>>&x, vector<vector<ll>>&f, vector<vector<ll>>&g)
{
    if(power <= 1)
        return;
    modpow(power / 2, x, f, g);
    mul(f, f, g);
    
    if((power & 1) == 1)
    {
        mul(g, x, f);
        return;
    }
    //(f).swap(g);
    return;
}
 
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, m, k, a, b;
    cin>>n>>m>>k;
    vector<vector<ll>> x(n + 1, vector<ll> (n + 1, 0));
    vector<vector<ll>> f(n + 1, vector<ll> (n + 1, 0));
    vector<vector<ll>> g(n + 1, vector<ll> (n + 1));
    for(int i = 1; i <= m; i++)
    {
        cin>>a>>b;
        x[a][b] += 1;
        f[a][b] += 1;
        g[a][b] += 1;
    }
    modpow(k, x, f, g);
    cout<<f[1][n];
    
    return 0;
}
