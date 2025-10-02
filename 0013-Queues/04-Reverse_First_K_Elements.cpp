#include<bits/stdc++.h>
using namespace std;

class Solution {
    void reverseKElements(queue<int>& q, int k) {
        if(k == 0) {
            return;
        }

        int temp= q.front();
        q.pop();

        reverseKElements(q, k-1);
        q.push(temp);
    }
public:
    queue<int> modifyQueue(queue<int> q, int k) {
        reverseKElements(q, k);

        for(int i=q.size()-k; i>=0; i--) {
            int temp= q.front();
            q.pop();
            q.push(temp);
        }

        return q;
    }
};
