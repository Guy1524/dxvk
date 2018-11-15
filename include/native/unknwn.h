#ifndef UNKNWN_H
#define UNKNWN_H

#include <windows.h>

#include <atomic>
#include <inttypes.h>

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
};

#endif