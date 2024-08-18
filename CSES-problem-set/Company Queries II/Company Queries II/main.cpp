//
//  main.cpp
//  Company Queries II
//
//  Created by Yousef on 26.09.20.
//
 
#include <iostream>
#include <vector>
using namespace std;
int answer;
int pos = 0;
 
vector<vector<int>> v;
vector<int> level;

int cal (int x, int k){
    
for(int z = 18; z >= 0; z--)
    {
        if(k & (1<<z))
        {
            x = v[z + 1][x];
            if(x== 0)
            {
                return -1;
            }
            
        }
    }
        return x;
}
 
bool cal2 (int x, int y, int k){
    
for(int z = 18; z >= 0; z--)
    {
        if(k & (1<<z))
        {
            x = v[z + 1][x];
            y = v[z + 1][y];
            if(x == 0)
            {
                return false;
            }
            if(x == y)
            {
                answer = x;
                pos = pos - level[x];
                return true;
            }
        }
    }
        answer = x;
        return x==y;
}
 
 
 
 
 
int main(int argc, const char * argv[]) {
    int n, q, t, c = 1 ,tt = 0, a, b;
    cin>>n>>q;
    t = n;
       
    while(t)
    {
        if(t & 1)
            tt = c;
        c++;
        t = t>>1;
    }
    level = vector<int>  (n + 1);
    level[1] = 0;
    
    v  = vector<vector<int>> (tt + 1, vector<int>(n + 1));
    v[1][1] = 0;
    
    for(int i = 2; i <= n; i++)
    {
        cin>>v[1][i];
        level[i] = level[v[1][i]] + 1;
    }
       
    for(int i = 2; i <= tt; i++)
    {
        for(int k = 1; k <=n ; k++)
            v[i][k] = v[i - 1][v[i - 1][k]];
    }
       
    for (int i = 1; i <= q; i++)
    {
        cin>>a>>b;
        if(a == 1|| b==1)
        {
            cout<<"1"<<"\n";
        }
        else
        {
            if(level[a] > level[b])
                swap(a, b);
            b = cal (b, level[b] - level [a]);
            if(b==a)
            {
                cout<<a<<"\n";
                continue;
            }
            int end = level[b];
            int begin = 0;
            int mid;
            int temp = 1e8;
            int ans ;
            while(begin <= end)
                {
                    mid = (begin + end) /2;
                    pos = level[b];
                    if(cal2(a, b, mid))
                    {
                        if(pos < temp)
                        {
                            temp =  pos;
                            ans = answer;
                        }
                        end = pos - 1;
                    }
                    else
                    {
                       begin = mid + 1;
                    }
                   
                }
                cout<<ans<<"\n";
        }
    }
 
    return 0;
}
