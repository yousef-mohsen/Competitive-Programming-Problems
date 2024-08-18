//
//  main.cpp
//  Building Roads
//
//  Created by Yousef on 09.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//
# include <iostream>
# include <vector>
using namespace std;
 
int * link;
int * size;
vector <pair<int, int>> paths;
 
int find (int x)
{
    if(x == link[x])
        return x;
    return (link[x] = find(link[x]));
}
bool same (int a, int b)
{
    return (find(a) == find(b));
}
 
void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a != b){
    if(size[a] < size[b])
    {
        size[b] += size[a];
        link[a] = b;
    }
    else
    {
        size[a] += size[b];
        link [b] = a;
    }
    }
}
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin>>n>>m;
    
    link = new int [n + 1];
    size = new int [n + 1];
    for(int i = 1; i <= n; i++)
    {
        link[i] = i;
        size[i] = 1;
    }
    
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        unite(a,b);
    }
    
    for(int i = 2; i <= n; i++)
    {
        
        if(!same(1, i))
        {
            unite(1,i);
            int k = find (1);
            if(k == 1)
            {
                paths.push_back({k,i});
            }
            else
            {
              paths.push_back({1,i});
            }
            
        }
    }
    
    
    
    cout<<paths.size()<<"\n";
    
    for(int i = 0; i < paths.size(); i++)
    {
        cout<<paths[i].first<<" "<<paths[i].second<<"\n";
    }
    
    
    return 0;
}
