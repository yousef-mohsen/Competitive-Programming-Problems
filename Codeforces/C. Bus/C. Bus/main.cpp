//
//  main.cpp
//  C. Bus
//
//  Created by Yousef on 16.08.20.
//

#include <iostream>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

priority_queue<int,vector<int>,greater <int>> bus;
priority_queue<pi, vector<pi>, greater <pi>> station;
long long d = 0;
pi temp;

int x = 0;

void go()
{
    int k = 0;
    x = bus.top();
    
    while(bus.size() >=0)
    {
        if(bus.size()==0)
        {
            
        }
        if(bus.top()==x)
        {
            k++;
            
        }
        else
        {
            d += 1 + (k/2);
            d += x;
            x= bus.top();
            bus.pop();
            while(k--)
            {
                cout<<d<<" ";
                
            }
        }
        if(bus.size() == 1)
        {
            d+=x;
            cout<<d+k/2<<" ";
            d+= bus.top();
            bus.pop();

        }
                
            
        
    }
        
}

int main(int argc, const char * argv[]) {
    int n, m, t, x;
    cin>>n>>m;
    
    
    while(n--)
    {
        cin>>t>>x;
        station.push(make_pair(t, x));
    }
    
    while(station.size()>0)
    {
       
        while(bus.size()<m && station.size() >0)
        {
                temp = station.top();
                station.pop();
                bus.push(temp.second);
            if((station.size() == 0 ||bus.size() ==m) && temp.second>d)
                {
                    d+= temp.second - d;
                }
        }
        
        if(bus.size() == m ||station.size() == 0 )
        {
            go();
        }
    }
    
    return 0;
}
