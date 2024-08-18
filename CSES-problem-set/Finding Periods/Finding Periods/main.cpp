//
//  main.cpp
//  Finding Periods
//
//  Created by Yousef on 24.10.20.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(0); cin.tie(0);
    string s, p;
    int l = 0, r = 0, counter, c = 0;
    cin>>s;
    vector<int> z(s.size());
    p = s;

    for(int i = 1; i < s. size(); i++)
    {
        if(i > r)
        {
            r = i;
            l = i;
            counter = 0;
            c = 0;
            while(s[r] == p[c] && r < s.size())
            {
                counter++;
                r++;
                c++;
            }
            if(r == s.size() || s[r] != p[c])
                r--;
            z[i] = counter;
            
        }
        else if(z[i - l] + i <= r)
        {
            z[i] = z[i - l];
        }
        else
        {
            l = i;
            counter = r - i + 1;
            c = counter;
            r =  r + 1;
            while(s[r] == p[c] && r < s.size())
            {
                c++;
                counter ++;
                r++;
            }
            if(r == s.size() || s[r] != p[c])
                           r--;
            z[i] = counter;
        }
    }
    int q = s.size();
    for(int i = 1; i < q; i
        ++)
    {
        if(i + z[i] == q)
            cout<<q - z[i]<<" ";
    }
    cout<<q;
    return 0;
}
