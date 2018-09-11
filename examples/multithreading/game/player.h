/*!  \file player.h

     Describes a player, that will exist in game
 */
#pragma once
#include "inventory.h"
#include <sprite2d.h>
#include <p2d/body.h>
#include <actor.h>
#include <animations/animationsinstance.h>
#include <animations/animationsoptionlist.h>

class Game;

namespace game
{

/*! A player
 */
class Player
{
public:
    /*! Maximal horizontal velocity for player
     */
    static const int MaxHorizontalVelocity;
    /*! Maximal vertical velocity for player
     */
    static const int MaxVerticalVelocity;
    /*! A player, that will be used in game
     */
    Player();
    /*! Frees data from player
     */
    ~Player();
    /*! Tries to set actor options for player
        \param[in] opts an options
        \throws logic_error if options are invalid
        \return true if setting is succesfull, otherwise false
     */
    bool setActorOptions(game::ActorOptions* opts);
    /*! Sets game for player
        \param[in] gama a game
     */
    void setGame(Game* game);
    /*! Resets player's items in game
     */
    void reset();
    /*! Returns player's inventory
     *  \return inventory of player
     */
    game::Inventory* inventory();
    /*! Whether player is resting on platform
        \return whether he is resting
     */
    bool isResting() const;
    /*! Whether player can jump
        \return whether player can jump
     */
    bool canJump() const;
    /*! Sets sprite for player
     *  \param[in] sprite a sprite
     */
    void setSprite(sad::Sprite2D* sprite);
    /*! Sets body for player
     *  \param[in] body a body for player
     */
    void setBody(sad::p2d::Body* body);
    /*! Sets horizontal velocity for player
     *  \param[in] value velocity value
     */
    void setHorizontalVelocity(double value);
    /*! Increments vertical velocity of player by value
     */
    void incrementVerticalVelocity(double value) const;
    /*! Enables gravity for body
     */
    void enableGravity() const;
    /*! Disables gravity for body
     */
    void disableGravity() const;
    /*! Rests player on platform
        \param[in] b body
        \param[in] old_velocity old platform's velocity
     */
    void restOnPlatform(sad::p2d::Body* b, const  sad::p2d::Vector& old_velocity);
    /*! Disables resting player on platform
     */
    void disableResting();
    /*! Fetches area for user
     */
    sad::Rect2D area() const;
    /*! Moves player by point
     */
    void move(const sad::Point2D& p) const;
    /*! Clears flags, which determine, whether player's position is fixed
     */
    void clearFixedFlags();
    /*! Tests, whether x coordinate fixed
     *  \return whehter it's fixed
     */
    bool isXCoordinateFixed() const;
    /*! Tests, whether y coordinate fixed
     *  \return whehter it's fixed
     */
    bool isYCoordinateFixed() const;
    /*! Makes x coordinate fixed or not
     *  \param[in] value m new value
     */
    void setXCoordinateFixed(bool value);
    /*! Makes y coordinate fixed or not
     *  \param[in] value m new value
     */
    void setYCoordinateFixed(bool value);
    /*! Returns body for player
     *  \return body
     */
    sad::p2d::Body* body() const;
    /*! Returns sprite for player
        \return sprite for player
     */
    sad::Sprite2D* sprite() const;
    /*! Tests resting a player
     */
    void testResting();
    /*! Pushes old options, replaces with new in sprite
     *  \param[in] new_options a new options
     */
    void pushOptions(const sad::String& new_options);
    /*! Pops options
     */
    void popOptions();
    /*! Starts moving actor to left
     */
    void startMovingLeft();
    /*! Start moving actor to right
     */
    void startMovingRight();
    /*! Stops actor from moving horizontally
     */
    void stopMovingHorizontally();
    /*! Makes actor try to jump
     */
    void tryJump();
    /*! Makes actor start falling or duck
     */
    void startFallingOrDuck();
    /*! Stops falling or ducking for actor
     */
    void stopFallingOrStopDucking();
    /*! Makes actor stop ducking
     */
    void duck();
    /*!  Makes actor stand, not duck
     */
    void stopDucking();
    /*! Returns whether actor is ducking
        \return whether actor is ducking
     */
    bool isDucking() const;
    /*! Returns whether actor is freefalling
        \return whether actor is freefalling
     */
    bool isFreefalling() const;
    /*! Returns old velocity for player
        \return old veloctity
     */
    const sad::p2d::Vector& oldVelocity() const;
private:
    /*! Player's inventory, that will be carried around
     */
    game::Inventory m_inventory;
    /*! An actor for player
     */
    game::Actor m_actor;
};

}
