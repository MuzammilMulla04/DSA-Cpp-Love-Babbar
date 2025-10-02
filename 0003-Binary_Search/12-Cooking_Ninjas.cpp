#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool ifPossible(vector<int> &ranksOfCooks, int noOfDishes, int newCookingTime) {
	int noOfCooks=0;
	int dishesCompleted=0;
	int dishesAssignedToThisCook=1;
	int timeConsumed=0;
	while(noOfCooks < ranksOfCooks.size()) {
		if(timeConsumed + dishesAssignedToThisCook*ranksOfCooks[noOfCooks] <= newCookingTime) {
			timeConsumed += dishesAssignedToThisCook*ranksOfCooks[noOfCooks];
			dishesAssignedToThisCook++;
			dishesCompleted++;
			if(dishesCompleted == noOfDishes)
				return true;
		} else {
			noOfCooks++;
			timeConsumed=0;
			dishesAssignedToThisCook=1;
		}
	}
	return false;
}
int minCookTime(vector<int> &ranksOfCooks, int noOfDishes) {
	int minimumCookingTime=0;
	int maximumCookingTime=200;
	int minPossibleTime= -1;

	while(minimumCookingTime <= maximumCookingTime) {
		int newCookingTime= minimumCookingTime + (maximumCookingTime-minimumCookingTime)/2;

		if(ifPossible(ranksOfCooks, noOfDishes, newCookingTime)) {
			minPossibleTime= newCookingTime;
			maximumCookingTime= newCookingTime-1;
		} else {
			minimumCookingTime= newCookingTime+1;
		}
	}
	return minPossibleTime;
}

int main() {
	system("cls");

	int noOfCooks, noOfDishes;
	cout << "Enter no. of cooks: ";
	cin >> noOfCooks;
	cout << "Enter no. of dishes: ";
	cin >> noOfDishes;

	vector<int> ranksOfCooks(noOfCooks);
	cout << "Enter ranks of cooks: ";
	for(int i=0; i<noOfCooks; i++)
		cin >> ranksOfCooks[i];

	cout << "Minimum time required to cook " << noOfDishes << " dishes: " << minCookTime(ranksOfCooks, noOfDishes) << endl;

	cout << endl;
	return 0;
}