/*
228. Middle of Linked List
中文English
Find the middle node of a linked list.

Example
Example 1:

Input:  1->2->3
Output: 2	
Explanation: return the value of the middle node.
Example 2:

Input:  1->2
Output: 1	
Explanation: If the length of list is  even return the value of center left one.
*/

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode * middleNode(ListNode * head) {
        // write your code here
        if(head == NULL) 
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next; 
        }
        return slow; 
    }
};