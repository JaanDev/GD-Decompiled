#include <includes.h>

class TextAreaDelegate {};
class TextArea : public cocos2d::CCSprite {};

enum DialogAnimationType {
	scale = 1,
	fromLeft = 2,
	fromRight = 3,
	fromTop = 4,
	fromBottom = 5
};

enum DialogChatPlacement {
	center = 0,
	top = 1,
	bottom = 2
};

class DialogLayer : public cocos2d::CCLayerColor, public TextAreaDelegate
{
public:
	DialogLayer();
	~DialogLayer();

	void displayNextObject();
	void animateIn(DialogAnimationType type);
	void animateInDialog();
	void animateInRandomSide();
	void updateNavButtonFrame();
	void updateChatPlacement(DialogChatPlacement placement);
	void displayDialogObject(DialogObject* obj);
	void registerWithTouchDispatcher();
	void onEnter();
	void onClose();
	void keyDown(cocos2d::enumKeyCodes code);
	void keyBackClicked() { this->onClose(); }
	void handleDialogTap();
	void finishCurrentAnimation();
	void fadeInTextFinished(TextArea* textArea);

	bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent*);
	void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent*);
	void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent*);
	void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent*) {};

	bool init(DialogObject* dialogObject, cocos2d::CCArray* dialogObjects, int bgSpriteType);
	DialogLayer* create(DialogObject* dialogObject, int bgSpriteType);
	DialogLayer* createDialogLayer(DialogObject* dialogObject, cocos2d::CCArray* dialogObjects, int bgSpriteType);
	DialogLayer* createWithObjects(cocos2d::CCArray* dialogObjects, int bgSpriteType);

	DWORD dword198;
	float m_fTime;
	cocos2d::CCLayer* m_pLayer;
	cocos2d::CCLabelBMFont* m_pTitle;
	TextArea* m_pDialog;
	cocos2d::CCSprite* m_pIcon;
	cocos2d::CCArray* m_pDialogObjects; // DialogObject*
	int m_iTouchID;
	cocos2d::CCSprite* m_pChatBtn;
	bool m_bTextFading;
	bool m_bCanSkip;
	DialogDelegate* m_pDialogDelegate;
	bool m_bAlwaysAcceptInput;  // i have really no clue about this one, it's only used in 1 function(handleDialogTap)
								// and in the constructor which means its always 0. maybe it was left after rob's debugging who knows
	DialogAnimationType m_eAnimationType;
};