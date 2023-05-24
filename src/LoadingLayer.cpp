#include "../headers/includes.h"

const char* LoadingLayer::getLoadingString() {
	if (this->m_bFromReload)
		return "Loading resources";

	switch (rand() % 60) {
    case 0:
        return "Unlock new icons and colors by completing achievements!";
        break;
    case 1:
        return "Listen to the music to help time your jumps";
        break;
    case 2:
        return "Back for more are ya?";
        break;
    case 3:
        return "Use practice mode to learn the layout of a level";
        break;
    case 4:
        return "If at first you don't succeed, try, try again...";
        break;
    case 5:
        return "Customize your character's icon and color!";
        break;
    case 6:
        return "You can download all songs from the level select page!";
        break;
    case 7:
        return "Spikes are not your friends, don't forget to jump";
        break;
    case 8:
        return "Build your own levels using the level editor";
        break;
    case 9:
        return "Go online to play other players levels!";
        break;
    case 10:
        return "Can you beat them all?";
        break;
    case 11:
        return "Here be dragons...";
        break;
    case 12:
        return "Pro tip: Don't crash";
        break;
    case 13:
        return "Hold down to keep jumping";
        break;
    case 14:
        return "The spikes whisper to me...";
        break;
    case 15:
        return "Looking for pixels";
        break;
    case 16:
        return "Loading awesome soundtracks...";
        break;
    case 17:
        return "What if the spikes are the good guys?";
        break;
    case 18:
        return "Pro tip: Jump";
        break;
    case 19:
        return "Does anyone even read this?";
        break;
    case 20:
        return "Collecting scrap metal";
        break;
    case 21:
        return "Waiting for planets to align";
        break;
    case 22:
        return "Starting the flux capacitor";
        break;
    case 23:
        return "Wandering around aimlessly";
        break;
    case 24:
        return "Where did I put that coin...";
        break;
    case 25:
        return "Loading the progressbar";
        break;
    case 26:
        return "Calculating chance of success";
        break;
    case 27:
        return "Hiding secrets";
        break;
    case 28:
        return "Drawing pretty pictures";
        break;
    case 29:
        return "Programmer is sleeping, please wait";
        break;
    case 30:
        return "RobTop is Love, RobTop is Life";
        break;
    case 31:
        return "Play, Crash, Rage, Quit, Repeat";
        break;
    case 32:
        return "Only one button required to crash";
        break;
    case 33:
        return "Such wow, very amaze.";
        break;
    case 34:
        return "Fus Ro DASH!";
        break;
    case 35:
        return "Loading Rage Cannon";
        break;
    case 36:
        return "Counting to 1337";
        break;
    case 37:
        return "It's all in the timing";
        break;
    case 38:
        return "Fake spikes are fake";
        break;
    case 39:
        return "Spikes... OF DOOM!";
        break;
    case 40:
        return "Why don't you go outside?";
        break;
    case 41:
        return "Loading will be finished... soon";
        break;
    case 42:
        return "This seems like a good\nplace to hide a secret...";
        break;
    case 43:
        return "The Vault Keeper's name is 'Spooky'...";
        break;
    case 44:
        return "Hope the big guy doesn't wake up...";
        break;
    case 45:
        return "Shhhh! You're gonna wake the big one!";
        break;
    case 46:
        return "I have been expecting you.";
        break;
    case 47:
        return "A wild RubRub appeared!";
        break;
    case 48:
        return "So many secrets...";
        break;
    case 49:
        return "Hiding rocket launcher";
        break;
    case 50:
        return "It's Over 9000!";
        break;
    case 51:
        return "Programming amazing AI";
        break;
    case 52:
        return "Hiding secret vault";
        break;
    case 53:
        return "Spooky doesn't get out much";
        break;
    case 54:
        return "RubRub was here";
        break;
    case 55:
        return "Warp Speed";
        break;
    case 56:
        return "So, what's up?";
        break;
    case 57:
        return "Hold on, reading the manual";
        break;
    case 58:
        return "I don't know how this works...";
        break;
    case 59:
        return "Why u have to be mad?";
        break;
	}
}

