#include "Hooks.h"

namespace LoadingScreenTruce
{
	bool __fastcall CombatAIHook::sub_1405CFD30(RE::Actor* a1)
	{
		auto result = func(a1);
		if (!result) {
			auto ui = RE::UI::GetSingleton();
			if (ui && (ui->IsMenuOpen(RE::LoadingMenu::MENU_NAME) || ui->IsMenuOpen(RE::FaderMenu::MENU_NAME))) {
				return true;
			}
		} 

		return result;
	}
}