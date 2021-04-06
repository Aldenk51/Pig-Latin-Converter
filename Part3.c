#include <stdio.h>
#include <string.h>

char* toPigLatin (char* word) {
	char vowels[] = "aeiouAEIOU";
	char vowelsWithY[] = "aeiouyAEIOUY";
	if(!strcspn(word, vowels)) {
		if(word[0] >= 'a' && word[0] <= 'z') {
			word[0] -= 32;
		}
		return strcat(word, "way");
	}
	if(word[0] >= 'A' && word[0] <= 'Z') {
		word[0] += 32;
	}
	strncat(word, word, strcspn(word, vowelsWithY) );
	memmove(&word[0], &word[strcspn(word, vowelsWithY)], strlen(word) - strcspn(word, vowelsWithY) + 1);
	strcat(word, "ay");
	if(word[0] >= 'a' && word[0] <= 'z') {
		word[0] -= 32;
	}
	return word;
}
int main() {
	int i;
	char input[39];
	for(i = 0; i < 5; i ++) {
		printf("Input: ");
		scanf(" %s", &input);
		printf("Output: %s\n", toPigLatin(input) );
	}
	return 0;
}
