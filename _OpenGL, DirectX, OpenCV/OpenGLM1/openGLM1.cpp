//*****************************************************************************
//	�@��һ���M�AOpenGL��������,����NeHe��OpenGL�̶̳���
//	�˾���OpenGL1��ɵ���Lesson9��
//	���ܣ�
//	��3D�������ƶ�λͼ����ȥ��λͼ�ϵĺ�ɫ����(ʹ�û�ɫ)��
//*****************************************************************************

#include <windows.h>	// Windows��ͷ�ļ�
#include <glew.h>		// �������µ�gl.h,glu.h��
#include <glut.h>		// ����OpenGLʵ�ÿ�
#include <stdio.h>		// ��׼���������ͷ�ļ�
#include <glaux.h>		// GLaux���ͷ�ļ�

HGLRC           hRC = NULL;							// ������ɫ��������
HDC             hDC = NULL;							// OpenGL��Ⱦ��������
HWND            hWnd = NULL;						// �������ǵĴ��ھ��
HINSTANCE       hInstance;							// ��������ʵ��

bool			keys[256];							// ������̰���������
bool			active = TRUE;						// ���ڵĻ��־��ȱʡΪTRUE
bool			fullscreen = FALSE;					// �@߅��ͬ춽̳̣�ȱʡ�鴰��ģʽ

BOOL			twinkle;							// ��˸������
BOOL			tp;									// 'T' ������ô? DOUBLE

const GLuint	NUM_OF_STARS = 50;					// ���Ƶ�������

struct Stars										// Ϊ���Ǵ���һ���ṹ�w
{
	GLuint r, g, b;									// ���ǵ���ɫ
	GLfloat dist;									// ���Ǿ������ĵľ���
	GLfloat angle;									// ��ǰ���������ĽǶ�
};													// �ṹ����Ϊstars
Stars star[NUM_OF_STARS];							// ʹ�� 'stars' �ṹ����һ������ 'num'��Ԫ�ص� 'star'����

GLfloat	zoom = -15.0f;								// ������۲��ߵľ����ʼֵ
GLfloat xPos = 0.0f;								// �M�Sλ��
GLfloat yPos = 0.0f;								// �v�Sλ��
GLfloat tilt = 90.0f;								// ���ǵ����
GLfloat	spin;										// ��˸���ǵ���ת

GLuint	texture[1];									// ���һ������

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);// WndProc����

AUX_RGBImageRec *LoadBMP(char *Filename)			// ����λͼ�ļ�
{
	FILE *File = NULL;								// �ļ����

	if (!Filename)									// ȷ���Ѹ����ļ���
	{
		return NULL;								// ���޷��� NULL
	}

	File = fopen(Filename, "r");					// ����ļ��Ƿ����

	if (File)										// �ļ�����ô?
	{
		fclose(File);								// �ر��ļ����
		return auxDIBImageLoadA((LPCSTR)Filename);	// ����λͼ������ָ��
	}
	return NULL;									// �������ʧ�ܷ��� NULL
}

//*****************************************************************************

int LoadGLTextures()								// ����λͼ��ת��������
{
	int Status = FALSE;								// ״ָ̬ʾ��

	AUX_RGBImageRec *TextureImage[1];				// Ϊ�������洢�ռ�

	memset(TextureImage, 0, sizeof(void *)* 1);		// ��ָ����Ϊ NULL

	// ����λͼ��������δ�ҵ�λͼ�ļ����˳�
	if (TextureImage[0] = LoadBMP("Star.bmp"))
	{
		Status = TRUE;								// �� Status ��ΪTRUE

		glGenTextures(1, &texture[0]);				// ����һ������

		// ����һ�������˲�����
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
	}

	if (TextureImage[0])					// ����������
	{
		if (TextureImage[0]->data)			// �������ͼ�����
		{
			free(TextureImage[0]->data);		// �ͷ�����ͼ����ռ���ڴ�
		}

		free(TextureImage[0]);				// �ͷ�ͼ��ṹ
	}

	return Status;						// ���� Status��ֵ
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
	if (!LoadGLTextures())					// ������������������
	{
		return FALSE;						// ���δ�����룬����FALSE
	}

	glEnable(GL_TEXTURE_2D);				// ��������ӳ��
	glShadeModel(GL_SMOOTH);				// ������Ӱƽ��
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);	// �����Ļʱ���õ���ɫ������ɫ,��̎�Ǻ�ɫ
	glClearDepth(1.0f);						// ������Ȼ���
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// ����ϵͳ��͸�ӽ�������(���ÿ�)
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);		// ���û�ɫ����ȡ�ð�͸��Ч��
	glEnable(GL_BLEND);						// ���û�ɫ

	// ��ʼ������
	for (int i = 0; i < NUM_OF_STARS; i++)	// ����ѭ������ȫ������
	{
		star[i].angle = 0.0f;							// �������Ƕ�����Ƕȿ�ʼ
		star[i].dist = (float(i) / NUM_OF_STARS)*5.0f;	// �������������ĵľ���
		star[i].r = rand() % 256;			// Ϊstar[i]��������tɫ����
		star[i].g = rand() % 256;			// Ϊstar[i]��������Gɫ����
		star[i].b = rand() % 256;			// Ϊstar[i]��������{ɫ����
	}
	return TRUE;							// ��ʼ��OK�ͷ���TRUE
}

//*****************************************************************************

