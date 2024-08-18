//
//  main.cpp
//  Moons and umbrellas
//
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    ll t, x, y;
    cin>>t;
    
    for(int z = 1; z <= t; z++)
    {
        string s;
        
        cin>>x>>y;
        cin>>s;
        ll c_end = 1e12, j_end = 1e12;
        if(s[0] != 'J')
            c_end = 0;
        if(s[0] != 'C')
            j_end = 0;
        
        
        for(int i = 1; i < s.size(); i++)
        {
            ll c_t = 1e12, j_t = 1e12;
            
            if(s[i] != 'J')
            {
                c_t = min(c_end, j_end + y);

            }
            if(s[i] != 'C')
            {
                j_t = min(j_end, c_end + x);
            }
            c_end = c_t;
            j_end = j_t;

        }
        cout<<"Case #"<<z<<": "<<min(c_end, j_end)<<"\n";
    }
    return 0;
}
