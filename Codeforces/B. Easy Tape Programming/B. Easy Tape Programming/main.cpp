//
//  main.cpp
//  B. Easy Tape Programming
//
//  Created by Yousef on 09.08.20.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {

    int n, q, l, r, d = 1, pos = 1, p;
    bool f = false;
    
    
    char c;
    cin>>n>>q;
    vector <char> v;
    vector<int> v3(10,0);
    v.push_back('\n');
    
    while(n--)
    {
        cin>>c;
        v.push_back(c);
    }
    v.push_back('\n');
    
    for(int i = 0; i < q; i++)
    {
        pos = 1;
        cin>>l>>r;
        vector <char> v2;
        v2.push_back('\n');
        
        for(l; l<=r; l++)
            v2.push_back(v[l]);
        v2.push_back('\n');
        vector<int> v3(10,0);
        d= 1;
        f = false;
        while(v2[pos]!= '\n')
        {
           if(v2[pos]=='-')
           {
               pos += d;
               continue;
           }
            
            if(v2[pos] != '>' && v2[pos] != '<')
            {
                if(v2[pos] =='0')
                {
                    f = false;
                    v3[0] += 1;
                    v2[pos] = '-';
                }
                else
                {
                    
                    v3[v2[pos]-48]+=1;
                    v2[pos]-=1;
                    f= false;
                }
            }
            else
            {
                if(f)
                {
                    v2[p] ='-';
                }
                
                
                if(v2[pos] == '>')
                {
                    d = 1;
                    f = true;
                    p= pos;
                }
                else {
                    d = -1;
                    f = true;
                    p= pos;
                }
            }
            pos+=d;
        }
        for(int i = 0; i<10;i++)
            cout<<v3[i]<<" ";
        cout<<"\n";
        
        
        
    }

    return 0;
}
