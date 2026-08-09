//
//  main.cpp
//  141. Linked List Cycle
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        
        ListNode *a = head;
        ListNode *b = head;
        
        if(a)
            a = a->next;
        else
            return false;
        
        if(b && b->next)
        {
            b = b->next->next;
            }
        else
            return false;
        
        while(a!= b)
        {
            if(a)
                a = a->next;
            else
                return false;
            
            if(b && b->next)
            {
                b = b->next->next;
             
            }
            else
                return false;
        }
        
        return true;
        
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
