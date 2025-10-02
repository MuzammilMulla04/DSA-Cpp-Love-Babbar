#include <iostream>
using namespace std;

bool isPossible(int arr[], int noOfBooks, int noOfStudents, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < noOfBooks; i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        } else {
            studentCount++;
            if (studentCount > noOfStudents || arr[i] > mid)
                return false;
            pageSum = arr[i];
        }
    }
    return true;
}
int bookAllocation(int arr[], int noOfBooks, int noOfStudents) {
    if (noOfBooks < noOfStudents)
        return -1;
    int start = 0;
    int end;
    for (int i = 0; i < noOfBooks; i++) {
        end += arr[i];
    }
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, noOfBooks, noOfStudents, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    system("cls");

    int noOfStudents, noOfBooks;
    cout << "Enter no. of Books: ";
    cin >> noOfBooks;
    cout << "Enter no. of Students: ";
    cin >> noOfStudents;

    int arr[noOfBooks];
    cout << "Enter pages of each book: ";
    for (int i = 0; i < noOfBooks; i++)
        cin >> arr[i];

    cout << "Minimum Pages: " << bookAllocation(arr, noOfBooks, noOfStudents) << endl;

    cout << endl;
    return 0;
}