//-----------------------------------------------------------------------------
// File: Matrices.cpp
//
// Desc: Taking references of tutorials 03 -- Matrices in DirectX samples.
//		 This program is to read the Vertices and Faces info and despict the 
//		 graph out.
//
// References and Thanks to: 
//		 Copyright (c) Microsoft Corporation. All rights reserved.
//-----------------------------------------------------------------------------
#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>




//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
LPDIRECT3D9             g_pD3D = NULL;		// Used to create the D3DDevice
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL;// Our rendering device
LPDIRECT3DVERTEXBUFFER9 g_pVB = NULL;		// Buffer to hold vertices
DWORD g_faces[1476][4];						// Info of faces stored
FLOAT g_vertice[1443][3];					// Info of vertices stored

// A structure for our custom vertex type
struct CUSTOMVERTEX
{
    FLOAT x, y, z;      // The untransformed, 3D position for the vertex
    DWORD color;        // The vertex color
};

// Our custom FVF, which describes our custom vertex structure
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)




//-----------------------------------------------------------------------------
// Name: InitD3D()
// Desc: Initializes Direct3D
//-----------------------------------------------------------------------------
HRESULT InitD3D( HWND hWnd )
{
    // Create the D3D object.
    if( NULL == ( g_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
        return E_FAIL;

    // Set up the structure used to create the D3DDevice
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp, sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

    // Create the D3DDevice
    if( FAILED( g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, &g_pd3dDevice ) ) )
    {
        return E_FAIL;
    }

    // Turn off culling, so we see the front and back of the triangle
    g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );

    // Turn off D3D lighting, since we are providing our own vertex colors
    g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );

    return S_OK;
}

//-----------------------------------------------------------------------------
//Name: InitVFInfo()
//Desc: Initializes the info of Vertice and Faces, for which "2.txt" and "1.dat"
//		stands.
//-----------------------------------------------------------------------------
VOID InitVFInfo() 
{
	if (freopen("2.txt", "r", stdin) == NULL)	// Redirect Input stream
		MessageBox(NULL, L"Fail to open vertices file.", L"Matrices.exe", MB_OK);
	DWORD no;
	for (DWORD i = 1; i <= 1442; i++) // Vertices
		scanf( "%d%f%f%f", &no, &g_vertice[i][0], &g_vertice[i][1], &g_vertice[i][2] );
	fclose(stdin);

	if (freopen("1.dat", "r", stdin) == NULL)
		MessageBox(NULL, L"Fail to open faces info file.", L"Matrices.exe", MB_OK);
	scanf( "%d%d", &no, &no );
	for (DWORD i = 0; i < 1476; i++)  // Faces
		scanf( "%d%d%d%d%d", &no, &g_faces[i][0], &g_faces[i][1], 
		&g_faces[i][2], &g_faces[i][3] );
	fclose(stdin);
}

//-----------------------------------------------------------------------------
//Name: TransformSet()
//Desc: Restore the faces info in g_faces to the Geometry vertex(adding color).
//-----------------------------------------------------------------------------
VOID TransformSet( CUSTOMVERTEX *arr, FLOAT xyz[3] ) 
{
	(*arr).x = xyz[0];
	(*arr).y = xyz[1];
	(*arr).z = xyz[2];
	(*arr).color = 0xffffffff;
}


//-----------------------------------------------------------------------------
// Name: InitGeometry()
// Desc: Creates the scene geometry
//-----------------------------------------------------------------------------
HRESULT InitGeometry()
{
    // Initialize three vertices for rendering a triangle
    CUSTOMVERTEX vertices[6000];	// Store the faces info to dispict, 
									// (include color)
	DWORD count = 0;				// Number of vertices in vertices[]
	InitVFInfo();
	for (DWORD i = 0; i < 1476; i++) 
	{
		if (g_faces[i][3] == 0) 
		{
			for (DWORD j = 0; j < 3; j++) 
				TransformSet( vertices + count++,// The position of vetex stored in vertices
				g_vertice[g_faces[i][j]] );		 // Which vertex stored in 2.txt
		}
		else 
		{
			for (DWORD j = 0; j < 4; j++) 
				TransformSet( vertices + count++, g_vertice[g_faces[i][j]] );
		}
	}

    // Create the vertex buffer.
    if( FAILED( g_pd3dDevice->CreateVertexBuffer( 6000 * sizeof( CUSTOMVERTEX ),
                                                  0, D3DFVF_CUSTOMVERTEX,
                                                  D3DPOOL_DEFAULT, &g_pVB, NULL ) ) )
    {
        return E_FAIL;
    }

    // Fill the vertex buffer.
    VOID* pVertices;
    if( FAILED( g_pVB->Lock( 0, sizeof( vertices ), ( void** )&pVertices, 0 ) ) )
        return E_FAIL;
    memcpy( pVertices, vertices, sizeof( vertices ) );
    g_pVB->Unlock();

    return S_OK;
}




//-----------------------------------------------------------------------------
// Name: Cleanup()
// Desc: Releases all previously initialized objects
//-----------------------------------------------------------------------------
VOID Cleanup()
{
    if( g_pVB != NULL )
        g_pVB->Release();

    if( g_pd3dDevice != NULL )
        g_pd3dDevice->Release();

    if( g_pD3D != NULL )
        g_pD3D->Release();
}



