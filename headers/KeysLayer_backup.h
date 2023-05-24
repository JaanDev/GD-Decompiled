#include "includes.h"

class KeysLayer : public cocos2d::CCLayer {
	cocos2d::CCAction* dialogClosed(DialogLayer*);
	GJRewardItem* onSelectItem(cocos2d::CCObject*);
	int onSwitchPage(cocos2d::CCObject*);
	_DWORD* onSpecialItem(cocos2d::CCObject*);
	signed int keyBackClicked();
	int FLAlert_Clicked(FLAlertLayer*, bool);
	int switchToOpenedState(CCMenuItemSpriteExtra*);
	int updateUnlockedLabel();
	signed int init();
	AppDelegate* scene();
	cocos2d::CCLayer* create();
	signed int onBack(cocos2d::CCObject*);
	cocos2d::CCAction* onShop(cocos2d::CCObject*);
	cocos2d::CCAction* onShop3(cocos2d::CCObject*);
	int goToPage(int);
	KeysLayer * ~KeysLayer();
	virtual KeysLayer * ~KeysLayer();
	virtual signed int init(void);
	virtual signed int keyBackClicked(void);
	virtual int FLAlert_Clicked(FLAlertLayer*, bool);
	virtual cocos2d::CCAction* dialogClosed(DialogLayer*);
};