#include "includes.h"

class GJGroundLayer : public cocos2d::CCLayer
{
public:
	inline GJGroundLayer();
	void fadeInFinished();
	void fadeInGround(float delay);
	void fadeOutGround();
	float getGroundY();
	void deactivateGround();
	void createLine(int lineType);
	void hideShadows();
	bool init(int groundID, int lineType);
	void loadGroundSprites(int, bool);
	void positionGround(float height);
	void showGround();
	void updateGround01Color(cocos2d::ccColor3B color);
	void updateGround02Color(cocos2d::ccColor3B color);
	void updateGroundPos(cocos2d::CCPoint pos);
	void updateGroundWidth();
	void updateLineBlend(bool blend);
	virtual void draw() {};
	static GJGroundLayer* create(int groundID, int lineType);

	cocos2d::CCSprite* m_pGround1Sprite;
	cocos2d::CCSprite* m_pGround2Sprite;
	float m_fGroundWidth;
	cocos2d::CCSprite* m_pLineSprite;
	bool m_bShowGround;
	bool m_bLineBlend;
	float m_fGroundHeight;
	int m_nLineType;
};
