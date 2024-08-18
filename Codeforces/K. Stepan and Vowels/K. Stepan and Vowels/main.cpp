//
//  main.cpp
//  K. Stepan and Vowels
//
//  Created by y.m on 19.08.20.
//
 
#include <iostream>
#include <vector>
#include <set>
using namespace std;
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, c_e = 0, c_o = 0;
    char c;
    cin>>n;
    
    
    vector<char> v (n + 4);
    bool e,o;
    
    for(int i = 1; i<=n; i++)
    {
        cin>>c;
        v[i] = c;
    }
    
  
    
    for(int i =1; i <=n;i++)
    {
        
            if((v[i]==v[i+1])
               &&(v[i]!=v[i-1])
               &&(v[i]!=v[i+2])
               &&(v[i]=='o'))
            {
                cout<<v[i]<<v[i+1];
                i++;
                continue;
            }
            
            if((v[i]==v[i+1]&&(v[i]!=v[i-1])&&v[i]!=v[i+2])&&(v[i]=='e'))
            {
                cout<<v[i]<<v[i+1];
                i++;
                continue;
            }
           
        if((v[i]==v[i+1])&&(v[i]=='a'||v[i]=='e'||v[i]=='i'||v[i]=='o'||v[i]=='u'||v[i]=='y'))
        {
            cout<<v[i];
            
            while(v[i]==v[i+1])
            {
                i++;
            }
        }
        else
        {
            cout<<v[i];
        }
        
    }
    
    return 0;
}
