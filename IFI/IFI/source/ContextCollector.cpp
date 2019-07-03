#include "ContextCollector.h"
namespace fs = std::filesystem;
_declspec(dllimport)ULONG adjust_privileges();

ContextCollector::ContextCollector()
{
}

ContextCollector::~ContextCollector()
{
}

std::unordered_map<Key_Presort, std::vector<std::string>> ContextCollector::Collect()
{
	adjust_privileges();
	for (auto& p : fs::recursive_directory_iterator(L"c:\\", fs::directory_options::skip_permission_denied)){
		presort_key.name = p.path().filename().string();
		Collection[presort_key].push_back(p.path().string());
	}
	return Collection;
}
