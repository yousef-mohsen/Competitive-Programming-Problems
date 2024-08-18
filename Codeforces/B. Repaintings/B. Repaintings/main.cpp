//
//  main.cpp
//  B. Repaintings
//
//  Created by y.m on 27.08.20.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    long long x, counter = 0;
    cin>>n>>m>>x;
    
    for(int i = 1; i <= n; i++)
    {
        if(i & 1)
        {
            k=1;
        }
        else
        {
            k = 2;
        }
        for(k ; k <= m; k+=2)
        {
            int  temp = min (k, m - k + 1);
            temp = min (temp, i);
            temp = min (temp, n);
            temp = min (temp, n- i + 1);
            if(temp == x)
                counter +=1;
        }
    }
    cout<<counter;
    
    return 0;
}
