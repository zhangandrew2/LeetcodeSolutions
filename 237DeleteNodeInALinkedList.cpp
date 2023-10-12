#include <string>
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};


int main(){
    ListNode head = ListNode(4);
    ListNode second = ListNode(5);
    head.next = &second;
    ListNode third = ListNode(1);
    second.next = &third;
    ListNode fourth = ListNode(9);
    third.next = &fourth;
    fourth.next = nullptr;
    Solution test;
    test.deleteNode(&third);
    ListNode* counter = &head;
    while(counter->next != nullptr){
        cout<< counter->val;
        counter = counter->next;
    }
    cout << counter->val;
}