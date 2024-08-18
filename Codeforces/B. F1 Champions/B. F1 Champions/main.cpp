//
//  main.cpp
//  B. F1 Champions
//
//  Created by Yousef on 08.08.20.
//

#include <iostream>
#include  <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    map<string, int> m;
    map<int,string> m2;
    
    vector <vector<int>> v;
    vector <vector<int>> v2;
    int arr[11] ={0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    int id = -1, t, n;
    string r;
    
    cin>>t;
    
    for (int i = 0; i < t; i++)
    {
        cin>>n;
        int pos = 1;
        
        while(n--)
        {
            cin>>r;
            if(!m.count(r))
            {
                id++;
                m[r] = id;
                m2[id] = r;
                
                v.push_back(vector<int>(52));
                v2.push_back(vector<int>(52));
                v[id][51] = id;
                v2[id][51] = id;
            }
            
            if(pos <=10)
                {
                    v[m[r]][0] += arr[pos];
                    v2[m[r]][1] += arr[pos];
                }
            
                v[m[r]][pos] += 1;
            
            
                if(pos == 1)
                {
                    v2[m[r]][0] += 1;
                }
                else
                {
                    v2[m[r]][pos] += 1;
                }
                          pos ++;
            
        }
    }
    
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    
    auto it1 =v.end();
    auto it2 =v2.end();
    it1--;
    it2--;

    cout<<m2[(*it1)[51]]<<"\n";
    cout<<m2[(*it2)[51]]<<"\n";

    
    return 0;
}
