#pragma once

#include "SDL.h"

#include "graphics3d.h"
#include "Resource.h"
#include "ResourcePool.h"

class Texture : public Resource
{
public:
	/**
	*  @brief implicitly inlined function that gets the GL texture identifier
	*  @return GL texture ID
	*/
	GLuint getTex() const { return tex; }

	explicit Texture(GUID guid, char const * filepath);
	virtual ~Texture() { if (surface != nullptr) SDL_FreeSurface(surface); } //implicit inline

private:
	Texture() = delete;
	Texture(const Texture &) = delete;
	Texture & operator=(const Texture &) = delete;

	GLuint tex;
	SDL_Surface * surface; //CONSIDER: remove?
};

Texture * get(GUID guid);