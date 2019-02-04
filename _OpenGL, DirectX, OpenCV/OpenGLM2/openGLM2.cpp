//*****************************************************************************
//	�@��һ���M�AOpenGL��������,����NeHe��OpenGL�̶̳���
//	�˾���OpenGL2��ɵ���Lesson10��
//	���ܣ�
//	����3D������
//*****************************************************************************
#include "OpenGLM2\utiltyGL.h"
#include "OpenGLM2\resource.h"
#include "CLoad3DS.h"


//*****************************************************************************
// ������壬����Ա�ڴ���ӿ��Ʊ���֮ѶϢ��д��utilityGL.h�У�
//*****************************************************************************
BOOL	mp_load_texture = TRUE;						// �Ƿ���������
BOOL	mp_enable_mode_choose = FALSE;				// �Ƿ����û�ѡ���Ƿ�ȫ��Ļ
BOOL	mp_fullscreen = FALSE;						// �Ƿ�һ��ʼ��ȫ��Ļ
BOOL	mp_show_crusor = FALSE;						// �Ƿ�һ�_ʼ�@ʾ����
BOOL	mp_enable_light = FALSE;					// �Ƿ����ù�Դ
BOOL	mp_enable_model = TRUE;					// �Ƿ���ģ�͌���
char*	f_world_file = "F:\\Visual C++ programs\\OpenGLM2\\World.txt";// �򿪵��ļ�(������Ϣ��)
char*	f_world_file2 = "F:\\Visual C++ programs\\OpenGLM2\\Door.txt";
char*	f_bmp_name = "F:\\Visual C++ programs\\OpenGLM2\\Crate.bmp";// ���������λͼ
char*	f_bmp_name2 = "F:\\Visual C++ programs\\OpenGLM2\\Door.bmp";
char*	f_model_file = "F:\\Visual C++ programs\\OpenGLM2\\Data\\3DS\\ABRAMS_L.3DS";		// ģ���ļ�
char*	f_window_name = "cstrike";					// ��������
// ԭ�������Q: OpenGLM2 -- Scene
FLOAT	sp_mouse_factor = 2.0f;						// ����`����
LONG	mp_window_width = 640;						// �����L(�M��)
LONG	mp_window_height = 480;						// ���ڸ�(�v��)
LONG	mp_window_left_top_x = 100;					// ���ڳ�ʼ���r���ϽǙM����
LONG	mp_window_left_top_y = 50;					// ���ڳ�ʼ���r���Ͻǿv����
FLOAT	sp_world_size = 4.0f;						// �ſs�x���������ٱ�, >1�Ŵ�,<1�sС
FLOAT	sp_max_head_angle = 50.0f;					// ���Ǹ��ǵ����ֵ(�^���ԔE���)
FLOAT	sp_cwral_degree = 0.002f;					// �¶׳̶�,����Խ���¶׵�Խ����
GLuint	sp_crawl_smooth = 60;						// �¶�ƽ���̶�,����Խ��Խƽ��(��Ҳ�������¶׳̶�)
GLfloat	sp_hop_v0 = 0.3f;							// ���S�ĳ�ʼ����
GLfloat sp_walk_speed = 0.002f;						// ��·����
GLfloat	sp_shift_speed = 5.0f;						// ׃������,>1�Ǽ���--����,<1�ǜp��--�����_��
GLfloat sp_gravity = 5.0f;							// ����
FLOAT	sp_max_height = 0.6f;						// ���S���߶�
FLOAT	sp_jump_duration = 0.5f;					// ���S�r�g
GLuint	sp_mouse_factor_rotate = 25;				// ����������D��������,����Խ�����Խ��
//*****************************************************************************

// ����
const GLfloat PI_OVER_180 = 0.0174532925f;
const GLuint ONE_LINE_WORDS = 255;

//	���㡢�����Ρ�����֮���ݽṹ
struct VERTEX										// ����Vertex����ṹ
{
	GLfloat x, y, z;								// 3D ����
	GLfloat u, v;									// ��������
};													// ����ΪVERTEX

struct TRIANGLE										// ����Triangle�����νṹ
{
	VERTEX vertex[3];								// VERTEXʸ�����飬��СΪ3
};													// ����Ϊ TRIANGLE

struct SECTOR										// ����Sector���νṹ
{
	GLuint numTriangles;							// Sector�е������θ���
	TRIANGLE* triangle;								// ָ�����������ָ��
};													// ����ΪSECTOR

// ���Ƽy���^�V���
GLuint	filter = 2;									// �˲�����
GLuint	texture[4];									// 3������Ĵ���ռ� + �T�ļy��
BOOL	fp;											// F��������ô?

// ���ƹ�Դ
BOOL	light;										// ��Դ�Ŀ�/��
BOOL	lp;											// L��������ô?
GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };// ���������
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };// ��������
GLfloat LightPosition[] = { 0.0f, 0.0f, 2.0f, 1.0f };// ��Դλ��

// ����͸��
bool    blend = FALSE;								// �Ƿ���?
bool	bp;											// B ��������ô?

// ������ߵı�������
GLfloat heading;
GLfloat xpos;
GLfloat zpos;
GLfloat	yrot;										// ��y��֮��ת
GLfloat walkbias = 0;								// �������ʱͷ���������°ڶ��ķ���
GLfloat walkbiasangle = 0;
GLfloat lookupdown = 0.0f;
GLfloat	z = 0.0f;									// ������Ļ�ľ���
BOOL cp;											// �Ƿ��¶�
BOOL sp;											// �Ƿ�׃��
BOOL hp;											// �Ƿ����S
BOOL mp;											// �Ƿ���ģ��
GLfloat walkbiasDefault;							// ���S�r��ʼ֮λ��
GLfloat sp_walk_speedCurrent;							// ���r��������

// ��˿���
POINT mousePosPre;
POINT mousePos;
enum mouseDirect {POSITIVE, NEGATIVE, STATIC, POSITIVE2X, NEGATIVE2X};		// ��˳����S��ؓ�S�����Ƅӡ��ҿ��D�Ӽ��١�����D�Ӽ���
enum windowRegion {INNER, OUTSIDE, LEFTMOST, RIGHTMOST};					// ����ڴ���֮λ��,�Ȳ�,�ⲿ,��˲���,�Ҷ˲���
mouseDirect mouseHorizon = STATIC;				// POSITIVE������,NEGATIVE������,STATIC�ǲ���
mouseDirect mouseVertical = STATIC;				// POSITIVE������,NEGATIVE������,STATIC�ǲ���
//BOOL ifShowCrusor;									// �Ƿ��@ʾ����,��축�ͣ����

// �����
SECTOR sector1;										// ����һ������, ����
SECTOR sector2;										// ����һ������, ���T

