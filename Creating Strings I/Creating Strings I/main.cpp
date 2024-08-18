//
//  main.cpp
//  Creating Strings I
//
//  Created by Yousef on 18.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;
map <string,string> ans;
void search(string,vector <char>& , int[]);


int main(int argc, const char * argv[]) {
    string s;
    cin>>s;
    vector <char> permutations;
    int *arr = new int[s.size()];
    
    for(int i=0; i<s.size();i++)
    {
        arr[i] = 0;
    }
    
    sort(s.begin(),s.end());
    search(s,permutations, arr);
    cout<<ans.size()<<"\n";
    
    for (auto i = ans.begin(); i != ans.end(); ++i)
         cout <<i->first<<"\n";
    
    
    
    return 0;
}
void search(string s, vector<char>& permutations,int arr[])

{
    if(permutations.size()== s.size())
    {
        string k;
        for(int i=0; i<s.size();i++)
        {
            k+=permutations[i];
        }
        
        ans.insert(pair<string,string>(k,k));
        
    }
    else
    {
        for(int i=0; i<s.size();i++)
        {
            if(arr[i])
            {
                continue;
                
            }
            permutations.push_back(s[i]);
            arr[i] = 1;
            search(s, permutations,arr);
            arr[i] = 0;
            permutations.pop_back();
    }
    }
}
