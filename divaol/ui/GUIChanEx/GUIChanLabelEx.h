#pragma once

#include "guichan.hpp"
#include "SoraSprite.h"
#include "SoraCore.h"
#include <string>

namespace gcn
{

	class LabelEx :
		public Container
	{
	private:
		std::wstring text;
	public:
		LabelEx(std::wstring v = L"");
		~LabelEx();
		
		std::wstring getText() const;
		void setText(const std::wstring& v);

		void virtual draw(Graphics* graphics);
	};
}