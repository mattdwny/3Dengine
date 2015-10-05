#include <cstring>
#include <string>

#include "SDL_image.h"

#include "simple_logger.h"
#include "graphics3d.h"
#include "Texture.h"

ResourcePool<Texture*> textures;

Texture::Texture(GUID guid, char const * filepath) : Resource(guid)
{
	surface = IMG_Load(filepath);
	if (surface == nullptr) slog("failed to load sprite image file: %s, re: %s", filepath, SDL_GetError());

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	int Mode = GL_RGB;
	if (surface->format->BytesPerPixel == 4)
		Mode = GL_RGBA;

	glTexImage2D(GL_TEXTURE_2D, 0, Mode, surface->w, surface->h, 0, Mode, GL_UNSIGNED_BYTE, surface->pixels);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//SDL_FreeSurface(surface);
}

Texture * get(GUID guid)
{
	return textures.get(guid);
}