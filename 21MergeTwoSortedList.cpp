#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
    // Recursion solution:
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     //if either list is empty(NULL), return the other list
    //     if (!list1)
    //         return list2;
    //     if (!list2)
    //         return list1;
    //     if(list1->val < list2->val){
    //         list1->next = mergeTwoLists(list1->next, list2);
    //         return list1;
    //     }
    //     else{
    //         list2->next = mergeTwoLists(list1, list2->next);
    //         return list2;
    //     }
    // }

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //if either list is empty(NULL), return the other list
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode* head = list1;
        if(list1->val < list2->val){
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }
        //make a counter pointer for current node that we're on
        ListNode* curr = head;
        //While both lists have nodes left, continue comparing and adding to merged list
        while(list1 && list2){
            if(list1->val < list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        //for any remaining nodes in one list
        if (!list1){
            curr->next = list2;
        }
        else{
            curr->next = list1;
        }
        return head;
    }
};

int main(){
    Solution tester;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    node1->next = new ListNode(2);
    node1->next->next = new ListNode(4);
    node2->next = new ListNode(3);
    node2->next->next = new ListNode(4);
    ListNode* head = tester.mergeTwoLists(node1,node2);
    while (head->next != nullptr){
        cout << head->val << "->";
        head = head->next;
    }
    cout << head->val;
}