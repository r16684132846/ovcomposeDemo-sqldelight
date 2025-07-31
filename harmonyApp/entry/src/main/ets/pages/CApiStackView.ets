import  nativeNode from 'libentry.so';
import { NodeContent } from "@ohos.arkui.node"

class Params {
  insert: boolean = false;
  nodeContent: NodeContent;

  constructor(insert: boolean, nodeContent: NodeContent) {
    this.insert = insert;
    this.nodeContent = nodeContent;
  }
}

class MyNodeContent extends NodeContent {

}

@Builder
function buildNodeContent(params: Params) {
  Column() {
    ContentSlot(params.nodeContent)
  }
  .height("100%")
  .onAppear(() => {
  })
}

@Entry
@Component
export struct CApiStackView {
  @State insert: boolean = true;
  private nodeContent = new MyNodeContent();
  @State @Watch('watchContent') controlContent: boolean = true;

  aboutToAppear(): void {
    nativeNode.createNativeNodeStackView(this.nodeContent);
  }

  watchContent() {
    if (this.getDialogController() == true) {
      nativeNode.createNativeNodeStackView(this.nodeContent);
    }
  }

  build() {
    Column() {
      Scroll() {
        buildNodeContent(new Params(this.insert, this.nodeContent))
      }
    }
    .height('100%')
    .width('100%')
    .justifyContent(FlexAlign.Center)
    .alignItems(HorizontalAlign.Center)
  }
}

@Component
export struct CApiStackSingle {
  @State insert: boolean = true;
  private nodeContent = new MyNodeContent();
  @State @Watch('watchContent') controlContent: boolean = true;

  aboutToAppear(): void {
    nativeNode.createNativeNodeStackSingleView(this.nodeContent);
  }

  watchContent() {
    if (this.getDialogController() == true) {
      nativeNode.createNativeNodeStackSingleView(this.nodeContent);
    }
  }

  build() {
    Column() {
      Scroll() {
        buildNodeContent(new Params(this.insert, this.nodeContent))
      }
    }
    .height('100%')
    .width('100%')
    .justifyContent(FlexAlign.Center)
    .alignItems(HorizontalAlign.Center)
  }
}
