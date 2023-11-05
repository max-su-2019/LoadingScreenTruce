#pragma once

namespace LoadingScreenTruce
{
	class CombatAIHook
	{
	public:
		static void InstallHook()
		{
			REL::Relocation<uintptr_t> hook{ REL::ID(32469) };
			auto& trampoline = SKSE::GetTrampoline();
			SKSE::AllocTrampoline(1 << 4);
			func = trampoline.write_call<5>(hook.address() + 0xFF, sub_1405CFD30);
		};

	private:
		static bool __fastcall sub_1405CFD30(RE::Actor* a1);

		static inline REL::Relocation<decltype(sub_1405CFD30)> func;
	};
}