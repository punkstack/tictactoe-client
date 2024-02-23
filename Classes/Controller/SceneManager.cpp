//
// Created by Manoj Bojja on 22/02/24.
//
#include "SceneManager.h"
#include "Definations.h"
#include "MainScene.h"

USING_NS_CC;

void SceneManager::SwitchScene(cocos2d::Scene *scene) {
    if (scene != nullptr) {
        TransitionFade *transition = TransitionFade::create( SCENE_TRANSITION_TIME, scene );
        Director::getInstance( )->replaceScene( transition );
    } else {
        return;
    }
}
