#include <Windows.h>

int main()
{
	HANDLE hFile;
	DWORD dwWritten;

	CHAR szSystemDir[MAX_PATH];
	GetSystemDirectoryA(szSystemDir, MAX_PATH);
	hFile = CreateFileA("systemroot.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile != INVALID_HANDLE_VALUE)
	{
		if (!WriteFile(hFile, szSystemDir, lstrlenA(szSystemDir), &dwWritten, NULL))
			return GetLastError();
	}
	CloseHandle(hFile);
	return  0;
}