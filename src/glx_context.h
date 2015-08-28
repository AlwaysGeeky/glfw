//========================================================================
// GLFW 3.2 GLX - www.glfw.org
//------------------------------------------------------------------------
// Copyright (c) 2002-2006 Marcus Geelnard
// Copyright (c) 2006-2010 Camilla Berglund <elmindreda@elmindreda.org>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#ifndef _glfw3_glx_context_h_
#define _glfw3_glx_context_h_

#define GLX_GLXEXT_LEGACY
#include <GL/glx.h>

// This path may need to be changed if you build GLFW using your own setup
// We ship and use our own copy of glxext.h since GLFW uses fairly new
// extensions and not all operating systems come with an up-to-date version
#define GLX_GLXEXT_PROTOTYPES
#include "../deps/GL/glxext.h"

// libGL.so function pointer typedefs
typedef int (*PFNGLXGETFBCONFIGATTRIBPROC)(Display*,GLXFBConfig,int,int*);
typedef const char* (*PFNGLXGETCLIENTSTRINGPROC)(Display*,int);
typedef Bool (*PFNGLXQUERYEXTENSIONPROC)(Display*,int*,int*);
typedef Bool (*PFNGLXQUERYVERSIONPROC)(Display*,int*,int*);
typedef void (*PFNGLXDESTROYCONTEXTPROC)(Display*,GLXContext);
typedef Bool (*PFNGLXMAKECURRENTPROC)(Display*,GLXDrawable,GLXContext);
typedef void (*PFNGLXSWAPBUFFERSPROC)(Display*,GLXDrawable);
typedef const char* (*PFNGLXQUERYEXTENSIONSSTRINGPROC)(Display*,int);
#define _glfw_glXGetFBConfigs _glfw.glx.GetFBConfigs
#define _glfw_glXGetFBConfigAttrib _glfw.glx.GetFBConfigAttrib
#define _glfw_glXGetClientString _glfw.glx.GetClientString
#define _glfw_glXQueryExtension _glfw.glx.QueryExtension
#define _glfw_glXQueryVersion _glfw.glx.QueryVersion
#define _glfw_glXDestroyContext _glfw.glx.DestroyContext
#define _glfw_glXMakeCurrent _glfw.glx.MakeCurrent
#define _glfw_glXSwapBuffers _glfw.glx.SwapBuffers
#define _glfw_glXQueryExtensionsString _glfw.glx.QueryExtensionsString
#define _glfw_glXCreateNewContext _glfw.glx.CreateNewContext

#define _GLFW_PLATFORM_FBCONFIG                 GLXFBConfig     glx
#define _GLFW_PLATFORM_CONTEXT_STATE            _GLFWcontextGLX glx
#define _GLFW_PLATFORM_LIBRARY_CONTEXT_STATE    _GLFWlibraryGLX glx

#ifndef GLX_MESA_swap_control
typedef int (*PFNGLXSWAPINTERVALMESAPROC)(int);
#endif


// GLX-specific per-context data
//
typedef struct _GLFWcontextGLX
{
    GLXContext      handle;

} _GLFWcontextGLX;


// GLX-specific global data
//
typedef struct _GLFWlibraryGLX
{
    int             major, minor;
    int             eventBase;
    int             errorBase;

    // dlopen handle for libGL.so.1
    void*           handle;

    // GLX 1.3 functions
    PFNGLXGETFBCONFIGSPROC              GetFBConfigs;
    PFNGLXGETFBCONFIGATTRIBPROC         GetFBConfigAttrib;
    PFNGLXGETCLIENTSTRINGPROC           GetClientString;
    PFNGLXQUERYEXTENSIONPROC            QueryExtension;
    PFNGLXQUERYVERSIONPROC              QueryVersion;
    PFNGLXDESTROYCONTEXTPROC            DestroyContext;
    PFNGLXMAKECURRENTPROC               MakeCurrent;
    PFNGLXSWAPBUFFERSPROC               SwapBuffers;
    PFNGLXQUERYEXTENSIONSSTRINGPROC     QueryExtensionsString;
    PFNGLXCREATENEWCONTEXTPROC          CreateNewContext;

    // GLX 1.4 and extension functions
    PFNGLXGETPROCADDRESSPROC            GetProcAddress;
    PFNGLXGETPROCADDRESSPROC            GetProcAddressARB;
    PFNGLXSWAPINTERVALSGIPROC           SwapIntervalSGI;
    PFNGLXSWAPINTERVALEXTPROC           SwapIntervalEXT;
    PFNGLXSWAPINTERVALMESAPROC          SwapIntervalMESA;
    PFNGLXCREATECONTEXTATTRIBSARBPROC   CreateContextAttribsARB;
    int                                 SGI_swap_control;
    int                                 EXT_swap_control;
    int                                 MESA_swap_control;
    int                                 ARB_multisample;
    int                                 ARB_framebuffer_sRGB;
    int                                 EXT_framebuffer_sRGB;
    int                                 ARB_create_context;
    int                                 ARB_create_context_profile;
    int                                 ARB_create_context_robustness;
    int                                 EXT_create_context_es2_profile;
    int                                 ARB_context_flush_control;

} _GLFWlibraryGLX;


int _glfwInitContextAPI(void);
void _glfwTerminateContextAPI(void);
int _glfwCreateContext(_GLFWwindow* window,
                       const _GLFWctxconfig* ctxconfig,
                       const _GLFWfbconfig* fbconfig);
void _glfwDestroyContext(_GLFWwindow* window);

#endif // _glfw3_glx_context_h_
