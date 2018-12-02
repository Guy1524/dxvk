#ifndef D3D10_H
#define D3D10_H

/*
 * Copyright 2007 Andras Kovacs
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

#include <dxgi.h>
#include <d3dcommon.h>

/* forward declarations */
struct ID3D10Device;

#ifndef _D3D10_CONSTANTS
#define _D3D10_CONSTANTS
const float D3D10_DEFAULT_BLEND_FACTOR_ALPHA                                            = 1.0;
const float D3D10_DEFAULT_BLEND_FACTOR_BLUE                                             = 1.0;
const float D3D10_DEFAULT_BLEND_FACTOR_GREEN                                            = 1.0;
const float D3D10_DEFAULT_BLEND_FACTOR_RED                                              = 1.0;
const float D3D10_DEFAULT_BORDER_COLOR_COMPONENT                                        = 0.0;
const float D3D10_DEFAULT_SLOPE_SCALED_DEPTH_BIAS                                       = 0.0;
const float D3D10_DEFAULT_DEPTH_BIAS_CLAMP                                              = 0.0;
const float D3D10_DEFAULT_MAX_ANISOTROPY                                                = 16.0;
const float D3D10_DEFAULT_MIP_LOD_BIAS                                                  = 0.0;
const float D3D10_DEFAULT_VIEWPORT_MAX_DEPTH                                            = 0.0;
const float D3D10_DEFAULT_VIEWPORT_MIN_DEPTH                                            = 0.0;
const float D3D10_FLOAT16_FUSED_TOLERANCE_IN_ULP                                        = 0.6;
const float D3D10_FLOAT32_MAX                                                           = 3.402823466e+38;
const float D3D10_FLOAT32_TO_INTEGER_TOLERANCE_IN_ULP                                   = 0.6;
const float D3D10_FLOAT_TO_SRGB_EXPONENT_DENOMINATOR                                    = 2.4;
const float D3D10_FLOAT_TO_SRGB_EXPONENT_NUMERATOR                                      = 1.0;
const float D3D10_FLOAT_TO_SRGB_OFFSET                                                  = 0.055;
const float D3D10_FLOAT_TO_SRGB_SCALE_1                                                 = 12.92;
const float D3D10_FLOAT_TO_SRGB_SCALE_2                                                 = 1.055;
const float D3D10_FLOAT_TO_SRGB_THRESHOLD                                               = 0.0031308;
const float D3D10_FTOI_INSTRUCTION_MAX_INPUT                                            = 2147483647.999;
const float D3D10_FTOI_INSTRUCTION_MIN_INPUT                                            = -2147483648.999;
const float D3D10_FTOU_INSTRUCTION_MAX_INPUT                                            = 4294967295.999;
const float D3D10_FTOU_INSTRUCTION_MIN_INPUT                                            = 0.0;
const float D3D10_LINEAR_GAMMA                                                          = 1.0;
const float D3D10_MAX_BORDER_COLOR_COMPONENT                                            = 1.0;
const float D3D10_MAX_DEPTH                                                             = 1.0;
const float D3D10_MAX_POSITION_VALUE                                                    = 3.402823466e+34;
const float D3D10_MIN_BORDER_COLOR_COMPONENT                                            = 0.0;
const float D3D10_MIN_DEPTH                                                             = 0.0;
const float D3D10_MIP_LOD_BIAS_MAX                                                      = 15.99;
const float D3D10_MIP_LOD_BIAS_MIN                                                      = -16.0;
const float D3D10_PS_PIXEL_CENTER_FRACTIONAL_COMPONENT                                  = 0.5;
const float D3D10_MULTISAMPLE_ANTIALIAS_LINE_WIDTH                                      = 1.4;
const float D3D10_SRGB_GAMMA                                                            = 2.2;
const float D3D10_SRGB_TO_FLOAT_DENOMINATOR_1                                           = 12.92;
const float D3D10_SRGB_TO_FLOAT_DENOMINATOR_2                                           = 1.055;
const float D3D10_SRGB_TO_FLOAT_EXPONENT                                                = 2.4;
const float D3D10_SRGB_TO_FLOAT_OFFSET                                                  = 0.055;
const float D3D10_SRGB_TO_FLOAT_THRESHOLD                                               = 0.04045;
const float D3D10_SRGB_TO_FLOAT_TOLERANCE_IN_ULP                                        = 0.5;
const float D3D10_PS_LEGACY_PIXEL_CENTER_FRACTIONAL_COMPONENT                           = 0.0;
const float D3D_SPEC_VERSION                                                            = 1.050005;
const unsigned int D3D10_16BIT_INDEX_STRIP_CUT_VALUE                                    = 0xffff;
const unsigned int D3D10_32BIT_INDEX_STRIP_CUT_VALUE                                    = 0xffffffff;
const unsigned int D3D10_8BIT_INDEX_STRIP_CUT_VALUE                                     = 0xff;
const unsigned int D3D10_ARRAY_AXIS_ADDRESS_RANGE_BIT_COUNT                             = 9;
const unsigned int D3D10_CLIP_OR_CULL_DISTANCE_COUNT                                    = 8;
const unsigned int D3D10_CLIP_OR_CULL_DISTANCE_ELEMENT_COUNT                            = 2;
const unsigned int D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT                    = 14;
const unsigned int D3D10_COMMONSHADER_CONSTANT_BUFFER_COMPONENTS                        = 4;
const unsigned int D3D10_COMMONSHADER_CONSTANT_BUFFER_COMPONENT_BIT_COUNT               = 32;
const unsigned int D3D10_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT                     = 15;
const unsigned int D3D10_COMMONSHADER_CONSTANT_BUFFER_REGISTER_COMPONENTS               = 4;
const unsigned int D3D10_COMMONSHADER_CONSTANT_BUFFER_REGISTER_COUNT                    = 15;
const unsigned int D3D10_COMMONSHADER_CONSTANT_BUFFER_REGISTER_READS_PER_INST           = 1;
const unsigned int D3D10_COMMONSHADER_CONSTANT_BUFFER_REGISTER_READ_PORTS               = 1;
const unsigned int D3D10_COMMONSHADER_FLOWCONTROL_NESTING_LIMIT                         = 64;
const unsigned int D3D10_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_COMPONENTS     = 4;
const unsigned int D3D10_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_COUNT          = 1;
const unsigned int D3D10_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_READS_PER_INST = 1;
const unsigned int D3D10_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_READ_PORTS     = 1;
const unsigned int D3D10_COMMONSHADER_IMMEDIATE_VALUE_COMPONENT_BIT_COUNT               = 32;
const unsigned int D3D10_COMMONSHADER_INPUT_RESOURCE_REGISTER_COMPONENTS                = 1;
const unsigned int D3D10_COMMONSHADER_INPUT_RESOURCE_REGISTER_COUNT                     = 128;
const unsigned int D3D10_COMMONSHADER_INPUT_RESOURCE_REGISTER_READS_PER_INST            = 1;
const unsigned int D3D10_COMMONSHADER_INPUT_RESOURCE_REGISTER_READ_PORTS                = 1;
const unsigned int D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT                         = 128;
const unsigned int D3D10_COMMONSHADER_SAMPLER_REGISTER_COMPONENTS                       = 1;
const unsigned int D3D10_COMMONSHADER_SAMPLER_REGISTER_COUNT                            = 16;
const unsigned int D3D10_COMMONSHADER_SAMPLER_REGISTER_READS_PER_INST                   = 1;
const unsigned int D3D10_COMMONSHADER_SAMPLER_REGISTER_READ_PORTS                       = 1;
const unsigned int D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT                                = 16;
const unsigned int D3D10_COMMONSHADER_SUBROUTINE_NESTING_LIMIT                          = 32;
const unsigned int D3D10_COMMONSHADER_TEMP_REGISTER_COMPONENTS                          = 4;
const unsigned int D3D10_COMMONSHADER_TEMP_REGISTER_COMPONENT_BIT_COUNT                 = 32;
const unsigned int D3D10_COMMONSHADER_TEMP_REGISTER_COUNT                               = 4096;
const unsigned int D3D10_COMMONSHADER_TEMP_REGISTER_READS_PER_INST                      = 3;
const unsigned int D3D10_COMMONSHADER_TEMP_REGISTER_READ_PORTS                          = 3;
const unsigned int D3D10_COMMONSHADER_TEXCOORD_RANGE_REDUCTION_MAX                      = 10;
const int D3D10_COMMONSHADER_TEXCOORD_RANGE_REDUCTION_MIN                               = -10;
const int D3D10_COMMONSHADER_TEXEL_OFFSET_MAX_NEGATIVE                                  = -8;
const unsigned int D3D10_COMMONSHADER_TEXEL_OFFSET_MAX_POSITIVE                         = 7;
const unsigned int D3D10_DEFAULT_DEPTH_BIAS                                             = 0;
const unsigned int D3D10_DEFAULT_RENDER_TARGET_ARRAY_INDEX                              = 0;
const unsigned int D3D10_DEFAULT_SAMPLE_MASK                                            = 0xffffffff;
const unsigned int D3D10_DEFAULT_SCISSOR_ENDX                                           = 0;
const unsigned int D3D10_DEFAULT_SCISSOR_ENDY                                           = 0;
const unsigned int D3D10_DEFAULT_SCISSOR_STARTX                                         = 0;
const unsigned int D3D10_DEFAULT_SCISSOR_STARTY                                         = 0;
const unsigned int D3D10_DEFAULT_STENCIL_READ_MASK                                      = 0xff;
const unsigned int D3D10_DEFAULT_STENCIL_REFERENCE                                      = 0;
const unsigned int D3D10_DEFAULT_STENCIL_WRITE_MASK                                     = 0xff;
const unsigned int D3D10_DEFAULT_VIEWPORT_AND_SCISSORRECT_INDEX                         = 0;
const unsigned int D3D10_DEFAULT_VIEWPORT_HEIGHT                                        = 0;
const unsigned int D3D10_DEFAULT_VIEWPORT_TOPLEFTX                                      = 0;
const unsigned int D3D10_DEFAULT_VIEWPORT_TOPLEFTY                                      = 0;
const unsigned int D3D10_DEFAULT_VIEWPORT_WIDTH                                         = 0;
const unsigned int D3D10_GS_INPUT_PRIM_CONST_REGISTER_COMPONENTS                        = 1;
const unsigned int D3D10_GS_INPUT_PRIM_CONST_REGISTER_COMPONENT_BIT_COUNT               = 32;
const unsigned int D3D10_GS_INPUT_PRIM_CONST_REGISTER_COUNT                             = 1;
const unsigned int D3D10_GS_INPUT_PRIM_CONST_REGISTER_READS_PER_INST                    = 2;
const unsigned int D3D10_GS_INPUT_PRIM_CONST_REGISTER_READ_PORTS                        = 1;
const unsigned int D3D10_GS_INPUT_REGISTER_COMPONENTS                                   = 4;
const unsigned int D3D10_GS_INPUT_REGISTER_COMPONENT_BIT_COUNT                          =32;
const unsigned int D3D10_GS_INPUT_REGISTER_COUNT                                        = 16;
const unsigned int D3D10_GS_INPUT_REGISTER_READS_PER_INST                               = 2;
const unsigned int D3D10_GS_INPUT_REGISTER_READ_PORTS                                   = 1;
const unsigned int D3D10_GS_INPUT_REGISTER_VERTICES                                     = 6;
const unsigned int D3D10_GS_OUTPUT_ELEMENTS                                             = 32;
const unsigned int D3D10_GS_OUTPUT_REGISTER_COMPONENTS                                  = 4;
const unsigned int D3D10_GS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT                         = 32;
const unsigned int D3D10_GS_OUTPUT_REGISTER_COUNT                                       = 32;
const unsigned int D3D10_IA_DEFAULT_INDEX_BUFFER_OFFSET_IN_BYTES                        = 0;
const unsigned int D3D10_IA_DEFAULT_PRIMITIVE_TOPOLOGY                                  = 0;
const unsigned int D3D10_IA_DEFAULT_VERTEX_BUFFER_OFFSET_IN_BYTES                       = 0;
const unsigned int D3D10_IA_INDEX_INPUT_RESOURCE_SLOT_COUNT                             = 1;
const unsigned int D3D10_IA_INSTANCE_ID_BIT_COUNT                                       = 32;
const unsigned int D3D10_IA_INTEGER_ARITHMETIC_BIT_COUNT                                = 32;
const unsigned int D3D10_IA_PRIMITIVE_ID_BIT_COUNT                                      = 32;
const unsigned int D3D10_IA_VERTEX_ID_BIT_COUNT                                         = 32;
const unsigned int D3D10_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT                            = 16;
const unsigned int D3D10_IA_VERTEX_INPUT_STRUCTURE_ELEMENTS_COMPONENTS                  = 64;
const unsigned int D3D10_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT                        = 16;
const unsigned int D3D10_INTEGER_DIVIDE_BY_ZERO_QUOTIENT                                = 0xffffffff;
const unsigned int D3D10_INTEGER_DIVIDE_BY_ZERO_REMAINDER                               = 0xffffffff;
const unsigned int D3D10_MAX_MAXANISOTROPY                                              = 16;
const unsigned int D3D10_MAX_MULTISAMPLE_SAMPLE_COUNT                                   = 32;
const unsigned int D3D10_MAX_TEXTURE_DIMENSION_2_TO_EXP                                 = 17;
const unsigned int D3D10_MIN_MAXANISOTROPY                                              = 0;
const unsigned int D3D10_MIP_LOD_FRACTIONAL_BIT_COUNT                                   = 6;
const unsigned int D3D10_MIP_LOD_RANGE_BIT_COUNT                                        = 8;
const unsigned int D3D10_NONSAMPLE_FETCH_OUT_OF_RANGE_ACCESS_RESULT                     = 0;
const unsigned int D3D10_PIXEL_ADDRESS_RANGE_BIT_COUNT                                  = 13;
const unsigned int D3D10_PRE_SCISSOR_PIXEL_ADDRESS_RANGE_BIT_COUNT                      = 15;
const unsigned int D3D10_PS_FRONTFACING_DEFAULT_VALUE                                   = 0xffffffff;
const unsigned int D3D10_PS_FRONTFACING_FALSE_VALUE                                     = 0;
const unsigned int D3D10_PS_FRONTFACING_TRUE_VALUE                                      = 0xffffffff;
const unsigned int D3D10_PS_INPUT_REGISTER_COMPONENTS                                   = 4;
const unsigned int D3D10_PS_INPUT_REGISTER_COMPONENT_BIT_COUNT                          = 32;
const unsigned int D3D10_PS_INPUT_REGISTER_COUNT                                        = 32;
const unsigned int D3D10_PS_INPUT_REGISTER_READS_PER_INST                               = 2;
const unsigned int D3D10_PS_INPUT_REGISTER_READ_PORTS                                   = 1;
const unsigned int D3D10_PS_OUTPUT_DEPTH_REGISTER_COMPONENTS                            = 1;
const unsigned int D3D10_PS_OUTPUT_DEPTH_REGISTER_COMPONENT_BIT_COUNT                   = 32;
const unsigned int D3D10_PS_OUTPUT_DEPTH_REGISTER_COUNT                                 = 1;
const unsigned int D3D10_PS_OUTPUT_REGISTER_COMPONENTS                                  = 4;
const unsigned int D3D10_PS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT                         = 32;
const unsigned int D3D10_PS_OUTPUT_REGISTER_COUNT                                       = 8;
const unsigned int D3D10_REQ_BLEND_OBJECT_COUNT_PER_CONTEXT                             = 4096;
const unsigned int D3D10_REQ_BUFFER_RESOURCE_TEXEL_COUNT_2_TO_EXP                       = 27;
const unsigned int D3D10_REQ_CONSTANT_BUFFER_ELEMENT_COUNT                              = 4096;
const unsigned int D3D10_REQ_DEPTH_STENCIL_OBJECT_COUNT_PER_CONTEXT                     = 4096;
const unsigned int D3D10_REQ_DRAWINDEXED_INDEX_COUNT_2_TO_EXP                           = 32;
const unsigned int D3D10_REQ_DRAW_VERTEX_COUNT_2_TO_EXP                                 = 32;
const unsigned int D3D10_REQ_FILTERING_HW_ADDRESSABLE_RESOURCE_DIMENSION                = 8192;
const unsigned int D3D10_REQ_GS_INVOCATION_32BIT_OUTPUT_COMPONENT_LIMIT                 = 1024;
const unsigned int D3D10_REQ_IMMEDIATE_CONSTANT_BUFFER_ELEMENT_COUNT                    = 4096;
const unsigned int D3D10_REQ_MAXANISOTROPY                                              = 16;
const unsigned int D3D10_REQ_MIP_LEVELS                                                 = 14;
const unsigned int D3D10_REQ_MULTI_ELEMENT_STRUCTURE_SIZE_IN_BYTES                      = 2048;
const unsigned int D3D10_REQ_RASTERIZER_OBJECT_COUNT_PER_CONTEXT                        = 4096;
const unsigned int D3D10_REQ_RENDER_TO_BUFFER_WINDOW_WIDTH                              = 8192;
const unsigned int D3D10_REQ_RESOURCE_SIZE_IN_MEGABYTES                                 = 128;
const unsigned int D3D10_REQ_RESOURCE_VIEW_COUNT_PER_CONTEXT_2_TO_EXP                   = 20;
const unsigned int D3D10_REQ_SAMPLER_OBJECT_COUNT_PER_CONTEXT                           = 4096;
const unsigned int D3D10_REQ_TEXTURE1D_ARRAY_AXIS_DIMENSION                             = 512;
const unsigned int D3D10_REQ_TEXTURE1D_U_DIMENSION                                      = 8192;
const unsigned int D3D10_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION                             = 512;
const unsigned int D3D10_REQ_TEXTURE2D_U_OR_V_DIMENSION                                 = 8192;
const unsigned int D3D10_REQ_TEXTURE3D_U_V_OR_W_DIMENSION                               = 2048;
const unsigned int D3D10_REQ_TEXTURECUBE_DIMENSION                                      = 8192;
const unsigned int D3D10_RESINFO_INSTRUCTION_MISSING_COMPONENT_RETVAL                   = 0;
const unsigned int D3D10_SHADER_MAJOR_VERSION                                           = 4;
const unsigned int D3D10_SHADER_MINOR_VERSION                                           = 0;
const unsigned int D3D10_SHIFT_INSTRUCTION_PAD_VALUE                                    = 0;
const unsigned int D3D10_SHIFT_INSTRUCTION_SHIFT_VALUE_BIT_COUNT                        = 5;
const unsigned int D3D10_SIMULTANEOUS_RENDER_TARGET_COUNT                               = 8;
const unsigned int D3D10_SO_BUFFER_MAX_STRIDE_IN_BYTES                                  = 2048;
const unsigned int D3D10_SO_BUFFER_MAX_WRITE_WINDOW_IN_BYTES                            = 256;
const unsigned int D3D10_SO_BUFFER_SLOT_COUNT                                           = 4;
const unsigned int D3D10_SO_DDI_REGISTER_INDEX_DENOTING_GAP                             = 0xffffffff;
const unsigned int D3D10_SO_MULTIPLE_BUFFER_ELEMENTS_PER_BUFFER                         = 1;
const unsigned int D3D10_SO_SINGLE_BUFFER_COMPONENT_LIMIT                               = 64;
const unsigned int D3D10_STANDARD_COMPONENT_BIT_COUNT                                   = 32;
const unsigned int D3D10_STANDARD_COMPONENT_BIT_COUNT_DOUBLED                           = 64;
const unsigned int D3D10_STANDARD_MAXIMUM_ELEMENT_ALIGNMENT_BYTE_MULTIPLE               = 4;
const unsigned int D3D10_STANDARD_PIXEL_COMPONENT_COUNT                                 = 128;
const unsigned int D3D10_STANDARD_PIXEL_ELEMENT_COUNT                                   = 32;
const unsigned int D3D10_STANDARD_VECTOR_SIZE                                           = 4;
const unsigned int D3D10_STANDARD_VERTEX_ELEMENT_COUNT                                  = 16;
const unsigned int D3D10_STANDARD_VERTEX_TOTAL_COMPONENT_COUNT                          = 64;
const unsigned int D3D10_SUBPIXEL_FRACTIONAL_BIT_COUNT                                  = 8;
const unsigned int D3D10_SUBTEXEL_FRACTIONAL_BIT_COUNT                                  = 6;
const unsigned int D3D10_TEXEL_ADDRESS_RANGE_BIT_COUNT                                  = 18;
const unsigned int D3D10_UNBOUND_MEMORY_ACCESS_RESULT                                   = 0;
const unsigned int D3D10_VIEWPORT_AND_SCISSORRECT_MAX_INDEX                             = 15;
const unsigned int D3D10_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE             = 16;
const unsigned int D3D10_VIEWPORT_BOUNDS_MAX                                            = 16383;
const int D3D10_VIEWPORT_BOUNDS_MIN                                                     = -16384;
const unsigned int D3D10_VS_INPUT_REGISTER_COMPONENTS                                   = 4;
const unsigned int D3D10_VS_INPUT_REGISTER_COMPONENT_BIT_COUNT                          = 32;
const unsigned int D3D10_VS_INPUT_REGISTER_COUNT                                        = 16;
const unsigned int D3D10_VS_INPUT_REGISTER_READS_PER_INST                               = 2;
const unsigned int D3D10_VS_INPUT_REGISTER_READ_PORTS                                   = 1;
const unsigned int D3D10_VS_OUTPUT_REGISTER_COMPONENTS                                  = 4;
const unsigned int D3D10_VS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT                         = 32;
const unsigned int D3D10_VS_OUTPUT_REGISTER_COUNT                                       = 16;
const unsigned int D3D10_WHQL_CONTEXT_COUNT_FOR_RESOURCE_LIMIT                          = 10;
const unsigned int D3D10_WHQL_DRAWINDEXED_INDEX_COUNT_2_TO_EXP                          = 25;
const unsigned int D3D10_WHQL_DRAW_VERTEX_COUNT_2_TO_EXP                                = 25;
const unsigned int D3D_MAJOR_VERSION                                                    = 10;
const unsigned int D3D_MINOR_VERSION                                                    = 0;
const unsigned int D3D_SPEC_DATE_DAY                                                    = 8;
const unsigned int D3D_SPEC_DATE_MONTH                                                  = 8;
const unsigned int D3D_SPEC_DATE_YEAR                                                   = 2006;
#endif

