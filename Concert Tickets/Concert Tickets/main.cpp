//
//  main.cpp
//  Concert Tickets
//
//  Created by Yousef on 22.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, m;
    long long ticketPrice, offered;
    multiset <long long> price;
    cin>>n>>m;
    for(int i = 0; i< n; i++)
    {
        cin>>ticketPrice;
        price.insert(ticketPrice);
        
    }
    for(int i =0; i<m; i++)
    {
        cin>>offered;
        auto isFound = price.upper_bound(offered);
        
        if( isFound == price.begin() || price.size() == 0)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<*(--isFound)<<"\n";
            price.erase(price.find(*(isFound)));
        }
    }
    return 0;
}
