//
//  main.cpp
//  Repetitions
//
//  Created by Yousef on 16.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string text;
    cin>>text;
    int best = 1;
    int count = 1;
  
    for (int i=0; i<text.length()-1;i++)
    {
        if(text[i]==text[i+1])
        {
            count++;
            best = max(count,best);
        }
        else {
            
            count = 1;
        }
    }
    cout<<best;
    
    return 0;
}
