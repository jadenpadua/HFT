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
private:
    void printLL(ListNode* head) {
        while(head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << "\n";
    }
    void findMidpoint(ListNode*& slow, ListNode*& fast) {
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    ListNode* reverseLL(ListNode*& head) {
        ListNode* prev = nullptr; ListNode* temp = nullptr;
        while(head != nullptr) {
            temp = head;
            head = head->next;
            temp->next = prev;
            prev = temp;
        }
        return prev;
    }
    bool compareHalves(ListNode*& h1, ListNode*& h2) {
        while(h1 != nullptr && h2 != nullptr ) {
            if(h1->val != h2->val) return false;
            h1 = h1->next; h2 = h2->next;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head; ListNode* fast = head;
        findMidpoint(slow, fast);

        ListNode* p = reverseLL(slow);

        bool isPalindrome = compareHalves(head, p);
        return isPalindrome;

    }
};
