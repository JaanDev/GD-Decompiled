#include "includes.h"

//class CCIndexPath;
//class TableViewCell : public cocos2d::CCLayer
//{
//	DWORD dwordEC;
//	DWORD dwordF0;
//	CCIndexPath* m_pIndexPath;
//	DWORD dwordF8;
//	DWORD dwordFC;
//	int gap100;
//	int field_134;
//	int field_138;
//	int field_13C;
//	int field_140;
//	int field_144;
//	int field_148;
//	bool field_14C;
//	std::string m_sKey;
//	float m_fTableHeight;
//	float m_fCellHeight;
//	cocos2d::CCLayerColor* m_pColourLayer;
//	cocos2d::CCLayer* m_pLayer;
//};

struct TableViewCell : public cocos2d::CCLayer
{
	BYTE gap11C[4];
	DWORD dword120;
	cocos2d::CCObject m_pCCObject;
	DWORD dword144;
	DWORD dword148;
	BYTE byte14C;
	std::string m_sString;
	float m_fWidth;
	float m_fHeight;
	cocos2d::CCLayerColor* m_pCCLayerColor;
	cocos2d::CCLayer* m_pCCLayer;
};
