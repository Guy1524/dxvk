#ifndef WINDOWS_H
#define WINDOWS_H

#include <inttypes.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// barebones windows.h for compatibility

// basic integer definitions
typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned int   DWORD;
typedef unsigned long  ULONG;
typedef int32_t        LONG;
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

#define S_OK                    0
#define S_FALSE       (HRESULT) 1
#define E_NOTIMPL     (HRESULT) 0x80004001
#define E_NOINTERFACE (HRESULT) 0x80004002
#define E_FAIL        (HRESULT) 0x80004005
#define E_INVALIDARG  (HRESULT) 0x80070057

#define DXGI_ERROR_INVALID_CALL            (HRESULT) 0x887a0001
#define DXGI_ERROR_NOT_FOUND               (HRESULT) 0x887a0002
#define DXGI_ERROR_MORE_DATA               (HRESULT) 0x887a0003
#define DXGI_ERROR_UNSUPPORTED             (HRESULT) 0x887a0004
#define DXGI_ERROR_WAS_STILL_DRAWING       (HRESULT) 0x887a000a
#define DXGI_ERROR_DRIVER_INTERNAL_ERROR   (HRESULT) 0x887a0020
#define DXGI_ERROR_NOT_CURRENTLY_AVAILABLE (HRESULT) 0x887a0022

#define SUCCEEDED(stat) ((HRESULT)(stat)>=0)
#define FAILED(stat) ((HRESULT)(stat)<0)

// COM
#define __uuidof(iface)  iface::guid

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

    bool operator ==(const GUID* other) const
    {
        return this->Data1 == other->Data1
            && this->Data2 == other->Data2
            && this->Data3 == other->Data3
            && (uint64_t)this->Data4 == (uint64_t)other->Data4;
    
    }
};

typedef const GUID& REFIID;
#define REFGUID const GUID &

/*#define __CRT_UUID_DECL(type,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)           \
    extern "C++" {                                                      \
    template<> inline const GUID &__wine_uuidof<type>() {               \
        static const IID __uuid_inst = {l,w1,w2, {b1,b2,b3,b4,b5,b6,b7,b8}}; \
        return __uuid_inst;                                             \
    }                                                                   \
    template<> inline const GUID &__wine_uuidof<type*>() {              \
        return __wine_uuidof<type>();                                   \
    }                                                                   \
    }

#define __uuidof(type) __wine_uuidof<typeof(type)>()*/

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

#define ENUM_CURRENT_SETTINGS  ((DWORD) -1)

// custom
#define STDMETHODCALLTYPE

#define HWND GLFWwindow*
#define HMONITOR GLFWmonitor*

#define __stdcall

inline bool IsWindow(GLFWwindow* window)
{
  return window != nullptr;
}

#endif
