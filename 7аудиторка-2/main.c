#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "netapi32.lib")
#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <lm.h>
#include <sddl.h>   
int main() {
    int x;
    int size = 0;
    char* c = (char*)malloc(size * sizeof(char));
    while (1) {
        x = getch();
        printf("%c", x);
        if (x == 13) break;
        size++;
        c = realloc(c, size * sizeof(char));
        c[size - 1] = x;
    }
    c[size] = '\0';
    LPUSER_INFO_1 pBuf1 = NULL;
    NET_API_STATUS nStatus;
    nStatus = NetUserGetInfo(NULL, (wchar_t*)c, 1, (LPBYTE*)&pBuf1);
    if (pBuf1 == NULL || nStatus == NERR_Success || nStatus == ERROR_MORE_DATA) {
        wprintf(L"\tUser account name: %s\n", pBuf1->usri1_name);
        wprintf(L"\tPassword age (seconds): %d\n",
            pBuf1->usri1_password_age);
        wprintf(L"\tPrivilege level: %d\n", pBuf1->usri1_priv);
        wprintf(L"\tUser comment: %s\n", pBuf1->usri1_comment);
        wprintf(L"\tFlags (in hex): %x\n", pBuf1->usri1_flags);
        wprintf(L"\tScript path: %s\n", pBuf1->usri1_script_path);
    }
    else
        printf("ERROR");
	return 0;
}