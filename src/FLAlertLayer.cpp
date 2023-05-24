#include <FLAlertLayer.h>

void FLAlertLayer::onEnter() {
	auto director = cocos2d::CCDirector::sharedDirector();
	director->getTouchDispatcher()->m_bForcePrio = true;
	this->onEnter();
}

void FLAlertLayer::keyDown(cocos2d::enumKeyCodes key) {
	if (key == cocos2d::KEY_Space) {
		if (!this->m_bNoBtn2)
			return;
		this->onBtn2(nullptr);
		return;
	}
	if (key == cocos2d::CONTROLLER_X) {
		//uhm
		this->onBtn2(nullptr);
		return;
	}

	this->keyDown(key);
}

void FLAlertLayer::registerWithTouchDispatcher() {
	auto director = cocos2d::CCDirector::sharedDirector();
	auto dispatcher = director->getTouchDispatcher();

	int prio = -501;
	if (dispatcher->m_bForcePrio)
		prio = dispatcher->m_nPrio - 1;

	dispatcher->addTargetedDelegate(this, prio, true);
}

void FLAlertLayer::keyBackClicked() {
	this->setKeypadEnabled(false);
	this->setKeyboardEnabled(false);

	if (this->m_bReverseKeyBack)
		this->onBtn2(nullptr);
	else
		this->onBtn1(nullptr);
}