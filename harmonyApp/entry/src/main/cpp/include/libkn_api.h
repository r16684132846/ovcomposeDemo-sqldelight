#ifndef KONAN_LIBKN_H
#define KONAN_LIBKN_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
typedef bool            libkn_KBoolean;
#else
typedef _Bool libkn_KBoolean;
#endif
typedef unsigned short libkn_KChar;
typedef signed char libkn_KByte;
typedef short libkn_KShort;
typedef int libkn_KInt;
typedef long long libkn_KLong;
typedef unsigned char libkn_KUByte;
typedef unsigned short libkn_KUShort;
typedef unsigned int libkn_KUInt;
typedef unsigned long long libkn_KULong;
typedef float libkn_KFloat;
typedef double libkn_KDouble;
typedef float __attribute__ ((__vector_size__ (16))) libkn_KVector128;
typedef void *libkn_KNativePtr;
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
} libkn_kref_kotlinx_serialization_json_Json;
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
} libkn_kref_com_tencent_compose_sample_mainpage_Test1;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_mainpage_Test1_$serializer;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_kotlinx_serialization_descriptors_SerialDescriptor;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_kotlin_Array;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_kotlinx_serialization_encoding_Decoder;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_kotlinx_serialization_encoding_Encoder;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_mainpage_Test1_Companion;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_kotlinx_serialization_KSerializer;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_KsoupTest;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_WebViewTest;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_Person;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_Person_$serializer;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_Person_Companion;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_XmlUtilTest;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sample_XmlUtilTest_Companion;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_service_FileItem;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_kotlinx_datetime_Instant;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_service_FileInfo;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_app_cash_sqldelight_db_SqlDriver;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_AppDatabase;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_PlayerQueries;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_TeamQueries;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_AppDatabase_Companion;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_app_cash_sqldelight_db_SqlSchema;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_Player_Adapter;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_Team_Adapter;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_ForTeam;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_Player;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_kotlinx_datetime_LocalDate;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_app_cash_sqldelight_ColumnAdapter;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_app_cash_sqldelight_Query;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_SelectAll;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_Team;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_DateAdapter;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_PlayerVals;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots_RIGHT;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots_LEFT;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position_LEFT_WING;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position_RIGHT_WING;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position_CENTER;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position_DEFENSE;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position_GOALIE;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_Schema;
typedef struct {
    libkn_KNativePtr pinned;
} libkn_kref_com_tencent_compose_sqldelight_Db;

extern void androidx_compose_ui_arkui_ArkUIViewController_aboutToAppear(void *controllerRef);

extern void androidx_compose_ui_arkui_ArkUIViewController_aboutToDisappear(void *controllerRef);

extern void androidx_compose_ui_arkui_ArkUIViewController_cancelSyncRefresh(void *controllerRef,
                                                                            libkn_KInt refreshId);

extern void androidx_compose_ui_arkui_ArkUIViewController_dispatchHoverEvent(void *controllerRef);

extern void androidx_compose_ui_arkui_ArkUIViewController_dispatchMouseEvent(void *controllerRef);

extern libkn_KBoolean
androidx_compose_ui_arkui_ArkUIViewController_dispatchTouchEvent(void *controllerRef,
                                                                 void *nativeTouchEvent,
                                                                 libkn_KBoolean ignoreInteropView);

extern const char *androidx_compose_ui_arkui_ArkUIViewController_getId(void *controllerRef);

extern void *androidx_compose_ui_arkui_ArkUIViewController_getXComponentRender(void *controllerRef);

extern void androidx_compose_ui_arkui_ArkUIViewController_keyboardWillHide(void *controllerRef);

extern void androidx_compose_ui_arkui_ArkUIViewController_keyboardWillShow(void *controllerRef,
                                                                           libkn_KFloat keyboardHeight);

extern libkn_KBoolean
androidx_compose_ui_arkui_ArkUIViewController_onBackPress(void *controllerRef);

extern void androidx_compose_ui_arkui_ArkUIViewController_onFinalize(void *controllerRef);

extern void androidx_compose_ui_arkui_ArkUIViewController_onFocusEvent(void *controllerRef);

extern void
androidx_compose_ui_arkui_ArkUIViewController_onFrame(void *controllerRef, libkn_KLong timestamp,
                                                      libkn_KLong targetTimestamp);

extern void androidx_compose_ui_arkui_ArkUIViewController_onKeyEvent(void *controllerRef);

extern void androidx_compose_ui_arkui_ArkUIViewController_onPageHide(void *controllerRef);

extern void androidx_compose_ui_arkui_ArkUIViewController_onPageShow(void *controllerRef);

extern void androidx_compose_ui_arkui_ArkUIViewController_onSurfaceChanged(void *controllerRef,
                                                                           libkn_KInt width,
                                                                           libkn_KInt height);

extern void androidx_compose_ui_arkui_ArkUIViewController_onSurfaceCreated(void *controllerRef,
                                                                           void *xcomponentPtr,
                                                                           libkn_KInt width,
                                                                           libkn_KInt height);

extern void androidx_compose_ui_arkui_ArkUIViewController_onSurfaceDestroyed(void *controllerRef);

extern void androidx_compose_ui_arkui_ArkUIViewController_onSurfaceHide(void *controllerRef);

extern void androidx_compose_ui_arkui_ArkUIViewController_onSurfaceShow(void *controllerRef);

extern libkn_KInt
androidx_compose_ui_arkui_ArkUIViewController_requestSyncRefresh(void *controllerRef);

extern const char *
androidx_compose_ui_arkui_ArkUIViewController_sendMessage(void *controllerRef, const char *type,
                                                          const char *message);

extern void
androidx_compose_ui_arkui_ArkUIViewController_setContext(void *controllerRef, void *context);

extern void androidx_compose_ui_arkui_ArkUIViewController_setEnv(void *controllerRef, void *env);

extern void
androidx_compose_ui_arkui_ArkUIViewController_setId(void *controllerRef, const char *id);

extern void
androidx_compose_ui_arkui_ArkUIViewController_setMessenger(void *controllerRef, void *messenger);

extern void
androidx_compose_ui_arkui_ArkUIViewController_setRootView(void *controllerRef, void *backRootView,
                                                          void *foreRootView,
                                                          void *touchableRootView);

extern void
androidx_compose_ui_arkui_ArkUIViewController_setUIContext(void *controllerRef, void *uiContext);

extern void androidx_compose_ui_arkui_ArkUIViewController_setXComponentRender(void *controllerRef,
                                                                              void *render);

