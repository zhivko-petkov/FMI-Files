#include <iostream>

using namespace std;

static int arrM[10];

int exam(int m, int n, int k)
{
	int first_sum = 0;
	int second_sum = 0;
	_asm {
		mov ebx, n
		add ebx, k
		sub ebx, 1
		mov ecx, 0

		LeftFibb:                                 //sum(Fibonacci(N+K))
		mov eax, [arrM + 4 * ecx]
			add first_sum, eax
			add eax, [arrM + 4 + 4 * ecx]
			mov[arrM + 8 + 4 * ecx], eax
			inc ecx
			cmp ecx, ebx
			jle LeftFibb

			mov ebx, n
			sub ebx, k
			sub ebx, 1
			mov ecx, 0

			RightFibb:								//sum(Fibonacci(N-K))
		mov eax, [arrM + 4 * ecx]
			add second_sum, eax
			add eax, [arrM + 4 * ecx + 4]
			mov[arrM + 4 * ecx + 8], eax
			inc ecx
			cmp ecx, ebx
			jle RightFibb
			jmp Result

			Result :                             //getResult
		mov eax, first_sum
			mov ebx, second_sum
			mov edx, 0
			div ebx
			imul m

	}
}

int main()
{
	arrM[0] = 0;
	arrM[1] = 1;

	cout << exam(3, 6, 2) << endl;

	//other test
	//cout << exam(4, 6, 2) << endl;

	system("pause");
	return 0;
}