//*****************************************************************************
//	這是一個進階OpenGL函數練習,根據NeHe的OpenGL教程而來。
//	此練習OpenGL2完成的是Lesson10。
//	功能：
//	创造3D场景。
//*****************************************************************************
#include "OpenGLM2\utiltyGL.h"
#include "OpenGLM2\resource.h"
#include "CLoad3DS.h"


//*****************************************************************************
// 控制面板，程序员在此添加控制变量之讯息（写在utilityGL.h中）
//*****************************************************************************
BOOL	mp_load_texture = TRUE;						// 是否载入纹理
BOOL	mp_enable_mode_choose = FALSE;				// 是否让用户选择是否全熒幕
BOOL	mp_fullscreen = FALSE;						// 是否一开始就全熒幕
BOOL	mp_show_crusor = FALSE;						// 是否一開始顯示滑鼠
BOOL	mp_enable_light = FALSE;					// 是否启用光源
BOOL	mp_enable_model = TRUE;					// 是否啟用模型導入
char*	f_world_file = "F:\\Visual C++ programs\\OpenGLM2\\World.txt";// 打开的文件(点阵信息等)
char*	f_world_file2 = "F:\\Visual C++ programs\\OpenGLM2\\Door.txt";
char*	f_bmp_name = "F:\\Visual C++ programs\\OpenGLM2\\Crate.bmp";// 载入的纹理位图
char*	f_bmp_name2 = "F:\\Visual C++ programs\\OpenGLM2\\Door.bmp";
char*	f_model_file = "F:\\Visual C++ programs\\OpenGLM2\\Data\\3DS\\ABRAMS_L.3DS";		// 模型文件
char*	f_window_name = "cstrike";					// 窗口名称
// 原來窗口名稱: OpenGLM2 -- Scene
FLOAT	sp_mouse_factor = 2.0f;						// 鼠標靈敏度
LONG	mp_window_width = 640;						// 窗口長(橫向)
LONG	mp_window_height = 480;						// 窗口高(縱向)
LONG	mp_window_left_top_x = 100;					// 窗口初始化時左上角橫坐標
LONG	mp_window_left_top_y = 50;					// 窗口初始化時左上角縱坐標
FLOAT	sp_world_size = 4.0f;						// 放縮讀入的世界多少倍, >1放大,<1縮小
FLOAT	sp_max_head_angle = 50.0f;					// 仰角俯角的最大值(頭可以擡多高)
FLOAT	sp_cwral_degree = 0.002f;					// 下蹲程度,數字越大下蹲地越下面
GLuint	sp_crawl_smooth = 60;						// 下蹲平滑程度,數字越大越平滑(但也會加深下蹲程度)
GLfloat	sp_hop_v0 = 0.3f;							// 跳躍的初始速率
GLfloat sp_walk_speed = 0.002f;						// 走路速率
GLfloat	sp_shift_speed = 5.0f;						// 變速因子,>1是加速--快跑,<1是減速--緩慢腳步
GLfloat sp_gravity = 5.0f;							// 重力
FLOAT	sp_max_height = 0.6f;						// 跳躍最大高度
FLOAT	sp_jump_duration = 0.5f;					// 跳躍時間
GLuint	sp_mouse_factor_rotate = 25;				// 鼠標左右旋轉加速因子,數字越大加速越慢
//*****************************************************************************

// 常量
const GLfloat PI_OVER_180 = 0.0174532925f;
const GLuint ONE_LINE_WORDS = 255;

//	顶点、三角形、区段之数据结构
struct VERTEX										// 创建Vertex顶点结构
{
	GLfloat x, y, z;								// 3D 坐标
	GLfloat u, v;									// 纹理坐标
};													// 命名为VERTEX

struct TRIANGLE										// 创建Triangle三角形结构
{
	VERTEX vertex[3];								// VERTEX矢量数组，大小为3
};													// 命名为 TRIANGLE

struct SECTOR										// 创建Sector区段结构
{
	GLuint numTriangles;							// Sector中的三角形个数
	TRIANGLE* triangle;								// 指向三角数组的指针
};													// 命名为SECTOR

// 控制紋理過濾類型
GLuint	filter = 2;									// 滤波类型
GLuint	texture[4];									// 3种纹理的储存空间 + 門的紋理
BOOL	fp;											// F键按下了么?

// 控制光源
BOOL	light;										// 光源的开/关
BOOL	lp;											// L键按下了么?
GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };// 环境光参数
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };// 漫射光参数
GLfloat LightPosition[] = { 0.0f, 0.0f, 2.0f, 1.0f };// 光源位置

// 控制透明
bool    blend = FALSE;								// 是否混合?
bool	bp;											// B 键按下了么?

// 玩家行走的变量控制
GLfloat heading;
GLfloat xpos;
GLfloat zpos;
GLfloat	yrot;										// 沿y轴之旋转
GLfloat walkbias = 0;								// 玩家行走时头部产生上下摆动的幅度
GLfloat walkbiasangle = 0;
GLfloat lookupdown = 0.0f;
GLfloat	z = 0.0f;									// 深入屏幕的距离
BOOL cp;											// 是否下蹲
BOOL sp;											// 是否變速
BOOL hp;											// 是否跳躍
BOOL mp;											// 是否導入模型
GLfloat walkbiasDefault;							// 跳躍時起始之位置
GLfloat sp_walk_speedCurrent;							// 即時行走速率

// 鼠標控制
POINT mousePosPre;
POINT mousePos;
enum mouseDirect {POSITIVE, NEGATIVE, STATIC, POSITIVE2X, NEGATIVE2X};		// 鼠標朝正軸、負軸、不移動、右框轉動加速、左框轉動加速
enum windowRegion {INNER, OUTSIDE, LEFTMOST, RIGHTMOST};					// 鼠標在窗口之位置,內部,外部,左端部分,右端部分
mouseDirect mouseHorizon = STATIC;				// POSITIVE是右移,NEGATIVE是左移,STATIC是不移
mouseDirect mouseVertical = STATIC;				// POSITIVE是上移,NEGATIVE是下移,STATIC是不移
//BOOL ifShowCrusor;									// 是否顯示滑鼠,用於暫停控制

// 场景搭建
SECTOR sector1;										// 创造一个区段, 读墻
SECTOR sector2;										// 创造一个区段, 读門

// 是否暫停
BOOL ifPause = FALSE;

// 顯示文字
GLuint	base;			// 绘制字体的显示列表的开始位置
GLfloat	cnt1;			// 字体移动计数器1
GLfloat	cnt2;			// 字体移动计数器2

// 3DS模型導入
CLoad3DS *gothicLoader = new(CLoad3DS);
t3DModel gothicModel;
DWORD tankZPos = 0;
float gothicTrans[10] = 
{
	0, 0.3, -9,			//表示在世界矩阵的位置
	0.0004, 0.0004, 0.0004,      //表示xyz放大倍数
	0, 0, 0, 0			//表示旋转
};

// 聲音
BOOL isPlaying = FALSE;
BOOL isToPlay = FALSE;

//*****************************************************************************

