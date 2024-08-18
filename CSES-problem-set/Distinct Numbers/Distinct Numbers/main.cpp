//
//  main.cpp
//  Distinct Numbers
//
//  Created by Yousef on 18.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map <int, int > myMap;
    cin >> n;
    long long x;
    for(int i =0; i<n;i++)
    {
        cin>>x;
        
        if(!myMap.count(x))
        {
            myMap[x] = 1;
        }
        
    }
    cout<<myMap.size();
        
    return 0;
}
