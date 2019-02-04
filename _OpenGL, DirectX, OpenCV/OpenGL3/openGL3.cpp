//*****************************************************************************
//	�@��һ��OpenGL��������,����NeHe��OpenGL�̶̳���
//	�˾���OpenGL1��ɵ���Lesson6��
//	���ܣ�
//	���F���w���N�D֮�L�u��
//*****************************************************************************

#include <windows.h>	// Windows��ͷ�ļ�
#include <glew.h>		// �������µ�gl.h,glu.h��
#include <glut.h>		// ����OpenGLʵ�ÿ�
#include <stdio.h>		// ��׼����/������ͷ�ļ�
#include <glaux.h>		// GLaux���ͷ�ļ�

HGLRC           hRC = NULL;							// ������ɫ��������
HDC             hDC = NULL;							// OpenGL��Ⱦ��������
HWND            hWnd = NULL;						// �������ǵĴ��ھ��
HINSTANCE       hInstance;							// ��������ʵ��

bool			keys[256];							// ������̰���������
bool			active = TRUE;						// ���ڵĻ��־��ȱʡΪTRUE
bool			fullscreen = FALSE;					// �@߅��ͬ춽̳̣�ȱʡ�鴰��ģʽ

GLfloat		xrot;									// X ��ת��
GLfloat		yrot;									// Y ��ת��
GLfloat		zrot;									// Z ��ת��

GLuint		texture[1];								// �洢һ������

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// WndProc����

AUX_RGBImageRec *LoadBMP(char *Filename)
// ����:	����λͼͼ��
{
	FILE *file = NULL;								// �ļ����
	if (!Filename)									// ȷ���ļ������ṩ
		return NULL;								// ���û�ṩ������ NULL

	file = fopen((char*)Filename, "r");				// ���Դ��ļ�
	if (file)										// �ļ�����ô?
	{
		fclose(file);								// �رվ��
		return auxDIBImageLoad((LPCWSTR)Filename);	// ����λͼ������ָ��
	}
	return NULL;									// �������ʧ�ܣ����� NULL
}

//*****************************************************************************

BOOL LoadGLTextures()
// ����:	����λͼ(��������Ĵ���)��ת��������
{
	BOOL Status = FALSE;							// ״ָ̬ʾ�Ƿ��܉��d��λ�D�������y��
	AUX_RGBImageRec *TextureImage[1];				// ��������Ĵ洢�ռ�
	memset(TextureImage, 0, sizeof(void *)* 1);		// ��ָ����Ϊ NULL

	// ����λͼ��������޴������λͼû�ҵ����˳�
	if (TextureImage[0] = LoadBMP("D:\\Visual C++ programs\\OpenGL3\\NeHe.bmp"))
	{
		Status = TRUE;								// �� Status ��Ϊ TRUE
		glGenTextures(1, &texture[0]);				// ��������

		// ʹ������λͼ�������ɵĵ�������
		glBindTexture(GL_TEXTURE_2D, texture[0]);

		// ���ɼy��
		glTexImage2D(GL_TEXTURE_2D,					// ����OpenGL��������һ��2D����
			0,										// ͼ�����ϸ�̶�,ͨ����0
			3,										// ���ݵĳɷ���(�t�G�{���N�ɷ�ռ�׷N)
			TextureImage[0]->sizeX,					// ����Ŀ��
			TextureImage[0]->sizeY,					// ����ĸ߶�
			0,										// �߿��ֵ��һ�����0 
			GL_RGB,									// ����OpenGLͼ�������ɺ졢�̡�����ɫ�������
			GL_UNSIGNED_BYTE,						// ���ͼ����������޷����ֽ�����
			TextureImage[0]->data);					// ����OpenGL�������ݵ���Դ

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// �sС�y��r�����˲���ʽ
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// �Ŵ�y��r�����˲���ʽ
	}

	// ጷŃȴ�
	if (TextureImage[0])							// �����Ƿ����
	{
		if (TextureImage[0]->data)					// ����ͼ���Ƿ����
			free(TextureImage[0]->data);			// �ͷ�����ͼ��ռ�õ��ڴ�
		free(TextureImage[0]);						// �ͷ�ͼ��ṹ
	}
	return Status;									// ���� Status
}

