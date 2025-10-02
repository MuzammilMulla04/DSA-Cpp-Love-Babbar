#include <bits/stdc++.h> 
using namespace std;

// BFS
long countOfNumbers(long n) {
    queue<string> q;
    q.push("1");
	
    long count= 0;
    while(!q.empty()) {
        string front= q.front();
        q.pop();

        int num= stol(front);

        if(num <= n) {
            count++;

            q.push(front + '0');
            q.push(front + '1');
        }
    }

	return count;
}