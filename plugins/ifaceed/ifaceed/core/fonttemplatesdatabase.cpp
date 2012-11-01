#include "fonttemplatesdatabase.h"
#include <QDomDocument>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "../editorcore/path.h"
#include "xmlconfigloader.h"
#include "spritedatabase.h"

FontTemplatesMaps::FontTemplatesMaps()
{

}

bool FontTemplatesMaps::load(const QString & name)
{
	hst::log::inst()->owrite("Entering FontTemplatesMaps::load(\"").owrite(name.toStdString()).owrite("\")\n");
	hst::string parentdir =  path::directory(name.toStdString().c_str());
	hst::log::inst()->owrite("Parent dir is set to \"").owrite(parentdir).owrite("\"\n");
	m_fonts.clear();
	m_configs.clear();
	
	QDomDocument doc("globalconfig");
	QFile file(name);
	if (!file.open(QIODevice::ReadOnly)) 
	{
		hst::log::inst()->owrite(hst::string("FontTemplatesMaps::load: can\'t load file"))
						 .owrite(hst::string(name.toStdString().c_str()))
						 .owrite(hst::string("\n"));			
		return false;
	}
	if (!doc.setContent(&file)) 
	{
		hst::log::inst()->owrite(hst::string("FontTemplatesMaps::load: can\'t parse file "))
						 .owrite(hst::string(name.toStdString().c_str()))
						 .owrite(hst::string("\n"));
		file.close();
		return false;
	}
	file.close();
	QDomElement root = doc.documentElement();
	if (root.isNull())
	{
		hst::log::inst()->owrite(hst::string("FontTemplatesMaps::load: no root element found "))
						 .owrite(hst::string(name.toStdString().c_str()))
						 .owrite(hst::string("\n"));
		return false;
	}
	
	QDomElement entry = root.firstChildElement();
	bool test = entry.isNull();
	while(entry.isNull() == false) 
	{
		if (entry.tagName() == "font")
		{
			this->loadFont(entry, parentdir);
		} 
		else if (entry.tagName() == "config")
		{
			this->loadConfig(entry, parentdir);
		}
		else 
		{
			hst::log::inst()->owrite(hst::string("FontTemplatesMaps::load: found unknown tag "))
							 .owrite(hst::string(entry.tagName().toStdString().c_str()))
							 .owrite(hst::string("\n"));
			QMessageBox::warning(NULL, "IFaceEditor", QString("Unknown tag found, while loading: ") + entry.tagName());
		}
		entry = entry.nextSiblingElement();
	}
	hst::log::inst()->owrite("Leaving FontTemplatesMaps::load()\n");
	
	return true;
}

void FontTemplatesMaps::loadFont(QDomElement & entry, const hst::string & parent)
{
	if (entry.hasAttribute("name")==false || entry.hasAttribute("file")==false)
	{
		hst::log::inst()->owrite(hst::string("FontTemplatesMaps::loadFont: in one or more font elements skipped attributes \"name\" or \"file\"\n"));
	} 
	else 
	{
		QString name = entry.attribute("name");
		QString file = entry.attribute("file");
		if (m_fonts.contains(name))
		{
			hst::log::inst()->owrite(hst::string("FontTemplatesMaps::loadFont: duplicate entry skipped "))
							 .owrite(hst::string(name.toStdString().c_str()))
							 .owrite(hst::string("\n"));
			QMessageBox::warning(NULL, "IFaceEditor", QString("Duplicate font entry skipped ") + name);
		}
		else
		{
			hst::string path = path::concat(parent,file.toStdString().c_str());
			m_fonts.insert(name, path.data());
			hst::log::inst()->owrite("Deserialized XML Font entry \"").owrite(name.toStdString())
							 .owrite("\" with path \"").owrite(path).owrite("\"\n");
		}
	}
}

void FontTemplatesMaps::loadConfig(QDomElement & entry, const hst::string & parent)
{
	if (entry.hasAttribute("name")==false || entry.hasAttribute("file")==false)
	{
		hst::log::inst()->owrite(hst::string("FontTemplatesMaps::loadConfig: in one or more config elements skipped attributes \"name\" or \"file\"\n"));
	} 
	else 
	{
		QString name = entry.attribute("name");
		QString file = entry.attribute("file");
		if (m_fonts.contains(name))
		{
			hst::log::inst()->owrite(hst::string("FontTemplatesMaps::loadConfig: duplicate entry skipped "))
							 .owrite(hst::string(name.toStdString().c_str()))
							 .owrite(hst::string("\n"));
			QMessageBox::warning(NULL, "IFaceEditor", QString("Duplicate config entry skipped ") + name);
		}
		else 
		{
			hst::string path = path::concat(parent,file.toStdString().c_str());
			m_configs.insert(name, path.data());
			hst::log::inst()->owrite("Deserialized XML Config entry \"").owrite(name.toStdString())
							 .owrite("\" with path \"").owrite(path).owrite("\"\n");
		}
	}
}

FontTemplateDatabase::FontTemplateDatabase(int * counter)
{
	m_sprites =  new SpriteDatabase();
	m_fonts = new IFaceEditorFontList();
	m_counter = counter;
}

FontTemplateDatabase::~FontTemplateDatabase()
{
	delete m_sprites;
	delete m_fonts;
}

bool FontTemplateDatabase::load(FontTemplatesMaps & maps, DBCriticalLogger * logger)
{
	m_maps = maps;
	IFaceEditorFontList * fonts = new IFaceEditorFontList();
	{
		db::NameFileMap::const_iterator it = maps.fonts().constBegin();
		db::NameFileMap::const_iterator end = maps.fonts().constEnd();
		bool success = true;
		
		for (it;it!=end;it++)
		{
			IFaceEditorFontLoadResult r = fonts->tryLoadFont(it.key(), it.value());
			if (r!=IEFLR_OK) 
			{
				hst::log::inst()->owrite("FontTemplateDatabase::load: can\'t load file ")
						    	 .owrite(it.value().toStdString().c_str())
							     .owrite("\n");
				logger->critical(QString("Can't load font from ") + it.value());
				success = false;
			}
		}
		// Don't proceed further if can't load stuff
		if (!success) {
			delete fonts;
			return false;
		}
	}
	SpriteDatabase * sprites = new SpriteDatabase();
	// Load some configs
	{
		if (sprites->load(maps, *m_counter, logger) == false)
		{
			delete sprites;
			delete fonts;
			return false;
		}
	}
	// Apply changes
	delete m_sprites; m_sprites = sprites;
	delete m_fonts; m_fonts = fonts;

	return true;
}

