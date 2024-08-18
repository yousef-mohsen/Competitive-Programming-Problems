//
//  main.cpp
//  Minimizing Coins
//
//  Created by Yousef on 06.01.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin>>n>>x;
    vector <long long> coins;
    long long input;
    long long * value = new long long [x + 1];
    
    for (int i = 0; i < n; i++)
    {
        cin>>input;
        coins.push_back(input);
    }
    
    value [0] = 0;
    sort(coins.begin(), coins.end());
    
    for(int i = 1; i <= x; i++)
    {
        value[i] = 1000000000;
        for (auto k: coins)
        {
            if(i - k >= 0)
            {
                value [i] = min (value[i], value[i-k] + 1);
            }
            else
            {
                break;
            }
        }
    }
    
    if(value [x] == 1000000000)
    {
        cout <<-1;
    }
    else
    {
        cout<<value[x];
    }
    return 0;
}
