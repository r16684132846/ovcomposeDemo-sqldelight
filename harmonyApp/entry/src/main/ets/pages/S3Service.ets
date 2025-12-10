import {
  S3Client,
  PutObjectCommand,
  GetObjectCommand,
  DeleteObjectCommand,
  ListObjectsV2Command,
  HeadObjectCommand,
  CopyObjectCommand,
  PutObjectCommandInput
} from '@ohos/aws-sdk-client-s3';
import { common } from '@kit.AbilityKit';
import { fileIo, picker } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';


// 定义 S3 对象接口
interface S3Object {
  Key: string;
  LastModified: Date;
  ETag: string;
  Size: number;
  StorageClass: string;
}

/**
 * 文件信息接口
 */
interface FileInfo {
  name: string;
  size: number;
  lastModified: Date;
  contentType: string;
}

// S3 客户端配置
export const ACCESS_KEY = '4p9C203iaTfMsifJJZj'; //天翼云

// 密钥
export const SECRET_KEY = 'PI9Y22H37129VGA2UXM7KXOGIB7IOCJ95LYTWAM';

// 临时凭证
export const ACCESS_TOKEN =
  'wK/fyzzSJHZ18+LiRV5vfKeYHO+VtipM/5SdIXorIZLaR1PTxx8MQfe/arQrV5POefug4t8ettDQZOF+4iTH+IdgyENud1HZGDCnjmJen68bHwEXryXoHgyf4VoVs8Etz0mvgAzDpOIISOaSluDFUSOh11xNmtTI7s72q1aEVSzEnDKaGksvEUbRaf1z+B3yG3CP1LgyMIo5dFobOMfEzz/7A4ndCdjHa68WDD6XouwVrEF0w0JKMyM8S5vrduYw1vhwMh/svhTx7wjXiKC95I9K5y48ZyCDMytymPLlNHQDVOpWF/jAKJ3NQ8wWLIodatt0SGyOqQlB4x/O/fqsTnXzbNrQcmxZLVuWGwC6eNRKosZx8K6wugCeSQbObP5s/ZFRjLQTZmzmaXzbO6nZwiKAfZkLQu9hMdaSkaKlbVAUbYvK8cTNvuWKLj1XpvDbwevkYk2IF50M5rFcWL8zJ5c2jBAOM8C6sqKdwP+1C8U4UHif+kB8yS5S6jQTEAl1OtvDk3eKCKQK+uh2uJ2f0HtPbu22BGohNdEuIRddS2i4jQr6vKL/UKTtMrV9TpXIFHfb5kmXd6HmyOl+yiijeS+uPGBzyszel4E5SLhF006Il5AVsJak1qQwJi/QzvKvwJZiKI7vutDULWUwT/Eq6WDHjnxufWLA12iPB37QkJmcILOmKst6P42GfgEUPUttDcvOB876wyAjsgIRQzfLRkMnnH+z+FKXi6OBQF93rawtlbtkrHug3OgTwZ9p9VTJluDQ1o8V77pE8FjzBMtsUdj4KWXRdcnXvWXNqgk2titXOHFwF87WXsj5K7eYJSzYLNrsXhvU4CxfdmH3zOxvelaB5PCGJPfamjYouW1zurFuhIPgfE0QSr0s14DSAmuDBp6cNXXKk7b7Uw7D4lUQ2A==';

// 存储桶名称
export const BUCKET_NAME = 'notetest';

// 存储桶区域
const REGION = 'cn-south-1';

// 存储桶的终端节点
export const ENDPOINT = 'https://gd5oss.ctyunxs.cn';

// 文件前缀
export const PRE_PATH = 'touchnotes/userdata/note20000115837cdfa3cf3bb441b9639989928ae8f90/';


console.log('- 访问密钥:', ACCESS_KEY);
console.log('- 密钥长度:', SECRET_KEY.length);
console.log('- Token长度:', ACCESS_TOKEN.length);

// 创建上下文对象
const context = globalThis.abilityContext as common.UIAbilityContext;

// S3客户端配置参数
interface S3Config_2 {
  connectionTimeout: number;
  socketTimeout: number;
}

interface S3Config {
  accessKeyId: string;
  secretAccessKey: string;
  sessionToken: string;
}

