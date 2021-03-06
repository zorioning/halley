#pragma once
#include "halley/ui/ui_widget.h"

namespace Halley {
	class HalleyAPI;
	class Project;
	class UIFactory;

	class SceneEditorTabs final : public UIWidget {
	public:
		SceneEditorTabs(UIFactory& factory, Project& project, const HalleyAPI& api);

		void load(AssetType assetType, const String& name);

	protected:
		void update(Time t, bool moved) override;
		
	private:
		UIFactory& factory;
		Project& project;
		const HalleyAPI& api;
		
		std::shared_ptr<UIList> tabs;
		std::shared_ptr<UIPagedPane> pages;
		std::vector<String> toClose;

		void makeUI();
		void closeTab(const String& key);
	};
}
