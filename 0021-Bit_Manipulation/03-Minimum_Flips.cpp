#include <bits/stdc++.h>
using namespace std;

int minimumFlips(int a, int b, int c) {
	bitset<32> bitA(a);
	bitset<32> bitB(b);
	bitset<32> bitC(c);

	int flipCount= 0;
	for(int i=0; i<32; i++) {
		if(bitC[i] == 0) {
			if(bitA[i] == 1)
				flipCount++;
			if(bitB[i] == 1)
				flipCount++;
		} else {
			if(bitA[i] == 0 && bitB[i] == 0)
				flipCount++;
		}
	}

	return flipCount;
}