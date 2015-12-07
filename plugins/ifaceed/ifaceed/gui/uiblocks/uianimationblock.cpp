#include <new>
#include <cassert>
#include "uianimationblock.h"
#include <QListWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTabWidget>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QSpinBox>
#include "../gui/colorview/colorview.h"
#include "../gui/textedit/textedit.h"
#include "../gui/rectwidget/rectwidget.h"

gui::uiblocks::UIAnimationBlock::UIAnimationBlock() : lstAnimations(NULL),
txtAnimationName(NULL),
cmbAddedAnimationType(NULL),
btnAnimationsAdd(NULL),
btnAnimationsRemove(NULL),
btnAnimationsStart(NULL),
btnAnimationsCancel(NULL),
tabAnimationTypes(NULL),
cmbWayAnimationWay(NULL),
btnCompositeAnimationRemoveFromList(NULL),
btnCompositeAnimationAddToList(NULL),
btnCompositeAnimationMoveBack(NULL),
btnCompositeAnimationMoveFront(NULL),
dsbAnimationTime(NULL),
cbAnimationLooped(NULL),
sbBlinkingFrequency(NULL),
cwColorEndingColor(NULL),
cwColorStartingColor(NULL),
dabResizeStartingSizeX(NULL),
dabResizeStartingSizeY(NULL),
dabResizeEndingSizeX(NULL),
dabResizeEndingSizeY(NULL),
dsbRotateStartingAngle(NULL),
dsbRotateEndingAngle(NULL),
dabSimpleMovementStartingPointX(NULL),
dabSimpleMovementStartingPointY(NULL),
btnSimpleMovementPickStartingPoint(NULL),
dabSimpleMovementEndingPointX(NULL),
dabSimpleMovementEndingPointY(NULL),
btnSimpleMovementPickEndingPoint(NULL),
txtFontListList(NULL),
sbFontSizeStartingSize(NULL),
sbFontSizeEndingSize(NULL),
txtOptionListList(NULL),
txtTextureCoordinatesList(NULL),
rctTCCStartingRect(NULL),
rctTCCEndingRect(NULL),
dsbCameraRotationPivotX(NULL),
dsbCameraRotationPivotY(NULL),
dsbCameraRotationStartingAngle(NULL),
dsbCameraRotationEndingAngle(NULL),
dsbCameraShakingOffsetX(NULL),
dsbCameraShakingOffsetY(NULL),
sbCameraShakingFrequency(NULL),
lstCompositeList(NULL),
lstCompositeCandidates(NULL)
{

}

