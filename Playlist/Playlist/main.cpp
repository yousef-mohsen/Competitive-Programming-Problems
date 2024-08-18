//
//  main.cpp
//  Playlist
//
//  Created by Yousef on 22.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
# include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    
    map <long long, long long > myMap;
    int n;
    cin>>n;
    long long value;
    long long counter = 0;
    long long pos = 0;
 
    for (int i = 1; i <= n; i++)
    {
        cin>>value;
        
        if(myMap.count(value))
        {
            pos = max(pos, myMap[value]);
            
        }
        
        myMap[value] = i;
        counter = max(counter, i - pos);
        }
   
    cout<<counter;
    
    return 0;
}
