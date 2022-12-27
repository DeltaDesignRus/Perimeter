#pragma once
/*
    #version:1# (machine generated, don't edit!)

    Generated by sokol-shdc (https://github.com/floooh/sokol-tools)

    Cmdline: sokol-shdc --input color_texture.glsl --output color.h --slang glsl330:glsl100:glsl300es:metal_macos --ifdef --defines=SHADER_COLOR --reflection --module color --format=sokol

    Overview:

        Shader program 'program':
            Get shader desc: color_program_shader_desc(sg_query_backend());
            Vertex shader: vs
                Attribute slots:
                    ATTR_color_vs_vs_position = 0
                    ATTR_color_vs_vs_color = 1
                Uniform block 'vs_params':
                    C struct: color_vs_params_t
                    Bind slot: SLOT_color_vs_params = 0
            Fragment shader: fs


    Shader descriptor structs:

        sg_shader program = sg_make_shader(color_program_shader_desc(sg_query_backend()));

    Vertex attribute locations for vertex shader 'vs':

        sg_pipeline pip = sg_make_pipeline(&(sg_pipeline_desc){
            .layout = {
                .attrs = {
                    [ATTR_color_vs_vs_position] = { ... },
                    [ATTR_color_vs_vs_color] = { ... },
                },
            },
            ...});

    Image bind slots, use as index in sg_bindings.vs_images[] or .fs_images[]


    Bind slot and C-struct for uniform block 'vs_params':

        color_vs_params_t vs_params = {
            .un_mvp = ...;
        };
        sg_apply_uniforms(SG_SHADERSTAGE_[VS|FS], SLOT_color_vs_params, &SG_RANGE(vs_params));

*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#if !defined(SOKOL_SHDC_ALIGN)
  #if defined(_MSC_VER)
    #define SOKOL_SHDC_ALIGN(a) __declspec(align(a))
  #else
    #define SOKOL_SHDC_ALIGN(a) __attribute__((aligned(a)))
  #endif
#endif
#define ATTR_color_vs_vs_position (0)
#define ATTR_color_vs_vs_color (1)
#define SLOT_color_vs_params (0)
#pragma pack(push,1)
SOKOL_SHDC_ALIGN(16) typedef struct color_vs_params_t {
    Mat4f un_mvp;
} color_vs_params_t;
#pragma pack(pop)
#if defined(SOKOL_GLCORE33)
/*
    #version 330
    
    uniform vec4 vs_params[4];
    layout(location = 0) in vec3 vs_position;
    out vec4 fs_color;
    layout(location = 1) in vec4 vs_color;
    
    void main()
    {
        gl_Position = mat4(vs_params[0], vs_params[1], vs_params[2], vs_params[3]) * vec4(vs_position, 1.0);
        fs_color = vs_color;
    }
    
*/
static const char color_vs_source_glsl330[290] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x33,0x30,0x0a,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x76,0x73,0x5f,0x70,0x61,
    0x72,0x61,0x6d,0x73,0x5b,0x34,0x5d,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,
    0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x30,0x29,0x20,0x69,0x6e,
    0x20,0x76,0x65,0x63,0x33,0x20,0x76,0x73,0x5f,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,
    0x6e,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x34,0x20,0x66,0x73,0x5f,0x63,
    0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,
    0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x31,0x29,0x20,0x69,0x6e,0x20,0x76,0x65,
    0x63,0x34,0x20,0x76,0x73,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x0a,0x76,0x6f,
    0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,
    0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x6d,0x61,
    0x74,0x34,0x28,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x30,0x5d,0x2c,
    0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x31,0x5d,0x2c,0x20,0x76,
    0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x32,0x5d,0x2c,0x20,0x76,0x73,0x5f,
    0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x33,0x5d,0x29,0x20,0x2a,0x20,0x76,0x65,0x63,
    0x34,0x28,0x76,0x73,0x5f,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x2c,0x20,0x31,
    0x2e,0x30,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x73,0x5f,0x63,0x6f,0x6c,0x6f,
    0x72,0x20,0x3d,0x20,0x76,0x73,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x7d,0x0a,
    0x0a,0x00,
};
/*
    #version 330
    
    in vec4 fs_color;
    layout(location = 0) out vec4 frag_color;
    
    void main()
    {
        frag_color = fs_color;
    }
    
*/
static const char color_fs_source_glsl330[120] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x33,0x30,0x0a,0x0a,0x69,0x6e,
    0x20,0x76,0x65,0x63,0x34,0x20,0x66,0x73,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,
    0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,
    0x3d,0x20,0x30,0x29,0x20,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x34,0x20,0x66,0x72,
    0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,
    0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,
    0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x66,0x73,0x5f,0x63,0x6f,0x6c,
    0x6f,0x72,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