cocos2d::CCScene* LoadingLayer::scene(bool fromReload) {
    auto scene = cocos2d::CCScene::create();
    scene->addChild(LoadingLayer::create(fromReload));
    return scene;
}

void LoadingLayer::loadingFinished() {
    //if (this->m_bFromReload)
    //{
    //    v4 = cocos2d::CCDirector::sharedDirector();
    //    v2 = MenuLayer::scene();
    //    v3 = v4;
    //}
    //else
    //{
    //    v1 = cocos2d::CCDirector::sharedDirector();
    //    v2 = MenuLayer::scene();
    //    v3 = v1;
    //}
    //cocos2d::CCDirector::replaceScene(v3, v2);
    // what the heck lmao

    cocos2d::CCDirector* director;
    cocos2d::CCScene* scene;

    if (this->m_bFromReload) {
        scene = MenuLayer::scene();
        director = cocos2d::CCDirector::sharedDirector();
    }
    else {
        scene = MenuLayer::scene();
        director = cocos2d::CCDirector::sharedDirector();
    }

    director->replaceScene(scene);
}

void LoadingLayer::loadAssets() {
    switch (this->m_nLoadingStage) {
    case 0:
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_GameSheet.png", false);
        cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("GJ_GameSheet.plist");
        break;
    case 1:
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_GameSheet02.png", false);
        cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("GJ_GameSheet02.plist");
        break;
    case 2:
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_GameSheet03.png", false);
        cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("GJ_GameSheet03.plist");
        break;
    case 3:
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_GameSheet04.png", false);
        cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("GJ_GameSheet04.plist");
        break;
    case 4:
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_GameSheetGlow.png", false);
        cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("GJ_GameSheetGlow.plist");
        break;
    case 5:
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("FireSheet_01.png", false);
        cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("FireSheet_01.plist");
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_ShopSheet.png", false);
        cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("GJ_ShopSheet.plist");
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("smallDot.png", false);
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("square02_001.png", false);
        break;
    case 6:
        if (AppDelegate::get()->m_resourceRootPath) { // *(AppDelegate::get() + 19)
            cocos2d::CCTextureCache::sharedTextureCache()->addImage("CCControlColourPickerSpriteSheet.png", false);
            cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("CCControlColourPickerSpriteSheet.plist");
        }

        auto texFormat = cocos2d::CCTexture2D::defaultAlphaPixelFormat();
        cocos2d::CCTexture2D::setDefaultAlphaPixelFormat(cocos2d::kCCTexture2DPixelFormat_RGBA8888);

        if (!AppDelegate::get()->m_resourceRootPath) {
            cocos2d::CCTextureCache::sharedTextureCache()->addImage("CCControlColourPickerSpriteSheet.png", false);
            cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("CCControlColourPickerSpriteSheet.plist");
        }

        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_gradientBG.png", false);
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("edit_barBG_001.png", false);
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_button_01.png", false);
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("slidergroove2.png", false);
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("sliderBar2.png", false);

        cocos2d::CCTexture2D::setDefaultAlphaPixelFormat(texFormat);
        break;
    case 7:
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_square01.png", false);
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_square02.png", false);
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_square03.png", false);
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_square04.png", false);
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("gravityLine_001.png", false);
        break;
    case 8:
        cocos2d::CCLabelBMFont::create(" ", "chatFont.fnt");

        TextArea::create("temp", "chatFont.fnt", 1.0, 200.0, { 0.0, 20.0 }, 0.0);

        cocos2d::CCTextureCache::sharedTextureCache()->addImage("goldFont.png", false);
        cocos2d::CCTextureCache::sharedTextureCache()->addImage("bigFont.png", false);

        cocos2d::CCLabelBMFont::create(" ", "goldFont.fnt");
        cocos2d::CCLabelBMFont::create(" ", "bigFont.fnt");
        break;
    case 9:
        ObjectManager::instance()->setup();
        CCAnimateFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Robot_AnimDesc.plist");
        CCContentManager::sharedManager()->addDict("glassDestroy01.plist", false);
        CCContentManager::sharedManager()->addDict("coinPickupEffect.plist", false);
        CCContentManager::sharedManager()->addDict("explodeEffect.plist", false);

        AchievementManager::sharedState();
        ObjectToolbox::sharedState();
        break;
    case 10:
        // lmao nothing here
        break;
    case 11:
        if (*(GameManager::sharedState() + 555)) // idk what those are
        {
            if (!this->m_bFromReload)
            {
                *(GameManager::sharedState() + 552) = 1;
                EveryplayToolbox::firstSetup();
            }
        }
        break;
    case 12:
        CCTextInputNode::create(200.0, 50.0, "Temp", "Thonburi", 24, "bigFont.fnt");
        break;
    case 13:
        if (!this->m_bFromReload) {
            auto wave = CCCircleWave::create(10.0, 5.0, 0.3, 1);
            this->addChild(wave);
            wave->setPosition({ -100.0, -100.0 });
        }
        break;
    }

    if (this->m_nLoadingStage != 14) {
        int stage = this->m_nLoadingStage;
        this->m_bUnk = 1;
        this->m_nLoadingStage = ++stage;
        this->updateProgress(7 * stage);
        cocos2d::CCDirector::sharedDirector()->getActionManager()->addAction(
            cocos2d::CCSequence::create(
                cocos2d::CCDelayTime::create(0.01),
                cocos2d::CCCallFunc::create(this, LoadingLayer::loadAssets),
                nullptr
            ),
            this,
            false
        );

        return;
    }

    cocos2d::CCDirector::sharedDirector()->setSceneDelegate((AppDelegate::get() == nullptr) : nullptr ? *(AppDelegate::get() + 4));

    AppDelegate::get()->loadingIsFinished();
    if (!this->m_bFromReload) {
        GameManager::sharedState()->fadeInMusic("menuLoop.mp3");
        GameManager::sharedState()->syncPlatformAchievements();
    }

    this->loadingFinished();
}

