#include "../headers/includes.h"

void GJGroundLayer::showGround() {
	this->m_bShowGround = true;
}

void GJGroundLayer::deactivateGround() {
	this->stopAllActions();
	this->m_bShowGround = false;
}

void GJGroundLayer::hideShadows() {
	auto child1 = this->getChildByTag(0);
	auto child2 = this->getChildByTag(1);

	if (child1)
		child1->setVisible(false);

	if (child2)
		child2->setVisible(false);
}

void GJGroundLayer::fadeInGround(float delay) {
	this->stopActionByTag(3);

	auto action = cocos2d::CCSequence::create(
		cocos2d::CCDelayTime::create(delay),
		cocos2d::CCCallFunc::create(this, GJGroundLayer::fadeInFinished),
		nullptr
	);
	action->setTag(3);
	this->runAction(action);
}

void GJGroundLayer::fadeOutGround() {
	this->m_bShowGround = false;
}

void GJGroundLayer::fadeInFinished() {
	this->m_bShowGround = true;
}

float GJGroundLayer::getGroundY() {
	return this->m_pGround1Sprite->getPosition().y + this->m_fGroundHeight;
}

void GJGroundLayer::updateGroundPos(cocos2d::CCPoint pos) {
	this->m_pGround1Sprite->setPosition(pos);

	auto g2 = this->m_pGround2Sprite;
	if (g2)
		g2->setPosition({ pos.x, 0 });
}

void GJGroundLayer::updateGroundWidth() {
	if (this->getParent()) {
		auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
		
		auto parentScale = this->getParent()->getScale();
		auto idk = ceilf((winSize.width / parentScale + 10.0) / this->m_fGroundWidth) + 1.0;
		this->loadGroundSprites(idk, true);
		this->loadGroundSprites(idk, false);

		if (this->m_nLineType == 2)
			this->m_pLineSprite->setScaleX((winSize.width + 10.0) / parentScale / this->m_pLineSprite->getTextureRect().size.width);

		this->m_pLineSprite->setPosition({ winSize.width / parentScale / 2.0, this->m_pLineSprite->getPosition().y }); // (winSize.width / parentScale + 10.0) * 0.5 - 5.0
	}
}

void GJGroundLayer::updateGround01Color(cocos2d::ccColor3B color) {
	int i = 0;
	auto children = this->m_pGround1Sprite->getChildren();
	while (i < children->count()) {
		children->objectAtIndex(i++)->setColor(color);
	}
}

void GJGroundLayer::updateGround02Color(cocos2d::ccColor3B color) {
	if (this->m_pGround2Sprite) {
		int i = 0;
		auto children = this->m_pGround2Sprite->getChildren();
		while (i < children->count()) {
			children->objectAtIndex(i++)->setColor(color);
		}
	}
}

void GJGroundLayer::positionGround(float height) {
	this->setPosition({ 0.0, height - 90.0 });
}

void GJGroundLayer::updateLineBlend(bool blend) {
	if (this->m_bLineBlend != blend) {
		this->m_bLineBlend = blend;

		cocos2d::ccBlendFunc func;

		if (blend)
			func = { 0x2300, 0x1000 };
		else
			func = { 0x1000, 0x3300 };

		this->m_pLineSprite->setBlendFunc(func);
	}
}

void GJGroundLayer::createLine(int lineType) {
	if (this->m_pLineSprite) {
		this->m_pLineSprite->removeFromParent();
		this->m_pLineSprite = nullptr;
	}

	if (lineType < 1)
		lineType = 1;
	if (lineType >= 2)
		lineType = 2;

	this->m_nLineType = lineType;

	float x = (lineType == 1) ? 0.5 : 0.2;

	auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

	auto line = cocos2d::CCSprite::createWithSpriteFrameName(cocos2d::CCString::createWithFormat("floorLine_%02d_001.png", this->m_nLineType)->getCString());
	this->m_pLineSprite = line;
	this->addChild(line, 5);
	this->m_pLineSprite->setPosition({ winSize.width * 0.5, x + 90.0 });
	this->m_pLineSprite->setAnchorPoint({ 0.5, 1.0 });
	this->m_pLineSprite->setTag(2);

	if (this->m_bLineBlend)
		this->m_pLineSprite->setBlendFunc({ 770, 1 });

	if (this->m_nLineType == 2)
		this->m_pLineSprite->setScaleX((winSize.width + 10.0) / this->m_pLineSprite->getTextureRect().size.width);
}

