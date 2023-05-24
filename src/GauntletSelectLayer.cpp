#include <GauntletSelectLayer.h>

void GauntletSelectLayer::updateArrows() {
	this->m_pPrevBtn->setVisible(false);

	bool visible;

	auto scrollLayer = this->m_pScrollLayer;
	if (scrollLayer) {
		visible = scrollLayer->m_nCurrentPage < scrollLayer->getTotalPages() - 1;
	}

	this->m_pNextBtn->setVisible(visible);
}

void GauntletSelectLayer::scrollLayerWillScrollToPage(BoomScrollLayer* layer, int page) {
	this->updateArrows();
}

void GauntletSelectLayer::scrollLayerScrolledToPage(BoomScrollLayer* layer, int page) {
	this->updateArrows();
}

void GauntletSelectLayer::onRefresh(cocos2d::CCObject* pObj) {
	this->m_pRefreshBtn->setVisible(false);

	if (this->m_pScrollLayer) {
		this->m_pScrollLayer->removeFromParentAndCleanup(true);
		this->m_pScrollLayer = nullptr;
	}

	this->updateArrows();
	GameLevelManager::sharedState()->resetGauntlets();
	this->m_pLoadingCircle->setVisible(true);
	//*(GameLevelManager::sharedState() + 396) = &this->dword120;
	GameLevelManager::sharedState()->getGauntlets();
}

void GauntletSelectLayer::keyBackClicked() {
	this->onBack(nullptr);
}

void GauntletSelectLayer::loadLevelsFailed(const char*) {

}