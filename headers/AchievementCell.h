#include "includes.h"

class AchievementCell : public TableViewCell {
public:
	AchievementCell(char const* title, float width, float height);
	bool init();
	virtual void draw();
	void updateBGColor(int);
	const char* getTitleFromKey(char const*);
	void loadFromDict(cocos2d::CCDictionary*);
};