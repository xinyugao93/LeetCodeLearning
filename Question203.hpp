#include "ListNode.h"

namespace q203 {

class Solution203 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) {
            return head;
        }
        ListNode* cur = head, *last = nullptr;
        while(cur) {
            if(val == cur->val) {
                if(cur == head) {
                    auto delNode = cur;
                    cur = cur->next;
                    head = cur;
                    delNode->next = nullptr;
                    delete delNode;
                } else {
                    auto delNode = cur;
                    last->next = cur->next;
                    cur = cur->next;
                    delNode->next = nullptr;
                    delete delNode;
                }
            } else {
                last = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

}

