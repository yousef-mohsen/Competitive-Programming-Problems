//
//  main.cpp
//  Chessboard and Queens
//
//  Created by Yousef on 03.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
using namespace std;

bool diag_1 [16]{false};
bool diag_2 [16]{false};
bool column [16]{false};
char arr [8][8];
long long counter = 0;

void search(int y)
{
    
    if(y == 8)
    {
        counter ++;
        return;
    }
    for(int x = 0; x < 8; x++)
    {
        if (column[x]|| diag_1[ x + y] || diag_2[ x - y + 7] || (arr[y][x] == '*'))
        {
            continue;
        }
        column[x] = diag_1[x + y] = diag_2[x - y + 7] = 1;
        search(y + 1);
        column[x] = diag_1[x + y] = diag_2[x - y + 7] = 0;
    }
    
}

int main(int argc, const char * argv[]) {
    for(int i = 0; i < 8; i++)
        {
            for(int k = 0; k < 8; k++)
            {
                cin>>arr[i][k];
            }
        }

    search(0);
    cout<<counter;
    
    return 0;
}
