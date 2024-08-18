//
//  main.cpp
//  B. Restoring IPv6
//
//  Created by Yousef on 12.08.20.
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    char c;
    int n;
    cin>>n;
    
    while(n--)
    {
        vector<vector<char>> v (8, vector<char>(4,0));
        
        int counter = 0;
        while(c!='\n')
        {
            

            v[counter].push_back(c);
            (v[counter]).erase(v[counter].begin());
            cin>>c;
        }
        for(int i =0; i<8; i++)
        {
            for(int k=0; k<4; k++)
            {
                cout<<v[i][k];
            }
            cout<<":";
        }
        cout<<"\n";
        
    }
    
    return 0;
}
