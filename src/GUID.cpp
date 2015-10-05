#include <iostream>
#include <stdexcept>
#include "GUID.h"

constexpr GUID hash(char const * identifier)
{
	//static_assert(/*does filepath exist?*/);

	return *identifier + ((*identifier) ? 256 * hash(identifier + 1) : 0);
	/*GUID result = 0;
	if (*identifier != '\0') result = 256*hash(identifier + 1);
	return result + *identifier;*/
}

GUID GUIDFactory::getGUID(char const * identifier)
{
	GUID result = hash(identifier);
	if (GUIDs[result] != "")
	{
		std::cerr << identifier << " collided with " << GUIDs[result] << std::endl;
		throw std::runtime_error("GUID: hash function collision, please change hash function or colliding resource filepaths");
	}
	GUIDs[result] = identifier;
		
	return result;
}