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
export const ACCESS_KEY = 'LYHpaojJs57UYbjLTXd'; //天翼云

// 密钥
export const SECRET_KEY = '5J9UY7Y0K1JET14Y1SRFQ5MV46JD9IUDFCB9YH5';

// 临时凭证
export const ACCESS_TOKEN =
  'P0EdyTS7YDFE1a3s+tqFsiDTGqx/XoRHlgHzLG7kWc8dpVWe0DnWoYRfqo+6SZ5qluuQfEiBwxlGvStI3ifZksgGBQCuNHy/6SyubLzMolTojOe/jtvihJbewfQJHtbdMRQC1zDRIIQmW3YVWB23ueru+LQtga3eyXOEYu4oOz/HrquUKkHOyM4vMBDkJKYJvf356qicQVwHDoy0PixbhdCLIPJ+eaQJU/HfelWl6xlVi+U4TfQe1qJaAbp5I+/M4LOU0FL0soniyrLFB58sarB9N1U4UMoqoR1Yy4LK5Q8uJA2C4YXvlvbJ3u4FsWcBfinqi7Qr8sm3vjgKRB3za6PSugNjwsmARZyf5cLnz6gjH2+ambuqbftBOuZ/0f005R43dS0wEb9Gb3aBUvDNrOekovSxCHAp9fRhL3yjQtdF5bOlEUu7tv7lpaG0P8SmKHhlD7DQ0U4R1lroh2ym0cDAQKZH9ZM03YCoVce53ZJ+48Ia3mtiYoVOIteqMzNbipv6S6T0OCzCRzUN76yrv+6Fj/O+sOSb6SCMhVt31otOTCAN6YMCFbHDn8sv5Baec6CqELOCiUuzbgh9CAMgJESlcWqMf+ZDyQCxE5Wp/85AV6XUgciAnEv8lmNGfdFY8MdOqRkh0VVZUVY7WsiY4Z8Ff3dVNED1larvC0KLGW0Ro8r5H/U6THgY+ks1KKO76iwzmEgJQEr/dTsgLCbFtEZuJgOJ65ojT2hr9UxPWfvV+md7xclX3RpqMvdg6lbXfTfC6hXbEJHskk8jJ/fi/vZu6+yFVVFyTWuvsIntfyGxZXcSMaV46XWNjr2zbd/8prNf3p/9Vz4ssfujiJezMI+ELARjR3g89jXfCIGFTfKMDO6PHky4uayKuspqyodekZ80q8EyODiL6UoZS6sldg==';

// 存储桶名称
export const BUCKET_NAME = 'notetest';

// 存储桶区域
const REGION = 'cn-south-1';

// 存储桶的终端节点
export const ENDPOINT = 'https://gd5oss.ctyunxs.cn';

// 文件前缀
export const PRE_PATH = 'touchnotes/userdata/note20000115837cdfa3cf3bb441b9639989928ae8f90/';

