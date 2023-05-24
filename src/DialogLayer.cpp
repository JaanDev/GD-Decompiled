#include "../headers/Layers/DialogLayer.h"

void DialogLayer::displayNextObject() {
	if (this->m_pDialogObjects->count()) {
		this->displayDialogObject(this->m_pDialogObjects->objectAtIndex(0));
		this->m_pDialogObjects->removeObjectAtIndex(0);
		this->updateNavButtonFrame();
	}
}

void DialogLayer::animateIn(DialogAnimationType type) {
	this->setVisible(true);
	
	struct timespec t;
	clock_gettime(0, &t);
	this->m_fTime = t.tv_nsec / 1000000000.0;

	if (type < 1 || type > 5) {
		auto opacity = this->getOpacity();
		if (opacity > 0) {
			this->setOpacity(0);
			this->runAction(cocos2d::CCFadeTo::create(0.14, opacity));
		}
	}

	auto layerPos = this->m_pLayer->getPosition();
	switch (type) {
	case scale:
		this->m_pLayer->setScale(0.1);
		auto action = cocos2d::CCScaleTo::create(0.5, 1.0);
		this->m_pLayer->runAction(cocos2d::CCEaseElasticOut::create(action, 0.6));
		break;
	case fromLeft:
		this->m_pLayer->setPosition( { -191, layerPos.y } );
		auto action = cocos2d::CCMoveTo::create(0.5, layerPos);
		this->m_pLayer->runAction(cocos2d::CCEaseElasticOut::create(action, 0.6));
		break;
	case fromRight:
		this->m_pLayer->setPosition({ cocos2d::CCDirector::sharedDirector()->getScreenRight() + 191, layerPos.y });
		auto action = cocos2d::CCMoveTo::create(0.5, layerPos);
		this->m_pLayer->runAction(cocos2d::CCEaseElasticOut::create(action, 0.6));
		break;
	case fromTop:
		this->m_pLayer->setPosition( { layerPos.x, cocos2d::CCDirector::sharedDirector()->getScreenTop() + 51 } );
		auto action = cocos2d::CCMoveTo::create(0.5, layerPos);
		this->m_pLayer->runAction(cocos2d::CCEaseElasticOut::create(action, 0.6));
		break;
	case fromBottom:
		this->m_pLayer->setPosition({ layerPos.x, cocos2d::CCDirector::sharedDirector()->getScreenTop() - 51 });
		auto action = cocos2d::CCMoveTo::create(0.5, layerPos);
		this->m_pLayer->runAction(cocos2d::CCEaseElasticOut::create(action, 0.6));
		break;
	}
}

void DialogLayer::animateInDialog() {
	this->animateIn(this->m_eAnimationType);
}

void DialogLayer::animateInRandomSide() {
	// raw code if someone needs it
	//v2 = lrand48() * 4.6566e-10;
	//if (v2 <= 0.66)
	//{
	//	v3 = this;
	//	if (v2 <= 0.33)
	//		v4 = scale;
	//	else
	//		v4 = fromRight;
	//}
	//else
	//{
	//	v3 = this;
	//	v4 = fromLeft;
	//}

	// i'll prettify it a bit
	DialogAnimationType animType;
	switch (rand() % 3 + 1) {
	case 1:
		animType = DialogAnimationType::scale;
		break;
	case 2:
		animType = DialogAnimationType::fromRight;
		break;
	case 3:
		animType = DialogAnimationType::fromLeft;
		break;
	}
	this->animateIn(animType);
}

void DialogLayer::updateNavButtonFrame() {
	if (this->m_pDialogObjects && this->m_pDialogObjects->count()) {
		this->m_pChatBtn->setDisplayFrame(cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("GJ_chatBtn_01_001.png"));
	}
	else {
		this->m_pChatBtn->setDisplayFrame(cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("GJ_chatBtn_02_001.png"));
	}
}

void DialogLayer::updateChatPlacement(DialogChatPlacement placement) {
	auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

	switch (placement) {
	case center:
		this->m_pLayer->setPosition(winSize / 2.0);
		break;
	case top:
		this->m_pLayer->setPosition( { winSize.width / 2.0, winSize.height - 70.0 } );
		break;
	case bottom:
		this->m_pLayer->setPosition( { winSize.width / 2.0, 70.0 } );
		break;
	}
}