#endif /* SOKOL_GLCORE33 */
#if defined(SOKOL_GLES2)
/*
    #version 100
    
    uniform vec4 vs_params[4];
    attribute vec3 vs_position;
    varying vec4 fs_color;
    attribute vec4 vs_color;
    
    void main()
    {
        gl_Position = mat4(vs_params[0], vs_params[1], vs_params[2], vs_params[3]) * vec4(vs_position, 1.0);
        fs_color = vs_color;
    }
    
*/
static const char color_vs_source_glsl100[266] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x31,0x30,0x30,0x0a,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x76,0x73,0x5f,0x70,0x61,
    0x72,0x61,0x6d,0x73,0x5b,0x34,0x5d,0x3b,0x0a,0x61,0x74,0x74,0x72,0x69,0x62,0x75,
    0x74,0x65,0x20,0x76,0x65,0x63,0x33,0x20,0x76,0x73,0x5f,0x70,0x6f,0x73,0x69,0x74,
    0x69,0x6f,0x6e,0x3b,0x0a,0x76,0x61,0x72,0x79,0x69,0x6e,0x67,0x20,0x76,0x65,0x63,
    0x34,0x20,0x66,0x73,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x61,0x74,0x74,0x72,
    0x69,0x62,0x75,0x74,0x65,0x20,0x76,0x65,0x63,0x34,0x20,0x76,0x73,0x5f,0x63,0x6f,
    0x6c,0x6f,0x72,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,
    0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,
    0x69,0x6f,0x6e,0x20,0x3d,0x20,0x6d,0x61,0x74,0x34,0x28,0x76,0x73,0x5f,0x70,0x61,
    0x72,0x61,0x6d,0x73,0x5b,0x30,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,
    0x6d,0x73,0x5b,0x31,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,
    0x5b,0x32,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x33,
    0x5d,0x29,0x20,0x2a,0x20,0x76,0x65,0x63,0x34,0x28,0x76,0x73,0x5f,0x70,0x6f,0x73,
    0x69,0x74,0x69,0x6f,0x6e,0x2c,0x20,0x31,0x2e,0x30,0x29,0x3b,0x0a,0x20,0x20,0x20,
    0x20,0x66,0x73,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x76,0x73,0x5f,0x63,
    0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #version 100
    precision mediump float;
    precision highp int;
    
    varying highp vec4 fs_color;
    
    void main()
    {
        gl_FragData[0] = fs_color;
    }
    
*/
static const char color_fs_source_glsl100[139] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x31,0x30,0x30,0x0a,0x70,0x72,0x65,
    0x63,0x69,0x73,0x69,0x6f,0x6e,0x20,0x6d,0x65,0x64,0x69,0x75,0x6d,0x70,0x20,0x66,
    0x6c,0x6f,0x61,0x74,0x3b,0x0a,0x70,0x72,0x65,0x63,0x69,0x73,0x69,0x6f,0x6e,0x20,
    0x68,0x69,0x67,0x68,0x70,0x20,0x69,0x6e,0x74,0x3b,0x0a,0x0a,0x76,0x61,0x72,0x79,
    0x69,0x6e,0x67,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x76,0x65,0x63,0x34,0x20,0x66,
    0x73,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,
    0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x67,0x6c,0x5f,0x46,
    0x72,0x61,0x67,0x44,0x61,0x74,0x61,0x5b,0x30,0x5d,0x20,0x3d,0x20,0x66,0x73,0x5f,
    0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