const unsigned int D3D10_APPEND_ALIGNED_ELEMENT                                         = 0xffffffff;
const unsigned int _FACD3D10                                                            = 0x879;
const unsigned int _FACD3D10DEBUG                                                       = _FACD3D10 + 1;
const unsigned int D3D10_FILTER_TYPE_MASK                                               = 0x3;
const unsigned int D3D10_SDK_VERSION                                                    = 29;

#define MAKE_D3D10_HRESULT(code)                   MAKE_HRESULT( 1, _FACD3D10, code)
#define MAKE_D3D10_STATUS(code)                    MAKE_HRESULT( 0, _FACD3D10, code)
#define D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS  MAKE_D3D10_HRESULT(1)
#define D3D10_ERROR_FILE_NOT_FOUND                 MAKE_D3D10_HRESULT(2)

typedef enum D3D10_BLEND {
    D3D10_BLEND_ZERO             = 1,
    D3D10_BLEND_ONE              = 2,
    D3D10_BLEND_SRC_COLOR        = 3,
    D3D10_BLEND_INV_SRC_COLOR    = 4,
    D3D10_BLEND_SRC_ALPHA        = 5,
    D3D10_BLEND_INV_SRC_ALPHA    = 6,
    D3D10_BLEND_DEST_ALPHA       = 7,
    D3D10_BLEND_INV_DEST_ALPHA   = 8,
    D3D10_BLEND_DEST_COLOR       = 9,
    D3D10_BLEND_INV_DEST_COLOR   = 10,
    D3D10_BLEND_SRC_ALPHA_SAT    = 11,
    D3D10_BLEND_BLEND_FACTOR     = 14,
    D3D10_BLEND_INV_BLEND_FACTOR = 15,
    D3D10_BLEND_SRC1_COLOR       = 16,
    D3D10_BLEND_INV_SRC1_COLOR   = 17,
    D3D10_BLEND_SRC1_ALPHA       = 18,
    D3D10_BLEND_INV_SRC1_ALPHA   = 19
} D3D10_BLEND;