void DialogLayer::displayDialogObject(DialogObject* obj) {
	if (obj) {
		this->m_bTextFading = true;
		this->m_bCanSkip = obj->m_bCanSkip;

		this->m_pChatBtn->stopAllActions();
		this->m_pChatBtn->setOpacity(0);

		if (this->m_pIcon) {
			this->m_pIcon->removeMeAndCleanup();
			this->m_pIcon = nullptr;
		}

		if (this->m_pDialog) {
			//*(m_pDialog + 137) = 0;
			//m_pDialog->m_fScaleX = 0; // not sure at all bc there is *(this->m_pDialog + 137) = &this->dword198; later in the code
			//nvm
			//if i set it to CCSprite* => m_pDialog[1].m_fSkewY = 0.0;
			this->m_pDialog->removeMeAndCleanup();
			this->m_pDialog = nullptr;
		}

		this->m_pTitle->setString("");
		this->m_pTitle->setColor(obj->m_pColour);

		int dialogType = obj->m_nDialogType;
		if (dialogType > 0) {
			if (dialogType >= 18)
				dialogType = 18;

			this->m_pIcon = cocos2d::CCSprite::create(
				cocos2d::CCString::createWithFormat("dialogIcon_%03d.png", dialogType)->getCString()
			);

			this->m_pLayer->addChild(this->m_pIcon, 2);
			this->m_pIcon->setPosition( { -143, 0 } );
		}

		this->m_pDialog = TextArea::create(obj->m_sText, "chatFont.fnt", 1.0, 220.0 / obj->m_fTextWidth, { 0.0, 1.0 }, 0.0, false); // not sure about the anchor
		this->m_pDialog->setAnchorPoint( { 0.0, 0.5 } );
		this->m_pDialog->setScale(obj->m_fTextWidth);
		//*(this->m_pDialog + 137) = &this->dword198;
		this->m_pLayer->addChild(this->m_pDialog, 3);
		this->m_pDialog->setPosition( { -92, 0 } );
		this->m_pDialog->fadeInCharacters(0.2, 0.02);
	}
}

void DialogLayer::registerWithTouchDispatcher() {
	auto dispatcher = cocos2d::CCDirector::sharedDirector()->getTouchDispatcher();
	int priority = -501;

	if (dispatcher->m_bForcePrio)
		priority = dispatcher->m_nTargetPrio - 1;

	dispatcher->addTargetedDelegate(this, priority, true);
}

void DialogLayer::onEnter() {
	cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->m_bForcePrio = true;
	return this->onEnter();
}

void DialogLayer::onClose() {
	if (this->m_pDialogDelegate)
		this->m_pDialogDelegate->dialogCLosed(this);

	if (this->m_pDialog) {
		//*(v3 + 137) = 0; // again scaleX?? what
	}

	this->setKeypadEnabled(false);
	this->setKeyboardEnabled(false);
	this->removeFromParentAndCleanup(true);
}

void DialogLayer::keyDown(cocos2d::enumKeyCodes code) {
	if (
		code == cocos2d::KEY_Up
	 || code == cocos2d::CONTROLLER_A
	 || code == cocos2d::CONTROLLER_LB
	 || code == cocos2d::CONTROLLER_RB
	 || code == cocos2d::KEY_Escape
	 || code == cocos2d::KEY_Space
		)
	{ this->handleDialogTap(); }
}

void DialogLayer::handleDialogTap() {
	struct timespec t;
	clock_gettime(0, &t);

	float timeDiff = t.tv_nsec / 1000000000.0 - this->m_fTime;
	if (this->m_fTime <= 0.0 || timeDiff >= 0.8 || this->m_bAlwaysAcceptInput || timeDiff <= 0.0) {
		if (this->m_bTextFading && !this->m_bCanSkip) {
			this->finishCurrentAnimation();
		}
		else {
			if (this->m_pDialogObjects && this->m_pDialogObjects->count())
				this->displayNextObject();
			else
				this->onClose();
		}
	}
}

void DialogLayer::finishCurrentAnimation() {
	this->m_bTextFading = false;

	if (this->m_pDialog) {
		//*(v1 + 137) = 0; // here too
		this->m_pDialog->stopAllCharacterActions();
		this->m_pDialog->showAll();
	}

	this->m_pChatBtn->stopAllActions();
	this->m_pChatBtn->setOpacity(255);
	this->updateNavButtonFrame();
}

void DialogLayer::fadeInTextFinished(TextArea* textArea) {
	this->m_bTextFading = false;

	this->m_pChatBtn->stopAllActions();
	this->m_pChatBtn->setOpacity(0);

	float d = 0;
	if (this->m_pDialogObjects) {
		if (!this->m_pDialogObjects->count())
			d = 0.5;
		else
			d = 0.3;
	}
	else
		d = 0.5;

	this->m_pChatBtn->runAction(cocos2d::CCFadeIn::create(d));
}

