//
//  main.cpp
//  A. Square and Rectangles
//
//  Created by Yousef on 11.08.20.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, x1, x2, y1, y2, x_m= -1, y_m = -1, x_mi= 1e8, y_mi = 1e8;
    
    double area = 0.0;
    cin>>n;
    
    while(n--)
    {
        cin>>x1>>y1>>x2>>y2;
        x_m = max(x_m,(max(x1,x2)));
        y_m = max(y_m,(max(y1,y2)));
        x_mi = min(x_mi,(min(x1,x2)));
        y_mi = min(y_mi,(min(y1,y2)));
        
        area += (y2-y1)*(x2-x1);
    }
    
    if(((x_m-x_mi) * (y_m-y_mi)) > area || (x_m-x_mi != y_m-y_mi) )
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }
    
    
    
    return 0;
}
