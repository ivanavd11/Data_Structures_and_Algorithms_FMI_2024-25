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
        if(!list1)
            return list2;

        if(!list2)
            return list1;


        ListNode* result = nullptr;
        ListNode* curr = nullptr;

        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                if(!result)
                {
                    result = list1;
                    curr = result;
                }
                else
                {
                    curr->next = list1;
                    curr = curr->next;
                }
                list1 = list1->next;
            }
            else
            {
                if(!result)
                {
                    result = list2;
                    curr = result;
                }
                else
                {
                    curr->next = list2;
                    curr = curr->next;
                }
                list2 = list2->next;
            }

        }

        if(!list1)
        {
            curr->next = list2;
        }
        if(!list2)
        {
            curr->next = list1;
        }
        return result;
    }
};
