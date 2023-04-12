/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //EXPLANATION :
    //we will create 2 pointers one is fast and the other one is slow
    //fast will move 2 steps 
    //slow will move 1 step
    //if its Cycle they will meetup and somepoint
    //if they meetup sure it will cyclic linked list 
    bool hasCycle(ListNode *head)
    {
        ListNode * fast = head , *slow = head; //create two node 1-fast : moves 2 steps 2-slow : move 1 step
        while(fast && fast -> next) 
        {
            slow=slow->next; //move 1 step
            fast=fast->next->next; //move 2 steps
            
            if(slow == fast) // check if they meetup
            {
              return true;
            }
        }
        return false;
    }
};
