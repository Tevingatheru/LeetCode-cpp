#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *iterator(ListNode *head)
    {
        ListNode *curr = head;
        int size = 0;
        while (curr != nullptr)
        {
            size++;
            curr = curr->next;
        }
        int middle = (size / 2);

        int count = 0;
        ListNode *result = head;
        while (count < middle)
        {
            count++;
            result = result->next;
        }
        return result;
    }

public:
    ListNode *twoPointer(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

ListNode* sampleOne() {
    return new ListNode(1,
                                   new ListNode(2,
                                                new ListNode(3,
                                                             new ListNode(4,
                                                                          new ListNode(5)))));
}

/**
 * Deletes each node to free up memory
*/
void deleteListNode(ListNode *input) {
    while (input != nullptr)
    {
        ListNode *temp = input;
        input = input->next;
        delete temp;
    }
}

int main()
{
    ListNode *input = sampleOne();
    Solution solution;
    ListNode *iteratorResponse = solution.iterator(input);
    ListNode *twoPointerResponse = solution.twoPointer(input);

    cout << "Iterator => Middle node value: " << iteratorResponse->val << endl;
    cout << "Two Pointer => Middle node value: " << twoPointerResponse->val << endl;

    deleteListNode(input);

    return 0;
}
