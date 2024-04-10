#include<Windows.h>
#include<iostream>
using namespace std;

struct Numbers {
	int num1;
	int num2;
};

volatile int n;

DWORD WINAPI Add(LPVOID nums)
{
	cout << "Thread is started" << endl;
	Numbers* numbers = (Numbers*)nums;
	n = numbers->num1 + numbers->num2;
	cout << "Thread is finished" << endl;
	return 0;
}

int main()
{
	Numbers nums;
	nums.num1 = 100;
	nums.num2 = 500;

	HANDLE hThread;
	DWORD IDThread;

	cout << "n= " << n << endl;
	hThread = CreateThread(NULL, 0, Add, &nums, 0, &IDThread);

	if (hThread == NULL)
		return GetLastError();

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);

	cout << "n= " << n << endl;

	return 0;
}