GLvoid PlayMusic()
{
	if (isToPlay == TRUE)
	{
		// 播放声音
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
//	描述:	根據不同char類型大寫字母參數(W,A,S,D)判斷如果在行走範圍內,返回TRUE, 
//			否則返回FALSE.
//	被調用:	WinMain()
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
	tagRECT windowRect;			// 取得當前視窗
	GetWindowRect(hWnd, &windowRect);
	SetCursorPos((windowRect.left + windowRect.right) / 2, (windowRect.bottom + windowRect.top) / 2);
	mouseHorizon = STATIC;
	mouseVertical = STATIC;
}

//*****************************************************************************

GLvoid BuildFont(GLvoid)						// 创建位图字体
{
	HFONT	font;								// 字体句柄
	HFONT	oldfont;							// 旧的字体句柄

	base = glGenLists(96);						// 创建96个显示列表
	font = CreateFontA(-24,						// 字体高度
		0,										// 字体宽度
		0,										// 字体的旋转角度 Angle Of Escapement
		0,										// 字体底线的旋转角度Orientation Angle
		FW_BOLD,								// 字体的重量
		TRUE,									// 是否使用斜体
		FALSE,									// 是否使用下划线
		FALSE,									// 是否使用删除线
		ANSI_CHARSET,							// 设置字符集
		OUT_TT_PRECIS,							// 输出精度
		CLIP_DEFAULT_PRECIS,					// 裁剪精度
		ANTIALIASED_QUALITY,					// 输出质量
		FF_DONTCARE | DEFAULT_PITCH,			// Family And Pitch
		"Courier New");							// 字体名称
	oldfont = (HFONT)SelectObject(hDC, font);	// 选择我们需要的字体
	wglUseFontBitmaps(hDC, 32, 96, base);		// 创建96个显示列表，绘制从ASCII码为32-128的字符
	SelectObject(hDC, oldfont);					// 选择原来的字体
	DeleteObject(font);							// 删除字体
}

//*****************************************************************************

GLvoid ReleaseFont(GLvoid)							// 删除显示列表
{
	glDeleteLists(base, 96);					//删除96个显示列表
}

//*****************************************************************************

GLvoid glPrint(const char *fmt, ...)			// 自定义GL输出字体函数
{
	char		text[256];						// 保存文字串
	va_list		ap;								// 指向一个变量列表的指针
	if (fmt == NULL)							// 如果无输入则返回
		return;
	va_start(ap, fmt);							// 分析可变参数
	vsprintf(text, fmt, ap);					// 把参数值写入字符串
	va_end(ap);									// 结束分析
	glPushAttrib(GL_LIST_BIT);					// 把显示列表属性压入属性堆栈
	glListBase(base - 32);						// 设置显示列表的基础值
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);		// 调用显示列表绘制字符串
	glPopAttrib();						// 弹出属性堆栈
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
	windowRegion state = INNER;		// 是否鼠標跑出了窗口
	tagRECT windowRect;				// 取得當前視窗
	GetCursorPos(&mousePos);
	GetWindowRect(hWnd, &windowRect);
	if (mousePos.x <= windowRect.left ||
		mousePos.x >= windowRect.right ||
		mousePos.y >= windowRect.bottom ||
		mousePos.y <= windowRect.top)
	{
		state = OUTSIDE;	// 跑出窗口了
	}
	else if (mousePos.x <= (windowRect.left + 30) && mousePos.x >= windowRect.left)
	{
		state = LEFTMOST;	// 窗口左邊區域
	}
	else if (mousePos.x >= (windowRect.right - 30) && mousePos.x <= windowRect.right)
	{
		state = RIGHTMOST;	// 窗口右邊區域
	}
	else
	{
		state = INNER;	// 窗口內部
	}
	if (mousePos.x < mousePosPre.x && state == INNER)	// 左移
	{
		mouseHorizon = NEGATIVE;
	}
	else if (mousePos.x > mousePosPre.x && state == INNER) // 右移
	{
		mouseHorizon = POSITIVE;
	}
	else if (state == INNER)	// 不移
	{
		mouseHorizon = STATIC;
		//SetCursorPos((mp_window_width + mp_window_left_top_x) / 2, (mp_window_height + mp_window_left_top_y) / 2);
		//mousePosPre.x = (mp_window_width + mp_window_left_top_x) / 2;
		//mousePosPre.y = (mp_window_height + mp_window_left_top_y) / 2;
	}

	if (state == LEFTMOST)			// 左移加速
	{
		mouseHorizon = NEGATIVE2X;
	}
	else if (state == RIGHTMOST)	// 右移加速
	{
		mouseHorizon = POSITIVE2X;
	}


	if (mousePos.y > mousePosPre.y && state != OUTSIDE) // 上移
	{
		mouseVertical = POSITIVE;
	}
	else if (mousePos.y < mousePosPre.y && state != OUTSIDE) // 下移
	{
		mouseVertical = NEGATIVE;
	}
	else	// 不移
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
// 描述:	读入一个字符串
{
	do
	{
		fgets(string, ONE_LINE_WORDS, f);				// 读入一行
	} while ((string[0] == '/') || (string[0] == '\n'));// 考察是否有必要进行处理
	return;												// 返回
}

//*****************************************************************************

void SetupWorld()
// 描述：	建制场景
{
	// 打开文件
	int numTriangles;											// 区段中的三角形数量
	char oneLine[ONE_LINE_WORDS];								// 存储数据的字符串
	float x, y, z, u, v;										// 3D 和 纹理坐标
	FILE *filein;
	filein = fopen(f_world_file, "rt");

	// 开始读取
	ReadData(filein, oneLine);									// 读入一行数据
	sscanf(oneLine, "NUMPOLLIES %d\n", &numTriangles);			// 读入三角形数量
	sector1.triangle = new TRIANGLE[numTriangles];				// 为numTriangles个三角形分配内存并设定指针
	sector1.numTriangles = numTriangles;						// 定义区段1中的三角形数量

	for (int triLoop = 0; triLoop < numTriangles; triLoop++)	// 遍历区段中的每个三角形
	{
		// 遍历三角形的每个顶点
		for (int vertLoop = 0; vertLoop < 3; vertLoop++)		// 遍历所有的顶点
		{
			ReadData(filein, oneLine);							// 读入一行数据
			// 读入各自的顶点数据
			sscanf(oneLine, "%f %f %f %f %f", &x, &y, &z, &u, &v);
			// 将顶点数据存入各自的顶点
			sector1.triangle[triLoop].vertex[vertLoop].x = x * sp_world_size;	// 区段 1,  第 triLoop 个三角形, 第  vertLoop 个顶点, 值 x =x
			sector1.triangle[triLoop].vertex[vertLoop].y = y * sp_world_size;	// 区段 1,  第 triLoop 个三角形, 第  vertLoop 个顶点, 值 y =y
			sector1.triangle[triLoop].vertex[vertLoop].z = z * sp_world_size;	// 区段 1,  第 triLoop 个三角形, 第  vertLoop 个顶点, 值  z =z
			sector1.triangle[triLoop].vertex[vertLoop].u = u * sp_world_size;	// 区段 1,  第 triLoop 个三角形, 第  vertLoop 个顶点, 值  u =u
			sector1.triangle[triLoop].vertex[vertLoop].v = v * sp_world_size;	// 区段 1,  第 triLoop 个三角形, 第  vertLoop 个顶点, 值  e=v
		}
	}

	// 关闭文件
	fclose(filein);	
	filein = freopen(f_world_file2, "r", stdin);
	
	// 再讀
	ReadData(filein, oneLine);									// 读入一行数据
	sscanf(oneLine, "NUMPOLLIES %d\n", &numTriangles);			// 读入三角形数量
	sector2.triangle = new TRIANGLE[numTriangles];				// 为numTriangles个三角形分配内存并设定指针
	sector2.numTriangles = numTriangles;						// 定义区段2中的三角形数量
	for (int triLoop = 0; triLoop < numTriangles; triLoop++)	// 遍历区段中的每个三角形
	{
		// 遍历三角形的每个顶点
		for (int vertLoop = 0; vertLoop < 3; vertLoop++)		// 遍历所有的顶点
		{
			ReadData(filein, oneLine);							// 读入一行数据
			// 读入各自的顶点数据
			sscanf(oneLine, "%f %f %f %f %f", &x, &y, &z, &u, &v);
			// 将顶点数据存入各自的顶点
			sector2.triangle[triLoop].vertex[vertLoop].x = x * sp_world_size;	// 区段 1,  第 triLoop 个三角形, 第  vertLoop 个顶点, 值 x =x
			sector2.triangle[triLoop].vertex[vertLoop].y = y * sp_world_size;	// 区段 1,  第 triLoop 个三角形, 第  vertLoop 个顶点, 值 y =y
			sector2.triangle[triLoop].vertex[vertLoop].z = z * sp_world_size;	// 区段 1,  第 triLoop 个三角形, 第  vertLoop 个顶点, 值  z =z
			sector2.triangle[triLoop].vertex[vertLoop].u = u;	// 区段 1,  第 triLoop 个三角形, 第  vertLoop 个顶点, 值  u =u
			sector2.triangle[triLoop].vertex[vertLoop].v = v;	// 区段 1,  第 triLoop 个三角形, 第  vertLoop 个顶点, 值  e=v
		}
	}

	return;											// 返回
}

//*****************************************************************************

AUX_RGBImageRec *LoadBMP(char *Filename)			
//	描述：	载入位图文件
//	被调用：LoadGLTextures()
{
	FILE *File = NULL;								// 文件句柄

	if (!Filename)									// 确认已给出文件名
	{
		return NULL;								// 若无返回 NULL
	}

	File = fopen(Filename, "r");					// 检查文件是否存在

	if (File)										// 文件存在么?
	{
		fclose(File);								// 关闭文件句柄
		return auxDIBImageLoadA((LPCSTR)Filename);	// 载入位图并返回指针
	}
	return NULL;									// 如果载入失败返回 NULL
}

//*****************************************************************************

BOOL LoadGLTextures()
//	描述：	载入位图并转换成纹理
//	被调用：InitGL(GLvoid)
{
	BOOL Status = FALSE;							// 状态指示是否能夠載入位圖及創建紋理
	AUX_RGBImageRec *TextureImage[2];				// 创建纹理的存储空间
	memset(TextureImage, 0, sizeof(void *)* 1);		// 将指针设为 NULL

	// 载入位图，检查有无错误，如果位图没找到则退出
	if (TextureImage[0] = LoadBMP(f_bmp_name))
	{
		Status = TRUE;								// 将 Status 设为 TRUE
		glGenTextures(4, &texture[0]);				// 创建纹理

		// 创建 Nearest 滤波贴图
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		// 生成紋理
		glTexImage2D(GL_TEXTURE_2D,					// 告诉OpenGL此纹理是一个2D纹理
			0,										// 图像的详细程度,通常為0
			3,										// 数据的成分数(紅綠藍三種成分占幾種)
			TextureImage[0]->sizeX,					// 纹理的宽度
			TextureImage[0]->sizeY,					// 纹理的高度
			0,										// 边框的值，一般就是0 
			GL_RGB,									// 告诉OpenGL图像数据由红、绿、蓝三色数据组成
			GL_UNSIGNED_BYTE,						// 组成图像的数据是无符号字节类型
			TextureImage[0]->data);					// 告诉OpenGL纹理数据的来源

		// 创建线性滤波纹理
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D,					// 告诉OpenGL此纹理是一个2D纹理
			0,										// 图像的详细程度,通常為0
			3,										// 数据的成分数(紅綠藍三種成分占幾種)
			TextureImage[0]->sizeX,					// 纹理的宽度
			TextureImage[0]->sizeY,					// 纹理的高度
			0,										// 边框的值，一般就是0 
			GL_RGB,									// 告诉OpenGL图像数据由红、绿、蓝三色数据组成
			GL_UNSIGNED_BYTE,						// 组成图像的数据是无符号字节类型
			TextureImage[0]->data);					// 告诉OpenGL纹理数据的来源

		// 创建 MipMapped 纹理
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		// 
		gluBuild2DMipmaps(GL_TEXTURE_2D,
			3,
			TextureImage[0]->sizeX,					// 位图宽度 
			TextureImage[0]->sizeY,					// 位图高度
			GL_RGB,
			GL_UNSIGNED_BYTE,
			TextureImage[0]->data);
	}

	// 釋放內存
	if (TextureImage[0])							// 纹理是否存在
	{
		if (TextureImage[0]->data)					// 纹理图像是否存在
			free(TextureImage[0]->data);			// 释放纹理图像占用的内存
		free(TextureImage[0]);						// 释放图像结构
	}

	// 創建 MipMapped 纹理 門的紋理
	if (TextureImage[1] = LoadBMP(f_bmp_name2))
	{
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D,
			3,
			TextureImage[1]->sizeX,					// 位图宽度 
			TextureImage[1]->sizeY,					// 位图高度
			GL_RGB,
			GL_UNSIGNED_BYTE,
			TextureImage[1]->data);
	}
	
	// 釋放內存
	if (TextureImage[1])							// 纹理是否存在
	{
		if (TextureImage[1]->data)					// 纹理图像是否存在
			free(TextureImage[1]->data);			// 释放纹理图像占用的内存
		free(TextureImage[1]);						// 释放图像结构
	}

	return Status;									// 返回 Status
}

