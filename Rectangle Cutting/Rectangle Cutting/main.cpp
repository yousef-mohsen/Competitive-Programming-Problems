//
//  main.cpp
//  Rectangle Cutting
//
//  Created by Yousef on 03.05.20.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> v;
int a, b;

long long cal (int c, int d)
{
    if(c==d)
    {
        return 0;
    }
    if(c == 1 || d ==1)
    {
        return (max(c,d) - 1);
    }
   
    if(v[c][d] == -1)
    {
        if(d <= a && c<= b)
        {
            if(v[d][c]!= -1)
            {
                return v[d][c];
            }
        }
    
            long long counter = 10000000, temp = 0;
            for(int i = 1; i < d/2 + 1; i++ )
            {
                temp = 1 + cal(c, d - i)+ cal(c, i);
                if(counter > temp)
                {
                    counter = temp;
                }
            }
            
           
            for(int i = 1; i < c/2 +1 ; i++)
            {
                temp = 1 + cal(i, d)+ cal(c - i, d);
                if(counter > temp)
                {
                counter = temp;
                }
            }
            
            v[c][d] = counter;
            
            return counter;
            
        }
        else
        {
            return v[c][d];
        }
    
    
    
}

int main(int argc, const char * argv[]) {
    
    cin>>a>>b;
    v= vector<vector<long long>>(a + 1, vector<long long> (b + 1, -1));

    cout<<cal(a,b);
    
    return 0;
}
