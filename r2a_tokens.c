RLAPI                       ASCAPI
raylib.h                    ascede.h
RAYLIB                      ASCEDE
MemAlloc                    Mem_Alloc
MemRealloc                  Mem_Realloc
MemFree                     Mem_Free
InitWindow                  Window_Init
CloseWindow                 Window_Close
WindowShouldClose           Window_ShouldClose
IsWindowReady               Window_IsReady
IsWindowFullscreen          Window_IsFullscreen
IsWindowHidden              Window_IsHidden
IsWindowMinimized           Window_IsMinimized
IsWindowMaximized           Window_IsMaximized
IsWindowFocused             Window_IsFocused
IsWindowResized             Window_IsResized
IsWindowState               Window_GetFlags
SetWindowState              Window_SetFlags
ClearWindowState            Window_ClearFlags
ToggleFullscreen            Window_ToggleFullscreen
MaximizeWindow              Window_Maximize
MinimizeWindow              Window_Minimize
RestoreWindow               Window_Restore
SetWindowIcon               Window_SetIcon
SetWindowTitle              Window_SetTitle
SetWindowPosition           Window_SetPos
GetWindowPosition           Window_GetPos
GetWindowScaleDPI           Window_GetDPI
SetWindowMonitor            Window_SetMonitor
SetWindowMinSize            Window_SetMinsize
SetWindowSize               Window_SetSize
SetWindowOpacity            Window_SetOpacity
GetWindowHandle             Window_GetHandle
GetScreenWidth              Window_GetScreenWidth
GetScreenHeight             Window_GetScreenHeight
GetRenderWidth              Window_GetRenderWidth
GetRenderHeight             Window_GetRenderHeight
GetCurrentMonitor           Monitor_Get
GetMonitorCount             Monitor_Count
GetMonitorPosition          Monitor_GetPos
GetMonitorWidth             Monitor_GetWidth
GetMonitorHeight            Monitor_GetHeight
GetMonitorPhysicalWidth     Monitor_GetPhysicalWidth
GetMonitorPhysicalHeight    Monitor_GetPhysicalHeight
GetMonitorRefreshRate       Monitor_GetRefreshRate
GetMonitorName              Monitor_GetName
SetClipboardText            Clipboard_Set
GetClipboardText            Clipboard_Get
ShowCursor                  Cursor_Show
HideCursor                  Cursor_Hide
IsCursorHidden              Cursor_IsHidden
EnableCursor                Cursor_Enable
DisableCursor               Cursor_Disable
IsCursorOnScreen            Cursor_IsOnScreen
ClearBackground             Buffer_Clear
BeginDrawing                Buffer_Begin
EndDrawing                  Buffer_Update
BeginTextureMode            RenderTexture_Begin
EndTextureMode              RenderTexture_Update
BeginShaderMode             Shader_Begin
EndShaderMode               Shader_Update
BeginBlendMode              Buffer_BeginBlend
EndBlendMode                Buffer_UpdateBlend
BeginScissorMode            Buffer_BeginScissor
EndScissorMode              Buffer_EndScissor
LoadShader                  Shader_Load
LoadShaderFromMemory        Shader_LoadData
GetShaderLocation           Shader_GetLoc
GetShaderLocationAttrib     Shader_GetLocAttrib
SetShaderValue              Shader_SetValue
SetShaderValueV             Shader_SetValueV
SetShaderValueMatrix        Shader_SetValueMatrix
SetShaderValueTexture       Shader_SetValueTexture
UnloadShader                Shader_Free
SetConfigFlags              Window_PresetFlags
Tracelog                    TraceLog
SetTraceLogLevel            TraceLog_SetLevel
SetTracelogLevel            TraceLog_SetLevel
SetTraceLogCallback         Callback_SetTraceLog
SetLoadFileDataCallback     Callback_SetLoadFileData
SetSaveFileDataCallback     Callback_SetSaveFileData
SetLoadFileTextCallback     Callback_SetLoadFileText
SetSaveFileTextCallback     Callback_SetSaveFileText
LoadFileData                File_Load
UnloadFileData              File_Free
SaveFileData                File_Save
ExportDataAsCode            File_SaveAsCode
LoadFileText                File_LoadStr
UnloadFileText              File_FreeStr
SaveFileText                File_SaveStr
FileExists                  File_Exists
DirectoryExists             File_DirExists
IsFileExtension             File_IsExt
GetFileLength               File_GetSize
GetFileExtension            File_GetExt
GetFileModTime              File_GetModTime
GetFileName                 File_GetName
GetFileNameWithoutExt       File_GetNameNX
GetDirectoryPath            File_GetDir
GetPrevDirectoryPath        File_GetDirPrev
GetWorkingDirectory         File_GetWoringDir
GetApplicationDirectory     File_GetDirApp
ChangeDirectory             File_ChangeDir
IsPathFile                  File_IsFile
GetDirectoryFiles           File_LoadDirFileList
LoadDirectoryFiles          File_LoadDirFileList
LoadDirectoryFilesEx        File_LoadDirFileListEx
ClearDirectoryFiles         File_FreeDirFileList
UnloadDirectoryFiles        File_FreeDirFileList
IsFileDropped               File_IsDropped
GetDroppedFiles             File_GetDroppedList
LoadDroppedFiles            File_GetDroppedList
ClearDroppedFiles           File_FreeDroppedList
UnloadDroppedFiles          File_FreeDroppedList
IsKeyPressed                Key_IsPressed
IsKeyDown                   Key_IsDown
IsKeyReleased               Key_IsReleased
IsKeyUp                     Key_IsUp
SetExitKey                  Key_SetExitHotkey
GetKeyPressed               Key_Get
GetCharPressed              Key_GetChar
IsGamepadAvailable          Gamepad_IsAvailable
GetGamepadName              Gamepad_GetName
IsGamepadName               Gamepad_IsName
IsGamepadButtonPressed      Gamepad_IsPressed
IsGamepadButtonReleased     Gamepad_IsReleased
IsGamepadButtonUp           Gamepad_IsUp
IsGamepadButtonDown         Gamepad_IsDown
GetGamepadButtonPressed     Gamepad_GetPressed
GetGamepadAxisCount         Gamepad_CountAxis
GetGamepadAxisMovement      Gamepad_GetAxisMovement
SetGamepadMappings          Gamepad_SetMappings
IsMouseButtonPressed        Mouse_IsPressed
IsMouseButtonReleased       Mouse_IsReleased
IsMouseButtonDown           Mouse_IsDown
IsMouseButtonUp             Mouse_IsUp
GetMouseX                   Mouse_GetX
GetMouseY                   Mouse_GetY
GetMousePosition            Mouse_GetPos
GetMouseDelta               Mouse_GetDelta
SetMousePosition            Mouse_SetPos
SetMouseOffset              Mouse_SetOffset
SetMouseScale               Mouse_SetScale
GetMouseWheelMove           Mouse_GetWheelDelta
GetMouseWheelMoveV          Mouse_GetWheelDeltaV
SetMouseCursor              Mouse_SetCursor
GetTouchX                   Touch_GetX
GetTouchY                   Touch_GetY
GetTouchPosition            Touch_GetPos
GetTouchPointId             Touch_GetID
GetTouchPointsCount         Touch_Count
GetTouchPointCount          Touch_Count
SetGesturesEnabled          Gesture_SetFlags
IsGestureDetected           Gesture_IsPerformed
GetGestureDetected          Gesture_Get
GetGestureHoldDuration      Gesture_GetDuration
GetGestureDragVector        Gesture_GetDragV
GetGestureDragAngle         Gesture_GetDragAngle
GetGesturePinchVector       Gesture_GetPinchV
GetGesturePinchAngle        Getsure_GetPinchAngle
SetShapesTexture            Shape_SetTexture
DrawLine                    Shape_DrawLine
DrawLineV                   Shape_DrawLineV
DrawLineEx                  Shape_DrawLineEx
DrawRectangle               Shape_DrawRec
DrawRectangleV              Shape_DrawRecV
DrawRectangleRec            Shape_DrawRecRec
DrawRectanglePro            Shape_DrawRecPro
DrawTriangle                Shape_DrawTriangle
DrawPoly                    Shape_DrawPoly
CheckCollisionRecs          Collision_CheckRecs
CheckCollisionPointRec      Collision_CheckPointRec
LoadImage                   Image_Load
LoadImageRaw                Image_LoadRaw
LoadImageAnim               Image_LoadAnim
LoadImageFromMemory         Image_LoadMem
LoadImageFromTexture        Image_LoadFromTexture
LoadImageFromScreen         Image_Screenshot
UnloadImage                 Image_Free
ExportImage                 Image_Export
ExportImageAsCode           Image_ExportAsCode
GenImageColor               Image_Gen
ImageCopy                   Image_Copy
ImageFromImage              Image_FromImage
ImageText                   Image_FromText
ImageTextEx                 Image_FromTextEx
ImageFormat                 Image_SetFormat
ImageToPOT                  Image_ToPOT
ImageCrop                   Image_Crop
ImageAlphaCrop              Image_AlphaCrop
ImageAlphaClear             Image_AlphaClear
ImageAlphaMask              Image_AlphaMask
ImageAlphaPremultiply       Image_AlphaPremultiply
ImageResize                 Image_Resize
ImageResizeNN               Image_ResizeNN
ImageResizeCanvas           Image_ResizeCanvas
ImageMipmaps                Image_GenMipmaps
ImageDither                 Image_Dither
ImageFlipVertical           Image_FlipV
ImageFlipHorizontal         Image_FlipH
ImageRotateCW               Image_Rotate
ImageRotateCCW              Image_RotateCCW
ImageColorTint              Image_Tint
ImageColorInvert            Image_InvertColor
ImageColorGrayscale         Image_Grayscale
ImageColorContrast          Image_SetContrast
ImageColorBrightness        Image_SetBrightness
ImageColorReplace           Image_ColorReplace
LoadImageColors             Image_LoadColors
LoadImagePalette            Image_LoadPalette
UnloadImageColors           Image_FreeColors
UnloadImagePalette          Image_FreePalette
GetImageColor               Image_GetPixelColor
GetImageAlphaBorder         Image_GetAlphaBorder
ImageClearBackground        ImageBuffer_Clear
ImageDrawPixel              ImageBuffer_DrawPixel
ImageDrawPixelV             ImageBuffer_DrawPixelV
ImageDrawLine               ImageBuffer_DrawLine
ImageDrawLineV              ImageBuffer_DrawLineV
ImageDrawCircle             ImageBuffer_DrawCircle
ImageDrawCircleV            ImageBuffer_DrawCircleV
ImageDrawRectangle          ImageBuffer_DrawRec
ImageDrawRectangleV         ImageBuffer_DrawRecV
ImageDrawRectangleRec       ImageBuffer_DrawRecRec
ImageDraw                   ImageBuffer_DrawImage
ImageDrawText               ImageBuffer_DrawText
ImageDrawTextEx             ImageBuffer_DrawTextEx
LoadTexture                 Texture_Load
LoadTextureFromImage        Texture_LoadFromImage
LoadTextureCubemap          Texture_LoadCubemap
LoadRenderTexture           RenderTexture_Create
UnloadTexture               Texture_Free
UnloadRenderTexture         RenderTexture_Free
UpdateTexture               Texture_Update
UpdateTextureRec            Texture_UpdateRec
GenTextureMipmaps           Texture_GenMipmaps
SetTextureFilter            Texture_SetFilter
SetTextureWrap              Texture_SetWrap
DrawTexture                 Texture_Draw
DrawTextureV                Texture_DrawV
DrawTextureEx               Texture_DrawEx
DrawTextureRec              Texture_DrawRec
DrawTexturePro              Texture_DrawPro
Fade                        Color_Fade
ColorToInt                  Color_GetCode
ColorToHSV                  Color_ToHSV
ColorFromHSV                Color_FromHSV
ColorAlphaBlend             Color_AlphaBlend
GetPixelColor               Color_GetPixel
SetPixelColor               Color_SetPixel
GetPixelDataSize            Color_GetPixelDataSize
GetFontDefault              Font_GetDefault
LoadFont                    Font_Load
LoadFontEx                  Font_LoadEx
LoadFontFromImage           Font_LoadFromImage
LoadFontFromMemory          Font_LoadMem
LoadFontData                Glyph_LoadInfo
GenImageFontAtlas           Font_GenAtlas
UnloadFontData              Glyph_UnloadInfo
UnloadFont                  Font_Free
ExportFontAsCode            Font_ExportAsCode
DrawText                    Text_Draw
DrawTextEx                  Text_DrawEx
DrawTextPro                 Text_DrawPro
DrawTextCodepoint           Text_DrawCodepoint
DrawTextCodepoints          Text_DrawCodepoints
MeasureText                 Text_GetWidth
MeasureTextEx               Text_GetWidthEx
GetGlyphIndex               Glyph_GetIndex
GetGlyphInfo                Glyph_Get
GetGlyphAtlasRec            Glyph_GetAtlas
LoadCodepoints              Text_LoadCodepoints
UnloadCodepoints            Text_FreeCodepoints
GetCodepointCount           Text_CountCodepoints
GetCodepointsCount          Text_CountCodepoints
GetCodepoint                Text_GetCodepoint
TextFormat                  Text_Format
TextReplace                 Text_Replace