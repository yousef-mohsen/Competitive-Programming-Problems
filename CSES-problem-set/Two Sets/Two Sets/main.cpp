//
//  main.cpp
//  Two Sets
//
//  Created by Yousef on 17.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int begin = 0;
    int end =0;
    
    if((n*(n+1))%4 != 0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<"\n";

        if(n%2 == 0)
        {
            begin = n /4 +1;
            end = n-  n/4;
        }
    else
    {
        begin = n / 4 +1;
        end = n -n/4 -1;
    }
    cout<<n-(end-begin)-1<<"\n";
    for (int i=1; i<=n;i++)
    {
        if(i==begin)
        {
            i = end+1;
        }
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<end - begin + 1<<"\n";
    for(int i= begin; i<=end; i++)
    {
        cout<<i<<" ";
    }
    return 0;
}
