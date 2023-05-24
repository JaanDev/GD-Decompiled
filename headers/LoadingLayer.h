#pragma once
#include <includes.h>

class LoadingLayer : public cocos2d::CCLayer {
public:
	const char* getLoadingString();
	bool init(bool fromReload);
	void loadAssets();
	void loadingFinished();
	static cocos2d::CCScene* scene(bool fromReload);
	void updateProgress(int percent);
	static LoadingLayer* create(bool fromReload);

	inline LoadingLayer();
	~LoadingLayer();

	BYTE byte11C; // idk, unused
	bool m_bUnk;
	BYTE gap11E[2]; // unused too
	int m_nLoadingStage;
	cocos2d::CCLabelBMFont* m_pTextLabel;
	TextArea* m_pText;
	cocos2d::CCSprite* m_pBarSprite;
	float m_fBarWidth;
	float m_fBarHeight;
	bool m_bFromReload;
};