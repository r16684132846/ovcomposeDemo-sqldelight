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

import { appTasks } from '@ohos/hvigor-ohos-plugin';

export default {
  system: appTasks, /* Built-in plugin of Hvigor. It cannot be modified. */
  plugins: [
    // 添加 Native 模块构建配置
    {
      name: 'native-module',
      config: {
        modules: [
          {
            name: 'libentry.so',
            sourceDir: 'entry/src/main/cpp',
            buildType: 'shared',
            cflags: ['-std=c++17'],
            includeDirs: ['entry/src/main/cpp/include'],
            dependencies: [],
            outputDir: 'entry/libs'
          }
        ]
      }
    }
  ]
}
