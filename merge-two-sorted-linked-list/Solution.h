/*
    Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

    Example 1:
    Input: l1 = [1,2,4], l2 = [1,3,4]
    Output: [1,1,2,3,4,4]

    Example 2:
    Input: l1 = [], l2 = []
    Output: []

    Example 3:
    Input: l1 = [], l2 = [0]
    Output: [0]
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {        
        if (!l1 && !l2) {
            return nullptr; 
        }                        
        // define a dummy root and its points to the first element, 
        auto root = new ListNode(0); 
        ListNode* preNode = root;
        
        while (l1 || l2) {
            if (!l1) {
                preNode->next = l2; 
                break; 
            }
            if (!l2) {
                preNode->next = l1;
                break;  
            }                                          
            if (l1->val <= l2->val) {
                preNode->next = new ListNode(l1->val); 
                l1 = l1->next;                 
            }
            else {
                preNode->next = new ListNode(l2->val);
                l2 = l2->next;                 
            }
            /**
             * at this point, the previous node is pointing to a new node, and for the 
             * next iteration, move the previous node to its next
             **/ 
            preNode = preNode->next;                                     
        }
        
        return root->next; 
                
    }
};