//*****************************************************************************

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)
//	描述:	重置OpenGL透视图屏幕窗口大小
//	被调用：CreateGLWindow()， WndProc（）
{
	// 重置OpenGL窗口大小
	if (height == 0)								// 防止被零除
	{
		height = 1;									// 将Height设为1
	}

	glViewport(0, 0, width, height);				// 重置当前的视口

	// 为透视图设置屏幕
	glMatrixMode(GL_PROJECTION);					// 选择投影矩阵(PROJECTION即投影)
	glLoadIdentity();								// 重置之(投影矩阵)

	// 设置视口的大小
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f); //所以height不能==0

	glMatrixMode(GL_MODELVIEW);						// 选择模型观察矩阵(MODEVIEW即模型觀察)
	glLoadIdentity();								// 重置之(模型观察矩阵)
}

//*****************************************************************************

BOOL InitGL(GLvoid)
//	描述:	此处开始对OpenGL进行所有设置
//	被调用：CreateGLWindow()
{
	// 控制面板控制是否载入纹理
	if (mp_load_texture)
	{
		if (!LoadGLTextures())				// 调用纹理载入子例程
		{
			return FALSE;					// 如果未能载入，返回FALSE
		}
	}

	glEnable(GL_TEXTURE_2D);				// 启用纹理映射

	// 基本初始化
	glShadeModel(GL_SMOOTH);				// 启用阴影平滑
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);	// 清除屏幕时所用的颜色即背景色,此處是黑色
	glClearDepth(1.0f);						// 设置深度缓存
	glEnable(GL_DEPTH_TEST);				// 启用深度测试
	glDepthFunc(GL_LEQUAL);					// 所作深度测试的类型
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// 告诉系统对透视进行修正(更好看)
	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);		// 全亮度， 50% Alpha 混合
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);		// 设置混色函数取得半透明效果
	//glEnable(GL_BLEND);						// 启用混色

	// 進階初始化
	// 光源效果
	if (mp_enable_light)
	{
		glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);		// 设置环境光
		glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);		// 设置漫射光
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);	// 设置光源位置
		glEnable(GL_LIGHT1);								// 启用一号光源(開燈相當於也許)
	}

	SetupWorld();

	BuildFont();							// 创建字体

	// 导入模型 模型的文件夹尽量这样设置 
	// 然后模型贴图 装在Data/pic里面  一定要跟前面截图的文件夹名字一样，想改得去CLoad3DS文件里面改
	if (mp_enable_model)
		gothicLoader->Import3DS(&gothicModel, f_model_file);
	
	return TRUE;							// 初始化OK就返回TRUE
}

