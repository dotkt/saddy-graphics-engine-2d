#include "core/shared.h"

#include "../gui/rendergrids.h"

#include <db/custom/customobject.h>

core::Shared::Shared() : 
m_selected(NULL),
m_active(NULL),
m_selected_way(NULL),
m_selected_dialogue(NULL),
m_selected_animation(NULL),
m_selected_instance(NULL),
m_selected_group(NULL), 
m_active_grid(NULL),
m_selected_grid(NULL),
m_way_point_position(0),
m_editor(NULL),
m_animation_is_running(false),
m_animation_instance_is_running(false),
m_animation_group_is_running(false),
m_old_angle(0.0),
m_triggered_by_fast_mode(false)
{
    m_show_active_border = true;
    m_nonresizeable_nodetypes << "sad::Label";
}

core::Shared::~Shared()
{
    if (m_selected_grid)
    {
        m_selected_grid->delRef();
    }
}

void core::Shared::setEditor(core::Editor* e)
{
    m_editor = e;
}

core::Editor* core::Shared::editor() const
{
    return m_editor;
}

void core::Shared::setSelectedObject(sad::SceneNode* o)
{
    m_selected = o;
}

void core::Shared::setActiveObject(sad::SceneNode* o)
{
    m_active = o;
}

sad::SceneNode* core::Shared::selectedObject() const
{
    return m_selected;
}

sad::SceneNode* core::Shared::activeObject() const
{
    return m_active;
}


bool core::Shared::canShowActiveBorder() const
{
    return m_show_active_border  && m_active != NULL;
}

void core::Shared::toggleActiveBorder(bool flag) 
{
    m_show_active_border = flag;
}

void core::Shared::setPivotPoint(const sad::Point2D& p)
{
    m_pivot_point = p;
}

const sad::Point2D& core::Shared::pivotPoint() const
{
    return m_pivot_point;
}

void core::Shared::setOldArea(const sad::Rect2D& r)
{
    m_old_area = r;
}

const sad::Rect2D& core::Shared::oldArea() const
{
    return m_old_area;
}

bool core::Shared::isSelectionResizeable() const
{
    if (m_selected == NULL)
        return false;
    bool result  = true;
    for(size_t i = 0; i < m_nonresizeable_nodetypes.size(); i++)
    {
        if (m_selected->metaData()->canBeCastedTo(m_nonresizeable_nodetypes[i]))
        {
            result = false;
        }
    }
    if (m_selected->metaData()->canBeCastedTo("sad::db::custom::Object"))
    {
        sad::db::custom::Object* o  = static_cast<sad::db::custom::Object*>(m_selected);
        result = o->innerTypeIs("sad::Label") == false;
    }
    return result;
}

void core::Shared::setResizingIndexes(const sad::Pair<int, int>& indexes)
{
    m_resizing_indexes = indexes;
}

const sad::Pair<int, int>& core::Shared::resizingIndexes() const
{
    return m_resizing_indexes;
}

void core::Shared::setResizingDirection(const sad::p2d::Vector& direction)
{
    m_resizing_direction = direction;
}

const sad::p2d::Vector& core::Shared::resizingDirection() const
{
    return m_resizing_direction;
}

void core::Shared::setNormalizedResizingDirection(const sad::p2d::Vector& direction)
{
    m_normalized_resizing_direction = direction;
}

const sad::p2d::Vector& core::Shared::normalizedResizingDirection() const
{
    return m_normalized_resizing_direction;
}

void core::Shared::setFileName(const QString& name)
{
    m_filename = name;
}

const QString& core::Shared::fileName() const
{
    return m_filename;
}

void core::Shared::setOldRegion(const sad::Rect2D& r)
{
    m_old_region = r;
}

const sad::Rect2D&  core::Shared::oldRegion() const
{
    return m_old_region;
}


void core::Shared::setSelectedWay(sad::p2d::app::Way* way)
{
    m_selected_way = way;
}

sad::p2d::app::Way* core::Shared::selectedWay() const
{
    return m_selected_way;
}

