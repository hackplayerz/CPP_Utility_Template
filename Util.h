#pragma once

#include <vector>
#include <string>
#include <sstream>

using namespace std;

/// <summary>
/// Splits the specified string.
/// </summary>
/// <param name="str_">To split string.</param>
/// <param name="delimiter_">The delimiter.</param>
/// <returns>Divided vector data.</returns>
vector<string> Split(const string& str_, const char delimiter_ = ' ')
{
	vector<string> internal; // Divided data
	stringstream strStream(str_); // Divider
	string temp; // Cache

	while (getline(strStream, temp, delimiter_))
	{
		internal.push_back(temp);
	}
	return internal;
}