#ifndef _OPEN_GL_DLL_H_
#define _OPEN_GL_DLL_H_
#endif // _OPEN_GL_DLL_H_

#if defined (EXPORTBUILD)
#define _DLLExport __declspec (dllexport)
#else
#define _DLLExport __declspec (dllimport)
#endif

#include <iostream>
#include <math.h>

#include <openglxy\glut.h>

extern "C" int _DLLExport add(int x, int y);
extern "C" int _DLLExport TestOpenGLDll();

_DLLExport class OpenGLDll {
public:
	OpenGLDll(void);
	~OpenGLDll(void);
};