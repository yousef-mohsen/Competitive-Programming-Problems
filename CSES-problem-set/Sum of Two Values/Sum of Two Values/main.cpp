//
//  main.cpp
//  Sum of Two Values
//
//  Created by Yousef on 22.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    long long n, pos_1, pos_2;
    long long x, a, value;
    cin>>n>>x;
    
    multimap <long long, long long > myMap;
   
    for (long long i = 1; i<=n; i++)
    {
        cin>>a;
        myMap.insert(pair <long long, long long> (a,i));

    }
      for ( auto it = myMap.begin(); it != myMap.end(); ++it )
    {
        value = it->first;
        if(value >= x)
            continue;
        
        pos_1 = it->second;
        
        if(myMap.count(x - value))
            
        {
            pos_2 = (myMap.find(x-value))->second;
            
            if(pos_1 == pos_2)
                {
                    if(++it != myMap.end())
                    {
                        if(it->first == value)
                        pos_2 = it->second;
                    }
                    --it;
                }
            
            if((pos_1 != pos_2))
            {
            cout<<pos_1<<" "<<pos_2;
            return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";

    return 0;
}
