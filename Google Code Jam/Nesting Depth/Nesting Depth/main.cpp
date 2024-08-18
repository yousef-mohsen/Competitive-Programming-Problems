//
//  main.cpp
//  Nesting Depth
//
//  Created by Yousef on 24.03.21.
//

#include <iostream>
#include <vector>
#include <string>
typedef long long  ll;
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, o = 0, counter;
    string s;
    cin>>t;
    
    for(int q = 1; q <= t; q++)
    {
        cin>>s;
        o = 0;
        cout<<"Case #"<<q<<": ";
        
        for(int i = 0; i < s.length(); i++)
        {
            counter = s[i] - 48;
            
            if(o > counter )
            {
                for(int k = 1; k <= o - counter; k++)
                    cout<<")";
                o -= o - counter;
                
            }
            
            for(int k = 1; k <= counter - o; k++)
                cout<<"(";
            o += counter - o;
            
            
            cout<<s[i];
        }
        
        for(int k = 1; k <= o; k++)
            cout<<")";
        cout<<"\n";
    }
    

    return 0;
}