//*****************************************************************************

BOOL DrawGLScene(GLvoid)
//	描述:	从这里开始进行所有的绘制
//	被调用：WinMain()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// 清除屏幕和深度缓存
	glLoadIdentity();										// 重置当前的模型观察矩阵
	// OpenGL屏幕中心纔是(0,0),右手系
	//glColor3f(1.0, 1.0, 1.0);								// 顏色恢復

	// 從這裡開始繪製
	GLfloat x_m, y_m, z_m, u_m, v_m;						// 顶点的临时 X, Y, Z, U 和 V 的数值
	GLfloat xtrans = -xpos;									// 用于游戏者沿X轴平移时的大小
	GLfloat ztrans = -zpos;									// 用于游戏者沿Z轴平移时的大小
	GLfloat ytrans = -walkbias - 0.25f;						// 用于头部的上下摆动及下蹲
	GLfloat sceneroty = 360.0f - yrot;						// 位于游戏者方向的360度角

	int numTriangles;										// 保有三角形数量的整数

	glRotatef(lookupdown, 1.0f, 0, 0);						// 上下旋转
	glRotatef(sceneroty, 0, 1.0f, 0);						// 根据游戏者正面所对方向所作的旋转

	glTranslatef(xtrans, ytrans, ztrans);					// 以游戏者为中心的平移场景
	glBindTexture(GL_TEXTURE_2D, texture[filter]);			// 根据 filter 选择的纹理

	numTriangles = sector1.numTriangles;					// 取得Sector1的三角形数量

	// 逐个处理三角形
	for (int loop_m = 0; loop_m < numTriangles; loop_m++)	// 遍历所有的三角形
	{
		glBegin(GL_TRIANGLES);								// 开始绘制三角形
		glNormal3f(0.0f, 0.0f, 1.0f);						// 指向前面的法线
		x_m = sector1.triangle[loop_m].vertex[0].x;			// 第一点的 X 分量
		y_m = sector1.triangle[loop_m].vertex[0].y;			// 第一点的 Y 分量
		z_m = sector1.triangle[loop_m].vertex[0].z;			// 第一点的 Z 分量
		u_m = sector1.triangle[loop_m].vertex[0].u;			// 第一点的 U  纹理坐标
		v_m = sector1.triangle[loop_m].vertex[0].v;			// 第一点的 V  纹理坐标
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);	// 设置纹理坐标和顶点

		x_m = sector1.triangle[loop_m].vertex[1].x;			// 第二点的 X 分量
		y_m = sector1.triangle[loop_m].vertex[1].y;			// 第二点的 Y 分量
		z_m = sector1.triangle[loop_m].vertex[1].z;			// 第二点的 Z 分量
		u_m = sector1.triangle[loop_m].vertex[1].u;			// 第二点的 U  纹理坐标
		v_m = sector1.triangle[loop_m].vertex[1].v;			// 第二点的 V  纹理坐标
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);	// 设置纹理坐标和顶点

		x_m = sector1.triangle[loop_m].vertex[2].x;			// 第三点的 X 分量
		y_m = sector1.triangle[loop_m].vertex[2].y;			// 第三点的 Y 分量
		z_m = sector1.triangle[loop_m].vertex[2].z;			// 第三点的 Z 分量
		u_m = sector1.triangle[loop_m].vertex[2].u;			// 第二点的 U  纹理坐标
		v_m = sector1.triangle[loop_m].vertex[2].v;			// 第二点的 V  纹理坐标
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);	// 设置纹理坐标和顶点
		glEnd();											// 三角形绘制结束
	}

	numTriangles = sector2.numTriangles;					// 取得Sector2的三角形数量
	glBindTexture(GL_TEXTURE_2D, texture[3]);				// 第四個也就是門的紋理

	// 逐个处理三角形
	for (int loop_m = 0; loop_m < numTriangles; loop_m++)	// 遍历所有的三角形
	{
		glBegin(GL_TRIANGLES);								// 开始绘制三角形
		glNormal3f(0.0f, 0.0f, 1.0f);						// 指向前面的法线
		x_m = sector2.triangle[loop_m].vertex[0].x;			// 第一点的 X 分量
		y_m = sector2.triangle[loop_m].vertex[0].y;			// 第一点的 Y 分量
		z_m = sector2.triangle[loop_m].vertex[0].z;			// 第一点的 Z 分量
		u_m = sector2.triangle[loop_m].vertex[0].u;			// 第一点的 U  纹理坐标
		v_m = sector2.triangle[loop_m].vertex[0].v;			// 第一点的 V  纹理坐标
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);	// 设置纹理坐标和顶点

		x_m = sector2.triangle[loop_m].vertex[1].x;			// 第二点的 X 分量
		y_m = sector2.triangle[loop_m].vertex[1].y;			// 第二点的 Y 分量
		z_m = sector2.triangle[loop_m].vertex[1].z;			// 第二点的 Z 分量
		u_m = sector2.triangle[loop_m].vertex[1].u;			// 第二点的 U  纹理坐标
		v_m = sector2.triangle[loop_m].vertex[1].v;			// 第二点的 V  纹理坐标
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);	// 设置纹理坐标和顶点

		x_m = sector2.triangle[loop_m].vertex[2].x;			// 第三点的 X 分量
		y_m = sector2.triangle[loop_m].vertex[2].y;			// 第三点的 Y 分量
		z_m = sector2.triangle[loop_m].vertex[2].z;			// 第三点的 Z 分量
		u_m = sector2.triangle[loop_m].vertex[2].u;			// 第二点的 U  纹理坐标
		v_m = sector2.triangle[loop_m].vertex[2].v;			// 第二点的 V  纹理坐标
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);	// 设置纹理坐标和顶点
		glEnd();											// 三角形绘制结束
	}

	// 畫模型
	if (mp_enable_model)
	{
		glPushMatrix();
		changeObject(gothicTrans);
		drawModel(gothicModel, true, false);
		glPopMatrix();
		glFlush();
	}

	// 暫停時的控制
	glLoadIdentity();										// 重置当前的模型观察矩阵
	glTranslatef(0.0f, 0.0f, -1.0f);						// 移入屏幕一个单位
	if (ifPause)
	{
		// 根据字体位置设置颜色
		glColor3f(0.3, 0.3, 0.3);							// 暗灰色

		// 设置光栅化位置，即字体的位置
		glRasterPos2f(-0.55f + 0.05f, 0.25f);
		glPrint("Pause");		// 输出文字到屏幕
		glRasterPos2f(-0.55f + 0.05f, 0.15f);
		glPrint("Please press [P] to resume.");
	}
	else
		glColor3f(1.0, 1.0, 1.0);

	return TRUE;											// 一切OK, FALSE的話程序即將退出
}

