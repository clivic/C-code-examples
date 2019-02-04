//*****************************************************************************
//	這是一個OpenGL函數練習,根據NeHe的OpenGL教程而來。
//	此練習OpenGL1完成的是Lesson1, Lesson2, Lesson3, Lesson4。
//	功能：
//	搭建OpenGL框架,創建OpenGL窗口,並實現三角形四邊形之繪製及旋轉功能。
//*****************************************************************************

#include <windows.h>	// Windows的头文件
#include <glew.h>		// 包含最新的gl.h,glu.h库
#include <glut.h>		// 包含OpenGL实用库

HGLRC           hRC = NULL;							// 窗口着色描述表句柄
HDC             hDC = NULL;							// OpenGL渲染描述表句柄
HWND            hWnd = NULL;						// 保存我们的窗口句柄
HINSTANCE       hInstance;							// 保存程序的实例

bool			keys[256];							// 保存键盘按键的数组
bool			active = TRUE;						// 窗口的活动标志，缺省为TRUE
bool			fullscreen = FALSE;					// 這邊不同於教程，缺省為窗口模式

GLfloat			rtri;								// 用于三角形的旋轉角度,這裡沒初始化似乎也可以
GLfloat			rquad;								// 用于四边形的旋轉角度,這裡沒初始化似乎也可以


LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// WndProc的聲明

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)
// 描述:	重置OpenGL透视图屏幕窗口大小
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

int InitGL(GLvoid)
// 描述:	此处开始对OpenGL进行所有设置
{
	glShadeModel(GL_SMOOTH);				// 启用阴影平滑

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// 清除屏幕时所用的颜色即背景色,此處是黑色

	glClearDepth(1.0f);						// 设置深度缓存
	glEnable(GL_DEPTH_TEST);				// 启用深度测试
	glDepthFunc(GL_LEQUAL);					// 所作深度测试的类型

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// 告诉系统对透视进行修正(更好看)

	return TRUE;							// 初始化OK就返回TRUE
}

//*****************************************************************************

int DrawGLScene(GLvoid)								
// 描述:	从这里开始进行所有的绘制
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// 清除屏幕和深度缓存
	glLoadIdentity();									// 重置当前的模型观察矩阵
														// OpenGL屏幕中心纔是(0,0),右手系
	// 從這裡開始繪製
	glTranslatef(-1.5f, 1.0f, -6.0f);					// 畫筆移動到(-1.5f, 1.0f, -6.0f)點
	
	// 先設定旋轉
	glRotatef(rtri, 0.0f, 1.0f, 0.0f);					// 绕Y轴旋转三角形

	// 绘制三角形
	glBegin(GL_TRIANGLES);							
	glColor3f(1.0f, 0.0f, 0.0f);						// 设置当前色为红色(默認是白色也許)
	glVertex3f(0.0f, 1.0f, 0.0f);						// 上顶点(這裡點的坐標是相對於畫筆的位置的也許)
	glColor3f(0.0f, 1.0f, 0.0f);						// 设置当前色为绿色
	glVertex3f(-1.0f, -1.0f, 0.0f);						// 左下
	glColor3f(0.0f, 0.0f, 1.0f);						// 设置当前色为蓝色
	glVertex3f(1.0f, -1.0f, 0.0f);						// 右下
	glEnd();											// 三角形绘制结束

	// 再設定旋轉
	glLoadIdentity();									// 因為旋轉過了,畫筆位置變化了,故重置模型观察矩阵
	glTranslatef(-1.5f, -1.0f, -6.0f);					// 重新從原點開始放好正方形中心之位置,在三角形中心下面2.0f處
	glRotatef(rquad, 1.0f, 0.0f, 0.0f);					// 绕X轴旋转四边形

	// 绘制正方形
	glBegin(GL_QUADS);	
	glColor3f(0.5f, 0.5f, 1.0f);						// 一次性将当前色设置为蓝色
	glVertex3f(-1.0f, 1.0f, 0.0f);						// 左上
	glVertex3f(1.0f, 1.0f, 0.0f);						// 右上
	glVertex3f(1.0f, -1.0f, 0.0f);						// 左下
	glVertex3f(-1.0f, -1.0f, 0.0f);						// 右下
	glEnd();											// 正方形绘制结束

	//繪製完後,因為此函數會被循環調用,故讓之旋轉
	rtri += 0.2f;										// 增加三角形的旋转变量
	rquad -= 0.15f;										// 减少四边形的旋转变量

	return TRUE;										// 一切OK, FALSE的話程序即將退出
}

