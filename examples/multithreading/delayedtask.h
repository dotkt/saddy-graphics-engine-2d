/*! \file delayedtask.h
 *
 *  A pausable delayed task to be performed in event loop
 */
#pragma once
#include <functional>
#include <pausabletimer.h>

class Game;

/*! A delayed task data
 */
class DelayedTask
{
public:
    /*! Makes new delayed task
     * \param[in] time a time
     * \param[in] f a delayed task
     */
    DelayedTask(double time, std::function<void()>  f);
    /*! Tries to execute task
     *  \return true if executed
     */
    bool tryExecute();
    /*! Pauses delayed task
     */
    void pause();
    /*! Resumes delayed task
     */
    void resume();
protected:
    /*! A function to be executed
     */
    std::function<void()> m_fn;
    /*! A timer value
     */
    sad::PausableTimer m_timer;
    /*! A total execution time
     */
    double m_time;
};
