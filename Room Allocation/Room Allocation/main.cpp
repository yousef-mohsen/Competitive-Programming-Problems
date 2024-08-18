//
//  main.cpp
//  Room Allocation
//
//  Created by Yousef on 24.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
# include <tuple>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    long long a,b;
    vector < tuple<long long, char, long long > > v;
    queue <pair<long long, long long> > q;
    long long * arr = new long long [n+1];
    
    for(int i =1; i<=n; i++)
    {
        cin>>a>>b;
        v.push_back(make_tuple (a, 'a', i));
        v.push_back(make_tuple (b, 'd', i));
    }
    
    sort(v.begin(), v.end());
    long long roomNumber = 0;
    
    for(auto i :v)
    {
        if( get<1>(i) == 'a')
        {
            if (q.size() == 0 || q.front().second == get<0>(i) )
            {
                roomNumber ++;
                arr[get<2>(i)] = roomNumber;
            }
            else{
                arr[get<2>(i)] = q.front().first;
                q.pop();
            }
        }
        else
        {
            q.push(make_pair(arr[get<2>(i)], get<0>(i)));
        }
    }
    cout<<roomNumber<<"\n";
    
    for(int i = 1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