//*****************************************************************************

GLvoid ReleaseGLWindow(GLvoid)
// 描述:	正常销毁窗口
{
	// 我们处于全屏模式吗?
	if (fullscreen)
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
}

//*****************************************************************************

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint PixelFormat;										// 保存查找匹配的结果
	WNDCLASS wc;											// 窗口类结构
	DWORD dwExStyle;										// 扩展窗口风格
	DWORD dwStyle;											// 窗口风格

	RECT WindowRect;										// 用來存儲矩形的左上角和右下角的坐标值
	WindowRect.left = (long)100;							// 将Left   设为 0
	WindowRect.top = (long)50;								// 将Top    设为 0
	WindowRect.right = (long)width;							// 将Right  设为要求的宽度
	WindowRect.bottom = (long)height;						// 将Bottom 设为要求的高度

	fullscreen = fullscreenflag;							// 设置全局全屏标志

	hInstance = GetModuleHandle(NULL);						// 取得我们窗口的实例
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;			// 移动时重画，并为窗口取得DC
	wc.lpfnWndProc = (WNDPROC)WndProc;						// WndProc处理消息
	wc.cbClsExtra = 0;										// 无额外窗口数据
	wc.cbWndExtra = 0;										// 无额外窗口数据
	wc.hInstance = hInstance;								// 设置实例
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);					// 装入图标
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// 装入鼠标指针
	wc.hbrBackground = NULL;								// GL不需要背景
	wc.lpszMenuName = NULL;									// 不需要菜单
	wc.lpszClassName = L"OpenGL";							// 窗口類名

	if (!RegisterClass(&wc))								// 尝试注册窗口类
	{
		MessageBox(NULL, L"Fail to register window", L"Register Error", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;										// 退出并返回FALSE
	}

	// 要尝试全屏模式吗?
	if (fullscreen)
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
				fullscreen = FALSE;							// 选择窗口模式
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
	if (fullscreen)
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

	if (!(hWnd = CreateWindowEx(dwExStyle,					// 扩展窗体风格
		L"OpenGL",											// 类名字
		(LPCWSTR)title,										// 窗口标题
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
		ReleaseGLWindow();										// 重置显示区
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
	ReSizeGLScene(width, height);							// 设置透视 GL 屏幕

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

	// 這邊先不提醒選擇模式了,注釋了以下碼字
	// 提示用户选择运行模式
	//if (MessageBox(NULL, L"Welcome!\n Would you like to run in FullScreen?", L"Welcome", MB_YESNO | MB_ICONQUESTION) == IDYES)
	//{
	//	fullscreen = TRUE;						// FALSE为窗口模式
	//}

	// 创建OpenGL窗口
	if (!CreateGLWindow("OpenGL1", 640, 480, 16, fullscreen))	// 标题、宽度、高度、色彩深度，以及全屏标志
	{
		return 0;												// 失败退出
	}

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
				}
			}

			// 允许用户按下F1键在全屏模式和窗口模式间切换
			if (keys[VK_F1])					// F1键按下了么?
			{
				keys[VK_F1] = FALSE;			// 若是，使对应的Key数组中的值为 FALSE
				ReleaseGLWindow();				// 销毁当前的窗口
				fullscreen = !fullscreen;		// 切换全屏/窗口模式
				
				// 重建 OpenGL 窗口
				if (!CreateGLWindow("OpenGL1", 640, 480, 16, fullscreen))				
					return 0;					// 如果窗口未能创建，程序退出				
			}
		}
	}
	// done 變成了TRUE, 关闭程序
	ReleaseGLWindow();							// 销毁窗口
	return (msg.wParam);						// 退出程序
}

