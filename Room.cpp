#include <Ogre.h>
#include <OgreEntity.h>
#include <OgreSceneManager.h>

class Room{
	protected:
		Ogre::SceneNode* roomNode;
		Ogre::Vector3 center;
		int maxHeight;
		int minHeight;
		int leftMost;
		int rightMost;
		int closest;
		int furthest;
		void buildWalls(Ogre::SceneManager* scnMgr, 
			Ogre::Vector3 center, 
			int height, int width, int depth);

		
	public:
		Room(Ogre::SceneManager* scnMgr);
		~Room();
		int getMaxHeight(){return maxHeight;}
		int getMinHeight(){return minHeight;}
		int getLeftMost() {return leftMost;}
		int getRightMost(){return rightMost;}
		int getClosest()  {return closest;}
		int getFurthest() {return furthest;}

};

Room::Room(Ogre::SceneManager* scnMgr){
	maxHeight = 50;
	minHeight = 50;
	leftMost = 50;
	rightMost = 50;
	closest = 50;
	furthest = 50;

	buildWalls(scnMgr, Ogre::Vector3(0, 0, 0), 100, 100, 100);
}

void Room::buildWalls(Ogre::SceneManager* scnMgr, 
	Ogre::Vector3 center, 
	int height, int width, int depth){

	    Ogre::Plane plane1(Ogre::Vector3::UNIT_Y, -50);
    Ogre::MeshManager::getSingleton().createPlane(
        "floor",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane1,
        100, 100, 1, 1,
        true,
        1, 5, 5,
        Ogre::Vector3::UNIT_Z);
    Ogre::Entity* floor_ = scnMgr->createEntity("floor");
    floor_->setMaterialName("Examples/Rockwall");
    floor_->setCastShadows(true);
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(floor_);

    //set up room
    Ogre::Plane plane5(Ogre::Vector3::NEGATIVE_UNIT_Y, -50);
    Ogre::MeshManager::getSingleton().createPlane(
        "ceiling",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane5,
        100, 100, 1, 1,
        true,
        1, 5, 5,
        Ogre::Vector3::UNIT_Z);
    Ogre::Entity* ceiling_ = scnMgr->createEntity("ceiling");
    ceiling_->setMaterialName("Examples/Rockwall");
    ceiling_->setCastShadows(true);
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ceiling_);


    Ogre::Plane plane2(Ogre::Vector3::UNIT_Z, -50);
    Ogre::MeshManager::getSingleton().createPlane(
        "wall",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane2,
        100, 100, 1, 1,
        true,
        1, 5, 5,
        Ogre::Vector3::UNIT_Y);
    Ogre::Entity* wall_ = scnMgr->createEntity("wall");
    wall_->setCastShadows(true);
    wall_->setMaterialName("Examples/Rockwall");
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(wall_);

    Ogre::Plane plane3(Ogre::Vector3::UNIT_X, -50);
    Ogre::MeshManager::getSingleton().createPlane(
        "wall3",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane3,
        100, 100, 1, 1,
        true,
        1, 5, 5,
        Ogre::Vector3::UNIT_Y);
    Ogre::Entity* wall_3 = scnMgr->createEntity("wall3");
    wall_3->setCastShadows(true);
    wall_3->setMaterialName("Examples/Rockwall");
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(wall_3);

    Ogre::Plane plane4(Ogre::Vector3::NEGATIVE_UNIT_X, -50);
    Ogre::MeshManager::getSingleton().createPlane(
        "wall4",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane4,
        100, 100, 1, 1,
        true,
        1, 5, 5,
        Ogre::Vector3::UNIT_Y);
    Ogre::Entity* wall_4 = scnMgr->createEntity("wall4");
    wall_4->setCastShadows(true);
    wall_4->setMaterialName("Examples/Rockwall");
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(wall_4);
}

