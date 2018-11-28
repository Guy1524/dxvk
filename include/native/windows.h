#ifndef WINDOWS_H
#define WINDOWS_H

#include <inttypes.h>

// barebones windows.h for compatibility

// basic integer definitions
typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned int   DWORD;
typedef unsigned long  ULONG;
typedef long           LONG;
typedef unsigned int   UINT;
typedef int            INT;
typedef int            BOOL;
typedef unsigned char  UINT8;
typedef float          FLOAT;
typedef unsigned short USHORT;
typedef uint64_t       ULONGLONG;
typedef uint64_t       ULONG_PTR;
typedef uint64_t       UINT64;
typedef int64_t        LONGLONG;
typedef ULONG_PTR      SIZE_T;

typedef struct _LARGE_INTEGER {
  LONGLONG QuadPart;
} LARGE_INTEGER;

// more from windef

typedef void  *PVOID;
typedef void  *LPVOID;
typedef PVOID  HANDLE;
typedef HANDLE HMODULE;
typedef HANDLE HMONITOR;
typedef HANDLE HWND;
typedef HANDLE HDC;
typedef HANDLE HINSTANCE;

typedef struct _RECT {
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
} RECT, *PRECT;

typedef struct tagPOINT {
  LONG x;
  LONG y;
} POINT, *PPOINT;

typedef struct tagSIZE
{
    LONG cx;
    LONG cy;
} SIZE, *PSIZE, *LPSIZE;

// strings

typedef const char *LPCSTR;
typedef char *LPSTR;

// errors
typedef LONG HRESULT;

#define S_OK          0
#define E_NOINTERFACE 0x80004002

// COM
#define __uuidof(iface)  iface ## _GUID

struct GUID{
    DWORD Data1;
    WORD  Data2;
    WORD  Data3;
    BYTE  Data4[8];

    bool operator ==(const GUID& other) const
    {
        return this->Data1 == other.Data1
            && this->Data2 == other.Data2
            && this->Data3 == other.Data3
            && (uint64_t)this->Data4 == (uint64_t)other.Data4;
    
    }
};

typedef const GUID& REFIID;
typedef GUID* REFGUID;

// misc.
typedef wchar_t WCHAR;
typedef const WCHAR *LPCWSTR;

typedef struct _SECURITY_ATTRIBUTES {
  DWORD  nLength;
  LPVOID lpSecurityDescriptor;
  BOOL   bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _LUID {
  DWORD LowPart;
  LONG  HighPart;
} LUID, *PLUID;

#define TRUE  1
#define FALSE 0

// custom
#define STDMETHODCALLTYPE

#endif
