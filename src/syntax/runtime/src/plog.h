/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: plog.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2021/02/20
 * @brief: utils for log
*/

#ifndef __PLOG_H__
#define __PLOG_H__

#include <stdio.h>

#ifdef DEBUG_ANTLR
#define PLOG(fmt, ...) {printf(fmt, ##__VA_ARGS__);}
#else
#define PLOG(fmt, ...) {}
#endif

#endif