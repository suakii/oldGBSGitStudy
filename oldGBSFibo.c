#include <stdio.h>
/*
 복잡도 분석
 아래 프로그램은 재귀식으로 아주 잘짜여진 코드입니다.
 자 시간 복잡도를 빅오로 이야기 해주세요.^^
*/
int fibo(int n) {
	if (n < 2)
		return 1;
	
	return fibo(n-1) + fibo(n-2);
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", fibo(n));
	return 0;
}
