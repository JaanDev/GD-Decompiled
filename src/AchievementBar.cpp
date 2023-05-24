#include "../headers/AchievementBar.h"

void AchievementBar::setOpacity(unsigned char opacity) {
	this->m_pSquareSprite->setOpacity(opacity);
	this->m_pIcon->setOpacity(opacity);
	this->m_pAchTitle->setOpacity(opacity);
	this->m_pAchDesc->setOpacity(opacity);
}

void AchievementBar::show() {
	auto scene = cocos2d::CCDirector::sharedDirector()->m_pRunningScene;

	if (this->m_pScene)
		scene = this->m_pScene;

	int zOrder;
	if (scene->getHighestChildZ() >= 1000)
		zOrder = scene->getHighestChildZ() + 1;
	else
		zOrder = 1000;
	scene->addChild(this, zOrder);
	
	this->m_pBarLayer->setScale(1.2);
	this->m_pBarLayer->runAction(cocos2d::CCEaseInOut::create(cocos2d::CCScaleTo::create(0.4, 1.0), 2.0));
	auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
	this->m_pBarLayer->setPosition({ winSize.width * 0.5, winSize.height - 48.0 });
	this->m_pBarLayer->runAction(cocos2d::CCSequence::create(
		cocos2d::CCDelayTime::create(3.2),
		cocos2d::CCCallFunc::create(AchievementNotifier::sharedState(), AchievementNotifier::achievementDisplayFinished)
	));

	this->runAction(cocos2d::CCSequence::create(
		cocos2d::CCDelayTime::create(2.4),
		cocos2d::CCEaseIn::create(cocos2d::CCFadeOut::create(0.8), 2.0)
	));

	this->m_pIconBG->setOpacity(255);
	this->m_pIconBG->runAction(cocos2d::CCEaseInOut::create(cocos2d::CCFadeOut::create(0.9), 1.8));

	this->m_pAchGlow->runAction(cocos2d::CCSequence::create(
		cocos2d::CCEaseInOut::create(cocos2d::CCFadeIn::create(0.35), 2.0),
		cocos2d::CCDelayTime::create(0.5),
		cocos2d::CCEaseInOut::create(cocos2d::CCFadeOut::create(2.4), 2.0)
	));
}

bool AchievementBar::init(const char* title, const char* desc, const char* iconSprite, bool quest) {
	if (!cocos2d::CCNodeRGBA::init())
		return false;

	float v50;

	auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

	auto barLayer = cocos2d::CCLayerColor::create({ 0, 0, 0, 0 }, 0, 0);
	this->m_pBarLayer = barLayer;
	this->addChild(barLayer);
	barLayer->setPosition({ winSize.width * 0.5, 40 });

	const char* bgSpr;
	if (quest)
		bgSpr = "GJ_square02.png";
	else
		bgSpr = "GJ_square01.png";

	auto squareSprite = cocos2d::extension::CCScale9Sprite::create(bgSpr, { 0.0, 0.0, 80.0, 80.0 });
	squareSprite->setContentSize({ 300.0, 80.0 });
	this->m_pBarLayer->addChild(squareSprite, 1);
	this->m_pSquareSprite = squareSprite;

	auto achGlow = cocos2d::CCSprite::createWithSpriteFrameName("achievementGlow_001.png");
	this->m_pAchGlow = achGlow;
	achGlow->setScale(4);
	this->m_pBarLayer->addChild(this->m_pAchGlow, -1);
	this->m_pAchGlow->setBlendFunc({ 770, 1 });

	auto iconBG = cocos2d::extension::CCScale9Sprite::create("square02b_001.png", { 0.0, 0.0, 80.0, 80.0 });
	iconBG->setContentSize({ 300.0, 80.0 });
	this->m_pBarLayer->addChild(iconBG, 100);
	iconBG->setPosition(squareSprite->getPosition());
	iconBG->setOpacity(0);
	iconBG->setBlendAdditive(true);
	this->m_pIconBG = iconBG;

	auto playerIcon = cocos2d::CCSprite::createWithSpriteFrameName("playerSquare_001.png");

	if (quest) {
		auto icon = cocos2d::CCSprite::createWithSpriteFrameName(iconSprite);
		icon->setScale(30.0 / icon->getContentSize().width);
		v50 = 0.0;
		if (icon) {
			icon->setPosition({ 40, 40 });
			this->m_pBarLayer->addChild(icon, 3);
			this->m_pIcon = icon;

			auto node = cocos2d::CCNode::create();
			this->m_pBarLayer->addChild(node, 2);

			float fontScale;
			const char* fntName;
			if (quest) {
				fontScale = 0.8;
				fntName = "goldFont.fnt";
			}
			else {
				fontScale = 0.7;
				fntName = "bigFont.fnt";
			}

			auto titleLabel = cocos2d::CCLabelBMFont::create(title, fntName);
			node->addChild(titleLabel);
			titleLabel->setAnchorPoint({ 0.0, 0.5 });
			titleLabel->setScale(fontScale);
			this->m_pAchTitle = titleLabel;
			if (titleLabel->getContentSize().width > 200.0) {
				titleLabel->setScale(200.0 / titleLabel->getContentSize().width);
			}

			if (fontScale > titleLabel->getScale())
				fontScale = titleLabel->getScale();

			titleLabel->setScale(fontScale);

			auto descText = TextArea::create(desc, "chatFont.fnt", 1.0, 200.0, { 0.0, 20.0 }, 0.0, false); // anchor point is weird lol
			node->addChild(descText);
			descText->setAnchorPoint({ 0.0, 0.5 });
			descText->setPosition({ 0.0, 5.0 });
			*(descText + 126) = 16.0; // dword1F8
			this->m_pAchDesc = descText;

			auto titleLblHeight = titleLabel->getContentSize().height;
			auto descHeight = descText->getContentSize().height;

			titleLabel->setPosition({ 0.0, (((((titleLblHeight + (descHeight + 17.0)) * 0.5) - (titleLblHeight * 0.5)) + 1) + 2.0) + (quest ? 2.5 : 0.0) }); // simplified: 0.5 * descHeight + (quest ? 2.5 : 0.0) + 11.5
			descText->setPosition({ 1.0, ((15.0 - (((titleLblHeight + (descHeight + 17.0)) * 0.5) - ((descHeight + 17.0) * 0.5))) - 1.0) - 1.0 }); // simplified: -0.5 * titleLblHeight + 13.0

			playerIcon->setScale(1.0);
			if (!quest)
				icon->setScale(1.0);

			float v79; // no idea how to name it
			if ((titleLabel->getContentSize().width * titleLabel->getScale()) >= descText->m_fContentSizeScaleMod) {
				v79 = titleLabel->getContentSize().width * titleLabel->getScale() + 5.0;
			}
			else {
				v79 = descText->m_fContentSizeScaleMod + 5.0;
			}

			icon->setPosition({ ((playerIcon->m_obRect.width * playerIcon()->getScale()) * 0.5) - (((((playerIcon->m_obRect.width * playerIcon()->getScale()) * 0.5) + v79) + 30.0) * 0.5), v50 }); // simplified: 0.25 * playerIcon->m_obRect.width * playerIcon()->getScale() - 0.5 * v79 - 15.0
			node->setPosition({ icon->getPosition().y + 30.0, 0.0 });
			this->m_fUnk = 86.0;

			return true;
		}
	}

	if (!iconSprite) {
		v50 = 0.0;

	}

	return true;

	// sorry, but i have 0 idea how to decompile this func
	// the above is probably not accurate
	// it has a million of "goto ..." in ida decomp
	// if anyone knows what to do with them, please tell Jaan#2897 (me)
}