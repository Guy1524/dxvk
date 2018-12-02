#ifndef D3D10_1_H
#define D3D10_1_H

/*
 * Copyright 2010 Jacek Caban for CodeWeavers
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

#include <windows.h>

#ifndef _D3D10_1_CONSTANTS
#define _D3D10_1_CONSTANTS
const UINT D3D10_1_DEFAULT_SAMPLE_MASK                     = 0xffffffff;
const UINT D3D10_1_GS_INPUT_REGISTER_COUNT                 = 32;
const UINT D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT     = 32;
const UINT D3D10_1_IA_VERTEX_INPUT_STRUCTURE_ELEMENTS_COMPONENTS = 128;
const UINT D3D10_1_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT = 32;
const UINT D3D10_1_PS_OUTPUT_MASK_REGISTER_COMPONENTS      = 1;
const UINT D3D10_1_PS_OUTPUT_MASK_REGISTER_COMPONENT_BIT_COUNT = 32;
const UINT D3D10_1_PS_OUTPUT_MASK_REGISTER_COUNT           = 1;
const UINT D3D10_1_SHADER_MAJOR_VERSION                    = 4;
const UINT D3D10_1_SHADER_MINOR_VERSION                    = 1;
const UINT D3D10_1_SO_BUFFER_MAX_STRIDE_IN_BYTES           = 2048;
const UINT D3D10_1_SO_BUFFER_MAX_WRITE_WINDOW_IN_BYTES     = 256;
const UINT D3D10_1_SO_BUFFER_SLOT_COUNT                    = 4;
const UINT D3D10_1_SO_MULTIPLE_BUFFER_ELEMENTS_PER_BUFFER  = 1;
const UINT D3D10_1_SO_SINGLE_BUFFER_COMPONENT_LIMIT        = 64;
const UINT D3D10_1_STANDARD_VERTEX_ELEMENT_COUNT           = 32;
const UINT D3D10_1_SUBPIXEL_FRACTIONAL_BIT_COUNT           = 8;
const UINT D3D10_1_VS_INPUT_REGISTER_COUNT                 = 32;
const UINT D3D10_1_VS_OUTPUT_REGISTER_COUNT                = 32;
#endif

#define D3D10_1_FLOAT16_FUSED_TOLERANCE_IN_ULP      (0.6)
#define D3D10_1_FLOAT32_TO_INTEGER_TOLERANCE_IN_ULP (0.6f)

#include <d3d10.h>
#include <d3d10_1shader.h>


typedef enum D3D10_FEATURE_LEVEL1
{
    D3D10_FEATURE_LEVEL_10_0  = 0xa000,
    D3D10_FEATURE_LEVEL_10_1  = 0xa100,
    D3D10_FEATURE_LEVEL_9_1   = 0x9100,
    D3D10_FEATURE_LEVEL_9_2   = 0x9200,
    D3D10_FEATURE_LEVEL_9_3   = 0x9300
} D3D10_FEATURE_LEVEL1;

typedef struct D3D10_RENDER_TARGET_BLEND_DESC1
{
    BOOL BlendEnable;
    D3D10_BLEND SrcBlend;
    D3D10_BLEND DestBlend;
    D3D10_BLEND_OP BlendOp;
    D3D10_BLEND SrcBlendAlpha;
    D3D10_BLEND DestBlendAlpha;
    D3D10_BLEND_OP BlendOpAlpha;
    UINT8 RenderTargetWriteMask;
} D3D10_RENDER_TARGET_BLEND_DESC1;

typedef struct D3D10_BLEND_DESC1
{
    BOOL AlphaToCoverageEnable;
    BOOL IndependentBlendEnable;
    D3D10_RENDER_TARGET_BLEND_DESC1 RenderTarget[D3D10_SIMULTANEOUS_RENDER_TARGET_COUNT];
} D3D10_BLEND_DESC1;

struct ID3D10BlendState1 : public ID3D10BlendState
{
    static constexpr GUID guid = {0xedad8d99,0x8a35,0x4d6d,{0x85,0x66,0x2e,0xa2,0x76,0xcd,0xe1,0x61}};

    virtual void GetDesc1(/*out*/ D3D10_BLEND_DESC1 *pDesc) = 0;
};

typedef struct D3D10_TEXCUBE_ARRAY_SRV1
{
    UINT MostDetailedMip;
    UINT MipLevels;
    UINT First2DArrayFace;
    UINT NumCubes;
} D3D10_TEXCUBE_ARRAY_SRV1;

typedef D3D_SRV_DIMENSION D3D10_SRV_DIMENSION1;

typedef struct D3D10_SHADER_RESOURCE_VIEW_DESC1
{
    DXGI_FORMAT Format;
    D3D10_SRV_DIMENSION1  ViewDimension;
    union {
        D3D10_BUFFER_SRV Buffer;
        D3D10_TEX1D_SRV Texture1D;
        D3D10_TEX1D_ARRAY_SRV Texture1DArray;
        D3D10_TEX2D_SRV Texture2D;
        D3D10_TEX2D_ARRAY_SRV Texture2DArray;
        D3D10_TEX2DMS_SRV Texture2DMS;
        D3D10_TEX2DMS_ARRAY_SRV Texture2DMSArray;
        D3D10_TEX3D_SRV Texture3D;
        D3D10_TEXCUBE_SRV TextureCube;
        D3D10_TEXCUBE_ARRAY_SRV1 TextureCubeArray;
    };
} D3D10_SHADER_RESOURCE_VIEW_DESC1;

struct ID3D10ShaderResourceView1 : public ID3D10ShaderResourceView
{
    static constexpr GUID guid = {0x9b7e4c87,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

    virtual void GetDesc1(/*out*/ D3D10_SHADER_RESOURCE_VIEW_DESC1 *pDesc) = 0;
};

struct ID3D10Device1 : public ID3D10Device
{
    static constexpr GUID guid = {0x9b7e4c8f,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

    virtual HRESULT CreateShaderResourceView1(
            /*in*/ ID3D10Resource *pResource,
            /*inout*/ const D3D10_SHADER_RESOURCE_VIEW_DESC1 *pDesc,
            /*out*/ ID3D10ShaderResourceView1 **ppSRView) = 0;

    virtual HRESULT CreateBlendState1(
            /*in*/ const D3D10_BLEND_DESC1 *pBlendStateDesc,
            /*out*/ ID3D10BlendState1 **ppBlendState) = 0;

    virtual D3D10_FEATURE_LEVEL1 GetFeatureLevel() = 0;
};

const UINT D3D10_1_SDK_VERSION = 0x20;

#endif