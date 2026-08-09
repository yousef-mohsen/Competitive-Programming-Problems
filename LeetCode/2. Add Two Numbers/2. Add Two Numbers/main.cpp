//
//  main.cpp
//  2. Add Two Numbers
//
//  Created by Yousef on 19.05.26.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0, sum = 0;
        
        ListNode * head = nullptr;
        ListNode * tail = nullptr;
        
        while (l1 != nullptr || l2 != nullptr)
        {
            sum = 0;
            if (l1!= nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2!= nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            if(sum >= 10)
                carry = 1;
            else
                carry = 0;
            
            ListNode* n = new ListNode(sum%10, nullptr);
            
            if(!head)
            {
                head = n;
                tail = n;
            }
            else
            {
                tail->next = n;
                tail = n;
            }
            
        }
        if(carry){
            ListNode* n = new ListNode(1, nullptr);
            tail->next = n;
        }
            
        return head;
        
    }
};

int main(int argc, const char * argv[]) {
    // 2 -> 4 -> 3
        ListNode* l1 =
            new ListNode(2,
                new ListNode(4,
                    new ListNode(3)));

        // 5 -> 6 -> 4
        ListNode* l2 =
            new ListNode(5,
                new ListNode(6));

        Solution s;

        ListNode* result = s.addTwoNumbers(l1, l2);
    cout<<10%10;
    return EXIT_SUCCESS;
}