// �Ƿ�ͣ
BOOL ifPause = FALSE;

// �@ʾ����
GLuint	base;			// �����������ʾ�б�Ŀ�ʼλ��
GLfloat	cnt1;			// �����ƶ�������1
GLfloat	cnt2;			// �����ƶ�������2

// 3DSģ�͌���
CLoad3DS *gothicLoader = new(CLoad3DS);
t3DModel gothicModel;
DWORD tankZPos = 0;
float gothicTrans[10] = 
{
	0, 0.3, -9,			//��ʾ����������λ��
	0.0004, 0.0004, 0.0004,      //��ʾxyz�Ŵ���
	0, 0, 0, 0			//��ʾ��ת
};

// ��
BOOL isPlaying = FALSE;
BOOL isToPlay = FALSE;

//*****************************************************************************

GLvoid PlayMusic()
{
	if (isToPlay == TRUE)
	{
		// ��������
		if (isPlaying == FALSE)
		{
			isPlaying = TRUE;
			PlaySoundA("F:\\Visual C++ programs\\OpenGLM2\\footstep_1.wav", NULL, SND_ASYNC);
			//PlaySoundA("F:\\Visual C++ programs\\OpenGLM2\\footstep_2.wav", NULL, SND_NOWAIT);
			isPlaying = FALSE;
		}

	}
}

//*****************************************************************************

BOOL DetectBump(GLfloat xposDelta, GLfloat zposDelta, char state)
//	����:	������ͬchar��ʹ���ĸ����(W,A,S,D)�Д���������߹�����,����TRUE, 
//			��t����FALSE.
//	���{��:	WinMain()
{
	BOOL noBumpZ;
	BOOL noBumpX;
	switch (state)
	{	
	case 'W':
		if ((xpos - xposDelta < 0.4f * sp_world_size && xpos - xposDelta > -0.4f * sp_world_size))
		{
			if (zpos - zposDelta < 2.9f * sp_world_size && zpos - zposDelta > -2.9f * sp_world_size)
				noBumpZ = TRUE;
			else
				noBumpZ = FALSE;
		}
		else
		{
			if (zpos - zposDelta < 1.9f * sp_world_size && zpos - zposDelta > -1.9f * sp_world_size)
				noBumpZ = TRUE;
			else
				noBumpZ = FALSE;
		}
		if ((zpos - zposDelta < 0.4f * sp_world_size && zpos - zposDelta > -0.4f * sp_world_size))
		{
			if (xpos - xposDelta < 2.9f * sp_world_size && xpos - xposDelta > -2.9f * sp_world_size)
				noBumpX = TRUE;
			else
				noBumpX = FALSE;
		}
		else
		{
			if (xpos - xposDelta < 1.9f * sp_world_size && xpos - xposDelta > -1.9f * sp_world_size)
				noBumpX = TRUE;
			else
				noBumpX = FALSE;
		}
		break;

	case 'S':
		if ((xpos + xposDelta < 0.4f * sp_world_size && xpos + xposDelta > -0.4f * sp_world_size))
		{
			if (zpos + zposDelta < 2.9f * sp_world_size && zpos + zposDelta > -2.9f * sp_world_size)
				noBumpZ = TRUE;
			else
				noBumpZ = FALSE;
		}
		else
		{
			if (zpos + zposDelta < 1.9f * sp_world_size && zpos + zposDelta > -1.9f * sp_world_size)
				noBumpZ = TRUE;
			else
				noBumpZ = FALSE;
		}
		if ((zpos + zposDelta < 0.4f * sp_world_size && zpos + zposDelta > -0.4f * sp_world_size))
		{
			if (xpos + xposDelta < 2.9f * sp_world_size && xpos + xposDelta > -2.9f * sp_world_size)
				noBumpX = TRUE;
			else
				noBumpX = FALSE;
		}
		else
		{
			if (xpos + xposDelta < 1.9f * sp_world_size && xpos + xposDelta > -1.9f * sp_world_size)
				noBumpX = TRUE;
			else
				noBumpX = FALSE;
		}
		break;

	case 'A':
		if ((xpos - xposDelta < 0.4f * sp_world_size && xpos - xposDelta > -0.4f * sp_world_size))
		{
			if (zpos + zposDelta < 2.9f * sp_world_size && zpos + zposDelta > -2.9f * sp_world_size)
				noBumpZ = TRUE;
			else
				noBumpZ = FALSE;
		}
		else
		{
			if (zpos + zposDelta < 1.9f * sp_world_size && zpos + zposDelta > -1.9f * sp_world_size)
				noBumpZ = TRUE;
			else
				noBumpZ = FALSE;
		}
		if ((zpos + zposDelta < 0.4f * sp_world_size && zpos + zposDelta > -0.4f * sp_world_size))
		{
			if (xpos - xposDelta < 2.9f * sp_world_size && xpos - xposDelta > -2.9f * sp_world_size)
				noBumpX = TRUE;
			else
				noBumpX = FALSE;
		}
		else
		{
			if (xpos - xposDelta < 1.9f * sp_world_size && xpos - xposDelta > -1.9f * sp_world_size)
				noBumpX = TRUE;
			else
				noBumpX = FALSE;
		}
		break;

	case 'D':
		if ((xpos + xposDelta < 0.4f * sp_world_size && xpos + xposDelta > -0.4f * sp_world_size))
		{
			if (zpos - zposDelta < 2.9f * sp_world_size && zpos - zposDelta > -2.9f * sp_world_size)
				noBumpZ = TRUE;
			else
				noBumpZ = FALSE;
		}
		else
		{
			if (zpos - zposDelta < 1.9f * sp_world_size && zpos - zposDelta > -1.9f * sp_world_size)
				noBumpZ = TRUE;
			else
				noBumpZ = FALSE;
		}
		if ((zpos - zposDelta < 0.4f * sp_world_size && zpos - zposDelta > -0.4f * sp_world_size))
		{
			if (xpos + xposDelta < 2.9f * sp_world_size && xpos + xposDelta > -2.9f * sp_world_size)
				noBumpX = TRUE;
			else
				noBumpX = FALSE;
		}
		else
		{
			if (xpos + xposDelta < 1.9f * sp_world_size && xpos + xposDelta > -1.9f * sp_world_size)
				noBumpX = TRUE;
			else
				noBumpX = FALSE;
		}
		break;
	}
	return noBumpX && noBumpZ;
}

//*****************************************************************************

GLvoid SetCursorToCenter(GLvoid)
{
	tagRECT windowRect;			// ȡ�î�ǰҕ��
	GetWindowRect(hWnd, &windowRect);
	SetCursorPos((windowRect.left + windowRect.right) / 2, (windowRect.bottom + windowRect.top) / 2);
	mouseHorizon = STATIC;
	mouseVertical = STATIC;
}

