/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;
    struct ListNode* prev = NULL;
    int carry = 0;

    // Step 1: add corresponding digits while both lists have nodes
    while (temp1 != NULL && temp2 != NULL) {
        int sum = temp1->val + temp2->val + carry;
        temp1->val = sum % 10;
        carry = sum / 10;

        prev = temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // Step 2: if l2 is longer, attach its remaining part to l1
    if (temp2 != NULL) {
        prev->next = temp2;   // connect remaining nodes of l2
        temp1 = temp2;
    }

    // Step 3: handle remaining carry through the rest of the list
    while (temp1 != NULL) {
        int sum = temp1->val + carry;
        temp1->val = sum % 10;
        carry = sum / 10;

        prev = temp1;
        temp1 = temp1->next;
    }

    // Step 4: if carry still left, create a new node
    if (carry > 0) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = carry;
        newNode->next = NULL;
        prev->next = newNode;
    }

    return l1;
}