//*****************************************************************************

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
	// �y��֧��
	if (!LoadGLTextures())					// ������������������
		return FALSE;						// ���δ�����룬����FALSE
	glEnable(GL_TEXTURE_2D);				// ��������ӳ��

	// ������ʼ��
	glShadeModel(GL_SMOOTH);				// ������Ӱƽ��

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// �����Ļʱ���õ���ɫ������ɫ,��̎�Ǻ�ɫ

	glClearDepth(1.0f);						// ������Ȼ���
	glEnable(GL_DEPTH_TEST);				// ������Ȳ���
	glDepthFunc(GL_LEQUAL);					// ������Ȳ��Ե�����

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// ����ϵͳ��͸�ӽ�������(���ÿ�)

	return TRUE;							// ��ʼ��OK�ͷ���TRUE
}

//*****************************************************************************

int DrawGLScene(GLvoid)								
// ����:	�����￪ʼ�������еĻ���
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			// �����Ļ����Ȼ���
	glLoadIdentity();											// ���õ�ǰ��ģ�͹۲����
																// OpenGL��Ļ�����u��(0,0),����ϵ
	// ���@�e�_ʼ�L�u
	glTranslatef(0.0f, 0.0f, -5.0f);							// ���P�Ƅӵ�(0.0f, 0.0f, -5.0f)�c
	
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);							// ��X����ת
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);							// ��Y����ת
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);							// ��Z����ת

	// ע��: ������ glBegin()�� glEnd()֮�������, ������ glBegin()֮ǰ�� glEnd()֮���
	glBindTexture(GL_TEXTURE_2D, texture[0]);					// ѡ������

	// �_ʼ�L�u
	glBegin(GL_QUADS);
	// ǰ��
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);		// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// ������ı��ε�����
	// ����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// ������ı��ε�����
	// ����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);		// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// ������ı��ε�����
	// ����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// ������ı��ε�����
	// ����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);		// ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// ������ı��ε�����
	// ����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// ������ı��ε�����
	glEnd();

	// �O�����D
	xrot += 0.3f;												// X ����ת
	yrot += 0.2f;												// Y ����ת
	zrot += 0.4f;												// Z ����ת

	return TRUE;												// һ��OK, FALSE��Ԓ���򼴌��˳�
}

//*****************************************************************************

