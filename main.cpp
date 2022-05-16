 // Wordcount.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include <stdio.h>  
#include <string.h>  
#include <stdbool.h>  
#include <ctype.h>  

#define TEXTLEN 10000  
#define TEXTBUFFER 100  
#define MAXWORDS 500  
#define WORDLEN 15  

int main() {
	//�ı�����  
	char text[TEXTLEN + 1];
	char buffer[TEXTBUFFER];
	char endstr[] = "*\n";

	//�ַ�����  
	const char space = ' ';
	const char quote = '\'';

	//���ʴ���  
	char words[MAXWORDS][WORDLEN + 1];
	char nword[MAXWORDS];
	char word[WORDLEN + 1];
	int wordlen = 0;
	int wordcount = 0;

	//��ȡ�����ı�  
	while (true) {

		//���뻺���������ı�,��Ϊendstr,���������.  
		if (strcmp(fgets(buffer, TEXTBUFFER, stdin), endstr) == 0) {
			break;
		}

		//���Ƶ�text��.  
		if (strlen(text) + strlen(buffer) + 1 < TEXTLEN) {
			strcat(text, buffer);
		}
		else {
			printf("�����޶�����ı�����.(%d)", TEXTLEN);
			return 1;
		}
	}

	//�滻',��ĸ,������������з���Ϊ�ո�  
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == quote || isalnum(text[i])) {
			continue;
		}
		text[i] = space;
	}

	//��ȡ����  
	int index = 0;
	while (true) {

		while (text[index] == space)
			++index;

		if (text[index] == '\0')
			break;

		wordlen = 0;
		while (text[index] == quote || isalnum(text[index])) {
			if (wordlen == WORDLEN) {
				printf("��������������󳤶�.(%d)", WORDLEN);
				return 1;
			}
			word[wordlen++] = tolower(text[index++]);
		}
		word[wordlen] = '\0';

		//�ж�  
		bool isnew = true;
		for (int i = 0; i < wordcount; i++) {
			if (strcmp(words[i], word) == 0) {
				++nword[i];
				isnew = false;
				break;
			}
		}

		//��������,��ͳ��  
		if (isnew) {
			strcpy(words[wordcount], word);
			nword[wordcount] = 1;
			wordcount++;
		}
	}

	//���  
	for (int i = 0; i < wordcount; i++) {
		if (i % 3 == 0)
			printf("\n");
		printf("%-15s%5d ", words[i], nword[i]);
	}
	printf("\n");
	return 0;
}