void LoadingLayer::updateProgress(int percent) {
    auto barWidth = this->m_fBarWidth;
    auto spr = this->m_pBarSprite;

    if (barWidth > (barWidth * (percent / 100.0)))
        barWidth = (barWidth * (percent / 100.0))

    this->m_pBarSprite->setTextureRect({ 0.0, 0.0, barWidth, this->m_fBarHeight });
}

bool LoadingLayer::init(bool fromReload) {
    if (cocos2d::CCLayer::init()) {
        this->m_bFromReload = fromReload;

        if (!fromReload) {
            GameSoundManager::sharedManager()->setup();
            GameManager::sharedState()->updateMusic();
        }

        if (*(GameManager::sharedState() + 636)) {
            *(GameManager::sharedState() + 636) = 0;
            GameLevelManager::sharedState()->getLevelSaveData();
        }

        cocos2d::CCTextureCache::sharedTextureCache()->addImage("GJ_LaunchSheet.png", false);
        cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("GJ_LaunchSheet.plist");

        auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

        const char* bgTex = GameManager::sharedState()->getBGTexture(1);
        auto bgSpr = cocos2d::CCSprite::create(bgTex);
        this->addChild(bgSpr);
        bgSpr->setPosition({ winSize.width * 0.5, winSize.height * 0.5 });
        bgSpr->setScale(AppDelegate::get()->bgScale());
        bgSpr->setColor({ 0x0, 0x66, 0xFF });

        auto logoSpr = cocos2d::CCSprite::createWithSpriteFrameName("GJ_logo_001.png");
        this->addChild(logoSpr);
        logoSpr->setPosition({ winSize.width * 0.5, (winSize.height * 0.5) + 0.0 });

        auto robLogoSpr = cocos2d::CCSprite::createWithSpriteFrameName("RobTopLogoBig_001.png");
        this->addChild(robLogoSpr);
        robLogoSpr->setPosition({ logoSpr->getPosition().x, 80.0 });

        this->m_nLoadingStage = 0;
        this->m_bUnk = false;

        auto loadingString = this->getLoadingString();
        auto textLabel = cocos2d::CCLabelBMFont::create(loadingString, "goldFont.fnt");
        this->m_pTextLabel = textLabel;
        this->addChild(textLabel);
        this->m_pTextLabel->setPosition({ winSize.width * 0.5, (winSize.height * 0.5) - 70.0 });
        this->m_pTextLabel->setScale(0.7f);
        this->m_pTextLabel->setVisible(false);

        auto loadingString2 = this->getLoadingString(); // looks like for some reason rob couldnt use the old var lol
        this->m_pText = TextArea::create(loadingString2, "goldFont.fnt", 1.0, 440.0, { 0.5, 28.0 }, 0.0);
        this->addChild(m_pText);
        this->m_pText->setPosition({ winSize.width * 0.5, (winSize.height * 0.5) - 100.0 });
        this->m_pText->setScale(0.7f);

        if (this->m_pTextLabel->getContentSize().width > 300.0) {
            this->m_pTextLabel->setScale(300.0 / this->m_pTextLabel->getContentSize().width);
        }

        this->m_pTextLabel->setScale((this->m_pTextLabel->getScale() < 0.7) ? this->m_pTextLabel->getScale() : 0.7);

        auto slidergroove = cocos2d::CCSprite::create("slidergroove.png");
        this->addChild(slidergroove, 3);
        auto barSpr = cocos2d::CCSprite::create("sliderBar.png");
        this->m_pBarSprite = barSpr;
        this->m_fBarWidth = slidergroove->getTextureRect().size.width - 4.0;
        this->m_fBarHeight = 8.0;

        cocos2d::ccTexParams* params;
        params->minFilter = 9729; // not sure if these are accurate but idk
        params->magFilter = 9729;
        params->wrapS = 10497;
        params->wrapT = 10497;
        barSpr->getTexture()->setTexParameters(params);

        slidergroove->addChild(this->m_pBarSprite, -1);
        this->m_pBarSprite->setAnchorPoint({ 0.0, 0.0 });
        this->m_pBarSprite->setPosition({ 2.0, 4.0 });
        slidergroove->setPosition({ this->m_pTextLabel->getPosition().x, this->m_pText->getPosition().y + 40.0 });

        this->updateProgress(0);

        cocos2d::CCDirector::sharedDirector()->getActionManager()->addAction(
            cocos2d::CCSequence::create(
                cocos2d::CCDelayTime::create(0.0),
                cocos2d::CCCallFunc::create(this, LoadingLayer::loadAssets),
                nullptr
            ),
            this,
            false
        );

        if (!this->m_bFromReload) {
            if (GameManager::sharedState()->getGameVariable("0034"))
                PlatformToolbox::activateGameCenter();
        }

        return true;
    }

    return false;
}

LoadingLayer* LoadingLayer::create(bool fromReload) {
    auto pRet = new LoadingLayer();

    if (pRet && pRet->init(fromReload)) {
        pRet->autorelease();
        return pRet;
    }

    CC_SAFE_DELETE(pRet);
    return nullptr;
}

LoadingLayer::LoadingLayer() {
    this->m_fBarWidth = 0.0;
    this->byte11C = 0;
    this->m_bUnk = false;
    this->m_nLoadingStage = 0;
    this->m_pTextLabel = nullptr;
    this->m_pText = nullptr;
    this->m_pBarSprite = nullptr;
    this->m_fBarHeight = 0.0;
    this->m_bFromReload = false;
}

LoadingLayer::~LoadingLayer() {
    this->removeAllChildrenWithCleanup(true);
}