typedef enum D3D10_BLEND_OP {
    D3D10_BLEND_OP_ADD = 1,
    D3D10_BLEND_OP_SUBTRACT,
    D3D10_BLEND_OP_REV_SUBTRACT,
    D3D10_BLEND_OP_MIN,
    D3D10_BLEND_OP_MAX,
} D3D10_BLEND_OP;

typedef struct D3D10_BLEND_DESC {
    BOOL AlphaToCoverageEnable;
    BOOL BlendEnable[8];
    D3D10_BLEND SrcBlend;
    D3D10_BLEND DestBlend;
    D3D10_BLEND_OP BlendOp;
    D3D10_BLEND SrcBlendAlpha;
    D3D10_BLEND DestBlendAlpha;
    D3D10_BLEND_OP BlendOpAlpha;
    UINT8 RenderTargetWriteMask[8];
} D3D10_BLEND_DESC;

typedef enum D3D10_DEPTH_WRITE_MASK {
    D3D10_DEPTH_WRITE_MASK_ZERO,
    D3D10_DEPTH_WRITE_MASK_ALL,
} D3D10_DEPTH_WRITE_MASK;

typedef enum D3D10_COMPARISON_FUNC {
    D3D10_COMPARISON_NEVER = 1,
    D3D10_COMPARISON_LESS,
    D3D10_COMPARISON_EQUAL,
    D3D10_COMPARISON_LESS_EQUAL,
    D3D10_COMPARISON_GREATER,
    D3D10_COMPARISON_NOT_EQUAL,
    D3D10_COMPARISON_GREATER_EQUAL,
    D3D10_COMPARISON_ALWAYS,
} D3D10_COMPARISON_FUNC;

typedef enum D3D10_STENCIL_OP {
    D3D10_STENCIL_OP_KEEP = 1,
    D3D10_STENCIL_OP_ZERO,
    D3D10_STENCIL_OP_REPLACE,
    D3D10_STENCIL_OP_INCR_SAT,
    D3D10_STENCIL_OP_DECR_SAT,
    D3D10_STENCIL_OP_INVERT,
    D3D10_STENCIL_OP_INCR,
    D3D10_STENCIL_OP_DECR,
} D3D10_STENCIL_OP;

typedef struct D3D10_DEPTH_STENCILOP_DESC {
    D3D10_STENCIL_OP StencilFailOp;
    D3D10_STENCIL_OP StencilDepthFailOp;
    D3D10_STENCIL_OP StencilPassOp;
    D3D10_COMPARISON_FUNC StencilFunc;
} D3D10_DEPTH_STENCILOP_DESC;

typedef struct D3D10_DEPTH_STENCIL_DESC {
    BOOL DepthEnable;
    D3D10_DEPTH_WRITE_MASK DepthWriteMask;
    D3D10_COMPARISON_FUNC DepthFunc;
    BOOL StencilEnable;
    UINT8 StencilReadMask;
    UINT8 StencilWriteMask;
    D3D10_DEPTH_STENCILOP_DESC FrontFace;
    D3D10_DEPTH_STENCILOP_DESC BackFace;
} D3D10_DEPTH_STENCIL_DESC;

typedef enum D3D10_FILL_MODE {
    D3D10_FILL_WIREFRAME = 2,
    D3D10_FILL_SOLID,
} D3D10_FILL_MODE;

typedef enum D3D10_CULL_MODE {
    D3D10_CULL_NONE = 1,
    D3D10_CULL_FRONT,
    D3D10_CULL_BACK,
} D3D10_CULL_MODE;

typedef struct D3D10_RASTERIZER_DESC {
    D3D10_FILL_MODE FillMode;
    D3D10_CULL_MODE CullMode;
    BOOL FrontCounterClockwise;
    INT DepthBias;
    FLOAT DepthBiasClamp;
    FLOAT SlopeScaledDepthBias;
    BOOL DepthClipEnable;
    BOOL ScissorEnable;
    BOOL MultisampleEnable;
    BOOL AntialiasedLineEnable;
} D3D10_RASTERIZER_DESC;

typedef enum D3D10_FILTER {
    D3D10_FILTER_MIN_MAG_MIP_POINT                          = 0,
    D3D10_FILTER_MIN_MAG_POINT_MIP_LINEAR                   = 0x1,
    D3D10_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT             = 0x4,
    D3D10_FILTER_MIN_POINT_MAG_MIP_LINEAR                   = 0x5,
    D3D10_FILTER_MIN_LINEAR_MAG_MIP_POINT                   = 0x10,
    D3D10_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR            = 0x11,
    D3D10_FILTER_MIN_MAG_LINEAR_MIP_POINT                   = 0x14,
    D3D10_FILTER_MIN_MAG_MIP_LINEAR                         = 0x15,
    D3D10_FILTER_ANISOTROPIC                                = 0x55,
    D3D10_FILTER_COMPARISON_MIN_MAG_MIP_POINT               = 0x80,
    D3D10_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR        = 0x81,
    D3D10_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT  = 0x84,
    D3D10_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR        = 0x85,
    D3D10_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT        = 0x90,
    D3D10_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x91,
    D3D10_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT        = 0x94,
    D3D10_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR              = 0x95,
    D3D10_FILTER_COMPARISON_ANISOTROPIC                     = 0xd5,
    D3D10_FILTER_TEXT_1BIT                                  = 0x80000000
} D3D10_FILTER;

typedef enum D3D10_TEXTURE_ADDRESS_MODE {
    D3D10_TEXTURE_ADDRESS_WRAP = 1,
    D3D10_TEXTURE_ADDRESS_MIRROR,
    D3D10_TEXTURE_ADDRESS_CLAMP,
    D3D10_TEXTURE_ADDRESS_BORDER,
    D3D10_TEXTURE_ADDRESS_MIRROR_ONCE,
} D3D10_TEXTURE_ADDRESS_MODE;

typedef struct D3D10_SAMPLER_DESC {
    D3D10_FILTER Filter;
    D3D10_TEXTURE_ADDRESS_MODE AddressU;
    D3D10_TEXTURE_ADDRESS_MODE AddressV;
    D3D10_TEXTURE_ADDRESS_MODE AddressW;
    FLOAT MipLODBias;
    UINT MaxAnisotropy;
    D3D10_COMPARISON_FUNC ComparisonFunc;
    FLOAT BorderColor[4];
    FLOAT MinLOD;
    FLOAT MaxLOD;
} D3D10_SAMPLER_DESC;

