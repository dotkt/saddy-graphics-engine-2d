#include "texture.h"
using namespace sad;

Texture::Texture()
{
	m_mode = BORDER_CLAMP;	/*!< Set default mode of texture.		*/
	m_filter = 10;			/*!< Set default filter of texture.		*/
}

Texture::~Texture()
{
	m_data.clear();			/*!< Cleaning the container of pixels.  */
}
void Texture::disable()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
void Texture::enable()
{
	glBindTexture(GL_TEXTURE_2D,m_id);
}
void Texture::buildMipMaps()
{
	// ������ ��������
	GLuint type,components;
	switch (m_bpp)
	{
		case 24: // 24 ����
			type=GL_RGB;components=3; break;
		case 32: // 32 ����
			type=GL_RGBA;components=4; break;
	};
    
	glGenTextures(1, (GLuint *)&m_id);	
	glBindTexture(GL_TEXTURE_2D, m_id);

	GLuint what;
	switch (m_mode)
	{
		case BORDER_CLAMP:	what=GL_CLAMP;break;
		case BORDER_REPEAT: what=GL_REPEAT;break;
	}
    
	// ������������� ��������� ������
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, what);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, what);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);	
	gluBuild2DMipmaps(GL_TEXTURE_2D, components, m_width, m_height, type, GL_UNSIGNED_BYTE, m_data.data());

		
}