//
//  main.cpp
//  A. Set Theory
//
//  Created by Yousef on 20.08.20.
//
 
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    
    while (n--)
    {
        int t, p;
        cin>>t;
        vector<int> v;
        //unordered_set<int> s;
        //unordered_set<int> ans;
        vector<int> ans;
        
        for(int i =1; i<=t; i++)
        {
            cin>>p;
            v.push_back(p);
        }
        vector<bool> test(1000000+1, false);
        
        for(int i=0; i<t; i++)
        {
            for(int q=i+1; q<t; q++)
            {
                test[max(v[i],v[q])-min(v[i],v[q])]= true;
                
                //s.insert(max(v[i],v[q])-min(v[i],v[q]));
            }
        }
        
        for(int i= 1; i<=1000000; i++)
        {
            bool f = false;
            for(auto z:ans)
            {
                if(test[max(z,i)-min(z,i)])
                //if(s.count(max(z,i)-min(z,i)))
                {
                    f = true;
                    break;
                }
            }
            if(!f){
                ans.push_back(i);
            }
            if(ans.size()  == t)
            {
                break;
            }
        }
        if(ans.size() == t)
        {
            cout<<"YES"<<"\n";
            for(auto a:ans)
            {
                cout<<a<<" ";
            }
            cout<<"\n";
        }
        else
        {
            cout<<"NO"<<"\n";
        }
    }
 
 
    return 0;
}
