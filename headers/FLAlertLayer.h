#include <includes.h>

class FLAlertLayer : public cocos2d::CCLayerColor {
	void onEnter();
	void keyDown(cocos2d::enumKeyCodes key);
	void registerWithTouchDispatcher();
	void keyBackClicked();
};