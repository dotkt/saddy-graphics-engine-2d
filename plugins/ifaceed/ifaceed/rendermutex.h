/*! \file rendermutex.h
	\author HiddenSeeker
	Declares a mutex for rendering scene to sync between a Qt and saddy
 */
#include<os/mutex.h>

/*! This mutex should be locked by a scene to render properly.
	Every action, that needs should be performed after locking this mutex;
 */
extern os::mutex RenderMutex;