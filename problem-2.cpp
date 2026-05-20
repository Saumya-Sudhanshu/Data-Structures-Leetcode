/*
2. Add Two Numbers
    Time complexity: O(max(m, n)) where m and n are the lengths of the two linked lists.
    Space complexity: O(max(m, n)) for the new linked list that we create to store the result.
    Approach: We traverse both linked lists simultaneously, 
    adding corresponding digits along with any carry from the previous addition.
    We create new nodes for the resulting linked list as we go, 
    and handle cases where one list is shorter than the other by treating missing nodes as zero.
    Finally, 
    we return the head of the new linked list that represents the sum of the two numbers.
*/

#include <iostream>

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
        // Create a dummy node to simplify insertion
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;
        
        // Continue if there are nodes left in either list, or a carry remains
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Use ternary operators to get values safely, defaulting to 0 if null
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate sum and the new carry
            int total = val1 + val2 + carry;
            carry = total / 10;
            
            // Create the new node with the digit part of the sum
            current->next = new ListNode(total % 10);
            
            // Advance the current pointer
            current = current->next;
            
            // Advance l1 and l2 pointers if they haven't reached the end
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        // Store the result before deleting the dummy node to prevent memory leaks
        ListNode* result = dummyHead->next;
        delete dummyHead; 
        
        return result;
    }
};