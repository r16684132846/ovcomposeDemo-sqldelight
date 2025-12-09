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
export const ACCESS_KEY = 'WhZPjFVcxkfAWfjoRz0'; //天翼云

// 密钥
export const SECRET_KEY = '8I2B1ZOZBC9CKUXPA1GB84JZSGCXK0105B7ED5E';

// 临时凭证
export const ACCESS_TOKEN =
  '/kzCbFMxsPxBoNMkdVnNuNNR2v+sPalVZvgvGKpc7tYyfc/5Ga6e4KGB6KpFowNi3XUMtRnBUMy6dLqOE/BGbNyzuVaWoZiMh5uYuLlu/K25U5aQq4FzCQzqxtU/miTfj6yTzORHjqKeTXQdxD25KE5QuzVIRx1HFSoT4LQ5fQDtYqxYx61/KqBRl0tAmAUbB5SWx1l/j9o6kzStn+xYPZXuNHJmQhd9AvLZ1GHVWmG/si3JKqCKCkngNOBIX8hWi53hO2EVaPpD1D9Qc7jHR1TkBFdTR2LiwMGjCidk9YeqJqb5aPeEZt3slJfNmOAc/w4GVEKZWOdHL5iNmPO5UZnJ2ulfR0QffdP+7vtMMBLhZvC1ubLexfBRTV5n3MX4U9Dug0FDewo4IVsnYh7qrAVgNpuKrhqI6ZoLHbOZ1ZRy/VoWfNm8DcsAQCpx3gEM7iP0a1pG6B+Z/0RpsQFCnonL1nsPdWqa6UJofSWHaoVn/YmCj0BIbu8MGlG5eplPEKdoodWAyqLWzloiLQv3D56qUqcjgPjzG2rkTLpdcdAN0lZv2XlFUss9ty9tACOXr3bv2aLrRnOPovGTIcZ7Qqj634rvvgDA7wgN0pt5+w5Cez5AaGJTXgiICxccrlXlh1+ME8r0v5J7I3tocGJUk6IykSjpiGL2byUZEa4xMyN6psPDWarr1QrF420I7+No6phNnjepyfX2vWYESw+IACA4agSbkncTFf3ikQNRCoAGduQjrW2yPLWM47xPYacKuy6d8jNt3FLRR3yPTZFl1xqe5mww34MGoDxT/1Zrp+GpgSnCWayUndpUebYHefzPDrXkeJg6faF69p375C4qRf9hIxgOau1T/F+NaPpQPA1IIdsbwShiG8eSqGL+KyOrh9Kn0RG4+HAvB/m7FPIpcA==';

// 存储桶名称
export const BUCKET_NAME = 'notetest';

// 存储桶区域
const REGION = 'cn-south-1';

// 存储桶的终端节点
export const ENDPOINT = 'https://gd5oss.ctyunxs.cn';

// 文件前缀
// export const PRE_PATH = 'touchnotes/userdata/note20000115837cdfa3cf3bb441b9639989928ae8f90/';
export const PRE_PATH = ''

console.log('- 访问密钥:', ACCESS_KEY);
console.log('- 密钥长度:', SECRET_KEY.length);
console.log('- Token长度:', ACCESS_TOKEN.length);

// 创建上下文对象
const context = globalThis.abilityContext as common.UIAbilityContext;

// 创建 S3 客户端
export const s3Client = new S3Client(
  context,
  {
    region: REGION,
    endpoint: ENDPOINT,
    credentials: {
      accessKeyId: ACCESS_KEY,
      secretAccessKey: SECRET_KEY,
      sessionToken: ACCESS_TOKEN
    },
    forcePathStyle: true,
    tls: true,
    requestHandler: {
      connectionTimeout: 60000,
      socketTimeout: 600000
    },
  }
);

/**
 * 检查并刷新凭证
 * @param force 是否强制刷新
 */
export function checkAndRefreshToken(force: boolean = false): boolean {
  try {
    const expirationTimestamp = 1765233728012; // 凭证过期时间
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

export async function uploadFile(fileName: string, fileContent: Uint8Array): Promise<boolean> {
  try {
    // 检查凭证有效性
    if (!checkAndRefreshToken()) {
      console.error('凭证无效，无法上传文件');
      throw new Error('凭证已过期，请更新凭证后再尝试操作');
    }

    const key = PRE_PATH + fileName;
    console.log(`开始上传文件: ${key}`);
    console.log(`文件大小: ${fileContent.byteLength} 字节`);

    // 使用明确的类型定义参数
    const params: PutObjectCommandInput = {
      Bucket: BUCKET_NAME,
      Key: key,
      Body: fileContent,
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
      const expirationTimestamp = 1765233728012;
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

export async function downloadFile(fileName: string): Promise<Uint8Array | null> {
  try {
    const key = PRE_PATH + fileName;
    const command = new GetObjectCommand({
      Bucket: BUCKET_NAME,
      Key: key
    });

    const response = await s3Client.send(command);

    // 检查 Body 是否存在
    if (response.Body === undefined) {
      console.error('响应体为空');
      return null;
    }

    // 根据参考资料中的处理方式，检查不同的 Body 类型
    if (typeof response.Body === 'string') {
      // 如果是字符串，转换为 Uint8Array
      // 使用替代方法：手动转换字符编码
      const arrayBuffer = new ArrayBuffer(response.Body);
      const view = new Uint8Array(arrayBuffer);

      // 添加类型断言来解决类型检查问题
      const bodyString = response.Body as string;

      for (let i = 0; i < bodyString.length; i++) {
        view[i] = bodyString.charCodeAt(i);
      }

      return view;
    } else if (response.Body instanceof ArrayBuffer) {
      // 如果是 ArrayBuffer，直接包装为 Uint8Array
      return new Uint8Array(response.Body);
    } else if (response.Body instanceof Uint8Array) {
      // 如果已经是 Uint8Array，直接返回
      return response.Body;
    } else if (typeof response.Body.transformToByteArray === 'function') {
      // 如果有 transformToByteArray 方法，调用它
      const arrayBuffer = await response.Body.transformToByteArray();
      return new Uint8Array(arrayBuffer);
    } else {
      console.error('未知的 Body 类型:', typeof response.Body);
      return null;
    }
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
