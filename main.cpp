 // Wordcount.cpp: 定义控制台应用程序的入口点。
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
	//文本处理  
	char text[TEXTLEN + 1];
	char buffer[TEXTBUFFER];
	char endstr[] = "*\n";

	//字符处理  
	const char space = ' ';
	const char quote = '\'';

	//单词处理  
	char words[MAXWORDS][WORDLEN + 1];
	char nword[MAXWORDS];
	char word[WORDLEN + 1];
	int wordlen = 0;
	int wordcount = 0;

	//读取完整文本  
	while (true) {

		//输入缓冲区部分文本,若为endstr,则结束读入.  
		if (strcmp(fgets(buffer, TEXTBUFFER, stdin), endstr) == 0) {
			break;
		}

		//复制到text上.  
		if (strlen(text) + strlen(buffer) + 1 < TEXTLEN) {
			strcat(text, buffer);
		}
		else {
			printf("超出限定最大文本长度.(%d)", TEXTLEN);
			return 1;
		}
	}

	//替换',字母,数字以外的所有符号为空格  
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == quote || isalnum(text[i])) {
			continue;
		}
		text[i] = space;
	}

	//提取单词  
	int index = 0;
	while (true) {

		while (text[index] == space)
			++index;

		if (text[index] == '\0')
			break;

		wordlen = 0;
		while (text[index] == quote || isalnum(text[index])) {
			if (wordlen == WORDLEN) {
				printf("超出单个单词最大长度.(%d)", WORDLEN);
				return 1;
			}
			word[wordlen++] = tolower(text[index++]);
		}
		word[wordlen] = '\0';

		//判定  
		bool isnew = true;
		for (int i = 0; i < wordcount; i++) {
			if (strcmp(words[i], word) == 0) {
				++nword[i];
				isnew = false;
				break;
			}
		}

		//存入数组,并统计  
		if (isnew) {
			strcpy(words[wordcount], word);
			nword[wordcount] = 1;
			wordcount++;
		}
	}

	//输出  
	for (int i = 0; i < wordcount; i++) {
		if (i % 3 == 0)
			printf("\n");
		printf("%-15s%5d ", words[i], nword[i]);
	}
	printf("\n");
	return 0;
}
