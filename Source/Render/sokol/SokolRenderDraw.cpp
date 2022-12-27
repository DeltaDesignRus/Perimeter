#include "StdAfxRD.h"
#include "IRenderDevice.h"
#include "EmptyRenderDevice.h"
#include "SokolRender.h"
#include "VertexFormat.h"

void cSokolRender::DrawRectangle(int x1,int y1,int dx,int dy,sColor4c color,bool outline) {
    VISASSERT(ActiveScene);

    int x2=x1+dx,y2=y1+dy;
    if (0 <= dx) { if (x2<0 || x1>ScreenSize.x) return; }
    else if (x1 < 0 || x2 > ScreenSize.x) return;
    if (0 <= dy) { if (y2<0 || y1>ScreenSize.y) return; }
    else if (y1 < 0 || y2 > ScreenSize.y) return;

    SetNoMaterial(ALPHA_BLEND);
    SetupMatrix(&orthoMat, false);

    /* TODO
    if (outline) {
        PrepareBuffers(8, 24, sVertexXYZD::fmt);
        size_t vc = activeCommand.vertices;

        sVertexXYZD* v = static_cast<sVertexXYZD*>(LockVertexBuffer(vertexBuffer));
        v = &v[vc];
        for (int i = 0; i < 8; ++i) {
            v[i].z=0;
            v[i].diffuse.v=color.ABGR();
        }
        v[0].x=v[1].x=static_cast<float>(x1);
        v[3].x=v[2].x=static_cast<float>(x2);
        v[0].y=v[2].y=static_cast<float>(y1);
        v[1].y=v[3].y=static_cast<float>(y2);
        UnlockVertexBuffer(vertexBuffer);

        sPolygon* p = BufferSeekPolygon(LockIndexBuffer(indexBuffer), activeCommand.indices);
        p[0].set(vc + 0, vc + 1, vc + 2);
        p[1].set(vc + 2, vc + 1, vc + 3);
        UnlockIndexBuffer(indexBuffer);

        activeCommand.vertices += 8;
        activeCommand.indices += 24;
    } else {
    */
        PrepareBuffers(4, 6, sVertexXYZD::fmt);
        size_t vc = activeCommand.vertices;

        sVertexXYZD* v = static_cast<sVertexXYZD*>(LockVertexBuffer(vertexBuffer));
        v = &v[vc];
        v[0].z=v[1].z=v[2].z=v[3].z=0;
        v[0].diffuse.v=v[1].diffuse.v=v[2].diffuse.v=v[3].diffuse.v=color.ABGR();
        v[0].x=v[1].x=static_cast<float>(x1);
        v[0].y=v[2].y=static_cast<float>(y1);
        v[3].x=v[2].x=static_cast<float>(x2);
        v[1].y=v[3].y=static_cast<float>(y2);
        UnlockVertexBuffer(vertexBuffer);

        sPolygon* p = BufferSeekPolygon(LockIndexBuffer(indexBuffer), activeCommand.indices);
        p[0].set(vc + 0, vc + 1, vc + 2);
        p[1].set(vc + 2, vc + 1, vc + 3);
        UnlockIndexBuffer(indexBuffer);

        activeCommand.vertices += 4;
        activeCommand.indices += 6;
    //}
}

void cSokolRender::FlushPrimitive2D() {
}

