#include <bits/stdc++.h>
using namespace std;

// The structure of petrolPump is
struct petrolPump {
    int petrol;
    int distance;
};

class Solution {
public:
    int tour(petrolPump p[], int n) {
        int balance= 0, deficit= 0;
        int start= 0;

        for(int i=0; i<n; i++) {
            balance += p[i].petrol - p[i].distance;

            if(balance < 0) {
                deficit += balance;
                start= i+1;
                balance= 0;
            }
        }

        return (balance+deficit >= 0)? start: -1;
    }
};