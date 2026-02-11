#pragma once

#include <Windows.h>

namespace WinProcessInspector {
namespace GUI {

struct Theme {
	static constexpr COLORREF Background = RGB(255, 255, 255);
	static constexpr COLORREF BackgroundLight = RGB(250, 250, 250);
	static constexpr COLORREF BackgroundDark = RGB(245, 245, 245);
	static constexpr COLORREF Text = RGB(0, 0, 0);
	static constexpr COLORREF TextDim = RGB(96, 96, 96);
	static constexpr COLORREF Border = RGB(200, 200, 200);
	static constexpr COLORREF Accent = RGB(0, 120, 215);
	static constexpr COLORREF AccentHover = RGB(23, 145, 238);
	static constexpr COLORREF Selection = RGB(230, 240, 255);
	
	static constexpr COLORREF SystemProcess = RGB(0, 100, 200);
	static constexpr COLORREF HighIntegrity = RGB(200, 0, 0);
	static constexpr COLORREF MediumIntegrity = RGB(200, 120, 0);
	static constexpr COLORREF LowIntegrity = RGB(0, 128, 0);
	static constexpr COLORREF OwnProcess = RGB(128, 0, 200);
	
	static constexpr COLORREF CpuBarLow = RGB(80, 200, 120);
	static constexpr COLORREF CpuBarMed = RGB(255, 200, 80);
	static constexpr COLORREF CpuBarHigh = RGB(255, 100, 100);
	
	static HBRUSH GetBackgroundBrush() {
		static HBRUSH brush = CreateSolidBrush(Background);
		return brush;
	}
	
	static HBRUSH GetBackgroundLightBrush() {
		static HBRUSH brush = CreateSolidBrush(BackgroundLight);
		return brush;
	}
};

}
}
