//
//  main.cpp
//  You Can Go Your Own Way
//
//  Created by Yousef on 02.11.21.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int t, n;
    cin>>t;
    
    for(int i = 1; i <= t; i++)
    {
        cin>>n;
        string s;
        cin>>s;
        replace(s.begin(), s.end(),'E', '*');
        replace(s.begin(), s.end(),'S', 'E');
        replace(s.begin(), s.end(),'*', 'S');
        cout<<"Case #"<<i<<": "<<s<<"\n";
    }
    
    return 0;
}
