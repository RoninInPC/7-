#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"function.h"
int NotRepeatSymbolInString(char* String) {
	int Arr[128];
	for (int i = 0; i < 128; i++) {
		Arr[i] = 0;
	}
	for (int i = 0; i < strlen(String); i++) {
		Arr[String[i]]++;
	}

	for (int i = 0; i < 128; i++) {
		if (Arr[i] > 1) {
			return 0;
		}
	}
	return 1;
}
Ans BiggestNotRepeatSymbolInString(char* String) {
	char* Ans1 = (char*)malloc(0 * sizeof(char));
	Ans1[0] = '\0';
	for (int i = 0; i < strlen(String)+1; i++) {
		for (int j = i + 1; j < strlen(String)+1; j++) {
			char* A = (char*)malloc(0*sizeof(char));
			int l = 0;
			for (int k = i; k < j; k++) {
				l++;
				A = realloc(A, l * sizeof(char));
				A[l - 1] = String[k];
			}
			A[l] = '\0';
			int k = strlen(A);
			int k1 = strlen(Ans1);
			int h = NotRepeatSymbolInString(A);
			if (h == 1 && k>k1) {
				Ans1 = (char*)realloc(Ans1, k * sizeof(char));
				Ans1 = A;
				
			}
		}
	}
	Ans Answer;
	Answer.Str = Ans1;
	Answer.size = strlen(Ans1);
	return Answer;
}