//-----------------------------------------------------------------------------
// Name: SetupMatrices()
// Desc: Sets up the world, view, and projection transform matrices.
//-----------------------------------------------------------------------------
VOID SetupMatrices()
{
    // For our world matrix, we will just rotate the object about the y-axis.
    D3DXMATRIXA16 matWorld;

    // Set up the rotation matrix to generate 1 full rotation (2*PI radians) 
    // every 1000 ms. To avoid the loss of precision inherent in very high 
    // floating point numbers, the system time is modulated by the rotation 
    // period before conversion to a radian angle.
    UINT iTime = timeGetTime() % 2000;
    FLOAT fAngle = iTime * ( 2.0f * D3DX_PI ) / 1000.0f;
    D3DXMatrixRotationY( &matWorld, fAngle );
    g_pd3dDevice->SetTransform( D3DTS_WORLD, &matWorld );

    // Set up our view matrix. A view matrix can be defined given an eye point,
    // a point to lookat, and a direction for which way is up. Here, we set the
    // eye five units back along the z-axis and up three units, for the graph 
	// is a bit big, and look at the origin, and define "up" to be in the 
	// y-direction.
    D3DXVECTOR3 vEyePt( 0.0f, 30.0f,-50.0f );
    D3DXVECTOR3 vLookatPt( 0.0f, 0.0f, 0.0f );
    D3DXVECTOR3 vUpVec( 0.0f, 10.0f, 0.0f );
    D3DXMATRIXA16 matView;
    D3DXMatrixLookAtLH( &matView, &vEyePt, &vLookatPt, &vUpVec );
    g_pd3dDevice->SetTransform( D3DTS_VIEW, &matView );

    // For the projection matrix, we set up a perspective transform (which
    // transforms geometry from 3D view space to 2D viewport space, with
    // a perspective divide making objects smaller in the distance). To build
    // a perpsective transform, we need the field of view (1/4 pi is common),
    // the aspect ratio, and the near and far clipping planes (which define at
    // what distances geometry should be no longer be rendered).
    D3DXMATRIXA16 matProj;
    D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f );
    g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &matProj );
}



//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Draws the scene
//-----------------------------------------------------------------------------
VOID Render()
{
    // Clear the backbuffer to a black color
    g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 0, 0, 0 ), 1.0f, 0 );

    // Begin the scene
    if( SUCCEEDED( g_pd3dDevice->BeginScene() ) )
    {
        // Setup the world, view, and projection matrices
        SetupMatrices();

        // Render the vertex buffer contents
        g_pd3dDevice->SetStreamSource( 0, g_pVB, 0, sizeof( CUSTOMVERTEX ) );
        g_pd3dDevice->SetFVF( D3DFVF_CUSTOMVERTEX );
		DWORD count = 0;
		for (DWORD i = 0; i < 1476; i++)
		{
			if (g_faces[i][3] == 0)
			{
				g_pd3dDevice->DrawPrimitive( D3DPT_TRIANGLELIST, count, 1 );
				count += 4;
			}
			else 
			{
				g_pd3dDevice->DrawPrimitive( D3DPT_TRIANGLEFAN, count, 2 );
				count += 4;
			}
		}

        // End the scene
        g_pd3dDevice->EndScene();
    }

    // Present the backbuffer contents to the display
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}




//-----------------------------------------------------------------------------
// Name: MsgProc()
// Desc: The window's message handler
//-----------------------------------------------------------------------------
LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
        case WM_DESTROY:
            Cleanup();
            PostQuitMessage( 0 );
            return 0;
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}




//-----------------------------------------------------------------------------
// Name: WinMain()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
INT WINAPI wWinMain( HINSTANCE hInst, HINSTANCE, LPWSTR, INT )
{
    UNREFERENCED_PARAMETER( hInst );

    // Register the window class
    WNDCLASSEX wc =
    {
        sizeof( WNDCLASSEX ), CS_CLASSDC, MsgProc, 0L, 0L,
        GetModuleHandle( NULL ), NULL, NULL, NULL, NULL,
        L"D3D Dipict", NULL
    };
	wc.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(ICON_SMALL));
	RegisterClassEx( &wc );

    // Create the application's window
    HWND hWnd = CreateWindow( L"D3D Dipict", L"D3D Read vertices and faces",
                              WS_OVERLAPPEDWINDOW, 100, 100, 512, 512,
                              NULL, NULL, wc.hInstance, NULL );

    // Initialize Direct3D
    if( SUCCEEDED( InitD3D( hWnd ) ) )
    {
        // Create the scene geometry
        if( SUCCEEDED( InitGeometry() ) )
        {
            // Show the window
            ShowWindow( hWnd, SW_SHOWDEFAULT );
            UpdateWindow( hWnd );

            // Enter the message loop
            MSG msg;
            ZeroMemory( &msg, sizeof( msg ) );
            while( msg.message != WM_QUIT )
            {
                if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
                {
                    TranslateMessage( &msg );
                    DispatchMessage( &msg );
                }
                else
                    Render();
            }
        }
    }

    UnregisterClass( L"D3D Dipict", wc.hInstance );
    return 0;
}



