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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next ==nullptr)
        {
            return true;
        }
        //first we have to find the middle of the linked list
        ListNode *slow = head , *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //now slow is in the middle of the linked list
        //now we need to reverse the second half and compare it with the first one
        ListNode* reversedLinkedList = reverse(slow);
        ListNode* BackUpReversedLinkedList = reversedLinkedList;
        while(head != nullptr && reversedLinkedList != nullptr)
        {
            if (head->val != reversedLinkedList->val)
            {
                break;
            }
            head = head->next;
            reversedLinkedList = reversedLinkedList->next;
        }
        reverse(BackUpReversedLinkedList);
        if(head == nullptr || reversedLinkedList == nullptr)
        {
            return true;
        }
        return false;
    }
private:
ListNode* reverse(ListNode*head)
{
    ListNode *prev = nullptr;
    ListNode *next ;
    while (head != nullptr)
    {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
}
};
