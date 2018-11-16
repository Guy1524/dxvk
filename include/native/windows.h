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

// misc.
typedef wchar_t WCHAR;

#endif