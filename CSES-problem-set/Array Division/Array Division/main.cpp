//
//  main.cpp
//  Array Division
//
//  Created by Yousef on 04.05.20.
//

#include <iostream>
#include <vector>
using namespace std;

vector <long long > v;

bool cal (long long t, long long k)
{
    long long sum = 0;
    long long count = 0;
    
    for(auto e:v)
    {
      if(e > t)
      {
          return false;
      }
      else{
          sum += e;
            if(sum>t)
            {
                count++;
                sum = e;
            }
      }
        
    }
    count ++;
    return (count<=k);
}

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    long long end = 0, begin = 1e9+1, x, mid;
    cin>>n>>k;
    
    
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        end+= x;
        begin = min(begin, x);
        v.push_back(x);
    }
    
    while(begin <= end)
    {
        mid = (begin + end)/2;
        if(cal(mid,k))
        {
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
        
    }
    cout<<begin;
    
    
    return 0;
}