bool DialogLayer::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent*) {
	if (this->m_iTouchID == -1) {
		this->m_iTouchID = touch->m_uID;
		this->handleDialogTap();
	}

	return true;
}

void DialogLayer::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* e) {
	if (this->m_iTouchID == touch->m_uID)
		this->ccTouchEnded(touch, e);
}

void DialogLayer::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent*) {
	if (this->m_iTouchID == touch->m_uID)
		this->m_iTouchID = -1;
}

bool DialogLayer::init(DialogObject* dialogObject, cocos2d::CCArray* dialogObjects, int bgSpriteType) {
	if (this->initWithColor({ 0, 0, 0, 150 })) {
		if (dialogObjects) {
			this->m_pDialogObjects = dialogObjects;
			dialogObjects->retain();
		}

		auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

		cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->incrementForcePrio(2);

		this->setTouchEnabled(true);
		this->setKeypadEnabled(true);
		this->setKeyboardEnabled(true);

		this->m_pLayer = cocos2d::CCLayer::create();
		this->addChild(this->m_pLayer);
		this->m_pLayer->setContentSize({ 0, 0 }); // &stru_73B0F0 uhm wtf
		this->m_pLayer->setPosition(winSize * 0.5);

		auto bgTexName = cocos2d::CCString::createWithFormat("GJ_square%02d.png", bgSpriteType)->getCString();
		auto bgSprite = cocos2d::extension::CCScale9Sprite::create(bgTexName, { 0.0, 0.0, 80.0, 80.0 });
		bgSprite->setContentSize({ 380, 100 });
		this->m_pLayer->addChild(bgSprite, -2);

		this->m_pTitle = cocos2d::CCLabelBMFont::create(" ", "bigFont.fnt");
		this->m_pLayer->addChild(this->m_pTitle, 2);
		this->m_pTitle->setAnchorPoint({ 0, 1 });
		this->m_pTitle->setPosition({ -93, 36 });
		this->m_pTitle->limitLabelWidth(200, 0.5, 0);

		auto spr = cocos2d::extension::CCScale9Sprite::create("square02b_001.png", { 0.0, 0.0, 80.0, 80.0 });
		spr->setContentSize({ 280, 80 });
		this->m_pLayer->addChild(spr, -1);
		spr->setPosition({ 40, 0 });
		spr->setColor({ 0, 0, 0 });
		spr->setOpacity(50);

		this->m_pChatBtn = cocos2d::CCSprite::createWithSpriteFrameName("GJ_chatBtn_01_001.png");
		this->m_pLayer->addChild(this->m_pChatBtn, 3);
		this->m_pChatBtn->setPosition({ 0, -50 });
		this->m_pChatBtn->setOpacity(0);

		if (this->m_pDialogObjects)
			this->displayNextObject();
		else
			this->displayDialogObject(dialogObject);

		this->updateNavButtonFrame();

		return true;
	}

	return false;
}

DialogLayer* DialogLayer::create(DialogObject* dialogObject, int bgSpriteType) {
	return DialogLayer::create(dialogObject, nullptr, bgSpriteType);
}

DialogLayer* DialogLayer::createDialogLayer(DialogObject* dialogObject, cocos2d::CCArray* dialogObjects, int bgSpriteType) {
	auto pRet = new DialogLayer();

	if (pRet && pRet->init(dialogObject, dialogObjects, bgSpriteType)) {
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

DialogLayer* DialogLayer::createWithObjects(cocos2d::CCArray* dialogObjects, int bgSpriteType) {
	return DialogLayer::create(nullptr, dialogObjects, bgSpriteType);
}

DialogLayer::DialogLayer() {
	this->m_iTouchID = -1;
	this->m_fTime = 0.0;
	this->m_pTitle = nullptr;
	this->m_pDialog = nullptr;
	this->m_pIcon = nullptr;
	this->m_pDialogObjects = nullptr;
	this->m_bTextFading = false;
	this->m_bCanSkip = false;
	this->m_pDialogDelegate = nullptr;
	this->m_bAlwaysAcceptInput = false;
	this->m_eAnimationType = DialogAnimationType::scale;
}

DialogLayer::~DialogLayer() {
	cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->decrementForcePrio(2);

	//if (this->m_pDialogObjects)
	//	this->m_pDialogObjects->release();
	// not sure if this actually exists in the code but generated after compiling
}