#endif /* SOKOL_GLES2 */
#if defined(SOKOL_GLES3)
/*
    #version 300 es
    
    uniform vec4 vs_params[4];
    layout(location = 0) in vec3 vs_position;
    out vec4 fs_color;
    layout(location = 1) in vec4 vs_color;
    
    void main()
    {
        gl_Position = mat4(vs_params[0], vs_params[1], vs_params[2], vs_params[3]) * vec4(vs_position, 1.0);
        fs_color = vs_color;
    }
    
*/
static const char color_vs_source_glsl300es[293] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x30,0x30,0x20,0x65,0x73,0x0a,
    0x0a,0x75,0x6e,0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x76,0x73,
    0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x34,0x5d,0x3b,0x0a,0x6c,0x61,0x79,0x6f,
    0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x30,0x29,
    0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x33,0x20,0x76,0x73,0x5f,0x70,0x6f,0x73,0x69,
    0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x34,0x20,0x66,
    0x73,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,
    0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x31,0x29,0x20,0x69,0x6e,
    0x20,0x76,0x65,0x63,0x34,0x20,0x76,0x73,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,
    0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,
    0x20,0x20,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x3d,
    0x20,0x6d,0x61,0x74,0x34,0x28,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,
    0x30,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x31,0x5d,
    0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x32,0x5d,0x2c,0x20,
    0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x33,0x5d,0x29,0x20,0x2a,0x20,
    0x76,0x65,0x63,0x34,0x28,0x76,0x73,0x5f,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,
    0x2c,0x20,0x31,0x2e,0x30,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x73,0x5f,0x63,
    0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x76,0x73,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,
    0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #version 300 es
    precision mediump float;
    precision highp int;
    
    in highp vec4 fs_color;
    layout(location = 0) out highp vec4 frag_color;
    
    void main()
    {
        frag_color = fs_color;
    }
    
