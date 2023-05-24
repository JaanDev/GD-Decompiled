#include "includes.h"

//class AchievementBar : public cocos2d::CCNodeRGBA
//{
//	cocos2d::CCLayerColor* m_pBarLayer;
//	float m_fUnk;
//	cocos2d::CCScene* m_pScene;
//	cocos2d::extension::CCScale9Sprite* m_pSquareSprite;
//	cocos2d::extension::CCScale9Sprite* m_pIconBG;
//	cocos2d::CCSprite* m_pAchievementGlow;
//	cocos2d::CCSprite* m_pIcon;
//	cocos2d::CCLabelBMFont* m_pAchievementTitle;
//	TextArea* m_pAchievementDescription;
//};

class AchievementBar : cocos2d::CCNodeRGBA
{
public:
	void setOpacity(unsigned char opacity);
	void show();
	bool init(const char* title, const char* desc, const char* iconSprite, bool quest);

	cocos2d::CCLayerColor* m_pBarLayer;
	float m_fUnk;
	cocos2d::CCScene* m_pScene;
	cocos2d::extension::CCScale9Sprite* m_pSquareSprite;
	cocos2d::extension::CCScale9Sprite* m_pIconBG;
	cocos2d::CCSprite* m_pAchGlow;
	cocos2d::CCSprite* m_pIcon;
	cocos2d::CCLabelBMFont* m_pAchTitle;
	TextArea* m_pAchDesc;
};