//*****************************************************************************

GLvoid BuildFont(GLvoid)						// ����λͼ����
{
	HFONT	font;								// ������
	HFONT	oldfont;							// �ɵ�������

	base = glGenLists(96);						// ����96����ʾ�б�
	font = CreateFontA(-24,						// ����߶�
		0,										// ������
		0,										// �������ת�Ƕ� Angle Of Escapement
		0,										// ������ߵ���ת�Ƕ�Orientation Angle
		FW_BOLD,								// ���������
		TRUE,									// �Ƿ�ʹ��б��
		FALSE,									// �Ƿ�ʹ���»���
		FALSE,									// �Ƿ�ʹ��ɾ����
		ANSI_CHARSET,							// �����ַ���
		OUT_TT_PRECIS,							// �������
		CLIP_DEFAULT_PRECIS,					// �ü�����
		ANTIALIASED_QUALITY,					// �������
		FF_DONTCARE | DEFAULT_PITCH,			// Family And Pitch
		"Courier New");							// ��������
	oldfont = (HFONT)SelectObject(hDC, font);	// ѡ��������Ҫ������
	wglUseFontBitmaps(hDC, 32, 96, base);		// ����96����ʾ�б����ƴ�ASCII��Ϊ32-128���ַ�
	SelectObject(hDC, oldfont);					// ѡ��ԭ��������
	DeleteObject(font);							// ɾ������
}

//*****************************************************************************

GLvoid ReleaseFont(GLvoid)							// ɾ����ʾ�б�
{
	glDeleteLists(base, 96);					//ɾ��96����ʾ�б�
}

//*****************************************************************************

GLvoid glPrint(const char *fmt, ...)			// �Զ���GL������庯��
{
	char		text[256];						// �������ִ�
	va_list		ap;								// ָ��һ�������б��ָ��
	if (fmt == NULL)							// ����������򷵻�
		return;
	va_start(ap, fmt);							// �����ɱ����
	vsprintf(text, fmt, ap);					// �Ѳ���ֵд���ַ���
	va_end(ap);									// ��������
	glPushAttrib(GL_LIST_BIT);					// ����ʾ�б�����ѹ�����Զ�ջ
	glListBase(base - 32);						// ������ʾ�б�Ļ���ֵ
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);		// ������ʾ�б�����ַ���
	glPopAttrib();						// �������Զ�ջ
}

//*****************************************************************************

FLOAT GetGravityDist(FLOAT time)
{
	return 0.5f * sp_gravity * time * time;
}

//*****************************************************************************

void SetViewByMouse()
{
	mousePosPre = mousePos;
	windowRegion state = INNER;		// �Ƿ�����ܳ��˴���
	tagRECT windowRect;				// ȡ�î�ǰҕ��
	GetCursorPos(&mousePos);
	GetWindowRect(hWnd, &windowRect);
	if (mousePos.x <= windowRect.left ||
		mousePos.x >= windowRect.right ||
		mousePos.y >= windowRect.bottom ||
		mousePos.y <= windowRect.top)
	{
		state = OUTSIDE;	// �ܳ�������
	}
	else if (mousePos.x <= (windowRect.left + 30) && mousePos.x >= windowRect.left)
	{
		state = LEFTMOST;	// ������߅�^��
	}
	else if (mousePos.x >= (windowRect.right - 30) && mousePos.x <= windowRect.right)
	{
		state = RIGHTMOST;	// ������߅�^��
	}
	else
	{
		state = INNER;	// ���ڃȲ�
	}
	if (mousePos.x < mousePosPre.x && state == INNER)	// ����
	{
		mouseHorizon = NEGATIVE;
	}
	else if (mousePos.x > mousePosPre.x && state == INNER) // ����
	{
		mouseHorizon = POSITIVE;
	}
	else if (state == INNER)	// ����
	{
		mouseHorizon = STATIC;
		//SetCursorPos((mp_window_width + mp_window_left_top_x) / 2, (mp_window_height + mp_window_left_top_y) / 2);
		//mousePosPre.x = (mp_window_width + mp_window_left_top_x) / 2;
		//mousePosPre.y = (mp_window_height + mp_window_left_top_y) / 2;
	}

	if (state == LEFTMOST)			// ���Ƽ���
	{
		mouseHorizon = NEGATIVE2X;
	}
	else if (state == RIGHTMOST)	// ���Ƽ���
	{
		mouseHorizon = POSITIVE2X;
	}


	if (mousePos.y > mousePosPre.y && state != OUTSIDE) // ����
	{
		mouseVertical = POSITIVE;
	}
	else if (mousePos.y < mousePosPre.y && state != OUTSIDE) // ����
	{
		mouseVertical = NEGATIVE;
	}
	else	// ����
	{
		mouseVertical = STATIC;
	}

	if (mousePos.x > windowRect.left && mousePos.x < (windowRect.left + 10) ||
		mousePos.x < windowRect.right && mousePos.x >(windowRect.right - 10) ||
		mousePos.y > windowRect.top && mousePos.y < (windowRect.top + 10) ||
		mousePos.y < windowRect.bottom && mousePos.y >(windowRect.bottom - 10))
		SetCursorToCenter();
}

//*****************************************************************************

void ReadData(FILE *f, char *string)
// ����:	����һ���ַ���
{
	do
	{
		fgets(string, ONE_LINE_WORDS, f);				// ����һ��
	} while ((string[0] == '/') || (string[0] == '\n'));// �����Ƿ��б�Ҫ���д���
	return;												// ����
}

//*****************************************************************************

