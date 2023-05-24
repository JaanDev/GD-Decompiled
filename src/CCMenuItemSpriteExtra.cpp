#include "../headers/includes.h"
#include "CCMenuItemSpriteExtra.h"

using namespace cocos2d;

void CCMenuItemSpriteExtra::activate() {
    if (m_bEnabled) {
        this->stopAllActions();

        if (m_type == MenuAnimationType::kMenuAnimationTypeScale)
            this->setScale(m_pressedScale);

        if (m_activateSound.length() > 0) // *(this->m_activateSound - 12)
            GameSoundManager::sharedManager()->playEffect(m_activateSound, 1.f, 0.f, m_fUnk2);

        CCMenuItem::activate();
    }
}

CCMenuItemSpriteExtra* CCMenuItemSpriteExtra::create(CCNode* normalSprite, CCNode* selectedSprite, CCObject* target,
                                                     SEL_MenuHandler selector) {
    CREATE_FUNC_BODY(CCMenuItemSpriteExtra, normalSprite, selectedSprite, target, selector)
}

bool CCMenuItemSpriteExtra::init(CCNode* normalSprite, CCNode* selectedSprite, CCObject* target, SEL_MenuHandler selector) {
    if (!CCMenuItemSprite::initWithNormalSprite(normalSprite, selectedSprite, nullptr, target, selector))
        return false;

    m_pressedScale = 1.f;
    normalSprite->setAnchorPoint({.5f, .5f});

    // getScaledContentSize was invented in the 22nd century
    // people before:
    auto sprSize = normalSprite->getContentSize();
    this->setContentSize({sprSize.width * normalSprite->getScaleX(), sprSize.height * normalSprite->getScaleY()});

    normalSprite->setPosition(
        normalSprite->getParent()->convertToNodeSpace({0, 0})); // eeh CCNode::convertToNodeSpace(&v19, v15, &unk_75765C);

    m_bUnk = true;
    m_multiplier = 1.26f;

    return true;
}

void CCMenuItemSpriteExtra::selected() {
    if (isEnabled()) {
        CCMenuItemSprite::selected();

        if (m_selectedSound.length() > 0) // *(this->m_selectedSound - 12)
            GameSoundManager::sharedManager()->playEffect(m_selectedSound, 1.f, 0.f, m_fUnk2);

        if (m_colorMode) {
            auto val = static_cast<uint8_t>(m_fUnk3 * 255.f);
            reinterpret_cast<CCSprite*>(getNormalImage())->setColor({val, val, val});
        }

        if (m_bUnk) {
            if (m_type == MenuAnimationType::kMenuAnimationTypeMove) {
                getNormalImage()->stopActionByTag(0);
                auto action = CCEaseInOut::create(CCMoveTo::create(m_selectAnimDuration, m_startPoint + m_moveOffset), 1.5f);
                action->setTag(0);
                getNormalImage()->runAction(action);
            } else if (m_type == MenuAnimationType::kMenuAnimationTypeScale) {
                this->stopActionByTag(0);
                auto action = CCEaseBounceOut::create(CCScaleTo::create(m_selectAnimDuration, m_pressedScale * m_multiplier));
                action->setTag(0);
                runAction(action);
            } else {
                return; // /shrug
            }
        }
    }
}

void CCMenuItemSpriteExtra::setSizeMult(float sizeMult) {
    auto img = getNormalImage();

    if (img) {
        auto initialSize = img->getContentSize();

        auto size = img->getContentSize();
        CCSize newSize = {size.width * img->getScaleX() * sizeMult, size.height * img->getScaleY() * sizeMult};
        this->setContentSize(newSize);

        CCSize sizeDiff = {newSize.width - initialSize.width, newSize.height - initialSize.height};
        img->setPosition(img->getPosition() + sizeDiff / 2.f);
    }
}

void CCMenuItemSpriteExtra::unselected() {
    if (isEnabled()) {
        CCMenuItemSprite::unselected();

        if (m_colorMode)
            reinterpret_cast<CCSprite*>(getNormalImage())->setColor({255, 255, 255});

        if (m_bUnk) {
            if (m_type == MenuAnimationType::kMenuAnimationTypeMove) {
                auto img = getNormalImage();
                img->stopActionByTag(0);
                auto action = CCEaseInOut::create(CCMoveTo::create(m_unselectAnimDuration, m_startPoint), 2.f);
                action->setTag(0);
                img->runAction(action);
            } else if (m_type == MenuAnimationType::kMenuAnimationTypeScale) {
                stopActionByTag(0);
                auto action = CCEaseBackOut::create(CCScaleTo::create(m_unselectAnimDuration, m_pressedScale));
                action->setTag(0);
                runAction(action);
            }
        }
    }
}

void CCMenuItemSpriteExtra::useAnimationType(MenuAnimationType type) {
    m_startPoint = getNormalImage()->getPosition();
    m_type = type;
}
