//
//  main.cpp
//  Line Segment Intersection
//
//  Created by Yousef on 08.03.21.
//
 
#include <iostream>
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
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll x1, x2, x3, x4, y1, y2, y3, y4, n;
    cin>>n;
    
    for(int i = 1; i <= n; i++)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    
        C p1 = {x1, y1};
        C p2 = {x2, y2};
        C p3 = {x3, y3};
        C p4 = {x4, y4};
        ll temp1 = (conj(p3 - p1) *(p3 - p2)).imag();
        ll temp2 = (conj(p4 - p1) *(p4 - p2)).imag();
        ll temp3 = (conj(p1 - p3) *(p1 - p4)).imag();
        ll temp4 = (conj(p2 - p3) *(p2 - p4)).imag();
        bool ans = false;
        
        if(temp1 == 0 || temp2 == 0 || temp3 == 0 || temp4 == 0)
        {
            if(temp1 == 0 )
                ans = cal(p3, p1, p2);
             if(temp2 == 0)
                ans |= cal(p4, p1, p2);
            if(temp3 == 0)
                ans |= cal(p1, p3, p4);
            if(temp4 == 0)
                ans |= cal(p2, p3, p4);
            
            if(!ans)
            {
                cout<<"NO"<<"\n";
            }
            else {
                cout<<"YES"<<"\n";
            }
            continue;
            
        }
        
        if((temp1 > 0 && temp2 < 0) || (temp2 > 0 && temp1 < 0))
           
        {
            if((temp3 > 0 && temp4 < 0) || (temp3 < 0 && temp4 > 0))
            {
                cout<<"YES"<<"\n";
            }
            else
            {
                cout<<"NO"<<"\n";
            }
        }
        else
        {
            cout<<"NO"<<"\n";
        }
    
    }
    return 0;
}
