//
//  main.cpp
//  Square Dance
//
//  Created by Yousef on 03.04.21.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long  ll;
vector<pair<ll, ll>> eliminate;
vector<pair<ll,ll>> sug;

struct player
{
    player * north = NULL;
    player * south = NULL;
    player * east = NULL;
    player * west = NULL;
    ll value = 0;
    ll r = 0;
    ll c = 0;
};
vector<vector<player *>> v;

ll eli ()
{
    vector<pair<ll,ll>> temp;
    for(auto a: sug)
    {
     
        float m = 0, count = 0;
        if(v[a.first][a.second] == NULL)
            continue;
       if(v[a.first][a.second]->east != NULL)
       {
           count ++;
           m += v[a.first][a.second]->east->value;
       }
        if(v[a.first][a.second]->north != NULL)
        {
            count ++;
            m += v[a.first][a.second]->north->value;
        }
        if(v[a.first][a.second]->south != NULL)
        {
            count ++;
            m += v[a.first][a.second]->south->value;
        }
        if(v[a.first][a.second]->west != NULL)
        {
            count ++;
            m += v[a.first][a.second]->west->value;
        }
        if(count!=0)
        m /= count;
        if(v[a.first][a.second]->value < m)
        {
            temp.push_back({a.first,a.second});
        }
    }
        ll sum  = 0;
        sug = vector<pair<ll,ll>>(0);
        for(auto a: temp)
        {
            if(v[a.first][a.second] == NULL)
                continue;
            if(v[a.first][a.second]->west != NULL)
            {
                v[a.first][a.second]->west->east = v[a.first][a.second]->east;
                
                
                sug.push_back({v[a.first][a.second]->west->r,v[a.first][a.second]->west->c});
            }
            
            if(v[a.first][a.second]->east != NULL)
            {
                v[a.first][a.second]->east->west = v[a.first][a.second]->west;
                
                sug.push_back({v[a.first][a.second]->east->r,v[a.first][a.second]->east->c});

            }

            
            if(v[a.first][a.second]->north != NULL)
            {
                v[a.first][a.second]->north->south = v[a.first][a.second]->south;
                
                sug.push_back({v[a.first][a.second]->north->r,v[a.first][a.second]->north->c});
                
            }
            
            if(v[a.first][a.second]->south != NULL)
            {
                v[a.first][a.second]->south->north = v[a.first][a.second]->north;
                
                sug.push_back({v[a.first][a.second]->south->r,v[a.first][a.second]->south->c});
                
            }
            sum+= v[a.first][a.second]->value;
            delete v[a.first][a.second];
            v[a.first][a.second] = NULL;
        }
    
    
    return sum;
    
    
}

int main(int argc, const char * argv[]) {
    ll t, n, r, c, sum, e, ans;
    cin>>t;
    for(int i = 1; i <= t; i ++)
    {
        sum = 0, ans = 0;
        cin>>r>>c;
        v = vector<vector<player *>> (r + 1,vector<player *  >(c + 1, NULL));
        eliminate = vector<pair<ll, ll>>();
         
        
        for(int k = 1; k <= r; k++)
            for(int j = 1; j <= c; j++)
        {
            cin>>e;
            sum += e;
            
            v[k][j] = new player;
            v[k][j]->value = e;
            v[k][j]->r = k;
            v[k][j]->c = j;
            
            if(k == 1 && j == 1)
            {
                
                continue;
            }
            if(k == 1)
            {
                v[k][j]->west = v[k][j - 1];
                v[k][j - 1]->east = v[k][j];
            }
            else if(j == 1)
            {
                v[k][j]->north = v[k - 1][j];
                v[k - 1][j]->south = v[k][j];
            }
            else
            {
                v[k][j]->west = v[k][j - 1];
                v[k][j - 1]->east = v[k][j];
                v[k][j]->north = v[k - 1][j];
                v[k - 1][j]->south = v[k][j];
                
                
            }
           
        }
     
        
        ans = sum;
        for(int k = 1; k <= r; k++)
            for(int j = 1; j <= c; j++)
        {
            float m = 0, count = 0;
           if(v[k][j]->east != NULL)
           {
               count ++;
               m += v[k][j]->east->value;
           }
            if(v[k][j]->north != NULL)
            {
                count ++;
                m += v[k][j]->north->value;
            }
            if(v[k][j]->south != NULL)
            {
                count ++;
                m += v[k][j]->south->value;
            }
            if(v[k][j]->west != NULL)
            {
                count ++;
                m += v[k][j]->west->value;
            }
            if(count!=0)
            m /= count;
            if(v[k][j]->value < m)
            {
                sug.push_back({k,j});
            }
            
        }
        ans = sum;
        while(sug.size()!= 0)
        {
            ll temp = eli();
            if(temp == 0)
                break;
            sum -= temp;
            ans += sum;
        }
        cout<<"Case #"<<i<<": "<<ans<<"\n";

        
    }

    return 0;
}
