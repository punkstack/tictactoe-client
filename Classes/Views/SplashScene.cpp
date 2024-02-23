
#include "SplashScene.h"
#include "SimpleAudioEngine.h"
#include "Definations.h"
#include "SceneManager.h"
#include "SonarFrameworks.h"
#include "MainSceneController.h"

USING_NS_CC;

Scene* Splash::createScene()
{
    return Splash::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Splash::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    SonarCocosHelper::GameCenter::signIn();

    SonarCocosHelper::UI::AddCentredBackground(SPLASH_SCENE_BACKGROUND_FILEPATH, this);

    scheduleOnce( schedule_selector( Splash::SwitchToMainMenu ), SPLASH_SCENE_SHOW_TIME );

    return true;
}


void Splash::SwitchToMainMenu(float dt)
{
    MainSceneController *mC = new MainSceneController();
    mC->renderMainView();
}
