//
//  main.cpp
//  2011. Final Value of Variable After Performing Operations
//
//  Created by Yousef on 27.05.26.
//

#include <iostream>
#include <string>

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int counter = 0;
        
        for(auto a: operations)
        if(a == "X++" || a == "++X")
            counter ++;
        else
            counter --;
            
        return counter;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
