#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>
#include <cstdlib>
#include <cocos2d.h>
#include <cocos-ext.h>
#include "enums.h"
#include "custom.h"

#ifndef CREATE_FUNC_BODY
#define CREATE_FUNC_BODY(name, ...)                                                                                                        \
    auto pRet = new (std::nothrow) name();                                                                                                 \
    if (pRet && pRet->init(__VA_ARGS__)) {                                                                                                 \
        pRet->autorelease();                                                                                                               \
        return pRet;                                                                                                                       \
    }                                                                                                                                      \
    CC_SAFE_DELETE(pRet);                                                                                                                  \
    return nullptr;
#endif

#ifndef PAD
#define PAD(count) uint8_t pad##__LINE__[count];
#endif

#include "AccountHelpLayer.h"
#include "AccountLayer.h"
#include "AccountLoginLayer.h"
#include "AccountRegisterLayer.h"
#include "AchievementBar.h"
#include "AchievementCell.h"
#include "AchievementManager.h"
#include "AchievementNotifier.h"
#include "AchievementsLayer.h"
#include "ArtistCell.h"
#include "BoomListView.h"
#include "ButtonSprite.h"
#include "CCTextInputNode.h"
#include "CheckpointObject.h"
#include "ColoredSection.h"
#include "CommentCell.h"
#include "CustomSongCell.h"
#include "DelaySection.h"
#include "delegates.h"
#include "DialogLayer.h"
#include "DialogObject.h"
#include "DrawGridLayer.h"
#include "EditorUI.h"
#include "EffectGameObject.h"
#include "FLAlertLayer.h"
#include "GameCell.h"
#include "GameLevelManager.h"
#include "GameManager.h"
#include "GameObject.h"
#include "GauntletNode.h"
#include "GauntletSelectLayer.h"
#include "GhostTrailEffect.h"
#include "GJAccountManager.h"
#include "GJBaseGameLayer.h"
#include "GJChallengeItem.h"
#include "GJComment.h"
#include "GJDropDownLayer.h"
#include "GJEffectManager.h"
#include "GJGameLevel.h"
#include "GJGarageLayer.h"
#include "GJGroundLayer.h"
#include "GJLevelScoreCell.h"
#include "GJMapPack.h"
#include "GJMessageCell.h"
#include "GJObjectDecoder.h"
#include "GJRequestCell.h"
#include "GJRewardItem.h"
#include "GJRewardObject.h"
#include "GJScoreCell.h"
#include "GJSearchObject.h"
#include "GJStoreItem.h"
#include "GJUserCell.h"
#include "GJUserMessage.h"
#include "GJUserScore.h"
#include "InfoLayer.h"
#include "InstantSection.h"
#include "KeysLayer.h"
#include "LevelCell.h"
#include "LevelEditorLayer.h"
#include "LevelPage.h"
#include "LevelSelectLayer.h"
#include "LevelSettingsLayer.h"
#include "LevelSettingsObject.h"
#include "ListCell.h"
#include "MapPackCell.h"
#include "MenuLayer.h"
#include "MultilineBitmapFont.h"
#include "NumberInputLayer.h"
#include "ObjectToolbox.h"
#include "PauseLayer.h"
#include "PlayerCheckpoint.h"
#include "PlayerObject.h"
#include "PlayLayer.h"
#include "SecretLayer.h"
#include "SetGroupIDLayer.h"
#include "SetIDLayer.h"
#include "SimplePlayer.h"
#include "SongCell.h"
#include "SongInfoObject.h"
#include "SongObject.h"
#include "StatsCell.h"
#include "TableViewCell.h"
#include "UILayer.h"
#include "UndoObject.h"
#include "LoadingLayer.h"
#include "CCMenuItemSpriteExtra.h"