void SetupWorld()
// ������	���Ƴ���
{
	// ���ļ�
	int numTriangles;											// �����е�����������
	char oneLine[ONE_LINE_WORDS];								// �洢���ݵ��ַ���
	float x, y, z, u, v;										// 3D �� ��������
	FILE *filein;
	filein = fopen(f_world_file, "rt");

	// ��ʼ��ȡ
	ReadData(filein, oneLine);									// ����һ������
	sscanf(oneLine, "NUMPOLLIES %d\n", &numTriangles);			// ��������������
	sector1.triangle = new TRIANGLE[numTriangles];				// ΪnumTriangles�������η����ڴ沢�趨ָ��
	sector1.numTriangles = numTriangles;						// ��������1�е�����������

	for (int triLoop = 0; triLoop < numTriangles; triLoop++)	// ���������е�ÿ��������
	{
		// ���������ε�ÿ������
		for (int vertLoop = 0; vertLoop < 3; vertLoop++)		// �������еĶ���
		{
			ReadData(filein, oneLine);							// ����һ������
			// ������ԵĶ�������
			sscanf(oneLine, "%f %f %f %f %f", &x, &y, &z, &u, &v);
			// ���������ݴ�����ԵĶ���
			sector1.triangle[triLoop].vertex[vertLoop].x = x * sp_world_size;	// ���� 1,  �� triLoop ��������, ��  vertLoop ������, ֵ x =x
			sector1.triangle[triLoop].vertex[vertLoop].y = y * sp_world_size;	// ���� 1,  �� triLoop ��������, ��  vertLoop ������, ֵ y =y
			sector1.triangle[triLoop].vertex[vertLoop].z = z * sp_world_size;	// ���� 1,  �� triLoop ��������, ��  vertLoop ������, ֵ  z =z
			sector1.triangle[triLoop].vertex[vertLoop].u = u * sp_world_size;	// ���� 1,  �� triLoop ��������, ��  vertLoop ������, ֵ  u =u
			sector1.triangle[triLoop].vertex[vertLoop].v = v * sp_world_size;	// ���� 1,  �� triLoop ��������, ��  vertLoop ������, ֵ  e=v
		}
	}

	// �ر��ļ�
	fclose(filein);	
	filein = freopen(f_world_file2, "r", stdin);
	
	// ���x
	ReadData(filein, oneLine);									// ����һ������
	sscanf(oneLine, "NUMPOLLIES %d\n", &numTriangles);			// ��������������
	sector2.triangle = new TRIANGLE[numTriangles];				// ΪnumTriangles�������η����ڴ沢�趨ָ��
	sector2.numTriangles = numTriangles;						// ��������2�е�����������
	for (int triLoop = 0; triLoop < numTriangles; triLoop++)	// ���������е�ÿ��������
	{
		// ���������ε�ÿ������
		for (int vertLoop = 0; vertLoop < 3; vertLoop++)		// �������еĶ���
		{
			ReadData(filein, oneLine);							// ����һ������
			// ������ԵĶ�������
			sscanf(oneLine, "%f %f %f %f %f", &x, &y, &z, &u, &v);
			// ���������ݴ�����ԵĶ���
			sector2.triangle[triLoop].vertex[vertLoop].x = x * sp_world_size;	// ���� 1,  �� triLoop ��������, ��  vertLoop ������, ֵ x =x
			sector2.triangle[triLoop].vertex[vertLoop].y = y * sp_world_size;	// ���� 1,  �� triLoop ��������, ��  vertLoop ������, ֵ y =y
			sector2.triangle[triLoop].vertex[vertLoop].z = z * sp_world_size;	// ���� 1,  �� triLoop ��������, ��  vertLoop ������, ֵ  z =z
			sector2.triangle[triLoop].vertex[vertLoop].u = u;	// ���� 1,  �� triLoop ��������, ��  vertLoop ������, ֵ  u =u
			sector2.triangle[triLoop].vertex[vertLoop].v = v;	// ���� 1,  �� triLoop ��������, ��  vertLoop ������, ֵ  e=v
		}
	}

	return;											// ����
}

//*****************************************************************************

AUX_RGBImageRec *LoadBMP(char *Filename)			
//	������	����λͼ�ļ�
//	�����ã�LoadGLTextures()
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

BOOL LoadGLTextures()
//	������	����λͼ��ת��������
//	�����ã�InitGL(GLvoid)
{
	BOOL Status = FALSE;							// ״ָ̬ʾ�Ƿ��܉��d��λ�D�������y��
	AUX_RGBImageRec *TextureImage[2];				// ��������Ĵ洢�ռ�
	memset(TextureImage, 0, sizeof(void *)* 1);		// ��ָ����Ϊ NULL

	// ����λͼ��������޴������λͼû�ҵ����˳�
	if (TextureImage[0] = LoadBMP(f_bmp_name))
	{
		Status = TRUE;								// �� Status ��Ϊ TRUE
		glGenTextures(4, &texture[0]);				// ��������

		// ���� Nearest �˲���ͼ
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

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

		// ���������˲�����
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D,					// ����OpenGL��������һ��2D����
			0,										// ͼ�����ϸ�̶�,ͨ����0
			3,										// ���ݵĳɷ���(�t�G�{���N�ɷ�ռ�׷N)
			TextureImage[0]->sizeX,					// ����Ŀ��
			TextureImage[0]->sizeY,					// ����ĸ߶�
			0,										// �߿��ֵ��һ�����0 
			GL_RGB,									// ����OpenGLͼ�������ɺ졢�̡�����ɫ�������
			GL_UNSIGNED_BYTE,						// ���ͼ����������޷����ֽ�����
			TextureImage[0]->data);					// ����OpenGL�������ݵ���Դ

		// ���� MipMapped ����
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		// 
		gluBuild2DMipmaps(GL_TEXTURE_2D,
			3,
			TextureImage[0]->sizeX,					// λͼ��� 
			TextureImage[0]->sizeY,					// λͼ�߶�
			GL_RGB,
			GL_UNSIGNED_BYTE,
			TextureImage[0]->data);
	}

	// ጷŃȴ�
	if (TextureImage[0])							// �����Ƿ����
	{
		if (TextureImage[0]->data)					// ����ͼ���Ƿ����
			free(TextureImage[0]->data);			// �ͷ�����ͼ��ռ�õ��ڴ�
		free(TextureImage[0]);						// �ͷ�ͼ��ṹ
	}

	// ���� MipMapped ���� �T�ļy��
	if (TextureImage[1] = LoadBMP(f_bmp_name2))
	{
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D,
			3,
			TextureImage[1]->sizeX,					// λͼ��� 
			TextureImage[1]->sizeY,					// λͼ�߶�
			GL_RGB,
			GL_UNSIGNED_BYTE,
			TextureImage[1]->data);
	}
	
	// ጷŃȴ�
	if (TextureImage[1])							// �����Ƿ����
	{
		if (TextureImage[1]->data)					// ����ͼ���Ƿ����
			free(TextureImage[1]->data);			// �ͷ�����ͼ��ռ�õ��ڴ�
		free(TextureImage[1]);						// �ͷ�ͼ��ṹ
	}

	return Status;									// ���� Status
}

//*****************************************************************************

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)
//	����:	����OpenGL͸��ͼ��Ļ���ڴ�С
//	�����ã�CreateGLWindow()�� WndProc����
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

