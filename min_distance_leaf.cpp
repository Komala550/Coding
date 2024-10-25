#include <iostream>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Function to find the minimum distance to a leaf node starting from the given node
void leaf(Node* x, int val, int* ans) {
    if (x == NULL) return;
    if (!x->left && !x->right) {
        *ans = min(*ans, val);
        return;
    }
    leaf(x->left, val + 1, ans);
    leaf(x->right, val + 1, ans);
}

// Function to find the minimum distance to a leaf node from the target node's parent nodes
bool parent(Node* root, Node* x, int* ans) {
    if (root == NULL) return false;
    if (root == x) return true;

    bool l = parent(root->left, x, ans);
    if (l) {
        leaf(root->right, 2, ans);
        return true;
    }

    bool r = parent(root->right, x, ans);
    if (r) {
        leaf(root->left, 2, ans);
        return true;
    }

    return false;
}

// Wrapper function to find minimum distance to any leaf from the target node x
void solve(Node* root, Node* x) {
    int ans = INT_MAX;
    leaf(x, 0, &ans);
    parent(root, x, &ans);
    cout << "Minimum distance to a leaf from node " << x->data << ": " << ans << endl;
}

// Function to create the binary tree based on inputs
Node* buildTree(unordered_map<int, Node*>& nodes, int rootData, int n) {
    for (int i = 0; i < n; i++) {
        int parentData, leftData, rightData;
        cout << "Enter parent node, left child, and right child (use -1 for NULL): ";
        cin >> parentData >> leftData >> rightData;

        // Get or create the parent node
        Node* parentNode = nodes[parentData];
        if (parentNode == NULL) {
            parentNode = new Node(parentData);
            nodes[parentData] = parentNode;
        }

        // Attach left child
        if (leftData != -1) {
            Node* leftNode = nodes[leftData];
            if (leftNode == NULL) {
                leftNode = new Node(leftData);
                nodes[leftData] = leftNode;
            }
            parentNode->left = leftNode;
        }

        // Attach right child
        if (rightData != -1) {
            Node* rightNode = nodes[rightData];
            if (rightNode == NULL) {
                rightNode = new Node(rightData);
                nodes[rightData] = rightNode;
            }
            parentNode->right = rightNode;
        }
    }
    return nodes[rootData];
}

int main() {
    int n, rootData, targetData;
    cout << "Enter number of nodes in the tree: ";
    cin >> n;
    cout << "Enter the root node data: ";
    cin >> rootData;

    unordered_map<int, Node*> nodes;
    Node* root = buildTree(nodes, rootData, n);

    cout << "Enter target node data: ";
    cin >> targetData;
    Node* targetNode = nodes[targetData];

    if (targetNode != NULL) {
        solve(root, targetNode);
    } else {
        cout << "Target node not found in the tree." << endl;
    }

    return 0;
}
