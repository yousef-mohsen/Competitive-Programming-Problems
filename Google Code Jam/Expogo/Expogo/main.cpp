//
//  main.cpp
//  Expogo
//
//  Created by Yousef on 04.04.21.
//

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
typedef long long ll;

string ans;
void invert(bool inv_x, bool inv_y)
{
    for(auto a: ans)
    {
        if(a == 'E')
            if(inv_x)
                cout<<'W';
            else
                cout<<a;
        if(a == 'W')
            if(inv_x)
                cout<<'E';
            else
                cout<<a;
        if(a == 'N')
            if(inv_y)
                cout<<'S';
            else
                cout<<a;
        if(a == 'S')
            if(inv_y)
                cout<<'N';
            else
                cout<<a;
        
    }
}

int main(int argc, const char * argv[]) {
    ll t, x, y;
    cin>>t;
    for(int i = 1; i <= t; i++)
    {
        cin>>x>>y;
        bool inv_x = x < 0, inv_y = y < 0;
        x = llabs(x);
        y = llabs(y);
        
        if((x + y) % 2 == 0)
            cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<"\n";
        else
        {
            
             ans = "";
            
            while(true)
            {
                if(x == 1 && y == 0)
                {
                          ans += "E" ;
                        cout<<"Case #"<<i<<": ";
                    if(!inv_x && ! inv_y )
                        cout<<ans<<"\n";
                    else
                    {
                        invert(inv_x, inv_y);
                        cout<<"\n";
                    }
                    
                            break;
                 
                }
                if(y == 1 && x == 0)
                {
                    ans += "N";
                    cout<<"Case #"<<i<<": ";
                if(!inv_x && ! inv_y )
                    cout<<ans<<"\n";
                else
                {
                    invert(inv_x, inv_y);
                    cout<<"\n";
                }
                            break;
                  
                }
                if(x == 0 || y % 2 == 1)
                {
                    if((((y + 1) / 2) % 2 == 1 && (x/2)%2 == 0) || (((y + 1) / 2) % 2 == 0 && (x/2)%2 == 1) )
                    {
                            ans += "S";
                            y++;
                    }
                    else
                    {
                        
                        ans += "N";
                        y--;
               
                    }
                    y /= 2;
                    x /= 2;
                }
                else
                {
                    if((((x + 1) / 2) % 2 == 1 && (y/2)%2 == 0) || (((x + 1) / 2) % 2 == 0 && (y/2)%2 == 1) )

                    {
                         ans += "W";
                            x++;
                       
                    }
                    else
                    {
                            ans += "E";
                            x--;
                        
                    }
                    x /= 2;
                    y /= 2;
                }
 
            }
            
        }
    }
    
    return 0;
}
