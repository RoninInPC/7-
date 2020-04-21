#include"function.h"
#include<stdio.h>
int main() {
	FILE* f;
	fopen_s(&f, "input.txt", "r");
	fseek(f, SEEK_END, 0);
	int size = ftell(f);
	fseek(f, SEEK_SET, 0);
	char* Ans1 = (char*)malloc(size * sizeof(char));
	for (int i = 0; i < size; i++) {
		fscnaf_s("%c", &Ans1[i]);
	}
	Ans1[size] = '\0';
	flcose(f);
	Ans Answ = BiggestNotRepeatSymbolInString(Ans1);
	printf("%s", Answ.Str);
	fopen_s(&f, "input1.txt", "w");
	fprintf("%s", Answ.Str);
	fclose(f);
	return 0;
}