typedef enum D3D10_COUNTER {
    D3D10_COUNTER_GPU_IDLE,
    D3D10_COUNTER_VERTEX_PROCESSING,
    D3D10_COUNTER_GEOMETRY_PROCESSING,
    D3D10_COUNTER_PIXEL_PROCESSING,
    D3D10_COUNTER_OTHER_GPU_PROCESSING,
    D3D10_COUNTER_HOST_ADAPTER_BANDWIDTH_UTILIZATION,
    D3D10_COUNTER_LOCAL_VIDMEM_BANDWIDTH_UTILIZATION,
    D3D10_COUNTER_VERTEX_THROUGHPUT_UTILIZATION,
    D3D10_COUNTER_TRIANGLE_SETUP_THROUGHPUT_UTILIZATION,
    D3D10_COUNTER_FILLRATE_THROUGHPUT_UTILIZATION,
    D3D10_COUNTER_VS_MEMORY_LIMITED,
    D3D10_COUNTER_VS_COMPUTATION_LIMITED,
    D3D10_COUNTER_GS_MEMORY_LIMITED,
    D3D10_COUNTER_GS_COMPUTATION_LIMITED,
    D3D10_COUNTER_PS_MEMORY_LIMITED,
    D3D10_COUNTER_PS_COMPUTATION_LIMITED,
    D3D10_COUNTER_POST_TRANSFORM_CACHE_HIT_RATE,
    D3D10_COUNTER_TEXTURE_CACHE_HIT_RATE,
    D3D10_COUNTER_DEVICE_DEPENDENT_0 = 0x40000000
} D3D10_COUNTER;

typedef struct D3D10_COUNTER_DESC {
    D3D10_COUNTER Counter;
    UINT MiscFlags;
} D3D10_COUNTER_DESC;

typedef enum D3D10_COUNTER_TYPE {
    D3D10_COUNTER_TYPE_FLOAT32,
    D3D10_COUNTER_TYPE_UINT16,
    D3D10_COUNTER_TYPE_UINT32,
    D3D10_COUNTER_TYPE_UINT64,
} D3D10_COUNTER_TYPE;

typedef struct D3D10_COUNTER_INFO {
    D3D10_COUNTER LastDeviceDependentCounter;
    UINT NumSimultaneousCounters;
    UINT8 NumDetectableParallelUnits;
} D3D10_COUNTER_INFO;

typedef enum D3D10_RESOURCE_DIMENSION {
    D3D10_RESOURCE_DIMENSION_UNKNOWN,
    D3D10_RESOURCE_DIMENSION_BUFFER,
    D3D10_RESOURCE_DIMENSION_TEXTURE1D,
    D3D10_RESOURCE_DIMENSION_TEXTURE2D,
    D3D10_RESOURCE_DIMENSION_TEXTURE3D,
} D3D10_RESOURCE_DIMENSION;

typedef enum D3D10_USAGE {
    D3D10_USAGE_DEFAULT,
    D3D10_USAGE_IMMUTABLE,
    D3D10_USAGE_DYNAMIC,
    D3D10_USAGE_STAGING,
} D3D10_USAGE;

typedef enum D3D10_BIND_FLAG {
    D3D10_BIND_VERTEX_BUFFER   = 0x1,
    D3D10_BIND_INDEX_BUFFER    = 0x2,
    D3D10_BIND_CONSTANT_BUFFER = 0x4,
    D3D10_BIND_SHADER_RESOURCE = 0x8,
    D3D10_BIND_STREAM_OUTPUT   = 0x10,
    D3D10_BIND_RENDER_TARGET   = 0x20,
    D3D10_BIND_DEPTH_STENCIL   = 0x40
} D3D10_BIND_FLAG;

typedef struct D3D10_BUFFER_DESC {
    UINT ByteWidth;
    D3D10_USAGE Usage;
    UINT BindFlags;
    UINT CPUAccessFlags;
    UINT MiscFlags;
} D3D10_BUFFER_DESC;

#if !defined(D3D10_NO_HELPERS) && defined(__cplusplus)
struct CD3D10_BUFFER_DESC : public D3D10_BUFFER_DESC {
    CD3D10_BUFFER_DESC() {}
    explicit CD3D10_BUFFER_DESC(const D3D10_BUFFER_DESC &o) : D3D10_BUFFER_DESC(o) {}
    explicit CD3D10_BUFFER_DESC(UINT byteWidth, UINT bindFlags, D3D10_USAGE usage = D3D10_USAGE_DEFAULT, UINT cpuaccessFlags = 0, UINT miscFlags = 0 ) {
        ByteWidth = byteWidth;
        Usage = usage;
        BindFlags = bindFlags;
        CPUAccessFlags = cpuaccessFlags;
        MiscFlags = miscFlags;
    }
    ~CD3D10_BUFFER_DESC() {}
    operator const D3D10_BUFFER_DESC&() const {
        return *this;
    }
};
#endif

typedef enum D3D10_MAP {
    D3D10_MAP_READ = 1,
    D3D10_MAP_WRITE,
    D3D10_MAP_READ_WRITE,
    D3D10_MAP_WRITE_DISCARD,
    D3D10_MAP_WRITE_NO_OVERWRITE,
} D3D10_MAP;

typedef struct D3D10_TEXTURE1D_DESC {
    UINT Width;
    UINT MipLevels;
    UINT ArraySize;
    DXGI_FORMAT Format;
    D3D10_USAGE Usage;
    UINT BindFlags;
    UINT CPUAccessFlags;
    UINT MiscFlags;
} D3D10_TEXTURE1D_DESC;

#if !defined(D3D10_NO_HELPERS) && defined(__cplusplus)
struct CD3D10_TEXTURE1D_DESC : public D3D10_TEXTURE1D_DESC {
    CD3D10_TEXTURE1D_DESC() {}
    explicit CD3D10_TEXTURE1D_DESC(const D3D10_TEXTURE1D_DESC &o) : D3D10_TEXTURE1D_DESC(o) {}
    explicit CD3D10_TEXTURE1D_DESC(DXGI_FORMAT format, UINT width, UINT arraySize = 1, UINT mipLevels = 0,
        UINT bindFlags = D3D10_BIND_SHADER_RESOURCE, D3D10_USAGE usage = D3D10_USAGE_DEFAULT, UINT cpuaccessFlags = 0,
        UINT miscFlags = 0) {
        Width = width;
        MipLevels = mipLevels;
        ArraySize = arraySize;
        Format = format;
        Usage = usage;
        BindFlags = bindFlags;
        CPUAccessFlags = cpuaccessFlags;
        MiscFlags = miscFlags;
    }
    ~CD3D10_TEXTURE1D_DESC() {}
    operator const D3D10_TEXTURE1D_DESC&() const {
        return *this;
    }
};
#endif

typedef struct D3D10_TEXTURE2D_DESC {
    UINT Width;
    UINT Height;
    UINT MipLevels;
    UINT ArraySize;
    DXGI_FORMAT Format;
    DXGI_SAMPLE_DESC SampleDesc;
    D3D10_USAGE Usage;
    UINT BindFlags;
    UINT CPUAccessFlags;
    UINT MiscFlags;
} D3D10_TEXTURE2D_DESC;

#if !defined(D3D10_NO_HELPERS) && defined(__cplusplus)
struct CD3D10_TEXTURE2D_DESC : public D3D10_TEXTURE2D_DESC {
    CD3D10_TEXTURE2D_DESC() {}
    explicit CD3D10_TEXTURE2D_DESC(const D3D10_TEXTURE2D_DESC &o) : D3D10_TEXTURE2D_DESC(o) {}
    explicit CD3D10_TEXTURE2D_DESC(DXGI_FORMAT format, UINT width, UINT height,
            UINT arraySize = 1,
            UINT mipLevels = 0,
            UINT bindFlags = D3D10_BIND_SHADER_RESOURCE,
            D3D10_USAGE usage = D3D10_USAGE_DEFAULT,
            UINT cpuaccessFlags = 0,
            UINT sampleCount = 1,
            UINT sampleQuality = 0,
            UINT miscFlags = 0) {
        Width = width;
        Height = height;
        MipLevels = mipLevels;
        ArraySize = arraySize;
        Format = format;
        SampleDesc.Count = sampleCount;
        SampleDesc.Quality = sampleQuality;
        Usage = usage;
        BindFlags = bindFlags;
        CPUAccessFlags = cpuaccessFlags;
        MiscFlags = miscFlags;
    }
    ~CD3D10_TEXTURE2D_DESC() {}
    operator const D3D10_TEXTURE2D_DESC&() const {
        return *this;
    }
};
#endif

typedef struct D3D10_TEXTURE3D_DESC {
    UINT Width;
    UINT Height;
    UINT Depth;
    UINT MipLevels;
    DXGI_FORMAT Format;
    D3D10_USAGE Usage;
    UINT BindFlags;
    UINT CPUAccessFlags;
    UINT MiscFlags;
} D3D10_TEXTURE3D_DESC;

typedef enum D3D10_DSV_DIMENSION
{
    D3D10_DSV_DIMENSION_UNKNOWN,
    D3D10_DSV_DIMENSION_TEXTURE1D,
    D3D10_DSV_DIMENSION_TEXTURE1DARRAY,
    D3D10_DSV_DIMENSION_TEXTURE2D,
    D3D10_DSV_DIMENSION_TEXTURE2DARRAY,
    D3D10_DSV_DIMENSION_TEXTURE2DMS,
    D3D10_DSV_DIMENSION_TEXTURE2DMSARRAY,
} D3D10_DSV_DIMENSION;

typedef struct D3D10_TEX1D_DSV {
    UINT MipSlice;
} D3D10_TEX1D_DSV;

typedef struct D3D10_TEX1D_ARRAY_DSV {
    UINT MipSlice;
    UINT FirstArraySlice;
    UINT ArraySize;
} D3D10_TEX1D_ARRAY_DSV;

typedef struct D3D10_TEX2D_DSV {
    UINT MipSlice;
} D3D10_TEX2D_DSV;

typedef struct D3D10_TEX2D_ARRAY_DSV {
    UINT MipSlice;
    UINT FirstArraySlice;
    UINT ArraySize;
} D3D10_TEX2D_ARRAY_DSV;

typedef struct D3D10_TEX2DMS_DSV {
    UINT UnusedField_NothingToDefine;
} D3D10_TEX2DMS_DSV;

