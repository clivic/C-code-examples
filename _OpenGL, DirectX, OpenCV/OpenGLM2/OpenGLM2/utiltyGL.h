//*******************************************************************
//	OpenGL Utility Package specification
//	version 1.0.0
//	General introduction:	
//		The Utility header file contains neccessary elements and 
//		definitions based on NeHe OpenGL skeleton to provide easy use 
//		of coding OpenGL programs.
//	Notes:
//		any clients using the whole Utility Package should include 
//		this header file into the project to run properly, and also
//		include it in the client source file when necessary.
//*******************************************************************
#include <windows.h>	
#include <glew.h>			// contains newlest gl.h,glu.h library
#include <glut.h>			// contains OpenGL utility library
#include <stdio.h>			// standard input/output
#include <glaux.h>			// GLaux library
#include <math.h>
#include <time.h>
#include <stdarg.h>			// used for words processing

HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Context
HWND		hWnd = NULL;	// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

BOOL	keys[256];			// Array Used For The Keyboard Routine
BOOL	active = TRUE;		// Window Active Flag Set To TRUE By Default

LARGE_INTEGER start;
LARGE_INTEGER over;
LARGE_INTEGER frequ;

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//// Control Panel
//BOOL	isToLoadTexture = TRUE;		// Whether to load texture
//BOOL	isToChooseMode = FALSE;		// Whether to let user choose fullscreen or window running