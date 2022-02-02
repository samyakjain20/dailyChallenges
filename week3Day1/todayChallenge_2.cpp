#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void insert(Node** root, int item){
	Node *ctr, *temp;
	temp = new Node;
	temp->data = item;
	temp->next = NULL;

	if (*root == NULL)
		*root = temp;
	else {
		ctr = *root;
		while (ctr->next != NULL)
			ctr = ctr->next;
		ctr->next = temp;
	}
}

void printLinkedList(Node* root){
	while (root != NULL) {
		cout << root->data << " ";
		root = root->next;
	}
	cout << endl;
}

int main(){
    int n, x;
    cin>>n;
    	Node *root = NULL;
    for(int i=0; i<n; i++){
        cin>>x;
        insert(&root, x);
    }
	printLinkedList(root);
	return 0;
}