void cSokolRender::DrawSprite(int x1, int y1, int dx, int dy, float u1, float v1, float du, float dv, cTexture* Texture,
                              const sColor4c& ColorMul, float phase, eBlendMode mode) {
    if (!Texture) return;
    VISASSERT(ActiveScene);

    int x2=x1+dx,y2=y1+dy;
    if (0 <= dx) { if (x2<0 || x1>ScreenSize.x) return; }
    else if (x1 < 0 || x2 > ScreenSize.x) return;
    if (0 <= dy) { if (y2<0 || y1>ScreenSize.y) return; }
    else if (y1 < 0 || y2 > ScreenSize.y) return;

    bool alpha = ColorMul.a < 255 || Texture->IsAlpha();
    if (mode <= ALPHA_TEST && alpha) mode = ALPHA_BLEND;

    SetNoMaterial(mode,phase,Texture);

    PrepareBuffers(4, 6, sVertexXYZDT1::fmt);
    SetupMatrix(&orthoMat, false);
    size_t vc = activeCommand.vertices;

    sVertexXYZDT1* v = static_cast<sVertexXYZDT1*>(LockVertexBuffer(vertexBuffer));
    v = &v[vc];
    v[0].z=v[1].z=v[2].z=v[3].z=0;
    v[0].diffuse.v=v[1].diffuse.v=v[2].diffuse.v=v[3].diffuse.v=ColorMul.ABGR();
    v[0].x=v[1].x=static_cast<float>(x1);
    v[0].y=v[2].y=static_cast<float>(y1);
    v[3].x=v[2].x=static_cast<float>(x2);
    v[1].y=v[3].y=static_cast<float>(y2);

    v[0].u1()=u1;    v[0].v1()=v1;
    v[1].u1()=u1;    v[1].v1()=v1+dv;
    v[2].u1()=u1+du; v[2].v1()=v1;
    v[3].u1()=u1+du; v[3].v1()=v1+dv;
    UnlockVertexBuffer(vertexBuffer);

    sPolygon* p = BufferSeekPolygon(LockIndexBuffer(indexBuffer), activeCommand.indices);
    p[0].set(vc + 0, vc + 1, vc + 2);
    p[1].set(vc + 2, vc + 1, vc + 3);
    UnlockIndexBuffer(indexBuffer);
    
    activeCommand.vertices += 4;
    activeCommand.indices += 6;
}

void cSokolRender::DrawSprite2(int x1,int y1,int dx,int dy,
                               float u0,float v0,float du0,float dv0,
                               float u1,float v1,float du1,float dv1,
                               cTexture *Tex1,cTexture *Tex2,const sColor4c &ColorMul,float phase,
                               eColorMode mode,eBlendMode blend_mode) {
    if (!Tex1||!Tex2) return;
    VISASSERT(ActiveScene);

    int x2=x1+dx,y2=y1+dy;
    if (0 <= dx) { if (x2<0 || x1>ScreenSize.x) return; }
    else if (x1 < 0 || x2 > ScreenSize.x) return;
    if (0 <= dy) { if (y2<0 || y1>ScreenSize.y) return; }
    else if (y1 < 0 || y2 > ScreenSize.y) return;

    if (blend_mode == ALPHA_NONE && ColorMul.a < 255) {
        blend_mode = ALPHA_BLEND;
    }
    SetNoMaterial(blend_mode, phase, Tex1, Tex2, mode);

    PrepareBuffers(4, 6, sVertexXYZDT1::fmt);
    SetupMatrix(&orthoMat, false);
    size_t vc = activeCommand.vertices;
    SetupMatrix(&orthoMat, false);

    sVertexXYZDT2* v = static_cast<sVertexXYZDT2*>(LockVertexBuffer(vertexBuffer));
    v = &v[vc];
    v[0].z=v[1].z=v[2].z=v[3].z=0;
    v[0].diffuse.v=v[1].diffuse.v=v[2].diffuse.v=v[3].diffuse.v=ColorMul.ABGR();
    v[0].x=v[1].x=static_cast<float>(x1);
    v[0].y=v[2].y=static_cast<float>(y1);
    v[3].x=v[2].x=static_cast<float>(x2);
    v[1].y=v[3].y=static_cast<float>(y2);

    v[0].u1()=u0;     v[0].v1()=v0;
    v[1].u1()=u0;     v[1].v1()=v0+dv0;
    v[2].u1()=u0+du0; v[2].v1()=v0;
    v[3].u1()=u0+du0; v[3].v1()=v0+dv0;

    v[0].u2()=u1;     v[0].v2()=v1;
    v[1].u2()=u1;     v[1].v2()=v1+dv1;
    v[2].u2()=u1+du1; v[2].v2()=v1;
    v[3].u2()=u1+du1; v[3].v2()=v1+dv1;
    UnlockVertexBuffer(vertexBuffer);

    sPolygon* p = BufferSeekPolygon(LockIndexBuffer(indexBuffer), activeCommand.indices);
    p[0].set(vc + 0, vc + 1, vc + 2);
    p[1].set(vc + 2, vc + 1, vc + 3);
    UnlockIndexBuffer(indexBuffer);

    activeCommand.vertices += 4;
    activeCommand.indices += 6;
    
    DrawRectangle(x1, y1, dx, dy, sColor4c(0,255,0,24));
}

