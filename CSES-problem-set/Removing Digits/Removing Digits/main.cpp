//
//  main.cpp
//  Removing Digits
//
//  Created by Yousef on 07.01.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    string s = to_string(n);
    int counter = 0;
    int max = 0;
    
    while(n)
    {
        max = s.at(0) - 48;
        for(int i =0; i <s.length();i++)
            {
                if(s.at(i) -48 > max)
                {
                    max = s.at(i) -48;
                }
            }
        n -= (int)max;
        s = to_string(n);
        counter += 1;
    }
    
   
    cout<<counter;
        
    return 0;
}
