#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[26][2];
int n;

void preorder(int idx) {
	if (idx < 0) return;
	cout << char(idx + 'A');
	preorder(arr[idx][0]);
	preorder(arr[idx][1]);
}

void inorder(int idx) {
	if (idx < 0) return;
	inorder(arr[idx][0]);
	cout << char(idx + 'A');
	inorder(arr[idx][1]);
}

void postorder(int idx) {
	if (idx < 0) return;
	postorder(arr[idx][0]);
	postorder(arr[idx][1]);
	cout << char(idx + 'A');
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char node, left, right;
		cin >> node >> left >> right;
		arr[node-'A'][0] = left-'A';
		arr[node-'A'][1] = right-'A';
	}
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
}