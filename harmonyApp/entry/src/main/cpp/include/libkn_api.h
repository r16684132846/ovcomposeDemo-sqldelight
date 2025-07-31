#ifndef KONAN_LIBKN_H
#define KONAN_LIBKN_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
typedef bool            libkn_KBoolean;
#else
typedef _Bool           libkn_KBoolean;
#endif
typedef unsigned short     libkn_KChar;
typedef signed char        libkn_KByte;
typedef short              libkn_KShort;
typedef int                libkn_KInt;
typedef long long          libkn_KLong;
typedef unsigned char      libkn_KUByte;
typedef unsigned short     libkn_KUShort;
typedef unsigned int       libkn_KUInt;
typedef unsigned long long libkn_KULong;
typedef float              libkn_KFloat;
typedef double             libkn_KDouble;
typedef float __attribute__ ((__vector_size__ (16))) libkn_KVector128;
typedef void*              libkn_KNativePtr;
struct libkn_KType;
typedef struct libkn_KType libkn_KType;

typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_Byte;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_Short;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_Int;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_Long;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_Float;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_Double;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_Char;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_Boolean;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_Unit;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_UByte;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_UShort;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_UInt;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_ULong;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_Greeting;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_Any;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_androidx_compose_runtime_snapshots_SnapshotStateList;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_LogBuffer;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_LeakTracker;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_collections_MutableList;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_kotlin_collections_List;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_RefManager;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_CallbackHolder;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_MemoryLogger;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_CallbackRegistry;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_LeakyCallbackHolder;
typedef struct {
  libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_ObjectTracker;

extern void androidx_compose_ui_arkui_ArkUIViewController_aboutToAppear(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_aboutToDisappear(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_cancelSyncRefresh(void* controllerRef, libkn_KInt refreshId);
extern void androidx_compose_ui_arkui_ArkUIViewController_dispatchHoverEvent(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_dispatchMouseEvent(void* controllerRef);
extern libkn_KBoolean androidx_compose_ui_arkui_ArkUIViewController_dispatchTouchEvent(void* controllerRef, void* nativeTouchEvent, libkn_KBoolean ignoreInteropView);
extern const char* androidx_compose_ui_arkui_ArkUIViewController_getId(void* controllerRef);
extern void* androidx_compose_ui_arkui_ArkUIViewController_getXComponentRender(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_keyboardWillHide(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_keyboardWillShow(void* controllerRef, libkn_KFloat keyboardHeight);
extern libkn_KBoolean androidx_compose_ui_arkui_ArkUIViewController_onBackPress(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_onFinalize(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_onFocusEvent(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_onFrame(void* controllerRef, libkn_KLong timestamp, libkn_KLong targetTimestamp);
extern void androidx_compose_ui_arkui_ArkUIViewController_onKeyEvent(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_onPageHide(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_onPageShow(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_onSurfaceChanged(void* controllerRef, libkn_KInt width, libkn_KInt height);
extern void androidx_compose_ui_arkui_ArkUIViewController_onSurfaceCreated(void* controllerRef, void* xcomponentPtr, libkn_KInt width, libkn_KInt height);
extern void androidx_compose_ui_arkui_ArkUIViewController_onSurfaceDestroyed(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_onSurfaceHide(void* controllerRef);
extern void androidx_compose_ui_arkui_ArkUIViewController_onSurfaceShow(void* controllerRef);
extern libkn_KInt androidx_compose_ui_arkui_ArkUIViewController_requestSyncRefresh(void* controllerRef);
extern const char* androidx_compose_ui_arkui_ArkUIViewController_sendMessage(void* controllerRef, const char* type, const char* message);
extern void androidx_compose_ui_arkui_ArkUIViewController_setContext(void* controllerRef, void* context);
extern void androidx_compose_ui_arkui_ArkUIViewController_setEnv(void* controllerRef, void* env);
extern void androidx_compose_ui_arkui_ArkUIViewController_setId(void* controllerRef, const char* id);
extern void androidx_compose_ui_arkui_ArkUIViewController_setMessenger(void* controllerRef, void* messenger);
extern void androidx_compose_ui_arkui_ArkUIViewController_setRootView(void* controllerRef, void* backRootView, void* foreRootView, void* touchableRootView);
extern void androidx_compose_ui_arkui_ArkUIViewController_setUIContext(void* controllerRef, void* uiContext);
extern void androidx_compose_ui_arkui_ArkUIViewController_setXComponentRender(void* controllerRef, void* render);
extern void androidx_compose_ui_arkui_init(void* env, void* exports);
extern void define_string_function(void* env, void* exports);
extern void kotlin_callback(libkn_KInt data, void* handler);
extern libkn_KInt kotlin_function(libkn_KInt input);
extern void* MainArkUIViewController(void* env);

typedef struct {
  /* Service functions. */
  void (*DisposeStablePointer)(libkn_KNativePtr ptr);
  void (*DisposeString)(const char* string);
  libkn_KBoolean (*IsInstance)(libkn_KNativePtr ref, const libkn_KType* type);
  libkn_kref_kotlin_Byte (*createNullableByte)(libkn_KByte);
  libkn_KByte (*getNonNullValueOfByte)(libkn_kref_kotlin_Byte);
  libkn_kref_kotlin_Short (*createNullableShort)(libkn_KShort);
  libkn_KShort (*getNonNullValueOfShort)(libkn_kref_kotlin_Short);
  libkn_kref_kotlin_Int (*createNullableInt)(libkn_KInt);
  libkn_KInt (*getNonNullValueOfInt)(libkn_kref_kotlin_Int);
  libkn_kref_kotlin_Long (*createNullableLong)(libkn_KLong);
  libkn_KLong (*getNonNullValueOfLong)(libkn_kref_kotlin_Long);
  libkn_kref_kotlin_Float (*createNullableFloat)(libkn_KFloat);
  libkn_KFloat (*getNonNullValueOfFloat)(libkn_kref_kotlin_Float);
  libkn_kref_kotlin_Double (*createNullableDouble)(libkn_KDouble);
  libkn_KDouble (*getNonNullValueOfDouble)(libkn_kref_kotlin_Double);
  libkn_kref_kotlin_Char (*createNullableChar)(libkn_KChar);
  libkn_KChar (*getNonNullValueOfChar)(libkn_kref_kotlin_Char);
  libkn_kref_kotlin_Boolean (*createNullableBoolean)(libkn_KBoolean);
  libkn_KBoolean (*getNonNullValueOfBoolean)(libkn_kref_kotlin_Boolean);
  libkn_kref_kotlin_Unit (*createNullableUnit)(void);
  libkn_kref_kotlin_UByte (*createNullableUByte)(libkn_KUByte);
  libkn_KUByte (*getNonNullValueOfUByte)(libkn_kref_kotlin_UByte);
  libkn_kref_kotlin_UShort (*createNullableUShort)(libkn_KUShort);
  libkn_KUShort (*getNonNullValueOfUShort)(libkn_kref_kotlin_UShort);
  libkn_kref_kotlin_UInt (*createNullableUInt)(libkn_KUInt);
  libkn_KUInt (*getNonNullValueOfUInt)(libkn_kref_kotlin_UInt);
  libkn_kref_kotlin_ULong (*createNullableULong)(libkn_KULong);
  libkn_KULong (*getNonNullValueOfULong)(libkn_kref_kotlin_ULong);

  /* User functions. */
  struct {
    struct {
      struct {
        struct {
          struct {
            struct {
              struct {
                void (*_Export_ArkUIViewController_aboutToAppear)(void* controllerRef);
                void (*_Export_ArkUIViewController_aboutToDisappear)(void* controllerRef);
                void (*_Export_ArkUIViewController_cancelSyncRefresh)(void* controllerRef, libkn_KInt refreshId);
                void (*_Export_ArkUIViewController_dispatchHoverEvent)(void* controllerRef);
                void (*_Export_ArkUIViewController_dispatchMouseEvent)(void* controllerRef);
                libkn_KBoolean (*_Export_ArkUIViewController_dispatchTouchEvent)(void* controllerRef, void* nativeTouchEvent, libkn_KBoolean ignoreInteropView);
                const char* (*_Export_ArkUIViewController_getId)(void* controllerRef);
                void* (*_Export_ArkUIViewController_getXComponentRender)(void* controllerRef);
                void (*_Export_ArkUIViewController_keyboardWillHide)(void* controllerRef);
                void (*_Export_ArkUIViewController_keyboardWillShow)(void* controllerRef, libkn_KFloat keyboardHeight);
                libkn_KBoolean (*_Export_ArkUIViewController_onBackPress)(void* controllerRef);
                void (*_Export_ArkUIViewController_onFinalize)(void* controllerRef);
                void (*_Export_ArkUIViewController_onFocusEvent)(void* controllerRef);
                void (*_Export_ArkUIViewController_onFrame)(void* controllerRef, libkn_KLong timestamp, libkn_KLong targetTimestamp);
                void (*_Export_ArkUIViewController_onKeyEvent)(void* controllerRef);
                void (*_Export_ArkUIViewController_onPageHide)(void* controllerRef);
                void (*_Export_ArkUIViewController_onPageShow)(void* controllerRef);
                void (*_Export_ArkUIViewController_onSurfaceChanged)(void* controllerRef, libkn_KInt width, libkn_KInt height);
                void (*_Export_ArkUIViewController_onSurfaceCreated)(void* controllerRef, void* xcomponentPtr, libkn_KInt width, libkn_KInt height);
                void (*_Export_ArkUIViewController_onSurfaceDestroyed)(void* controllerRef);
                void (*_Export_ArkUIViewController_onSurfaceHide)(void* controllerRef);
                void (*_Export_ArkUIViewController_onSurfaceShow)(void* controllerRef);
                libkn_KInt (*_Export_ArkUIViewController_requestSyncRefresh)(void* controllerRef);
                const char* (*_Export_ArkUIViewController_sendMessage)(void* controllerRef, const char* type, const char* message);
                void (*_Export_ArkUIViewController_setContext)(void* controllerRef, void* context);
                void (*_Export_ArkUIViewController_setEnv)(void* controllerRef, void* env);
                void (*_Export_ArkUIViewController_setId)(void* controllerRef, const char* id);
                void (*_Export_ArkUIViewController_setMessenger)(void* controllerRef, void* messenger);
                void (*_Export_ArkUIViewController_setRootView)(void* controllerRef, void* backRootView, void* foreRootView, void* touchableRootView);
                void (*_Export_ArkUIViewController_setUIContext)(void* controllerRef, void* uiContext);
                void (*_Export_ArkUIViewController_setXComponentRender)(void* controllerRef, void* render);
                void (*_Export_ArkUIViewInitializer_init)(void* env, void* exports);
              } arkui;
            } ui;
          } export_;
        } compose;
      } androidx;
      struct {
        struct {
          struct {
            struct {
              libkn_KType* (*_type)(void);
              libkn_kref_com_tencent_compose_Greeting (*Greeting)();
              const char* (*greet)(libkn_kref_com_tencent_compose_Greeting thiz);
            } Greeting;
            struct {
              struct {
                libkn_KInt (*com_tencent_compose_sample_data_DisplayItem$stableprop_getter)();
                libkn_KInt (*com_tencent_compose_sample_data_DisplaySection$stableprop_getter)();
              } data;
              struct {
                struct {
                  struct {
                    libkn_KType* (*_type)(void);
                    libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData (*PieceData)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game game, libkn_KFloat velocity, libkn_KULong color);
                    libkn_KBoolean (*get_clicked)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);
                    void (*set_clicked)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz, libkn_KBoolean set);
                    libkn_KULong (*get_color)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);
                    libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game (*get_game)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);
                    libkn_KFloat (*get_position)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);
                    void (*set_position)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz, libkn_KFloat set);
                    libkn_KFloat (*get_velocity)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);
                    void (*click)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);
                    libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game (*component1)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);
                    libkn_KFloat (*component2)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);
                    libkn_KULong (*component3)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);
                    libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData (*copy)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz, libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game game, libkn_KFloat velocity, libkn_KULong color);
                    libkn_KBoolean (*equals)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz, libkn_kref_kotlin_Any other);
                    libkn_KInt (*hashCode)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);
                    const char* (*toString)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);
                    void (*update)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz, libkn_KLong dt);
                  } PieceData;
                  struct {
                    libkn_KType* (*_type)(void);
                    libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game (*Game)();
                    libkn_KLong (*get_elapsed)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);
                    void (*set_elapsed)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz, libkn_KLong set);
                    libkn_KBoolean (*get_finished)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);
                    void (*set_finished)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz, libkn_KBoolean set);
                    libkn_KFloat (*get_height)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);
                    void (*set_height)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz, libkn_KFloat set);
                    libkn_KFloat (*get_numBlocks)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);
                    void (*set_numBlocks)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz, libkn_KFloat set);
                    libkn_KBoolean (*get_paused)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);
                    void (*set_paused)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz, libkn_KBoolean set);
                    libkn_kref_androidx_compose_runtime_snapshots_SnapshotStateList (*get_pieces)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);
                    libkn_KInt (*get_score)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);
                    void (*set_score)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz, libkn_KInt set);
                    libkn_KBoolean (*get_started)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);
                    void (*set_started)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz, libkn_KBoolean set);
                    libkn_KFloat (*get_width)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);
                    void (*set_width)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz, libkn_KFloat set);
                    void (*clicked)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz, libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData piece);
                    void (*start)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);
                    void (*update)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz, libkn_KLong deltaTimeNanos);
                  } Game;
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter_)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter_)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter_)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter__)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter__)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter__)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter___)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter___)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter___)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter____)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter____)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter____)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter_____)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter_____)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter_____)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter______)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter______)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter______)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter_______)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter_______)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter_______)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter_________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter_________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter_________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter__________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter__________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter__________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter___________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter___________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter___________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter____________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter____________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter____________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter_____________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter_____________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter_____________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter______________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter______________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter______________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter_______________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter_______________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter_______________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter________________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter________________)();
                  libkn_KInt (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter________________)();
                } sectionItem;
              } mainpage;
              struct {
                libkn_KType* (*_type)(void);
                libkn_kref_com_tencent_compose_sample_LogBuffer (*_instance)();
                libkn_kref_androidx_compose_runtime_snapshots_SnapshotStateList (*get_logs)(libkn_kref_com_tencent_compose_sample_LogBuffer thiz);
                void (*clear)(libkn_kref_com_tencent_compose_sample_LogBuffer thiz);
                void (*log)(libkn_kref_com_tencent_compose_sample_LogBuffer thiz, const char* msg);
              } LogBuffer;
              struct {
                libkn_KType* (*_type)(void);
                libkn_kref_com_tencent_compose_sample_LeakTracker (*_instance)();
                libkn_kref_kotlin_collections_MutableList (*get_holders)(libkn_kref_com_tencent_compose_sample_LeakTracker thiz);
                libkn_kref_kotlin_collections_List (*collectStatus)(libkn_kref_com_tencent_compose_sample_LeakTracker thiz);
              } LeakTracker;
              struct {
                libkn_KType* (*_type)(void);
                libkn_kref_com_tencent_compose_sample_RefManager (*_instance)();
                void (*disposeAll)(libkn_kref_com_tencent_compose_sample_RefManager thiz);
                void (*register_)(libkn_kref_com_tencent_compose_sample_RefManager thiz, void* ref);
              } RefManager;
              struct {
                libkn_KType* (*_type)(void);
                libkn_kref_com_tencent_compose_sample_CallbackHolder (*CallbackHolder)(const char* name);
                const char* (*get_name)(libkn_kref_com_tencent_compose_sample_CallbackHolder thiz);
                void (*finalize)(libkn_kref_com_tencent_compose_sample_CallbackHolder thiz);
                void (*onResult)(libkn_kref_com_tencent_compose_sample_CallbackHolder thiz, libkn_KInt x);
              } CallbackHolder;
              struct {
                libkn_KType* (*_type)(void);
                libkn_kref_com_tencent_compose_sample_MemoryLogger (*_instance)();
                libkn_kref_androidx_compose_runtime_snapshots_SnapshotStateList (*get_logs)(libkn_kref_com_tencent_compose_sample_MemoryLogger thiz);
                void (*clear)(libkn_kref_com_tencent_compose_sample_MemoryLogger thiz);
                void (*log)(libkn_kref_com_tencent_compose_sample_MemoryLogger thiz, const char* msg);
              } MemoryLogger;
              struct {
                libkn_KType* (*_type)(void);
                libkn_kref_com_tencent_compose_sample_CallbackRegistry (*_instance)();
                void (*clear)(libkn_kref_com_tencent_compose_sample_CallbackRegistry thiz);
                libkn_KInt (*getActiveCount)(libkn_kref_com_tencent_compose_sample_CallbackRegistry thiz);
                libkn_kref_com_tencent_compose_sample_LeakyCallbackHolder (*getCallback)(libkn_kref_com_tencent_compose_sample_CallbackRegistry thiz, const char* id);
                void (*register_)(libkn_kref_com_tencent_compose_sample_CallbackRegistry thiz, const char* id, libkn_kref_com_tencent_compose_sample_LeakyCallbackHolder holder);
                void (*remove)(libkn_kref_com_tencent_compose_sample_CallbackRegistry thiz, const char* id);
              } CallbackRegistry;
              struct {
                libkn_KType* (*_type)(void);
                libkn_kref_com_tencent_compose_sample_ObjectTracker (*_instance)();
                void (*checkStatus)(libkn_kref_com_tencent_compose_sample_ObjectTracker thiz);
                void (*reset)(libkn_kref_com_tencent_compose_sample_ObjectTracker thiz);
                void (*track)(libkn_kref_com_tencent_compose_sample_ObjectTracker thiz, libkn_kref_com_tencent_compose_sample_LeakyCallbackHolder obj);
              } ObjectTracker;
              struct {
                libkn_KType* (*_type)(void);
                libkn_kref_com_tencent_compose_sample_LeakyCallbackHolder (*LeakyCallbackHolder)(const char* id);
                const char* (*get_id)(libkn_kref_com_tencent_compose_sample_LeakyCallbackHolder thiz);
                void (*cleanupOnlyRegistry)(libkn_kref_com_tencent_compose_sample_LeakyCallbackHolder thiz);
                void (*dispose)(libkn_kref_com_tencent_compose_sample_LeakyCallbackHolder thiz);
                void (*finalize)(libkn_kref_com_tencent_compose_sample_LeakyCallbackHolder thiz);
                void (*handleCallback)(libkn_kref_com_tencent_compose_sample_LeakyCallbackHolder thiz, const char* data);
                void (*partialDispose)(libkn_kref_com_tencent_compose_sample_LeakyCallbackHolder thiz);
                void (*registerToC)(libkn_kref_com_tencent_compose_sample_LeakyCallbackHolder thiz, libkn_KBoolean createCircularRef);
              } LeakyCallbackHolder;
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter_)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter_)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter_)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter_)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter_)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter_)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter_)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter_)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter__)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter__)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter__)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter__)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter__)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter__)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter__)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter__)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter___)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter___)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter___)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter___)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter___)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter___)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter___)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter___)();
              void (*forceGC)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter____)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter____)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter____)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter____)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter____)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter____)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter____)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter____)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter_____)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter_____)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter_____)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter_____)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter_____)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter_____)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter_____)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter_____)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter______)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter______)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter______)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter______)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter______)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter______)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter______)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter______)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter_______)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter_______)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter_______)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter_______)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter_______)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter_______)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter_______)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter_______)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter_________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter_________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter_________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter_________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter_________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter_________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter_________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter_________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter__________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter__________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter__________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter__________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter__________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter__________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter__________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter__________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter___________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter___________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter___________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter___________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter___________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter___________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter___________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter___________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter____________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter____________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter____________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter____________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter____________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter____________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter____________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter____________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter_____________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter_____________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter_____________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter_____________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter_____________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter_____________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter_____________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter_____________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter______________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter______________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter______________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter______________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter______________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter______________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter______________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter______________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter_______________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter_______________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter_______________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter_______________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter_______________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter_______________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter_______________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter_______________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter________________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter________________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter________________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter________________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter________________)();
              void* (*get_nativeResourceManager)();
              void (*set_nativeResourceManager)(void* set);
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter_________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter_________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter_________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter_________________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter_________________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter_________________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter_________________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter_________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter__________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter__________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter__________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter__________________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter__________________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter__________________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter__________________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter__________________)();
              void (*testMemScoped)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter___________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter___________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter___________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter___________________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter___________________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter___________________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter___________________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter___________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter____________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter____________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter____________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter____________________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter____________________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter____________________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter____________________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter____________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter_____________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter_____________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter_____________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter_____________________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter_____________________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter_____________________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter_____________________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter_____________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter______________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter______________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter______________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter______________________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter______________________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter______________________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter______________________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter______________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter_______________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter_______________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter_______________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter_______________________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter_______________________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter_______________________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter_______________________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter_______________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter________________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter________________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter________________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter________________________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter________________________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter________________________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter________________________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter________________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackHolder$stableprop_getter_________________________)();
              libkn_KInt (*com_tencent_compose_sample_CallbackRegistry$stableprop_getter_________________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakTracker$stableprop_getter_________________________)();
              libkn_KInt (*com_tencent_compose_sample_LeakyCallbackHolder$stableprop_getter_________________________)();
              libkn_KInt (*com_tencent_compose_sample_LogBuffer$stableprop_getter_________________________)();
              libkn_KInt (*com_tencent_compose_sample_MemoryLogger$stableprop_getter_________________________)();
              libkn_KInt (*com_tencent_compose_sample_ObjectTracker$stableprop_getter_________________________)();
              libkn_KInt (*com_tencent_compose_sample_RefManager$stableprop_getter_________________________)();
            } sample;
            struct {
              const char* (*get_TestString)();
              void (*defineStringFunction)(void* env, void* exports);
              void (*kn_string_params)(const char* a);
              const char* (*kn_string_result)();
              void* (*createString)(const char* value);
              const char* (*asString)(void* thiz);
              const char* (*asStringUtf8)(void* thiz);
            } utils;
            libkn_KInt (*com_tencent_compose_Greeting$stableprop_getter)();
            libkn_KInt (*com_tencent_compose_OHOSPlatform$stableprop_getter)();
            libkn_KInt (*com_tencent_compose_Greeting$stableprop_getter_)();
            libkn_KInt (*com_tencent_compose_OHOSPlatform$stableprop_getter_)();
            libkn_KInt (*com_tencent_compose_Greeting$stableprop_getter__)();
            libkn_KInt (*com_tencent_compose_OHOSPlatform$stableprop_getter__)();
            void (*callback)(libkn_KInt data, void* handler);
            libkn_KInt (*com_tencent_compose_Greeting$stableprop_getter___)();
            libkn_KInt (*com_tencent_compose_OHOSPlatform$stableprop_getter___)();
            libkn_KInt (*kotlinFunction)(libkn_KInt input);
            void* (*MainArkUIViewController_)(void* env);
            libkn_KInt (*com_tencent_compose_Greeting$stableprop_getter____)();
            libkn_KInt (*com_tencent_compose_OHOSPlatform$stableprop_getter____)();
            void (*initResourceManager)(void* resourceManager);
            libkn_KInt (*com_tencent_compose_Greeting$stableprop_getter_____)();
            libkn_KInt (*com_tencent_compose_OHOSPlatform$stableprop_getter_____)();
          } compose;
        } tencent;
      } com;
      struct {
        struct {
          struct {
            struct {
              libkn_KInt (*composesample_composeapp_generated_resources_Res$stableprop_getter)();
              libkn_KInt (*composesample_composeapp_generated_resources_Res_drawable$stableprop_getter)();
              libkn_KInt (*composesample_composeapp_generated_resources_Res_font$stableprop_getter)();
              libkn_KInt (*composesample_composeapp_generated_resources_Res_string$stableprop_getter)();
              libkn_KInt (*composesample_composeapp_generated_resources_Res$stableprop_getter_)();
              libkn_KInt (*composesample_composeapp_generated_resources_Res_drawable$stableprop_getter_)();
              libkn_KInt (*composesample_composeapp_generated_resources_Res_font$stableprop_getter_)();
              libkn_KInt (*composesample_composeapp_generated_resources_Res_string$stableprop_getter_)();
            } resources;
          } generated;
        } composeapp;
      } composesample;
    } root;
  } kotlin;
} libkn_ExportedSymbols;
extern libkn_ExportedSymbols* libkn_symbols(void);
#ifdef __cplusplus
}  /* extern "C" */
#endif
#endif  /* KONAN_LIBKN_H */
