//
//  main.cpp
//  Subarray Sums I
//
//  Created by Yousef on 24.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    long long x, sum = 0, value, counter = 0;
    cin>>n>>x;
    
    queue <long long > q;
    
    
    for(int i = 0; i< n; i++)
    {
        cin>>value;
        sum += value;
        if(sum == x)
        {
            counter ++;
            q.push(value);
            sum -= q.front();
            q.pop();
            
        }
        
        else if(sum > x)
        {
            q.push(value);
            while(sum > x)
            {
                sum -= q.front();
                q.pop();
            }
            if(sum == x)
                counter ++;
            continue;
        }
        else
        {
            q.push(value);
        }
        
    }
    cout<<counter;
    return 0;
}
