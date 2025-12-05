import {
  uploadFile,
  downloadFile,
  listFiles,
  deleteFile,
  getFileInfo,
  isFileExists,
  copyFile,
  deleteFolder
} from './S3Service'

@Entry
@Component
struct S3Page {
  @State message: string = 'S3 功能演示'
  @State fileInfo: string = ''
  @State fileList: string[] = []

  build() {
    Scroll() {
      Column() {
        Text(this.message)
          .fontSize(24)
          .fontWeight(FontWeight.Bold)
          .margin({ bottom: 20 })

        // 添加测试按钮
        Button('上传测试文件')
          .onClick(() => {
            this.testUpload()
          })
          .width('80%')
          .margin({ bottom: 10 })

        Button('下载测试文件')
          .onClick(() => {
            this.testDownload()
          })
          .width('80%')
          .margin({ bottom: 10 })

        Button('列出文件')
          .onClick(() => {
            this.listFiles()
          })
          .width('80%')
          .margin({ bottom: 10 })

        Button('获取文件信息')
          .onClick(() => {
            this.getFileInfo()
          })
          .width('80%')
          .margin({ bottom: 10 })

        Button('检查文件是否存在')
          .onClick(() => {
            this.checkFileExists()
          })
          .width('80%')
          .margin({ bottom: 10 })

        Button('删除文件')
          .onClick(() => {
            this.deleteFile()
          })
          .width('80%')
          .margin({ bottom: 10 })

        Button('复制文件')
          .onClick(() => {
            this.copyFile()
          })
          .width('80%')
          .margin({ bottom: 10 })

        Button('删除文件夹')
          .onClick(() => {
            this.deleteFolder()
          })
          .width('80%')
          .margin({ bottom: 10 })

        // 显示文件信息
        Text(this.fileInfo)
          .fontSize(16)
          .margin({ top: 20, bottom: 20 })
          .textAlign(TextAlign.Start)

        // 显示文件列表
        ForEach(this.fileList, (item: string, index: number) => {
          Text(item)
            .fontSize(14)
            .textAlign(TextAlign.Start)
            .margin({ bottom: 5 })
        }, (item: string) => item)
      }
      .width('100%')
      .padding(20)
    }
    .height('100%')
  }

  // 测试上传文件
  async testUpload() {
    try {
      // 创建一个简单的测试文件内容
      const content = '这是一个测试文件的内容'
      // 修复文本编码方式
      let fileContent = new Uint8Array(new ArrayBuffer(content.length));
      for (let i = 0; i < content.length; i++) {
        fileContent[i] = content.charCodeAt(i);
      }

      const success = await uploadFile('test.txt', fileContent);
      if (success) {
        this.message = '文件上传成功';
      } else {
        this.message = '文件上传失败';
      }
    } catch (error) {
      this.message = '上传过程中出现错误: ' + error.message;
    }
  }

  // 测试下载文件
  async testDownload() {
    try {
      const data = await downloadFile('test.txt');
      if (data) {
        // 修复文本解码方式
        let content = '';
        for (let i = 0; i < data.length; i++) {
          content += String.fromCharCode(data[i]);
        }
        this.message = '文件下载成功';
        this.fileInfo = '文件内容: ' + content;
      } else {
        this.message = '文件下载失败';
      }
    } catch (error) {
      this.message = '下载过程中出现错误: ' + error.message;
    }
  }

  // 列出文件
  async listFiles() {
    try {
      const files = await listFiles('');
      if (files) {
        this.fileList = files.map(file =>
        `文件名: ${file.Key}, 大小: ${file.Size} 字节, 修改时间: ${file.LastModified}`
        );
        this.message = `找到 ${files.length} 个文件`;
      } else {
        this.message = '获取文件列表失败';
      }
    } catch (error) {
      this.message = '获取文件列表时出现错误: ' + error.message;
    }
  }

  // 获取文件信息
  async getFileInfo() {
    try {
      const info = await getFileInfo('test.txt');
      if (info) {
        this.fileInfo =
          `文件名: ${info.name}\n大小: ${info.size} 字节\n修改时间: ${info.lastModified}\n类型: ${info.contentType}`;
        this.message = '获取文件信息成功';
      } else {
        this.message = '获取文件信息失败';
      }
    } catch (error) {
      this.message = '获取文件信息时出现错误: ' + error.message;
    }
  }

  // 检查文件是否存在
  async checkFileExists() {
    try {
      const exists = await isFileExists('test.txt');
      if (exists) {
        this.message = '文件存在';
      } else {
        this.message = '文件不存在';
      }
    } catch (error) {
      this.message = '检查文件存在性时出现错误: ' + error.message;
    }
  }

  // 删除文件
  async deleteFile() {
    try {
      const success = await deleteFile('test.txt');
      if (success) {
        this.message = '文件删除成功';
      } else {
        this.message = '文件删除失败';
      }
    } catch (error) {
      this.message = '删除文件时出现错误: ' + error.message;
    }
  }

  // 复制文件
  async copyFile() {
    try {
      const success = await copyFile('test.txt', 'test_copy.txt');
      if (success) {
        this.message = '文件复制成功';
      } else {
        this.message = '文件复制失败';
      }
    } catch (error) {
      this.message = '复制文件时出现错误: ' + error.message;
    }
  }

  // 删除文件夹
  async deleteFolder() {
    try {
      // 示例：删除 test_folder 文件夹
      const success = await deleteFolder('test_folder');
      if (success) {
        this.message = '文件夹删除成功';
      } else {
        this.message = '文件夹删除失败';
      }
    } catch (error) {
      this.message = '删除文件夹时出现错误: ' + error.message;
    }
  }
}