GLvoid ReleaseGLWindow(GLvoid)
// ����:	�������ٴ���
{
	// ���Ǵ���ȫ��ģʽ��?
	if (fullscreen)
	{
		ChangeDisplaySettings(NULL, 0);			// �ǵĻ����л�������,���˷�ֹĳЩ�@����������ֱ���
		ShowCursor(TRUE);						// ��ʾ���ָ��
	}

	// ����ӵ��OpenGL��Ⱦ��������?
	if (hRC)
	{
		// �����ܷ��ͷ�DC��RC������?
		if (!wglMakeCurrent(NULL, NULL))
			MessageBox(NULL, L"Fail to release DC or RC.", L"Shutdown Error", MB_OK | MB_ICONINFORMATION);

		// �����ܷ�ɾ��RC?
		if (!wglDeleteContext(hRC))
			MessageBox(NULL, L"Fail to release RC.", L"Shutdown Error", MB_OK | MB_ICONINFORMATION);

		hRC = NULL;							// ��RC��ΪNULL
	}

	// �����ܷ��ͷ�DC?
	if (hDC && !ReleaseDC(hWnd, hDC))
	{
		MessageBox(NULL, L"Fail to release DC.", L"Shutdown Error", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;							// ��DC��ΪNULL
	}

	// �ܷ����ٴ���?
	if (hWnd && !DestroyWindow(hWnd))
	{
		MessageBox(NULL, L"Fail to release Wnd", L"Shutdown Error", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;						// ��hWnd��ΪNULL
	}

	// �ܷ�ע����?
	if (!UnregisterClass(L"OpenGL", hInstance))
	{
		MessageBox(NULL, L"Fail to unregister class \"OpenGL\".", L"Shutdown Error", MB_OK | MB_ICONINFORMATION);
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
	WindowRect.left = (long)100;							// ��Left   ��Ϊ 0
	WindowRect.top = (long)50;								// ��Top    ��Ϊ 0
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
	wc.lpszClassName = L"OpenGL";							// �������

	if (!RegisterClass(&wc))								// ����ע�ᴰ����
	{
		MessageBox(NULL, L"Fail to register window", L"Register Error", MB_OK | MB_ICONEXCLAMATION);
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
			if (MessageBox(NULL, L"Fail to enter FullScreen Mode.\nEnter Window Mode��", L"Window Mode Error",
				MB_YESNO | MB_ICONEXCLAMATION) == IDYES)	// �������,���M��˷�֧
			{
				fullscreen = FALSE;							// ѡ�񴰿�ģʽ
			}
			else
			{
				// ����һ���Ի��򣬸����û��������
				MessageBox(NULL, L"Program aborted.", L"Window Mode Error", MB_OK | MB_ICONSTOP);
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
		L"OpenGL",											// ������
		(LPCWSTR)title,										// ���ڱ���
		dwStyle |											// ѡ��Ĵ�������
		WS_CLIPSIBLINGS |									// ����Ĵ���������,��ֹ��Ĵ��������ǵĴ�����/�ϻ�ͼ
		WS_CLIPCHILDREN ,									// ����Ĵ���������,��ֹ��Ĵ��������ǵĴ�����/�ϻ�ͼ 
		WindowRect.left, WindowRect.top,					// ����λ��
		WindowRect.right - WindowRect.left,					// ��������õĴ��ڿ��
		WindowRect.bottom - WindowRect.top,					// ��������õĴ��ڸ߶�
		NULL,												// �޸�����
		NULL,												// �޲˵�
		hInstance,											// ʵ��
		NULL)))												// ����WM_CREATE�����κζ���
	{
		ReleaseGLWindow();										// ������ʾ��
		MessageBox(NULL, L"Fail to create an OpenGL Window", L"Creation Error", MB_OK | MB_ICONEXCLAMATION);
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
		MessageBox(NULL, L"Fail to create a pixal script.", L"Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// ���� FALSE
	}

	// Windows �ҵ���Ӧ�����ظ�ʽ����?
	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))
	{
		ReleaseGLWindow();										// ������ʾ��
		MessageBox(NULL, L"Fail to find pixal format.", L"Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// ���� FALSE
	}

	// Windows �ܹ��������ظ�ʽô?
	if (!SetPixelFormat(hDC, PixelFormat, &pfd))
	{
		ReleaseGLWindow();										// ������ʾ��
		MessageBox(NULL, L"Fail to set pixal format.", L"Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// ���� FALSE
	}

	// �ܷ�ȡ����ɫ������?
	if (!(hRC = wglCreateContext(hDC)))
	{
		ReleaseGLWindow();										// ������ʾ��
		MessageBox(NULL, L"Fail to create OpenGL DC.", L"Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// ���� FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))							// ���Լ�����ɫ������
	{
		ReleaseGLWindow();										// ������ʾ��
		MessageBox(NULL, L"Fail to activate OpenGL DC.", L"Creation Error", MB_OK | MB_ICONEXCLAMATION);
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
		MessageBox(NULL, L"Initialization Failed.", L"Initialization Error", MB_OK | MB_ICONEXCLAMATION);
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

	// �@߅�Ȳ������x��ģʽ��,ע������´a��
	// ��ʾ�û�ѡ������ģʽ
	//if (MessageBox(NULL, L"Welcome!\n Would you like to run in FullScreen?", L"Welcome", MB_YESNO | MB_ICONQUESTION) == IDYES)
	//{
	//	fullscreen = TRUE;						// FALSEΪ����ģʽ
	//}

	// ����OpenGL����
	if (!CreateGLWindow("OpenGL1", 640, 480, 16, fullscreen))	// ���⡢��ȡ��߶ȡ�ɫ����ȣ��Լ�ȫ����־
	{
		return 0;												// ʧ���˳�
	}

	// �S�ֵ�ޒȦ
	while (!done)								// ����ѭ��ֱ�� done==TRUE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))		// ����Ϣ�ڵȴ���?
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
				ReleaseGLWindow();				// ���ٵ�ǰ�Ĵ���
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

