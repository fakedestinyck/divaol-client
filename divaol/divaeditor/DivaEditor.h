/*
 *  DivaCore.h
 *
 *  Created by CK on 7/6/12.
 *  Copyright 2012 CK. All rights reserved.
 *
 */

#ifndef DIVA_EDITOR
#define DIVA_EDITOR

#include<algorithm>

#include "divaeditor/DivaEditorCommon.h"
#include "divaeditor/DivaEditorMapData.h"
#include "divaeditor/Scene/DivaEditorScene.h"

#include "divacore/Core/DivaCommon.h"
#include "divacore/Core/DivaCore.h"
#include "divacore/Core/DivaMapInfo.h"

#include "SoraFSM.h"
#include "SoraInputListeners.h"
#include "SoraCanvas.h"
#include "app/SoraGameState.h"

#include "guichansetup.h"


namespace divaeditor
{
	using namespace sora;
	using namespace divacore;
	using namespace std;


	class Editor;
	class DivaEditorScene;
	class DivaEditorMapData;

	typedef Editor* EditorPtr;

	/*
	Editor
	manage all the editor functions
	*/
	class Editor : public sora::SoraGameState, public sora::SoraEventHandler, public EventHandler
	{
	public: 
		enum State{PRELOAD,MAIN} mState;

	private:
		friend class Core;
	    /*
		 * Common Variables
		 */
		//total state
		int mMode;
		//the initialize state name
		std::string initStateTag;
		//event manager
		EventManager eventManager;
		//state manager
		SoraFSMManager mFSMManager;

		


	private:
		Editor():nowScene(NULL),mState(PRELOAD),songInitialized(false) {};

		bool songInitialized;

		void coreDidLoad(void* arg);
		void registerEvent(){};


		/*
		 * Scene Manage
		 */
		DivaEditorScene *nowScene;
		DivaEditorScene *nextScene;
		map<State,DivaEditorScene*> scenes;

		void initScenes();
		void onSceneDisappeared(DivaEditorScene* sender);
		void onSceneAppeared(DivaEditorScene* sender);

	public:
		
		//map info
		DivaEditorMapData *mapData;

		/*
		 * singleton
		 */
		static EditorPtr Ptr;
		static EditorPtr instance() {static Editor instance; return (Ptr=&instance);}

		/*
		register and get
		*/
		void initDivaCoreForEditor();
		void setSongInitialized();
	public:
		// Scene
		void changeScene(State sceneState);

		 /*
		  * GameState
		  */
		void onStart();
		void onInitiate();
		void onDestroy();
		void onEnter();
		void onLeave();
		void onRender();
		void onUpdate(float dt);
		void onKeyPressed(SoraKeyEvent& event);
		void onKeyReleased(SoraKeyEvent& event);
		void onMouseClicked(SoraMouseEvent& event);
		void onMouseReleased(SoraMouseEvent& event);
		void onMouseMoved(SoraMouseEvent& event);
		void onMouseWheelUp(SoraMouseEvent& event);
		void onMouseWheelDown(SoraMouseEvent& event);


	    /*
		 * Control funcions
		 */
		 void prepare(const std::string &configFile);
		 void restart();
		 void pause();
		 void resume();
		 void over();
		 void ready();
		 void flowOver();
		 void render(sora::SoraSprite *sprite, const std::string &tag = "");
		 void render(float x, float y, sora::SoraSprite *sprite, const std::string &tag = "");
		 sora::SoraSprite* renderToCanvas(float width = 0, float height = 0);

		/*
		 * set functions
		 */


		/*
		 * Get functions
		 */
		 int getState() {return mState;}
	};


	#define INITIALIZE_EDITOR divaeditor::Editor::instance()
	#define EDITOR_PTR (divaeditor::Editor::Ptr)
	#define EDITUTILITY divacore::StandardEditUtility::instance()
}

#endif