// export const PRE_PATH = ''

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
export function s3ClientInit(): void {
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
    const expirationTimestamp = 1765304962126; // 凭证过期时间
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
 * @param fileName 文件名
 * @param fileContent 文件内容
 */
globalThis.uploadFile = uploadFile

export async function uploadFile(fileName: string, fileContent: ArrayBuffer): Promise<boolean> {
  try {
    // 检查凭证有效性
    if (!checkAndRefreshToken()) {
      console.error('凭证无效，无法上传文件');
      throw new Error('凭证已过期，请更新凭证后再尝试操作');
    }

    // 将 ArrayBuffer 转换为 Uint8Array
    const uint8ArrayContent = new Uint8Array(fileContent);

    const key = PRE_PATH + fileName;
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
      const expirationTimestamp = 1765304962126;
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
 * @param fileName 文件名
 * @returns 文件内容
 */
globalThis.downloadFile = downloadFile

export async function downloadFile(fileName: string): Promise<ArrayBuffer | null> {
  try {
    const key = PRE_PATH + fileName;
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
      console.error(`文件 ${fileName} 不存在`);
    }

    // 处理权限错误
    if (error.statusCode === 403 || error.$metadata?.httpStatusCode === 403) {
      console.error('下载文件时权限不足');
      console.error('请检查:');
      console.error('- 存储桶名称是否正确:', BUCKET_NAME);
      console.error('- 文件路径是否正确:', PRE_PATH + fileName);
      console.error('- 凭证是否有读取权限');
    }

    return null;
  }
}

export function saveToDocument(filename: string, content: string | ArrayBuffer): Promise<void> {
  return new Promise((resolve, reject) => {
    try {
      let documentSaveOptions = new picker.DocumentSaveOptions();
      documentSaveOptions.newFileNames = [filename];
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
 * 列出文件夹中的对象
 * @param prefix 文件夹前缀
 * @returns 文件列表
 */
globalThis.listFiles = listFiles

export async function listFiles(prefix?: string): Promise<S3Object[] | null> {
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
 * 获取文件信息
 * @param fileName 文件名
 * @returns 文件信息
 */
globalThis.getFileInfo = getFileInfo

export async function getFileInfo(fileName: string): Promise<FileInfo | null> {
  try {
    const key = PRE_PATH + fileName;
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
      name: fileName,
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
      console.error('- 文件路径是否正确:', PRE_PATH + fileName);
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
 * @param fileName 文件名
 * @returns 是否存在
 */
globalThis.isFileExists = isFileExists

export async function isFileExists(fileName: string): Promise<boolean> {
  try {
    const key = PRE_PATH + fileName;
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
      console.error('- 文件路径是否正确:', PRE_PATH + fileName);
      console.error('- 凭证是否有读取权限');
    }

    // 创建自定义错误
    const customError = new S3Error(`S3 操作失败: ${error.message}`, error.code || -1);
    console.error('检查文件存在性时出错:', customError);
    throw customError;
  }
}

/**
 * 删除文件
 * @param fileName 文件名
 * @returns 是否删除成功
 */
globalThis.deleteFile = deleteFile

export async function deleteFile(fileName: string): Promise<boolean> {
  try {
    const key = PRE_PATH + fileName;
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
 * 复制文件
 * @param sourceFileName 源文件名
 * @param targetFileName 目标文件名
 * @returns 是否复制成功
 */
globalThis.copyFile = copyFile

export async function copyFile(sourceFileName: string, targetFileName: string): Promise<boolean> {
  try {
    const sourceKey = PRE_PATH + sourceFileName;
    const targetKey = PRE_PATH + targetFileName;

    // 使用 CopyObjectCommand 直接复制文件，而不是下载再上传
    const command = new CopyObjectCommand({
      Bucket: BUCKET_NAME,
      Key: targetKey,
      CopySource: `${BUCKET_NAME}/${sourceKey}`,
      // 可选：设置目标对象的 Metadata 或 StorageClass 等
      // MetadataDirective: 'REPLACE', // 可选：是否替换元数据，默认是 'COPY'（继承源对象的元数据）
      // Metadata: {                  // 可选：自定义元数据（仅在 MetadataDirective 为 'REPLACE' 时生效）
      //   'author': 'John Doe',
      //   'description': 'Copied file',
      // },
      // StorageClass: 'STANDARD',    // 可选：设置存储类别，如 'STANDARD', 'GLACIER' 等
    });

    const response = await s3Client.send(command);
    console.log('文件复制成功:', response);
    return true;
  } catch (error) {
    console.error('文件复制失败:', error);

    // 特别处理403错误
    if (error.statusCode === 403 || error.$metadata?.httpStatusCode === 403) {
      console.error('复制文件时权限不足');
      console.error('请检查:');
      console.error('- 存储桶名称是否正确:', BUCKET_NAME);
      console.error('- 源文件路径是否正确:', PRE_PATH + sourceFileName);
      console.error('- 目标文件路径是否正确:', PRE_PATH + targetFileName);
      console.error('- 凭证是否有足够的权限执行复制操作');
    }

    // 特别处理404错误（源文件不存在）
    if (error.name === 'NoSuchKey' || error.statusCode === 404) {
      console.error(`源文件 ${sourceFileName} 不存在`);
    }

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

