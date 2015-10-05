#pragma once

#include <iostream>
#include <iterator>     // std::back_inserter
#include <vector>       // std::vector
#include <map>
#include <algorithm>    // std::copy

#include "boost/filesystem.hpp"

#include "Resource.h"

template <typename resource>
class ResourcePool
{
public:
	ResourcePool() {};							 //FIXME: delete default constructor
	ResourcePool(char const * extention);
	~ResourcePool() = default;

	resource get(GUID guid) { return pool[guid]; } //has to exist for any valid resource
private:
	ResourcePool(const resource &) = delete;			 //delete copy constructor
	ResourcePool & operator=(const resource &) = delete; //delete copy assignment operator

	static std::map<GUID, resource> pool;
};

template <typename resource>
ResourcePool<resource>::ResourcePool(char const * extension)
{
	using boost::filesystem;

	GUIDFactory factory;
	path directory(extension);

	std::vector<path> files;

	copy(directory_iterator(directory),
		 directory_iterator(),
		 back_inserter(files));

	for(path p : files)
	{
		GUID guid = factory.getGUID(p);
		typename std::map<GUID, resource> pool.emplace(guid, new resource(guid, p)); //guid needed for first key (GUID) and the emplace constructor args for (Resource)
	}
}