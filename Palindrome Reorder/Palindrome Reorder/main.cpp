//
//  main.cpp
//  Palindrome Reorder
//
//  Created by Yousef on 18.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    map<char,string>  myMap;
    string a;
    cin>>a;
    for(int i=0; i<a.length();i++)
    {
        if(myMap.count(a[i]))
        {
            myMap[a[i]]+=a[i];
        }
        else
        {
         myMap[a[i]]=a[i];
        }
    }
    int odd =0;
    
    char oddChar;
    string oddString;
    for(auto i =myMap.begin(); i!=myMap.end();++i)
    {
        if((i->second.size())%2 ==1)
        {
            odd ++;
            oddString = i->second;
            oddChar = i->first;
        }
    }
    if(odd > 1)
    {
        cout<<"NO SOLUTION";
        return 0;
    }
    string ans;
    ans+= oddString;
    for(auto i =myMap.begin(); i!=myMap.end();++i)
     {
         if(i->second.size()%2==1)
         {
             continue;
         }
         
         ans = (i->second).substr((i->second).size()/2) + ans + (i->second).substr((i->second).size()/2);
     }
    cout<<ans;
    return 0;
}
