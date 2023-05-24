#include <includes.h>

class GauntletSelectLayer : cocos2d::CCLayer {
	void updateArrows();
	void scrollLayerWillScrollToPage(BoomScrollLayer* layer, int page);
	void scrollLayerScrolledToPage(BoomScrollLayer* layer, int page);
	void onRefresh(cocos2d::CCObject* pObj);
	void keyBackClicked();
	void loadLevelsFailed(const char*);

	DWORD dword11C;
	DWORD dword120;
	cocos2d::CCSprite* m_pBGSprite;
	BoomScrollLayer* m_pScrollLayer;
	CCMenuItemSpriteExtra* m_pPrevBtn;
	CCMenuItemSpriteExtra* m_pNextBtn;
	CCMenuItemSpriteExtra* m_pRefreshBtn;
	BYTE byte138;
	BYTE byte139;
	TextArea* m_pWentWrongText;
	LoadingCircle* m_pLoadingCircle;
	cocos2d::CCDictionary* m_pSomeDict;
};