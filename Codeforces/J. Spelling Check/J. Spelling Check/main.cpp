//
//  main.cpp
//  J. Spelling Check
//
//  Created by Yousef on 11.08.20.
//

#include <iostream>

#include "string.h"
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s, d, c;
    int begin = 0, end;

    getline(cin,s);
    getline(cin,d);
    
    c = s;
    
    for(int i = 0; i <s.length(); i++)
    {
        if(s[i]!= d[i])
        {
            begin = i;
            s.erase(i,1);
            
            if(s.compare(d) != 0)
            {
                cout<<0;
                return 0;
            }
            
            while(c[i]== c[i-1])
            {
                i--;
            }
                
            begin = i;
            while(c[i]==c[i+1])
            {
                i++;
            }
         
            
            if(i== begin)
            {
                cout<<1<<"\n"<<i+1;
            }
            else
            {
                begin++;
                i++;
                
                cout<<i-begin +1<<"\n";
                for(begin; begin <=i; begin ++)
                {
                    cout<<begin<<" ";
                }
            }
            
            return 0;
            
        }
    }
    
    
    
    
    return 0;
}
