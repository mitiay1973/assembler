#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int a = 5;
	int b = 2; 
	printf_s("Сложение  %d\n", sloz(a, b));
	printf_s("Вычитание %d\n", vicitanie(a, b));
	printf_s("Умножение %d\n", ymn(a, b));
	printf_s("Деление %d\n", del(a, b));
	printf_s("Остаток %d\n", ostatok(a, b));
	printf_s("%d число больше\n", sravnenie(a, b));
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
			greater :
			mov c, 1
			less :
			mov c, 2
			exit:
	}
	return c;
}