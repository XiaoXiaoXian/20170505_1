/**
 * Copyright (c), 2012~2017 iot.10086.cn All Rights Reserved
 * @file 		Quectel_BC95.h
 * @brief       移远NB模组(Quectel BC95系列)操作接口，网络接口只支持UDP
 * @author 		宋伟<songwei1@iot.chinamobile.com>
 * @date 		2017/04/20
 * @version 	1.0.0
 * @par Revision History:
 * 		Date			Author		Revised.Ver		Notes
 * 		2017/04/20		宋伟		  1.0.0			file created
 */
#ifndef __QUECTEL_BC95_H__
#define __QUECTEL_BC95_H__

/*****************************************************************************/
/* Includes                                                                  */
/*****************************************************************************/

#ifdef _cplusplus
extern "C"{
#endif   


/*****************************************************************************/
/* External Definition（Constant and Macro )                                 */
/*****************************************************************************/
/**
 * @name 模组网络状态定义
 * @{ */
#define QUECTEL_CSCON_MASK  0x01
#define QUECTEL_CSCON_IDLE  0
#define QUECTEL_CSCON_CONNECTED 1

#define QUECTEL_CEREG_MASK  0x02
#define QUECTEL_CEREG_NOT_REGISTERD 0
#define QUECTEL_CEREG_REGISTERD 1

#define QUECTEL_CGATT_MASK  0x04
#define QUECTEL_CGATT_DETACHED  0
#define QUECTEL_CGATT_ATTACHED  1
/**  @} */

/*****************************************************************************/
/* External Structures, Enum and Typedefs                                    */
/*****************************************************************************/
/**
 * @brief 向模组发送数据的回调函数接口定义
 *
 * @param buf 需要发送的数据缓冲区
 * @param buf_len 需要发送的数据长度
 *
 * @return 
 */
typedef void (*Quectel_BC95_send_callback)(char *buf, unsigned int buf_len);

/**
 * @brief 模组响应结果定义
 */
typedef enum Quectel_response_type
{
    /** 无响应*/
    QUECTEL_RESPONSE_NONE = 0,
    /** 响应为OK*/
    QUECTEL_RESPONSE_CMD_ERROR,
    /** 响应为ERROR*/
    QUECTEL_RESPONSE_CMD_OK
} Quectel_response_type;

/*****************************************************************************/
/* External Function Prototypes                                              */
/*****************************************************************************/
/**
 * @brief 模组串口数据接收接口。用户收到来自模组的数据后，直接调用该接口传入，
 *        每次传入一个字节
 *
 * @param c
 */
void Quectel_BC95_recv_char(char c);

/**
 * @brief 获取模组当前网络状态
 *
 * @return 
 */
int Quectel_BC95_get_link_status(void);

/**
 * @brief 向模组发送命令并获取响应
 *
 * @param cmd 构造好的AT命令字符串
 * @param timeout 响应超时时间，单位ms
 * @param response 返回响应内容(除OK或ERROR外的非空行)
 *
 * @return 响应结果，参见enum Quectel_response_type
 */
int Quectel_BC95_send_cmd(unsigned char *cmd, unsigned int timeout, unsigned char **response);

/**
 * @brief 创建网络socket
 *
 * @param port 指定本地端口
 *
 * @return socket操作句柄，-1 - 失败，> 0 成功
 */
int Quectel_BC95_socket(unsigned short port);

/**
 * @brief 关闭网络socket
 *
 * @param socket 需要关闭的socket句柄
 *
 * @return -1 - 失败, 0 - 成功
 */
int Quectel_BC95_socket_close(int socket);

/**
 * @brief 通过网络发送数据
 *
 * @param socket 通过Quectel_BC95_socket创建的socket句柄
 * @param remote_addr 数据发送的目的地址，格式为“ip,port”字符串，ip为点分十进制格式
 * @param data 需要发送的数据缓冲区
 * @param data_len 需要发送的数据长度
 *
 * @return >= 0 发送的数据长度，-1 - 失败
 */
int Quectel_BC95_send_data(int socket, unsigned char *remote_addr, const unsigned char *data, unsigned int data_len);

/**
 * @brief 尝试从网络接收数据
 *
 * @param remote_addr 收到的数据的源地址，格式与发送函数中定义相同
 * @param data 用于保存接收数据的缓冲区
 * @param data_buf_len 缓冲区长度
 *
 * @return 接收到的数据长度
 */
int Quectel_BC95_recv_data(unsigned char *remote_addr, unsigned char *data, unsigned int data_buf_len);

/**
 * @brief 初始化模组操作接口
 *
 * @param cb 注册可以发送数据到模组的操作接口
 *
 * @return 
 */
int Quectel_BC95_init(Quectel_BC95_send_callback cb);
int Quectel_BC95_exit(void);


#ifdef _cplusplus
}
#endif   

#endif

