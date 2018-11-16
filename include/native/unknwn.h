#ifndef UNKNWN_H
#define UNKNWN_H

#include <windows.h>

#include <atomic>
#include <inttypes.h>

const GUID IUnknown_GUID = {0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

struct IUnknown
{
    std::atomic<uint32_t> m_refCount;

    IUnknown()
    {
        m_refCount = 1;
    }

    virtual ~IUnknown()
    {
        /* Implemented by child interfaces */
    }

    ULONG AddRef()
    {
        return ++m_refCount;
    }

    ULONG Release()
    {
        m_refCount--;

        if(!m_refCount)
        {
            delete this;
            return 0;
        }

        return m_refCount;
    }

    virtual HRESULT QueryInterface(REFIID riid, void **ppvObject)
    {
        *ppvObject = nullptr;

        if( riid == __uuidof(IUnknown))
        {
            *ppvObject = this;
            return S_OK;
        }

        return E_NOINTERFACE;
    }
};

#endif