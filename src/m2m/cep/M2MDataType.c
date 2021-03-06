/*******************************************************************************
 * M2MDataType.c
 *
 * Copyright (c) 2014, Akihisa Yasuda
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

#include "m2m/cep/M2MDataType.h"


/*******************************************************************************
 * 公開関数
 ******************************************************************************/
/**
 * 引数で指定された列挙子を文字列に変換して返す。<br>
 *
 * @param[in] self	データ型を示す列挙子
 * @return			列挙子の名前を示す文字列 or NULL（エラーの場合）
 */
unsigned char *M2MDataType_toString (const M2MDataType self)
	{
	if (self==M2M_DATA_TYPE_BLOB)
		{
		return (unsigned char *)"BLOB";
		}
	else if (self==M2M_DATA_TYPE_BOOL)
		{
		return (unsigned char *)"BOOL";
		}
	else if (self==M2M_DATA_TYPE_CHAR)
		{
		return (unsigned char *)"CHAR";
		}
	else if (self==M2M_DATA_TYPE_DATETIME)
		{
		return (unsigned char *)"DATETIME";
		}
	else if (self==M2M_DATA_TYPE_DOUBLE)
		{
		return (unsigned char *)"DOUBLE";
		}
	else if (self==M2M_DATA_TYPE_ERROR)
		{
		return NULL;
		}
	else if (self==M2M_DATA_TYPE_FLOAT)
		{
		return (unsigned char *)"FLOAT";
		}
	else if (self==M2M_DATA_TYPE_INTEGER)
		{
		return (unsigned char *)"INTEGER";
		}
	else if (self==M2M_DATA_TYPE_NUMERIC)
		{
		return (unsigned char *)"NUMERIC";
		}
	else if (self==M2M_DATA_TYPE_REAL)
		{
		return (unsigned char *)"REAL";
		}
	else if (self==M2M_DATA_TYPE_TEXT)
		{
		return (unsigned char *)"TEXT";
		}
	else if (self==M2M_DATA_TYPE_VARCHAR)
		{
		return (unsigned char *)"VARCHAR";
		}
	else
		{
		return NULL;
		}
	}




/* End Of File */
