#include <stdio.h>
#include <string.h>
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
	int asciiVal;
	while (word[index] != '\0' && word[index] != '\n') {
		asciiVal = (int)word[index] - 97;
		if (root->letters_[asciiVal] != NULL) {
			++root->numLetters_;
			root = root->letters_[asciiVal];
			++index;
		} else {
			break;
		}
	}
	while (word[index] != '\0' && word[index] != '\n') {
		root->letters_[asciiVal] = initNode();
		++root->numLetters_;
		root = root->letters_[asciiVal];
		asciiVal = (int)word[++index] - 97;
	}
	++root->numLetters_;
}

int findWord(Node* root, char* word) {
	int index = 0;
	int asciiVal;
	while (word[index] != '\0' && word[index] != '\n') {
		asciiVal = (int)word[index] - 97;
		if (root->letters_[asciiVal] != NULL) {
			root = root->letters_[asciiVal];
			++index;
		} else {
			return 0;
		}
	}
	return root->numLetters_;
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
		char add[4];
		strcpy(add, "add");
		char find[5];
		strcpy(find, "find");
		for (currNum = 0; currNum < numCommands; ++currNum) {
			char input[22];
			fgets(input, 22, stdin);
			char* line = strtok(input, " ");
			// int i = 0;
			// while (input[i] != '\n') {
			// 	printf("%c\n", input[i++]);
			// }
			int function = strcmp(line, add);
			if (function == 0) {
				line = strtok(NULL, "\0");
				if (line[0] != '\n' && line[0] != '\0') {
					addWord(root_, line);
				}
			} 
			function = strcmp(line, find);
			if (function == 0) {
				line = strtok(NULL, "\0");
				if ((root_->numLetters_ > 0) && 
					(line[0] != '\n'  && line[0] != '\0')) {
					printf("%d\n", findWord(root_, line));
				}
			}
		}
		freeMemory(root_);
	}
	return 0;
}
