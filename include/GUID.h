#pragma once

#include <unordered_map>

typedef unsigned int GUID;

class GUIDFactory
{
public:
	explicit GUIDFactory() = default;
	~GUIDFactory() = default;

	GUID getGUID(char const *identifier);

private:
	GUIDFactory(const GUIDFactory&) = delete; //delete copy constructor
	GUIDFactory& operator=(const GUIDFactory&) = delete; //delete copy assignment operator

	std::unordered_map<GUID, char const *> GUIDs;
};

constexpr GUID hash(char const * identifier);