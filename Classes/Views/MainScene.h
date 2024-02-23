//
// Created by Manoj Bojja on 22/02/24.
//

#ifndef TICTACTOE_MAINSCENE_H
#define TICTACTOE_MAINSCENE_H

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "SonarFrameworks.h"

USING_NS_CC;


class MainScene: public cocos2d::Scene {
    bool m_rendered{false};
    std::function<void()> m_playCallback;
    
public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;
    
    void setPlayerButtonVisible();
    
    void setPlayCallback(const std::function<void()>& callback);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);

private:
    Button* v_playButton;
    Sprite* v_playButtonOuter;
    SonarCocosHelper::UI ui;
    
    void renderScene();
    void touchEvent(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    void onEnter() override;
    void onExit() override;
};

#endif //TICTACTOE_MAINSCENE_H
