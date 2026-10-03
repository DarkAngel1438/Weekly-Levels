#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include <Geode/binding/GJSearchObject.hpp>

using namespace geode::prelude;

class $modify(CreatorLayer) {   
    void onFeaturedLevels(CCObject*) {
        auto search = GJSearchObject::create(SearchType::FeaturedLite);
        CCDirector::get()->pushScene(CCTransitionFade::create(0.5f, LevelBrowserLayer::scene(search)));
    }
};

class $modify(LevelBrowserLayer) {
    bool init(GJSearchObject* search) {
        if (!LevelBrowserLayer::init(search)) return false;
        return true;
    }
};
