//
//  main.cpp
//  B. Interactive Bulls and Cows (Easy)
//
//  Created by y.m on 24.08.20.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> ans;
    int b, c;
    
    for(int i=0; i<= 9; i++)
    {
        for(int k = 1; k<= 4; k++)
        {
            cout<<i;
        }
        cout<<"\n";
        fflush(stdout);
        cin>>b>>c;
        if(b)
        {
            ans.push_back(i);
        }
        if(ans.size() == 4)
        {
            break;
            
        }
    }
    sort(ans.begin(), ans.end());
    do{
        for(int i =0; i< 4; i++)
        {
            cout<<ans[i];
        }
        cout<<"\n";
        fflush(stdout);
        cin>>b>>c;
        if(b == 4)
            return 0;
        
    }while(next_permutation(ans.begin(),ans.end()));
    
    return 0;
}
