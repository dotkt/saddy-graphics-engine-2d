#include <p2d/app/objectemitter.h>


void sad::p2d::app::AbstractObjectEmitter::perform()
{
    sad::p2d::app::Object * o = this->produce();
    this->app()->addObject(o);
    sad::p2d::World* wld = this->app()->world();
    for (size_t i = 0; i < m_additional_groups.size(); i++)
    {
        wld->addBodyToGroup(m_additional_groups[i], o->body());
    }

    sad::p2d::Point p;
    this->position(p);
    o->setPosition(p);

    sad::p2d::Vector v;
    this->tangentialVelocity(v);
    o->setTangentialVelocity(v);

    o->setAngle(this->angle());
    o->setAngularVelocity(this->angularVelocity());
}

void sad::p2d::app::AbstractObjectEmitter::addAdditionalGroupForObjects(const sad::String& group_name)
{
    m_additional_groups.push_back(group_name);
}


double sad::p2d::app::AbstractObjectEmitter::angle()
{
    return 0;
}

