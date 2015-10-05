#pragma once

#include "GUID.h"

class Resource
{
protected:
	explicit Resource(GUID id) : guid(id) {}
	~Resource(); //Resource is abstract
	const GUID guid;
private:
	Resource() = delete;										 //delete default constructor
	Resource(const Resource &) = delete;			 //delete copy constructor
	Resource & operator=(const Resource &) = delete; //delete copy assignment operator, might break swapping
};