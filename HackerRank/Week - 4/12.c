typedef struct node {
    int freq;
    char data;
    struct node *left;
    struct node *right;
} node;

node* newNode(char data, int freq) {
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->freq = freq;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void decode_huff(node *root, char *s) {
    node *curr = root;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '0') {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
        if (curr->left == NULL && curr->right == NULL) {
            printf("%c", curr->data);
            curr = root;
        }
    }
    printf("\n");
}