/*! \file bulletsettings.h


    Defines a basic settings for bullet
 */
#pragma once
#include <sadstring.h>
#include <sadpoint.h>

namespace weapons
{

/*! A settings for bullet
 */
class BulletSettings
{
public:
    /*! A name for icon
     */
    sad::String IconName;
    /*! A tangential speed fpr bullet
     */
    double Speed;
    /*! Whether gravity should be applied to bullet
     */
    bool ApplyGravity;
    /*! A gravity value to be applied
     */
    sad::Point2D GravityValue;
    /*! An angular speed for bullet
     */
    double AngularSpeed;
    /*! Whether bullet should bounce or be removed, when collided with platform.
     */
    bool IsGhost;
    /*! Maximal amount of bouncing, before bullet will be removed
     */
    int MaxBounceCount;
    /*! A restitution coefficient for bouncing
     */
    double RestitutionCoefficient;
    /*! If set to true bullet won't decay, when enemy is hit
     */
    bool IsPiercing;
    /*! Is navigating gravity to direction of bullet angle
     */
    bool IsNavigatingGravityToDirection;
    /*! A sound for shot
     */
    sad::String SoundName;

    /*! Default bullet settings
     */
    inline BulletSettings()
    : IconName("bullets/green/x_huge"),
    Speed(400),
    ApplyGravity(false),
    AngularSpeed(0),
    IsGhost(false),
    MaxBounceCount(0),
    RestitutionCoefficient(1.0),
    IsPiercing(false),
    IsNavigatingGravityToDirection(false)
    {

    }
};

/*! Exposes bullet settings to context
    \param[in] c context
 */
void exposeBulletSettings(void* c);

}
