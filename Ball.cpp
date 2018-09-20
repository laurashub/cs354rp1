#include <iostream>
#include <Ogre.h>
#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include "Room.cpp"

class Ball{
	protected:
		Ogre::SceneNode*  ballNode;
		Ogre::Real bRadius;
		Ogre::Vector3 bDirection;
		Ogre::Real bSpeed;
		Room* room;

	public:
		Ball(Ogre::SceneManager* scnMgr);
		~Ball();
		void move(const Ogre::FrameEvent& evt);
		Ogre::SceneNode* getNode(){return ballNode;}
		void setRoom(Room* r);
};

Ball::Ball(Ogre::SceneManager* scnMgr){
	Ogre::Entity* ball = scnMgr->createEntity("Sphere", "sphere.mesh");
	ball->setCastShadows(true);
	ballNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	ballNode->attachObject(ball); 
	ballNode->scale(0.1f,0.1f,0.1f); 
	bRadius = 5.0f; 
	bDirection = Ogre::Vector3(1.0f, 2.0f, 3.0f); 
	bDirection.normalise(); 
	bSpeed = 50.0f;
}

void Ball::move(const Ogre::FrameEvent& evt) { 
	Ogre::Vector3 bPosition = ballNode->getPosition(); 
	if (room){
	if (bPosition.y < -room->getMaxHeight() + bRadius && bDirection.y < 0.0f) bDirection.y = -bDirection.y; 
	if (bPosition.y > room->getMinHeight() - bRadius && bDirection.y > 0.0f) bDirection.y = -bDirection.y; 
	if (bPosition.z < -room->getClosest() + bRadius && bDirection.z < 0.0f) bDirection.z = -bDirection.z; 
	if (bPosition.z > room->getFurthest() - bRadius && bDirection.z > 0.0f) bDirection.z = -bDirection.z; 
	if (bPosition.x < -room->getLeftMost() + bRadius && bDirection.x < 0.0f) bDirection.x = -bDirection.x; 
	if (bPosition.x > room->getRightMost() - bRadius && bDirection.x > 0.0f) bDirection.x = -bDirection.x; 
	}
	ballNode->translate(bSpeed * evt.timeSinceLastFrame * bDirection); 
}

void Ball::setRoom(Room* r){
	room = r;
}