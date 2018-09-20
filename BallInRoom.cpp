#include <Ogre.h>
#include <OgreConfigFile.h>
#include <OgreApplicationContext.h>
#include <OgreInput.h>
#include "Ball.cpp"

class BallInRoom : 
    public OgreBites::ApplicationContext, 
    public OgreBites::InputListener
{
public:
    BallInRoom();
    virtual ~BallInRoom();
    void setup();
    bool keyPressed(const OgreBites::KeyboardEvent& evt);
    void frameRendered(const Ogre::FrameEvent& evt);

protected:
    Ball* ball;
    Room* room;
};


//constructor
BallInRoom::BallInRoom()
    : OgreBites::ApplicationContext("")
{
}

//destructor
BallInRoom::~BallInRoom()
{
}

//! [key_handler]
bool BallInRoom::keyPressed(const OgreBites::KeyboardEvent& evt)
{
    return true;
}

void BallInRoom::frameRendered(const Ogre::FrameEvent& evt){
    if (ball){
        ball->move(evt);
    }
}

//! [key_handler]

//! [setup]
void BallInRoom::setup(void)
{
    OgreBites::ApplicationContext::setup();
    addInputListener(this);

    Ogre::Root* root = getRoot();
    root->addFrameListener(this);
    Ogre::SceneManager* scnMgr = root->createSceneManager();

    //get room
    room = new Room(scnMgr);

    //get ball
    ball = new Ball(scnMgr);
    ball->setRoom(room);


    scnMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    Ogre::RTShader::ShaderGenerator* shadergen =
        Ogre::RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);

    
    Ogre::Light* light = scnMgr->createLight("MainLight");
    Ogre::SceneNode* lightNode = 
        scnMgr->getRootSceneNode()->createChildSceneNode();
    lightNode->setPosition(20, 80, 50);
    lightNode->attachObject(light); 

    Ogre::SceneNode *camNode = 
        scnMgr->getRootSceneNode()->createChildSceneNode();
    camNode->setPosition(0,0,150);
    camNode->lookAt(Ogre::Vector3(0, 0, 50), Ogre::Node::TS_PARENT);

    Ogre::Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5);
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);

    getRenderWindow()->addViewport(cam);
}


//! [setup]

//! [main]
int main(int argc, char *argv[])
{
    BallInRoom bir;
    bir.initApp();
    bir.getRoot()->startRendering();
    bir.closeApp();
    return 0;
}
//! [main]
