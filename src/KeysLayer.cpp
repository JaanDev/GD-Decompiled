#include <KeysLayer.h>

void KeysLayer::dialogClosed(DialogLayer* dialog) {
	GameManager::sharedState()->setUGV("11", true);
	this->onShop(nullptr);
}

void KeysLayer::onShop(cocos2d::CCObject* pObj) {
	if (GameManager::sharedState()->getUGV("11")) { // Secret Shop unlocked
		auto transition = cocos2d::CCTransitionMoveInT::create(0.5, GJShopLayer::scene());
		if (cocos2d::CCDirector::sharedDirector()->replaceScene(transition))
			this->setKeypadEnabled(false);
	}
	else {
		auto dialogObjsArray = cocos2d::CCArray::create();
		bool doChangeDelegate = false;

		if (GameStatsManager::sharedState()->getStat("13") >= 500 && GameManager::sharedState()->getUGV("10")) { // total diamonds; Scratch Dialog
			dialogObjsArray->addObject(
				DialogObject::create("Scratch", "Oh,<d020> the <cl>diamonds</c>.<d030>\nYou found them.", 10, 1, false, { 0x65, 0xBF, 0xB8 }
			));

			dialogObjsArray->addObject(
				DialogObject::create("Scratch", "Alright come in, <d010>quickly before someone sees you.", 13, 1, false, { 0x65, 0xBF, 0xB8 }
			));

			dialogObjsArray->addObject(
				DialogObject::create("Scratch", "You never know who might be watching.", 8, 1, false, { 0x65, 0xBF, 0xB8 }
			));

			dialogObjsArray->addObject(
				DialogObject::create("Scratch", "<d010>.<d010>.<d010>.", 9, 1, false, { 0x65, 0xBF, 0xB8 }
			));

			doChangeDelegate = true;
		}
		else {
			this->m_iScratchDialogViewedCount++;
			if (this->m_iScratchDialogViewedCount > 5)
				this->m_iScratchDialogViewedCount = 0;

			switch (this->m_iScratchDialogViewedCount) {
			case 0:
				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "Uhm,<d030> there is no rope.", 8, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "Just<d010>.<d010>.<d010>. Pretend this never happened.", 9, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "<d010>.<d010>.<d010>.", 8, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				break;
			case 1:
				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "I'm gonna need you to stop doing that.", 13, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "If RubRub sees this I am in <cr>BIG</c> trouble.", 8, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "I hate that guy<d010>.<d010>.<d010>.", 12, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				break;
			case 2:
				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "Finally,<d020> I thought you wou<d010>.<d010>.<d010>.<d030>", 10, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "Wait,<d020> You're not the delivery guy.", 11, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "How am I supposed to run a shop if I don't have any merchandise?", 12, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "I mean, <d040>what shop?", 13, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "<d010>.<d010>.<d010>.", 8, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				break;
			case 3:
				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "Look,<d030> I can't let you in.\n<d040>Not without the<d010>.<d010>.<d010>. <cl>stuff</c>.", 8, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "I'm not even supposed to be here.\nI'm just a glitch in the code.", 13, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "Did you hear something?", 8, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "<d010>.<d010>.<d010>.", 9, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				break;
			case 4:
				dialogObjsArray->addObject(
					DialogObject::create(
						"Scratch",
						cocos2d::CCString::createWithFormat("Alright, alright.<d010> If you collect\n<cy>%i</c> <cl>Diamonds</c> I will let you in.", 500)->getCString(),
						10, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create(
						"Scratch",
						cocos2d::CCString::createWithFormat("Usually the limit is %i, but you look a bit scary.", 1000)->getCString(),
						13, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "Just, <d030> get out of here before someone sees you.", 11, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "Do you smell burning chicken?", 8, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "<d010>.<d010>.<d010>.", 9, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				GameManager::sharedState()->setUGV("10", true);
				break;
			case 5:
				dialogObjsArray->addObject(
					DialogObject::create(
						"Scratch",
						cocos2d::CCString::createWithFormat("Collect <cy>%i</c> <cl>Diamonds</c> and I will let you in.", 500)->getCString(),
						10, 0.8, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "Now go away, RubRub might be watching.", 8, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				dialogObjsArray->addObject(
					DialogObject::create("Scratch", "<d010>.<d010>.<d010>.", 9, 1, false, { 0x65, 0xBF, 0xB8 })
				);

				break;
			}
		}

		DialogLayer* dialog = DialogLayer::createWithObjects(dialogObjsArray, 2);
		this->addChild(dialog, 100);

		if (doChangeDelegate)
			dialog->m_pDialogDelegate = this;

		dialog->updateChatPlacement(center);
		dialog->animateInRandomSide();
	}
}

void KeysLayer::onSpecialItem(cocos2d::CCObject* pObj) {
	std::string chestID;
	int requiredOpenedChests = 0;

	switch (pObj->getTag()) {
	case 1:
		chestID = "0004";
		requiredOpenedChests = 50;
		break;
	case 2:
		chestID = "0005";
		requiredOpenedChests = 100;
		break;
	case 3:
		chestID = "0006";
		requiredOpenedChests = 200;
		break;
	}

	auto gsm = GameStatsManager::sharedState();
	if (gsm->m_pOpenedTreasureChestsDict->count() >= requiredOpenedChests) {
		GJRewardItem* reward = gsm->unlockSpecialChest(chestID);

		if (reward) {
			this->switchToOpenedState(pObj);
			auto rewardLayer = RewardUnlockLayer::create(reward->m_eRewardType, 0);
			this->addChild(rewardLayer, 100);
			rewardLayer->showCollectReward(reward);
		}
	}
	else {
		auto dialogObjs = cocos2d::CCArray::create();

		const char* chestsText = "";
		if (requiredOpenedChests - gsm->m_pOpenedTreasureChestsDict->count() == 1)
			chestsText = "Chest";
		else
			chestsText = "Chests";

		dialogObjs->addObject(
			DialogObject::create("The Keymaster",
				cocos2d::CCString::createWithFormat("Unlock <cy>%i</c> more <cg>%s</c>, and you can collect this bonus.", requiredOpenedChests - gsm->m_pOpenedTreasureChestsDict->count(), chestsText)->getCString(),
				2, 1, false, {0x65, 0xBF, 0xB8}
				)
		);

		DialogLayer* dialog = DialogLayer::createWithObjects(dialogObjs, 2);
		this->addChild(dialog, 100);
		dialog->updateChatPlacement(center);
		dialog->animateInRandomSide();
	}
}

void KeysLayer::updateUnlockedLabel() {
	auto gsm = GameStatsManager::sharedState();

	this->m_pOpenedChestsLabel->setString(
		cocos2d::CCString::createWithFormat("%i/%i", gsm->m_pOpenedTreasureChestsDict->count(), gsm->m_pTreasureRoomChestsDict->count())->getCString()
	);
}

void KeysLayer::goToPage(int page) {
	this->m_pBGSprite->stopAllActions();

	int totalPages = this->m_pScrollLayer->getTotalPages();
	auto newPage = page % totalPages;
	if (newPage < 0)
		newPage += page;

	GLubyte r, g, b;
	switch (newPage) {
	case 1:
		b = 79;
		g = 6;
		r = 90;
		break;
	case 2:
		b = 84;
		g = 6;
		r = 81;
		break;
	case 3:
		b = 89;
		g = 7;
		r = 71;
		break;
	case 4:
		b = 93;
		g = 7;
		r = 62;
		break;
	case 5:
		b = 98;
		g = 8;
		r = 53;
		break;
	default:
		b = 75;
		g = 0;
		r = 100;
		break;
	}

	this->m_pBGSprite->runAction(cocos2d::CCTintTo::create(0.3, r, g, b));
	this->m_pScrollLayer->moveToPage(page);
}

void KeysLayer::onBack(cocos2d::CCObject* pObj) {
	GameManager::sharedState()->fadeInMusic("menuLoop.mp3");
	this->setKeypadEnabled(false);
	cocos2d::CCDirector::sharedDirector()->replaceScene(cocos2d::CCTransitionFade::create(0.5, CreatorLayer::scene());
}

void KeysLayer::keyBackClicked() {
	this->onBack(nullptr);
}

void KeysLayer::onSelectItem(cocos2d::CCObject* pObj) {
	int keysCount = GameStatsManager::sharedState()->getStat("21");

	if (keysCount <= 0) {
		FLAlertLayer::create(nullptr, "No Key", "You need a key to unlock this chest.", "OK", nullptr, 380)->show();
	}

	auto btnTag = pObj->getTag();
	int chestID = (CCMenuItemSpriteExtra*)(pObj)->getNormalImage()->getTag();
	GJRewardItem* reward = GameStatsManager::sharedState()->unlockSpecialChest(btnTag);

	if (chestID) {
		reward->m_nChestID = chestID;
		this->switchToOpenedState(pObj);

		auto rewardLayer = RewardUnlockLayer::create(reward->m_eRewardType, 0);
		this->addChild(rewardLayer, 100);
		rewardLayer->showCollectReward(reward);
		this->m_pKeysLabel->setString(cocos2d::CCString::createWithFormat("%i", (keysCount - 1))->getCString());
		this->updateUnlockedLabel();
	}
}

void KeysLayer::onSwitchPage(cocos2d::CCObject* pObj) {
	int currentPage = this->m_pScrollLayer->m_iCurrentPage;

	if (pObj->getTag() != 1)
		this->goToPage(currentPage - 1);
	else
		this->goToPage(currentPage + 1);
}

bool KeysLayer::init() {
	if (!this->init())
		return false;

	this->setKeypadEnabled(true);
	this->setKeyboardEnabled(true);

	auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

	if (GameManager::sharedState()->getUGV("10")) // Scratch Dialog
		this->m_iScratchDialogViewedCount = 4;

	GameManager::sharedState()->fadeInMusic("secretLoop.mp3");

	this->m_pBGSprite = cocos2d::CCSprite::create("GJ_gradientBG.png");
	this->m_pBGSprite->setAnchorPoint({ 0, 0 });
	this->addChild(this->m_pBGSprite, -3);
	this->m_pBGSprite->setScaleX((winSize.width + 10.0) / this->m_pBGSprite->m_obRect.width);
	this->m_pBGSprite->setScaleY((winSize.height + 10.0) / this->m_pBGSprite->m_obRect.height);
	this->m_pBGSprite->setPosition({ -5, -5 });
	this->m_pBGSprite->setColor({ 100, 0, 75 });

	auto backBtn = CCMenuItemSpriteExtra::create(cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"), nullptr, this, menu_selector(KeysLayer::onBack));
	backBtn->setSizeMult(1.6);
	auto backMenu = cocos2d::CCMenu::create(backBtn);
	this->addChild(backMenu, 1);
	auto director = cocos2d::CCDirector::sharedDirector();
	backMenu->setPosition({ director->getScreenLeft() + 24, director->getScreenTop() - 23 });

	if (PlatformToolbox::isControllerConnected())
		GameToolbox::addBackButton(this, backBtn);

	this->m_pKeysLabel = cocos2d::CCLabelBMFont::create(
		cocos2d::CCString::createWithFormat("%i", GameStatsManager::sharedState()->getStat("21"))->getCString(), // keys
		"bigFont.fnt"
	);
	this->m_pKeysLabel->setPosition({ winSize.width - 55, winSize.height - 18 });
	this->m_pKeysLabel->setAnchorPoint({ 1, 0.5 });
	this->m_pKeysLabel->setScale(0.6);
	this->addChild(this->m_pKeysLabel);

	auto keySpr = cocos2d::CCSprite::createWithSpriteFrameName("GJ_bigKey_001.png");
	this->addChild(keySpr, 3);
	keySpr->setPosition(this->m_pKeysLabel->getPosition() + ccp(25.0, -0.5));

	auto titleSpr = cocos2d::CCSprite::createWithSpriteFrameName("treasureRoomLabel_001.png");
	this->addChild(titleSpr, 2);
	titleSpr->setPosition({ winSize.width / 2.0, winSize.height - 42 });

	this->m_pSomeDict = cocos2d::CCDictionary::create();
	this->m_pSomeDict->retain();

	auto someMenu = cocos2d::CCMenu::create();
	this->addChild(someMenu);
	auto coords = someMenu->convertToNodeSpace({ winSize.width * 0.5, (winSize.height * 0.5) + 55 });

	auto someArray = cocos2d::CCArray::create();
	auto someDict = cocos2d::CCDictionary::create();
	for (int i = 1; i < 201; i++) { // 200 total chests
		GJRewardItem* chest = GameStatsManager::sharedState()->m_pOpenedTreasureChestsDict->objectForKey(cocos2d::CCString::createWithFormat("%i", i)->getCString());
		if (chest) {
			// todo
		}
	}
}