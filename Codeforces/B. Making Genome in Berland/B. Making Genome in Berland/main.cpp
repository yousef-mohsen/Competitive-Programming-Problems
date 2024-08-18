//
//  main.cpp
//  B. Making Genome in Berland
//
//  Created by Yousef on 12.08.20.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj (27);
vector <int> child (27,0);
vector <bool> visited(27, false);
vector <bool> contain (27, false);

void dfs(int n)
{
    for (auto k:adj[n])
    {
        if(!visited[k])
        {
            visited[k] = 1;
            dfs(k);
        }
        child[n] = k;
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    int n;
    cin>>n;
    
    
    while(n--)
    {
        cin>>s;
        for(int i = 1; i < s.length(); i++)
        {
            adj[s[i-1]- 96].push_back(s[i]- 96);
            contain[s[i-1]- 96] = true;
            contain[s[i]- 96] = true;
        }
        if(s.length()== 1)
        {
            contain[s[0] - 96] = true;
        }
        
    }
    
    for(int i =1; i<=26; i++)
    {
        if(!visited[i])
            dfs(i);
    }
    
    s= "";
    for(int i =1; i<27; i++)
    {
        if(!visited[i] && contain[i])
        {
            int c =i;
            
            while(child[c] !=  0)
            {
                char m = char(c + 96);
                s += m;
                c=child[c];
            }
            char m = char(c + 96);
            s+=m;
        }
    }
    
    cout<<s;
    return 0;
}
