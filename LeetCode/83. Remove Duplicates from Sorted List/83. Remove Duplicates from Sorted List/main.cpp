//
//  main.cpp
//  83. Remove Duplicates from Sorted List
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        
        ListNode * temp = head;
        ListNode *temp_2;
        
        while(temp)
        {
            if(temp -> next)
            {
                if((temp -> next -> val) == (temp -> val))
                {
                    temp_2 = temp ->next;
                    temp->next = temp_2->next;
                    //temp = temp_2->next;
                    delete temp_2;
                }
                else
                {
                    temp = temp -> next;
                }
            }
            else
                return head;
        }
        
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
