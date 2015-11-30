#include <stdio.h>
/*
 복잡도 분석
 아래 프로그램은 재귀식으로 아주 잘짜여진 코드입니다.
 자 시간 복잡도를 빅오로 이야기 해주세요.^^
*/

/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/
/*fork test*/



#define MAX 100
int arr[MAX];
int ma[2][2]={{1,1}, {1,0}};

//재귀, 시간복잡도=O(n!)
int fibo(int n) {
	if (n < 2)
		return 1;

	return fibo(n-1) + fibo(n-2);
}

//동적계획법, 시간복잡도=O(n)
int fibo2(int n){
    if(n<2) return 1;
    int a[n], i;
    a[0]=a[1]=1;
    for(i=2; i<=n; i++){
        a[i]=a[i-1]+a[i-2];
    }
    return a[n];
}

//메모이제이션, 시간복잡도=O(n)
int fibo3(int n){
    if(n<2) return 1;
    if(arr[n]!=0) return arr[n];
    else return arr[n] = fibo3(n-1) + fibo3(n-2);
}


//행렬계산, 시간복잡도=O(log(n))
void mul(int a[2][2], int b[2][2]){
    int temp1 = a[0][0]*b[0][0]+a[0][1]*b[1][0];
    int temp2 = a[0][0]*b[0][1]+a[0][1]*b[1][1];
    int temp3 = a[1][0]*b[0][0]+a[1][1]*b[1][0];
    int temp4 = a[1][0]*b[0][1]+a[1][1]*b[1][1];

    a[0][0]=temp1;
    a[0][1]=temp2;
    a[1][0]=temp3;
    a[1][1]=temp4;
}

void pow(int a[2][2], int n){ //행렬거듭제곱
    if(n==0){
        a[0][0]=1;
        a[0][1]=0;
        a[1][0]=0;
        a[1][1]=1;
    }
    if(n==1) return;
    if(n%2==0){
        pow(a,n/2);
        mul(a,a);
    }else{
        int b[2][2]={{1,1}, {1,0}};
        pow(a,n-1);
        mul(a,b);
    }
}

int fibo4(int n){
    if(n<2) return 1;
    pow(ma,n);
    return ma[0][0];
}


int main() {
	int n;
	scanf("%d", &n);
	printf("recursion : %d\n", fibo(n));
	printf("dynamic programming : %d\n", fibo2(n));
	printf("memoization : %d\n", fibo3(n));
	printf("matrix : %d\n", fibo4(n));


	return 0;
}
