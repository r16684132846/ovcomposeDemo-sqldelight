/*
 * Tencent is pleased to support the open source community by making ovCompose available.
 * Copyright (C) 2025 THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import { OnPageBeginEvent, promptAction } from '@kit.ArkUI';

interface ButtonArgs {
  text: string
  backgroundColor: string
}

@Builder
export function buttonBuilder(args: ButtonArgs) {
  button()
}

@Component
export struct button {
  @Consume compose_args: ButtonArgs

  build() {
    Column() {
      Button(this.compose_args.text).backgroundColor(this.compose_args.backgroundColor).width('100%').onClick(e => {
        console.log(`Button Clicked: ${this.compose_args.text}`)
      }).height('70%')

      Text(this.compose_args.text).backgroundColor(this.compose_args.backgroundColor).width('100%').onClick(e => {
        console.log(`Text Clicked: ${this.compose_args.text}`)
      }).height('20%')
      Stack().height('10%')
    }
  }
}

interface TextArgs {
  id: string
  text: string
  backgroundColor: string
}

@Builder
export function textBuilder(args: TextArgs) {
  text()
}

@Component
export struct text {
  @Consume compose_args: TextArgs

  build() {
    Text(this.compose_args.id + " " + this.compose_args.text)
      .backgroundColor(this.compose_args.backgroundColor)
      .width('100%')
      .height('100%')
      .borderRadius('5vp')
      .onClick(e => {
        console.log(`Text Clicked: ${JSON.stringify(this.compose_args)}`)
      })
  }
}

@Builder
export function labelBuilder(args: ButtonArgs) {
  label()
}

@Component
export struct label {
  @Consume compose_args: ButtonArgs

  build() {
    Column() {

      Button(`+ ${this.compose_args.text}`, { type: ButtonType.Normal })
        .backgroundColor(this.compose_args.backgroundColor)
        .width('100%')
        .height('50%')
        .borderRadius(2)
        .onClick(e => {
          promptAction.showToast({
            message: this.compose_args.text
          })
        })
      Text(this.compose_args.text).backgroundColor(Color.Orange).width('100%').height('50%')
    }
  }
}

@Builder
export function layerBuilder(args: ButtonArgs) {
  layer()
}

@Component
export struct layer {
  @Consume compose_args: ButtonArgs

  build() {
    Stack({ alignContent: Alignment.BottomEnd }) {
      Text(this.compose_args.text)
    }
    .width('100%')
    .height('100%')
    .backgroundColor(this.compose_args.backgroundColor)
    .onClick(() => {
      promptAction.showToast({ message: `${this.compose_args.text} Clicked` })
    })
    .onTouch(e => {
      console.log(`layer ${this.compose_args.text} onTouch`)
    })
  }
}

@Builder
export function buttonWrapContentBuilder(args: ButtonArgs) {
  buttonWrapContent()
}

@Component
export struct buttonWrapContent {
  @Consume compose_args: ButtonArgs

  build() {
    Column() {

      Button(this.compose_args.text).backgroundColor(this.compose_args.backgroundColor).width('100%').onClick(e => {
        console.log(`Button Clicked: ${this.compose_args.text}`)
      })
      Text(this.compose_args.text).backgroundColor(this.compose_args.backgroundColor).width('100%').onClick(e => {
        console.log(`Text Clicked: ${this.compose_args.text}`)
      })
    }
  }
}


interface InputArgs {
  text: string
}

@Builder
export function textInputBuilder(args: InputArgs) {
  textInput()
}


@Component
export struct textInput {
  @Consume compose_args: InputArgs

  build() {
    Column() {
      TextInput({ text: $$this.compose_args.text }).onChange(value => {
        console.log(`/// onChange: ${value}`)
      })

      Text("ArkUI组件更新:").fontColor(Color.Gray).margin({ top: 30 })

      Text(this.compose_args.text)
        .width('100%')
        .padding(10)
        .border({ width: 1, color: Color.Gray })
    }.alignItems(HorizontalAlign.Start)
  }
}

@Builder
export function verticalListBuilder(args?: object) {
  verticalList()
}

@Component
export struct verticalList {
  build() {
    Row() {
      List() {
        ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], (item: number, index) => {
          ListItem() {
            Button(`Ark Button ${index}`, { type: ButtonType.Normal }).borderRadius(2).height('100vp').padding(10)
          }.padding(10)
        })
      }.listDirection(Axis.Vertical).height('100%').width('40%')

      Stack().width('20%').height('100%').borderWidth(1)

      Scroll() {
        Column() {
          ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], (item: number, index) => {
            ListItem() {
              Button(`Ark Button ${index}`, { type: ButtonType.Normal }).borderRadius(2).height('100vp').padding(10)
            }.padding(10)
          })
        }
      }.scrollable(ScrollDirection.Vertical).height('100%').width('40%')
    }
  }
}

@Builder
export function horizontalListBuilder(args?: object) {
  horizontalList()
}

@Component
export struct horizontalList {
  build() {
    Column() {
      List() {
        ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], (item: number, index) => {
          ListItem() {
            Button(`Ark Button ${index}`, { type: ButtonType.Normal }).borderRadius(2).height('100vp')
          }.padding(10)
        })
      }.listDirection(Axis.Horizontal).height('40%').width('100%')

      Stack().width('100%').height('20%').borderWidth(1)

      Scroll() {
        Row() {
          ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], (item: number, index) => {
            ListItem() {
              Button(`Ark Button ${index}`, { type: ButtonType.Normal }).borderRadius(2).height('100vp')
            }.padding(10)
          })
        }
      }.scrollable(ScrollDirection.Horizontal).height('40%').width('100%')
    }
  }
}

interface WebViewArgs {
  currentUrl: string;
  url: string
  userAgent: string
  databaseEnabled: boolean
  domStorageEnabled: boolean
  cacheMode: string
  javaScriptEnabled: boolean
  navigationCommand?: string
  navigationCommandId?: number
  onLoadStart?: () => void
  onLoadFinish?: () => void
  onLoadError?: (error: string) => void
  onNavigateBack?: () => void
  onNavigateForward?: () => void
  onReload?: () => void
  onGoHome?: () => void
  urlChangeCommandId?: number
}

@Builder
export function webviewBuilder(args: WebViewArgs) {
  webview()
}

interface GeneratedTypeLiteralInterface_1 {
  request: WebResourceRequest;
  error: WebResourceError;
}

@Component
    struct webview {
  @Consume compose_args: WebViewArgs
  private webviewController: WebController = new WebController();
  @State private currentUrl: string = ''
  @State private navigationCommand: string = ''
  @State private navigationCommandId: number = 0

  aboutToAppear(): void {
    // 确保 URL 不为空
    if (this.compose_args.url && this.compose_args.url.trim() !== '') {
      this.currentUrl = this.compose_args.url;
    } else {
      console.warn("WebView URL 为空或无效，使用默认值");
      this.currentUrl = "about:blank"; // 使用默认页面
    } }
  

  build() {
    Column() {
      Text("WebView Component")
        .fontSize(14)
        .fontWeight(FontWeight.Bold)
        .margin({ bottom: 10 })

      Text(`URL: ${this.currentUrl}`)
        .fontSize(14)
        .maxLines(1)
        .textOverflow({ overflow: TextOverflow.Ellipsis })

      Web({
        src: this.currentUrl,
        controller: this.webviewController
      })
      .onPageBegin((event: OnPageBeginEvent) => {
             console.info(`页面开始加载时更新 URL: ${event.url}`);
             // 页面开始加载时更新 URL
             this.currentUrl = event.url;
              // 通过更新参数通知Compose端
                this.compose_args.currentUrl = event.url;
             try {
               // 触发URL变更事件，通过增加commandId来通知变化
               this.compose_args.urlChangeCommandId = Date.now(); // 使用时间戳作为唯一ID

               if (this.compose_args.onLoadStart) {
                 this.compose_args.onLoadStart();
               }
             } catch (e) {
               console.error("执行回调时出错:", e);
             }
           })
           .onPageEnd((event: OnPageEndEvent) => {
             console.info(`页面加载完成时更新 URL: ${event.url}`);
             // 页面加载完成时更新 URL
             this.currentUrl = event.url;
             // 通过更新参数通知Compose端
             this.compose_args.currentUrl = event.url;
             try {
               // 触发URL变更事件，通过增加commandId来通知变化
               this.compose_args.urlChangeCommandId = Date.now(); // 使用时间戳作为唯一ID

               if (this.compose_args.onLoadFinish) {
                 this.compose_args.onLoadFinish();
               }
             } catch (e) {
               console.error("执行回调时出错:", e);
             }
           })
        .onErrorReceive((event: GeneratedTypeLiteralInterface_1) => {
          try {
            if (this.compose_args.onLoadError) {
              const errorInfo = event.error.getErrorInfo();
              const errorCode = event.error.getErrorCode();
              this.compose_args.onLoadError(`Error: ${errorInfo}, Code: ${errorCode}`);
            }
          } catch (e) {
            console.error("执行onLoadError回调时出错:", e);
          }
        })
      .javaScriptAccess(this.compose_args.javaScriptEnabled)
      .domStorageAccess(this.compose_args.domStorageEnabled)
      .databaseAccess(this.compose_args.databaseEnabled)
      .cacheMode(this.compose_args.cacheMode === "default" ? CacheMode.Default : CacheMode.None)
      .width('100%')
      .height('80%')
    }
    .width('100%')
    .height('100%')
    .padding(10)
    .onAreaChange((_oldValue: Area) => {
      // 添加详细的调试日志
      console.info(`=== Navigation Debug ===`);
      console.info(`Current navigationCommandId: ${this.compose_args.navigationCommandId}`);
      console.info(`Local navigationCommandId: ${this.navigationCommandId}`);
      console.info(`Navigation command: ${this.navigationCommand}`);
      console.info(`Current URL from compose_args: ${this.compose_args.url}`);
      console.info(`Local currentUrl: ${this.currentUrl}`);

      // 检查参数是否存在
      if (this.compose_args.navigationCommandId === undefined) {
        console.info("navigationCommandId 未定义");
      } else {
        console.info("navigationCommandId 类型: " + typeof this.compose_args.navigationCommandId);
        console.info("navigationCommandId 值: " + this.compose_args.navigationCommandId);
      }

      if (this.compose_args.navigationCommand === undefined) {
        console.info("navigationCommand 未定义");
      } else {
        console.info("navigationCommand 类型: " + typeof this.compose_args.navigationCommand);
        console.info("navigationCommand 值: " + this.compose_args.navigationCommand);
      }

      console.info(`=== End of Debug ===`);

       try {
        // 检查URL是否发生变化
        if (this.compose_args.url !== this.currentUrl) {
           console.info(`检测到URL变化，从 ${this.currentUrl} 更新为 ${this.compose_args.url}`);
           if (this.compose_args.url && this.compose_args.url.trim() !== '') {
             this.currentUrl = this.compose_args.url;
           } else {
             console.warn("接收到空URL，忽略更新");
           }

           if (this.webviewController && this.currentUrl !== this.compose_args.url) {
             this.webviewController.loadUrl({
               url: this.currentUrl
             });
           }
         }

        // 检查是否有新的导航命令
        // 确保比较的是数值类型
        const currentId = this.compose_args.navigationCommandId !== undefined ?
          Number(this.compose_args.navigationCommandId) : undefined;
        const localId = Number(this.navigationCommandId);

        console.info(`转换后的ID比较 - Current: ${currentId}, Local: ${localId}`);

        if (currentId !== undefined && currentId !== localId) {
          console.info("检测到新的导航命令，准备处理");

          // 更新本地状态
          this.navigationCommandId = currentId;
          this.navigationCommand = this.compose_args.navigationCommand || '';
          console.info("更新本地状态完成，开始处理命令");

          // 根据命令执行相应操作
          this.handleNavigationCommand();
        } else if (currentId !== undefined) {
          console.info("导航命令ID相同，无需处理");
        } else {
          console.info("navigationCommandId 未定义，跳过处理");
        }
      } catch (e) {
        console.error("处理导航命令时出错:", e);
      }
    })

  }

    // 新增处理导航命令的方法
private handleNavigationCommand(): void {
    console.info(`处理导航命令: ${this.navigationCommand}, commandId: ${this.navigationCommandId}`);

    try {
      // 添加详细的命令处理日志
      switch (this.navigationCommand) {
        case "back":
          console.info("执行后退操作");
          try {
            if (this.webviewController && this.webviewController.accessBackward &&
                this.webviewController.backward && this.webviewController.accessBackward()) {
              this.webviewController.backward();
              console.info("后退操作执行成功");
              // 后退成功后更新当前URL并通知Compose端
              const newUrl = this.currentUrl;
              if (newUrl) {
                this.currentUrl = newUrl;
                this.compose_args.currentUrl = newUrl;
                this.compose_args.urlChangeCommandId = Date.now();
              }
              if (this.compose_args.onNavigateBack) {
                this.compose_args.onNavigateBack();
              }
            } else {
              console.info("无法后退 - 没有后退历史或控制器不可用");
            }
          } catch (e) {
            console.error("执行后退操作时出错:", e);
          }
          break;
        case "forward":
          console.info("执行前进操作");
          try {
            if (this.webviewController && this.webviewController.accessForward &&
                this.webviewController.forward && this.webviewController.accessForward()) {
              this.webviewController.forward();
              console.info("前进操作执行成功");
              // 前进成功后更新当前URL并通知Compose端
              const newUrl = this.currentUrl;
              if (newUrl) {
                this.currentUrl = newUrl;
                this.compose_args.currentUrl = newUrl;
                this.compose_args.urlChangeCommandId = Date.now();
              }
              if (this.compose_args.onNavigateForward) {
                this.compose_args.onNavigateForward();
              }
            } else {
              console.info("无法前进 - 没有前进历史或控制器不可用");
            }
          } catch (e) {
            console.error("执行前进操作时出错:", e);
          }
          break;
        case "loadUrl":
        case "reload":
          console.info("执行刷新操作");
          try {
            // 对于loadUrl和reload命令，重新加载当前URL
            if (this.webviewController) {
              this.webviewController.loadUrl({
                url: this.currentUrl
              });
              console.info("刷新操作执行成功");
              if (this.compose_args.onReload) {
                this.compose_args.onReload();
              }
            }
          } catch (e) {
            console.error("执行刷新操作时出错:", e);
          }
          break;
          case "home":
           console.info("执行首页操作，跳转到: " + this.compose_args.url);
           // 更新当前URL并重新加载，但要确保URL有效
                // 检查URL是否发生变化
      if (this.compose_args.url !== this.currentUrl) {
        console.info(`检测到URL变化，从 ${this.currentUrl} 更新为 ${this.compose_args.url}`);
        // 修复：只有在compose_args.url非空且不为空字符串时才更新currentUrl
        if (this.compose_args.url && this.compose_args.url.trim() !== '') {
          this.currentUrl = this.compose_args.url;

          if (this.webviewController && this.currentUrl !== this.compose_args.url) {
            this.webviewController.loadUrl({
              url: this.currentUrl
            });
          }
        } else {
          console.warn("接收到空URL或空字符串，忽略更新");
        }
      }

           if (this.compose_args.onGoHome) {
             this.compose_args.onGoHome();
           }
           break;
        default:
          console.info("未知导航命令: " + this.navigationCommand);

          // 如果是loadUrl命令但没有匹配上面的情况，则直接加载URL
          if (this.navigationCommand === "loadUrl") {
            console.info("直接加载URL: " + this.currentUrl);
            if (this.webviewController) {
              // 修复类型错误：将字符串包装成对象
              this.webviewController.loadUrl({
                url: this.currentUrl
              });
            }
          }
      }
    } catch (e) {
      console.error("处理导航命令时发生异常:", e);
    }
  }

}
