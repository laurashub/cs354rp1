/*#include <Ogre.h>

class BIRFrameListener : public Ogre::FrameListener{
	bool frameRenderingQueued(const Ogre::FrameEvent& evt);	

};

bool BIRFrameListener::frameRenderingQueued(const Ogre::FrameEvent& evt){
	if(mWindow->isClosed()) return false; 
		
	mControls->update(); 
	if (mControls->exit()) return false; 
	mGUI->frameRenderingQueued(evt); 
	if (!mGUI->isDialogVisible()) { 

		// if dialog isn't up, then update the scene 
		mCameraMan->frameRenderingQueued(evt); 
		// Move the ball 
		ball->move(evt); 
	} 
    return true; 
} */
