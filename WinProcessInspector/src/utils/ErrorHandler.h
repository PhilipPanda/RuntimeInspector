#pragma once

#include <Windows.h>
#include <string>

namespace WinProcessInspector {
namespace Utils {

	class ErrorHandler {
	public:
		static std::wstring GetLastErrorString();

		static std::wstring GetErrorString(DWORD errorCode);

		static std::wstring FormatApiError(const wchar_t* apiName, DWORD errorCode = 0);

		static bool IsAccessDenied();

		static bool IsProcessNotFound();
	};

} // namespace Utils
} // namespace WinProcessInspector
