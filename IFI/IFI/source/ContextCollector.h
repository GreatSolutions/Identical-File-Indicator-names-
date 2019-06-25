#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <filesystem>
#include <Windows.h>
#include <iostream>

struct Key_Presort
{
	std::string name;
	friend bool operator ==(const Key_Presort& k1, const Key_Presort& k2)
	{
		return k1.name == k2.name;
	}
};

namespace std
{
	template<> struct hash<Key_Presort>
	{
		size_t operator()(const Key_Presort& key)const
		{
			return std::hash<std::string>()(key.name);
		}
	};
}


class ContextCollector
{
public:
	ContextCollector();
	~ContextCollector();
	std::unordered_map<Key_Presort, std::vector<std::string>> Collect();
	
private:

	Key_Presort presort_key;
	std::unordered_map<Key_Presort, std::vector<std::string>> Collection;
};