typedef struct D3D10_TEX2DMS_ARRAY_DSV {
    UINT FirstArraySlice;
    UINT ArraySize;
} D3D10_TEX2DMS_ARRAY_DSV;

typedef struct D3D10_DEPTH_STENCIL_VIEW_DESC {
    DXGI_FORMAT Format;
    D3D10_DSV_DIMENSION ViewDimension;
    union {
        D3D10_TEX1D_DSV Texture1D;
        D3D10_TEX1D_ARRAY_DSV Texture1DArray;
        D3D10_TEX2D_DSV Texture2D;
        D3D10_TEX2D_ARRAY_DSV Texture2DArray;
        D3D10_TEX2DMS_DSV Texture2DMS;
        D3D10_TEX2DMS_ARRAY_DSV Texture2DMSArray;
    };
} D3D10_DEPTH_STENCIL_VIEW_DESC;

typedef enum D3D10_RTV_DIMENSION {
    D3D10_RTV_DIMENSION_UNKNOWN,
    D3D10_RTV_DIMENSION_BUFFER,
    D3D10_RTV_DIMENSION_TEXTURE1D,
    D3D10_RTV_DIMENSION_TEXTURE1DARRAY,
    D3D10_RTV_DIMENSION_TEXTURE2D,
    D3D10_RTV_DIMENSION_TEXTURE2DARRAY,
    D3D10_RTV_DIMENSION_TEXTURE2DMS,
    D3D10_RTV_DIMENSION_TEXTURE2DMSARRAY,
    D3D10_RTV_DIMENSION_TEXTURE3D,
} D3D10_RTV_DIMENSION;

typedef struct D3D10_BUFFER_RTV {
    UINT ElementOffset;
    UINT ElementWidth;
} D3D10_BUFFER_RTV;

typedef struct D3D10_TEX1D_RTV {
    UINT MipSlice;
} D3D10_TEX1D_RTV;

typedef struct D3D10_TEX1D_ARRAY_RTV {
    UINT MipSlice;
    UINT FirstArraySlice;
    UINT ArraySize;
} D3D10_TEX1D_ARRAY_RTV;

typedef struct D3D10_TEX2D_RTV {
    UINT MipSlice;
} D3D10_TEX2D_RTV;

typedef struct D3D10_TEX2D_ARRAY_RTV {
    UINT MipSlice;
    UINT FirstArraySlice;
    UINT ArraySize;
} D3D10_TEX2D_ARRAY_RTV;

typedef struct D3D10_TEX2DMS_RTV {
    UINT UnusedField_NothingToDefine;
} D3D10_TEX2DMS_RTV;

typedef struct D3D10_TEX2DMS_ARRAY_RTV {
    UINT FirstArraySlice;
    UINT ArraySize;
} D3D10_TEX2DMS_ARRAY_RTV;

typedef struct D3D10_TEX3D_RTV {
    UINT MipSlice;
    UINT FirstWSlice;
    UINT WSize;
} D3D10_TEX3D_RTV;

typedef struct D3D10_RENDER_TARGET_VIEW_DESC {
    DXGI_FORMAT Format;
    D3D10_RTV_DIMENSION ViewDimension;
    union {
        D3D10_BUFFER_RTV Buffer;
        D3D10_TEX1D_RTV Texture1D;
        D3D10_TEX1D_ARRAY_RTV Texture1DArray;
        D3D10_TEX2D_RTV Texture2D;
        D3D10_TEX2D_ARRAY_RTV Texture2DArray;
        D3D10_TEX2DMS_RTV Texture2DMS;
        D3D10_TEX2DMS_ARRAY_RTV Texture2DMSArray;
        D3D10_TEX3D_RTV Texture3D;
    };
} D3D10_RENDER_TARGET_VIEW_DESC;

typedef D3D_SRV_DIMENSION D3D10_SRV_DIMENSION;

typedef struct D3D10_BUFFER_SRV {
    UINT ElementOffset;
    UINT ElementWidth;
} D3D10_BUFFER_SRV;

typedef struct D3D10_TEX1D_SRV {
    UINT MostDetailedMip;
    UINT MipLevels;
} D3D10_TEX1D_SRV;

typedef struct D3D10_TEX1D_ARRAY_SRV {
    UINT MostDetailedMip;
    UINT MipLevels;
    UINT FirstArraySlice;
    UINT ArraySize;
} D3D10_TEX1D_ARRAY_SRV;

typedef struct D3D10_TEX2D_SRV {
    UINT MostDetailedMip;
    UINT MipLevels;
} D3D10_TEX2D_SRV;

typedef struct D3D10_TEX2D_ARRAY_SRV {
    UINT MostDetailedMip;
    UINT MipLevels;
    UINT FirstArraySlice;
    UINT ArraySize;
} D3D10_TEX2D_ARRAY_SRV;

typedef struct D3D10_TEX2DMS_SRV {
    UINT UnusedField_NothingToDefine;
} D3D10_TEX2DMS_SRV;

typedef struct D3D10_TEX2DMS_ARRAY_SRV {
    UINT FirstArraySlice;
    UINT ArraySize;
} D3D10_TEX2DMS_ARRAY_SRV;

typedef struct D3D10_TEX3D_SRV {
    UINT MostDetailedMip;
    UINT MipLevels;
} D3D10_TEX3D_SRV;

typedef struct D3D10_TEXCUBE_SRV {
    UINT MostDetailedMip;
    UINT MipLevels;
} D3D10_TEXCUBE_SRV;

typedef struct D3D10_SHADER_RESOURCE_VIEW_DESC {
    DXGI_FORMAT Format;
    D3D10_SRV_DIMENSION ViewDimension;
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
    };
} D3D10_SHADER_RESOURCE_VIEW_DESC;

typedef struct D3D10_BOX {
    UINT left;
    UINT top;
    UINT front;
    UINT right;
    UINT bottom;
    UINT back;
} D3D10_BOX;

typedef struct D3D10_SUBRESOURCE_DATA {
    const void *pSysMem;
    UINT SysMemPitch;
    UINT SysMemSlicePitch;
} D3D10_SUBRESOURCE_DATA;

typedef struct D3D10_SO_DECLARATION_ENTRY
{
    const char *SemanticName;
    UINT SemanticIndex;
    BYTE StartComponent;
    BYTE ComponentCount;
    BYTE OutputSlot;
} D3D10_SO_DECLARATION_ENTRY;

typedef enum D3D10_INPUT_CLASSIFICATION {
    D3D10_INPUT_PER_VERTEX_DATA,
    D3D10_INPUT_PER_INSTANCE_DATA,
} D3D10_INPUT_CLASSIFICATION;

typedef struct D3D10_INPUT_ELEMENT_DESC
{
    const char *SemanticName;
    UINT SemanticIndex;
    DXGI_FORMAT Format;
    UINT InputSlot;
    UINT AlignedByteOffset;
    D3D10_INPUT_CLASSIFICATION InputSlotClass;
    UINT InstanceDataStepRate;
} D3D10_INPUT_ELEMENT_DESC;

typedef enum D3D10_QUERY {
    D3D10_QUERY_EVENT,
    D3D10_QUERY_OCCLUSION,
    D3D10_QUERY_TIMESTAMP,
    D3D10_QUERY_TIMESTAMP_DISJOINT,
    D3D10_QUERY_PIPELINE_STATISTICS,
    D3D10_QUERY_OCCLUSION_PREDICATE,
    D3D10_QUERY_SO_STATISTICS,
    D3D10_QUERY_SO_OVERFLOW_PREDICATE,
} D3D10_QUERY;

typedef struct D3D10_QUERY_DESC {
    D3D10_QUERY Query;
    UINT MiscFlags;
} D3D10_QUERY_DESC;

typedef D3D_PRIMITIVE_TOPOLOGY D3D10_PRIMITIVE_TOPOLOGY;

typedef D3D_PRIMITIVE D3D10_PRIMITIVE;

typedef RECT D3D10_RECT;

typedef struct D3D10_VIEWPORT {
    INT TopLeftX;
    INT TopLeftY;
    UINT Width;
    UINT Height;
    FLOAT MinDepth;
    FLOAT MaxDepth;
} D3D10_VIEWPORT;

typedef struct D3D10_MAPPED_TEXTURE2D {
    void *pData;
    UINT RowPitch;
} D3D10_MAPPED_TEXTURE2D;

typedef struct D3D10_MAPPED_TEXTURE3D {
    void *pData;
    UINT RowPitch;
    UINT DepthPitch;
} D3D10_MAPPED_TEXTURE3D;

typedef enum D3D10_CPU_ACCESS_FLAG {
    D3D10_CPU_ACCESS_WRITE = 0x10000,
    D3D10_CPU_ACCESS_READ  = 0x20000
} D3D10_CPU_ACCESS_FLAG;

typedef enum D3D10_RESOURCE_MISC_FLAG {
    D3D10_RESOURCE_MISC_GENERATE_MIPS      = 0x0001,
    D3D10_RESOURCE_MISC_SHARED             = 0x0002,
    D3D10_RESOURCE_MISC_TEXTURECUBE        = 0x0004,
    D3D10_RESOURCE_MISC_SHARED_KEYEDMUTEX  = 0x0010,
    D3D10_RESOURCE_MISC_GDI_COMPATIBLE     = 0x0020
} D3D10_RESOURCE_MISC_FLAG;

typedef enum D3D10_MAP_FLAG {
    D3D10_MAP_FLAG_DO_NOT_WAIT = 0x100000,
} D3D10_MAP_FLAG;

typedef enum D3D10_CLEAR_FLAG {
    D3D10_CLEAR_DEPTH   = 0x1,
    D3D10_CLEAR_STENCIL = 0x2
} D3D10_CLEAR_FLAG;

typedef enum D3D10_COLOR_WRITE_ENABLE {
    D3D10_COLOR_WRITE_ENABLE_RED   = 0x1,
    D3D10_COLOR_WRITE_ENABLE_GREEN = 0x2,
    D3D10_COLOR_WRITE_ENABLE_BLUE  = 0x4,
    D3D10_COLOR_WRITE_ENABLE_ALPHA = 0x8,
    D3D10_COLOR_WRITE_ENABLE_ALL   = (D3D10_COLOR_WRITE_ENABLE_RED  | D3D10_COLOR_WRITE_ENABLE_GREEN |
                                      D3D10_COLOR_WRITE_ENABLE_BLUE | D3D10_COLOR_WRITE_ENABLE_ALPHA)
} D3D10_COLOR_WRITE_ENABLE;