int DrawGLScene(GLvoid)								
// ����:	�����￪ʼ�������еĻ���
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// �����Ļ����Ȼ���
	glLoadIdentity();									// ���õ�ǰ��ģ�͹۲����
														// OpenGL��Ļ�����u��(0,0),����ϵ
	// ���@�e�_ʼ�L�u
	for (int i = 0; i < NUM_OF_STARS; i++)
	{
		glLoadIdentity();								// ����ÿ������֮ǰ������ģ�͹۲����
		glTranslatef(xPos, yPos, zoom);					// ������Ļ����
		glRotatef(tilt, 1.0f, 0.0f, 0.0f);				// ��б�ӽ�
		glRotatef(star[i].angle, 0.0f, 1.0f, 0.0f);		// ��ת����ǰ�������ǵĽǶ�
		glTranslatef(star[i].dist, 0.0f, 0.0f);			// ���ѽ����D�^��X�������ƶ�
		glRotatef(-star[i].angle, 0.0f, 1.0f, 0.0f);	// ȡ����ǰ���ǵĽǶ�
		glRotatef(-tilt, 1.0f, 0.0f, 0.0f);				// ȡ����Ļ��б

		// �L�u��һ������(������W�qЧ����Ԓ)
		if (twinkle)									// ������˸Ч��
		{
			// ʹ��byte����ֵָ��һ����ɫ
			glColor4ub(star[(NUM_OF_STARS - i) - 1].r, 
				star[(NUM_OF_STARS - i) - 1].g, 
				star[(NUM_OF_STARS - i) - 1].b, 
				255);
			glBegin(GL_QUADS);							// ��ʼ��������ӳ������ı���

			// ���c���»��a���ɫ
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
			glEnd();									// �ı��λ��ƽ���
		}

		// �L�u�ڶ�������
		glRotatef(spin, 0.0f, 0.0f, 1.0f);				// ��z����ת����
		// ʹ��byte����ֵָ��һ����ɫ
		glColor4ub(star[i].r, star[i].g, star[i].b, 255);
		glBegin(GL_QUADS);								// ��ʼ��������ӳ������ı���
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();										// �ı��λ��ƽ���

		spin += 0.01f;									// �@�w���ǵĹ�ת, Խ��ȥԽ��
		star[i].angle += float(i) / NUM_OF_STARS;		// �ı����ǵ���ת�Ƕ�
		star[i].dist -= 0.01f;							// �ı����������ĵľ���

		if (star[i].dist < 0.0f)						// ���ǵ���������ô
		{
			star[i].dist += 5.0f;						// ������5����λ
			star[i].r = rand() % 256;					// ��һ���º�ɫ����
			star[i].g = rand() % 256;					// ��һ������ɫ����
			star[i].b = rand() % 256;					// ��һ������ɫ����
		}
	}

	return TRUE;										// һ��OK, FALSE��Ԓ���򼴌��˳�
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
//BOOL CreateGLWindow(LPCSTR title, int width, int height, int bits, bool fullscreenflag)
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

	if (!(hWnd = CreateWindowExA(dwExStyle,					// ��չ������
		"OpenGL",											// ������
		title,												// ���ڱ���
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
	if (!CreateGLWindow("OpenGLM1 -- Stars", 640, 480, 16, fullscreen))	// ���⡢��ȡ��߶ȡ�ɫ����ȣ��Լ�ȫ����־
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

					// ����T�I
					if (keys['T'] && !tp)				
					{
						tp = TRUE;				// ���ǣ���tp��ΪTRUE
						twinkle = !twinkle;		// ��ת twinkle��ֵ
					}
					if (!keys['T'])				// T �����ɿ���ô��
					{
						tp = FALSE;				// ���� ��tpΪ FALSE
					}

					// �������������I
					if (keys['W'])			
					{
						tilt -= 0.5f;			// ��Ļ������б
					}

					if (keys['S'])			
					{
						tilt += 0.5f;			// ��Ļ������б
					}

					if (keys[VK_UP])
					{
						yPos -= 0.02f;			// ��Ļ�����Ƅ�(����ȥ���R�^����һ��)
					}

					if (keys[VK_DOWN])
					{
						yPos += 0.02f;			// ��Ļ�����Ƅ�(����ȥ���R�^����һ��)
					}

					if (keys[VK_LEFT])
					{
						xPos += 0.02f;			// ��Ļ�����Ƅ�(����ȥ���R�^����һ��)
					}

					if (keys[VK_RIGHT])
					{
						xPos -= 0.02f;			// ��Ļ�����Ƅ�(����ȥ���R�^����һ��)
					}

					if (keys[VK_PRIOR])			// ���Ϸ�ҳ��������ô
					{
						zoom -= 0.02f;			// ��С
					}

					if (keys[VK_NEXT])			// ���·�ҳ��������ô��
					{
						zoom += 0.02f;			// �Ŵ�
					}


				}
			}

			// �����û�����F1����ȫ��ģʽ�ʹ���ģʽ���л�
			if (keys[VK_F1])					// F1��������ô?
			{
				keys[VK_F1] = FALSE;			// ���ǣ�ʹ��Ӧ��Key�����е�ֵΪ FALSE
				ReleaseGLWindow();				// ���ٵ�ǰ�Ĵ���
				fullscreen = !fullscreen;		// �л�ȫ��/����ģʽ
				
				// �ؽ� OpenGL ����
				if (!CreateGLWindow("OpenGLM1 -- Stars", 640, 480, 16, fullscreen))				
					return 0;					// �������δ�ܴ����������˳�				
			}
		}
	}
	// done ׃����TRUE, �رճ���
	ReleaseGLWindow();							// ���ٴ���
	return (msg.wParam);						// �˳�����
}

