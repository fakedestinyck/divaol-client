/*
 *  DivaNormalNote.h
 *
 *  Created by Hyf042 on 1/25/12.
 *  Copyright 2012 Hyf042. All rights reserved.
 *
 */

#ifndef DIVA_NORMAL_NOTE
#define DIVA_NORMAL_NOTE

#include "Core/DivaNote.h"
#include "SoraCore.h"
#include "SoraSprite.h"
#include "SoraImageEffect.h"
#include "Component/DivaStandardFactory.h"

namespace divacore
{
	/*
	NormalNote
	*/
	class NormalNote : public Note
	{
		//variables
		int totalPosition;
		Point tailPosition,notePosition;
		Point lastTailPosition, nowTailPosition;
		Rect coverRect;

		//sprite
		SoraSprite *noteSprite;
		SoraSprite *coverSprite;
		//SoraSprite *arrowSprite;
		SoraSprite *rhythmSprite;
	public:
		NormalNote(MapNote& noteInfo):Note(noteInfo) {}

		//check the note info to say whether it's suitable
		bool checkInfo() {return (noteInfo.noteType=="normal"&&noteInfo.notePoint.size()==1);}
		void onInitiate() ;
		void onEnter();
		void onLeave() ;
		void onPoint(uint32 cnt, NotePoint point);
		void onRender();
		void onUpdate(double dt, double position);
		void onPressed(StateEvent& event);
		bool isReceive(KeyEvent& event, float time);
		void recover(int point, int position, float time);

		Point getReceiveScreenPosition() {return Point(noteSprite->getPosition().x,noteSprite->getPosition().y);}
	};
}

#endif