void core::Shared::setWayPointPosition(int p)
{
    m_way_point_position = p;
}

int core::Shared::wayPointPosition() const
{
    return m_way_point_position;
}

void core::Shared::setOldPoint(const sad::Point2D& p)
{
    m_old_point = p;
}

const sad::Point2D& core::Shared::oldPoint() const
{
    return m_old_point;
}


void core::Shared::setSelectedDialogue(sad::dialogue::Dialogue* d)
{
    m_selected_dialogue = d;
}

sad::dialogue::Dialogue*  core::Shared::selectedDialogue() const
{
    return m_selected_dialogue;
}

void core::Shared::setSelectedAnimation(sad::animations::Animation* a)
{
    m_selected_animation = a;
}

sad::animations::Animation* core::Shared::selectedAnimation() const
{
    return m_selected_animation;	
}

void core::Shared::setSelectedInstance(sad::animations::Instance* a)
{
    m_selected_instance = a;
}

sad::animations::Instance* core::Shared::selectedInstance() const
{
    return m_selected_instance;	
}

void core::Shared::setSelectedGroup(sad::animations::Group* a)
{
    m_selected_group = a;
}

sad::animations::Group* core::Shared::selectedGroup() const
{
    return m_selected_group;
}

void core::Shared::setActiveGrid(sad::layouts::Grid* g)
{
    if (g)
    {
        if (m_selected_grid)
        {
            m_selected_grid->setRenderColor(gui::RenderGrids::defaultColor());        	
        }
        g->setRenderColor(gui::RenderGrids::selectedColor());
    }
    else
    {
        if (m_selected_grid)
        {
            m_selected_grid->setRenderColor(gui::RenderGrids::selectedColor());	
        }
    }
    if (m_active_grid)
    {
        m_active_grid->setRenderColor(gui::RenderGrids::defaultColor());
    }
    m_active_grid = g;
}

sad::layouts::Grid* core::Shared::activeGrid() const
{
    return m_active_grid;
}

void core::Shared::setSelectedGrid(sad::layouts::Grid* g)
{
    if (m_selected_grid)
    {
        m_selected_grid->setRenderColor(gui::RenderGrids::defaultColor());
        m_selected_grid->delRef();
    }
    if (g)
    {
        g->setRenderColor(gui::RenderGrids::selectedColor());
        g->addRef();
    }
    m_selected_grid = g;
}

sad::layouts::Grid* core::Shared::selectedGrid() const
{
    return m_selected_grid;
}

bool core::Shared::isAnyKindOfAnimationIsRunning() const
{
    return m_animation_is_running
        || m_animation_instance_is_running
        || m_animation_group_is_running;
}

void core::Shared::setAnimationIsRunning(bool flag)
{
    m_animation_is_running = flag;	
}

void core::Shared::setAnimationInstanceIsRunning(bool flag)
{
    m_animation_instance_is_running = flag;	
}

void core::Shared::setAnimationGroupIsRunning(bool flag)
{
    m_animation_group_is_running = flag;	
}

void core::Shared::setEditingSimpleMovementProperty(const sad::String& name)
{
    m_editing_simple_movement_property = name;
}

const sad::String& core::Shared::editingSimpleMovementProperty() const
{
    return m_editing_simple_movement_property;
}

void core::Shared::setOldAngle(double angle)
{
    m_old_angle = angle;
}

double core::Shared::oldAngle() const
{
    return m_old_angle;
}

void core::Shared::setNameForFastMode(
    const QString& name
)
{
    m_name_for_fast_mode = name;    
}

const QString& core::Shared::nameForFastMode() const
{
    return m_name_for_fast_mode;
}

void core::Shared::setTriggeredByFastMode(bool flag)
{
    m_triggered_by_fast_mode = flag;
}

bool core::Shared::triggeredByFastMode() const
{
    return m_triggered_by_fast_mode;
}

void  core::Shared::setOldState(const picojson::value& state)
{
	m_old_state = state;
}

const picojson::value& core::Shared::oldState() const
{
	return m_old_state;
}