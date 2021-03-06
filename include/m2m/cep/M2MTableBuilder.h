/*******************************************************************************
 * M2MTableBuilder.h
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

#pragma once

#ifndef M2MTABLEBUILDER_H_
#define M2MTABLEBUILDER_H_


#include "m2m/cep/M2MColumnList.h"
#include "m2m/db/SQLRunner.h"



#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */



/*******************************************************************************
 * クラス変数
 ******************************************************************************/
/**
 * テーブルのカラム情報を保持した構造体オブジェクト．<br>
 */
#ifndef M2MTableBuilder
typedef struct M2MTableBuilder
	{
	struct M2MTableBuilder *previous;
	struct M2MTableBuilder *next;
	unsigned char *tableName;
	M2MColumnList *columnList;
	} M2MTableBuilder;
#endif /* M2MTableBuilder */


/*******************************************************************************
 * 公開関数
 ******************************************************************************/
/**
 * 引数で指定されたSQLite3データベースに対し、テーブルを作成する。<br>
 *
 * @param[in] self		（カラム情報挿入済みの）テーブル構築オブジェクト
 * @param[in] database	テーブル作成対象のSQLite3データベース
 */
void M2MTableBuilder_createTable (M2MTableBuilder *self, sqlite3 *database);


/**
 * 引数で指定されたテーブル構築オブジェクトのメモリ領域を解放する．<br>
 * この関数を呼び出した後は当該変数にアクセス出来なくなる事に留意する．<br>
 *
 * @param[in,out] self	（ヒープ）メモリ領域解放対象のテーブル構築オブジェクト
 */
void M2MTableBuilder_delete (M2MTableBuilder **self);


/**
 * 引数で指定されたテーブル構築オブジェクトからテーブル名に一致するカラム構造体オブジェクトを取得する．
 *
 * @param self		テーブル構築オブジェクト
 * @param tableName	テーブル名を示す文字列
 * @return			テーブル名が一致したカラム構造体オブジェクト or NULL（エラーの場合)
 */
M2MColumnList *M2MTableBuilder_getColumnList (M2MTableBuilder *self, const unsigned char *tableName);


/**
 * 引数で指定されたテーブル名に対し、テーブル情報（フィールド名）を表示するための<br>
 * SQL文を構築し、引数で指定されたポインタにコピーする。<br>
 *
 * @param[in] tableName	テーブル名を示す文字列
 * @param[out] sql		SQL文をコピーするためのポインタ（バッファリングは関数内部で実行する）
 * @return				引数のポインタにコピーした文字列 or NULL（エラーの場合）
 */
unsigned char *M2MTableBuilder_getTableInfoSQL (const unsigned char *tableName, unsigned char **sql);


/**
 * ヒープメモリ領域を獲得し，新規にテーブル構築オブジェクトを作成する．<br>
 *
 * @return		新規作成したテーブル構築オブジェクト
 */
M2MTableBuilder *M2MTableBuilder_new ();


/**
 * 引数で指定されたカラム情報を、同じく引数で指定されたテーブル構築オブジェクトに<br>
 * 格納する。<br>
 *
 * @param[in,out] self		テーブル作成のためのカラム設定情報を格納したテーブル構築オブジェクト
 * @param[in] tableName		テーブル名を示す文字列
 * @param[in] columnList	カラム設定情報を格納したカラム構造体オブジェクト
 * @return					カラム設定情報を含むテーブル構築オブジェクト or NULL（エラーの場合)
 */
M2MTableBuilder *M2MTableBuilder_setConfig (M2MTableBuilder *self, const unsigned char *tableName, M2MColumnList *columnList);



#ifdef __cplusplus
}
#endif /* __cplusplus */



#endif /* M2MTABLEBUILDER_H_ */