interface S3Config_3 {
  region: string;
  endpoint: string;
  credentials: S3Config;
  forcePathStyle: boolean;
  tls: boolean;
  requestHandler: S3Config_2;
}

const S3_CLIENT_CONFIG: S3Config_3 = {
  region: REGION,
  endpoint: ENDPOINT,
  credentials: ({
    accessKeyId: ACCESS_KEY,
    secretAccessKey: SECRET_KEY,
    sessionToken: ACCESS_TOKEN
  } as S3Config),
  forcePathStyle: true,
  tls: true,
  requestHandler: ({
    connectionTimeout: 60000,
    socketTimeout: 600000
  } as S3Config_2),
};

// 创建 S3 客户端
export let s3Client = new S3Client(context, S3_CLIENT_CONFIG);

/**
 * 初始化S3服务
 * 这个方法应该在使用S3服务之前调用
 */
export function createS3Client(): void {
  console.log('arkts:- 创建 S3 客户端...');

  // 确保上下文对象已创建
  if (!context) {
    console.error('无法创建S3客户端：上下文对象未初始化');
    return;
  }

  try {
    // 创建S3客户端
    s3Client = new S3Client(context, S3_CLIENT_CONFIG);

    console.log('S3客户端初始化完成');
  } catch (error) {
    console.error('创建S3客户端时出错:', error);
  }
}


/**
 * 检查并刷新凭证
 * @param force 是否强制刷新
 */
export function checkAndRefreshToken(force: boolean = false): boolean {
  try {
    const expirationTimestamp = 1765396917385; // 凭证过期时间
    const currentTime = new Date().getTime();
    const timeDiff = expirationTimestamp - currentTime;

    if (force || timeDiff < 10 * 60 * 1000) {
      console.log('凭证即将过期或需要强制刷新，建议重新获取凭证');
      // 在实际应用中，这里应该调用API重新获取凭证
      console.error('凭证已过期，请更新凭证后再尝试操作');
      return true;
    }

    console.log('凭证检查通过，有效期至:', new Date(expirationTimestamp));
    return true;
  } catch (error) {
    console.error('检查凭证时出错:', error);
    return false;
  }
}

/**
 * 上传文件
 * @param relativePath 文件名
 * @param fileContent 文件内容
 */
globalThis.uploadFile = uploadFile

export async function uploadFile(relativePath: string, fileContent: ArrayBuffer): Promise<boolean> {
  try {
    // 检查凭证有效性
    if (!checkAndRefreshToken()) {
      console.error('凭证无效，无法上传文件');
      throw new Error('凭证已过期，请更新凭证后再尝试操作');
    }

    // 将 ArrayBuffer 转换为 Uint8Array
    const uint8ArrayContent = new Uint8Array(fileContent);

    const key = PRE_PATH + relativePath;
    console.log(`开始上传文件: ${key}`);
    console.log(`文件大小: ${uint8ArrayContent.byteLength} 字节`);

    // 使用明确的类型定义参数
    const params: PutObjectCommandInput = {
      Bucket: BUCKET_NAME,
      Key: key,
      Body: uint8ArrayContent,
      ContentType: 'application/octet-stream'
    };

    const command = new PutObjectCommand(params);

    console.log(`发送请求到存储桶: ${BUCKET_NAME}, Key: ${key}`);
    const response = await s3Client.send(command);
    console.log('文件上传成功:', response);
    return true;
  } catch (error) {
    console.error('文件上传失败:', error);
    console.error('错误名称:', error.name);
    console.error('错误消息:', error.message);
    console.error('错误代码:', error.code);

    if (error.$metadata) {
      console.error('请求ID:', error.$metadata.requestId);
      console.error('HTTP状态码:', error.$metadata.httpStatusCode);
    }

    // 尝试获取原始错误响应
    if (error.$response) {
      const body: string = await error.$response.body.transformToString();
      console.error('原始错误响应:', body); // 这通常包含天翼云的具体错误原因
    }

    // 特别关注400错误
    if (error.statusCode === 400 || error.$metadata?.httpStatusCode === 400) {
      console.error('400错误诊断:');
      console.error('1. 请求参数无效');
      console.error('2. 不支持的请求头部');
      console.error('3. 校验和计算问题');
    }

    // 特别关注403错误
    if (error.statusCode === 403 || error.$metadata?.httpStatusCode === 403) {
      console.error('403错误诊断:');
      console.error('1. 凭证权限不足');
      console.error('2. 存储桶策略限制');
      console.error('3. 对象的ACL设置问题');
      console.error('4. 服务端安全组或防火墙规则');
      console.error('5. 存储桶名称不匹配');
      console.error('6. 访问路径或前缀不正确');

      // 检查是否是凭证过期问题
      const expirationTimestamp = 1765396917385;
      const currentTime = new Date().getTime();
      if (ACCESS_TOKEN && expirationTimestamp && currentTime > expirationTimestamp) {
        console.error('确认：临时凭证已过期，请获取新的凭证');
      } else {
        console.error('凭证尚未过期，可能是权限配置问题，请检查:');
        console.error('- 存储桶名称是否正确:', BUCKET_NAME);
        console.error('- 访问路径前缀是否正确:', PRE_PATH);
        console.error('- 凭证是否有足够的权限执行此操作');
      }
    }

    // 特别关注网络超时错误
    if (error.name === 'TimeoutError' || error.message.includes('timeout')) {
      console.error('网络超时错误:');
      console.error('1. 网络连接不稳定');
      console.error('2. 服务器响应超时');
      console.error('3. 文件过大上传耗时较长');
    }

    return false;
  }
}


