enum AccountError
{
    kAccountErrorUnknown = 0,
    kAccountErrorGeneric = -1,
    kAccountErrorTakenUsername = -2,
    kAccountErrorTakenEmail = -3,
    kAccountErrorInvalidUsername = -4,
    kAccountErrorInvalidPassword = -5,
    kAccountErrorInvalidEmail = -6,
    kAccountErrorPasswordsDontMatch = -7,
    kAccountErrorPasswordTooShort = -8,
    kAccountErrorUsernameTooShort = -9,
    kAccountErrorLinkedToDifferentAccount = -10,
    kAccountErrorUnk = -11,
    kAccountErrorAccountDisabled = -12,
    kAccountErrorLinkedToDifferentSteamAccount = -13,
    kAccountErrorEmailsDontMatch = -99
};

enum BackupAccountError
{
    kBackupAccountErrorUnknown = 0,
    kBackupAccountErrorGeneric = -1,
    kBackupAccountErrorLoginFailed = -2
};

enum EasingType {
	kEasingTypeNone = 0,
	kEasingTypeEaseInOut = 1,
	kEasingTypeEaseIn = 2,
	kEasingTypeEaseOut = 3,
	kEasingTypeElasticInOut = 4,
	kEasingTypeElasticIn = 5,
	kEasingTypeElasticOut = 6,
	kEasingTypeBounceInOut = 7,
	kEasingTypeBounceIn = 8,
	kEasingTypeBounceOut = 9,
	kEasingTypeExponentialInOut = 10,
	kEasingTypeExponentialIn = 11,
	kEasingTypeExponentialOut = 12,
	kEasingTypeSineInOut = 13,
	kEasingTypeSineIn = 14,
	kEasingTypeSineOut = 15,
	kEasingTypeBackInOut = 16,
	kEasingTypeBackIn = 17,
	kEasingTypeBackOut = 18,
};

enum ComparisonType {
	kComparisonTypeEquals = 0,
	kComparisonTypeLarger = 1,
	kComparisonTypeSmaller = 2,
};

enum MoveTargetType {
	kMoveTargetTypeBoth = 0,
	kMoveTargetTypeXOnly = 1,
	kMoveTargetTypeYOnly = 2,
};

enum TouchToggleMode {
	kTouchToggleModeNormal = 0,
	kTouchToggleModeToggleOn = 1,
	kTouchToggleModeToggleOff = 2,
};

enum PickupMode;

enum ButtonType {
	kButtonTypeImage = 0,
	kButtonTypeString = 1
};

enum LikeItemType {
	kLikeItemTypeLevel = 1,
	kLikeItemTypeComment = 2,
	kLikeItemTypeAccComment = 3
};

enum GJHttpType
{
    kGJHttpTypeUploadLevel = 0x1,
    kGJHttpTypeGetOnlineLevels = 0x2,
    kGJHttpTypeGetMapPacks = 0x3,
    kGJHttpTypeDownloadLevel = 0x4,
    kGJHttpTypeUpdateLevel = 0x5,
    kGJHttpTypeRateStars = 0x6,
    kGJHttpTypeDeleteServerLevel = 0x7,
    kGJHttpTypeSetLevelStars = 0x8,
    kGJHttpTypeSetLevelFeatured = 0x9,
    kGJHttpTypeUpdateUserScore = 0xA,
    kGJHttpTypeGetLeaderboardScores = 0xB,
    kGJHttpTypeGetLevelComments = 0xC,
    kGJHttpTypeUploadComment = 0xD,
    kGJHttpTypeDeleteComment = 0xE,
    kGJHttpTypeLikeItem = 0xF,
    kGJHttpTypeRestoreItems = 0x10,
    kGJHttpTypeSubmitUserInfo = 0x11,
    kGJHttpTypeReportLevel = 0x12,
    kGJHttpTypeGetSongInfo = 0x13,
    kGJHttpTypeBackupAccount = 0x14,
    kGJHttpTypeSyncAccount = 0x15,
    kGJHttpTypeRegisterAccount = 0x16,
    kGJHttpTypeLoginAccount = 0x17,
    kGJHttpTypeUpdateDescription = 0x18,
    kGJHttpTypeGetAccountComments = 0x19,
    kGJHttpTypeUpdateAccountSettings = 0x1A,
    kGJHttpTypeGetGJUserInfo = 0x1B,
    kGJHttpTypeGetFriendRequests = 0x1C,
    kGJHttpTypeUploadFriendRequest = 0x1D,
    kGJHttpTypeDeleteFriendRequest = 0x1E,
    kGJHttpTypeAcceptFriendRequest = 0x1F,
    kGJHttpTypeReadFriendRequest = 0x20,
    kGJHttpTypeRemoveFriend = 0x21,
    kGJHttpTypeBlockUser = 0x22,
    kGJHttpTypeUnblockUser = 0x23,
    kGJHttpTypeGetUserList = 0x24,
    kGJHttpTypeGetUserMessages = 0x25,
    kGJHttpTypeDownloadUserMessage = 0x26,
    kGJHttpTypeDeleteUserMessages = 0x27,
    kGJHttpTypeUploadUserMessage = 0x28,
    kGJHttpTypeGetUsers = 0x29,
    kGJHttpTypeBanUser = 0x2A,
    kGJHttpTypeRequestUserAccess = 0x2B,
    kGJHttpTypeGetLevelSaveData = 0x2C,
    kGJHttpTypeSuggestLevelStars = 0x2D,
    kGJHttpTypeGetGJRewards = 0x2E,
    kGJHttpTypeGetGJChallenges = 0x2F,
    kGJHttpTypeGetGJDailyLevelState = 0x30,
    kGJHttpTypeUnknown49 = 0x31,
    kGJHttpTypeRateDemon = 0x32,
    kGJHttpTypeGetLevelLeaderboard = 0x33,
    kGJHttpTypeGetGauntlets = 0x34,
    kGJHttpTypeGetTopArtists = 0x35,
    kGJHttpTypeGetAccountBackupURL = 0x36,
    kGJHttpTypeGetAccountSyncURL = 0x37,
};