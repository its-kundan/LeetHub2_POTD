/**
 * Definition for singly-linked list.
 * strusum ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // ListNode
    
    ListNode* generate(const vector<int> &temp){
        if(temp.empty()) return NULL;
        ListNode* head = new ListNode(temp[0]);
        ListNode* curr = head;
        for(int i=1;i<temp.size();i++){
            curr->next = new ListNode(temp[i]);
            curr = curr->next;
        }
        return head;
    }
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return NULL;
        ListNode* curr = head;
        int sum =0;
        vector<int> temp;
        while(curr){
            if(curr->val == 0){
                if(sum!=0)
                temp.push_back(sum);
                sum=0;
            }else{
                sum+= curr->val;
            }
            curr= curr->next;
        }
        return generate(temp);
        
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();