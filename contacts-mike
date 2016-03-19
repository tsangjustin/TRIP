#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Struct of contactNodeLevel
typedef struct contactNodeLevel {
    int numLetters_;
    struct contactNodeLevel* letters_[26];
} Node;

// Allocates memory in heap for Node
// Instantiates value of numLetters_ = 0
// Pointer of each index in Node array set to NULL
Node* initNode() {
    Node* node = malloc(sizeof(Node));
    node->numLetters_ = 0;
    int index;
    for (index = 0; index < 26; ++index) {
        node->letters_[index] = NULL;
    }
    return node;
}

char* findMatches(Node* root) {
    char* matches;
    int curr_index = 0;
    while (root->numLetters_ > 0) {
        if (root->letters_[curr_index] != NULL) {

        }
    }
}

void addWord(Node* root, char* word) {
    if (word[0] != '\0') {
        int index = 0;
        int asciiVal;
        while ((word[index + 1] != '\0') &&
               (root->letters_[asciiVal] != NULL)) {
            asciiVal = (int)word[index++] - 97;
            ++root->numLetters_;
            root = root->letters_[asciiVal];
        }
        while (word[index] != '\0') {
            asciiVal = (int)word[index++] - 97;
            root->letters_[asciiVal] = initNode();
            ++root->numLetters_;
            root = root->letters_[asciiVal];
        }
    }
}

char* findWord(Node* root, char* word) {
    char* output;
    if (word[0] != '\0') {
        int index = 0;
        int asciiVal = (int)word[index++] - 97;
        while ((word[index + 1] != '\0') && (root != NULL)) {
            root = root->letters_[asciiVal];
        }
        if (root->numLetters_ > 0) {
            output = findMatches(root);
        }
    }
    return output;
}

void freeMemory(Node* root) {
    if (root->numLetters_ > 0) {
        int i;
        for (i = 0; i < 26 && root->numLetters_ > 0; ++i) {
            if (root->letters_[i] != NULL) {
                root->numLetters_ -= root->letters_[i]->numLetters_;
                freeMemory(root->letters_[i]);
            }
        }
    }
    free(root);
    root = NULL;
}

int main() {
    int numCommands;
    scanf("%d\n", &numCommands);
    if (numCommands >= 1 && numCommands <= 100000) {
        Node* root_ = initNode();
        // printf("%p\n", root_->letters_[22]);
        // Node* child = malloc(sizeof(Node));
        // root_->letters_[4] = child;
        // if (root_->letters_[4] == NULL) {
        // 	printf("%p\n", root_->letters_[4]);
        // }
        //printf("%d\n", root_->letters_[4]->numLetters_);
        //Node* child = malloc(sizeof(Node));
        //root_->letters_[0] = child;
        //printf("%p\n", root_->letters_[0]->letters_);
        int currNum;
        for (currNum = 0; currNum < numCommands; ++currNum) {
            char input[22];
            fgets(input, 22, stdin);
            char* line = strtok(input, " ");
            // int i = 0;
            // while (input[i] != '\n') {
            // 	printf("%c\n", input[i++]);
            // }
            if (strcmp(line, "add") == 0) {
                char* word = strtok(NULL, " ");
                if (input[0] != '\n') {
                    printf("Adding %s\n", word);
                    addWord(root_, word);
                }
            } else if (strcmp(line, "find") == 0) {
                char* word = strtok(NULL, " ");
                if ((root_->numLetters_ > 0) && (input[0] != '\n')) {
                    printf("Finding %s\n", word);
                    findWord(root_, word);
                }
            }
        }
        freeMemory(root_);
    }
    return 0;
}