BOOL InitGL(GLvoid)
//	����:	�˴���ʼ��OpenGL������������
//	�����ã�CreateGLWindow()
{
	// �����������Ƿ���������
	if (mp_load_texture)
	{
		if (!LoadGLTextures())				// ������������������
		{
			return FALSE;					// ���δ�����룬����FALSE
		}
	}

	glEnable(GL_TEXTURE_2D);				// ��������ӳ��

	// ������ʼ��
	glShadeModel(GL_SMOOTH);				// ������Ӱƽ��
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);	// �����Ļʱ���õ���ɫ������ɫ,��̎�Ǻ�ɫ
	glClearDepth(1.0f);						// ������Ȼ���
	glEnable(GL_DEPTH_TEST);				// ������Ȳ���
	glDepthFunc(GL_LEQUAL);					// ������Ȳ��Ե�����
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// ����ϵͳ��͸�ӽ�������(���ÿ�)
	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);		// ȫ���ȣ� 50% Alpha ���
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);		// ���û�ɫ����ȡ�ð�͸��Ч��
	//glEnable(GL_BLEND);						// ���û�ɫ

	// �M�A��ʼ��
	// ��ԴЧ��
	if (mp_enable_light)
	{
		glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);		// ���û�����
		glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);		// ���������
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);	// ���ù�Դλ��
		glEnable(GL_LIGHT1);								// ����һ�Ź�Դ(�_���ஔ�Ҳ�S)
	}

	SetupWorld();

	BuildFont();							// ��������

	// ����ģ�� ģ�͵��ļ��о����������� 
	// Ȼ��ģ����ͼ װ��Data/pic����  һ��Ҫ��ǰ���ͼ���ļ�������һ������ĵ�ȥCLoad3DS�ļ������
	if (mp_enable_model)
		gothicLoader->Import3DS(&gothicModel, f_model_file);
	
	return TRUE;							// ��ʼ��OK�ͷ���TRUE
}

//*****************************************************************************

BOOL DrawGLScene(GLvoid)
//	����:	�����￪ʼ�������еĻ���
//	�����ã�WinMain()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// �����Ļ����Ȼ���
	glLoadIdentity();										// ���õ�ǰ��ģ�͹۲����
	// OpenGL��Ļ�����u��(0,0),����ϵ
	//glColor3f(1.0, 1.0, 1.0);								// �ɫ�֏�

	// ���@�e�_ʼ�L�u
	GLfloat x_m, y_m, z_m, u_m, v_m;						// �������ʱ X, Y, Z, U �� V ����ֵ
	GLfloat xtrans = -xpos;									// ������Ϸ����X��ƽ��ʱ�Ĵ�С
	GLfloat ztrans = -zpos;									// ������Ϸ����Z��ƽ��ʱ�Ĵ�С
	GLfloat ytrans = -walkbias - 0.25f;						// ����ͷ�������°ڶ����¶�
	GLfloat sceneroty = 360.0f - yrot;						// λ����Ϸ�߷����360�Ƚ�

	int numTriangles;										// ��������������������

	glRotatef(lookupdown, 1.0f, 0, 0);						// ������ת
	glRotatef(sceneroty, 0, 1.0f, 0);						// ������Ϸ���������Է�����������ת

	glTranslatef(xtrans, ytrans, ztrans);					// ����Ϸ��Ϊ���ĵ�ƽ�Ƴ���
	glBindTexture(GL_TEXTURE_2D, texture[filter]);			// ���� filter ѡ�������

	numTriangles = sector1.numTriangles;					// ȡ��Sector1������������

	// �������������
	for (int loop_m = 0; loop_m < numTriangles; loop_m++)	// �������е�������
	{
		glBegin(GL_TRIANGLES);								// ��ʼ����������
		glNormal3f(0.0f, 0.0f, 1.0f);						// ָ��ǰ��ķ���
		x_m = sector1.triangle[loop_m].vertex[0].x;			// ��һ��� X ����
		y_m = sector1.triangle[loop_m].vertex[0].y;			// ��һ��� Y ����
		z_m = sector1.triangle[loop_m].vertex[0].z;			// ��һ��� Z ����
		u_m = sector1.triangle[loop_m].vertex[0].u;			// ��һ��� U  ��������
		v_m = sector1.triangle[loop_m].vertex[0].v;			// ��һ��� V  ��������
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);	// ������������Ͷ���

		x_m = sector1.triangle[loop_m].vertex[1].x;			// �ڶ���� X ����
		y_m = sector1.triangle[loop_m].vertex[1].y;			// �ڶ���� Y ����
		z_m = sector1.triangle[loop_m].vertex[1].z;			// �ڶ���� Z ����
		u_m = sector1.triangle[loop_m].vertex[1].u;			// �ڶ���� U  ��������
		v_m = sector1.triangle[loop_m].vertex[1].v;			// �ڶ���� V  ��������
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);	// ������������Ͷ���

		x_m = sector1.triangle[loop_m].vertex[2].x;			// ������� X ����
		y_m = sector1.triangle[loop_m].vertex[2].y;			// ������� Y ����
		z_m = sector1.triangle[loop_m].vertex[2].z;			// ������� Z ����
		u_m = sector1.triangle[loop_m].vertex[2].u;			// �ڶ���� U  ��������
		v_m = sector1.triangle[loop_m].vertex[2].v;			// �ڶ���� V  ��������
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);	// ������������Ͷ���
		glEnd();											// �����λ��ƽ���
	}

	numTriangles = sector2.numTriangles;					// ȡ��Sector2������������
	glBindTexture(GL_TEXTURE_2D, texture[3]);				// ���Ă�Ҳ�����T�ļy��

	// �������������
	for (int loop_m = 0; loop_m < numTriangles; loop_m++)	// �������е�������
	{
		glBegin(GL_TRIANGLES);								// ��ʼ����������
		glNormal3f(0.0f, 0.0f, 1.0f);						// ָ��ǰ��ķ���
		x_m = sector2.triangle[loop_m].vertex[0].x;			// ��һ��� X ����
		y_m = sector2.triangle[loop_m].vertex[0].y;			// ��һ��� Y ����
		z_m = sector2.triangle[loop_m].vertex[0].z;			// ��һ��� Z ����
		u_m = sector2.triangle[loop_m].vertex[0].u;			// ��һ��� U  ��������
		v_m = sector2.triangle[loop_m].vertex[0].v;			// ��һ��� V  ��������
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);	// ������������Ͷ���

		x_m = sector2.triangle[loop_m].vertex[1].x;			// �ڶ���� X ����
		y_m = sector2.triangle[loop_m].vertex[1].y;			// �ڶ���� Y ����
		z_m = sector2.triangle[loop_m].vertex[1].z;			// �ڶ���� Z ����
		u_m = sector2.triangle[loop_m].vertex[1].u;			// �ڶ���� U  ��������
		v_m = sector2.triangle[loop_m].vertex[1].v;			// �ڶ���� V  ��������
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);	// ������������Ͷ���

		x_m = sector2.triangle[loop_m].vertex[2].x;			// ������� X ����
		y_m = sector2.triangle[loop_m].vertex[2].y;			// ������� Y ����
		z_m = sector2.triangle[loop_m].vertex[2].z;			// ������� Z ����
		u_m = sector2.triangle[loop_m].vertex[2].u;			// �ڶ���� U  ��������
		v_m = sector2.triangle[loop_m].vertex[2].v;			// �ڶ���� V  ��������
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);	// ������������Ͷ���
		glEnd();											// �����λ��ƽ���
	}

	// ��ģ��
	if (mp_enable_model)
	{
		glPushMatrix();
		changeObject(gothicTrans);
		drawModel(gothicModel, true, false);
		glPopMatrix();
		glFlush();
	}

	// ��ͣ�r�Ŀ���
	glLoadIdentity();										// ���õ�ǰ��ģ�͹۲����
	glTranslatef(0.0f, 0.0f, -1.0f);						// ������Ļһ����λ
	if (ifPause)
	{
		// ��������λ��������ɫ
		glColor3f(0.3, 0.3, 0.3);							// ����ɫ

		// ���ù�դ��λ�ã��������λ��
		glRasterPos2f(-0.55f + 0.05f, 0.25f);
		glPrint("Pause");		// ������ֵ���Ļ
		glRasterPos2f(-0.55f + 0.05f, 0.15f);
		glPrint("Please press [P] to resume.");
	}
	else
		glColor3f(1.0, 1.0, 1.0);

	return TRUE;											// һ��OK, FALSE��Ԓ���򼴌��˳�
}

