#pragma once
#include"stdafx.h"

#define BEGIN	".586\n"\
				".model flat, stdcall\n"\
				"includelib libucrt.lib\n"\
				"includelib kernel32.lib\n"\
				"includelib ../Debug/GenLib.lib\n"\
				"ExitProcess		PROTO:DWORD\n"\

#define EXTRN	"Strlen			PROTO : DWORD\n"\
				"Rand			PROTO : DWORD\n"\
				"Input			PROTO : DWORD\n"\
				"Printstroke	PROTO : DWORD\n"\
				"PrintNumb		PROTO : DWORD\n"\
				".stack 4096\n"

#define CONST	".const\n"

#define DATA	".data\n"

#define CODE	".code\n"

#define STR_SEPARATOR		"\n;------------------------------\n"
#define FUNCTION_NAME(u)	"\n;----------- " + string(u) + " ------------\n\n"


#define END		"push 0\n"\
				"call ExitProcess\n"\
				"main ENDP\n"\
				"end main\n"

#define LEXEMA(a)	tables.lextable.table[a].lexema

#define IT_ENTRY(a) tables.idtable.table[tables.lextable.table[a].idxTI]

#define IT_ENTRY_IN_TABLE(a) tables.idtable.table[a]

namespace Generator {
	void CodeGeneration(Lex::Tables& tables);
}