#include <stdio.h>
#include <string.h>

/* Put function prototypes for ARM assembly code and corresponding C code here */
int sum_a(int a, int b);
int sum_c(int a, int b);
int sum_array(int a[], int n);
int find_max(int a[], int n);
int fib_rec(int n);
int fib_iter_C(int n);
int fib_iter(int n);
int fib_rec_C(int n);
int sum_array_C(int a[], int n);
int find_max_C(int a[], int n);
int find_str_C(char a[], char b[]);
int find_str(char a[], char b[]);



/* Put test functions here */

void test_sum(void)
{
    printf("sum_a(0, 0) = %d [%d]\n", sum_a(0,0), sum_a(0,0) == 0);
    printf("sum_c(0, 0) = %d [%d]\n", sum_c(0,0), sum_c(0,0) == 0);    
}

void test_sum_array(void){
	int a[] = {1, 2, 3, 4};
	int a1[] = {-1, -2, -3, -4};
	int a2[] = {0, 0, 0, 0};
	int a3[1000];
	int i;
	for (i = 0; i < 1000; ++i)
	{
		a3[i] = 1;
	}
	printf("Test_sum_array Positive #s in C: ");
	printf("%d\n", sum_array_C(a, 4));
	printf("Test_sum_array Negative #s in C: ");
	printf("%d\n", sum_array_C(a1, 4));
	printf("Test_sum_array Zero #s in C: ");
	printf("%d\n", sum_array_C(a2, 4));
	printf("Test_sum_array 1000 #s in C: ");
	printf("%d\n", sum_array_C(a3, 1000));
	
	printf("Test_sum_array Positive #s in ARM: ");
	printf("%d\n", sum_array(a, 4));
	printf("Test_sum_array Positive #s in ARM: ");
	printf("%d\n", sum_array(a1, 4));
	printf("Test_sum_array Positive #s in ARM: ");
	printf("%d\n", sum_array(a2, 4));
	printf("Test_sum_array Positive #s in ARM: ");
	printf("%d\n\n", sum_array(a3, 1000));

}

void test_find_max(void){
	int a[] = {1, 2, 3, 4};
	int a1[] = {-1, -2, -3, -4};
	int a2[] = {0, 0, 0, 0};
	int a3[1000];
	int i;
	for (i = 0; i < 998; ++i)
	{
		a3[i] = 1;
	}a3[999] = 6;
	printf("Test_Find_Max Positive #s in C: ");
	printf("%d\n", find_max_C(a, 4));
	printf("Test_Find_Max Negative #s in C: ");
	printf("%d\n", find_max_C(a1, 4));
	printf("Test_Find_Max Zero #s in C: ");
	printf("%d\n", find_max_C(a2, 4));
	printf("Test_Find_Max 1000 #s in C: ");
	printf("%d\n", find_max_C(a3, 1000));

	printf("Test_Find_Max Positive #s in ARM: ");
	printf("%d\n", find_max(a, 4));
	printf("Test_Find_Max Negative #s in ARM: ");
	printf("%d\n", find_max(a1, 4));
	printf("Test_Find_Max Zero #s in ARM: ");
	printf("%d\n", find_max(a2, 4));
	printf("Test_Find_Max 1000 #s in ARM: ");
	printf("%d\n\n", find_max(a3, 1000));

}

void test_fib_rec(int n){
	printf("RECURSIVE: \n");
	printf("The fibonacci series for %d in C: ", n);
	int i;
	for(i=0;i<=n;i++){
	   printf(" %d ", fib_rec_C(i));
	}printf("\n");
	printf("The fibonacci series for %d in ARM: ", n);
	for(i=0;i<=n;i++){
	   printf(" %d ", fib_rec(i));
	}printf("\n");
}

void test_fib_iter(int n){
	printf("\nITERATIVE: ");
	printf("\nThe fibonacci series for %d in C:  ", n);
	int i;
	for(i=0;i<=n;i++){
	   printf(" %d ", fib_iter_C(i));
	}
	printf("\nThe fibonacci series for %d in ARM:  ", n);
	for(i=0;i<=n;i++){
	   printf(" %d ", fib_iter(i));
	}printf("\n\n");
}

void test_find_str(){
	char a[] = "MyNameIsAlec";
	char b[] = "Is";
	printf("Find %s inside %s using C: ", b, a);
	printf("%d\n", find_str_C(a, b));

	printf("Find %s inside %s using ARM: ", b, a);
	printf("%d\n", find_str(a, b));

	
}

void print(char c){
	printf("%c", c);
}

int main(int argc, char **argv){
    //test_sum();
    test_sum_array();
    test_find_max();
	test_fib_rec(20);
	test_fib_iter(20);
	test_find_str();
}