typedef enum D3D10_FORMAT_SUPPORT
{
    D3D10_FORMAT_SUPPORT_BUFFER                   = 0x00000001,
    D3D10_FORMAT_SUPPORT_IA_VERTEX_BUFFER         = 0x00000002,
    D3D10_FORMAT_SUPPORT_IA_INDEX_BUFFER          = 0x00000004,
    D3D10_FORMAT_SUPPORT_SO_BUFFER                = 0x00000008,
    D3D10_FORMAT_SUPPORT_TEXTURE1D                = 0x00000010,
    D3D10_FORMAT_SUPPORT_TEXTURE2D                = 0x00000020,
    D3D10_FORMAT_SUPPORT_TEXTURE3D                = 0x00000040,
    D3D10_FORMAT_SUPPORT_TEXTURECUBE              = 0x00000080,
    D3D10_FORMAT_SUPPORT_SHADER_LOAD              = 0x00000100,
    D3D10_FORMAT_SUPPORT_SHADER_SAMPLE            = 0x00000200,
    D3D10_FORMAT_SUPPORT_SHADER_SAMPLE_COMPARISON = 0x00000400,
    D3D10_FORMAT_SUPPORT_SHADER_SAMPLE_MONO_TEXT  = 0x00000800,
    D3D10_FORMAT_SUPPORT_MIP                      = 0x00001000,
    D3D10_FORMAT_SUPPORT_MIP_AUTOGEN              = 0x00002000,
    D3D10_FORMAT_SUPPORT_RENDER_TARGET            = 0x00004000,
    D3D10_FORMAT_SUPPORT_BLENDABLE                = 0x00008000,
    D3D10_FORMAT_SUPPORT_DEPTH_STENCIL            = 0x00010000,
    D3D10_FORMAT_SUPPORT_CPU_LOCKABLE             = 0x00020000,
    D3D10_FORMAT_SUPPORT_MULTISAMPLE_RESOLVE      = 0x00040000,
    D3D10_FORMAT_SUPPORT_DISPLAY                  = 0x00080000,
    D3D10_FORMAT_SUPPORT_CAST_WITHIN_BIT_LAYOUT   = 0x00100000,
    D3D10_FORMAT_SUPPORT_MULTISAMPLE_RENDERTARGET = 0x00200000,
    D3D10_FORMAT_SUPPORT_MULTISAMPLE_LOAD         = 0x00400000,
    D3D10_FORMAT_SUPPORT_SHADER_GATHER            = 0x00800000,
    D3D10_FORMAT_SUPPORT_BACK_BUFFER_CAST         = 0x01000000,
} D3D10_FORMAT_SUPPORT;

typedef enum D3D10_TEXTURECUBE_FACE {
    D3D10_TEXTURECUBE_FACE_POSITIVE_X,
    D3D10_TEXTURECUBE_FACE_NEGATIVE_X,
    D3D10_TEXTURECUBE_FACE_POSITIVE_Y,
    D3D10_TEXTURECUBE_FACE_NEGATIVE_Y,
    D3D10_TEXTURECUBE_FACE_POSITIVE_Z,
    D3D10_TEXTURECUBE_FACE_NEGATIVE_Z,
} D3D10_TEXTURECUBE_FACE;

typedef enum D3D10_ASYNC_GETDATA_FLAG {
    D3D10_ASYNC_GETDATA_DONOTFLUSH = 0x1,
} D3D10_ASYNC_GETDATA_FLAG;

typedef enum D3D10_FILTER_TYPE {
    D3D10_FILTER_TYPE_POINT,
    D3D10_FILTER_TYPE_LINEAR
} D3D10_FILTER_TYPE;

typedef enum D3D10_QUERY_MISC_FLAG {
    D3D10_QUERY_MISC_PREDICATEHINT = 0x1
} D3D10_QUERY_MISC_FLAG;

typedef struct D3D10_QUERY_DATA_TIMESTAMP_DISJOINT {
    UINT64 Frequency;
    BOOL Disjoint;
} D3D10_QUERY_DATA_TIMESTAMP_DISJOINT;

typedef struct D3D10_QUERY_DATA_PIPELINE_STATISTICS {
    UINT64 IAVertices;
    UINT64 IAPrimitives;
    UINT64 VSInvocations;
    UINT64 GSInvocations;
    UINT64 GSPrimitives;
    UINT64 CInvocations;
    UINT64 CPrimitives;
    UINT64 PSInvocations;
} D3D10_QUERY_DATA_PIPELINE_STATISTICS;

typedef struct D3D10_QUERY_DATA_SO_STATISTICS {
    UINT64 NumPrimitivesWritten;
    UINT64 PrimitivesStorageNeeded;
} D3D10_QUERY_DATA_SO_STATISTICS;

typedef enum D3D10_CREATE_DEVICE_FLAG {
    D3D10_CREATE_DEVICE_SINGLETHREADED                           = 0x1,
    D3D10_CREATE_DEVICE_DEBUG                                    = 0x2,
    D3D10_CREATE_DEVICE_SWITCH_TO_REF                            = 0x4,
    D3D10_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS = 0x8,
    D3D10_CREATE_DEVICE_ALLOW_NULL_FROM_MAP                      = 0x10,
    D3D10_CREATE_DEVICE_BGRA_SUPPORT                             = 0x20,
    D3D10_CREATE_DEVICE_STRICT_VALIDATION                        = 0x0200
} D3D10_CREATE_DEVICE_FLAG;

/* Core */

struct ID3D10DeviceChild : public IUnknown
{
    static constexpr GUID guid = {0x9b7e4c00,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

        virtual void GetDevice(
            /*out*/ ID3D10Device **ppDevice) = 0;
        virtual HRESULT GetPrivateData(
            /*in*/ REFGUID guid,
            /*inout*/ UINT *pDataSize,
            /*out*/ void *pData) = 0;
        virtual HRESULT SetPrivateData(
            /*in*/ REFGUID guid,
            /*in*/ UINT DataSize,
            /*in*/ const void *pData) = 0;
        virtual HRESULT SetPrivateDataInterface(
            /*in*/ REFGUID guid,
            /*in*/ const IUnknown *pData) = 0;
};

struct ID3D10Resource : public ID3D10DeviceChild
{
    static constexpr GUID guid = {0x9b7e4c01,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

        virtual void GetType(
            /*out*/ D3D10_RESOURCE_DIMENSION *rType) = 0;
        virtual void SetEvictionPriority(
            /*in*/ UINT EvictionPriority) = 0;
        virtual UINT GetEvictionPriority() = 0;
};

struct ID3D10Buffer : public ID3D10Resource
{
    static constexpr GUID guid = {0x9b7e4c02,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

        virtual HRESULT Map(
            /*in*/ D3D10_MAP MapType,
            /*in*/ UINT MapFlags,
            /*out*/ void **ppData) = 0;
        virtual void Unmap() = 0;
        virtual void GetDesc(
            /*out*/ D3D10_BUFFER_DESC *pDesc) = 0;
};

struct ID3D10Texture1D : public ID3D10Resource
{
    static constexpr GUID guid = {0x9b7e4c03,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xF0}};

        virtual HRESULT Map(
            /*in*/ UINT Subresource,
            /*in*/ D3D10_MAP MapType,
            /*in*/ UINT MapFlags,
            /*out*/ void **ppData) = 0;
        virtual void Unmap(
            /*in*/ UINT Subresource) = 0;
        virtual void GetDesc(
            /*out*/ D3D10_TEXTURE1D_DESC *pDesc) = 0;
};

struct ID3D10Texture2D : public ID3D10Resource
{
    static constexpr GUID guid = {0x9b7e4c04,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xF0}};

        virtual HRESULT Map(
            /*in*/ UINT Subresource,
            /*in*/ D3D10_MAP MapType,
            /*in*/ UINT MapFlags,
            /*out*/ D3D10_MAPPED_TEXTURE2D *pMappedTex2D) = 0;
        virtual void Unmap(
            /*in*/ UINT Subresource) = 0;
        virtual void GetDesc(
            /*out*/ D3D10_TEXTURE2D_DESC *pDesc) = 0;
};

struct ID3D10Texture3D : public ID3D10Resource
{
    static constexpr GUID guid = {0x9b7e4c05,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xF0}};

        virtual HRESULT Map(
            /*in*/ UINT Subresource,
            /*in*/ D3D10_MAP MapType,
            /*in*/ UINT MapFlags,
            /*out*/ D3D10_MAPPED_TEXTURE3D *pMappedTex3D) = 0;
        virtual void Unmap(
            /*in*/ UINT Subresource) = 0;
        virtual void GetDesc(
            /*out*/ D3D10_TEXTURE3D_DESC *pDesc) = 0;
};

struct ID3D10View : public ID3D10DeviceChild
{
    static constexpr GUID guid = {0xc902b03f,0x60a7,0x49ba,{0x99,0x36,0x2a,0x3a,0xb3,0x7a,0x7e,0x33}};

        virtual void GetResource(
            /*out*/ ID3D10Resource **ppResource) = 0;
};

struct ID3D10DepthStencilView : public ID3D10View
{
    static constexpr GUID guid = {0x9b7e4c09,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

        virtual void GetDesc(
            /*out*/ D3D10_DEPTH_STENCIL_VIEW_DESC *pDesc) = 0;
};

struct ID3D10RenderTargetView : public ID3D10View
{
    static constexpr GUID guid = {0x9b7e4c08,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

        virtual void GetDesc(
            /*out*/ D3D10_RENDER_TARGET_VIEW_DESC *pDesc) = 0;
};

struct ID3D10ShaderResourceView : public  ID3D10View
{
    static constexpr GUID guid = {0x9b7e4c07,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

        virtual void GetDesc(
            /*out*/ D3D10_SHADER_RESOURCE_VIEW_DESC *pDesc) = 0;
};

struct ID3D10BlendState : public ID3D10DeviceChild
{
    static constexpr GUID guid = {0xedad8d19,0x8a35,0x4d6d,{0x85,0x66,0x2e,0xa2,0x76,0xcd,0xe1,0x61}};

