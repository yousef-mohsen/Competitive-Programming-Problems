//
//  main.cpp
//  732. My Calendar III
//
//  Created by Yousef on 28.06.26.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    multiset<pair<int,char>> s;
    int book(int startTime, int endTime) {
        s.insert({startTime,'S'});
        s.insert({endTime,'E'});
        int counter = 1, m = 1;
        auto it = s.begin();
        it++;
        while(it != s.end())
        {
            if(it->second == 'S')
            {
                counter ++;
                m = max(counter, m);
            }
            else
            {
                counter--;
                
            }
            it++;
        }
        return m;
        
    }
};


int main(int argc, const char * argv[]) {
    
    MyCalendarThree myCalendarThree;
    myCalendarThree.book(10, 20); // return 1
    myCalendarThree.book(50, 60); // return 1
    myCalendarThree.book(10, 40); // return 2
    myCalendarThree.book(5, 15); // return 3
    myCalendarThree.book(5, 10); // return 3
    myCalendarThree.book(25, 55); // return 3

    return 0;
}
