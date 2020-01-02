#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <crtdbg.h>

/** Pointer array safe destroyer. */
#define SAFE_DELETE_ARRAY(arr) {delete[](arr);(arr)=nullptr;}
/** Pointer safe destroyer. */
#define SAFE_DELETE(ptr)\
	if( (ptr) != nullptr )\
	{\
		delete (ptr);\
		(ptr) = nullptr;\
	}

using Length = const unsigned int;

/**
 * Clear string value.
 * @param String To clear string.
 * @param Length String's length.
 */
constexpr void ClearString(char* String, const int Length)
{
	if (!String) return;
	for (int i = 0; i < Length; i++)
	{
		String[i] = '\0';
	}
}

/**
 * Replace string, don't change base string.
 * @param Subject To change String value.
 * @param Search To replace string item.
 * @param Replace Replace string. To change Search string.
 * @return Changed string.
 */
inline std::string ReplaceString(std::string Subject, const std::string& Search, const std::string& Replace)
{
	size_t pos = 0;
	while ((pos = Subject.find(Search, pos) != std::string::npos))
	{
		Subject.replace(pos, Search.length(), Replace);
		pos += Replace.length();
	}
	return Subject;
}

/**
 * Replace string with base class.
 * @param Subject To change String value.
 * @param Search To replace string item.
 * @param Replace Replace string. To change Search string.
 */
inline void ReplaceStringInPlace(std::string& Subject, const std::string& Search, const std::string& Replace)
{
	size_t pos = 0;
	while ((pos = Subject.find(Search, pos)) != std::string::npos)
	{
		Subject.replace(pos, Search.length(), Replace);
		pos += Replace.length();
	}
}
/**
 * Splits the specified string.
 * @param Str To split string.
 * @param Delimiter The delimiter.
 * @return Divided vector data.
 */
inline std::vector<std::string> Split(const std::string& Str, const char Delimiter = ' ')
{
	std::vector<std::string> internal; // Divided data
	std::stringstream strStream(Str); // Divider
	std::string temp; // Cache

	while (std::getline(strStream, temp, Delimiter))
	{
		internal.push_back(temp);
	}
	return internal;
}

#ifdef _DEBUG
/** �޸� ���� Ȯ�ο� new. */
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)

#endif

/**
 * @brief �޸� ���� Ȯ��, ���α׷� ������������ üũ.
 */
void CheckMemoryLeak()
{
	/** ����� �÷��� ����. */
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	if(_CrtDumpMemoryLeaks() != 0)
	{
		printf("�޸� ���� �߻�\n");
	}
}