//*****************************************************************************

GLvoid ReleaseGLWindow(GLvoid)
//	描述:	正常销毁窗口
//	被调用：CreateGLWindow()
{
	// 我们处于全屏模式吗?
	if (mp_fullscreen)
	{
		ChangeDisplaySettings(NULL, 0);			// 是的话，切换回桌面,為了防止某些顯卡中桌面出现崩溃
		ShowCursor(TRUE);						// 显示鼠标指针
	}

	// 我们拥有OpenGL渲染描述表吗?
	if (hRC)
	{
		// 我们能否释放DC和RC描述表?
		if (!wglMakeCurrent(NULL, NULL))
			MessageBox(NULL, L"Fail to release DC or RC.", L"Shutdown Error", MB_OK | MB_ICONINFORMATION);

		// 我们能否删除RC?
		if (!wglDeleteContext(hRC))
			MessageBox(NULL, L"Fail to release RC.", L"Shutdown Error", MB_OK | MB_ICONINFORMATION);

		hRC = NULL;							// 将RC设为NULL
	}

	// 我们能否释放DC?
	if (hDC && !ReleaseDC(hWnd, hDC))
	{
		MessageBox(NULL, L"Fail to release DC.", L"Shutdown Error", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;							// 将DC设为NULL
	}

	// 能否销毁窗口?
	if (hWnd && !DestroyWindow(hWnd))
	{
		MessageBox(NULL, L"Fail to release Wnd", L"Shutdown Error", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;						// 将hWnd设为NULL
	}

	// 能否注销类?
	if (!UnregisterClass(L"OpenGL", hInstance))
	{
		MessageBox(NULL, L"Fail to unregister class \"OpenGL\".", L"Shutdown Error", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;					// 将hInstance设为 NULL
	}

	ReleaseFont();								// 註銷創建之字體
}

//*****************************************************************************

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
//	被调用：WinMain()
{
	GLuint PixelFormat;										// 保存查找匹配的结果
	WNDCLASS wc;											// 窗口类结构
	DWORD dwExStyle;										// 扩展窗口风格
	DWORD dwStyle;											// 窗口风格

	RECT WindowRect;										// 用來存儲矩形的左上角和右下角的坐标值
	WindowRect.left = (long)mp_window_left_top_x;			// 将Left   设为 mp_window_left_top_x
	WindowRect.top = (long)mp_window_left_top_y;			// 将Top    设为 mp_window_left_top_y
	WindowRect.right = (long)width;							// 将Right  设为要求的宽度
	WindowRect.bottom = (long)height;						// 将Bottom 设为要求的高度

	mp_fullscreen = fullscreenflag;							// 设置全局全屏标志

	hInstance = GetModuleHandle(NULL);						// 取得我们窗口的实例
	
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;			// 移动时重画，并为窗口取得DC
	wc.lpfnWndProc = (WNDPROC)WndProc;						// WndProc处理消息
	wc.cbClsExtra = 0;										// 无额外窗口数据
	wc.cbWndExtra = 0;										// 无额外窗口数据
	wc.hInstance = hInstance;								// 设置实例
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_CS));		// 装入图标
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// 装入鼠标指针
	wc.hbrBackground = NULL;								// GL不需要背景
	wc.lpszMenuName = NULL;									// 不需要菜单
	wc.lpszClassName = L"OpenGL";							// 窗口類名

	// 小圖標
	// HICON hSmallIcon = (HICON)LoadImageA(hInstance, MAKEINTRESOURCEA(IDI_ICON_CS), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	//SendMessage(hWnd, WM_SETICON, ICON_SMALL, IDI_ICON_CS);

	if (!RegisterClass(&wc))								// 尝试注册窗口类
	{
		MessageBox(NULL, L"Fail to register window", L"Register Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// 退出并返回FALSE
	}

	// 要尝试全屏模式吗?
	if (mp_fullscreen)
	{
		DEVMODE dmScreenSettings;							// 设备模式
		memset(&dmScreenSettings, 0,
			sizeof(dmScreenSettings));						// 确保内存清空为零
		dmScreenSettings.dmSize =
			sizeof(dmScreenSettings);						// Devmode结构的大小
		dmScreenSettings.dmPelsWidth = width;				// 所选屏幕宽度
		dmScreenSettings.dmPelsHeight = height;				// 所选屏幕高度
		dmScreenSettings.dmBitsPerPel = bits;				// 每象素所选的色彩深度
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// 尝试设置显示模式并返回结果。注: CDS_FULLSCREEN 移去了状态条。
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// 若模式失败，提供两个选项：退出或在窗口内运行。
			if (MessageBox(NULL, L"Fail to enter FullScreen Mode.\nEnter Window Mode？", L"Window Mode Error",
				MB_YESNO | MB_ICONEXCLAMATION) == IDYES)	// 如果按是,就進入此分支
			{
				mp_fullscreen = FALSE;							// 选择窗口模式
			}
			else
			{
				// 弹出一个对话框，告诉用户程序结束
				MessageBox(NULL, L"Program aborted.", L"Window Mode Error", MB_OK | MB_ICONSTOP);
				return FALSE;								// 退出并返回FALSE
			}
		}
	}

	// 仍处于全屏模式吗?
	if (mp_fullscreen)
	{
		dwExStyle = WS_EX_APPWINDOW;						// 强制我们的窗体可见时处于最前面
		dwStyle = WS_POPUP;									// 窗体风格
		ShowCursor(FALSE);									// 隐藏鼠标指针
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;		// 强制我们的窗体可见时处于最前面
															// 並增强窗体的3D感观
		dwStyle = WS_OVERLAPPEDWINDOW;						// 带标题栏、可变大小的边框、菜单														// 和最大化/最小化按钮的窗体;
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);	// 调整窗口达到真正要求的大小
	// 全屏模式下，此命令无效

	if (!(hWnd = CreateWindowExA(dwExStyle,					// 扩展窗体风格
		"OpenGL",											// 类名字
		title,												// 窗口标题
		dwStyle |											// 选择的窗体属性
		WS_CLIPSIBLINGS |									// 必须的窗体风格属性,阻止别的窗体在我们的窗体内/上绘图
		WS_CLIPCHILDREN ,									// 必须的窗体风格属性,阻止别的窗体在我们的窗体内/上绘图 
		WindowRect.left, WindowRect.top,					// 窗口位置
		WindowRect.right - WindowRect.left,					// 计算调整好的窗口宽度
		WindowRect.bottom - WindowRect.top,					// 计算调整好的窗口高度
		NULL,												// 无父窗口
		NULL,												// 无菜单
		hInstance,											// 实例
		NULL)))												// 不向WM_CREATE传递任何东东
	{
		ReleaseGLWindow();									// 重置显示区
		MessageBox(NULL, L"Fail to create an OpenGL Window", L"Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// 返回FALSE
	}

	// pfd告诉窗口我们所希望的东东，即窗口使用的像素格式
	static	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),						// 上述格式描述符的大小
		1,													// 版本号
		PFD_DRAW_TO_WINDOW |								// 格式支持窗口
		PFD_SUPPORT_OPENGL |								// 格式必须支持OpenGL
		PFD_DOUBLEBUFFER,									// 必须支持双缓冲
		PFD_TYPE_RGBA,										// 申请 RGBA 格式
		bits,												// 选定色彩深度
		0, 0, 0, 0, 0, 0,									// 忽略的色彩位
		0,													// 无Alpha缓存
		0,													// 忽略Shift Bit
		0,													// 无累加缓存
		0, 0, 0, 0,											// 忽略聚集位
		16,													// 16位 Z-缓存 (深度缓存)
		0,													// 无蒙板缓存
		0,													// 无辅助缓存
		PFD_MAIN_PLANE,										// 主绘图层
		0,													// Reserved
		0, 0, 0												// 忽略层遮罩
	};

	// 取得设备描述表了么?
	if (!(hDC = GetDC(hWnd)))
	{
		ReleaseGLWindow();										// 重置显示区
		MessageBox(NULL, L"Fail to create a pixal script.", L"Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// 返回 FALSE
	}

	// Windows 找到相应的象素格式了吗?
	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))
	{
		ReleaseGLWindow();										// 重置显示区
		MessageBox(NULL, L"Fail to find pixal format.", L"Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// 返回 FALSE
	}

	// Windows 能够设置象素格式么?
	if (!SetPixelFormat(hDC, PixelFormat, &pfd))
	{
		ReleaseGLWindow();										// 重置显示区
		MessageBox(NULL, L"Fail to set pixal format.", L"Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// 返回 FALSE
	}

	// 能否取得着色描述表?
	if (!(hRC = wglCreateContext(hDC)))
	{
		ReleaseGLWindow();										// 重置显示区
		MessageBox(NULL, L"Fail to create OpenGL DC.", L"Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// 返回 FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))							// 尝试激活着色描述表
	{
		ReleaseGLWindow();										// 重置显示区
		MessageBox(NULL, L"Fail to activate OpenGL DC.", L"Creation Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// 返回 FALSE
	}

	// 至此OpenGL窗口已经创建完成

	ShowWindow(hWnd, SW_SHOW);								// 显示窗口
	SetForegroundWindow(hWnd);								// 提高一點优先级
	SetFocus(hWnd);											// 设置键盘的焦点至此窗口
	ReSizeGLScene(width, height);							// 设置(透视) GL 屏幕

	if (!InitGL())											// 初始化新建的GL窗口
	{
		ReleaseGLWindow();										// 重置显示区
		MessageBox(NULL, L"Initialization Failed.", L"Initialization Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// 返回FALSE
	}

	return TRUE;											// 成功
}

//*****************************************************************************

LRESULT CALLBACK WndProc(HWND hWnd,	// 窗口的句柄
	UINT	uMsg,					// 窗口的消息
	WPARAM	wParam,					// 附加的消息内容
	LPARAM	lParam)					// 附加的消息内容
	//	描述:	处理所有的窗口消息。
	//	被调用：CreateGLWindow()
{
	switch (uMsg)					// 检查Windows消息, uMsg中保存了我们要处理的消息名字。
	{
	case WM_ACTIVATE:				// 监视窗口激活消息
	{
		if (!HIWORD(wParam))		// 检查最小化状态
		{
			active = TRUE;			// 程序处于激活状态
		}
		else
		{
			active = FALSE;			// 程序不再激活
		}

		return 0;					// 返回消息循环
	}

	case WM_SYSCOMMAND:				// 系统中断命令
	{
		switch (wParam)				// 检查系统调用
		{
		case SC_SCREENSAVE:			// 屏保要运行?
		case SC_MONITORPOWER:		// 显示器要进入节电模式?
			return 0;				// 阻止发生
		}
		break;						// 退出
	}

	case WM_CLOSE:					// 收到Close消息?
	{
		PostQuitMessage(0);			// 发出退出消息
		return 0;					// 返回
	}

	case WM_KEYDOWN:				// 有键按下么?
	{
		keys[wParam] = TRUE;		// 如果是，设为TRUE
		return 0;					// 返回
	}

	case WM_KEYUP:					// 有键放开么?
	{
		keys[wParam] = FALSE;		// 如果是，设为FALSE
		return 0;					// 返回
	}

	case WM_SIZE:					// 调整OpenGL窗口大小
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));		// LoWord=Width,HiWord=Height
		return 0;					// 返回
	}
	}

	// 向 DefWindowProc传递所有未处理的消息(或者說除了這些的其他消息)。
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//*****************************************************************************

int WINAPI WinMain(HINSTANCE hInstance,			// 当前窗口实例
	HINSTANCE	hPrevInstance,					// 前一个窗口实例
	LPSTR		lpCmdLine,						// 命令行参数
	int			nCmdShow)						// 窗口显示状态
//	描述:	Windows程序的入口。将会调用窗口创建例程，处理窗口消息，并监视人机交互
{
	MSG	msg;									// Windowsx消息结构
	BOOL done = FALSE;							// 用来退出循环的Bool变量

	// 提示用户选择运行模式
	if (mp_enable_mode_choose)
	{
		if (MessageBox(NULL, L"Welcome!\n Would you like to run in FullScreen?", L"Welcome", MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			mp_fullscreen = TRUE;					// FALSE为窗口模式
		}
	}

	// 创建OpenGL窗口
	if (!CreateGLWindow(f_window_name, mp_window_width, mp_window_height, 16, mp_fullscreen))	// 标题、宽度、高度、色彩深度，以及全屏标志
	{
		return 0;								// 失败退出
	}

	// 鼠標之初始化
	// 置於中央並啟動
	mousePosPre.x = (mp_window_width + mp_window_left_top_x) / 2;
	mousePosPre.y = (mp_window_height + mp_window_left_top_y) / 2;

	// 控制台指定是否顯示滑鼠
	ShowCursor(mp_show_crusor);

	// 下蹲的控制變量
	GLuint countCwral = 0;

	// 跳躍的控制變量
	BOOL hop = FALSE;
	FLOAT standardHeight = GetGravityDist(sp_jump_duration / 2);	// 要求時間內自由落體會掉多少高度

	// 行走的速率設定
	sp_walk_speedCurrent = sp_walk_speed;

	// 維持的迴圈
	while (!done)								// 保持循环直到 done==TRUE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))		// 有消息在等待吗?
		{
			if (msg.message == WM_QUIT)			// 收到退出消息?
			{
				done = TRUE;					// 是，则done=TRUE
			}
			else								// 不是，处理窗口消息
			{
				TranslateMessage(&msg);			// 翻译消息
				DispatchMessage(&msg);			// 发送消息
			}
		}
		else									// 如果没有消息
		{
			// 绘制场景。监视ESC键和来自DrawGLScene()的退出消息
			// 先看程序激活了么?
			if (active)							
			{
				// ESC 按下了么?
				if (keys[VK_ESCAPE])					
					done = TRUE;				// ESC 发出退出信号
				
				// 沒按ESC的那段時間，刷新屏幕
				else
				{
					DrawGLScene();				// 绘制场景
					SwapBuffers(hDC);			// 交换缓存(双缓存),可以实现无闪烁的动画
					//PlayMusic(isToPlay);		// 播放聲音

					// 鼠標控制
					if (!ifPause)
						SetViewByMouse();

					// 控制各个键
					if (mp_enable_light)				// 控制面板是否开启光源
					{
						// L键 光照
						if (keys['L'] && !lp && !ifPause)
							// 同时检查这两个条件的原因是为了防止L键被按住后，这段代码被反复执行，并导致窗体不停闪烁。
						{
							lp = TRUE;						// lp 设为 TRUE,表明L鍵已按過
							light = !light;					// 切换光源的 TRUE/FALSE(即開關)
							if (!light)						// 如果没有光源
								glDisable(GL_LIGHTING);		// 禁用光源
							else							// 否则
								glEnable(GL_LIGHTING);		// 启用光源
						}
						if (!keys['L'])						// L键松开了么?
						{
							lp = FALSE;						// 若是，则将lp设为FALSE
						}
					}

					//*******************************************************************

					// F键 紋理方式
					if (keys['F'] && !fp)				// F键按下了么?
					{
						fp = TRUE;						// fp 设为 TRUE
						filter += 1;					// filter的值加一
						if (filter > 2)					// 大于2了么?
						{
							filter = 0;					// 若是重置为0
						}
						isToPlay = FALSE;
						//PlayMusic();
					}
					if (!keys['F'])						// F键放开了么?
					{
						fp = FALSE;						// 若是fp设为FALSE
						isToPlay = TRUE;
					}

					//*******************************************************************

					// P键 透視(暫停之效果)及暫停
					if (keys['P'] && !bp)				// P 鍵按下了么?
					{
						bp = TRUE;						// 若是， bp 设为 TRUE
						blend = !blend;					// 切换混合选项的 TRUE / FALSE
						if (blend)						// 混合打开了么?
						{
							glEnable(GL_BLEND);			// 打开混合
							glDisable(GL_DEPTH_TEST);	// 关闭深度测试
							ifPause = TRUE;				// 暫停了,鼠標不管事,需要再按此鍵取消暫停
							ShowCursor(TRUE);
						}
						else							// 否则
						{
							glDisable(GL_BLEND);		// 关闭混合
							glEnable(GL_DEPTH_TEST);	// 打开深度测试
							ifPause = FALSE;			// 取消暫停
							ShowCursor(FALSE);
							SetCursorToCenter();		// 置滑鼠於中央
						}
					}
					if (!keys['P'])
					{
						bp = FALSE;						// 若是， bp设为 FALSE
					}

					//*******************************************************************

					// Space鍵 跳躍
					if (keys[VK_SPACE] && hop == FALSE && !hp && !ifPause)// 如果按下了,啟動hop,讓跳躍一次
					{
						hop = TRUE;							// 準備跳
						QueryPerformanceFrequency(&frequ);
						QueryPerformanceCounter(&start);	// 記錄開始時間
						walkbiasDefault = walkbias;			// 記錄開始高度位置
						hp = TRUE;
					}

					if (hop)
					{
						// 得到現時時刻
						// dummy函式拖時間
						//for (int i = 0; i<1000000; i++);
						QueryPerformanceCounter(&over);
						DOUBLE timePeriod = (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart;

						// Clivic之方法
						/*walkbias += sp_hop_v0 * timePeriod - 0.4f * sp_gravity * timePeriod * timePeriod;
						if (walkbias > walkbiasDefault)
							walkbias += sp_hop_v0 * timePeriod - 0.4f * sp_gravity * timePeriod * timePeriod;
						else
						{
							hop = FALSE;
							walkbias = walkbiasDefault;
						}*/							
						
						// 借鑒了cdm之算法
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

					// Shift鍵 變速
					if (keys[VK_SHIFT] && !sp)
					{
						sp_walk_speedCurrent = sp_shift_speed * sp_walk_speed;
						sp = TRUE;						// 若已按下shift， sp 设为 TRUE
					}

					if (!keys[VK_SHIFT] && sp)
					{
						sp_walk_speedCurrent  = sp_walk_speed;
						sp = FALSE;						// 若已放開shift, sp設為FALSE
					}

					//*******************************************************************

					// Ctrl键 下蹲
					if (keys[VK_CONTROL] && !cp && !ifPause)		// Ctrl 鍵按下了么?
					{
						if (countCwral < sp_crawl_smooth)
						{
							walkbias -= sp_cwral_degree;
							countCwral++;
						}
						else
						{
							walkbias += sp_cwral_degree;
							cp = TRUE;					// 若平滑下蹲完畢， cp 设为 TRUE
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
							cp = FALSE;					// 若平滑下蹲回復完畢， cp设为 FALSE
						}
					}

					//*******************************************************************

					// 其他鍵
					if (keys[VK_PRIOR])
					{
						tankZPos += 0.01;
					}

					if (keys[VK_NEXT])
					{
						tankZPos -= 0.01;
					}

					//*******************************************************************

					// 右鍵 右轉
					if (keys[VK_RIGHT] && !ifPause)
					{
						heading -= 0.15f;
						yrot = heading;					// 向左旋转场景
					}

					//*******************************************************************

					// 鼠標 右轉
					if (mouseHorizon == FALSE)
					{
						heading -= sp_mouse_factor;
						yrot = heading;					// 鼠標控制向左旋转场景
					}

					//*******************************************************************

					// 鼠標 右轉加速
					if (mouseHorizon == POSITIVE2X)
					{
						heading -= sp_mouse_factor / sp_mouse_factor_rotate;	// 鼠標控制加速向左旋转场景
						yrot = heading;
					}

					//*******************************************************************

					// 左鍵 左轉
					if (keys[VK_LEFT] && !ifPause)
					{
						heading += 0.15f;
						yrot = heading;					// 向右侧旋转场景
					}

					//*******************************************************************

					// 鼠標 左轉
					if (mouseHorizon == TRUE)
					{
						heading += sp_mouse_factor;
						yrot = heading;					// 鼠標控制向右旋转场景
					}

					//*******************************************************************

					// 鼠標 左轉加速
					if (mouseHorizon == NEGATIVE2X)
					{
						heading += sp_mouse_factor / sp_mouse_factor_rotate;	// 鼠標控制加速向右旋转场景
						yrot = heading;
					}

					//*******************************************************************

					// W鍵 前進
					if (keys['W'] && !ifPause)
					{
						GLfloat xposDelta = sin(heading*PI_OVER_180) * sp_walk_speedCurrent;
						GLfloat zposDelta = cos(heading*PI_OVER_180) * sp_walk_speedCurrent;

						// 控制不能穿墻
						if (DetectBump(xposDelta, zposDelta, 'W'))
						{
							xpos -=	xposDelta;			// 沿游戏者所在的X平面移动
							zpos -= zposDelta;			// 沿游戏者所在的Z平面移动
						}

						if (walkbiasangle >= 359.0f)					// 如果walkbiasangle大于359度
						{
							walkbiasangle = 0.0f;					// 将 walkbiasangle 设为0
						}
						else										// 否则
						{
							walkbiasangle += 0.5f;					// 如果 walkbiasangle < 359 ，则增加 0.5(数字越小震频越小)
						}
						if (hop)
							walkbias = walkbias - walkbiasDefault + (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;	// 使游戏者产生跳跃感(除数越大越平滑)
						else
							walkbias = (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;	// 使游戏者产生跳跃感(除数越大越平滑)

						// 播放
						//isToPlay = TRUE;
						//PlayMusic();
						//PlaySoundA("F:\\Visual C++ programs\\OpenGLM2\\footstep_1.wav", NULL, SND_ASYNC);
					}

					//*******************************************************************

					// S鍵 後退
					if (keys['S'] && !ifPause)
					{
						GLfloat xposDelta = sin(heading*PI_OVER_180) * sp_walk_speedCurrent;
						GLfloat zposDelta = cos(heading*PI_OVER_180) * sp_walk_speedCurrent;

						// 控制不能穿墻
						if (DetectBump(xposDelta, zposDelta, 'S'))
						{
							xpos += xposDelta;			// 沿游戏者所在的X平面移动
							zpos += zposDelta;			// 沿游戏者所在的Z平面移动
						}
						if (walkbiasangle <= 1.0f)					// 如果walkbiasangle小于1度
						{
							walkbiasangle = 359.0f;					// 使 walkbiasangle 等于 359
						}
						else										// 否则
						{
							walkbiasangle -= 0.5f;					// 如果 walkbiasangle > 1 减去 0.5
						}
						if (hop)
							walkbias = walkbias - walkbiasDefault + (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;		// 使游戏者产生跳跃感(除数越大越平滑)
						else
							walkbias = (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;		// 使游戏者产生跳跃感(除数越大越平滑)
					}

					//*******************************************************************

					// A鍵 左平移
					if (keys['A'] && !ifPause)
					{
						GLfloat xposDelta = cos(heading*PI_OVER_180) * sp_walk_speedCurrent;
						GLfloat zposDelta = sin(heading*PI_OVER_180) * sp_walk_speedCurrent;
						if (DetectBump(xposDelta, zposDelta, 'A'))
						{
							xpos -= xposDelta;			// 沿游戏者所在的X平面移动
							zpos += zposDelta;			// 沿游戏者所在的Z平面移动
						}
						if (walkbiasangle >= 359.0f)					// 如果walkbiasangle大于359度
						{
							walkbiasangle = 0.0f;					// 将 walkbiasangle 设为0
						}
						else								// 否则
						{
							walkbiasangle += 0.5f;					// 如果 walkbiasangle < 359 ，则增加 0.5(数字越小震频越小)
						}
						if (hop)
							walkbias = walkbias - walkbiasDefault + (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;
						else
							walkbias = (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;		// 使游戏者产生跳跃感(除数越大越平滑)
					}

					//*******************************************************************

					// D鍵 右平移
					if (keys['D'] && !ifPause)
					{
						GLfloat xposDelta = cos(heading*PI_OVER_180) * sp_walk_speedCurrent;
						GLfloat zposDelta = sin(heading*PI_OVER_180) * sp_walk_speedCurrent;
						if (DetectBump(xposDelta, zposDelta, 'D'))
						{
							xpos += xposDelta;			// 沿游戏者所在的X平面移动
							zpos -= zposDelta;			// 沿游戏者所在的Z平面移动
						}
						if (walkbiasangle >= 359.0f)					// 如果walkbiasangle大于359度
						{
							walkbiasangle = 0.0f;					// 将 walkbiasangle 设为0
						}
						else								// 否则
						{
							walkbiasangle += 0.5f;					// 如果 walkbiasangle < 359 ，则增加 0.5(数字越小震频越小)
						}
						if (hop)
							walkbias = walkbias - walkbiasDefault + (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;
						else
							walkbias = (float)sin(walkbiasangle * PI_OVER_180) / 50.0f;		// 使游戏者产生跳跃感(除数越大越平滑)
					}

					//*******************************************************************

					// 上鍵 向上看
					if (keys[VK_UP] && lookupdown >= -sp_max_head_angle && !ifPause)
					{
						lookupdown -= 0.1f;
					}

					//*******************************************************************

					// 鼠標 向上看
					if (mouseVertical == TRUE && lookupdown >= -sp_max_head_angle)
					{
						lookupdown -= sp_mouse_factor;
					}

					//*******************************************************************

					// 下鍵 向下看
					if (keys[VK_DOWN] && lookupdown <= sp_max_head_angle && !ifPause)
					{
						lookupdown += 0.1f;
					}

					//*******************************************************************

					// 鼠標 向下看
					if (mouseVertical == FALSE && lookupdown <= sp_max_head_angle)
					{
						lookupdown += sp_mouse_factor;
					}

					//*******************************************************************

					// 模型
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

			// 允许用户按下F1键在全屏模式和窗口模式间切换
			if (keys[VK_F1])					// F1键按下了么?
			{
				keys[VK_F1] = FALSE;			// 若是，使对应的Key数组中的值为 FALSE
				ReleaseGLWindow();				// 销毁当前的窗口
				mp_fullscreen = !mp_fullscreen;	// 切换全屏/窗口模式
				
				// 重建 OpenGL 窗口
				if (!CreateGLWindow(f_window_name, mp_window_width, mp_window_height, 16, mp_fullscreen))
					return 0;					// 如果窗口未能创建，程序退出				
			}
		}
	}
	// done 變成了TRUE, 关闭程序
	ReleaseGLWindow();							// 销毁窗口
	return (msg.wParam);						// 退出程序
}

