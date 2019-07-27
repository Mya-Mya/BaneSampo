#pragma once
#include"uicomp\Vec2.h"
#include"DxLib.h"
namespace BSsystem {
	inline static Vec2 wndSize() {
		static Vec2 _wndSize= Vec2(1280, 720);
		return _wndSize;
	};
	static int font() {
		static int _font= CreateFontToHandle("ÉÅÉCÉäÉI", 30, 4, DX_FONTTYPE_ANTIALIASING);
		return _font;
	}
}