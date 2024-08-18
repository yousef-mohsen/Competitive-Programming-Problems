//
//  main.cpp
//  B. Traveling Around the Golden Ring of Berland
//
//  Created by Yousef on 24.07.20.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    long long max = -1, a, n, pos;
    
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a;
        if(a>=max)
        {
            pos = i;
            max = a;
        }
    }
    cout << (n* (max-1)) +pos;
    
    
    return 0;
}