extern void androidx_compose_ui_arkui_init(void *env, void *exports);

extern void *MainArkUIViewController(void *env);

typedef struct {
    /* Service functions. */
    void (*DisposeStablePointer)(libkn_KNativePtr ptr);

    void (*DisposeString)(const char *string);

    libkn_KBoolean (*IsInstance)(libkn_KNativePtr ref, const libkn_KType *type);

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
                                void
                                (*_Export_ArkUIViewController_aboutToAppear)(void *controllerRef);

                                void (*_Export_ArkUIViewController_aboutToDisappear)(
                                        void *controllerRef);

                                void (*_Export_ArkUIViewController_cancelSyncRefresh)(
                                        void *controllerRef, libkn_KInt refreshId);

                                void (*_Export_ArkUIViewController_dispatchHoverEvent)(
                                        void *controllerRef);

                                void (*_Export_ArkUIViewController_dispatchMouseEvent)(
                                        void *controllerRef);

                                libkn_KBoolean (*_Export_ArkUIViewController_dispatchTouchEvent)(
                                        void *controllerRef, void *nativeTouchEvent,
                                        libkn_KBoolean ignoreInteropView);

                                const char *
                                (*_Export_ArkUIViewController_getId)(void *controllerRef);

                                void *(*_Export_ArkUIViewController_getXComponentRender)(
                                        void *controllerRef);

                                void (*_Export_ArkUIViewController_keyboardWillHide)(
                                        void *controllerRef);

                                void
                                (*_Export_ArkUIViewController_keyboardWillShow)(void *controllerRef,
                                                                                libkn_KFloat keyboardHeight);

                                libkn_KBoolean
                                (*_Export_ArkUIViewController_onBackPress)(void *controllerRef);

                                void (*_Export_ArkUIViewController_onFinalize)(void *controllerRef);

                                void
                                (*_Export_ArkUIViewController_onFocusEvent)(void *controllerRef);

                                void (*_Export_ArkUIViewController_onFrame)(void *controllerRef,
                                                                            libkn_KLong timestamp,
                                                                            libkn_KLong targetTimestamp);

                                void (*_Export_ArkUIViewController_onKeyEvent)(void *controllerRef);

                                void (*_Export_ArkUIViewController_onPageHide)(void *controllerRef);

                                void (*_Export_ArkUIViewController_onPageShow)(void *controllerRef);

                                void
                                (*_Export_ArkUIViewController_onSurfaceChanged)(void *controllerRef,
                                                                                libkn_KInt width,
                                                                                libkn_KInt height);

                                void
                                (*_Export_ArkUIViewController_onSurfaceCreated)(void *controllerRef,
                                                                                void *xcomponentPtr,
                                                                                libkn_KInt width,
                                                                                libkn_KInt height);

                                void (*_Export_ArkUIViewController_onSurfaceDestroyed)(
                                        void *controllerRef);

                                void
                                (*_Export_ArkUIViewController_onSurfaceHide)(void *controllerRef);

                                void
                                (*_Export_ArkUIViewController_onSurfaceShow)(void *controllerRef);

                                libkn_KInt (*_Export_ArkUIViewController_requestSyncRefresh)(
                                        void *controllerRef);

                                const char *
                                (*_Export_ArkUIViewController_sendMessage)(void *controllerRef,
                                                                           const char *type,
                                                                           const char *message);

                                void (*_Export_ArkUIViewController_setContext)(void *controllerRef,
                                                                               void *context);

                                void (*_Export_ArkUIViewController_setEnv)(void *controllerRef,
                                                                           void *env);

                                void (*_Export_ArkUIViewController_setId)(void *controllerRef,
                                                                          const char *id);

                                void
                                (*_Export_ArkUIViewController_setMessenger)(void *controllerRef,
                                                                            void *messenger);

                                void (*_Export_ArkUIViewController_setRootView)(void *controllerRef,
                                                                                void *backRootView,
                                                                                void *foreRootView,
                                                                                void *touchableRootView);

                                void
                                (*_Export_ArkUIViewController_setUIContext)(void *controllerRef,
                                                                            void *uiContext);

                                void (*_Export_ArkUIViewController_setXComponentRender)(
                                        void *controllerRef, void *render);

                                void (*_Export_ArkUIViewInitializer_init)(void *env, void *exports);
                            } arkui;
                        } ui;
                    } export_;
                } compose;
            } androidx;
            struct {
                struct {
                    struct {
                        struct {
                            libkn_KType *(*_type)(void);

                            libkn_kref_com_tencent_compose_Greeting (*Greeting)();

                            const char *(*greet)(libkn_kref_com_tencent_compose_Greeting thiz);
                        } Greeting;

                        struct {
                            struct {
                                libkn_KInt
                                (*com_tencent_compose_sample_data_DisplayItem$stableprop_getter)();

                                libkn_KInt
                                (*com_tencent_compose_sample_data_DisplaySection$stableprop_getter)();
                            } data;

                            struct {
                                const char *(*sqlTest)();
                            } demo;

                            struct {
                                struct {
                                    struct {
                                        libkn_KType *(*_type)(void);

                                        libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData
                                        (*PieceData)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game game,
                                                libkn_KFloat velocity, libkn_KULong color);

                                        libkn_KBoolean (*get_clicked)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);

                                        void (*set_clicked)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz,
                                                libkn_KBoolean set);

                                        libkn_KULong (*get_color)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);

                                        libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game
                                        (*get_game)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);

                                        libkn_KFloat (*get_position)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);

                                        void (*set_position)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz,
                                                libkn_KFloat set);

                                        libkn_KFloat (*get_velocity)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);

                                        void (*click)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);

                                        libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game
                                        (*component1)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);

                                        libkn_KFloat (*component2)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);

                                        libkn_KULong (*component3)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);

                                        libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData
                                        (*copy)(libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz,
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game game,
                                                libkn_KFloat velocity, libkn_KULong color);

                                        libkn_KBoolean (*equals)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz,
                                                libkn_kref_kotlin_Any other);

                                        libkn_KInt (*hashCode)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);

                                        const char *(*toString)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz);

                                        void (*update)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData thiz,
                                                libkn_KLong dt);
                                    } PieceData;

                                    struct {
                                        libkn_KType *(*_type)(void);

                                        libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game
                                        (*Game)();

                                        libkn_KLong (*get_elapsed)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);

                                        void (*set_elapsed)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz,
                                                libkn_KLong set);

                                        libkn_KBoolean (*get_finished)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);

                                        void (*set_finished)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz,
                                                libkn_KBoolean set);

                                        libkn_KFloat (*get_height)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);

                                        void (*set_height)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz,
                                                libkn_KFloat set);

                                        libkn_KFloat (*get_numBlocks)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);

                                        void (*set_numBlocks)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz,
                                                libkn_KFloat set);

                                        libkn_KBoolean (*get_paused)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);

                                        void (*set_paused)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz,
                                                libkn_KBoolean set);

                                        libkn_kref_androidx_compose_runtime_snapshots_SnapshotStateList
                                        (*get_pieces)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);

                                        libkn_KInt (*get_score)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);

                                        void (*set_score)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz,
                                                libkn_KInt set);

                                        libkn_KBoolean (*get_started)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);

                                        void (*set_started)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz,
                                                libkn_KBoolean set);

                                        libkn_KFloat (*get_width)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);

                                        void (*set_width)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz,
                                                libkn_KFloat set);

                                        void (*clicked)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz,
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_PieceData piece);

                                        void (*start)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz);

                                        void (*update)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_sectionItem_Game thiz,
                                                libkn_KLong deltaTimeNanos);
                                    } Game;

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter_)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter_)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter_)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter__)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter__)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter__)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter___)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter___)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter___)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter____)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter____)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter____)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter_____)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter_____)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter_____)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter______)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter______)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter______)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter_______)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter_______)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter_______)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter_________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter_________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter_________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter__________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter__________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter__________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter___________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter___________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter___________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter____________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter____________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter____________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter_____________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter_____________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter_____________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter______________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter______________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter______________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_DropdownItem$stableprop_getter_______________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_Game$stableprop_getter_______________)();

                                    libkn_KInt
                                    (*com_tencent_compose_sample_mainpage_sectionItem_PieceData$stableprop_getter_______________)();
                                } sectionItem;

                                struct {
                                    struct {
                                        libkn_KType *(*_type)(void);

                                        libkn_kref_com_tencent_compose_sample_mainpage_Test1_$serializer
                                        (*_instance)();

                                        libkn_kref_kotlinx_serialization_descriptors_SerialDescriptor
                                        (*get_descriptor)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_Test1_$serializer thiz);

                                        libkn_kref_kotlin_Array (*childSerializers)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_Test1_$serializer thiz);

                                        libkn_kref_com_tencent_compose_sample_mainpage_Test1
                                        (*deserialize)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_Test1_$serializer thiz,
                                                libkn_kref_kotlinx_serialization_encoding_Decoder decoder);

                                        void (*serialize)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_Test1_$serializer thiz,
                                                libkn_kref_kotlinx_serialization_encoding_Encoder encoder,
                                                libkn_kref_com_tencent_compose_sample_mainpage_Test1 value);
                                    } $serializer;

                                    struct {
                                        libkn_KType *(*_type)(void);

                                        libkn_kref_com_tencent_compose_sample_mainpage_Test1_Companion
                                        (*_instance)();

                                        libkn_kref_kotlinx_serialization_KSerializer (*serializer)(
                                                libkn_kref_com_tencent_compose_sample_mainpage_Test1_Companion thiz);
                                    } Companion;

                                    libkn_KType *(*_type)(void);

                                    libkn_kref_com_tencent_compose_sample_mainpage_Test1 (*Test1)();

                                    const char *(*get_a)(
                                            libkn_kref_com_tencent_compose_sample_mainpage_Test1 thiz);

                                    void (*set_a)(
                                            libkn_kref_com_tencent_compose_sample_mainpage_Test1 thiz,
                                            const char *set);
                                } Test1;

                                libkn_KInt
                                (*com_tencent_compose_sample_mainpage_Test1$stableprop_getter)();

                                libkn_KInt
                                (*com_tencent_compose_sample_mainpage_Test1_$serializer$stableprop_getter)();

                                libkn_kref_kotlinx_serialization_json_Json
                                (*get_encodeJsonFormat)();

                                libkn_KInt
                                (*com_tencent_compose_sample_mainpage_Test1$stableprop_getter_)();

                                libkn_KInt
                                (*com_tencent_compose_sample_mainpage_Test1_$serializer$stableprop_getter_)();

                                const char *(*testJson)();

                                const char *(*testKsoup)();

                                const char *(*testWebView)();

                                const char *(*testXmlUtil)();

                                libkn_KInt
                                (*com_tencent_compose_sample_mainpage_Test1$stableprop_getter__)();

                                libkn_KInt
                                (*com_tencent_compose_sample_mainpage_Test1_$serializer$stableprop_getter__)();
                            } mainpage;

                            struct {
                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sample_KsoupTest (*KsoupTest)();

                                const char *(*runAllTests)(
                                        libkn_kref_com_tencent_compose_sample_KsoupTest thiz);

                                const char *(*testKsoupElementSelection)(
                                        libkn_kref_com_tencent_compose_sample_KsoupTest thiz);

                                const char *(*testKsoupHtmlCleaning)(
                                        libkn_kref_com_tencent_compose_sample_KsoupTest thiz);

                                const char *(*testKsoupHtmlParsing)(
                                        libkn_kref_com_tencent_compose_sample_KsoupTest thiz);
                            } KsoupTest;

                            struct {
                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sample_WebViewTest (*WebViewTest)();

                                const char *
                                (*runAllTests)(
                                        libkn_kref_com_tencent_compose_sample_WebViewTest thiz);

                                const char *(*testWebViewInitialization)(
                                        libkn_kref_com_tencent_compose_sample_WebViewTest thiz);

                                const char *
                                (*testWebViewJavaScript)(
                                        libkn_kref_com_tencent_compose_sample_WebViewTest thiz);

                                const char *
                                (*testWebViewLoading)(
                                        libkn_kref_com_tencent_compose_sample_WebViewTest thiz);

                                const char *
                                (*testWebViewNavigation)(
                                        libkn_kref_com_tencent_compose_sample_WebViewTest thiz);
                            } WebViewTest;

                            struct {
                                struct {
                                    libkn_KType *(*_type)(void);

                                    libkn_kref_com_tencent_compose_sample_Person_$serializer
                                    (*_instance)();

                                    libkn_kref_kotlinx_serialization_descriptors_SerialDescriptor
                                    (*get_descriptor)(
                                            libkn_kref_com_tencent_compose_sample_Person_$serializer thiz);

                                    libkn_kref_kotlin_Array (*childSerializers)(
                                            libkn_kref_com_tencent_compose_sample_Person_$serializer thiz);

                                    libkn_kref_com_tencent_compose_sample_Person (*deserialize)(
                                            libkn_kref_com_tencent_compose_sample_Person_$serializer thiz,
                                            libkn_kref_kotlinx_serialization_encoding_Decoder decoder);

                                    void (*serialize)(
                                            libkn_kref_com_tencent_compose_sample_Person_$serializer thiz,
                                            libkn_kref_kotlinx_serialization_encoding_Encoder encoder,
                                            libkn_kref_com_tencent_compose_sample_Person value);
                                } $serializer;

                                struct {
                                    libkn_KType *(*_type)(void);

                                    libkn_kref_com_tencent_compose_sample_Person_Companion
                                    (*_instance)();

                                    libkn_kref_kotlinx_serialization_KSerializer (*serializer)(
                                            libkn_kref_com_tencent_compose_sample_Person_Companion thiz);
                                } Companion;

                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sample_Person
                                (*Person)(const char *name, libkn_KInt age);

                                libkn_KInt
                                (*get_age)(libkn_kref_com_tencent_compose_sample_Person thiz);

                                const char *
                                (*get_name)(libkn_kref_com_tencent_compose_sample_Person thiz);

                                const char *
                                (*component1)(libkn_kref_com_tencent_compose_sample_Person thiz);

                                libkn_KInt
                                (*component2)(libkn_kref_com_tencent_compose_sample_Person thiz);

                                libkn_kref_com_tencent_compose_sample_Person
                                (*copy)(libkn_kref_com_tencent_compose_sample_Person thiz,
                                        const char *name, libkn_KInt age);

                                libkn_KBoolean
                                (*equals)(libkn_kref_com_tencent_compose_sample_Person thiz,
                                          libkn_kref_kotlin_Any other);

                                libkn_KInt
                                (*hashCode)(libkn_kref_com_tencent_compose_sample_Person thiz);

                                const char *
                                (*toString)(libkn_kref_com_tencent_compose_sample_Person thiz);
                            } Person;

                            struct {
                                struct {
                                    libkn_KType *(*_type)(void);

                                    libkn_kref_com_tencent_compose_sample_XmlUtilTest_Companion
                                    (*_instance)();
                                } Companion;

                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sample_XmlUtilTest (*XmlUtilTest)();

                                libkn_kref_com_tencent_compose_sample_Person
                                (*testXmlDeserialization)(
                                        libkn_kref_com_tencent_compose_sample_XmlUtilTest thiz,
                                        const char *xml);

                                const char *(*testXmlSerialization)(
                                        libkn_kref_com_tencent_compose_sample_XmlUtilTest thiz);
                            } XmlUtilTest;

                            libkn_KInt (*com_tencent_compose_sample_KsoupTest$stableprop_getter)();

                            libkn_KInt (*com_tencent_compose_sample_Person$stableprop_getter)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter)();

                            libkn_KInt (*com_tencent_compose_sample_KsoupTest$stableprop_getter_)();

                            libkn_KInt (*com_tencent_compose_sample_Person$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sample_KsoupTest$stableprop_getter__)();

                            libkn_KInt (*com_tencent_compose_sample_Person$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sample_KsoupTest$stableprop_getter___)();

                            libkn_KInt (*com_tencent_compose_sample_Person$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sample_KsoupTest$stableprop_getter____)();

                            libkn_KInt (*com_tencent_compose_sample_Person$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sample_KsoupTest$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sample_KsoupTest$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter______)();

                            void *(*get_nativeResourceManager)();

                            void (*set_nativeResourceManager)(void *set);

                            libkn_KInt
                            (*com_tencent_compose_sample_KsoupTest$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sample_KsoupTest$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_KsoupTest$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_KsoupTest$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_KsoupTest$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_KsoupTest$stableprop_getter____________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person$stableprop_getter____________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_Person_$serializer$stableprop_getter____________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_WebViewTest$stableprop_getter____________)();

                            libkn_KInt
                            (*com_tencent_compose_sample_XmlUtilTest$stableprop_getter____________)();
                        } sample;

                        struct {
                            struct {
                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_service_FileItem
                                (*FileItem)(const char *key,
                                            libkn_kref_kotlinx_datetime_Instant lastModified,
                                            const char *eTag, libkn_KLong size,
                                            const char *storageClass);

                                const char *
                                (*get_eTag)(libkn_kref_com_tencent_compose_service_FileItem thiz);

                                const char *
                                (*get_key)(libkn_kref_com_tencent_compose_service_FileItem thiz);

                                libkn_kref_kotlinx_datetime_Instant
                                (*get_lastModified)(
                                        libkn_kref_com_tencent_compose_service_FileItem thiz);

                                libkn_KLong
                                (*get_size)(libkn_kref_com_tencent_compose_service_FileItem thiz);

                                const char *
                                (*get_storageClass)(
                                        libkn_kref_com_tencent_compose_service_FileItem thiz);

                                const char *
                                (*component1)(libkn_kref_com_tencent_compose_service_FileItem thiz);

                                libkn_kref_kotlinx_datetime_Instant
                                (*component2)(libkn_kref_com_tencent_compose_service_FileItem thiz);

                                const char *
                                (*component3)(libkn_kref_com_tencent_compose_service_FileItem thiz);

                                libkn_KLong
                                (*component4)(libkn_kref_com_tencent_compose_service_FileItem thiz);

                                const char *
                                (*component5)(libkn_kref_com_tencent_compose_service_FileItem thiz);

                                libkn_kref_com_tencent_compose_service_FileItem
                                (*copy)(libkn_kref_com_tencent_compose_service_FileItem thiz,
                                        const char *key,
                                        libkn_kref_kotlinx_datetime_Instant lastModified,
                                        const char *eTag,
                                        libkn_KLong size, const char *storageClass);

                                libkn_KBoolean
                                (*equals)(libkn_kref_com_tencent_compose_service_FileItem thiz,
                                          libkn_kref_kotlin_Any other);

                                libkn_KInt
                                (*hashCode)(libkn_kref_com_tencent_compose_service_FileItem thiz);

                                const char *
                                (*toString)(libkn_kref_com_tencent_compose_service_FileItem thiz);
                            } FileItem;

                            struct {
                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_service_FileInfo
                                (*FileInfo)(const char *name, libkn_KLong size,
                                            libkn_kref_kotlinx_datetime_Instant lastModified,
                                            const char *contentType);

                                const char *
                                (*get_contentType)(
                                        libkn_kref_com_tencent_compose_service_FileInfo thiz);

                                libkn_kref_kotlinx_datetime_Instant
                                (*get_lastModified)(
                                        libkn_kref_com_tencent_compose_service_FileInfo thiz);

                                const char *
                                (*get_name)(libkn_kref_com_tencent_compose_service_FileInfo thiz);

                                libkn_KLong
                                (*get_size)(libkn_kref_com_tencent_compose_service_FileInfo thiz);

                                const char *
                                (*component1)(libkn_kref_com_tencent_compose_service_FileInfo thiz);

                                libkn_KLong
                                (*component2)(libkn_kref_com_tencent_compose_service_FileInfo thiz);

                                libkn_kref_kotlinx_datetime_Instant
                                (*component3)(libkn_kref_com_tencent_compose_service_FileInfo thiz);

                                const char *
                                (*component4)(libkn_kref_com_tencent_compose_service_FileInfo thiz);

                                libkn_kref_com_tencent_compose_service_FileInfo
                                (*copy)(libkn_kref_com_tencent_compose_service_FileInfo thiz,
                                        const char *name, libkn_KLong size,
                                        libkn_kref_kotlinx_datetime_Instant lastModified,
                                        const char *contentType);

                                libkn_KBoolean
                                (*equals)(libkn_kref_com_tencent_compose_service_FileInfo thiz,
                                          libkn_kref_kotlin_Any other);

                                libkn_KInt
                                (*hashCode)(libkn_kref_com_tencent_compose_service_FileInfo thiz);

                                const char *
                                (*toString)(libkn_kref_com_tencent_compose_service_FileInfo thiz);
                            } FileInfo;

                            libkn_KInt (*com_tencent_compose_service_FileInfo$stableprop_getter)();

                            libkn_KInt (*com_tencent_compose_service_FileItem$stableprop_getter)();

                            libkn_KInt (*com_tencent_compose_service_FileInfo$stableprop_getter_)();

                            libkn_KInt (*com_tencent_compose_service_FileItem$stableprop_getter_)();
                        } service;

                        struct {
                            struct {
                                struct {
                                    libkn_KType *(*_type)(void);

                                    libkn_kref_com_tencent_compose_sqldelight_AppDatabase_Companion
                                    (*_instance)();

                                    libkn_kref_app_cash_sqldelight_db_SqlSchema (*get_Schema)(
                                            libkn_kref_com_tencent_compose_sqldelight_AppDatabase_Companion thiz);

                                    libkn_kref_com_tencent_compose_sqldelight_AppDatabase (*invoke)(
                                            libkn_kref_com_tencent_compose_sqldelight_AppDatabase_Companion thiz,
                                            libkn_kref_app_cash_sqldelight_db_SqlDriver driver,
                                            libkn_kref_com_tencent_compose_sqldelight_Player_Adapter playerAdapter,
                                            libkn_kref_com_tencent_compose_sqldelight_Team_Adapter teamAdapter);
                                } Companion;

                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sqldelight_PlayerQueries
                                (*get_playerQueries)(
                                        libkn_kref_com_tencent_compose_sqldelight_AppDatabase thiz);

                                libkn_kref_com_tencent_compose_sqldelight_TeamQueries
                                (*get_teamQueries)(
                                        libkn_kref_com_tencent_compose_sqldelight_AppDatabase thiz);
                            } AppDatabase;

                            struct {
                                libkn_KInt
                                (*com_tencent_compose_sqldelight_composeApp_AppDatabaseImpl_Schema$stableprop_getter)();
                            } composeApp;

                            struct {
                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sqldelight_ForTeam
                                (*ForTeam)(const char *first_name, const char *last_name,
                                           const char *number,
                                           const char *teamName);

                                const char *
                                (*get_first_name)(
                                        libkn_kref_com_tencent_compose_sqldelight_ForTeam thiz);

                                const char *
                                (*get_last_name)(
                                        libkn_kref_com_tencent_compose_sqldelight_ForTeam thiz);

                                const char *
                                (*get_number)(
                                        libkn_kref_com_tencent_compose_sqldelight_ForTeam thiz);

                                const char *
                                (*get_teamName)(
                                        libkn_kref_com_tencent_compose_sqldelight_ForTeam thiz);

                                const char *
                                (*component1)(
                                        libkn_kref_com_tencent_compose_sqldelight_ForTeam thiz);

                                const char *
                                (*component2)(
                                        libkn_kref_com_tencent_compose_sqldelight_ForTeam thiz);

                                const char *
                                (*component3)(
                                        libkn_kref_com_tencent_compose_sqldelight_ForTeam thiz);

                                const char *
                                (*component4)(
                                        libkn_kref_com_tencent_compose_sqldelight_ForTeam thiz);

                                libkn_kref_com_tencent_compose_sqldelight_ForTeam
                                (*copy)(libkn_kref_com_tencent_compose_sqldelight_ForTeam thiz,
                                        const char *first_name, const char *last_name,
                                        const char *number,
                                        const char *teamName);

                                libkn_KBoolean
                                (*equals)(libkn_kref_com_tencent_compose_sqldelight_ForTeam thiz,
                                          libkn_kref_kotlin_Any other);

                                libkn_KInt
                                (*hashCode)(libkn_kref_com_tencent_compose_sqldelight_ForTeam thiz);

                                const char *
                                (*toString)(libkn_kref_com_tencent_compose_sqldelight_ForTeam thiz);
                            } ForTeam;

                            struct {
                                struct {
                                    libkn_KType *(*_type)(void);

                                    libkn_kref_com_tencent_compose_sqldelight_Player_Adapter
                                    (*Adapter)(
                                            libkn_kref_app_cash_sqldelight_ColumnAdapter numberAdapter,
                                            libkn_kref_app_cash_sqldelight_ColumnAdapter ageAdapter,
                                            libkn_kref_app_cash_sqldelight_ColumnAdapter birth_dateAdapter,
                                            libkn_kref_app_cash_sqldelight_ColumnAdapter weightAdapter,
                                            libkn_kref_app_cash_sqldelight_ColumnAdapter shootsAdapter,
                                            libkn_kref_app_cash_sqldelight_ColumnAdapter positionAdapter);

                                    libkn_kref_app_cash_sqldelight_ColumnAdapter (*get_ageAdapter)(
                                            libkn_kref_com_tencent_compose_sqldelight_Player_Adapter thiz);

                                    libkn_kref_app_cash_sqldelight_ColumnAdapter
                                    (*get_birth_dateAdapter)(
                                            libkn_kref_com_tencent_compose_sqldelight_Player_Adapter thiz);

                                    libkn_kref_app_cash_sqldelight_ColumnAdapter
                                    (*get_numberAdapter)(
                                            libkn_kref_com_tencent_compose_sqldelight_Player_Adapter thiz);

                                    libkn_kref_app_cash_sqldelight_ColumnAdapter
                                    (*get_positionAdapter)(
                                            libkn_kref_com_tencent_compose_sqldelight_Player_Adapter thiz);

                                    libkn_kref_app_cash_sqldelight_ColumnAdapter
                                    (*get_shootsAdapter)(
                                            libkn_kref_com_tencent_compose_sqldelight_Player_Adapter thiz);

                                    libkn_kref_app_cash_sqldelight_ColumnAdapter
                                    (*get_weightAdapter)(
                                            libkn_kref_com_tencent_compose_sqldelight_Player_Adapter thiz);
                                } Adapter;

                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sqldelight_Player
                                (*Player)(libkn_KLong id, const char *first_name,
                                          const char *last_name,
                                          libkn_KInt number, libkn_kref_kotlin_Long team,
                                          libkn_KInt age,
                                          libkn_kref_kotlinx_datetime_LocalDate birth_date,
                                          libkn_KFloat weight,
                                          libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots shoots,
                                          libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position position);

                                libkn_KInt
                                (*get_age)(libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_kref_kotlinx_datetime_LocalDate
                                (*get_birth_date)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                const char *
                                (*get_first_name)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_KLong
                                (*get_id)(libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                const char *
                                (*get_last_name)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_KInt
                                (*get_number)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position
                                (*get_position)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots
                                (*get_shoots)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_kref_kotlin_Long
                                (*get_team)(libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_KFloat
                                (*get_weight)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_KLong
                                (*component1)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position
                                (*component10)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                const char *
                                (*component2)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                const char *
                                (*component3)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_KInt
                                (*component4)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_kref_kotlin_Long
                                (*component5)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_KInt
                                (*component6)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_kref_kotlinx_datetime_LocalDate
                                (*component7)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_KFloat
                                (*component8)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots
                                (*component9)(
                                        libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                libkn_kref_com_tencent_compose_sqldelight_Player
                                (*copy)(libkn_kref_com_tencent_compose_sqldelight_Player thiz,
                                        libkn_KLong id,
                                        const char *first_name, const char *last_name,
                                        libkn_KInt number,
                                        libkn_kref_kotlin_Long team, libkn_KInt age,
                                        libkn_kref_kotlinx_datetime_LocalDate birth_date,
                                        libkn_KFloat weight,
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots shoots,
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position position);

                                libkn_KBoolean
                                (*equals)(libkn_kref_com_tencent_compose_sqldelight_Player thiz,
                                          libkn_kref_kotlin_Any other);

                                libkn_KInt
                                (*hashCode)(libkn_kref_com_tencent_compose_sqldelight_Player thiz);

                                const char *
                                (*toString)(libkn_kref_com_tencent_compose_sqldelight_Player thiz);
                            } Player;

                            struct {
                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sqldelight_PlayerQueries
                                (*PlayerQueries)(libkn_kref_app_cash_sqldelight_db_SqlDriver driver,
                                                 libkn_kref_com_tencent_compose_sqldelight_Player_Adapter playerAdapter,
                                                 libkn_kref_com_tencent_compose_sqldelight_Team_Adapter teamAdapter);

                                libkn_kref_app_cash_sqldelight_Query
                                (*forTeam)(
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerQueries thiz,
                                        libkn_KLong team_id);

                                void
                                (*insertPlayer)(
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerQueries thiz,
                                        const char *first_name, const char *last_name,
                                        libkn_KInt number, const char *name, libkn_KInt age,
                                        libkn_KFloat weight,
                                        libkn_kref_kotlinx_datetime_LocalDate birth_date,
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots shoots,
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position position);

                                libkn_kref_app_cash_sqldelight_Query
                                (*selectAll)(
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerQueries thiz);
                            } PlayerQueries;

                            struct {
                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sqldelight_SelectAll
                                (*SelectAll)(libkn_KLong id, const char *first_name,
                                             const char *last_name,
                                             libkn_KInt number, libkn_kref_kotlin_Long team,
                                             libkn_KInt age,
                                             libkn_kref_kotlinx_datetime_LocalDate birth_date,
                                             libkn_KFloat weight,
                                             libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots shoots,
                                             libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position position,
                                             libkn_KLong id_, const char *name,
                                             libkn_kref_kotlinx_datetime_LocalDate founded,
                                             const char *coach,
                                             libkn_kref_kotlin_Long captain,
                                             libkn_KBoolean won_cup);

                                libkn_KInt
                                (*get_age)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_kotlinx_datetime_LocalDate
                                (*get_birth_date)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_kotlin_Long
                                (*get_captain)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                const char *
                                (*get_coach)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                const char *
                                (*get_first_name)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_kotlinx_datetime_LocalDate
                                (*get_founded)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_KLong
                                (*get_id)(libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_KLong
                                (*get_id_)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                const char *
                                (*get_last_name)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                const char *
                                (*get_name)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_KInt
                                (*get_number)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position
                                (*get_position)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots
                                (*get_shoots)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_kotlin_Long
                                (*get_team)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_KFloat
                                (*get_weight)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_KBoolean
                                (*get_won_cup)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_KLong
                                (*component1)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position
                                (*component10)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_KLong
                                (*component11)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                const char *
                                (*component12)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_kotlinx_datetime_LocalDate
                                (*component13)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                const char *
                                (*component14)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_kotlin_Long
                                (*component15)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_KBoolean
                                (*component16)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                const char *
                                (*component2)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                const char *
                                (*component3)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_KInt
                                (*component4)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_kotlin_Long
                                (*component5)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_KInt
                                (*component6)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_kotlinx_datetime_LocalDate
                                (*component7)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_KFloat
                                (*component8)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots
                                (*component9)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                libkn_kref_com_tencent_compose_sqldelight_SelectAll
                                (*copy)(libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz,
                                        libkn_KLong id, const char *first_name,
                                        const char *last_name,
                                        libkn_KInt number, libkn_kref_kotlin_Long team,
                                        libkn_KInt age,
                                        libkn_kref_kotlinx_datetime_LocalDate birth_date,
                                        libkn_KFloat weight,
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots shoots,
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position position,
                                        libkn_KLong id_, const char *name,
                                        libkn_kref_kotlinx_datetime_LocalDate founded,
                                        const char *coach,
                                        libkn_kref_kotlin_Long captain, libkn_KBoolean won_cup);

                                libkn_KBoolean
                                (*equals)(libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz,
                                          libkn_kref_kotlin_Any other);

                                libkn_KInt
                                (*hashCode)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);

                                const char *
                                (*toString)(
                                        libkn_kref_com_tencent_compose_sqldelight_SelectAll thiz);
                            } SelectAll;

                            struct {
                                struct {
                                    libkn_KType *(*_type)(void);

                                    libkn_kref_com_tencent_compose_sqldelight_Team_Adapter
                                    (*Adapter)(
                                            libkn_kref_app_cash_sqldelight_ColumnAdapter foundedAdapter);

                                    libkn_kref_app_cash_sqldelight_ColumnAdapter
                                    (*get_foundedAdapter)(
                                            libkn_kref_com_tencent_compose_sqldelight_Team_Adapter thiz);
                                } Adapter;

                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sqldelight_Team
                                (*Team)(libkn_KLong id, const char *name,
                                        libkn_kref_kotlinx_datetime_LocalDate founded,
                                        const char *coach,
                                        libkn_kref_kotlin_Long captain, libkn_KBoolean won_cup);

                                libkn_kref_kotlin_Long
                                (*get_captain)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                const char *
                                (*get_coach)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                libkn_kref_kotlinx_datetime_LocalDate
                                (*get_founded)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                libkn_KLong
                                (*get_id)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                const char *
                                (*get_name)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                libkn_KBoolean
                                (*get_won_cup)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                libkn_KLong
                                (*component1)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                const char *
                                (*component2)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                libkn_kref_kotlinx_datetime_LocalDate
                                (*component3)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                const char *
                                (*component4)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                libkn_kref_kotlin_Long
                                (*component5)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                libkn_KBoolean
                                (*component6)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                libkn_kref_com_tencent_compose_sqldelight_Team
                                (*copy)(libkn_kref_com_tencent_compose_sqldelight_Team thiz,
                                        libkn_KLong id,
                                        const char *name,
                                        libkn_kref_kotlinx_datetime_LocalDate founded,
                                        const char *coach, libkn_kref_kotlin_Long captain,
                                        libkn_KBoolean won_cup);

                                libkn_KBoolean
                                (*equals)(libkn_kref_com_tencent_compose_sqldelight_Team thiz,
                                          libkn_kref_kotlin_Any other);

                                libkn_KInt
                                (*hashCode)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);

                                const char *
                                (*toString)(libkn_kref_com_tencent_compose_sqldelight_Team thiz);
                            } Team;

                            struct {
                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sqldelight_TeamQueries
                                (*TeamQueries)(libkn_kref_app_cash_sqldelight_db_SqlDriver driver,
                                               libkn_kref_com_tencent_compose_sqldelight_Team_Adapter teamAdapter,
                                               libkn_kref_com_tencent_compose_sqldelight_Player_Adapter playerAdapter);

                                void (*insertTeam)(
                                        libkn_kref_com_tencent_compose_sqldelight_TeamQueries thiz,
                                        const char *name,
                                        libkn_kref_kotlinx_datetime_LocalDate founded,
                                        const char *coach, libkn_KBoolean won_cup);

                                libkn_kref_app_cash_sqldelight_Query
                                (*selectAll)(
                                        libkn_kref_com_tencent_compose_sqldelight_TeamQueries thiz);

                                void (*setCaptain)(
                                        libkn_kref_com_tencent_compose_sqldelight_TeamQueries thiz,
                                        libkn_KInt player_number, const char *team_name);

                                void (*updateCoachForTeam)(
                                        libkn_kref_com_tencent_compose_sqldelight_TeamQueries thiz,
                                        const char *coach, const char *name);
                            } TeamQueries;

                            struct {
                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sqldelight_DateAdapter
                                (*DateAdapter)();

                                libkn_kref_kotlinx_datetime_LocalDate
                                (*decode)(
                                        libkn_kref_com_tencent_compose_sqldelight_DateAdapter thiz,
                                        libkn_KLong databaseValue);

                                libkn_KLong
                                (*encode)(
                                        libkn_kref_com_tencent_compose_sqldelight_DateAdapter thiz,
                                        libkn_kref_kotlinx_datetime_LocalDate value);
                            } DateAdapter;

                            struct {
                                struct {
                                    struct {
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots
                                        (*get)(); /* enum entry for RIGHT. */
                                    } RIGHT;

                                    struct {
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Shoots
                                        (*get)(); /* enum entry for LEFT. */
                                    } LEFT;

                                    libkn_KType *(*_type)(void);
                                } Shoots;

                                struct {
                                    struct {
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position
                                        (*get)(); /* enum entry for LEFT_WING. */
                                    } LEFT_WING;

                                    struct {
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position
                                        (*get)(); /* enum entry for RIGHT_WING. */
                                    } RIGHT_WING;

                                    struct {
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position
                                        (*get)(); /* enum entry for CENTER. */
                                    } CENTER;

                                    struct {
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position
                                        (*get)(); /* enum entry for DEFENSE. */
                                    } DEFENSE;

                                    struct {
                                        libkn_kref_com_tencent_compose_sqldelight_PlayerVals_Position
                                        (*get)(); /* enum entry for GOALIE. */
                                    } GOALIE;

                                    libkn_KType *(*_type)(void);
                                } Position;

                                libkn_KType *(*_type)(void);
                            } PlayerVals;

                            struct {
                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sqldelight_Schema (*_instance)();

                                libkn_KLong
                                (*get_version)(
                                        libkn_kref_com_tencent_compose_sqldelight_Schema thiz);

                                libkn_kref_kotlin_Any
                                (*create)(libkn_kref_com_tencent_compose_sqldelight_Schema thiz,
                                          libkn_kref_app_cash_sqldelight_db_SqlDriver driver);

                                libkn_kref_kotlin_Any
                                (*migrate)(libkn_kref_com_tencent_compose_sqldelight_Schema thiz,
                                           libkn_kref_app_cash_sqldelight_db_SqlDriver driver,
                                           libkn_KLong oldVersion, libkn_KLong newVersion,
                                           libkn_kref_kotlin_Array callbacks);
                            } Schema;

                            struct {
                                libkn_KType *(*_type)(void);

                                libkn_kref_com_tencent_compose_sqldelight_Db (*_instance)();

                                libkn_kref_com_tencent_compose_sqldelight_AppDatabase
                                (*get_instance)(libkn_kref_com_tencent_compose_sqldelight_Db thiz);

                                void
                                (*defaultDriver)(libkn_kref_com_tencent_compose_sqldelight_Db thiz);
                            } Db;

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_DateAdapter$stableprop_getter)();

                            libkn_KInt (*com_tencent_compose_sqldelight_Db$stableprop_getter)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_ForTeam$stableprop_getter)();

                            libkn_KInt (*com_tencent_compose_sqldelight_Player$stableprop_getter)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_PlayerQueries$stableprop_getter)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player_Adapter$stableprop_getter)();

                            libkn_KInt (*com_tencent_compose_sqldelight_Schema$stableprop_getter)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_SelectAll$stableprop_getter)();

                            libkn_KInt (*com_tencent_compose_sqldelight_Team$stableprop_getter)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_TeamQueries$stableprop_getter)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team_Adapter$stableprop_getter)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_DateAdapter$stableprop_getter_)();

                            libkn_KInt (*com_tencent_compose_sqldelight_Db$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_ForTeam$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_PlayerQueries$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player_Adapter$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Schema$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_SelectAll$stableprop_getter_)();

                            libkn_KInt (*com_tencent_compose_sqldelight_Team$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_TeamQueries$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team_Adapter$stableprop_getter_)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_DateAdapter$stableprop_getter__)();

                            libkn_KInt (*com_tencent_compose_sqldelight_Db$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_ForTeam$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_PlayerQueries$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player_Adapter$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Schema$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_SelectAll$stableprop_getter__)();

                            libkn_KInt (*com_tencent_compose_sqldelight_Team$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_TeamQueries$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team_Adapter$stableprop_getter__)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_DateAdapter$stableprop_getter___)();

                            libkn_KInt (*com_tencent_compose_sqldelight_Db$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_ForTeam$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_PlayerQueries$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player_Adapter$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Schema$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_SelectAll$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_TeamQueries$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team_Adapter$stableprop_getter___)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_DateAdapter$stableprop_getter____)();

                            libkn_KInt (*com_tencent_compose_sqldelight_Db$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_ForTeam$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_PlayerQueries$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player_Adapter$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Schema$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_SelectAll$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_TeamQueries$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team_Adapter$stableprop_getter____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_DateAdapter$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Db$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_ForTeam$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_PlayerQueries$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player_Adapter$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Schema$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_SelectAll$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_TeamQueries$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team_Adapter$stableprop_getter_____)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_DateAdapter$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Db$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_ForTeam$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_PlayerQueries$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player_Adapter$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Schema$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_SelectAll$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_TeamQueries$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team_Adapter$stableprop_getter______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_DateAdapter$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Db$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_ForTeam$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_PlayerQueries$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player_Adapter$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Schema$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_SelectAll$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_TeamQueries$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team_Adapter$stableprop_getter_______)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_DateAdapter$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Db$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_ForTeam$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_PlayerQueries$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player_Adapter$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Schema$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_SelectAll$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_TeamQueries$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team_Adapter$stableprop_getter________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_DateAdapter$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Db$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_ForTeam$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_PlayerQueries$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player_Adapter$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Schema$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_SelectAll$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_TeamQueries$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team_Adapter$stableprop_getter_________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_DateAdapter$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Db$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_ForTeam$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_PlayerQueries$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player_Adapter$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Schema$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_SelectAll$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_TeamQueries$stableprop_getter__________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team_Adapter$stableprop_getter__________)();

                            libkn_kref_com_tencent_compose_sqldelight_AppDatabase
                            (*createQueryWrapper)(
                                    libkn_kref_app_cash_sqldelight_db_SqlDriver driver);

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_DateAdapter$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Db$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_ForTeam$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_PlayerQueries$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Player_Adapter$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Schema$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_SelectAll$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_TeamQueries$stableprop_getter___________)();

                            libkn_KInt
                            (*com_tencent_compose_sqldelight_Team_Adapter$stableprop_getter___________)();

                            libkn_kref_com_tencent_compose_sqldelight_AppDatabase
                            (*getDbInstance)();
                        } sqldelight;

                        libkn_KInt (*com_tencent_compose_Greeting$stableprop_getter)();

                        libkn_KInt (*com_tencent_compose_OHOSPlatform$stableprop_getter)();

                        libkn_KInt (*com_tencent_compose_Greeting$stableprop_getter_)();

                        libkn_KInt (*com_tencent_compose_OHOSPlatform$stableprop_getter_)();

                        libkn_KInt (*com_tencent_compose_Greeting$stableprop_getter__)();

                        libkn_KInt (*com_tencent_compose_OHOSPlatform$stableprop_getter__)();

                        void *(*MainArkUIViewController_)(void *env);

                        libkn_KInt (*com_tencent_compose_Greeting$stableprop_getter___)();

                        libkn_KInt (*com_tencent_compose_OHOSPlatform$stableprop_getter___)();

                        void (*initResourceManager)(void *resourceManager);

                        libkn_KInt (*com_tencent_compose_Greeting$stableprop_getter____)();

                        libkn_KInt (*com_tencent_compose_OHOSPlatform$stableprop_getter____)();
                    } compose;
                } tencent;
            } com;
            struct {
                struct {
                    struct {
                        struct {
                            libkn_KInt
                            (*composesample_composeapp_generated_resources_Res$stableprop_getter)();

                            libkn_KInt
                            (*composesample_composeapp_generated_resources_Res_drawable$stableprop_getter)();

                            libkn_KInt
                            (*composesample_composeapp_generated_resources_Res_font$stableprop_getter)();

                            libkn_KInt
                            (*composesample_composeapp_generated_resources_Res_string$stableprop_getter)();

                            libkn_KInt
                            (*composesample_composeapp_generated_resources_Res$stableprop_getter_)();

                            libkn_KInt
                            (*composesample_composeapp_generated_resources_Res_drawable$stableprop_getter_)();

                            libkn_KInt
                            (*composesample_composeapp_generated_resources_Res_font$stableprop_getter_)();

                            libkn_KInt
                            (*composesample_composeapp_generated_resources_Res_string$stableprop_getter_)();
                        } resources;
                    } generated;
                } composeapp;
            } composesample;
        } root;
    } kotlin;
} libkn_ExportedSymbols;

extern libkn_ExportedSymbols *libkn_symbols(void);

#ifdef __cplusplus
}  /* extern "C" */
#endif
#endif  /* KONAN_LIBKN_H */
