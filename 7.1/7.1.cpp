#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

const int n = 100;
char s[n];
char a[n];
char seps[] = " ,.;";
void word(char *, char *);

int main()
{
	printf("enter string with words: ");
	gets_s(s);
	printf("enter string with symbols: ");
	gets_s(a);
	word(s, a);
	system("pause");
}

void word(char *p, char *q)
{
	char *tok;
	char *t;
	char *next = NULL;
	int len = 0;
	int k = 0;
	tok = strtok_s(s, seps, &next);
	t = strtok_s(a, seps, &next);
	while (tok != NULL)
	{
		len = strlen(tok);
		while (t != NULL)
		{
			k = strlen(t);
			if (tok[0] == t[0] && tok[len - 1] == t[0])
				printf("%c\n", tok);
			t = strtok_s(NULL, seps, &next);
		}
		tok = strtok_s(NULL, seps, &next);
	}
}