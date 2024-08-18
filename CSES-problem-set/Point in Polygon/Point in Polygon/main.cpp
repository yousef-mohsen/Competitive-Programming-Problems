//
//  main.cpp
//  Point in Polygon
//
//  Created by Yousef on 08.03.21.
//

#include <iostream>
#include <vector>
#include <utility>
#include <complex>

using namespace std;
typedef long long ll;
typedef complex<ll> C;

bool cal (C p1, C p2, C p3)
{
    ll x1 = p1.real();
    ll y1 = p1.imag();
    ll x2= p2.real();
    ll y2= p2.imag();
    ll x3= p3.real();
    ll y3= p3.imag();
    
    return x1 >= min(x2, x3) && x1<= max(x2, x3) && y1 >= min(y2, y3) && y1<= max(y2, y3);
}

ll intersect (C p1, C p2, C p3, C p4)
{
    ll temp1 = (conj(p3 - p1) *(p3 - p2)).imag();
    ll temp2 = (conj(p4 - p1) *(p4 - p2)).imag();
    ll temp3 = (conj(p1 - p3) *(p1 - p4)).imag();
    ll temp4 = (conj(p2 - p3) *(p2 - p4)).imag();
    ll counter = -1;
    bool ans = false;
    
    if(temp3 == 0)
    {
        ans = cal(p1, p3, p4);
        if(ans)
        {
            counter = 0;
        }
            return counter;
    }

    
    if((temp1 > 0 && temp2 <= 0) || (temp2 > 0 && temp1 <= 0))
       {
        if((temp3 > 0 && temp4 <= 0) || (temp3 < 0 && temp4 >= 0))
        {
            counter = 1;
        }
       
    }
    return counter;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, x1, y1, x2, y2, mo  = 1e9 + 1, counter, x3, x4, y3, y4;
    cin>>n>>m;
    vector<pair<ll, ll>> v (n);
    
    for(int i = 0; i < n; i++)
    {
        cin>>x1>>y1;
        v[i] = {x1,y1};
    }
    for(int i = 1; i <= m; i++)
    {
        cin>>x1>>y1;
        x2 = mo;
        y2 =  mo;
        C p1 = {x1, y1};
        C p2 = {x2, y2};
        counter = 0;
        
        for(int i = 0; i < n ; i++)
        {
            C p3, p4;
            
            if(i == n - 1)
            {
                 p3 = {v[i].first, v[i].second};
                 p4 = {v[0].first, v[0].second};
            }
            else
            {
                 p3 = {v[i].first, v[i].second};
                 p4 = {v[i + 1].first, v[i + 1].second};
            }
            
            ll ans = intersect (p1, p2, p3,p4);
            if(ans == 0)
            {
                cout<<"BOUNDARY"<<"\n";
                counter = -4;
                break;
            }
            else if(ans == 1)
                counter ++;
        }
        if(counter != -4)
        {
            if(counter & 1 )
            cout <<"INSIDE"<<"\n";
            else
            cout<<"OUTSIDE"<<"\n";
        }
    }
    
    return 0;
}
