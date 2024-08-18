//
//  main.cpp
//  Number Guessing
//
//  Created by Yousef on 25.03.21.
//

#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b, t, n, m;
    string s;
    cin>>t;
    
    for(int i = 1; i <= t; i++)
    {
        
        cin>>a>>b>>n;
        a++;
        while(a <= b)
        {
            m = (a + b) / 2;
            cout<<m<<endl;
            cin>>s;
            if(s == "CORRECT")
                break;
            else if (s == "TOO_BIG")
                b = m - 1;
            else if (s == "TOO_SMALL")
                a  = m + 1;
            else
                return 0;
            
        }
        
        
    }
    
    return 0;
}
