#include <windows.h>	// Windows��ͷ�ļ�
#include "glew.h"		// �������µ�gl.h,glu.h��
#include "glut.h"		// ����OpenGLʵ�ÿ�

HGLRC           hRC = NULL;							// ������ɫ��������
HDC             hDC = NULL;							// OpenGL��Ⱦ��������
HWND            hWnd = NULL;						// �������ǵĴ��ھ��
HINSTANCE       hInstance;							// ��������ʵ��

bool	keys[256];									// ������̰���������
bool	active = TRUE;								// ���ڵĻ��־��ȱʡΪTRUE
bool	fullscreen = TRUE;							// ȫ����־ȱʡ��ȱʡ�趨��ȫ��ģʽ

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// WndProc����

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)
// ����:	����OpenGL͸��ͼ��Ļ���ڴ�С
{
	// ����OpenGL���ڴ�С
	if (height == 0)								// ��ֹ�����
	{
		height = 1;									// ��Height��Ϊ1
	}

	glViewport(0, 0, width, height);				// ���õ�ǰ���ӿ�

	// Ϊ͸��ͼ������Ļ
	glMatrixMode(GL_PROJECTION);					// ѡ��ͶӰ����(PROJECTION��ͶӰ)
	glLoadIdentity();								// ����֮(ͶӰ����)

	// �����ӿڵĴ�С
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f); //����height����==0

	glMatrixMode(GL_MODELVIEW);						// ѡ��ģ�͹۲����(MODEVIEW��ģ���^��)
	glLoadIdentity();								// ����֮(ģ�͹۲����)
}

//*****************************************************************************

int InitGL(GLvoid)
// ����:	�˴���ʼ��OpenGL������������
{
	glShadeModel(GL_SMOOTH);				// ������Ӱƽ��

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// �����Ļʱ���õ���ɫ������ɫ,��̎�Ǻ�ɫ

	glClearDepth(1.0f);						// ������Ȼ���
	glEnable(GL_DEPTH_TEST);				// ������Ȳ���
	glDepthFunc(GL_LEQUAL);					// ������Ȳ��Ե�����

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);		// ����ϵͳ��͸�ӽ�������(���ÿ�)

	return TRUE;							// ��ʼ��OK�ͷ���TRUE
}

//*****************************************************************************

int DrawGLScene(GLvoid)								
// ����:	�����￪ʼ�������еĻ���
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			// �����Ļ����Ȼ���
	glLoadIdentity();							// ���õ�ǰ��ģ�͹۲����
	return TRUE;								// һ��OK, FALSE��Ԓ���򼴌��˳�
}

//*****************************************************************************

