#include <iostream>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
};

Node* createNode(char ch, int freq, Node* left = nullptr, Node* right = nullptr) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

void printCodes(Node* root, char code[], int top, string codes[], int sizes[], int& index) {
    if (root->left == nullptr && root->right == nullptr) {
        codes[index] = string(code, top); 
        sizes[index] = top;
        index++; 
        return;
    }

    if (root->left != nullptr) {
        code[top] = '0';
        printCodes(root->left, code, top + 1, codes, sizes, index);
    }

    if (root->right != nullptr) {
        code[top] = '1';
        printCodes(root->right, code, top + 1, codes, sizes, index);
    }
}

void sortNodes(Node* nodes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nodes[i]->freq > nodes[j]->freq) {
                Node* temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }
}

Node* buildHuffmanTree(int n, char characters[], int frequencies[]) {
    Node* nodes[100];

    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(characters[i], frequencies[i]);
    }

    while (n > 1) {
        sortNodes(nodes, n);

        Node* left = nodes[0];
        Node* right = nodes[1];
        Node* parent = createNode('#', left->freq + right->freq, left, right);

        for (int i = 2; i < n; i++) {
            nodes[i - 2] = nodes[i];
        }

        nodes[n - 2] = parent;
        n--;
    }

    return nodes[0];
}

int main() {
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    char characters[100];
    int frequencies[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter character " << i + 1 << ": ";
        cin >> characters[i];
        cout << "Enter frequency of " << characters[i] << ": ";
        cin >> frequencies[i];
    }

    Node* root = buildHuffmanTree(n, characters, frequencies);

    char code[100];
    string codes[100]; 
    int sizes[100]; 
    int index = 0; 

    printCodes(root, code, 0, codes, sizes, index);

    cout << "\nCharacter Frequency Code Size\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << characters[i] << "\t"
             << frequencies[i] << "\t"
             << codes[i] << "\t"
             << sizes[i] << endl;
    }

    return 0;
}