/**
 * 下载文件
 * @param relativePath 文件名
 * @returns 文件内容
 */
globalThis.downloadFile = downloadFile

export async function downloadFile(relativePath: string): Promise<ArrayBuffer | null> {
  try {
    const key = PRE_PATH + relativePath;
    const command = new GetObjectCommand({
      Bucket: BUCKET_NAME,
      Key: key
    });

    const response = await s3Client.send(command);

    if (response.Body === undefined) {
      console.error('响应体为空');
      return null;
    }

    let arrayBuffer: ArrayBuffer;

    if (typeof response.Body === 'string') {
      // 字符串 → 手动转为 ArrayBuffer（注意：这仅适用于 ASCII/UTF-8 文本）
      const str: string = response.Body;
      const buffer: ArrayBuffer = new ArrayBuffer(str.length);
      const view: Uint8Array = new Uint8Array(buffer);
      for (let i: number = 0; i < str.length; i++) {
        view[i] = str.charCodeAt(i);
      }
      arrayBuffer = buffer;
      await saveToDocument('111.txt', response.Body);
    } else if (response.Body instanceof ArrayBuffer) {
      arrayBuffer = response.Body; // ✅ 直接使用
    } else if (response.Body instanceof Uint8Array) {
      // Uint8Array → 提取其底层 buffer 并确保返回 ArrayBuffer
      const uint8Array: Uint8Array = response.Body;
      const buffer: ArrayBuffer = uint8Array.buffer.slice(
        uint8Array.byteOffset,
        uint8Array.byteOffset + uint8Array.byteLength
      ) as ArrayBuffer;
      arrayBuffer = buffer;
    } else if (typeof response.Body.transformToByteArray === 'function') {
      // 假设 transformToByteArray 返回 ArrayBuffer 或 Uint8Array
      const result: Uint8Array | ArrayBuffer = await response.Body.transformToByteArray();
      if (result instanceof Uint8Array) {
        // 如果是 Uint8Array，提取其底层 buffer 并确保返回 ArrayBuffer
        const uint8Array: Uint8Array = result;
        const buffer: ArrayBuffer = uint8Array.buffer.slice(
          uint8Array.byteOffset,
          uint8Array.byteOffset + uint8Array.byteLength
        ) as ArrayBuffer;
        arrayBuffer = buffer;
      } else if (result instanceof ArrayBuffer) {
        arrayBuffer = result;
      } else {
        console.error('transformToByteArray returned unexpected type:', typeof result);
        return null;
      }
    } else {
      console.error('未知的 Body 类型:', typeof response.Body, response.Body);
      return null;
    }

    // ✅ 确保最终返回的是 ArrayBuffer
    return arrayBuffer;

  } catch (error) {
    console.error('文件下载失败:', error);

    // 特别处理404错误（文件不存在）
    if (error.name === 'NoSuchKey' || error.statusCode === 404) {
      console.error(`文件 ${relativePath} 不存在`);
    }

    // 处理权限错误
    if (error.statusCode === 403 || error.$metadata?.httpStatusCode === 403) {
      console.error('下载文件时权限不足');
      console.error('请检查:');
      console.error('- 存储桶名称是否正确:', BUCKET_NAME);
      console.error('- 文件路径是否正确:', PRE_PATH + relativePath);
      console.error('- 凭证是否有读取权限');
    }

    return null;
  }
}

