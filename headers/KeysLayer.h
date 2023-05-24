#include <includes.h>

using cocos2d::SEL_MenuHandler;

class FLAlertLayerProtocol {};
class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite {};

class KeysLayer : public cocos2d::CCLayer, public FLAlertLayerProtocol, public DialogDelegate {
	void dialogClosed(DialogLayer* dialog);
	void onShop(cocos2d::CCObject* pObj);
	void onSpecialItem(cocos2d::CCObject* pObj);
	void updateUnlockedLabel();
	void goToPage(int page);
	void onBack(cocos2d::CCObject* pObj);
	void keyBackClicked();
	void onSelectItem(cocos2d::CCObject* pObj);
	void onSwitchPage(cocos2d::CCObject* pObj);
	bool init();

public:
	DWORD dword11C;
	DWORD dword120;
	cocos2d::CCLabelBMFont* m_pOpenedChestsLabel;
	cocos2d::CCLabelBMFont* m_pKeysLabel;
	DWORD dword12C;
	cocos2d::CCDictionary* m_pSomeDict;
	CCMenuItemSpriteExtra* m_pSwitchPageBtn;
	CCMenuItemSpriteExtra* m_pSwitchPageBtn2;
	DWORD dword13C;
	BoomScrollLayer* m_pScrollLayer;
	cocos2d::CCSprite* m_pBGSprite;
	int m_iScratchDialogViewedCount;
};