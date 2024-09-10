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
    int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
         if (!head->next) return head;
        int x=head->val, y;
        for(ListNode* prev=head, *ptr=head->next; ptr;ptr=ptr->next){
            int y=ptr->val;
        //    cout<<gcd(x, y)<<"-->";
            ListNode* newNode=new ListNode(gcd(x, y), ptr);
            prev->next=newNode;
            prev=ptr;
        //    if(ptr) cout<<ptr->val<<endl;
            x=y;
        }
        return head;
        
    }
};