#pragma once
#include <GL/glew.h>

namespace rTex
{
	struct RenderTexture
	{
		RenderTexture(int _width, int _height);
		~RenderTexture();

		void bind();
		void unbind();

		GLuint GetTexture() const;

	private:
		GLuint m_fboId;
		GLuint m_texId;
		GLuint m_rboId;
	};
}