    virtual void GetDesc(
            /*out*/ D3D10_BLEND_DESC *pDesc) = 0;
};

struct ID3D10DepthStencilState : public ID3D10DeviceChild
{
    static constexpr GUID guid = {0x2b4b1cc8,0xa4ad,0x41f8,{0x83,0x22,0xca,0x86,0xfc,0x3e,0xc6,0x75}};

    virtual void GetDesc(
            /*out*/ D3D10_DEPTH_STENCIL_DESC *pDesc) = 0;
};

struct ID3D10GeometryShader : public  ID3D10DeviceChild
{
    static constexpr GUID guid = {0x6316be88,0x54cd,0x4040,{0xab,0x44,0x20,0x46,0x1b,0xc8,0x1f,0x68}};

};

struct ID3D10InputLayout : public  ID3D10DeviceChild
{
    static constexpr GUID guid = {0x9b7e4c0b,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

};

struct ID3D10PixelShader : public  ID3D10DeviceChild
{
    static constexpr GUID guid = {0x4968b601,0x9d00,0x4cde,{0x83,0x46,0x8e,0x7f,0x67,0x58,0x19,0xb6}};

};

struct ID3D10RasterizerState : public  ID3D10DeviceChild
{
    static constexpr GUID guid = {0xa2a07292,0x89af,0x4345,{0xbe,0x2e,0xc5,0x3d,0x9f,0xbb,0x6e,0x9f}};

