//
//  main.cpp
//  Foregone Solution
//
//  Created by Yousef on 02.11.21.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    
    for (int k = 1; k <= t; k++)
    {
        string s, a, b;
        cin>>s;
        bool f = false;
    
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == '4')
            {
                f = true;
                a += '2';
                b += '2';
                continue;
            }
            
            if(!f)
            {
                a += s[i];
            }
            else
            {
                a += s[i];
                b += '0';
            }
        }
        cout<<"Case #"<<k<<": "<<a<<" "<<b<<"\n";
    }
    
    return 0;
}
