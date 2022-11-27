#pragma once
#define LEXEMA_FIXSIZE		1				//������������� ������ �������
#define LT_MAXSIZE			4096			//������������ ���������� ����� � ��
#define LT_TI_NULLIDX		0xffffffff		//��� �������� ������� ���������������
#define MAX_SCOPE			10
#define LEX_NUMB			't'				//integer
#define LEX_STROKE			't'				//string
#define LEX_ID				'i'				//�������������
#define LEX_LITERAL			'l'				//�������
#define LEX_MAIN			'm'
#define LEX_FUNCTION		'f'				//function
#define LEX_NEW				'n'				//declare
#define LEX_RETURN			'r'				//return
#define LEX_PRINT			'p'				//print
#define LEX_SEMICOLON		';'
#define LEX_COMMA			','
#define LEX_LEFTBRACE		'['
#define LEX_BRACELET		']'
#define LEX_LEFTHESIS		'('
#define LEX_RIGHTHESIS		')'
#define LEX_PLUS			'+'
#define LEX_MINUS			'-'
#define LEX_STAR			'*'
#define LEX_DIRSLASH		'/'
#define LEX_EQUAL			'='
//#define LEX_GREATER			'>'
//#define LEX_SMALLER			'<'
//#define LEX_GREATEROREQUAL	'}'
//#define LEX_SMALLEROREQUAL	'{'


namespace LT {				//������� ������
	struct Entry			//������ ������� ������
	{
		char lexema;					//�������
		int sn;							//����� ������ � �������� ������
		int idxTI;						//������ � ������� ��������������� ��� LT_TI_NULLIDX
		int priority;
	};

	struct LexTable						//��������� ������� ������
	{
		char scope[MAX_SCOPE];
		int maxsize;					//������� ������� ������ < LT_MAXSIZE
		int size;						//������� ������ ������� ������ < maxsize
		Entry* table;					//������ ����� ������� ������
	};
	LexTable Create(					//������� ������� ������
		int size						//������� ������� ������ < LT_MAXSIZE
	);
	void Add(							//�������� ������ � ������� ������
		LexTable& lextable,				//��������� ������� ������
		Entry entry						//������ ������� ������
	);
	Entry GetEntry(						//�������� ������ ������� ������
		LexTable& lextable,				//��������� ������� ������
		int n							//����� ���������� ������
	);
	void Delete(LexTable& lextable);	//������� ������� ������ (���������� ������)
	void showTable(LexTable lextable);
	void WriteTable(LexTable lextable, Out::OUT out);
};