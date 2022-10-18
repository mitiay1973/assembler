#include <stdio.h>
#include <locale.h>
#include <time.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int a = 5;
	int b = 2; 
	int c = 8;
	int f = 1000000000;
	for (size_t i = 0; i < f; i++)
	{
		sloz(a, b);
	}	
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		 vicitanie(a, b);
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		 ymn(a, b);
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		 del(a, b);
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		ostatok(a, b);
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
	 sravnenie(a, b);
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		 sravnenie3(a, b, c); 
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		swap(a, b);
	}
	printf_s("Время выполнения %d\n\n", clock());

	for (size_t i = 0; i < f; i++)
	{
		slozCi(a, b);
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		 vicitanieCi(a, b);
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		 ymnCi(a, b);
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		 delCi(a, b);
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		 ostatokCi(a, b);
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		 sravnenieCi(a, b);
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		 sravnenie3Ci(a, b, c);
	}
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		swapCi(a, b);
	}
	printf_s("Время выполнения %d\n", clock());
	return 0;
}
int sloz(int a,int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		add eax, ebx
		mov c, eax
	}
	return c;
}
int vicitanie(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		sub eax, ebx
		mov c, eax
	}
	return c;
}
int ymn(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		imul eax, ebx
		mov c, eax
	}
	return c;
}
int del(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		xor edx,edx
		idiv ebx
		mov c, eax
	}
	return c;
}
int ostatok(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		xor edx, edx
		idiv ebx
		mov c, eax
		imul eax, ebx
		mov ebx, a
		sub ebx, eax
		mov c, ebx
	}
	return c;
}
int sravnenie(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		cmp eax, ebx; 
		je equal
		jg greater
		jmp less
		equal:
		mov c, 0
			jmp exit
			greater :
			mov c, 1
			jmp exit
			less :
			mov c, 2
			jmp exit
			exit:
	}
	return c;
}
int sravnenie3(int a, int b, int c)
{
	_asm
	{
		mov eax, a
		mov ebx, b
		mov ecx, c
		cmp eax, ebx
		je equal
		jg greater
		jmp less


		equal :
		cmp eax, ecx
			je equal2
			jg greater2
			jmp less2

			greater :
		cmp eax, ecx
			je equal2
			jg greater2
			jmp less2

			less :
		cmp ebx, ecx
			je equal2
			jg greater3
			jmp less2

			equal2 :

		mov a, 0
			jmp exit

			greater2 :
		mov a, 1
			jmp exit

			less2 :
		mov a, 3
			jmp exit

			greater3 :
		mov a, 2
			jmp exit

			exit :
	}
	return a;
}
int swap(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b

		mov ecx, eax
		mov eax, ebx
		mov ebx, ecx

		mov a, eax
		mov b, ebx

	}
	//printf_s("a = %d, b = %d\n", a, b);
}
int slozCi(int a, int b)
{
	return a + b;
}
int vicitanieCi(int a, int b)
{
	return a - b;
}
int ymnCi(int a, int b)
{
	return a * b;
}
int delCi(int a, int b)
{
	return a / b;
}
int ostatokCi(int a, int b)
{
	int pr = a / b;
	return a - pr*b;
}
int sravnenieCi(int a, int b)
{
	if (a > b)
	{
		return 1;
	}
	else if (a < b)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}
int sravnenie3Ci(int a, int b, int c)
{
	if (a > b && a>c)
	{
		return 1;
	}
	else if (b>a && b>c)
	{
		return 2;
	}
	else if (c>a && c>b)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}
int swapCi(int a, int b)
{
	int a1 = a;
	int b1 = b;
	a = b1;
	b = a1;
	//printf_s("a = %d, b = %d\n", a, b);
}