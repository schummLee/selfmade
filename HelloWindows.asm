; Define the section where data is stored
section .data
    class_name db 'SimpleWinClass', 0          ; Class name for the window
    app_name db 'Hello Windows Assembly', 0    ; Application name

; Define the section where uninitialized data is stored
section .bss
    hInstance resd 1         ; Reserve space for hInstance
    CommandLine resd 1       ; Reserve space for CommandLine
    hWnd resd 1              ; Reserve space for hWnd (Window Handle)

; Define the text section (code)
section .text
    global _start           ; Entry point for the program

_start:
    ; Entry point for Windows
    pop ecx                ; Argc (Unused in this example)
    pop eax                ; Argv (Unused)
    pop dword [hInstance]  ; hInstance (Instance handle)
    pop dword [CommandLine]; lpCmdLine (Command line string)

    ; Initialize WNDCLASSEX structure
    mov ecx, 48            ; Size of WNDCLASSEX structure
    mov edi, wc            ; Address of wc
    xor al, al             ; Null byte for initialization
    rep stosb              ; Fill with zero

    ; Populate WNDCLASSEX fields
    mov word [wc], 48        ; wc.cbSize = sizeof(WNDCLASSEX)
    mov word [wc+4], 3Ch     ; wc.style = CS_CLASSDC
    lea eax, [WndProc]       ; wc.lpfnWndProc = WndProc
    mov [wc+8], eax
    mov eax, [hInstance]     ; wc.hInstance = hInstance
    mov [wc+12], eax
    mov dword [wc+40], offset class_name  ; wc.lpszClassName = class_name

    ; Register the window class
    lea eax, [wc]
    push eax
    call [RegisterClassEx]

    ; Create the window
    push 0                  ; HWND_DESKTOP (Parent Window)
    push 0                  ; NULL (Menu)
    push 0                  ; NULL (Instance for multiple windows)
    push 0                  ; NULL (lpParam)
    push 320                ; Height of the window
    push 240                ; Width of the window
    push 10                 ; Initial y-coordinate
    push 10                 ; Initial x-coordinate
    push 80000000h          ; Window Style (WS_OVERLAPPEDWINDOW)
    push offset app_name    ; Title
    push offset class_name  ; Class name
    push 0                  ; Extended window style (WS_OVERLAPPED)
    call [CreateWindowEx]
    mov [hWnd], eax         ; Save the window handle

    ; Show the window
    push 5                  ; SW_SHOW
    push dword [hWnd]
    call [ShowWindow]

    ; Windows message loop
.message_loop:
    push 0
    lea eax, [msg]
    push eax
    push 0
    push 0
    call [GetMessage]
    test eax, eax
    jz .end_loop            ; If GetMessage returns 0, exit loop

    lea eax, [msg]
    push eax
    call [TranslateMessage]

    lea eax, [msg]
    push eax
    call [DispatchMessage]

    jmp .message_loop       ; Continue the message loop

.end_loop:
    ; Exit the message loop and the program
    ; msg.wParam will be loaded into eax which will be returned as the program exit status
    push    dword [msg+8]      ; Push wParam onto the stack, it serves as the exit code
    call    [ExitProcess]      ; Call ExitProcess to terminate the program.

; Data section to hold WNDCLASSEX and MSG structures
; The WNDCLASSEX structure holds information about the window class.
; The MSG structure holds message information from a thread's message queue.
section .data
wc      dd 48, 3Ch, 0, 0, 0, 0, 0, 0, 0, 0, offset class_name, 0, 0, 0
msg     dd 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

; This section is the Import section for user32.dll and kernel32.dll
section .idata import data readable writeable
    dd 0,0,0, RVA user_dll, RVA user_iat  ; Import descriptor for user32.dll
    dd 0,0,0, RVA kernel_dll, RVA kernel_iat  ; Import descriptor for kernel32.dll
    dd 0,0,0,0,0  ; Null-terminate the Import Descriptor table

; Import address table for user32.dll
section .idata import user_iat readable writeable
    dd RVA _RegisterClassEx  ; Relative Virtual Address of RegisterClassEx function
    dd RVA _CreateWindowEx   ; RVA of CreateWindowEx function
    dd RVA _ShowWindow       ; RVA of ShowWindow function
    dd RVA _GetMessage       ; RVA of GetMessage function
    dd RVA _TranslateMessage ; RVA of TranslateMessage function
    dd RVA _DispatchMessage  ; RVA of DispatchMessage function
    dd 0  ; Null-terminate the IAT

; Import address table for kernel32.dll
section .idata import kernel_iat readable writeable
    dd RVA _ExitProcess  ; RVA of ExitProcess function, used to terminate the program
    dd 0  ; Null-terminate the IAT

; WndProc is the Window Procedure function. It's called by the system to deliver
; window messages (events) to the window created by this application.
; It takes four parameters: hWnd, message, wParam, and lParam.
WndProc:
    ; Standard function prologue
    ; Save the old base pointer and set up a new base pointer
    push    ebp
    mov     ebp, esp

    ; Get the message code from the stack ([ebp+12]) and store it in eax
    mov     eax, [ebp+12]

    ; Compare message code to WM_CREATE (1)
    cmp     eax, 1
    je      .wm_create

    ; Compare message code to WM_DESTROY (2)
    cmp     eax, 2 
    je      .wm_destroy

    ; If neither, jump to default_case label
.default_case:
    ; Pass the message to the default window procedure
    push    dword [ebp+20]
    push    dword [ebp+16]
    push    dword [ebp+12]
    push    dword [ebp+8]
    call    [DefWindowProc]
    jmp     .end

    ; Case when the message is WM_CREATE
.wm_create:
    ; Set the return value to 0 to proceed with window creation
    mov     eax, 0
    jmp     .end

    ; Case when the message is WM_DESTROY
.wm_destroy:
    ; Post a quit message to terminate the message loop
    push    0
    push    0
    call    [PostQuitMessage]
    ; Set return value to 0
    xor     eax, eax

    ; Standard function epilogue
.end:
    ; Restore original base pointer and stack pointer
    mov     esp, ebp
    pop     ebp
    ; Return and remove arguments from the stack
    ret     16
