/**
* @description:
* Step 1: Declare dummy and current variables (defined as pointers to point at the mem addr of each object)
* Step 2: since 2 LL's are sorted, have 2 ptrs that compare the value of each of the LL's starting from the beggining
* Step 3: Whichever LL has the smaller value, add that to curr->next and traverse that smaller valued LL by one node
* Step 4: Keep traversing until either one of the lists are null
* Step 5: Then append the trailing elements in the list that is nonnull
* Step 6: Lastly, since our curr ptr is all the way at the end, return dummy->next to get us back to the head
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        while (list1 && list2) {
            if(list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        list1 ? curr->next = list1 : curr->next = list2;

        ListNode *head = dummy->next;
        return head;
    }
};
