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
  canGoBack: boolean
  canGoForward: boolean
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
  @State @Watch('onNavigationChange') private navigationCommand: string = ''
  @State @Watch('onNavigationChange') private navigationCommandId: number = 0
  @State private lastHandledCommandId: number = -1

  aboutToAppear(): void {
    // 保存原始的URL，避免在初始化时重置导航历史
    const originalUrl = this.compose_args.url;

    if (originalUrl && originalUrl.trim() !== '') {
      this.currentUrl = originalUrl;
      console.info("设置初始URL和首页URL: " + this.currentUrl);
      //保留导航历史
    } else {
      console.warn("WebView URL 为空或无效，使用默认值");
      this.currentUrl = "about:blank";
    }
    // 确保在初始化时不会意外重置导航历史
    if (this.webviewController) {
      if (this.currentUrl !== "about:blank") {
        this.webviewController.loadUrl({
          url: this.currentUrl
        });
      }
    }
  }

  build() {
    Column() {
      Text("WebView Component")
        .fontSize(14)
        .fontWeight(FontWeight.Bold)
        .margin({ bottom: 10 })

      Text(`当前URL: ${this.compose_args.currentUrl}`)
        .fontSize(14)
        .maxLines(1)
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .onAreaChange((oldValue: Area, newValue: Area) => {
          this.onNavigationChange()
          console.info(`区域已改变: ${this.compose_args.currentUrl} - ${this.compose_args.url}`);
        })
      Web({
        src: this.currentUrl,
        controller: this.webviewController
      })
        .layoutWeight(1)
        .onPageBegin((event: OnPageBeginEvent) => {
          console.info(`页面开始加载时更新 URL: ${event.url}`);
          // 页面开始加载时更新 URL
          this.currentUrl = event.url;
          // 通过更新参数通知Compose端
          this.compose_args.currentUrl = event.url;
          try {
            // 触发URL变更事件，通过增加commandId来通知变化
            this.compose_args.urlChangeCommandId = Date.now(); // 使用时间戳作为唯一ID

            // 延迟更新导航状态，确保WebView有足够时间更新导航历史
            setTimeout(() => {
              this.updateNavigationState();
            }, 100);

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

            // 更新导航状态
            if (this.webviewController) {
              this.compose_args.canGoBack =
                this.webviewController.accessBackward ? this.webviewController.accessBackward() : false;
              this.compose_args.canGoForward =
                this.webviewController.accessForward ? this.webviewController.accessForward() : false;
            }
            // 延迟更新导航状态，确保WebView有足够时间更新导航历史
            setTimeout(() => {
              this.updateNavigationState();
            }, 100);

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

            // 错误时也更新导航状态
            setTimeout(() => {
              this.updateNavigationState();
            }, 100);
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
  }

  // 新增方法：统一更新导航状态
  private updateNavigationState(): void {
    if (this.webviewController) {
      try {
        const canGoBack = this.webviewController.accessBackward ? this.webviewController.accessBackward() : false;
        const canGoForward = this.webviewController.accessForward ? this.webviewController.accessForward() : false;
        console.info(`更新导航状态 - canGoBack: ${canGoBack}, canGoForward: ${canGoForward}`);
        this.compose_args.canGoBack = canGoBack;
        this.compose_args.canGoForward = canGoForward;

        // 保存旧的状态值用于比较
        const oldCanGoBack = this.compose_args.canGoBack;
        const oldCanGoForward = this.compose_args.canGoForward;
        console.info(`更新导航状态 - oldCanGoBack: ${oldCanGoBack}, oldCanGoForward: ${oldCanGoForward}`);

        if (oldCanGoBack !== canGoBack || oldCanGoForward !== canGoForward) {
          this.compose_args.urlChangeCommandId = Date.now();
        }
      } catch (e) {
        console.error("更新导航状态时出错:", e);
        // 出错时设为默认值   
        this.compose_args.canGoBack = false;
        this.compose_args.canGoForward = false;
      }
    }
  }

  // 导航命令处理逻辑
  private onNavigationChange(): void {
    // 检查导航命令变化
    const currentNavId = this.compose_args.navigationCommandId !== undefined ?
    Number(this.compose_args.navigationCommandId) : undefined;

    // 同时检查URL变化，但只在URL非空时更新
    if (this.compose_args.currentUrl && this.compose_args.currentUrl.trim() !== '' &&
      this.compose_args.currentUrl !== this.currentUrl) {
      console.info(`检测到compose_args.currentUrl变化，从 ${this.currentUrl} 更新为 ${this.compose_args.currentUrl}`);
      this.currentUrl = this.compose_args.currentUrl;

      // 如果是URL更新命令，立即加载新的URL
      if (this.compose_args.navigationCommand === "updateUrl" && this.webviewController) {
        this.webviewController.loadUrl({
          url: this.currentUrl
        });
        console.info(`已加载更新后的URL: ${this.currentUrl}`);

        // 更新导航状态
        setTimeout(() => {
          this.updateNavigationState();
        }, 100);
      }
    }

    // 确保不会在处理导航命令时意外重置URL
    if (currentNavId !== undefined && currentNavId > this.lastHandledCommandId) {
      this.handleNavigationCommand();
    }
  }

  // 处理导航命令的方法
  private handleNavigationCommand(): void {
    // 直接从 compose_args 获取最新值而不是依赖状态变量
    const currentNavCommand = this.compose_args.navigationCommand !== undefined ?
    this.compose_args.navigationCommand : "";
    const currentNavId = this.compose_args.navigationCommandId !== undefined ?
    Number(this.compose_args.navigationCommandId) : 0;

    console.info(`处理导航命令: ${currentNavCommand}, commandId: ${currentNavId}`);

    try {
      switch (currentNavCommand) {
        case "back":
          console.info("执行后退操作");
          try {
            if (this.webviewController && this.webviewController.accessBackward &&
            this.webviewController.backward && this.webviewController.accessBackward()) {
              this.webviewController.backward();
              console.info("后退操作执行成功");
              // 后退成功后更新当前URL并通知Compose端
              // 注意：后退操作后URL会自动变化，我们会在onPageBegin中处理URL更新
              if (this.compose_args.onNavigateBack) {
                this.compose_args.onNavigateBack();
              }
              // 更新最后处理的命令ID，避免重复处理
              if (currentNavId > this.lastHandledCommandId) {
                this.lastHandledCommandId = currentNavId;
              }

              // 延迟更新导航状态
              setTimeout(() => {
                this.updateNavigationState();
              }, 100);

              return;
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
              if (this.compose_args.onNavigateForward) {
                this.compose_args.onNavigateForward();
              }

              // 延迟更新导航状态
              setTimeout(() => {
                this.updateNavigationState();
              }, 100);
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

              // 延迟更新导航状态
              setTimeout(() => {
                this.updateNavigationState();
              }, 100);
            }
          } catch (e) {
            console.error("执行刷新操作时出错:", e);
          }
          break;
        case "home":
          console.info("执行首页操作，跳转到: " + this.compose_args.url);
          //loadUrl 来导航到首页
          if (this.webviewController) {
            this.webviewController.loadUrl({
              url: this.compose_args.url
            });
          }
          // 检查URL是否发生变化
          if (this.compose_args.url !== this.currentUrl) {
            console.info(`检测到URL变化，从 ${this.currentUrl} 更新为 ${this.compose_args.url}`);
            if (this.compose_args.url && this.compose_args.url.trim() !== '') {
              this.currentUrl = this.compose_args.url;

              if (this.webviewController) {
                console.info("开始加载首页URL: " + this.currentUrl);
                this.webviewController.loadUrl({
                  url: this.currentUrl
                });
              }
            } else {
              console.warn("接收到空URL或空字符串，忽略更新");
            }
          } else {
            // 即使URL没有变化，也要确保加载页面
            if (this.webviewController) {
              console.info("URL未变化，但强制加载首页URL: " + this.currentUrl);
              this.webviewController.loadUrl({
                url: this.currentUrl
              });
            }
          }

          if (this.compose_args.onGoHome) {
            this.compose_args.onGoHome();
          }

          // 延迟更新导航状态
          setTimeout(() => {
            this.updateNavigationState();
          }, 100);
          break;
        case "":
          // 处理空命令的情况，当命令为空时默认加载当前URL
          if (this.currentUrl && this.currentUrl.trim() !== '') {
            console.info("处理空导航命令，加载当前URL: " + this.currentUrl);
            if (this.webviewController) {
              this.webviewController.loadUrl({
                url: this.currentUrl
              });
              console.info("空命令情况下URL加载成功");
            }
            // 延迟更新导航状态
            setTimeout(() => {
              this.updateNavigationState();
            }, 100);
          }
          break;

        default:
          console.info("未知导航命令: " + currentNavCommand);

        // 添加对URL更新的支持
          if (currentNavCommand === "updateUrl") {
            console.info("处理URL更新命令，新URL: " + this.compose_args.currentUrl);
            // 即使currentUrl为空，也使用url字段作为备选
            const targetUrl = (this.compose_args.currentUrl && this.compose_args.currentUrl.trim() !== '')
              ? this.compose_args.currentUrl
              : this.compose_args.url;

            if (targetUrl && targetUrl.trim() !== '') {
              this.currentUrl = targetUrl;
              if (this.webviewController) {
                this.webviewController.loadUrl({
                  url: this.currentUrl
                });
                console.info("URL更新成功并加载新页面: " + this.currentUrl);

                // 更新导航状态
                setTimeout(() => {
                  this.updateNavigationState();
                }, 100);
              }
            } else {
              console.warn("接收到空URL，忽略更新");
            }
          }

        // 如果是loadUrl命令但没有匹配上面的情况，则直接加载URL
          if (currentNavCommand === "loadUrl") {
            console.info("直接加载URL: " + this.currentUrl);
            if (this.webviewController) {
              // 修复类型错误：将字符串包装成对象
              this.webviewController.loadUrl({
                url: this.currentUrl
              });
            }
          }

        // 延迟更新导航状态
          setTimeout(() => {
            this.updateNavigationState();
          }, 100);
      }
    } catch (e) {
      console.error("处理导航命令时发生异常:", e);

      // 即使发生异常，也尝试更新导航状态
      setTimeout(() => {
        this.updateNavigationState();
      }, 100);
    }

    // 更新最后处理的命令ID，避免重复处理
    if (currentNavId > this.lastHandledCommandId) {
      this.lastHandledCommandId = currentNavId;
    }
  }
}
