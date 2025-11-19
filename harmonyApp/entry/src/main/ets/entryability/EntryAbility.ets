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

import { AbilityConstant, ConfigurationConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { initResourceManager } from 'libentry.so';
import { fileIo as fs } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { setDatabasePath, getDatabasePath } from 'libentry.so';

const DOMAIN = 0x0D04;

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    this.context.getApplicationContext().setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_NOT_SET);
    initResourceManager(this.context.resourceManager)
    // 设置数据库路径供native层使用
    this.setupDatabasePath();

    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onCreate');
  }

  onDestroy(): void {
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(DOMAIN, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        return;
      }
      hilog.info(DOMAIN, 'testTag', 'Succeeded in loading the content.');
    });
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onBackground');
  }


  // 设置数据库路径并确保目录存在
  private async setupDatabasePath(): Promise<void> {
    try {
      // 沙箱路径
      const dbDirectory = `${this.context.filesDir}/database`;
      hilog.info(DOMAIN, 'testTag', 'dbDirectory: %{public}s', dbDirectory);
      // 创建数据库文件
      const dbPath = `${dbDirectory}/my_database.db`;
      hilog.info(DOMAIN, 'testTag', 'dbPath: %{public}s', dbPath);
      // 确保数据库目录存在
      try {
        await fs.mkdir(dbDirectory, true);
        hilog.info(DOMAIN, 'testTag', 'Database directory created or already exists: %{public}s', dbDirectory);
      } catch (mkdirError) {
        hilog.warn(DOMAIN, 'test', 'Could not create directory (may already exist): %{public}s', mkdirError.message);
      }

      // 检查目录是否可写
      try {
        const testFile = `${dbDirectory}/test.tmp`;
        const stream = fs.createWriteStream(testFile);
        stream.write('test');
        stream.close();
        fs.unlinkSync(testFile);
        hilog.info(DOMAIN, 'testTag', 'Database directory is writable');
      } catch (error) {
        hilog.error(DOMAIN, 'testTag', 'Database directory is not writable: %{public}s', error.message);
        return;
      }

      /*// 创建空的数据库文件
      try {
        const fd = fs.openSync(dbPath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
        fs.closeSync(fd);
        hilog.info(DOMAIN, 'testTag', 'Database file created or already exists: %{public}s', dbPath);
      } catch (error) {
        hilog.error(DOMAIN, 'testTag', 'Failed to create database file: %{public}s', error.message);
      }*/

      // 将dbPath传递到native层
      setDatabasePath(dbPath);
      hilog.info(DOMAIN, 'testTag', 'Successfully set database path to: %{public}s', dbPath);
    } catch (error) {
      const businessError = error as BusinessError;
      hilog.error(DOMAIN, 'testTag', 'Failed to setup database path. Error: %{public}s, Code: %{public}d',
        businessError.message, businessError.code);
    }
  }
}