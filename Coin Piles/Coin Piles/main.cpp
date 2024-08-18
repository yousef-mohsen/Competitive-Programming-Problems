//
//  main.cpp
//  Coin Piles
//
//  Created by Yousef on 18.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;

int main(int argc, const char * argv[]) {
    long long t, a, b, x, y = 0;
    cin>>t;
    string  * arr = new string[t];
    for(int i=0; i<t; i++)
    {
        cin>>a;
        cin>>b;
        if((a+b)%3 != 0)
        {
        arr[i]= "NO";
        }
        else
        {
            y = (((a+b)/3)*2)-a;
            x =(a+b)/3 -y;
            if(x>=0 && y>=0)
            arr[i]= "YES";
            else
            {
                arr[i]="NO";
            }
        }
    }
    for(int i = 0; i<t; i++)
    {
        cout<<arr[i]<<"\n";
    }
    return 0;
}
