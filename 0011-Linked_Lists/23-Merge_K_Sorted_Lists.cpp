#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        int n = arr.size();
        Node* dummy = new Node(-1);

        Node* temp = dummy;
        while (true) {
            int minIndex = -1;
            Node* minNode = nullptr;
            for (int i = 0; i < n; ++i) {
                if (!arr[i])
                    continue;

                if (!minNode) {
                    minIndex = i;
                    minNode = arr[i];
                } else if (arr[i]->data < minNode->data) {
                    minIndex = i;
                    minNode = arr[i];
                }
            }

            if (!minNode)
                break;

            arr[minIndex] = arr[minIndex]->next;

            temp->next = minNode;
            temp = minNode;
        }

        return dummy->next;
    }
};