#include <windows.h>
#define ID_OK_BTN 2000 
#define ID_SUBMISSION_WAY_BTN 2001 
#define ID_ADDITIONAL_REGISTER_BTN 2002 

HINSTANCE g_hInst; 

LPCTSTR lpszClass = L"HelloAPI"; 
LPCTSTR ChildClassName = L"ChildWin"; 
LPCTSTR ChildClassName1 = L"ChildWin1"; 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); 
LRESULT CALLBACK ChildWndProc1(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); 
int APIENTRY WinMain(HINSTANCE hInstance
, HINSTANCE hPrevInstance
, LPSTR lpszCmdParam
, int nCmdShow) { 
    HWND hWnd; MSG Message; 
    WNDCLASS WndClass; 
    g_hInst = hInstance; 

    WndClass.cbClsExtra = 0; 
    WndClass.cbWndExtra = 0; 
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); 
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); 
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hInstance = hInstance; 
    WndClass.lpfnWndProc = (WNDPROC)WndProc; WndClass.lpszClassName = lpszClass; 
    WndClass.lpszMenuName = NULL; 
    WndClass.style = CS_HREDRAW | CS_VREDRAW; 
    RegisterClass(&WndClass); 
    //메인윈도우 클래스 등록 
    WndClass.lpfnWndProc = ChildWndProc; 
    //차일드 윈도우 프로시저 WndClass.lpszClassName = ChildClassName; 
    //차일드 윈도우 클래스이름 RegisterClass(&WndClass); 
    WndClass.lpfnWndProc = ChildWndProc1; 
    //차일드 윈도우 프로시저 WndClass.lpszClassName = ChildClassName1; 
    //차일드 윈도우 클래스이름 RegisterClass(&WndClass); 
    hWnd = CreateWindow(lpszClass, //윈도우클래스 이름 
    L"Visual C++ 출석수업 대체 실습과제물", //윈도우타이틀 
    WS_OVERLAPPEDWINDOW | WS_VISIBLE, //윈도우스타일 
    200, 200, //윈도우가 보일때 X Y좌표 
    800, 600, //윈도우의 폭과 높이 
    (HWND)NULL, //부모윈도우 핸들 
    (HMENU)NULL, //윈도우가 가지는 메뉴핸들 
    hInstance, //인스턴스핸들 
    NULL); //여분의 데이터 

    ShowWindow(hWnd, nCmdShow); 
    while (GetMessage(&Message, 0, 0, 0)) { 
        TranslateMessage(&Message); 
        DispatchMessage(&Message); 
    } return Message.wParam; 
} 

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage
, WPARAM wParam, LPARAM lParam) 
{ 
    LPCTSTR text = L"201934-153694 김진성"; 
    switch (iMessage) { 
    case WM_PAINT: { 
        PAINTSTRUCT ps; 
        HDC hdc = BeginPaint(hWnd, &ps); 
        TextOut(hdc, 100, 100, text, lstrlen(text)); 
        EndPaint(hWnd, &ps); 
        return 0; 
        } 
        case WM_CREATE: 
        { 
            HWND hChildWnd = CreateWindow( 
                ChildClassName, // 차일드 윈도우 클래스 이름 
                L"신청기한", // 윈도우 타이틀 
                WS_OVERLAPPEDWINDOW | WS_CHILD, // 윈도우 스타일 
                50, // 윈도우 보일 때 x 좌표 
                150, // 윈도우 보일 때 y 좌표 
                260, // 윈도우 폭 
                200, // 윈도우 높이 
                hWnd, // 부모 윈도우 
                (HMENU)1000, // 차일드 윈도우
                ID g_hInst, // 인스턴스 핸들 
                (LPVOID)NULL); // 여분의 데이터 
            ShowWindow(hChildWnd, SW_SHOW); 

                hChildWnd1 = CreateWindow( ChildClassName1, // 차일드 윈도우 클래스 이름 
                L"제출기간", // 윈도우 타이틀 
                WS_OVERLAPPEDWINDOW | WS_CHILD, // 윈도우 스타일 
                400, // 윈도우 보일 때 x 좌표 
                150, // 윈도우 보일 때 y 좌표 
                260, // 윈도우 폭 
                200, // 윈도우 높이 
                hWnd, // 부모 윈도우 
                (HMENU)1000, // 차일드 윈도우
                ID g_hInst, // 인스턴스 핸들 
                (LPVOID)NULL); // 여분의 데이터 
                
                ShowWindow(hChildWnd1, SW_SHOW); 
                
                hChildWnd = CreateWindow( 
                    L"button", // 윈도우 클래스 이름 
                    L"소속", // 윈도우 타이틀 
                    WS_CHILD | WS_VISIBLE, // 윈도우 스타일 
                    50, // 윈도우 보일 때 x 좌표 
                    400, // 윈도우 보일 때 y 좌표 
                    150, // 윈도우 폭 
                    30, // 윈도우 높이 
                    hWnd, // 부모 윈도우 
                    (HMENU)ID_OK_BTN, // 컨트롤 
                    ID g_hInst, // 인스턴스 핸들 
                    (LPVOID)NULL); // 여분의 데이터 
                    
                hChildWnd = CreateWindow( 
                    L"button", // 윈도우 클래스 이름 
                    L"제출방법", // 윈도우 타이틀 
                    WS_CHILD | WS_VISIBLE, // 윈도우 스타일 
                    400, // 윈도우 보일 때 x 좌표 
                    400, // 윈도우 보일 때 y 좌표 
                    150, // 윈도우 폭 
                    30, // 윈도우 높이 
                    hWnd, // 부모 윈도우 
                    (HMENU)ID_SUBMISSION_WAY_BTN, // 컨트롤 
                    ID g_hInst, // 인스턴스 핸들 
                    (LPVOID)NULL);  // 여분의 데이터 
                if (!hChildWnd) return -1; 
                return 0; 
                } case WM_COMMAND: 
                { 
                if (LOWORD(wParam) == ID_OK_BTN) 
                {
                MessageBox(hWnd, L"서울지역대학", L"소속", MB_OK); 
                } 
                if 
                (LOWORD(wParam) == ID_SUBMISSION_WAY_BTN) { 
                MessageBox(hWnd, L"온라인제출", L"제출방법", MB_OK); 
                } 
                if (LOWORD(wParam) == ID_ADDITIONAL_REGISTER_BTN) 
                { 
                MessageBox(hWnd, L"5.27, 18:00 까지", L"추가접수", MB_OK); 
                } 
                return 0;
                } 
                case WM_DESTROY: 
                    PostQuitMessage(0);
                    return 0;
                } 
                return(DefWindowProc(hWnd, iMessage, wParam, lParam));
                } 
                LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
                { 
                    LPCTSTR text = L"2020.5.8, 18:00까지";
                    switch (message) 
                    { 
                        case WM_PAINT: 
                        { 
                            PAINTSTRUCT ps; 
                            HDC hdc = BeginPaint(hWnd, &ps); 
                            TextOut(hdc, 10, 10, text, lstrlen(text));
                            EndPaint(hWnd, &ps); 
                            return 0; 
                                } 
                            } 
                            
                            return DefWindowProc(hWnd, message, wParam, lParam);
                } 
                LRESULT CALLBACK ChildWndProc1(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
                {
                     LPCTSTR text = L"2020.5.11-5.22, 18:00까지"; 
                     switch (message) 
                     { 
                         case WM_PAINT: 
                         { 
                             PAINTSTRUCT ps; 
                             HDC hdc = BeginPaint(hWnd, &ps); 
                             TextOut(hdc, 10, 30, text, lstrlen(text)); 
                             EndPaint(hWnd, &ps); return 0; 
                             } case WM_CREATE:
                              { HWND hChildWnd = CreateWindow( L"button", // 윈도우 클래스 이름 
                              L"추가접수", // 윈도우 타이틀 
                              WS_CHILD | WS_VISIBLE, // 윈도우 스타일 
                              40, // 윈도우 보일 때 x 좌표 
                              100, // 윈도우 보일 때 y 좌표 
                              80, // 윈도우 폭 
                              30, // 윈도우 높이 
                              hWnd, // 부모 윈도우 
                              (HMENU)ID_ADDITIONAL_REGISTER_BTN, // 컨트롤 
                              ID g_hInst, // 인스턴스 핸들 (LPVOID)NULL);// 여분의 데이터 
                              
                            if (!hChildWnd) 
                                return -1; 
                            return 0; 
                            } 
                        case WM_COMMAND: 
                        { 
                            if (LOWORD(wParam) == ID_ADDITIONAL_REGISTER_BTN) 
                            { 
                                MessageBox(hWnd, L"5.27, 18:00 까지", L"추가접수", MB_OK);
        }
    }
} return DefWindowProc(hWnd, message, wParam, lParam);

