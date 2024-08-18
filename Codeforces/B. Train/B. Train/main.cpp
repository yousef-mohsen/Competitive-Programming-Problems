//
//  main.cpp
//  B. Train
//
//  Created by Yousef on 08.08.20.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n, m, k, t;
    string d, p;
    cin>>n>>m>>k;
    cin.ignore();
    getline(cin,d);
    getline(cin,p);
    
    cout<<"p"<<p<<"\n";
    cout<<"d"<<d<<"\n";
    
    if (d == "to head")
    {
        t = -1;
    }
    else
    {
        t = 1;
    }
    
    
    for (int i = 0; i<p.length(); i++)
    {
        
        if (p[i] == '1')
        {
            if (t == -1)
            {
                m = n;
            }
            else
            {m = 1;}
            
            }
        if(p[i]!= '1')
        {
            if ((t == -1 && m < k) ||(t == 1 && m < k))
                m = 1;
            else {
                m = n;
                }
        }
        k +=t;
        
        if(k == 1 || k == n)
        {
            t= -1 * t;
        }
            
        if (m == k)
        {
            cout<<"Controller"<<" "<<i+1;
            return 0;
        }
    }
    
    cout<<"Stowaway";
    
    
    
    
    return 0;
}
