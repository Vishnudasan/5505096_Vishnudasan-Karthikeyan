typedef struct Trie {
    struct Trie* child[26];
    bool end;
} Trie;

Trie* createNode() {
    Trie* node = (Trie*)malloc(sizeof(Trie));
    for (int i = 0; i < 26; i++){
	node->child[i] = NULL;
    	node->end = false;
   	 return node;
}

bool insert(Trie* root, char* word) {
    Trie* cur = root;
    for (int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';
        if (!cur->child[idx]){
	cur->child[idx] = createNode();
        cur = cur->child[idx];
        if (cur->end) return false;
    }
    for (int j = 0; j < 26; j++){
	 if (cur->child[j]){
		 return false;
    	cur->end = true;
   	 return true;
}

void noPrefix(int words_count, char** words) {
    Trie* root = createNode();
    for (int i = 0; i < words_count; i++) {
        if (!insert(root, words[i])) {
            printf("BAD SET\n%s\n", words[i]);
            return;
        }
    }
    printf("GOOD SET\n");
}