//*****************************************************************************

GLvoid ReleaseGLWindow(GLvoid)
//	����:	�������ٴ���
//	�����ã�CreateGLWindow()
{
	// ���Ǵ���ȫ��ģʽ��?
	if (mp_fullscreen)
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

	ReleaseFont();								// �]�N����֮���w
}

//*****************************************************************************

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
//	�����ã�WinMain()
{
	GLuint PixelFormat;										// �������ƥ��Ľ��
	WNDCLASS wc;											// ������ṹ
	DWORD dwExStyle;										// ��չ���ڷ��
	DWORD dwStyle;											// ���ڷ��

	RECT WindowRect;										// �Á�惦���ε����ϽǺ����½ǵ�����ֵ
	WindowRect.left = (long)mp_window_left_top_x;			// ��Left   ��Ϊ mp_window_left_top_x
	WindowRect.top = (long)mp_window_left_top_y;			// ��Top    ��Ϊ mp_window_left_top_y
	WindowRect.right = (long)width;							// ��Right  ��ΪҪ��Ŀ��
	WindowRect.bottom = (long)height;						// ��Bottom ��ΪҪ��ĸ߶�

	mp_fullscreen = fullscreenflag;							// ����ȫ��ȫ����־

	hInstance = GetModuleHandle(NULL);						// ȡ�����Ǵ��ڵ�ʵ��
	
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;			// �ƶ�ʱ�ػ�����Ϊ����ȡ��DC
	wc.lpfnWndProc = (WNDPROC)WndProc;						// WndProc������Ϣ
	wc.cbClsExtra = 0;										// �޶��ⴰ������
	wc.cbWndExtra = 0;										// �޶��ⴰ������
	wc.hInstance = hInstance;								// ����ʵ��
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_CS));		// װ��ͼ��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// װ�����ָ��
	wc.hbrBackground = NULL;								// GL����Ҫ����
	wc.lpszMenuName = NULL;									// ����Ҫ�˵�
	wc.lpszClassName = L"OpenGL";							// �������

	// С�D��
	// HICON hSmallIcon = (HICON)LoadImageA(hInstance, MAKEINTRESOURCEA(IDI_ICON_CS), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	//SendMessage(hWnd, WM_SETICON, ICON_SMALL, IDI_ICON_CS);

	if (!RegisterClass(&wc))								// ����ע�ᴰ����
	{
		MessageBox(NULL, L"Fail to register window", L"Register Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// �˳�������FALSE
	}

	// Ҫ����ȫ��ģʽ��?
	if (mp_fullscreen)
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
				mp_fullscreen = FALSE;							// ѡ�񴰿�ģʽ
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
	if (mp_fullscreen)
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
		ReleaseGLWindow();									// ������ʾ��
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
	ReSizeGLScene(width, height);							// ����(͸��) GL ��Ļ

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
	//	�����ã�CreateGLWindow()
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
	if (mp_enable_mode_choose)
	{
		if (MessageBox(NULL, L"Welcome!\n Would you like to run in FullScreen?", L"Welcome", MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			mp_fullscreen = TRUE;					// FALSEΪ����ģʽ
		}
	}

	// ����OpenGL����
	if (!CreateGLWindow(f_window_name, mp_window_width, mp_window_height, 16, mp_fullscreen))	// ���⡢��ȡ��߶ȡ�ɫ����ȣ��Լ�ȫ����־
	{
		return 0;								// ʧ���˳�
	}

	// ���֮��ʼ��
	// �������K����
	mousePosPre.x = (mp_window_width + mp_window_left_top_x) / 2;
	mousePosPre.y = (mp_window_height + mp_window_left_top_y) / 2;

	// ����ָ̨���Ƿ��@ʾ����
	ShowCursor(mp_show_crusor);

	// �¶׵Ŀ���׃��
	GLuint countCwral = 0;

	// ���S�Ŀ���׃��
	BOOL hop = FALSE;
	FLOAT standardHeight = GetGravityDist(sp_jump_duration / 2);	// Ҫ��r�g���������w�������ٸ߶�

	// ���ߵ������O��
	sp_walk_speedCurrent = sp_walk_speed;

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
					//PlayMusic(isToPlay);		// ������

					// ��˿���
					if (!ifPause)
						SetViewByMouse();

					// ���Ƹ�����
					if (mp_enable_light)				// ��������Ƿ�����Դ
					{
						// L�� ����
						if (keys['L'] && !lp && !ifPause)
							// ͬʱ���������������ԭ����Ϊ�˷�ֹL������ס����δ��뱻����ִ�У������´��岻ͣ��˸��
						{
							lp = TRUE;						// lp ��Ϊ TRUE,����L�I�Ѱ��^
							light = !light;					// �л���Դ�� TRUE/FALSE(���_�P)
							if (!light)						// ���û�й�Դ
								glDisable(GL_LIGHTING);		// ���ù�Դ
							else							// ����
								glEnable(GL_LIGHTING);		// ���ù�Դ
						}
						if (!keys['L'])						// L���ɿ���ô?
						{
							lp = FALSE;						// ���ǣ���lp��ΪFALSE
						}
					}

					//*******************************************************************

					// F�� �y��ʽ
					if (keys['F'] && !fp)				// F��������ô?
					{
						fp = TRUE;						// fp ��Ϊ TRUE
						filter += 1;					// filter��ֵ��һ
						if (filter > 2)					// ����2��ô?
						{
							filter = 0;					// ��������Ϊ0
						}
						isToPlay = FALSE;
						//PlayMusic();
					}
					if (!keys['F'])						// F���ſ���ô?
					{
						fp = FALSE;						// ����fp��ΪFALSE
						isToPlay = TRUE;
					}

					//*******************************************************************

					// P�� ͸ҕ(��֮ͣЧ��)����ͣ
					if (keys['P'] && !bp)				// P �I������ô?
					{
						bp = TRUE;						// ���ǣ� bp ��Ϊ TRUE
						blend = !blend;					// �л����ѡ��� TRUE / FALSE
						if (blend)						// ��ϴ���ô?
						{
							glEnable(GL_BLEND);			// �򿪻��
							glDisable(GL_DEPTH_TEST);	// �ر���Ȳ���
							ifPause = TRUE;				// ��ͣ��,��˲�����,��Ҫ�ٰ����Iȡ����ͣ
							ShowCursor(TRUE);
						}
						else							// ����
						{
							glDisable(GL_BLEND);		// �رջ��
							glEnable(GL_DEPTH_TEST);	// ����Ȳ���
							ifPause = FALSE;			// ȡ����ͣ
							ShowCursor(FALSE);
							SetCursorToCenter();		// �û��������
						}
					}
					if (!keys['P'])
					{
						bp = FALSE;						// ���ǣ� bp��Ϊ FALSE
					}

					//*******************************************************************

					// Space�I ���S
					if (keys[VK_SPACE] && hop == FALSE && !hp && !ifPause)// ���������,����hop,׌���Sһ��
					{
						hop = TRUE;							// �ʂ���
						QueryPerformanceFrequency(&frequ);
						QueryPerformanceCounter(&start);	// ӛ��_ʼ�r�g
						walkbiasDefault = walkbias;			// ӛ��_ʼ�߶�λ��
						hp = TRUE;
					}

					if (hop)
					{
						// �õ��F�r�r��
						// dummy��ʽ�ϕr�g
						//for (int i = 0; i<1000000; i++);
						QueryPerformanceCounter(&over);
						DOUBLE timePeriod = (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart;

						// Clivic֮����
						/*walkbias += sp_hop_v0 * timePeriod - 0.4f * sp_gravity * timePeriod * timePeriod;
						if (walkbias > walkbiasDefault)
							walkbias += sp_hop_v0 * timePeriod - 0.4f * sp_gravity * timePeriod * timePeriod;
						else
						{
							hop = FALSE;
							walkbias = walkbiasDefault;
						}*/							
						
						// ���b��cdm֮�㷨
						if (timePeriod < sp_jump_duration)
						{
							if (timePeriod < sp_jump_duration / 2)
							{
								walkbias = walkbiasDefault + sp_max_height - sp_max_height * GetGravityDist(sp_jump_duration / 2 - timePeriod) / standardHeight;
							}
							else
							{
								walkbias = walkbiasDefault + sp_max_height - sp_max_height * GetGravityDist(timePeriod - sp_jump_duration / 2) / standardHeight;
							}
						}
						else
						{
							hop = FALSE;
							walkbias = walkbiasDefault;
						}
					}

					if (!keys[VK_SPACE] && hp)
					{
						hp = FALSE;
					}

					//*******************************************************************

					// Shift�I ׃��
					if (keys[VK_SHIFT] && !sp)
					{
						sp_walk_speedCurrent = sp_shift_speed * sp_walk_speed;
						sp = TRUE;						// ���Ѱ���shift�� sp ��Ϊ TRUE
					}

					if (!keys[VK_SHIFT] && sp)
					{
						sp_walk_speedCurrent  = sp_walk_speed;
						sp = FALSE;						// ���ѷ��_shift, sp�O��FALSE
					}

					//*******************************************************************

					// Ctrl�� �¶�
					if (keys[VK_CONTROL] && !cp && !ifPause)		// Ctrl �I������ô?
					{
						if (countCwral < sp_crawl_smooth)
						{
							walkbias -= sp_cwral_degree;
							countCwral++;
						}
						else
						{
							walkbias += sp_cwral_degree;
							cp = TRUE;					// ��ƽ���¶��ꮅ�� cp ��Ϊ TRUE
						}			
					}
					if (!keys[VK_CONTROL] && cp)
					{
						if (countCwral > 0)
						{
							walkbias += sp_cwral_degree;
							countCwral--;
						}
						else
						{
							walkbias -= sp_cwral_degree;
							cp = FALSE;					// ��ƽ���¶׻؏��ꮅ�� cp��Ϊ FALSE
						}
					}

					//*******************************************************************

					// �����I
					if (keys[VK_PRIOR])
					{
						tankZPos += 0.01;
					}

					if (keys[VK_NEXT])
					{
						tankZPos -= 0.01;
					}

					//*******************************************************************

					// ���I ���D
					if (keys[VK_RIGHT] && !ifPause)
					{
						heading -= 0.15f;
						yrot = heading;					// ������ת����
					}

					//*******************************************************************

					// ��� ���D
					if (mouseHorizon == FALSE)
					{
						heading -= sp_mouse_factor;
						yrot = heading;					// ��˿���������ת����
					}

					//*******************************************************************

					// ��� ���D����
					if (mouseHorizon == POSITIVE2X)
					{
						heading -= sp_mouse_factor / sp_mouse_factor_rotate;	// ��˿��Ƽ���������ת����
						yrot = heading;
					}

					//*******************************************************************

					// ���I ���D
					if (keys[VK_LEFT] && !ifPause)
					{
						heading += 0.15f;
						yrot = heading;					// ���Ҳ���ת����
					}

					//*******************************************************************

					// ��� ���D
					if (mouseHorizon == TRUE)
					{
						heading += sp_mouse_factor;
						yrot = heading;					// ��˿���������ת����
					}

					//*******************************************************************

					// ��� ���D����
					if (mouseHorizon == NEGATIVE2X)
					{
						heading += sp_mouse_factor / sp_mouse_factor_rotate;	// ��˿��Ƽ���������ת����
						yrot = heading;
					}

					//*******************************************************************

					// W�I ǰ�M
					if (keys['W'] && !ifPause)
					{
						GLfloat xposDelta = sin(heading*PI_OVER_180) * sp_walk_speedCurrent;
						GLfloat zposDelta = cos(heading*PI_OVER_180) * sp_walk_speedCurrent;

						// ���Ʋ��ܴ���
						if (DetectBump(xposDelta, zposDelta, 'W'))
						{
							xpos -=	xposDelta;			// ����Ϸ�����ڵ�Xƽ���ƶ�
							zpos -= zposDelta;			// ����Ϸ�����ڵ�Zƽ���ƶ�
						}

						if (walkbiasangle >= 359.0f)					// ���walkbiasangle����359��
						{
							walkbiasangle = 0.0f;					// �� walkbiasangle ��Ϊ0
						}
						else										// ����
						{
							walkbiasangle += 0.5f;					// ��� walkbiasangle < 359 �������� 0.5(����ԽС��ƵԽС)
						}
						if (hop)
							walkbias = walkbias - walkbiasDefault + (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;	// ʹ��Ϸ�߲�����Ծ��(����Խ��Խƽ��)
						else
							walkbias = (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;	// ʹ��Ϸ�߲�����Ծ��(����Խ��Խƽ��)

						// ����
						//isToPlay = TRUE;
						//PlayMusic();
						//PlaySoundA("F:\\Visual C++ programs\\OpenGLM2\\footstep_1.wav", NULL, SND_ASYNC);
					}

					//*******************************************************************

					// S�I ����
					if (keys['S'] && !ifPause)
					{
						GLfloat xposDelta = sin(heading*PI_OVER_180) * sp_walk_speedCurrent;
						GLfloat zposDelta = cos(heading*PI_OVER_180) * sp_walk_speedCurrent;

						// ���Ʋ��ܴ���
						if (DetectBump(xposDelta, zposDelta, 'S'))
						{
							xpos += xposDelta;			// ����Ϸ�����ڵ�Xƽ���ƶ�
							zpos += zposDelta;			// ����Ϸ�����ڵ�Zƽ���ƶ�
						}
						if (walkbiasangle <= 1.0f)					// ���walkbiasangleС��1��
						{
							walkbiasangle = 359.0f;					// ʹ walkbiasangle ���� 359
						}
						else										// ����
						{
							walkbiasangle -= 0.5f;					// ��� walkbiasangle > 1 ��ȥ 0.5
						}
						if (hop)
							walkbias = walkbias - walkbiasDefault + (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;		// ʹ��Ϸ�߲�����Ծ��(����Խ��Խƽ��)
						else
							walkbias = (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;		// ʹ��Ϸ�߲�����Ծ��(����Խ��Խƽ��)
					}

					//*******************************************************************

					// A�I ��ƽ��
					if (keys['A'] && !ifPause)
					{
						GLfloat xposDelta = cos(heading*PI_OVER_180) * sp_walk_speedCurrent;
						GLfloat zposDelta = sin(heading*PI_OVER_180) * sp_walk_speedCurrent;
						if (DetectBump(xposDelta, zposDelta, 'A'))
						{
							xpos -= xposDelta;			// ����Ϸ�����ڵ�Xƽ���ƶ�
							zpos += zposDelta;			// ����Ϸ�����ڵ�Zƽ���ƶ�
						}
						if (walkbiasangle >= 359.0f)					// ���walkbiasangle����359��
						{
							walkbiasangle = 0.0f;					// �� walkbiasangle ��Ϊ0
						}
						else								// ����
						{
							walkbiasangle += 0.5f;					// ��� walkbiasangle < 359 �������� 0.5(����ԽС��ƵԽС)
						}
						if (hop)
							walkbias = walkbias - walkbiasDefault + (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;
						else
							walkbias = (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;		// ʹ��Ϸ�߲�����Ծ��(����Խ��Խƽ��)
					}

					//*******************************************************************

					// D�I ��ƽ��
					if (keys['D'] && !ifPause)
					{
						GLfloat xposDelta = cos(heading*PI_OVER_180) * sp_walk_speedCurrent;
						GLfloat zposDelta = sin(heading*PI_OVER_180) * sp_walk_speedCurrent;
						if (DetectBump(xposDelta, zposDelta, 'D'))
						{
							xpos += xposDelta;			// ����Ϸ�����ڵ�Xƽ���ƶ�
							zpos -= zposDelta;			// ����Ϸ�����ڵ�Zƽ���ƶ�
						}
						if (walkbiasangle >= 359.0f)					// ���walkbiasangle����359��
						{
							walkbiasangle = 0.0f;					// �� walkbiasangle ��Ϊ0
						}
						else								// ����
						{
							walkbiasangle += 0.5f;					// ��� walkbiasangle < 359 �������� 0.5(����ԽС��ƵԽС)
						}
						if (hop)
							walkbias = walkbias - walkbiasDefault + (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;
						else
							walkbias = (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;		// ʹ��Ϸ�߲�����Ծ��(����Խ��Խƽ��)
					}

					//*******************************************************************

					// ���I ���Ͽ�
					if (keys[VK_UP] && lookupdown >= -sp_max_head_angle && !ifPause)
					{
						lookupdown -= 0.1f;
					}

					//*******************************************************************

					// ��� ���Ͽ�
					if (mouseVertical == TRUE && lookupdown >= -sp_max_head_angle)
					{
						lookupdown -= sp_mouse_factor;
					}

					//*******************************************************************

					// ���I ���¿�
					if (keys[VK_DOWN] && lookupdown <= sp_max_head_angle && !ifPause)
					{
						lookupdown += 0.1f;
					}

					//*******************************************************************

					// ��� ���¿�
					if (mouseVertical == FALSE && lookupdown <= sp_max_head_angle)
					{
						lookupdown += sp_mouse_factor;
					}

					//*******************************************************************

					// ģ��
					if (keys['M'] && !mp)
					{
						mp_enable_model = !mp_enable_model;
					}

					if (!keys['M'] && mp)
					{
						mp_enable_model = !mp_enable_model;
					}
				}
			}

			// �����û�����F1����ȫ��ģʽ�ʹ���ģʽ���л�
			if (keys[VK_F1])					// F1��������ô?
			{
				keys[VK_F1] = FALSE;			// ���ǣ�ʹ��Ӧ��Key�����е�ֵΪ FALSE
				ReleaseGLWindow();				// ���ٵ�ǰ�Ĵ���
				mp_fullscreen = !mp_fullscreen;	// �л�ȫ��/����ģʽ
				
				// �ؽ� OpenGL ����
				if (!CreateGLWindow(f_window_name, mp_window_width, mp_window_height, 16, mp_fullscreen))
					return 0;					// �������δ�ܴ����������˳�				
			}
		}
	}
	// done ׃����TRUE, �رճ���
	ReleaseGLWindow();							// ���ٴ���
	return (msg.wParam);						// �˳�����
}