bool GJGroundLayer::init(int groundID, int lineType) {
	if (cocos2d::CCLayer::init()) {
		auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

		const char* groundName = GameManager::sharedState()->getGTexture(groundID);

		this->m_bLineBlend = true;

		this->createLine(lineType);

		auto shadow1 = cocos2d::CCSprite::createWithSpriteFrameName("groundSquareShadow_001.png");
		shadow1->setAnchorPoint({ 0.0, 1.0 });
		shadow1->setPosition({ cocos2d::CCDirector::sharedDirector()->getScreenLeft() - 1.0, 90.0 });
		this->addChild(shadow1, 6);
		shadow1->setTag(0);

		auto shadow2 = cocos2d::CCSprite::createWithSpriteFrameName("groundSquareShadow_001.png");
		shadow2->setAnchorPoint({ 1.0, 1.0 });
		shadow2->setPosition({ cocos2d::CCDirector::sharedDirector()->getScreenRight() + 1.0, 90.0 });
		this->addChild(shadow2, 6);
		shadow2->setFlipX(true);
		shadow2->setTag(1);

		shadow1->setOpacity(100);
		shadow2->setOpacity(100);

		shadow1->setScaleX(0.7);
		shadow2->setScaleX(0.7);

		shadow1->setBlendFunc({ 774, 771 });
		shadow2->setBlendFunc({ 774, 771 });

		this->m_bShowGround = false;

		auto batch = cocos2d::CCSpriteBatchNode::create(groundName, 29);
		this->addChild(batch, 2);
		auto texSize = batch->getTexture()->getContentSize();
		this->m_fGroundWidth = texSize.width;
		int rename_me = ceil(winSize.width / texSize.width) + 1;
		this->m_fGroundHeight = 128.0 - texSize.height;

		auto g1 = cocos2d::CCSprite::createWithTexture(batch->getTexture(), { 0, 0, texSize.width, texSize.height }); // &unk_73A854 as the 'rect' var so i kinda guessed it
		this->m_pGround1Sprite = g1;
		g1->byte1BB = 1; // no idea cuz ccsprite is broken
		this->m_pGround1Sprite->setPosition({ 0.0, texSize.height - 38.0 });
		this->m_pGround1Sprite->setColor({ 0, 102, 255 });
		batch->addChild(this->m_pGround1Sprite);
		batch->setBlendFunc({ 1, 0 });
		this->loadGroundSprites(rename_me, true);
		this->updateGround01Color({ 0, 102, 255 });

		if (groundID > 7) {
			auto secondGTex = cocos2d::CCString::createWithFormat("groundSquare_%02d_2_001.png", groundID)->getCString();
			auto batch2 = cocos2d::CCSpriteBatchNode::create(secondGTex, 29);
			this->addChild(batch2, 3);
			auto g2Sprite = cocos2d::CCSprite::createWithTexture(batch2->getTexture(), &stru_73A854); // idk here honestly
			this->m_pGround2Sprite = g2Sprite;
			g2Sprite->byte1BB = 1;
			this->m_pGround2Sprite->setPosition({ 0, texSize.height - 38.0 });
			this->m_pGround2Sprite->setColor({ 0, 102, 255 });
			batch2->addChild(this->m_pGround2Sprite);
			this->loadGroundSprites(rename_me, false);
			this->updateGround01Color({ 0, 102, 255 });
		}

		return true;
	}
	
	return false;
}