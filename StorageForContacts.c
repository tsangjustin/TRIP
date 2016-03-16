#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct contactNodeLevel {
	int numChildren_;
	struct contactNodeLevel* children[26];
} Node;


char* findWord(Node* root, char* word) {
	int i;
	int lenSequence = word->length();
	if (lenSequence == 0) {
		// FInd all varitaion from this point
	}
	if (root->numChildren_ == 0) {
		return ""
	}
	for (i = 0; i < lenSequence; ++i) {
		if (== 1) {
			++root.numChildren_;
			root = root.childrenNodes_;
			--lenSequence;
		} else {
			return ;
		}
	}
	return root_->numChildren_;
}

void addWord(Node* root, char* word) {
	if (word.length() > 0) {
		if (root->numChildren_ == 0) {
			add(sequence, root.childrenNodes_)
		} else {
			int lenSequence = sequence.length()
			while (lenSequence-- > 0) {
				++root->numChildren_;
				root->childrenNodes_ = new childrenNodes_;
			}
		}
	}
}

int main() {
	int numCommands;
	scanf("%d\n", &numCommands);

	if (numCommands >= 1 && numCommands <= 100000) {
		Node root_;
		printf("%d\n", root_.numChildren_);
		root_.numChildren_ = 0;
		printf("%d\n", root_.numChildren_);
		int currNum;
		for (currNum = 0; currNum < numCommands; ++currNum) {
			char input[22];
			fgets(input, 22, stdin);
			char* line = strtok(input, " ");
			printf("%d\n", (int)line[0]);
			if (line == "add") {
				//add(root_, strtok(NULL, ""));
				char* word = strtok(NULL, input);
				printf("Adding %s\n", strtok(NULL, word));
				addWord(&root_, word);

			} else if (line == "find") {
				//find(root_, strtok(NULL, ""));
				char* word = strtok(NULL, input);
				printf("Finding %s\n", strtok(NULL, word));
				findWord(&root_, word);
			}
		}

	}
	return 0;
}
