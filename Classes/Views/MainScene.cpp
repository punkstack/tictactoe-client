#include "MainScene.h"
#include "Definations.h"
#include "SonarFrameworks.h"

USING_NS_CC;


Scene* MainScene::createScene() {
    return MainScene::create();
}


// on "init" you need to initialize your instance
bool MainScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    if (m_rendered == true) {
        return true;
    }
    renderScene();
    
    m_rendered = true;
    return true;
}

void MainScene::onExit()
{
    // Unsubscribe from WebSocket events
//    auto webSocketController = WebSocketController::getInstance();
    //    webSocketController->onMessage = nullptr;
    //    webSocketController->onError = nullptr;

    Scene::onExit();
}

void MainScene::onEnter()
{
    Scene::onEnter();
}


void MainScene::setPlayCallback(const std::function<void()>& callback) {
    m_playCallback = callback;
}

void MainScene::renderScene() {
    Size screenSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    SonarCocosHelper::UI::AddCentredBackground(MAIN_MENU_BACKGROUND_FILEPATH, this);
    
    Sprite* title = Sprite::create(MAIN_MENU_TITLE_FILEPATH);
    title->setPosition(Vec2(screenSize.width / 2 + origin.x, screenSize.height * 0.75 + origin.y));
    this->addChild(title);

    v_playButton = Button::create(MAIN_MENU_PLAY_BUTTON, MAIN_MENU_PLAY_BUTTON_PRESSED);
    v_playButton->setPosition(SonarCocosHelper::UI::GetScreenCenter());
    this->addChild(v_playButton);
    
    v_playButton->setVisible(false);

    v_playButton->addTouchEventListener(CC_CALLBACK_2(MainScene::touchEvent, this));
    v_playButton->setTag(TAG_MAIN_MENU_PLAY_BUTTON);

    v_playButtonOuter = Sprite::create(MAIN_MENU_PLAY_BUTTON_OUTER);
    v_playButtonOuter->setPosition(SonarCocosHelper::UI::GetScreenCenter());
    this->addChild(v_playButtonOuter);
    
    v_playButtonOuter->setVisible(false);

    ui.AddAudioToggle(SOUND_ON_BUTTON, SOUND_ON_BUTTON_PRESSED, SOUND_OFF_BUTTON, SOUND_OFF_BUTTON_PRESSED, this, SonarCocosHelper::UIButtonPosition::eBottomRight);

    Button* v_achivementsButton = Button::create(ACHIEVEMENTS_BUTTON, ACHIEVEMENTS_BUTTON_PRESSED);
    v_achivementsButton->setPosition(SonarCocosHelper::UI::GetScreenCorner(SonarCocosHelper::UIButtonPosition::eBottomLeft, v_achivementsButton));
    this->addChild(v_achivementsButton);

    v_achivementsButton->addTouchEventListener(CC_CALLBACK_2(MainScene::touchEvent, this));
    v_achivementsButton->setTag(TAG_ACHIEVEMENTS_BUTTON);
}

void MainScene::touchEvent(Ref* sender, Widget::TouchEventType type) {
    Node* node = static_cast<Node*>(sender);

    switch (type)
    {
    case Widget::TouchEventType::BEGAN:
        // code to handle when the button is first clicked
        break;

    case Widget::TouchEventType::MOVED:
        // code to handle when the user is moving their finger/cursor whilst clicking the button
        break;

    case Widget::TouchEventType::ENDED:
        // code to handle when the button click has ended (e.g. finger is lifted off the screen)
        if (TAG_MAIN_MENU_PLAY_BUTTON == node->getTag())
        {
            if (m_playCallback) {
                m_playCallback();
            }
        }
        else if (TAG_ACHIEVEMENTS_BUTTON == node->getTag())
        {
            SonarCocosHelper::GameCenter::showAchievements();
            SonarCocosHelper::GooglePlayServices::showAchievements();
        }

        break;

    case Widget::TouchEventType::CANCELED:
        // code to handle when the button click has been cancelled,  this is usually handled the same way as ENDED in most applications (e.g. another application takes control of the device)
        break;

    default:
        break;
    }
}

void MainScene::setPlayerButtonVisible() {
    v_playButton->setVisible(true);
    v_playButtonOuter->setVisible(true);
}
