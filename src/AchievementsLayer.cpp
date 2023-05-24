#include <AchievementsLayer.h>

void AchievementsLayer::onNextPage(cocos2d::CCObject* pObj) {
	this->loadPage(this->m_nCurrentPage + 1);
}

void AchievementsLayer::onPrevPage(cocos2d::CCObject* pObj) {
	this->loadPage(this->m_nCurrentPage - 1);
}

void AchievementsLayer::setupLevelBrowser(cocos2d::CCArray* levels) {
	this->m_pListLayer->removeChildByTag(9, true);
	CustomListView* listView = CustomListView::create(levels, 220.0, 356.0, 0, 4);
	listView->setTag(9);
	this->m_pListLayer->addChild(listView, 6);
}

void AchievementsLayer::setupPageInfo(int totalAchs, int firstAch, int achsPerPage) {
	this->m_pPrevBtn->setVisible(firstAch);

	int lastAch = firstAch + achsPerPage;

	this->m_pNextBtn->setVisible(lastAch < totalAchs);

	int endAch = (lastAch >= totalAchs) ? totalAchs : lastAch;

	const char* newStr = cocos2d::CCString::createWithFormat("%i to %i of %i", firstAch + 1, endAch, totalAchs)->getCString();
	this->m_pPagesLabel->setString(newStr);
}

void AchievementsLayer::keyDown(cocos2d::enumKeyCodes key) {
    if (key != cocos2d::KEY_Right) {
        if (key == cocos2d::KEY_Left || key == cocos2d::CONTROLLER_Left) {
            if (this->m_pPrevBtn->isVisible())
                this->onPrevPage(nullptr);
            return;
        }

        if (key < cocos2d::KEY_Right || key != cocos2d::CONTROLLER_Right) {
            this->keyDown(key);
            return;
        }
    }

	if (this->m_pNextBtn->isVisible())
		this->onNextPage(nullptr);
}

void AchievementsLayer::customSetup() {
	cocos2d::CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
	bool controllerConnected = PlatformToolbox::isControllerConnected();
	cocos2d::CCMenu* menu = cocos2d::CCMenu::create();

	const char* backSprName = "";
	if (controllerConnected)
		backSprName = "controllerBtn_DPad_Left_001.png";
	else
		backSprName = "GJ_arrow_01_001.png";

	CCMenuItemSpriteExtra* backBtn = CCMenuItemSpriteExtra::create(cocos2d::CCSprite::createWithSpriteFrameName(backSprName), nullptr, this, AchievementsLayer::onPrevPage);
	this->m_pPrevBtn = backBtn;
	menu->addChild(backBtn);
	cocos2d::CCPoint newPos = ccp(cocos2d::CCDirector::sharedDirector()->getScreenLeft() + 24, winSize.height * 0.5);
	this->m_pPrevBtn->setPosition(menu->convertToNodeSpace(newPos));

	const char* nextSprName = "";
	if (controllerConnected)
		nextSprName = "controllerBtn_DPad_Right_001.png";
	else
		nextSprName = "GJ_arrow_01_001.png";

	cocos2d::CCSprite* nextSpr = cocos2d::CCSprite::createWithSpriteFrameName(nextSprName);

	if (!controllerConnected)
		nextSpr->setFlipX(true);

	CCMenuItemSpriteExtra* nextBtn = CCMenuItemSpriteExtra::create(nextSpr, nullptr, this, AchievementsLayer::onNextPage);
	this->m_pNextBtn = nextBtn;
	menu->addChild(nextBtn);
	cocos2d::CCPoint newPos2 = ccp(cocos2d::CCDirector::sharedDirector()->getScreenRight() - 24, winSize.height * 0.5);
	this->m_pNextBtn->setPosition(menu->convertToNodeSpace(newPos2));

	this->m_mainLayer->addChild(menu, 10);

	this->m_pPagesLabel = cocos2d::CCLabelBMFont::create(" ", "goldFont.fnt");
	this->m_mainLayer->addChild(this->m_pPagesLabel);
	cocos2d::CCDirector* director = cocos2d::CCDirector::sharedDirector();
	this->m_pPagesLabel->setPosition(ccp(director->getScreenRight() - 7, director->getScreenTop() - 4));
	this->m_pPagesLabel->setAnchorPoint({ 1, 1 });
	this->m_pPagesLabel->setScale(0.6);
	
	this->loadPage(0);
	if (controllerConnected)
		GameToolbox::addRThumbScrollButton(this->m_mainLayer);
}

void AchievementsLayer::loadPage(int page) {
	this->m_nCurrentPage = page;
	this->m_pPrevBtn->setVisible(page > 0);

	AchievementManager* achManager = AchievementManager::sharedState();
	cocos2d::CCArray* allAchs = achManager->getAllAchievements();

	if (!achManager->isAchievementEarned("geometry.ach.steam01")) {
		for (int i = 0; i < allAchs->count(); ++i) {
			cocos2d::CCDictionary* ach = dynamic_cast<cocos2d::CCDictionary*>(allAchs->objectAtIndex(i));
			const char* id = ach->valueForKey("identifier")->getCString();

			if (id == "geometry.ach.steam01") {
				allAchs->removeObjectAtIndex(i);
				break;
			}
		}
	}

	if (!achManager->isAchievementEarned("geometry.ach.steam02")) {
		for (int j = 0; j < allAchs->count(); ++j) {
			cocos2d::CCDictionary* ach = dynamic_cast<cocos2d::CCDictionary*>(allAchs->objectAtIndex(j));
			const char* id = ach->valueForKey("identifier")->getCString();

			if (id == "geometry.ach.steam02") {
				allAchs->removeObjectAtIndex(j);
				break;
			}
		}
	}

	int firstAch = 10 * page;
	cocos2d::CCArray* achsForPage = cocos2d::CCArray::create();
	int totalPages = allAchs->count();

	if (allAchs && allAchs->count()) {
		for (int k = firstAch; k != firstAch + 10 && k <= allAchs->count() - 1; ++k) {
			achsForPage->addObject(allAchs->objectAtIndex(k));
		}
	}

	int endAch = achsForPage->count() + firstAch;
	this->m_pNextBtn->setVisible(endAch < allAchs->count());
	this->setupPageInfo(totalPages, firstAch, 10);
	this->setupLevelBrowser(achsForPage);
}

AchievementsLayer::AchievementsLayer() {
	this->m_nCurrentPage = 0;
	this->m_pNextBtn = 0;
	this->m_pPrevBtn = 0;
	this->m_pPagesLabel = 0;
	this->m_CCPoint = ccp(0, 0);
}

AchievementsLayer* AchievementsLayer::create() {
	auto pRet = new AchievementsLayer();

	if (pRet && pRet->init("Achievements")) {
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}