#include <includes.h>

void PlayerObject::playBurstEffect() {
	if (!this->levelFlipping()) {
		if (!this->m_bIsHidden) {
			this->m_pBurstEffect->resumeSystem();
			this->stopActionByTag(6);
			auto seq = cocos2d::CCSequence::create(cocos2d::CCDelayTime::create(0.12), cocos2d::CCCallFunc::create(this, PlayerObject::stopBurstEffect));
			seq->setTag(6);
			this->runAction(seq);
		}
	}
}