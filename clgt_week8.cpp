#include<iostream>
using namespace std;
struct node {
    int data;
    struct node* next;
};
node* MakeNode(int x) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void browse(node* head) {
    int cnt = 0;
    bool check = true;
    cout << "y = ";
    while (head != NULL) {
        if (head->data != 0) {
            if (!check && head->data > 0) {
                cout << " + ";
            }
            if (head->data < 0) {
                cout << " - ";
                cout << abs(head->data);
            }
            else {
                cout << head->data;
            }
            if (cnt > 0) {
                cout << "x^" << cnt;
            }
            check = false;
        }
        head = head->next;
        cnt++;
    }
    cout << endl;
}


void InsLast(node*& head, int x) {
    node* newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode; return;
    }
    node* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}


int main() {
    node* head = NULL;
    int n; cout << "nhap bac cua da thuc: ";
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
        cout << "nhap he so cua bac x^" << i << ": ";
        int k;
        cin >> k;
        InsLast(head, k);
    }
    browse(head);

}