void gui::uiblocks::UIAnimationBlock::init(QWidget* w)
{
    assert(w);
    this->lstAnimations = w->findChild<QListWidget*>("lstAnimations");
    assert(this->lstAnimations);
    this->txtAnimationName = w->findChild<QLineEdit*>("txtAnimationName");
    assert(this->txtAnimationName);
    this->cmbAddedAnimationType = w->findChild<QComboBox*>("cmbAddedAnimationType");
    assert(this->cmbAddedAnimationType);
    this->btnAnimationsAdd = w->findChild<QPushButton*>("btnAnimationsAdd");
    assert(this->btnAnimationsAdd);
    this->btnAnimationsRemove = w->findChild<QPushButton*>("btnAnimationsRemove");
    assert(this->btnAnimationsRemove);
    this->btnAnimationsStart = w->findChild<QPushButton*>("btnAnimationsStart");
    assert(this->btnAnimationsStart);
    this->btnAnimationsCancel = w->findChild<QPushButton*>("btnAnimationsCancel");
    assert(this->btnAnimationsCancel);
    this->tabAnimationTypes = w->findChild<QTabWidget*>("tabAnimationTypes");
    assert(this->tabAnimationTypes);
    this->cmbWayAnimationWay = w->findChild<QComboBox*>("cmbWayAnimationWay");
    assert(this->cmbWayAnimationWay);
    this->btnCompositeAnimationRemoveFromList = w->findChild<QPushButton*>("btnCompositeAnimationRemoveFromList");
    assert(this->btnCompositeAnimationRemoveFromList);
    this->btnCompositeAnimationAddToList = w->findChild<QPushButton*>("btnCompositeAnimationAddToList");
    assert(this->btnCompositeAnimationAddToList);
    this->btnCompositeAnimationMoveBack = w->findChild<QPushButton*>("btnCompositeAnimationMoveBack");
    assert(this->btnCompositeAnimationMoveBack);
    this->btnCompositeAnimationMoveFront = w->findChild<QPushButton*>("btnCompositeAnimationMoveFront");
    assert(this->btnCompositeAnimationMoveFront);
    this->dsbAnimationTime = w->findChild<QDoubleSpinBox*>("dsbAnimationTime");
    assert(this->dsbAnimationTime);
    this->cbAnimationLooped = w->findChild<QCheckBox*>("cbAnimationLooped");
    assert(this->cbAnimationLooped);
    this->sbBlinkingFrequency = w->findChild<QSpinBox*>("sbBlinkingFrequency");
    assert(this->sbBlinkingFrequency);
    this->cwColorEndingColor = w->findChild<gui::colorview::ColorView*>("cwColorEndingColor");
    assert(this->cwColorEndingColor);
    this->cwColorStartingColor = w->findChild<gui::colorview::ColorView*>("cwColorStartingColor");
    assert(this->cwColorStartingColor);
    this->dabResizeStartingSizeX = w->findChild<QDoubleSpinBox*>("dabResizeStartingSizeX");
    assert(this->dabResizeStartingSizeX);
    this->dabResizeStartingSizeY = w->findChild<QDoubleSpinBox*>("dabResizeStartingSizeY");
    assert(this->dabResizeStartingSizeY);
    this->dabResizeEndingSizeX = w->findChild<QDoubleSpinBox*>("dabResizeEndingSizeX");
    assert(this->dabResizeEndingSizeX);
    this->dabResizeEndingSizeY = w->findChild<QDoubleSpinBox*>("dabResizeEndingSizeY");
    assert(this->dabResizeEndingSizeY);
    this->dsbRotateStartingAngle = w->findChild<QDoubleSpinBox*>("dsbRotateStartingAngle");
    assert(this->dsbRotateStartingAngle);
    this->dsbRotateEndingAngle = w->findChild<QDoubleSpinBox*>("dsbRotateEndingAngle");
    assert(this->dsbRotateEndingAngle);
    this->dabSimpleMovementStartingPointX = w->findChild<QDoubleSpinBox*>("dabSimpleMovementStartingPointX");
    assert(this->dabSimpleMovementStartingPointX);
    this->dabSimpleMovementStartingPointY = w->findChild<QDoubleSpinBox*>("dabSimpleMovementStartingPointY");
    assert(this->dabSimpleMovementStartingPointY);
    this->btnSimpleMovementPickStartingPoint = w->findChild<QPushButton*>("btnSimpleMovementPickStartingPoint");
    assert(this->btnSimpleMovementPickStartingPoint);
    this->dabSimpleMovementEndingPointX = w->findChild<QDoubleSpinBox*>("dabSimpleMovementEndingPointX");
    assert(this->dabSimpleMovementEndingPointX);
    this->dabSimpleMovementEndingPointY = w->findChild<QDoubleSpinBox*>("dabSimpleMovementEndingPointY");
    assert(this->dabSimpleMovementEndingPointY);
    this->btnSimpleMovementPickEndingPoint = w->findChild<QPushButton*>("btnSimpleMovementPickEndingPoint");
    assert(this->btnSimpleMovementPickEndingPoint);
    this->txtFontListList = w->findChild<gui::textedit::TextEdit*>("txtFontListList");
    assert(this->txtFontListList);
    this->sbFontSizeStartingSize = w->findChild<QSpinBox*>("sbFontSizeStartingSize");
    assert(this->sbFontSizeStartingSize);
    this->sbFontSizeEndingSize = w->findChild<QSpinBox*>("sbFontSizeEndingSize");
    assert(this->sbFontSizeEndingSize);
    this->txtOptionListList = w->findChild<gui::textedit::TextEdit*>("txtOptionListList");
    assert(this->txtOptionListList);
    this->txtTextureCoordinatesList = w->findChild<gui::textedit::TextEdit*>("txtTextureCoordinatesList");
    assert(this->txtTextureCoordinatesList);
    this->rctTCCStartingRect = w->findChild<gui::rectwidget::RectWidget*>("rctTCCStartingRect");
    assert(this->rctTCCStartingRect);
    this->rctTCCEndingRect = w->findChild<gui::rectwidget::RectWidget*>("rctTCCEndingRect");
    assert(this->rctTCCEndingRect);
    this->dsbCameraRotationPivotX = w->findChild<QDoubleSpinBox*>("dsbCameraRotationPivotX");
    assert(this->dsbCameraRotationPivotX);
    this->dsbCameraRotationPivotY = w->findChild<QDoubleSpinBox*>("dsbCameraRotationPivotY");
    assert(this->dsbCameraRotationPivotY);
    this->dsbCameraRotationStartingAngle = w->findChild<QDoubleSpinBox*>("dsbCameraRotationStartingAngle");
    assert(this->dsbCameraRotationStartingAngle);
    this->dsbCameraRotationEndingAngle = w->findChild<QDoubleSpinBox*>("dsbCameraRotationEndingAngle");
    assert(this->dsbCameraRotationEndingAngle);
    this->dsbCameraShakingOffsetX = w->findChild<QDoubleSpinBox*>("dsbCameraShakingOffsetX");
    assert(this->dsbCameraShakingOffsetX);
    this->dsbCameraShakingOffsetY = w->findChild<QDoubleSpinBox*>("dsbCameraShakingOffsetY");
    assert(this->dsbCameraShakingOffsetY);
    this->sbCameraShakingFrequency = w->findChild<QSpinBox*>("sbCameraShakingFrequency");
    assert(this->sbCameraShakingFrequency);
    this->lstCompositeList = w->findChild<QListWidget*>("lstCompositeList");
    assert(this->lstCompositeList);
    this->lstCompositeCandidates = w->findChild<QListWidget*>("lstCompositeCandidates");
    assert(this->lstCompositeCandidates);
}

gui::uiblocks::UIAnimationBlock::~UIAnimationBlock()
{

}
