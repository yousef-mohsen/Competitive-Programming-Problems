//
//  main.cpp
//  Collecting Numbers II
//
//  Created by Yousef on 31.01.21.
//

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
vector<int> v ;
vector<int> e ;
int n ;
int cal (int a, int start, int end)
{
    //int start = max (e[a] - 2, 1);
    int order = v[e[start]];
    int temp = 1;
    while(order <= end)
    {
        if(v[start] < order)
            temp++;
        order = v[start];
        start++;
        
    }
    return temp;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int x, ans = 0, order = 1e9, q, a, b, temp = 0;
    cin>>n>>q;
    v.resize(n + 2);
    e.resize(n + 2);
    e[0] = 0;
    e[n + 1] = n + 1;
    v[0] = 0;
    v[n + 1] = n + 1;
    
    for(int i = 1; i <= n; i++)
    {
        cin>>x;
        v[x] = i;
        e[i] = x;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(v[i] < order)
        {
            ans++;
        }
        order = v[i];
    }
    for(int i = 1; i <= q; i++)
    {
        cin>>a>>b;
        temp = 0;
        int temp2 = 0;
        if(b - a > 4)
        temp +=cal(a);
        temp += cal(b);
        /*
        int start = max (e[a] - 2, 1);
        int start2 = max (e[b] - 2, 1);
        order = v[e[start]];
        int counter  = 0;
        while(order <= n && counter < 5)
        {
            if(v[start] < order)
                temp++;
                order = v[start];
            start++;
            counter++;
        }
        
        order = v[e[start2]];
         counter  = 0;
        while(order <= n && counter < 5)
        {
            if(v[start] < order)
                temp++;
                order = v[start];
            start2++;
            counter++;
        }
         
         */
         
        swap(e[a], e[b]);
        swap(v[e[a]], v[e[b]]);
         
        temp2 += cal(a);
        temp2 += cal(b);
      /*
         start = max (e[a] - 2, 1);
        start2 = max (e[b] - 2, 1);
        order = v[e[start]];
         counter  = 0;
        while(order <= n && counter < 5)
        {
            if(v[start] < order)
                temp2++;
                order = v[start];
            start++;
            counter++;
        }
        
        order = v[e[start2]];
         counter  = 0;
        while(order <= n && counter < 5)
        {
            if(v[start2] < order)
                temp2++;
                order = v[start2];
            start2++;
            counter++;
        }
        */
        ans+= temp2-temp;
        
        
        cout<<ans<<"\n";
    }
    
    return 0;
}
