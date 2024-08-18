//
//  main.cpp
//  D. Physical Education
//
//  Created by Yousef on 24.07.20.
//

#include <iostream>
#include <queue>

using namespace std;
int main(int argc, const char * argv[]) {
    
    long long  n, a, i, p, temp;
    cin>>n;
    queue<int> q;
    
    long long  * arr = new long long  [n + 1];
    long long  * arr_b = new long long  [n + 1];
    
    for (int i = 1; i <= n; i ++)
    {
        cin>>a;
        arr[i] =a;
    }
    
    
    for (int i = 1; i <= n; i ++)
    {
        cin>>a;
        arr_b[i] = a;
    }
    
    i = 1;
    while(i<=n)
    {
        if(arr[i] != arr_b[i])
        {
            p = i + 1;
            while(arr[i] != arr_b[p])
            {
                p++;
            }
            while(p != i)
            {
            q.push(p);
            q.push(p - 1);
            temp = arr_b[p];
            arr_b[p] = arr_b[p - 1];
            arr_b[p - 1] = temp;
            p--;
            }
        }
        i++;
    }
    cout<<q.size()/2<<"\n";
    
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        
        temp = q.front();
        q.pop();
        if(p < temp)
        {
            cout<<p<<" "<<temp<<"\n";
        }
        else
        {
            cout<<temp<<" "<<p<<"\n";
        }
        
    }
        
    return 0;
}
