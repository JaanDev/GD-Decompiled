#include "includes.h"

enum class MenuAnimationType {
    kMenuAnimationTypeScale = 0x0,
    kMenuAnimationTypeMove = 0x1,
};

class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite {
    CCMenuItemSpriteExtra()
        : m_bUnk(false), m_colorMode(false), m_activateSound(""), m_selectedSound(""), m_pressedScale(0.f), m_multiplier(1.f), m_fUnk2(1.f),
          m_fUnk3(.78431f), m_moveOffset({0, 0}), m_selectAnimDuration(.3f), m_unselectAnimDuration(.4f),
          m_type(MenuAnimationType::kMenuAnimationTypeScale), m_startPoint({0, 0}) {}

    void activate();
    static CCMenuItemSpriteExtra* create(cocos2d::CCNode* normalSprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target,
                                         SEL_MenuHandler selector);
    bool init(cocos2d::CCNode* normalSprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, SEL_MenuHandler selector);
    void selected();
    void setSizeMult(float sizeMult);
    void unselected();
    void useAnimationType(MenuAnimationType type);

    float m_multiplier;
    float m_pressedScale;
    bool m_bUnk;
    bool m_colorMode; // ??? what
    PAD(2) // a padding to align with 0x4
    float m_fUnk2; // has to do with sounds
    std::string m_activateSound;
    std::string m_selectedSound;
    float m_fUnk3; // idk color thing
    cocos2d::CCPoint m_moveOffset;
    float m_selectAnimDuration;
    float m_unselectAnimDuration;
    MenuAnimationType m_type;
    cocos2d::CCPoint m_startPoint;
};