export function saveToDocument(relativePath: string, content: string | ArrayBuffer): Promise<void> {
  return new Promise((resolve, reject) => {
    try {
      let documentSaveOptions = new picker.DocumentSaveOptions();
      documentSaveOptions.newFileNames = [relativePath];
      let documentPicker = new picker.DocumentViewPicker(getContext());
      documentPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
        console.info('DocumentViewPicker.save successfully, documentSaveResult uri: ' +
        JSON.stringify(documentSaveResult));
        let file = fileIo.openSync(documentSaveResult[0], fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
        fileIo.writeSync(file.fd, content);
        fileIo.closeSync(file);
        resolve()
      }).catch((err: BusinessError) => {
        console.error(`DocumentViewPicker.save failed with err, code is: ${err.code}, message is: ${err.message}`);
        reject(err)
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`DocumentViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
      reject(error)
    }
  })
}

/**
 * 获取文件信息
 * @param relativePath 文件名
 * @returns 文件信息
 */
globalThis.getFileInfo = getFileInfo

export async function getFileInfo(relativePath: string): Promise<FileInfo | null> {
  try {
    const key = PRE_PATH + relativePath;
    const command = new HeadObjectCommand({
      Bucket: BUCKET_NAME,
      Key: key
    });

    const response = await s3Client.send(command);

    // 处理可能的 undefined 值
    const size = response.ContentLength !== undefined ? response.ContentLength : 0;
    const lastModified = response.LastModified !== undefined ? response.LastModified : new Date();
    const contentType = response.ContentType !== undefined ? response.ContentType : 'application/octet-stream';

    return {
      name: relativePath,
      size: size,
      lastModified: lastModified,
      contentType: contentType
    };
  } catch (error) {
    console.error('获取文件信息失败:', error);

    // 处理权限错误
    if (error.statusCode === 403 || error.$metadata?.httpStatusCode === 403) {
      console.error('获取文件信息时权限不足');
      console.error('请检查:');
      console.error('- 存储桶名称是否正确:', BUCKET_NAME);
      console.error('- 文件路径是否正确:', PRE_PATH + relativePath);
      console.error('- 凭证是否有读取权限');
    }

    return null;
  }
}

class S3Error extends Error {
  public readonly code: number;

  constructor(message: string, code: number = -1) {
    super(message);
    this.code = code;
  }
}

/**
 * 判断文件是否存在
 * @param relativePath 文件名
 * @returns 是否存在
 */
globalThis.existsFile = existsFile

export async function existsFile(relativePath: string): Promise<boolean> {
  try {
    const key = PRE_PATH + relativePath;
    const command = new HeadObjectCommand({
      Bucket: BUCKET_NAME,
      Key: key
    });

    await s3Client.send(command);
    return true;
  } catch (error) {
    // 如果是 404 错误，则文件不存在
    if (error.name === 'NotFound' || error.statusCode === 404) {
      return false;
    }

    // 处理权限错误
    if (error.statusCode === 403 || error.$metadata?.httpStatusCode === 403) {
      console.error('检查文件存在性时权限不足');
      console.error('请检查:');
      console.error('- 存储桶名称是否正确:', BUCKET_NAME);
      console.error('- 文件路径是否正确:', PRE_PATH + relativePath);
      console.error('- 凭证是否有读取权限');
    }

    // 创建自定义错误
    const customError = new S3Error(`S3 操作失败: ${error.message}`, error.code || -1);
    console.error('检查文件存在性时出错:', customError);
    throw customError;
  }
}

/**
 * 列出文件夹中的对象
 * @param prefix 文件夹前缀
 * @returns 文件列表
 */
globalThis.listObjects = listObjects

export async function listObjects(prefix?: string): Promise<S3Object[] | null> {
  try {
    const fullPrefix = PRE_PATH + (prefix ? prefix : '');
    const command = new ListObjectsV2Command({
      Bucket: BUCKET_NAME,
      Prefix: fullPrefix
    });

    const response = await s3Client.send(command);

    // 处理返回的 Contents 数据
    if (response.Contents && Array.isArray(response.Contents)) {
      // 将 _Object[] 转换为 S3Object[]
      return response.Contents.map(item => {
        // 创建一个符合 S3Object 接口的对象
        const s3Object: S3Object = {
          Key: item.Key || '',
          LastModified: item.LastModified || new Date(),
          ETag: item.ETag || '',
          Size: item.Size || 0,
          StorageClass: item.StorageClass || ''
        };
        return s3Object;
      });
    }

    return [];
  } catch (error) {
    console.error('获取文件列表失败:', error);
    return null;
  }
}


/**
 * 复制文件
 * @param relativePath 源文件名
 * @param toPath 目标文件名
 * @returns 是否复制成功
 */
globalThis.copy = copy

export async function copy(relativePath: string, toPath: string): Promise<boolean> {
  try {
    console.log(`开始通过下载上传方式复制文件: ${relativePath} -> ${toPath}`);

    // 首先下载源文件
    const fileContent = await downloadFile(relativePath);
    if (!fileContent) {
      console.error(`下载源文件失败: ${relativePath}`);
      return false;
    }

    // 然后将内容上传到目标路径
    const result = await uploadFile(toPath, fileContent);
    if (result) {
      console.log(`文件复制成功: ${relativePath} -> ${toPath}`);
    } else {
      console.error(`文件上传失败: ${toPath}`);
    }

    return result;
  } catch (error) {
    console.error('文件复制失败:', error);

    // 特别处理403错误
    if (error.statusCode === 403 || error.$metadata?.httpStatusCode === 403) {
      console.error('复制文件时权限不足');
      console.error('请检查:');
      console.error('- 存储桶名称是否正确:', BUCKET_NAME);
      console.error('- 源文件路径是否正确:', PRE_PATH + relativePath);
      console.error('- 目标文件路径是否正确:', PRE_PATH + toPath);
      console.error('- 凭证是否有足够的权限执行复制操作');
    }

    // 特别处理404错误（源文件不存在）
    if (error.name === 'NoSuchKey' || error.statusCode === 404) {
      console.error(`源文件 ${relativePath} 不存在`);
    }

    return false;
  }
}


/**
 * 删除文件
 * @param relativePath 文件名
 * @returns 是否删除成功
 */
globalThis.deleteFile = deleteFile

export async function deleteFile(relativePath: string): Promise<boolean> {
  try {
    const key = PRE_PATH + relativePath;
    const command = new DeleteObjectCommand({
      Bucket: BUCKET_NAME,
      Key: key
    });

    const response = await s3Client.send(command);
    console.log('文件删除成功:', response);
    return true;
  } catch (error) {
    console.error('文件删除失败:', error);
    return false;
  }
}

/**
 * 删除文件夹（删除具有指定前缀的所有文件）
 * @param folderPath 文件夹路径
 * @returns 是否删除成功
 */
globalThis.deleteFolder = deleteFolder

export async function deleteFolder(folderPath: string): Promise<boolean> {
  try {
    // 确保文件夹路径以 / 结尾
    const prefix = folderPath.endsWith('/') ? folderPath : folderPath + '/';
    const fullPrefix = PRE_PATH + prefix;

    // 列出文件夹中的所有文件
    const command = new ListObjectsV2Command({
      Bucket: BUCKET_NAME,
      Prefix: fullPrefix
    });

    const response = await s3Client.send(command);

    if (!response.Contents || response.Contents.length === 0) {
      console.log('文件夹为空或不存在');
      return true;
    }

    // 删除所有文件
    let allSuccess = true;
    for (const obj of response.Contents) {
      try {
        const deleteCommand = new DeleteObjectCommand({
          Bucket: BUCKET_NAME,
          Key: obj.Key
        });
        await s3Client.send(deleteCommand);
        console.log(`文件 ${obj.Key} 删除成功`);
      } catch (error) {
        console.error(`文件 ${obj.Key} 删除失败:`, error);
        allSuccess = false;
      }
    }

    return allSuccess;
  } catch (error) {
    console.error('删除文件夹时出错:', error);
    return false;
  }
}

