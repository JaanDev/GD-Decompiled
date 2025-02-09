#include "includes.h"

class CCSpritePlus : public cocos2d::CCSprite {};

class GameObject : public CCSpritePlus
{
	bool m_bUnk3;
	bool m_bIsBlueMaybe;
	float m_fUnk2;
	float m_fUnk;
	float m_fUnk3;
	float m_fUnk4;
	bool m_bUnk;
	float m_fAnimSpeed2;
	bool m_bIsEffectObject;
	bool m_bRandomisedAnimStart;
	float m_fAnimSpeed;
	bool m_bBlackChild;
	bool m_bUnkOutlineMaybe;
	float m_fBlackChildOpacity;
	bool field_21C;
	bool m_bEditor;
	bool m_bGroupDisabled;
	bool m_bColourOnTop;
	GJSpriteColor* m_pMainColourMode;
	GJSpriteColor* m_pSecondaryColourMode;
	bool m_bCol1;
	bool m_bCol2;
	cocos2d::CCSize m_obPos;
	float m_fUnkRotationField;
	bool m_bTintTrigger;
	bool m_bIsFlipX;
	bool m_bIsFlipY;
	cocos2d::CCPoint m_obBoxOffset;
	bool m_bIsOriented;
	cocos2d::CCPoint m_obBoxOffset2;
	OBB2D* m_pObjectOBB2D;
	bool m_bOriented;
	cocos2d::CCSprite* m_pGlowSprite;
	bool m_bNotEditor;
	cocos2d::CCAction* m_pAction;
	bool m_bUnk1;
	bool m_bRunActionWithTag;
	bool m_bObjectPoweredOn;
	cocos2d::CCSize m_obObjectSize;
	bool m_bTrigger;
	bool m_bActive;
	bool m_bAnimationFinished;
	cocos2d::CCParticleSystemQuad* m_pParticleSystem;
	std::string m_sEffectPlistName;
	bool m_bParticleAdded;
	bool m_bHasParticles;
	bool m_bUnkCustomRing;
	cocos2d::CCPoint m_obPortalPosition;
	bool m_bUnkParticleSystem;
	cocos2d::CCRect m_obObjectTextureRect;
	bool m_bTextureRectDirty;
	float m_fRectXCenterMaybe;
	cocos2d::CCRect m_obObjectRect2;
	bool m_bIsObjectRectDirty;
	bool m_bIsOrientedRectDirty;
	bool m_bHasBeenActivated;
	bool m_bHasBeenActivatedP2;
	BYTE PAD2[8]
	bool m_bObjectRectDirty;
	bool m_bOrientedRectDirty;
	bool m_bUniqueActivated;
	bool m_bActivated;
	bool m_bCollectable;
	bool m_bPulseToBPM;
	bool m_bCanRotateFree;
	int m_nLinkedGroupID;
	bool m_bRotationTrigger;
	int m_nCustomRotationSpeed;
	bool m_bDisableRotation;
	bool m_bIsMainColBlack;
	bool field_2CA;
	bool m_bBlending;
	bool m_bBlending2;
	bool m_bUnk2;
	bool field_2CE;
	cocos2d::CCSprite* m_pColourSprite;
	bool m_bIgnoreScreenCheck;
	float m_fRadius;
	bool m_bSnappedRotation;
	cocos2d::CCSize m_obScaleMod;
	int m_nUniqueID;
	GameObjectType m_eGameObjectType;
	int m_nSectionIdx;
	bool m_bTouchTriggered;
	bool m_bSpawnTriggered;
	cocos2d::CCPoint m_obStartPos;
	std::string m_sTextureFrameName;
	bool m_bUseAudioScale;
	bool m_bSleeping;
	float m_fRotation;
	cocos2d::CCSize m_obStartScale;
	bool m_bStartFlipX;
	bool m_bStartFlipY;
	bool m_bShouldHide;
	float m_fSpawnXPosition;
	bool m_bInvisible;
	float m_fEnterAngle;
	int m_eActiveEnterEffect;
	int m_nParentMode;
	bool m_bDisableGlow;
	int m_nColourIdx;
	float m_fScale;
	int m_nObjectID;
	bool m_bDontTransform;
	bool m_bDefaultDontFade;
	bool m_bIgnoreEnter;
	bool m_bIgnoreFade;
	bool m_bDontFadeTinted;
	bool m_bTintObject;
	bool m_bDetailColourObject;
	bool m_bDontEnter;
	bool m_bDontFade;
	bool m_bStateVar;
	int m_nDefaultZOrder;
	bool m_bPortal;
	bool m_bLockColourAsChild;
	bool m_bCustomAudioScale;
	int m_fMinAudioScale;
	int m_fMaxAudioScale;
	bool m_bUnkParticleSystem2;
	int m_nSecretCoinID;
	int m_unkUnusedSaveStringKey53;
	bool m_bInvisibleMode;
	bool m_bGlowUserBackgroundColour;
	bool m_bUseSpecialLight;
	bool m_bOrbOrPad;
	float m_fGlowOpacityMod;
	bool m_bUpSlope;
	int m_eSlopeType;
	float m_fSlopeAngle;
	bool m_bHazardousSlope;
	float dword18C;
	GJSpriteColor* m_pColour1;
	GJSpriteColor* m_pColour2;
	bool m_bBlendingBatchNode;
	int m_nDefaultZLayer;
	int m_nZLayer;
	int m_nZOrder;
	std::string m_sText;
	bool m_bSpecialObject;
	bool m_bObjectSelected2;
	bool m_bObjectSelected;
	int m_nGlobalClickCounter;
	cocos2d::CCPoint m_obUnk2;
	bool dword1BC;
	bool field_3AD;
	float m_fMultiScaleMultiplier;
	std::vector<short> m_nGroupContainer;
	int m_nGroupCount;
	std::vector<short> m_nColourGroupContainer;
	int m_nColourGroupCount;
	std::vector<short> m_nOpacityGroupContainer;
	int m_nOpacityGroupCount;
	int m_nEditorLayer1;
	int m_nEditorLayer2;
	int m_nGroupDisabled;
	bool dword1EC;
	bool m_bUseCustomContentSize;
	bool field_3DE;
	cocos2d::CCSize m_obUnkSize;
	cocos2d::CCPoint m_obLastPosition;
	bool m_bDidUpdateLastPosition;
	bool m_bUpdateLastPos;
	BYTE PAD3[4]
	bool m_bSyncedAnimation;
	int m_eLavaBubbleColourID;
	bool dword210;
	bool field_401;
	bool field_402;
	bool field_403;
	bool dword214;
	bool m_bSpawnObject;
	bool m_bHasObjectCount;
	int m_nAnimFrame;
	bool m_bHighDetail;
	void* m_pMainColourSprite;
	void* m_pSecondaryColourSprite;
	GJEffectManager* m_pEffectManager;
	bool dword22C;
	bool m_bIsDecoration;
	bool m_bOptimisedGroup;
	bool field_41F;
	bool dword230;
	int m_eZagColour;
	bool m_bMultiActivate;
	cocos2d::_ccColor3B m_Colour;
};
