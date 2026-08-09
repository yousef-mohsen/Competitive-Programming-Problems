//
//  main.cpp
//  941. Valid Mountain Array
//
//  Created by Yousef on 04.06.26.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int length = arr.size(), pos = 0;
        
        if(length < 3)
            return false;
        for(int i = 0; i < length - 1; i++)
        {
            if(arr[i] == arr[i + 1])
                return false;
            
            if (arr[i] > arr[i + 1])
            {
                if (i == 0)
                    return false;
                pos = i;
                break;
            }
        }
        for(int i = pos; i < length - 1; i ++)
        {
            if (arr[i] <= arr[i + 1])
                return false;
        }
        return true;
        
    }
};

int main(int argc, const char * argv[]) {
    
    
    
    return EXIT_SUCCESS;
}
