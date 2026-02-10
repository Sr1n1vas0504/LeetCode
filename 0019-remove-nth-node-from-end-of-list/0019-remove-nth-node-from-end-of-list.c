/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) return NULL;

    // Step 1: find length
    int len = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    // Step 2: if we need to remove the head
    if (n == len) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }

    // Step 3: find the node just before the one to delete
    temp = head;
    for (int i = 1; i < len - n; i++) {
        temp = temp->next;
    }

    // Step 4: delete the nth node from end
    struct ListNode* del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}
