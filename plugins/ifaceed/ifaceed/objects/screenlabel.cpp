#include "screenlabel.h"
#include "screentemplate.h"
#include "../core/fonttemplatesdatabase.h"
#include "../core/fontdatabase.h"
#include <extra/rigid_body.h>
#include <extra/geometry2d.h>
#include <3rdparty/format/format.h>

ScreenLabel::ScreenLabel() : AbstractScreenObject()
{
	m_font = NULL;

	this->addProperty("font" ,new MappedField<hst::string>(&m_font_name, ""));
	this->addProperty("size" ,new MappedField<unsigned int>(&m_font_size, 0));
	this->addProperty("color",new MappedField<hst::color>(&m_font_color, hst::color(0,0,0)));
	this->addProperty("text" ,new MappedField<hst::string>(&m_text, ""));
	this->addProperty("angle",new MappedField<float>(&m_angle, 0.0f));
	this->addProperty("pos"  ,new MappedField<hPointF>(&m_point, hPointF(0,0)));
	this->addProperty("alpha"  ,new MappedField<int>(&m_alpha, 0));

}


void ScreenLabel::moveCenterTo(const hPointF & p)
{
	hRectF r = m_font->size(m_text);
	m_point.setX(p.x() - r.width()/2);
	m_point.setY(p.y() + r.height()/2);
}

hst::string ScreenLabel::_description()
{
	hst::string result = m_text.subString(0,10);
	if (result.length() > 10)
		result<<"... ";
	else
		result<<" ";
	result<<"(";
	result<<m_font_name;
	result<<",";
	result<<hst::string::number(m_font_size);
	result<<")";
	return result; 
}

hst::string ScreenLabel::typeName()
{
	return "ScreenLabel";
}

void ScreenLabel::_render()
{
	if (!m_font)
	{
		return;
	}
	m_font->setColor(hst::acolor(m_font_color.r(),m_font_color.g(),m_font_color.b(),(Uint8)m_alpha));
	m_font->setHeight(m_font_size);

	hRectF s = m_font->size(m_text);
	glMatrixMode(GL_MODELVIEW_MATRIX);
	glPushMatrix();
	glTranslatef(m_point.x() +  s.width() /2, m_point.y() - s.height() /2, 0.0f);
	glRotatef(m_angle / M_PI*180.0f, 0.0f, 0.0f, 1.0f);
	m_font->render(m_text, - (s.width()/2), (s.height()/2));	
	
	glPopMatrix();

}

bool ScreenLabel::isValid(FontTemplateDatabase * db, hst::vector<hst::string> * errors)
{
	IFaceEditorFontList & d = db->fonts();
	bool result = d.hasFont(m_font_name.data());
	if (result == false && errors != NULL)
	{
		*errors << str(
					fmt::Print("Font \"{0}\" is absent in database\n") 
					<< m_font_name.data() 
					).c_str();
	}
	return result;
}

bool ScreenLabel::tryReload(FontTemplateDatabase * db)
{
	if (!isValid(db))
		return false;
	IFaceEditorFontList & d = db->fonts();
	m_font = d.font(m_font_name.data())->sadFont();
	return true;
}


bool ScreenLabel::isWithin(const hPointF & p)
{
	hRectF r = this->region();
	return ::isWithin(p, r);
}

hRectF ScreenLabel::region()
{
	if (!m_font)
	{
		return hRectF();
	}
	m_font->setHeight(m_font_size);

	hRectF s = m_font->size(m_text);
	hRectF non_rotated_region( hPointF(s.width() / -2.0f, s.height() / -2.0f),
		                       hPointF(s.width() / 2.0f, s.height() / 2.0f));
	hPointF results[4];
	float cos_angle = cos(m_angle);
	float sin_angle = sin(m_angle);
	float centerx = m_point.x() + s.width() / 2;
	float centery = m_point.y() - s.height() / 2;
	for (int i=0;i<4;i++)
	{
		results[i].setX(centerx + non_rotated_region[i].x()*cos_angle - non_rotated_region[i].y() * sin_angle);
		results[i].setY(centery + non_rotated_region[i].x()*sin_angle + non_rotated_region[i].y() * cos_angle);
	}
	return hRectF(results[0],results[1], results[2], results[3]);
}


bool ScreenLabel::resizable()
{
	return false;
}

