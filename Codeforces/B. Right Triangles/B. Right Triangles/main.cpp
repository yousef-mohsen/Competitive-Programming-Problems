//
//  main.cpp
//  B. Right Triangles
//
//  Created by Yousef on 16.08.20.
//

#include <iostream>
#include <utility>
#include <vector>

using namespace std;


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin>>m>>n;
    char c;
    vector<pair<int, int>> pos;
    vector<int> row(m + 1, 0);
    vector<int> column(n + 1, 0);
    for(int i = 1; i <= m; i++)
        for(int k = 1; k<=n; k++)
        {
            cin>>c;
            if(c == '*')
            {
                pos.push_back(make_pair(i,k));
                row[i] +=1;
                column[k]+=1;
            }
        }
    long long ans = 0;
    
    for(auto p: pos)
    {
        if(p.first!=0 && p.second !=0)
            ans+= (row[p.first] - 1) * (column[p.second] - 1);
    }
    cout<<ans;
    
    
    
    
    return 0;
}
