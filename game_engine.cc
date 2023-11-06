#define WGL_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB 0x2092
#define WGL_CONTEXT_FLAGS_ARB 0x2094
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#define WGL_CONTEXT_PROFILE_MASK_ARB 0x9126
typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC)
(HDC, HGLRC, const int*);

typedef const char*
(WINAPI* PFNWGLGETEXTENSIONSSTRINGEXTPROC) (void);
typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC) (int);
typedef int (WINAPI* PFNWGLGETSWAPINTERVALEXTPROC) (void);

Application* gApplication = 0;
GLuint gVertexArrayObject = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE
    hPrevInstance, PSTR szCmdLine,
int iCmdShow) 
{
    gApplication = new Application();
}

WNDCLASSEX wndclass;
wndclass.cbSize = sizeof(WNDCLASSEX);
wndclass.style = CS_HREDRAW | CS_VREDRAW;
wndclass.lpfnWndProc = WndProc;
wndclass.cbClsExtra = 0;
wndclass.cbWndExtra = 0;
wndclass.hInstance = hInstance;
wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
wndclass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
wndclass.lpszMenuName = 0;
wndclass.lpszClassName = "Win32 Game Window";
RegisterClassEx(&wndclass);

int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);
int clientWidth = 800;
int clientHeight = 600;
RECT windowRect;
SetRect(&windowRect,
    (screenWidth / 2) - (clientWidth / 2),
    (screenHeight / 2) - (clientHeight / 2),
    (screenWidth / 2) + (clientWidth / 2),
    (screenHeight / 2) + (clientHeight / 2));

DWORD style = (WS_OVERLAPPED | WS_CAPTION |
    WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);
// | WS_THICKFRAME to resize

AdjustWindowRectEx(&windowRect, style, FALSE, 0);
HWND hwnd = CreateWindowEx(0, wndclass.lpszClassName,
    "Game Window", style, windowRect.left,
    windowRect.top, windowRect.right -
    windowRect.left, windowRect.bottom -
    windowRect.top, NULL, NULL,
    hInstance, szCmdLine);
HDC hdc = GetDC(hwnd);

PIXELFORMATDESCRIPTOR pfd;
memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
pfd.nVersion = 1;
pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW
    | PFD_DOUBLEBUFFER;
pfd.iPixelType = PFD_TYPE_RGBA;
pfd.cColorBits = 24;
pfd.cDepthBits = 32;
pfd.cStencilBits = 8;
pfd.iLayerType = PFD_MAIN_PLANE;
int pixelFormat = ChoosePixelFormat(hdc, &pfd);
SetPixelFormat(hdc, pixelFormat, &pfd);

HGLRC tempRC = wglCreateContext(hdc);
wglMakeCurrent(hdc, tempRC);
PFNWGLCREATECONTEXTATTRIBSARBPROC 
    wglCreateContextAttribsARB = NULL;
wglCreateContextAttribsARB =
    (PFNWGLCREATECONTEXTATTRIBSARBPROC)
wglGetProcAddress("wglCreateContextAttribsARB");

const int attribList[] = 
{
    WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
    WGL_CONTEXT_MINOR_VERSION_ARB, 3,
    WGL_CONTEXT_FLAGS_ARB, 0,
    WGL_CONTEXT_PROFILE_MASK_ARB,
    WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
    0, 
};

HGLRC hglrc = wglCreateContextAttribsARB(
    hdc, 0, attribList);
// Creating a window 25
wglMakeCurrent(NULL, NULL);
wglDeleteContext(tempRC);
wglMakeCurrent(hdc, hglrc);

if (!gladLoadGL()) 
{
    std::cout << "Could not initialize GLAD\n";
}
else 
{
    std::cout << "OpenGL Version " <<
    GLVersion.major << "." << GLVersion.minor <<
    "\n";
}

FNWGLGETEXTENSIONSSTRINGEXTPROC
_wglGetExtensionsStringEXT =
    (PFNWGLGETEXTENSIONSSTRINGEXTPROC)
wglGetProcAddress("wglGetExtensionsStringEXT");
bool swapControlSupported = strstr(
    _wglGetExtensionsStringEXT(),
    "WGL_EXT_swap_control") != 0;

int vsynch = 0;
if (swapControlSupported) {
    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT =
        (PFNWGLSWAPINTERVALEXTPROC)
    wglGetProcAddress("wglSwapIntervalEXT");
    PFNWGLGETSWAPINTERVALEXTPROC
        wglGetSwapIntervalEXT =
            (PFNWGLGETSWAPINTERVALEXTPROC)
    wglGetProcAddress("wglGetSwapIntervalEXT");

    if (wglSwapIntervalEXT(1)) 
    {
        std::cout << "Enabled vsynch\n";
        vsynch = wglGetSwapIntervalEXT();
    }
    else 
    {
        std::cout << "Could not enable vsynch\n";
    }
}
else 
{ // !swapControlSupported
    cout << "WGL_EXT_swap_control not supported\n";
}

