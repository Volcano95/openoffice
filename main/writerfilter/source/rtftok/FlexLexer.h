/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/


#ifndef __FLEX_LEXER_H
// Never included before - need to define base class.
#define __FLEX_LEXER_H
//#include <iostream.h>
typedef void ostream;
#include <vector>
#include <rtftok/RTFInputSource.hxx>

extern "C++" {

struct yy_buffer_state;
typedef int yy_state_type;
  
}
#include <rtftok/RTFScanner.hxx>
#endif

#if defined(yyFlexLexer) || ! defined(yyFlexLexerOnce)
// Either this is the first time through (yyFlexLexerOnce not defined),
// or this is a repeated include to define a different flavor of
// yyFlexLexer, as discussed in the flex man page.
#define yyFlexLexerOnce

class yyFlexLexer : public writerfilter::rtftok::RTFScanner {
private:
	class RtfTokenizer* tokenizerInstance;

	void split_ctrl(char *yytext, char* token, char *value);
	void raise_ctrl(char* yytext);
	void raise_dest(char* yytext);
	void raise_destOrCtrl(char* yytext);
protected:
	int num_lines;
	sal_uInt64 num_chars;
	int star_flag;

public:
	// arg_yyin and arg_yyout default to the cin and cout, but we
	// only make that assignment when initializing in yylex().
	yyFlexLexer( class writerfilter::rtftok::RTFInputSource* arg_yyin, class writerfilter::rtftok::RTFScannerHandler &eventHandler );

	virtual ~yyFlexLexer();

	void yy_switch_to_buffer( struct yy_buffer_state* new_buffer );
	struct yy_buffer_state* yy_create_buffer( class writerfilter::rtftok::RTFInputSource* s, int size );
	void yy_delete_buffer( struct yy_buffer_state* b );
	void yyrestart( class writerfilter::rtftok::RTFInputSource* s );

	virtual int yylex();
	virtual void switch_streams( class writerfilter::rtftok::RTFInputSource* new_in, ostream* new_out );

protected:

//	int LexerInput( char* buf, int max_size );
	virtual void LexerOutput( const char* buf, int size );
	virtual void LexerError( const char* msg );

	void yyunput( int c, char* buf_ptr );
	int yyinput();

	void yy_load_buffer_state();
	void yy_init_buffer( struct yy_buffer_state* b, class writerfilter::rtftok::RTFInputSource* s );
	void yy_flush_buffer( struct yy_buffer_state* b );

	int yy_start_stack_ptr;
	int yy_start_stack_depth;
	int* yy_start_stack;

	void yy_push_state( int new_state );
	void yy_pop_state();
	int yy_top_state();

	yy_state_type yy_get_previous_state();
	yy_state_type yy_try_NUL_trans( yy_state_type current_state );
	int yy_get_next_buffer();

	class writerfilter::rtftok::RTFInputSource* yyin;	// input source for default LexerInput
	ostream* yyout;	// output sink for default LexerOutput

	struct yy_buffer_state* yy_current_buffer;

	// yy_hold_char holds the character lost when yytext is formed.
	char yy_hold_char;

	// Number of characters read into yy_ch_buf.
	int yy_n_chars;

	// Points to current character in buffer.
	char* yy_c_buf_p;

	int yy_init;		// whether we need to initialize
	int yy_start;		// start state number

	// Flag which is used to allow yywrap()'s to do buffer switches
	// instead of setting up a fresh yyin.  A bit of a hack ...
	int yy_did_buffer_switch_on_eof;

	// The following are not always needed, but may be depending
	// on use of certain flex features (like REJECT or yymore()).

	yy_state_type yy_last_accepting_state;
	char* yy_last_accepting_cpos;

	yy_state_type* yy_state_buf;
	yy_state_type* yy_state_ptr;

	char* yy_full_match;
	int* yy_full_state;
	int yy_full_lp;

	int yy_lp;
	int yy_looking_for_trail_begin;

	int yy_more_flag;
	int yy_more_len;
	int yy_more_offset;
	int yy_prev_more_offset;

 private:

};

#endif
