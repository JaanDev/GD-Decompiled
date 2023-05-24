#include "../../headers/includes.h"

AchievementCell::AchievementCell(char const* title, float width, float height) {
	TableViewCell::TableViewCell(title, width, height);
	//
	this->init();
}

void AchievementCell::draw() {
	cocos2d::ccDrawColor4B(0, 0, 0, 75);
	glLineWidth(2.0);
	cocos2d::ccDrawLine({ 1.0, this->m_fHeight }, { this->m_fWidth - 1.0, this->m_fHeight });
	cocos2d::ccDrawLine({ 1.0, 0.0 }, { this->m_fWidth - 1.0, 0.0 });
}

bool AchievementCell::init() {
	return true;
}

void AchievementCell::updateBGColor(int index) {
	if (index % 2 != 0) { // if index is odd
		this->m_pCCLayerColor->setColor({ 0xC2, 0x72, 0x3E });
	}
	else { // if index is even
		this->m_pCCLayerColor->setColor({ 0xA1, 0x58, 0x2C });
	}
}

void AchievementCell::loadFromDict(cocos2d::CCDictionary* dict) {
	this->m_pCCLayerColor->setOpacity(255);
	this->m_pCCLayer->removeAllChildrenWithCleanup(true);

	const char* id = dict->objectForKey("identifier")->getCString();
	bool earned = AchievementManager::sharedState()->isAchievementEarned(id);

	if (!dict->objectForKey("icon"))
		//
}