*/
static const char color_fs_source_glsl300es[181] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x30,0x30,0x20,0x65,0x73,0x0a,
    0x70,0x72,0x65,0x63,0x69,0x73,0x69,0x6f,0x6e,0x20,0x6d,0x65,0x64,0x69,0x75,0x6d,
    0x70,0x20,0x66,0x6c,0x6f,0x61,0x74,0x3b,0x0a,0x70,0x72,0x65,0x63,0x69,0x73,0x69,
    0x6f,0x6e,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x69,0x6e,0x74,0x3b,0x0a,0x0a,0x69,
    0x6e,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x76,0x65,0x63,0x34,0x20,0x66,0x73,0x5f,
    0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,
    0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x30,0x29,0x20,0x6f,0x75,0x74,0x20,
    0x68,0x69,0x67,0x68,0x70,0x20,0x76,0x65,0x63,0x34,0x20,0x66,0x72,0x61,0x67,0x5f,
    0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,
    0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x5f,0x63,
    0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x66,0x73,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,
    0x0a,0x7d,0x0a,0x0a,0x00,
};
#endif /* SOKOL_GLES3 */
#if defined(SOKOL_METAL)
/*
    #include <metal_stdlib>
    #include <simd/simd.h>
    
    using namespace metal;
    
    struct vs_params
    {
        float4x4 un_mvp;
    };
    
    struct main0_out
    {
        float4 fs_color [[user(locn0)]];
        float4 gl_Position [[position]];
    };
    
    struct main0_in
    {
        float3 vs_position [[attribute(0)]];
        float4 vs_color [[attribute(1)]];
    };
    
    #line 36 "color_texture.glsl"
    vertex main0_out main0(main0_in in [[stage_in]], constant vs_params& _21 [[buffer(0)]])
    {
        main0_out out = {};
    #line 36 "color_texture.glsl"
        out.gl_Position = _21.un_mvp * float4(in.vs_position, 1.0);
    #line 39 "color_texture.glsl"
        out.fs_color = in.vs_color;
        return out;
    }
    
*/
static const char color_vs_source_metal_macos[634] = {
    0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,0x20,0x3c,0x6d,0x65,0x74,0x61,0x6c,0x5f,
    0x73,0x74,0x64,0x6c,0x69,0x62,0x3e,0x0a,0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,
    0x20,0x3c,0x73,0x69,0x6d,0x64,0x2f,0x73,0x69,0x6d,0x64,0x2e,0x68,0x3e,0x0a,0x0a,
    0x75,0x73,0x69,0x6e,0x67,0x20,0x6e,0x61,0x6d,0x65,0x73,0x70,0x61,0x63,0x65,0x20,
    0x6d,0x65,0x74,0x61,0x6c,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x76,
    0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,
    0x6c,0x6f,0x61,0x74,0x34,0x78,0x34,0x20,0x75,0x6e,0x5f,0x6d,0x76,0x70,0x3b,0x0a,
    0x7d,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,
    0x5f,0x6f,0x75,0x74,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,
    0x34,0x20,0x66,0x73,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x5b,0x5b,0x75,0x73,0x65,
    0x72,0x28,0x6c,0x6f,0x63,0x6e,0x30,0x29,0x5d,0x5d,0x3b,0x0a,0x20,0x20,0x20,0x20,
    0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,
    0x6f,0x6e,0x20,0x5b,0x5b,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x5d,0x5d,0x3b,
    0x0a,0x7d,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,0x61,0x69,0x6e,
    0x30,0x5f,0x69,0x6e,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,
    0x33,0x20,0x76,0x73,0x5f,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x5b,0x5b,
    0x61,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x28,0x30,0x29,0x5d,0x5d,0x3b,0x0a,
    0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,0x76,0x73,0x5f,0x63,0x6f,
    0x6c,0x6f,0x72,0x20,0x5b,0x5b,0x61,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x28,
    0x31,0x29,0x5d,0x5d,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,
    0x33,0x36,0x20,0x22,0x63,0x6f,0x6c,0x6f,0x72,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,
    0x65,0x2e,0x67,0x6c,0x73,0x6c,0x22,0x0a,0x76,0x65,0x72,0x74,0x65,0x78,0x20,0x6d,
    0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x28,0x6d,
    0x61,0x69,0x6e,0x30,0x5f,0x69,0x6e,0x20,0x69,0x6e,0x20,0x5b,0x5b,0x73,0x74,0x61,
    0x67,0x65,0x5f,0x69,0x6e,0x5d,0x5d,0x2c,0x20,0x63,0x6f,0x6e,0x73,0x74,0x61,0x6e,
    0x74,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x26,0x20,0x5f,0x32,0x31,
    0x20,0x5b,0x5b,0x62,0x75,0x66,0x66,0x65,0x72,0x28,0x30,0x29,0x5d,0x5d,0x29,0x0a,
    0x7b,0x0a,0x20,0x20,0x20,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,0x74,0x20,
    0x6f,0x75,0x74,0x20,0x3d,0x20,0x7b,0x7d,0x3b,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,
    0x33,0x36,0x20,0x22,0x63,0x6f,0x6c,0x6f,0x72,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,
    0x65,0x2e,0x67,0x6c,0x73,0x6c,0x22,0x0a,0x20,0x20,0x20,0x20,0x6f,0x75,0x74,0x2e,
    0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x5f,0x32,
    0x31,0x2e,0x75,0x6e,0x5f,0x6d,0x76,0x70,0x20,0x2a,0x20,0x66,0x6c,0x6f,0x61,0x74,
    0x34,0x28,0x69,0x6e,0x2e,0x76,0x73,0x5f,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,
    0x2c,0x20,0x31,0x2e,0x30,0x29,0x3b,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x33,0x39,
    0x20,0x22,0x63,0x6f,0x6c,0x6f,0x72,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x2e,
    0x67,0x6c,0x73,0x6c,0x22,0x0a,0x20,0x20,0x20,0x20,0x6f,0x75,0x74,0x2e,0x66,0x73,
    0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x69,0x6e,0x2e,0x76,0x73,0x5f,0x63,
    0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x20,0x20,0x20,0x20,0x72,0x65,0x74,0x75,0x72,0x6e,
    0x20,0x6f,0x75,0x74,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #include <metal_stdlib>
    #include <simd/simd.h>
    
    using namespace metal;
    
    struct main0_out
    {
        float4 frag_color [[color(0)]];
    };
    
    struct main0_in
    {
        float4 fs_color [[user(locn0)]];
    };
    
    #line 31 "color_texture.glsl"
    fragment main0_out main0(main0_in in [[stage_in]])
    {
        main0_out out = {};
    #line 31 "color_texture.glsl"
    #line 41 "color_texture.glsl"
        out.frag_color = in.fs_color;
        return out;
    }
    
*/
static const char color_fs_source_metal_macos[411] = {
    0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,0x20,0x3c,0x6d,0x65,0x74,0x61,0x6c,0x5f,
    0x73,0x74,0x64,0x6c,0x69,0x62,0x3e,0x0a,0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,
    0x20,0x3c,0x73,0x69,0x6d,0x64,0x2f,0x73,0x69,0x6d,0x64,0x2e,0x68,0x3e,0x0a,0x0a,
    0x75,0x73,0x69,0x6e,0x67,0x20,0x6e,0x61,0x6d,0x65,0x73,0x70,0x61,0x63,0x65,0x20,
    0x6d,0x65,0x74,0x61,0x6c,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,
    0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,0x74,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,
    0x6c,0x6f,0x61,0x74,0x34,0x20,0x66,0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,
    0x20,0x5b,0x5b,0x63,0x6f,0x6c,0x6f,0x72,0x28,0x30,0x29,0x5d,0x5d,0x3b,0x0a,0x7d,
    0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,
    0x69,0x6e,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,
    0x66,0x73,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x5b,0x5b,0x75,0x73,0x65,0x72,0x28,
    0x6c,0x6f,0x63,0x6e,0x30,0x29,0x5d,0x5d,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x23,0x6c,
    0x69,0x6e,0x65,0x20,0x33,0x31,0x20,0x22,0x63,0x6f,0x6c,0x6f,0x72,0x5f,0x74,0x65,
    0x78,0x74,0x75,0x72,0x65,0x2e,0x67,0x6c,0x73,0x6c,0x22,0x0a,0x66,0x72,0x61,0x67,
    0x6d,0x65,0x6e,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,0x74,0x20,0x6d,
    0x61,0x69,0x6e,0x30,0x28,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x69,0x6e,0x20,0x69,0x6e,
    0x20,0x5b,0x5b,0x73,0x74,0x61,0x67,0x65,0x5f,0x69,0x6e,0x5d,0x5d,0x29,0x0a,0x7b,
    0x0a,0x20,0x20,0x20,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,0x74,0x20,0x6f,
    0x75,0x74,0x20,0x3d,0x20,0x7b,0x7d,0x3b,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x33,
    0x31,0x20,0x22,0x63,0x6f,0x6c,0x6f,0x72,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,
    0x2e,0x67,0x6c,0x73,0x6c,0x22,0x0a,0x23,0x6c,0x69,0x6e,0x65,0x20,0x34,0x31,0x20,
    0x22,0x63,0x6f,0x6c,0x6f,0x72,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x2e,0x67,
    0x6c,0x73,0x6c,0x22,0x0a,0x20,0x20,0x20,0x20,0x6f,0x75,0x74,0x2e,0x66,0x72,0x61,
    0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x69,0x6e,0x2e,0x66,0x73,0x5f,
    0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x20,0x20,0x20,0x20,0x72,0x65,0x74,0x75,0x72,
    0x6e,0x20,0x6f,0x75,0x74,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
#endif /* SOKOL_METAL */
#if !defined(SOKOL_GFX_INCLUDED)
  #error "Please include sokol_gfx.h before color.h"
#endif
static inline const sg_shader_desc* color_program_shader_desc(sg_backend backend) {
  #if defined(SOKOL_GLCORE33)
  if (backend == SG_BACKEND_GLCORE33) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.attrs[0].name = "vs_position";
      desc.attrs[1].name = "vs_color";
      desc.vs.source = color_vs_source_glsl330;
      desc.vs.entry = "main";
      desc.vs.uniform_blocks[0].size = 64;
      desc.vs.uniform_blocks[0].layout = SG_UNIFORMLAYOUT_STD140;
      desc.vs.uniform_blocks[0].uniforms[0].name = "vs_params";
      desc.vs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.vs.uniform_blocks[0].uniforms[0].array_count = 4;
      desc.fs.source = color_fs_source_glsl330;
      desc.fs.entry = "main";
      desc.label = "color_program_shader";
    }
    return &desc;
  }
  #endif /* SOKOL_GLCORE33 */
  #if defined(SOKOL_GLES2)
  if (backend == SG_BACKEND_GLES2) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.attrs[0].name = "vs_position";
      desc.attrs[1].name = "vs_color";
      desc.vs.source = color_vs_source_glsl100;
      desc.vs.entry = "main";
      desc.vs.uniform_blocks[0].size = 64;
      desc.vs.uniform_blocks[0].layout = SG_UNIFORMLAYOUT_STD140;
      desc.vs.uniform_blocks[0].uniforms[0].name = "vs_params";
      desc.vs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.vs.uniform_blocks[0].uniforms[0].array_count = 4;
      desc.fs.source = color_fs_source_glsl100;
      desc.fs.entry = "main";
      desc.label = "color_program_shader";
    }
    return &desc;
  }
  #endif /* SOKOL_GLES2 */
  #if defined(SOKOL_GLES3)
  if (backend == SG_BACKEND_GLES3) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.attrs[0].name = "vs_position";
      desc.attrs[1].name = "vs_color";
      desc.vs.source = color_vs_source_glsl300es;
      desc.vs.entry = "main";
      desc.vs.uniform_blocks[0].size = 64;
      desc.vs.uniform_blocks[0].layout = SG_UNIFORMLAYOUT_STD140;
      desc.vs.uniform_blocks[0].uniforms[0].name = "vs_params";
      desc.vs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.vs.uniform_blocks[0].uniforms[0].array_count = 4;
      desc.fs.source = color_fs_source_glsl300es;
      desc.fs.entry = "main";
      desc.label = "color_program_shader";
    }
    return &desc;
  }
  #endif /* SOKOL_GLES3 */
  #if defined(SOKOL_METAL)
  if (backend == SG_BACKEND_METAL_MACOS) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.vs.source = color_vs_source_metal_macos;
      desc.vs.entry = "main0";
      desc.vs.uniform_blocks[0].size = 64;
      desc.vs.uniform_blocks[0].layout = SG_UNIFORMLAYOUT_STD140;
      desc.fs.source = color_fs_source_metal_macos;
      desc.fs.entry = "main0";
      desc.label = "color_program_shader";
    }
    return &desc;
  }
  #endif /* SOKOL_METAL */
  return 0;
}
static inline int color_program_attr_slot(const char* attr_name) {
  (void)attr_name;
  if (0 == strcmp(attr_name, "vs_position")) {
    return 0;
  }
  if (0 == strcmp(attr_name, "vs_color")) {
    return 1;
  }
  return -1;
}
static inline int color_program_image_slot(sg_shader_stage stage, const char* img_name) {
  (void)stage; (void)img_name;
  return -1;
}
static inline int color_program_uniformblock_slot(sg_shader_stage stage, const char* ub_name) {
  (void)stage; (void)ub_name;
  if (SG_SHADERSTAGE_VS == stage) {
    if (0 == strcmp(ub_name, "vs_params")) {
      return 0;
    }
  }
  return -1;
}
static inline size_t color_program_uniformblock_size(sg_shader_stage stage, const char* ub_name) {
  (void)stage; (void)ub_name;
  if (SG_SHADERSTAGE_VS == stage) {
    if (0 == strcmp(ub_name, "vs_params")) {
      return sizeof(color_vs_params_t);
    }
  }
  return 0;
}
static inline int color_program_uniform_offset(sg_shader_stage stage, const char* ub_name, const char* u_name) {
  (void)stage; (void)ub_name; (void)u_name;
  if (SG_SHADERSTAGE_VS == stage) {
    if (0 == strcmp(ub_name, "vs_params")) {
      if (0 == strcmp(u_name, "un_mvp")) {
        return 0;
      }
    }
  }
  return -1;
}
static inline sg_shader_uniform_desc color_program_uniform_desc(sg_shader_stage stage, const char* ub_name, const char* u_name) {
  (void)stage; (void)ub_name; (void)u_name;
  #if defined(__cplusplus)
  sg_shader_uniform_desc desc = {};
  #else
  sg_shader_uniform_desc desc = {0};
  #endif
  if (SG_SHADERSTAGE_VS == stage) {
    if (0 == strcmp(ub_name, "vs_params")) {
      if (0 == strcmp(u_name, "un_mvp")) {
        desc.name = "un_mvp";
        desc.type = SG_UNIFORMTYPE_MAT4;
        desc.array_count = 1;
        return desc;
      }
    }
  }
  return desc;
}
