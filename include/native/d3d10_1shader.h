/*
 * Copyright 2010 Rico Schüller
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef D3D10_1SHADER_H
#define D3D10_1SHADER_H

#include <windows.h>

#include "d3d10shader.h"

struct ID3D10ShaderReflection1 : public IUnknown
{
    static constexpr GUID guid = {0xc3457783,0xa846,0x47ce,{0x95,0x20,0xce,0xa6,0xf6,0x6e,0x74,0x47}};

    /* ID3D10ShaderReflection1 methods */
    virtual void GetDesc(D3D10_SHADER_DESC *desc) = 0;
    virtual struct ID3D10ShaderReflectionConstantBuffer* GetConstantBufferByIndex(UINT index) = 0;
    virtual struct ID3D10ShaderReflectionConstantBuffer* GetConstantBufferByName(const char *name) = 0;
    virtual void                                         GetResourceBindingDesc(UINT index, D3D10_SHADER_INPUT_BIND_DESC *desc) = 0;
    virtual void                                         GetInputParameterDesc(UINT index, D3D10_SIGNATURE_PARAMETER_DESC *desc) = 0;
    virtual void                                         GetOutputParameterDesc(UINT index, D3D10_SIGNATURE_PARAMETER_DESC *desc) = 0;
    virtual struct ID3D10ShaderReflectionVariable*       GetVariableByName(const char *name) = 0;
    virtual void                                         GetResourceBindingDescByName(const char *name, D3D10_SHADER_INPUT_BIND_DESC *desc) = 0;
    virtual void                                         GetMovInstructionCount(UINT *count) = 0;
    virtual void                                         GetMovcInstructionCount(UINT *count) = 0;
    virtual void                                         GetConversionInstructionCount(UINT *count) = 0;
    virtual void                                         GetBitwiseInstructionCount(UINT *count) = 0;
    virtual void                                         GetGSInputPrimitive(D3D10_PRIMITIVE *prim) = 0;
    virtual void                                         IsLevel9Shader(BOOL *level9shader) = 0;
    virtual void                                         IsSampleFrequencyShader(BOOL *samplefrequency) = 0;
};

#endif