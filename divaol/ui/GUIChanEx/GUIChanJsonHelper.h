#pragma once

#include "lib/wjson/wjson.h"

namespace gcn
{
	class SuperButtonEx;
	class ContainerEx;
	class WindowEx;
	class LabelEx;
	class WTextField;
	class Rectangle;
	class Color;

	namespace Helper
	{
		void ReadJsonFromFile(const std::wstring& filename, WJson::Value& v);

		SuperButtonEx* CreateButton(const WJson::Value& conf, const std::wstring& normal,
			const std::wstring& on, const std::wstring& down, const std::wstring& disable);

		SuperButtonEx* CreateButton(const WJson::Value& conf);

		ContainerEx* CreateStaticImage(const WJson::Value& conf, const std::wstring& name);

		WindowEx* CreateWindowEx(const WJson::Value& conf, const std::wstring& name);

		LabelEx* CreateLabel(const WJson::Value& conf, const std::wstring& name);

		WTextField* CreateInput(const WJson::Value& conf, const std::wstring& name);

		Rectangle GetRect(const WJson::Value& v);

		Color GetColor(const WJson::Value& v);
	}
}