    virtual void GetDesc(
            /*out*/ D3D10_RASTERIZER_DESC *pDesc) = 0;
};

struct ID3D10SamplerState : public  ID3D10DeviceChild
{
    static constexpr GUID guid = {0x9b7e4c0c,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

    virtual void GetDesc(
            /*out*/ D3D10_SAMPLER_DESC *pDesc) = 0;
};

struct ID3D10VertexShader : public  ID3D10DeviceChild
{
    static constexpr GUID guid = {0x9b7e4c0a,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

};

struct ID3D10Asynchronous : public  ID3D10DeviceChild
{
    static constexpr GUID guid = {0x9b7e4c0d,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

    virtual void Begin() = 0;
    virtual void End() = 0;
    virtual HRESULT GetData(
            /*out*/ void *pData,
            /*in*/ UINT DataSize,
            /*in*/ UINT GetDataFlags) = 0;
    virtual UINT GetDataSize() = 0;
};

struct ID3D10Counter : public  ID3D10Asynchronous
{
    static constexpr GUID guid = {0x9b7e4c11,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

    virtual void GetDesc(
            /*out*/ D3D10_COUNTER_DESC *pDesc) = 0;
};

struct ID3D10Query : public ID3D10Asynchronous
{
    static constexpr GUID guid = {0x9b7e4C0e,0x342C,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

    virtual void GetDesc(
            /*out*/ D3D10_QUERY_DESC *pDesc) = 0;
};

struct ID3D10Predicate : public ID3D10Query
{
    static constexpr GUID guid = {0x9b7e4c10,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

};

struct ID3D10Device : public IUnknown
{
    static constexpr GUID guid = {0x9b7e4c0f,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

        virtual void VSSetConstantBuffers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumBuffers,
            /*in*/ ID3D10Buffer *const *ppConstantBuffers) = 0;
        virtual void PSSetShaderResources(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumViews,
            /*in*/ ID3D10ShaderResourceView *const *ppShaderResourceViews) = 0;
        virtual void PSSetShader(
            /*in*/ ID3D10PixelShader *pPixelShader) = 0;
        virtual void PSSetSamplers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumSamplers,
            /*in*/ID3D10SamplerState *const *ppSamplers) = 0;
        virtual void VSSetShader(
            /*in*/ ID3D10VertexShader *pVertexShader) = 0;
        virtual void DrawIndexed(
            /*in*/ UINT IndexCount,
            /*in*/ UINT StartIndexLocation,
            /*in*/ INT BaseVertexLocation) = 0;
        virtual void Draw(
            /*in*/ UINT VertexCount,
            /*in*/ UINT StartVertexLocation) = 0;
        virtual void PSSetConstantBuffers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumBuffers,
            /*in*/ ID3D10Buffer *const *ppConstantBuffers) = 0;
        virtual void IASetInputLayout(
            /*in*/ ID3D10InputLayout *pInputLayout) = 0;
        virtual void IASetVertexBuffers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumBuffers,
            /*in*/ ID3D10Buffer *const *ppVertexBuffers,
            /*in*/ const UINT *pStrides,
            /*in*/ const UINT *pOffsets) = 0;
        virtual void IASetIndexBuffer(
            /*in*/ ID3D10Buffer *pIndexBuffer,
            /*in*/ DXGI_FORMAT Format,
            /*in*/ UINT Offset) = 0;
        virtual void DrawIndexedInstanced(
            /*in*/ UINT IndexCountPerInstance,
            /*in*/ UINT InstanceCount,
            /*in*/ UINT StartIndexLocation,
            /*in*/ INT BaseVertexLocation,
            /*in*/ UINT StartInstanceLocation) = 0;
        virtual void DrawInstanced(
            /*in*/ UINT VertexCountPerInstance,
            /*in*/ UINT InstanceCount,
            /*in*/ UINT StartVertexLocation,
            /*in*/ UINT StartInstanceLocation) = 0;
        virtual void GSSetConstantBuffers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumBuffers,
            /*in*/ ID3D10Buffer *const *ppConstantBuffers) = 0;
        virtual void GSSetShader(
            /*in*/ ID3D10GeometryShader *pShader) = 0;
        virtual void IASetPrimitiveTopology(
            /*in*/ D3D10_PRIMITIVE_TOPOLOGY Topology) = 0;
        virtual void VSSetShaderResources(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumViews,
            /*in*/ ID3D10ShaderResourceView *const *ppShaderResourceViews) = 0;
        virtual void VSSetSamplers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumSamplers,
            /*in*/ ID3D10SamplerState *const *ppSamplers) = 0;
        virtual void SetPredication(
            /*in*/ ID3D10Predicate *pPredicate,
            /*in*/ BOOL PredicateValue) = 0;
        virtual void GSSetShaderResources(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumViews,
            /*in*/ ID3D10ShaderResourceView * const *ppShaderResourceViews) = 0;
        virtual void GSSetSamplers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumSamplers,
            /*in*/ ID3D10SamplerState *const *ppSamplers) = 0;
        virtual void OMSetRenderTargets(
            /*in*/ UINT NumViews,
            /*in*/ ID3D10RenderTargetView *const *ppRenderTargetViews,
            /*in*/ ID3D10DepthStencilView *pDepthStencilView) = 0;
        virtual void OMSetBlendState(
            /*in*/ ID3D10BlendState *pBlendState,
            /*in*/ const FLOAT BlendFactor[4],
            /*in*/ UINT SampleMask) = 0;
        virtual void OMSetDepthStencilState(
            /*in*/ ID3D10DepthStencilState *pDepthStencilState,
            /*in*/ UINT StencilRef) = 0;
        virtual void SOSetTargets(
            /*in*/ UINT NumBuffers,
            /*in*/ ID3D10Buffer *const *ppSOTargets,
            /*in*/ const UINT *pOffsets) = 0;
        virtual void DrawAuto() = 0;
        virtual void RSSetState(
            /*in*/ ID3D10RasterizerState *pRasterizerState) = 0;
        virtual void RSSetViewports(
            /*in*/ UINT NumViewports,
            /*in*/ const D3D10_VIEWPORT *pViewports) = 0;
        virtual void RSSetScissorRects(
            /*in*/ UINT NumRects,
            /*in*/ const D3D10_RECT *pRects) = 0;
        virtual void CopySubresourceRegion(
            /*in*/ ID3D10Resource *pDstResource,
            /*in*/ UINT DstSubresource,
            /*in*/ UINT DstX,
            /*in*/ UINT DstY,
            /*in*/ UINT DstZ,
            /*in*/ ID3D10Resource *pSrcResource,
            /*in*/ UINT SrcSubresource,
            /*in*/ const D3D10_BOX *pSrcBox) = 0;
        virtual void CopyResource(
            /*in*/ ID3D10Resource *pDstResource,
            /*in*/ ID3D10Resource *pSrcResource) = 0;
        virtual void UpdateSubresource(
            /*in*/ ID3D10Resource *pDstResource,
            /*in*/ UINT DstSubresource,
            /*in*/ const D3D10_BOX *pDstBox,
            /*in*/ const void *pSrcData,
            /*in*/ UINT SrcRowPitch,
            /*in*/ UINT SrcDepthPitch) = 0;
        virtual void ClearRenderTargetView(
            /*in*/ ID3D10RenderTargetView *pRenderTargetView,
            /*in*/ const FLOAT ColorRGBA[4]) = 0;
        virtual void ClearDepthStencilView(
            /*in*/ ID3D10DepthStencilView *pDepthStencilView,
            /*in*/ UINT ClearFlags,
            /*in*/ FLOAT Depth,
            /*in*/ UINT8 Stencil) = 0;
        virtual void GenerateMips(
            /*in*/ ID3D10ShaderResourceView *pShaderResourceView) = 0;
        virtual void ResolveSubresource(
            /*in*/ ID3D10Resource *pDstResource,
            /*in*/ UINT DstSubresource,
            /*in*/ ID3D10Resource *pSrcResource,
            /*in*/ UINT SrcSubresource,
            /*in*/ DXGI_FORMAT Format) = 0;
        virtual void VSGetConstantBuffers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumBuffers,
            /*out*/ ID3D10Buffer **ppConstantBuffers) = 0;
        virtual void PSGetShaderResources(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumViews,
            /*out*/ ID3D10ShaderResourceView **ppShaderResourceViews) = 0;
        virtual void PSGetShader(
            /*out*/ ID3D10PixelShader **ppPixelShader) = 0;
        virtual void PSGetSamplers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumSamplers,
            /*out*/ ID3D10SamplerState **ppSamplers) = 0;
        virtual void VSGetShader(
            /*out*/ ID3D10VertexShader **ppVertexShader) = 0;
        virtual void PSGetConstantBuffers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumBuffers,
            /*out*/ ID3D10Buffer **ppConstantBuffers) = 0;
        virtual void IAGetInputLayout(
            /*out*/ ID3D10InputLayout **ppInputLayout) = 0;
        virtual void IAGetVertexBuffers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumBuffers,
            /*out*/ ID3D10Buffer **ppVertexBuffers,
            /*out*/ UINT *pStrides,
            /*out*/ UINT *pOffsets) = 0;
        virtual void IAGetIndexBuffer(
            /*out*/ ID3D10Buffer **pIndexBuffer,
            /*out*/ DXGI_FORMAT *Format,
            /*out*/ UINT *Offset) = 0;
        virtual void GSGetConstantBuffers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumBuffers,
            /*out*/ ID3D10Buffer **ppConstantBuffers) = 0;
        virtual void GSGetShader(
            /*out*/ ID3D10GeometryShader **ppGeometryShader) = 0;
        virtual void IAGetPrimitiveTopology(
            /*out*/ D3D10_PRIMITIVE_TOPOLOGY *pTopology) = 0;
        virtual void VSGetShaderResources(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumViews,
            /*out*/ ID3D10ShaderResourceView **ppShaderResourceViews) = 0;
        virtual void VSGetSamplers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumSamplers,
            /*out*/ ID3D10SamplerState **ppSamplers) = 0;
        virtual void GetPredication(
            /*out*/ ID3D10Predicate **ppPredicate,
            /*out*/ BOOL *pPredicateValue) = 0;
        virtual void GSGetShaderResources(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumViews,
            /*out*/ ID3D10ShaderResourceView **ppShaderResourceViews) = 0;
        virtual void GSGetSamplers(
            /*in*/ UINT StartSlot,
            /*in*/ UINT NumSamplers,
            /*out*/ ID3D10SamplerState **ppSamplers) = 0;
        virtual void OMGetRenderTargets(
            /*in*/ UINT NumViews,
            /*out*/ ID3D10RenderTargetView **ppRenderTargetViews,
            /*out*/ ID3D10DepthStencilView **ppDepthStencilView) = 0;
        virtual void OMGetBlendState(
            /*out*/ ID3D10BlendState **ppBlendState,
            /*out*/ FLOAT BlendFactor[4],
            /*out*/ UINT *pSampleMask) = 0;
        virtual void OMGetDepthStencilState(
            /*out*/ ID3D10DepthStencilState **ppDepthStencilState,
            /*out*/ UINT *pStencilRef) = 0;
        virtual void SOGetTargets(
            /*in*/ UINT NumBuffers,
            /*out*/ ID3D10Buffer **ppSOTargets,
            /*out*/ UINT *pOffsets) = 0;
        virtual void RSGetState(
            /*out*/ ID3D10RasterizerState **ppRasterizerState) = 0;
        virtual void RSGetViewports(
            /*inout*/ UINT *NumViewports,
            /*out*/ D3D10_VIEWPORT *pViewports) = 0;
        virtual void RSGetScissorRects(
            /*inout*/ UINT *NumRects,
            /*out*/ D3D10_RECT *pRects) = 0;
        virtual HRESULT GetDeviceRemovedReason() = 0;
        virtual HRESULT SetExceptionMode(
            /*in*/ UINT RaiseFlags) = 0;
        virtual UINT GetExceptionMode() = 0;
        virtual HRESULT GetPrivateData(
            /*in*/ REFGUID guid,
            /*inout*/ UINT *pDataSize,
            /*out*/ void *pData) = 0;
        virtual HRESULT SetPrivateData(
            /*in*/ REFGUID guid,
            /*in*/ UINT DataSize,
            /*in*/ const void *pData) = 0;
        virtual HRESULT SetPrivateDataInterface(
            /*in*/ REFGUID guid,
            /*in*/ const IUnknown *pData) = 0;
        virtual void ClearState() = 0;
        virtual void Flush() = 0;
        virtual HRESULT CreateBuffer(
            /*in*/ const D3D10_BUFFER_DESC *pDesc,
            /*in*/ const D3D10_SUBRESOURCE_DATA *pInitialData,
            /*out*/ ID3D10Buffer **ppBuffer) = 0;
        virtual HRESULT CreateTexture1D(
            /*in*/ const D3D10_TEXTURE1D_DESC *pDesc,
            /*in*/ const D3D10_SUBRESOURCE_DATA *pInitialData,
            /*out*/ ID3D10Texture1D **ppTexture1D) = 0;
        virtual HRESULT CreateTexture2D(
            /*in*/ const D3D10_TEXTURE2D_DESC *pDesc,
            /*in*/ const D3D10_SUBRESOURCE_DATA *pInitialData,
            /*out*/ ID3D10Texture2D **ppTexture2D) = 0;
        virtual HRESULT CreateTexture3D(
            /*in*/ const D3D10_TEXTURE3D_DESC *pDesc,
            /*in*/ const D3D10_SUBRESOURCE_DATA *pInitialData,
            /*out*/ ID3D10Texture3D **ppTexture3D) = 0;
        virtual HRESULT CreateShaderResourceView(
            /*in*/ ID3D10Resource *pResource,
            /*in*/ const D3D10_SHADER_RESOURCE_VIEW_DESC *pDesc,
            /*out*/ ID3D10ShaderResourceView **ppSRView) = 0;
        virtual HRESULT CreateRenderTargetView(
            /*in*/ ID3D10Resource *pResource,
            /*in*/ const D3D10_RENDER_TARGET_VIEW_DESC *pDesc,
            /*out*/ ID3D10RenderTargetView **ppRTView) = 0;
        virtual HRESULT CreateDepthStencilView(
            /*in*/ ID3D10Resource *pResource,
            /*in*/ const D3D10_DEPTH_STENCIL_VIEW_DESC *pDesc,
            /*out*/ ID3D10DepthStencilView **ppDepthStencilView) = 0;
        virtual HRESULT CreateInputLayout(
            /*in*/ const D3D10_INPUT_ELEMENT_DESC *pInputElementDescs,
            /*in*/ UINT NumElements,
            /*in*/ const void *pShaderBytecodeWithInputSignature,
            /*in*/ SIZE_T BytecodeLength,
            /*out*/ ID3D10InputLayout **ppInputLayout) = 0;
        virtual HRESULT CreateVertexShader(
            /*in*/ const void *pShaderBytecode,
            /*in*/ SIZE_T BytecodeLength,
            /*out*/ ID3D10VertexShader **ppVertexShader) = 0;
        virtual HRESULT CreateGeometryShader(
            /*in*/ const void *pShaderBytecode,
            /*in*/ SIZE_T BytecodeLength,
            /*out*/ ID3D10GeometryShader **ppGeometryShader) = 0;
        virtual HRESULT CreateGeometryShaderWithStreamOutput(
            /*in*/ const void *pShaderBytecode,
            /*in*/ SIZE_T BytecodeLength,
            /*in*/ const D3D10_SO_DECLARATION_ENTRY *pSODeclaration,
            /*in*/ UINT NumEntries,
            /*in*/ UINT OutputStreamStride,
            /*out*/ ID3D10GeometryShader **ppGeometryShader) = 0;
        virtual HRESULT CreatePixelShader(
            /*in*/ const void *pShaderBytecode,
            /*in*/ SIZE_T BytecodeLength,
            /*out*/ ID3D10PixelShader **ppPixelShader) = 0;
        virtual HRESULT CreateBlendState(
            /*in*/ const D3D10_BLEND_DESC *pBlendStateDesc,
            /*out*/ ID3D10BlendState **ppBlendState) = 0;
        virtual HRESULT CreateDepthStencilState(
            /*in*/ const D3D10_DEPTH_STENCIL_DESC *pDepthStencilDesc,
            /*out*/ ID3D10DepthStencilState **ppDepthStencilState) = 0;
        virtual HRESULT CreateRasterizerState(
            /*in*/ const D3D10_RASTERIZER_DESC *pRasterizerDesc,
            /*out*/ ID3D10RasterizerState **ppRasterizerState) = 0;
        virtual HRESULT CreateSamplerState(
            /*in*/ const D3D10_SAMPLER_DESC *pSamplerDesc,
            /*out*/ ID3D10SamplerState **ppSamplerState) = 0;
        virtual HRESULT CreateQuery(
            /*in*/ const D3D10_QUERY_DESC *pQueryDesc,
            /*out*/ ID3D10Query **ppQuery) = 0;
        virtual HRESULT CreatePredicate(
            /*in*/ const D3D10_QUERY_DESC *pPredicateDesc,
            /*out*/ ID3D10Predicate **ppPredicate) = 0;
        virtual HRESULT CreateCounter(
            /*in*/ const D3D10_COUNTER_DESC *pCounterDesc,
            /*out*/ ID3D10Counter **ppCounter) = 0;
        virtual HRESULT CheckFormatSupport(
            /*in*/ DXGI_FORMAT Format,
            /*out*/ UINT *pFormatSupport) = 0;
        virtual HRESULT CheckMultisampleQualityLevels(
            /*in*/ DXGI_FORMAT Format,
            /*in*/ UINT SampleCount,
            /*out*/ UINT *pNumQualityLevels) = 0;
        virtual void CheckCounterInfo(
            /*out*/ D3D10_COUNTER_INFO *pCounterInfo) = 0;
        virtual HRESULT CheckCounter(
            /*in*/ const D3D10_COUNTER_DESC *pDesc,
            /*out*/ D3D10_COUNTER_TYPE *pType,
            /*out*/ UINT *pActiveCounters,
            /*out*/ char *name,
            /*inout*/ UINT *pNameLength,
            /*out*/ char *units,
            /*inout*/ UINT *pUnitsLength,
            /*out*/ char *description,
            /*inout*/ UINT *pDescriptionLength) = 0;
        virtual UINT GetCreationFlags() = 0;
        virtual HRESULT OpenSharedResource(
            /*in*/ HANDLE hResource,
            /*in*/ REFIID ReturnedInterface,
            /*out*/ void **ppResource) = 0;
        virtual void SetTextFilterSize(
            /*in*/ UINT Width,
            /*in*/ UINT Height) = 0;
        virtual void GetTextFilterSize(
            /*out*/ UINT *pWidth,
            /*out*/ UINT *pHeight) = 0;
};

struct ID3D10Multithread : public IUnknown
{
    static constexpr GUID guid = {0x9b7e4e00,0x342c,0x4106,{0xa1,0x9f,0x4f,0x27,0x04,0xf6,0x89,0xf0}};

        virtual void Enter() = 0;
        virtual void Leave() = 0;
        virtual BOOL SetMultithreadProtected(
            /*in*/ BOOL bMTProtect) = 0;
        virtual BOOL GetMultithreadProtected() = 0;
};

#endif