GLvoid ReleaseGLWindow(GLvoid)
// ����:	�������ٴ���
{
	// ���Ǵ���ȫ��ģʽ��?
	if (fullscreen)
	{
		ChangeDisplaySettings(NULL, 0);			// �ǵĻ����л�������
		ShowCursor(TRUE);						// ��ʾ���ָ��
	}

	// ����ӵ��OpenGL��Ⱦ��������?
	if (hRC)
	{
		// �����ܷ��ͷ�DC��RC������?
		if (!wglMakeCurrent(NULL, NULL))
			MessageBox(NULL, "Fail to release DC or RC.", "Shutdown Error", MB_OK | MB_ICONINFORMATION);

		// �����ܷ�ɾ��RC?
		if (!wglDeleteContext(hRC))
			MessageBox(NULL, "Fail to release RC.", "Shutdown Error", MB_OK | MB_ICONINFORMATION);

		hRC = NULL;							// ��RC��ΪNULL
	}

	// �����ܷ��ͷ�DC?
	if (hDC && !ReleaseDC(hWnd, hDC))
	{
		MessageBox(NULL, "Fail to release DC.", "Shutdown Error", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;							// ��DC��ΪNULL
	}

	// �ܷ����ٴ���?
	if (hWnd && !DestroyWindow(hWnd))
	{
		MessageBox(NULL, "Fail to release Wnd", "Shutdown Error", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;						// ��hWnd��ΪNULL
	}

	// �ܷ�ע����?
	if (!UnregisterClass("OpenG", hInstance))
	{
		MessageBox(NULL, "Fail to unregister class \"OpenG\".", "Shutdown Error", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;					// ��hInstance��Ϊ NULL
	}
}

//*****************************************************************************

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint PixelFormat;										// �������ƥ��Ľ��
	WNDCLASS wc;											// ������ṹ
	DWORD dwExStyle;										// ��չ���ڷ��
	DWORD dwStyle;											// ���ڷ��

	RECT WindowRect;										// �Á�惦���ε����ϽǺ����½ǵ�����ֵ
	WindowRect.left = (long)0;								// ��Left   ��Ϊ 0
	WindowRect.top = (long)0;								// ��Top    ��Ϊ 0
	WindowRect.right = (long)width;							// ��Right  ��ΪҪ��Ŀ��
	WindowRect.bottom = (long)height;						// ��Bottom ��ΪҪ��ĸ߶�

	fullscreen = fullscreenflag;							// ����ȫ��ȫ����־

	hInstance = GetModuleHandle(NULL);						// ȡ�����Ǵ��ڵ�ʵ��
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;			// �ƶ�ʱ�ػ�����Ϊ����ȡ��DC
	wc.lpfnWndProc = (WNDPROC)WndProc;						// WndProc������Ϣ
	wc.cbClsExtra = 0;										// �޶��ⴰ������
	wc.cbWndExtra = 0;										// �޶��ⴰ������
	wc.hInstance = hInstance;								// ����ʵ��
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);					// װ��ͼ��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// װ�����ָ��
	wc.hbrBackground = NULL;								// GL����Ҫ����
	wc.lpszMenuName = NULL;									// ����Ҫ�˵�
	wc.lpszClassName = "OpenG";							// �������

	if (!RegisterClass(&wc))								// ����ע�ᴰ����
	{
		MessageBox(NULL, "Fail to register window", "Register Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// �˳�������FALSE
	}

	// Ҫ����ȫ��ģʽ��?
	if (fullscreen)
	{
		DEVMODE dmScreenSettings;							// �豸ģʽ
		memset(&dmScreenSettings, 0,
			sizeof(dmScreenSettings));						// ȷ���ڴ����Ϊ��
		dmScreenSettings.dmSize =
			sizeof(dmScreenSettings);						// Devmode�ṹ�Ĵ�С
		dmScreenSettings.dmPelsWidth = width;				// ��ѡ��Ļ���
		dmScreenSettings.dmPelsHeight = height;				// ��ѡ��Ļ�߶�
		dmScreenSettings.dmBitsPerPel = bits;				// ÿ������ѡ��ɫ�����
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// ����������ʾģʽ�����ؽ����ע: CDS_FULLSCREEN ��ȥ��״̬����
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// ��ģʽʧ�ܣ��ṩ����ѡ��˳����ڴ��������С�
			if (MessageBox(NULL, "Fail to enter FullScreen Mode.\nEnter Window Mode��", "Window Mode Error",
				MB_YESNO | MB_ICONEXCLAMATION) == IDYES)	// �������,���M��˷�֧
			{
				fullscreen = FALSE;							// ѡ�񴰿�ģʽ
			}
			else
			{
				// ����һ���Ի��򣬸����û��������
				MessageBox(NULL, "Program aborted.", "Window Mode Error", MB_OK | MB_ICONSTOP);
				return FALSE;								// �˳�������FALSE
			}
		}
	}

	// �Դ���ȫ��ģʽ��?
	if (fullscreen)
	{
		dwExStyle = WS_EX_APPWINDOW;						// ǿ�����ǵĴ���ɼ�ʱ������ǰ��
		dwStyle = WS_POPUP;									// ������
		ShowCursor(FALSE);									// �������ָ��
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;		// ǿ�����ǵĴ���ɼ�ʱ������ǰ��
															// �K��ǿ�����3D�й�
		dwStyle = WS_OVERLAPPEDWINDOW;						// �����������ɱ��С�ı߿򡢲˵�														// �����/��С����ť�Ĵ���;
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);	// �������ڴﵽ����Ҫ��Ĵ�С
	// ȫ��ģʽ�£���������Ч

	if (!(hWnd = CreateWindowEx(dwExStyle,					// ��չ������
		"OpenG",											// ������
		title,												// ���ڱ���
		WS_CLIPSIBLINGS |									// ����Ĵ���������,��ֹ��Ĵ��������ǵĴ�����/�ϻ�ͼ
		WS_CLIPCHILDREN |									// ����Ĵ���������,��ֹ��Ĵ��������ǵĴ�����/�ϻ�ͼ
		dwStyle,											// ѡ��Ĵ�������
		0, 0,												// ����λ��
		WindowRect.right - WindowRect.left,					// ��������õĴ��ڿ��
		WindowRect.bottom - WindowRect.top,					// ��������õĴ��ڸ߶�
		NULL,												// �޸�����
		NULL,												// �޲˵�
		hInstance,											// ʵ��
		NULL)))												// ����WM_CREATE�����κζ���
	{
		ReleaseGLWindow();										// ������ʾ��
		MessageBox(NULL, "Fail to create an OpenGL Window", "Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// ����FALSE
	}

	// pfd���ߴ���������ϣ���Ķ�����������ʹ�õ����ظ�ʽ
	static	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),						// ������ʽ�������Ĵ�С
		1,													// �汾��
		PFD_DRAW_TO_WINDOW |								// ��ʽ֧�ִ���
		PFD_SUPPORT_OPENGL |								// ��ʽ����֧��OpenGL
		PFD_DOUBLEBUFFER,									// ����֧��˫����
		PFD_TYPE_RGBA,										// ���� RGBA ��ʽ
		bits,												// ѡ��ɫ�����
		0, 0, 0, 0, 0, 0,									// ���Ե�ɫ��λ
		0,													// ��Alpha����
		0,													// ����Shift Bit
		0,													// ���ۼӻ���
		0, 0, 0, 0,											// ���Ծۼ�λ
		16,													// 16λ Z-���� (��Ȼ���)
		0,													// ���ɰ建��
		0,													// �޸�������
		PFD_MAIN_PLANE,										// ����ͼ��
		0,													// Reserved
		0, 0, 0												// ���Բ�����
	};

	// ȡ���豸��������ô?
	if (!(hDC = GetDC(hWnd)))
	{
		ReleaseGLWindow();										// ������ʾ��
		MessageBox(NULL, "Fail to create a pixal script.", "Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// ���� FALSE
	}

	// Windows �ҵ���Ӧ�����ظ�ʽ����?
	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))
	{
		ReleaseGLWindow();										// ������ʾ��
		MessageBox(NULL, "Fail to find pixal format.", "Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// ���� FALSE
	}

	// Windows �ܹ��������ظ�ʽô?
	if (!SetPixelFormat(hDC, PixelFormat, &pfd))
	{
		ReleaseGLWindow();										// ������ʾ��
		MessageBox(NULL, "Fail to set pixal format.", "Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// ���� FALSE
	}

	// �ܷ�ȡ����ɫ������?
	if (!(hRC = wglCreateContext(hDC)))
	{
		ReleaseGLWindow();										// ������ʾ��
		MessageBox(NULL, "Fail to create OpenGL DC.", "Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// ���� FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))							// ���Լ�����ɫ������
	{
		ReleaseGLWindow();										// ������ʾ��
		MessageBox(NULL, "Fail to activate OpenGL DC.", "Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// ���� FALSE
	}

	// ����OpenGL�����Ѿ��������

	ShowWindow(hWnd, SW_SHOW);								// ��ʾ����
	SetForegroundWindow(hWnd);								// ���һ�c���ȼ�
	SetFocus(hWnd);											// ���ü��̵Ľ������˴���
	ReSizeGLScene(width, height);							// ����͸�� GL ��Ļ

	if (!InitGL())											// ��ʼ���½���GL����
	{
		ReleaseGLWindow();										// ������ʾ��
		MessageBox(NULL, "Initialization Failed.", "Initialization Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// ����FALSE
	}

	return TRUE;											// �ɹ�
}

//*****************************************************************************

LRESULT CALLBACK WndProc(HWND hWnd,	// ���ڵľ��
	UINT	uMsg,					// ���ڵ���Ϣ
	WPARAM	wParam,					// ���ӵ���Ϣ����
	LPARAM	lParam)					// ���ӵ���Ϣ����
	//	����:	�������еĴ�����Ϣ��
{
	switch (uMsg)					// ���Windows��Ϣ, uMsg�б���������Ҫ�������Ϣ���֡�
	{
	case WM_ACTIVATE:				// ���Ӵ��ڼ�����Ϣ
	{
		if (!HIWORD(wParam))		// �����С��״̬
		{
			active = TRUE;			// �����ڼ���״̬
		}
		else
		{
			active = FALSE;			// �����ټ���
		}

		return 0;					// ������Ϣѭ��
	}

	case WM_SYSCOMMAND:				// ϵͳ�ж�����
	{
		switch (wParam)				// ���ϵͳ����
		{
		case SC_SCREENSAVE:			// ����Ҫ����?
		case SC_MONITORPOWER:		// ��ʾ��Ҫ����ڵ�ģʽ?
			return 0;				// ��ֹ����
		}
		break;						// �˳�
	}

	case WM_CLOSE:					// �յ�Close��Ϣ?
	{
		PostQuitMessage(0);			// �����˳���Ϣ
		return 0;					// ����
	}

	case WM_KEYDOWN:				// �м�����ô?
	{
		keys[wParam] = TRUE;		// ����ǣ���ΪTRUE
		return 0;					// ����
	}

	case WM_KEYUP:					// �м��ſ�ô?
	{
		keys[wParam] = FALSE;		// ����ǣ���ΪFALSE
		return 0;					// ����
	}

	case WM_SIZE:					// ����OpenGL���ڴ�С
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));		// LoWord=Width,HiWord=Height
		return 0;					// ����
	}
	}

	// �� DefWindowProc��������δ�������Ϣ(�����f�����@Щ��������Ϣ)��
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//*****************************************************************************

int WINAPI WinMain(HINSTANCE hInstance,			// ��ǰ����ʵ��
	HINSTANCE	hPrevInstance,					// ǰһ������ʵ��
	LPSTR		lpCmdLine,						// �����в���
	int			nCmdShow)						// ������ʾ״̬
//	����:	Windows�������ڡ�������ô��ڴ������̣���������Ϣ���������˻�����
{
	MSG	msg;									// Windowsx��Ϣ�ṹ
	BOOL done = FALSE;							// �����˳�ѭ����Bool����

	// ��ʾ�û�ѡ������ģʽ
	if (MessageBox(NULL, "Welcome!\n Would you like to run in FullScreen?", "Welcome", MB_YESNO | MB_ICONQUESTION) == IDNO)
	{
		fullscreen = FALSE;						// FALSEΪ����ģʽ
	}

	// ����OpenGL����
	if (!CreateGLWindow("OpenGL1", 640, 480, 16, fullscreen))	// ���⡢��ȡ��߶ȡ�ɫ����ȣ��Լ�ȫ����־
	{
		return 0;												// ʧ���˳�
	}

	// �S�ֵ�ޒȦ
	while (!done)								// ����ѭ��ֱ�� done==TRUE
	{
		if (GetMessage(&msg, NULL, 0, 0))		// ����Ϣ�ڵȴ���?
		{
			if (msg.message == WM_QUIT)			// �յ��˳���Ϣ?
			{
				done = TRUE;					// �ǣ���done=TRUE
			}
			else								// ���ǣ���������Ϣ
			{
				TranslateMessage(&msg);			// ������Ϣ
				DispatchMessage(&msg);			// ������Ϣ
			}
		}
		else									// ���û����Ϣ
		{
			// ���Ƴ���������ESC��������DrawGLScene()���˳���Ϣ
			// �ȿ����򼤻���ô?
			if (active)							
			{
				// ESC ������ô?
				if (keys[VK_ESCAPE])					
					done = TRUE;				// ESC �����˳��ź�
				
				// �]��ESC���ǶΕr�g��ˢ����Ļ
				else							
				{
					DrawGLScene();				// ���Ƴ���
					SwapBuffers(hDC);			// ��������(˫����),����ʵ������˸�Ķ���
				}
			}

			// �����û�����F1����ȫ��ģʽ�ʹ���ģʽ���л�
			if (keys[VK_F1])					// F1��������ô?
			{
				keys[VK_F1] = FALSE;			// ���ǣ�ʹ��Ӧ��Key�����е�ֵΪ FALSE
				ReleaseGLWindow();					// ���ٵ�ǰ�Ĵ���
				fullscreen = !fullscreen;		// �л�ȫ��/����ģʽ
				
				// �ؽ� OpenGL ����
				if (!CreateGLWindow("OpenGL1", 640, 480, 16, fullscreen))				
					return 0;					// �������δ�ܴ����������˳�				
			}
		}
	}
	// done ׃����TRUE, �رճ���
	ReleaseGLWindow();							// ���ٴ���
	return (msg.wParam);						// �˳�����
}