void cSokolRender::DrawSprite2(int x1,int y1,int dx,int dy,
                               float u0,float v0,float du0,float dv0,
                               float u1,float v1,float du1,float dv1,
                               cTexture *Tex1,cTexture *Tex2,float lerp_factor,float alpha,float phase,
                               eColorMode mode,eBlendMode blend_mode) {
    if (!Tex1||!Tex2) return;
    VISASSERT(ActiveScene);

    int x2=x1+dx,y2=y1+dy;
    if (0 <= dx) { if (x2<0 || x1>ScreenSize.x) return; }
    else if (x1 < 0 || x2 > ScreenSize.x) return;
    if (0 <= dy) { if (y2<0 || y1>ScreenSize.y) return; }
    else if (y1 < 0 || y2 > ScreenSize.y) return;

    sColor4f lerp(lerp_factor,lerp_factor,lerp_factor,1-lerp_factor);
    sColor4c ColorMul(sColor4f(1,1,1,alpha) * lerp);
    if (blend_mode == ALPHA_NONE && alpha < 255) {
        blend_mode = ALPHA_BLEND;
    }
    SetNoMaterial(blend_mode, phase, Tex1, Tex2, mode);

    /* TODO 
    {
        SetTextureStageState(0,D3DTSS_COLOROP,D3DTOP_MODULATECOLOR_ADDALPHA);
        SetTextureStageState(0,D3DTSS_COLORARG1,D3DTA_TFACTOR);
        SetTextureStageState(0,D3DTSS_COLORARG2,D3DTA_TEXTURE);
        SetRenderState(D3DRS_TEXTUREFACTOR, lerp.ARGB());

        SetTextureStageState(1,D3DTSS_ALPHAOP,D3DTOP_MODULATE);
        SetTextureStageState(1,D3DTSS_ALPHAARG1,D3DTA_TEXTURE);
        SetTextureStageState(1,D3DTSS_ALPHAARG2,D3DTA_DIFFUSE);

//		SetTextureStageState(1,D3DTSS_COLOROP,D3DTOP_MODULATE);
        SetTextureStageState(1,D3DTSS_COLORARG1,D3DTA_TEXTURE);
        SetTextureStageState(1,D3DTSS_COLORARG2,D3DTA_CURRENT);
    }
    */

    PrepareBuffers(4, 6, sVertexXYZDT2::fmt);
    SetupMatrix(&orthoMat, false);
    size_t vc = activeCommand.vertices;
    
    sVertexXYZDT2* v = static_cast<sVertexXYZDT2*>(LockVertexBuffer(vertexBuffer));
    v = &v[vc];
    v[0].z=v[1].z=v[2].z=v[3].z=0;
    v[0].diffuse.v=v[1].diffuse.v=v[2].diffuse.v=v[3].diffuse.v=ColorMul.ABGR();
    v[0].x=v[1].x=static_cast<float>(x1);
    v[0].y=v[2].y=static_cast<float>(y1);
    v[3].x=v[2].x=static_cast<float>(x2);
    v[1].y=v[3].y=static_cast<float>(y2);

    v[0].u1()=u1;     v[0].v1()=v1;
    v[1].u1()=u1;     v[1].v1()=v1+dv1;
    v[2].u1()=u1+du1; v[2].v1()=v1;
    v[3].u1()=u1+du1; v[3].v1()=v1+dv1;

    v[0].u2()=u0;     v[0].v2()=v0;
    v[1].u2()=u0;     v[1].v2()=v0+dv0;
    v[2].u2()=u0+du0; v[2].v2()=v0;
    v[3].u2()=u0+du0; v[3].v2()=v0+dv0;
    UnlockVertexBuffer(vertexBuffer);

    sPolygon* p = BufferSeekPolygon(LockIndexBuffer(indexBuffer), activeCommand.indices);
    p[0].set(vc + 0, vc + 1,vc + 2);
    p[1].set(vc + 2, vc + 1,vc + 3);
    UnlockIndexBuffer(indexBuffer);

    activeCommand.vertices += 4;
    activeCommand.indices += 6;
    
    DrawRectangle(x1, y1, dx, dy, sColor4c(0,0,255,24));
}
