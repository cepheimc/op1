#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
const int n = 100;
char str[n];
char a[n];
char seps[] = " ,.!?\t\n";
void word(char *, char *);

int main(){
	
	printf("enter string with words: ");
	gets_s(str);
	printf("enter string with symbols : ");
	gets_s(a);
	word(str, a);
	system("pause");
}

void word(char *b,char *c)
{
	char *token;
	char *t;
	char *next = NULL;
	int len = 0;
	int k=0;
	token = strtok_s(b, seps, &next);
	t = strtok_s(c, seps, &next);
	while (token != NULL)
	{
		while (t != NULL)
		{
			k = strlen(a);
			len = strlen(token);
			if (token[0] == t[0] && token[len - 1] == t[0]){
				cout << token << endl;
			}
			t = strtok_s(NULL, seps, &next);
		}
		token = strtok_s(NULL, seps, &next);
	}
}




