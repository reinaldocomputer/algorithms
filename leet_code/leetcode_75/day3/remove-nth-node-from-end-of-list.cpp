#include <iostream>
#include <vector>

using namespace std;

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

/*
    Quando for casos de LinkedList conferir o tratamento pra quando for um elemento.
    E quando for possível, remover o início.

*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        if(head->next==NULL) return NULL;

        stack <ListNode *> s;
        ListNode *it = head;
        while(it != NULL){
            s.push(it);
            it = it->next;
        }

        int cont=1;
        while(not s.empty()){
            it = s.top(); s.pop();
            if(cont == n) {
                if(it==head){
                    head = it->next;
                } else{
                    s.top()->next = it->next;
                }
                break;
            }
            cont++;
        }
        return head;
    }
};

