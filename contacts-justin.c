#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct of contactNodeLevel
typedef struct contactNodeLevel {
	long numLetters_;
	struct contactNodeLevel* letters_[26];
} Node;

// Allocates memory in heap for Node
// Instantiates value of numLetters_ = 0
// Pointer of each index in Node array set to NULL
Node* initNode() {
	Node* node = (Node *)malloc(sizeof(Node));
	node->numLetters_ = 0;
	int index;
	for (index = 0; index < 26; ++index) {
		node->letters_[index] = NULL;
	}
	return node;
}

// char* findMatches(Node* root) {
// 	char* matches;
// 	int curr_index = 0;
// 	while (root->numLetters_ > 1 || curr_index < 26) {
// 		if (root->letters_[curr_index++] != NULL) {

// 		}
// 	}
// 	// If letter itself is word added
// 	if (root->numLetters_ > 0) {
// 		matches[curr_index] = "";
// 	}
// }

void addWord(Node* root, char* word) {
	int index = 0;
	if (word[index] != '\0' && word[index] != '\n') {
		int asciiVal;
		while (word[index] != '\0' && word[index] != '\n') {
			asciiVal = (int)word[index] - 97;
			if (root->letters_[asciiVal] == NULL) {
				root->letters_[asciiVal] = initNode();
			}
			++root->numLetters_;
			root = root->letters_[asciiVal];
			++index;
		}
		++root->numLetters_;
	}
}

long findWord(Node* root, char* word) {
	int index = 0;
	if (word[index] != '\0' && word[index] != '\n') {
		int asciiVal;
		while (word[index] != '\0' && word[index] != '\n') {
			asciiVal = (int)word[index] - 97;
			if (root->letters_[asciiVal] == NULL) {
				return 0;
			}
			root = root->letters_[asciiVal];
			++index;
		}
		return root->numLetters_;
	}
	return 0;
}

void freeMemory(Node* root) {
	int i;
	for (i = 0; i < 26 && root->numLetters_ >= 1; ++i) {
		if (root->letters_[i] != NULL) {
			root->numLetters_ -= root->letters_[i]->numLetters_;
			freeMemory(root->letters_[i]);
		}
	}
	free(root);
	root = NULL;
}

int main() {
	long numCommands;
	scanf("%li\n", &numCommands);
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
		int addFunction;
		int findFunction;
		char add[4];
		strcpy(add, "add");
		char find[5];
		strcpy(find, "find");
		for (currNum = 0; currNum < numCommands; ++currNum) {
			char input[27];
			fgets(input, 27, stdin);
			char* line = strtok(input, " ");
			// int i = 0;
			// while (input[i] != '\n') {
			// 	printf("%c\n", input[i++]);
			// }
			addFunction = strcmp(line, add);
			findFunction = strcmp(line, find);
			if (addFunction == 0) {
				line = strtok(NULL, "\0");
				if (line[0] != '\n' && line[0] != '\0') {
					addWord(root_, line);
				}
			} else if (findFunction == 0) {
				line = strtok(NULL, "\0");
				if ((root_->numLetters_ > 0) && 
					(line[0] != '\n'  && line[0] != '\0')) {
					printf("%li\n", findWord(root_, line));
				} else {
					printf("0\n");
				}
			}
		}
		freeMemory(root_);
	}
	return 0;
}
