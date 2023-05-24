#include <includes.h>

class AchievementsLayer : public GJDropDownLayer
{
public:
	AchievementsLayer();
	static AchievementsLayer* create();

	void onNextPage(cocos2d::CCObject* pObj);
	void onPrevPage(cocos2d::CCObject* pObj);
	void setupLevelBrowser(cocos2d::CCArray* levels);
	void setupPageInfo(int totalAchs, int firstAch, int achsPerPage);
	void keyDown(cocos2d::enumKeyCodes key);
	void customSetup();
	void loadPage(int page);

	int m_nCurrentPage;
	CCMenuItemSpriteExtra* m_pNextBtn;
	CCMenuItemSpriteExtra* m_pPrevBtn;
	cocos2d::CCLabelBMFont* m_pPagesLabel;
	cocos2d::CCPoint m_CCPoint;
};