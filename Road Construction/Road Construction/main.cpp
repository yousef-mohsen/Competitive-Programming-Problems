//
//  main.cpp
//  Road Construction
//
//  Created by Yousef on 16.09.20.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> sizee;
vector<int> link;
int comp = 0;

int find(int x)
{
    if(link [x] == x)
        return x;
    
    return link[x] = find(link[x]);
}

void unite (int x, int y)
{
    x = find(x);
    y = find (y);
 
    if(sizee[x] < sizee[y])
        swap(x, y);
    sizee[x] += sizee[y];
    link[y] = x;
    
    if(sizee[x] > comp)
        comp = sizee[x];
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin>>n>>m;
    sizee = vector<int> (n + 1);
    link = vector<int> (n + 1);
    
    for(int i = 1; i<= n; i++)
    {
        sizee[i] = 1;
        link [i] = i;
    }
    while(m--)
    {
        cin>>a>>b;
        if(find (a) == find (b))
        {
            cout<<n<<" "<<comp<<"\n";
        }
        else
        {
            unite (a, b);
            n--;
            cout<<n<<" "<<comp<<"\n";
        }
    }
    
    return 0;
}
