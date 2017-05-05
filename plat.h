/**
 * Copyright (c), 2012~2017 iot.10086.cn All Rights Reserved
 * @file 		plat.h
 * @brief 
 * @author 		宋伟<songwei1@iot.chinamobile.com>
 * @date 		2017/04/20
 * @version 	1.0.0
 * @par Revision History:
 * 		Date			Author		Revised.Ver		Notes
 * 		2017/04/20		宋伟		  1.0.0			file created
 */
#ifndef __PLAT_H__
#define __PLAT_H__

/*****************************************************************************/
/* Includes                                                                  */
/*****************************************************************************/

#ifdef _cplusplus
extern "C"{
#endif   


/*****************************************************************************/
/* External Definition（Constant and Macro )                                 */
/*****************************************************************************/





/*****************************************************************************/
/* External Structures, Enum and Typedefs                                    */
/*****************************************************************************/

/*****************************************************************************/
/* External Function Prototypes                                              */
/*****************************************************************************/
void plat_delay(unsigned int ms);

void *plat_malloc(unsigned int size);

void plat_free(void *addr);

#ifdef _cplusplus
}
#endif   

#endif

