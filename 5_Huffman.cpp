#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Minimum frequency comes first
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Print Huffman codes
void printCode(Node* root, string code) {

    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCode(root->left, code + "0");
    printCode(root->right, code + "1");
}

// Huffman function
void huffman(char ch[], int freq[], int n) {

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters
    for (int i = 0; i < n; i++) {
        pq.push(new Node(ch[i], freq[i]));
    }

    // Build Huffman tree
    while (pq.size() > 1) {

        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    printCode(pq.top(), "");
}

int main() {

    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    char ch[n];
    int freq[n];

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> ch[i];
    }

    cout << "Enter frequencies: ";
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    cout << "\nHuffman Codes:\n";
    huffman(ch, freq, n);

    return 0;
}
