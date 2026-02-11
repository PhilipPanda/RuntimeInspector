#pragma once

#include <Windows.h>
#include <string>
#include <vector>

namespace WinProcessInspector {
namespace Security {

	struct Privilege {
		std::wstring Name;
		bool Enabled;
		bool EnabledByDefault;
	};

	struct SecurityIdentifier {
		std::wstring Name;
		std::wstring Domain;
		SID_NAME_USE Type;
	};

	enum class IntegrityLevel : DWORD {
		Untrusted = SECURITY_MANDATORY_UNTRUSTED_RID,
		Low = SECURITY_MANDATORY_LOW_RID,
		Medium = SECURITY_MANDATORY_MEDIUM_RID,
		MediumPlus = SECURITY_MANDATORY_MEDIUM_PLUS_RID,
		High = SECURITY_MANDATORY_HIGH_RID,
		System = SECURITY_MANDATORY_SYSTEM_RID,
		Protected = SECURITY_MANDATORY_PROTECTED_PROCESS_RID,
		Unknown = 0xFFFFFFFFU
	};

	class SecurityManager {
	public:
		SecurityManager();
		~SecurityManager();

		SecurityManager(const SecurityManager&) = delete;
		SecurityManager& operator=(const SecurityManager&) = delete;

		bool EnablePrivilege(const wchar_t* privilegeName);

		bool DisablePrivilege(const wchar_t* privilegeName);

		bool IsPrivilegeEnabled(const wchar_t* privilegeName) const;

		std::vector<Privilege> GetPrivileges(HANDLE hToken = nullptr) const;

		IntegrityLevel GetProcessIntegrityLevel(DWORD processId = 0) const;

		std::vector<SecurityIdentifier> GetGroups(HANDLE hToken = nullptr) const;

		static HANDLE OpenProcessToken(DWORD processId, DWORD desiredAccess = TOKEN_QUERY | TOKEN_ADJUST_PRIVILEGES);

		static int ElevatePrivileges();

	private:
		HANDLE m_hToken;
		bool m_bTokenOpened;

		bool OpenCurrentProcessToken();
		void CloseToken();
	};

	std::wstring IntegrityLevelToString(IntegrityLevel level);

	std::wstring SidNameUseToString(SID_NAME_USE use);

} // namespace Security
} // namespace WinProcessInspector
