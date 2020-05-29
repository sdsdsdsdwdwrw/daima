#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int c_no;
	int p_id;
	int p;
	int time;
}process;
void run(process *pram,int w)
{
	pram[w].c_no;
	printf("id=%d,youxiandu=%d\n", pram[w].p_id,pram[w].p);
};
void sort(process *p, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (p[i].p < p[j].p) {
				process a;
				a = p[i];
				p[i] = p[j];
				p[j] = a;
			}
		}
	}
}
int main() {
	
	//printf("a=%d,b=%d,c=%d", a,b,c);
	process s[5];
	for (int i = 0; i < 5; i++) {
		int a, b, c,d;
		scanf("%d%d%d%d", &a, &b, &c,&d);
		s[i].c_no = a;
		s[i].p_id = b;
		s[i].p = c;
		s[i].time = d;
	}//xianchengchi
	sort(s, 5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < s[i].time; j++) {
			run(s, i);
		}
	}
  
	
	return 0;
}
