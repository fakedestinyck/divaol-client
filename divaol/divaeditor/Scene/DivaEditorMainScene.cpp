#include "divaeditor/Scene/DivaEditorScene.h"
#include "divaeditor/DivaEditorCommon.h"

#include "Animation/SoraGUIAnimation.h"

#include "divacore/Component/DivaStandardCoreFlow.h"
#include "divacore/Mode/DivaEditMode.h"

#include "direct.h"

namespace divaeditor
{
	using namespace gcn;

#define EditUtility divacore::StandardEditUtility::instance()


	gcn::Container* DivaEditorMainScene::initTimelineCategory()
	{
		//Init Timeline Category
		gcn::Container *timelineCategory = new gcn::Container();
		timelineCategory->setSize(1280,720);
		timelineCategory->setOpaque(true);
		timelineCategory->setBaseColor(gcn::Color(0,0,0,0));

		//Timeline Panel
		gcn::Container *timelinePanel = new gcn::Container();
		timelinePanel->setOpaque(true);
		timelinePanel->setAlpha(150);
		timelinePanel->setId("timelinePanel");
		timelinePanel->setSize(400,240);
		timelinePanel->setPosition(800,380);
		timelineCategory->add(timelinePanel);

#pragma region BPM operation

		gcn::WTextField *txtField_timeline_BPM = new gcn::WTextField();
		txtField_timeline_BPM->enableNumericMode(true);
		txtField_timeline_BPM->setId("txtField_timeline_BPM");
		txtField_timeline_BPM->setSize(100,20);
		txtField_timeline_BPM->setPosition(100,50);
		sora::SoraGUI::Instance()->registerGUIResponser(txtField_timeline_BPM, this, "txtField_timeline_BPM", sora::RESPONSEACTION);
		timelinePanel->add(txtField_timeline_BPM);

		gcn::Label *label_timeline_bpm = new gcn::Label("Now BPM:");
		label_timeline_bpm->adjustSize();
		label_timeline_bpm->setBackgroundColor(gcn::Color(0,0,0,0));
		label_timeline_bpm->setPosition(txtField_timeline_BPM->getX()-label_timeline_bpm->getWidth()-5,
			txtField_timeline_BPM->getY() + (txtField_timeline_BPM->getHeight()-label_timeline_bpm->getHeight())/2);
		label_timeline_bpm->setForegroundColor(gcn::Color(255,255,255,255));
		timelinePanel->add(label_timeline_bpm);

		gcn::Button *btn_TimeLine_changeBPM = new gcn::Button("Change");
		btn_TimeLine_changeBPM->setId("btn_TimeLine_changeBPM");
		btn_TimeLine_changeBPM->setSize(50,20);
		btn_TimeLine_changeBPM->setPosition(txtField_timeline_BPM->getX()+txtField_timeline_BPM->getWidth()+5,txtField_timeline_BPM->getY());
		btn_TimeLine_changeBPM->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_changeBPM, this, "btn_TimeLine_changeBPM", sora::RESPONSEACTION);
		timelinePanel->add(btn_TimeLine_changeBPM);

		gcn::Button *btn_TimeLine_insertBPM = new gcn::Button("Insert");
		btn_TimeLine_insertBPM->setId("btn_TimeLine_insertBPM");
		btn_TimeLine_insertBPM->setSize(50,20);
		btn_TimeLine_insertBPM->setPosition(btn_TimeLine_changeBPM->getX()+btn_TimeLine_changeBPM->getWidth()+5,txtField_timeline_BPM->getY());
		btn_TimeLine_insertBPM->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_insertBPM, this, "btn_TimeLine_insertBPM", sora::RESPONSEACTION);
		timelinePanel->add(btn_TimeLine_insertBPM);

		gcn::Button *btn_TimeLine_deleteBPM = new gcn::Button("Delete");
		btn_TimeLine_deleteBPM->setId("btn_TimeLine_deleteBPM");
		btn_TimeLine_deleteBPM->setSize(50,20);
		btn_TimeLine_deleteBPM->setPosition(btn_TimeLine_insertBPM->getX()+btn_TimeLine_insertBPM->getWidth()+5,txtField_timeline_BPM->getY());
		btn_TimeLine_deleteBPM->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_deleteBPM, this, "btn_TimeLine_deleteBPM", sora::RESPONSEACTION);
		timelinePanel->add(btn_TimeLine_deleteBPM);

#pragma endregion BPM operation
		
#pragma region Offset operation

		gcn::WTextField *txtField_timeline_offSet = new gcn::WTextField();
		txtField_timeline_offSet->enableNumericMode(true);
		txtField_timeline_offSet->setId("txtField_timeline_offSet");
		txtField_timeline_offSet->setSize(100,20);
		txtField_timeline_offSet->setPosition(100,80);
		sora::SoraGUI::Instance()->registerGUIResponser(txtField_timeline_offSet, this, "txtField_timeline_offSet", sora::RESPONSEACTION);
		timelinePanel->add(txtField_timeline_offSet);

		gcn::Label *label_timeline_offset = new gcn::Label("Grid Offset:");
		label_timeline_offset->adjustSize();
		label_timeline_offset->setBackgroundColor(gcn::Color(0,0,0,0));
		label_timeline_offset->setPosition(txtField_timeline_offSet->getX()-label_timeline_offset->getWidth()-5,
			txtField_timeline_offSet->getY() + (txtField_timeline_offSet->getHeight()-label_timeline_offset->getHeight())/2);
		label_timeline_offset->setForegroundColor(gcn::Color(255,255,255,255));
		timelinePanel->add(label_timeline_offset);

		gcn::Button *btn_TimeLine_changeOffset = new gcn::Button("Change");
		btn_TimeLine_changeOffset->setId("btn_TimeLine_changeOffset");
		btn_TimeLine_changeOffset->setSize(50,20);
		btn_TimeLine_changeOffset->setPosition(txtField_timeline_offSet->getX()+txtField_timeline_offSet->getWidth()+5,txtField_timeline_offSet->getY());
		btn_TimeLine_changeOffset->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_changeOffset, this, "btn_TimeLine_changeOffset", sora::RESPONSEACTION);
		timelinePanel->add(btn_TimeLine_changeOffset);


#pragma endregion Offset operation

#pragma region Stop Operation

		gcn::WTextField *txtField_timeline_Stop = new gcn::WTextField();
		txtField_timeline_Stop->enableNumericMode(true);
		txtField_timeline_Stop->setId("txtField_timeline_Stop");
		txtField_timeline_Stop->setSize(100,20);
		txtField_timeline_Stop->setPosition(100,110);
		sora::SoraGUI::Instance()->registerGUIResponser(txtField_timeline_Stop, this, "txtField_timeline_Stop", sora::RESPONSEACTION);
		timelinePanel->add(txtField_timeline_Stop);

		gcn::Label *label_timeline_Stop = new gcn::Label("Now Stop:");
		label_timeline_Stop->adjustSize();
		label_timeline_Stop->setBackgroundColor(gcn::Color(0,0,0,0));
		label_timeline_Stop->setPosition(txtField_timeline_Stop->getX()-label_timeline_Stop->getWidth()-5,
			txtField_timeline_Stop->getY() + (txtField_timeline_Stop->getHeight()-label_timeline_Stop->getHeight())/2);
		label_timeline_Stop->setForegroundColor(gcn::Color(255,255,255,255));
		timelinePanel->add(label_timeline_Stop);

		gcn::Button *btn_TimeLine_changeStop = new gcn::Button("Change");
		btn_TimeLine_changeStop->setId("btn_TimeLine_changeStop");
		btn_TimeLine_changeStop->setSize(50,20);
		btn_TimeLine_changeStop->setPosition(txtField_timeline_Stop->getX()+txtField_timeline_Stop->getWidth()+5,txtField_timeline_Stop->getY());
		btn_TimeLine_changeStop->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_changeStop, this, "btn_TimeLine_changeStop", sora::RESPONSEACTION);
		timelinePanel->add(btn_TimeLine_changeStop);

		gcn::Button *btn_TimeLine_insertStop = new gcn::Button("Insert");
		btn_TimeLine_insertStop->setId("btn_TimeLine_insertStop");
		btn_TimeLine_insertStop->setSize(50,20);
		btn_TimeLine_insertStop->setPosition(txtField_timeline_Stop->getX()+txtField_timeline_Stop->getWidth()+5,txtField_timeline_Stop->getY());
		btn_TimeLine_insertStop->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_insertStop, this, "btn_TimeLine_insertStop", sora::RESPONSEACTION);
		timelinePanel->add(btn_TimeLine_insertStop);

		gcn::Button *btn_TimeLine_deleteStop = new gcn::Button("Delete");
		btn_TimeLine_deleteStop->setId("btn_TimeLine_deleteStop");
		btn_TimeLine_deleteStop->setSize(50,20);
		btn_TimeLine_deleteStop->setPosition(btn_TimeLine_changeStop->getX()+btn_TimeLine_changeStop->getWidth()+5,txtField_timeline_Stop->getY());
		btn_TimeLine_deleteStop->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_deleteStop, this, "btn_TimeLine_deleteStop", sora::RESPONSEACTION);
		timelinePanel->add(btn_TimeLine_deleteStop);

#pragma endregion Stop Operation

#pragma region BeatNum Operation

		gcn::WTextField *txtField_timeline_BeatNum = new gcn::WTextField();
		txtField_timeline_BeatNum->enableNumericMode(true);
		txtField_timeline_BeatNum->setId("txtField_timeline_BeatNum");
		txtField_timeline_BeatNum->setSize(100,20);
		txtField_timeline_BeatNum->setPosition(100,140);
		sora::SoraGUI::Instance()->registerGUIResponser(txtField_timeline_BeatNum, this, "txtField_timeline_BeatNum", sora::RESPONSEACTION);
		timelinePanel->add(txtField_timeline_BeatNum);

		gcn::Label *label_timeline_BeatNum = new gcn::Label("BeatNum:");
		label_timeline_BeatNum->adjustSize();
		label_timeline_BeatNum->setBackgroundColor(gcn::Color(0,0,0,0));
		label_timeline_BeatNum->setPosition(txtField_timeline_BeatNum->getX()-label_timeline_BeatNum->getWidth()-5,
			txtField_timeline_BeatNum->getY() + (txtField_timeline_BeatNum->getHeight()-label_timeline_BeatNum->getHeight())/2);
		label_timeline_BeatNum->setForegroundColor(gcn::Color(255,255,255,255));
		timelinePanel->add(label_timeline_BeatNum);

		gcn::Button *btn_TimeLine_changeBeatNum = new gcn::Button("Change");
		btn_TimeLine_changeBeatNum->setId("btn_TimeLine_changeBeatNum");
		btn_TimeLine_changeBeatNum->setSize(50,20);
		btn_TimeLine_changeBeatNum->setPosition(txtField_timeline_BeatNum->getX()+txtField_timeline_BeatNum->getWidth()+5,txtField_timeline_BeatNum->getY());
		btn_TimeLine_changeBeatNum->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_changeBeatNum, this, "btn_TimeLine_changeBeatNum", sora::RESPONSEACTION);
		timelinePanel->add(btn_TimeLine_changeBeatNum);

		gcn::Button *btn_TimeLine_deleteBeatNum = new gcn::Button("Delete");
		btn_TimeLine_deleteBeatNum->setId("btn_TimeLine_deleteBeatNum");
		btn_TimeLine_deleteBeatNum->setSize(50,20);
		btn_TimeLine_deleteBeatNum->setPosition(btn_TimeLine_changeBeatNum->getX()+btn_TimeLine_changeBeatNum->getWidth()+5,txtField_timeline_BeatNum->getY());
		btn_TimeLine_deleteBeatNum->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_deleteBeatNum, this, "btn_TimeLine_deleteBeatNum", sora::RESPONSEACTION);
		timelinePanel->add(btn_TimeLine_deleteBeatNum);

#pragma endregion BeatNum Operation
		
#pragma region TailSpeed Operation


		gcn::WTextField *txtField_timeline_TailSpeed = new gcn::WTextField();
		txtField_timeline_TailSpeed->enableNumericMode(true);
		txtField_timeline_TailSpeed->setId("txtField_timeline_TailSpeed");
		txtField_timeline_TailSpeed->setSize(100,20);
		txtField_timeline_TailSpeed->setPosition(100,170);
		sora::SoraGUI::Instance()->registerGUIResponser(txtField_timeline_TailSpeed, this, "txtField_timeline_TailSpeed", sora::RESPONSEACTION);
		timelinePanel->add(txtField_timeline_TailSpeed);

		gcn::Label *label_timeline_TailSpeed = new gcn::Label("Tail Speed:");
		label_timeline_TailSpeed->adjustSize();
		label_timeline_TailSpeed->setBackgroundColor(gcn::Color(0,0,0,0));
		label_timeline_TailSpeed->setPosition(txtField_timeline_TailSpeed->getX()-label_timeline_TailSpeed->getWidth()-5,
			txtField_timeline_TailSpeed->getY() + (txtField_timeline_TailSpeed->getHeight()-label_timeline_TailSpeed->getHeight())/2);
		label_timeline_TailSpeed->setForegroundColor(gcn::Color(255,255,255,255));
		timelinePanel->add(label_timeline_TailSpeed);

		gcn::Button *btn_TimeLine_changeTailSpeed = new gcn::Button("Change");
		btn_TimeLine_changeTailSpeed->setId("btn_TimeLine_changeTailSpeed");
		btn_TimeLine_changeTailSpeed->setSize(50,20);
		btn_TimeLine_changeTailSpeed->setPosition(txtField_timeline_TailSpeed->getX()+txtField_timeline_TailSpeed->getWidth()+5,txtField_timeline_TailSpeed->getY());
		btn_TimeLine_changeTailSpeed->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_changeTailSpeed, this, "btn_TimeLine_changeTailSpeed", sora::RESPONSEACTION);
		timelinePanel->add(btn_TimeLine_changeTailSpeed);

#pragma endregion TailSpeed Operation
		
		return timelineCategory;
	}
	gcn::Container* DivaEditorMainScene::initNoteCategory()
	{
		//Init Note Category
		gcn::Container *noteCategory = new gcn::Container();
		noteCategory->setSize(1280,720);
		noteCategory->setOpaque(true);
		noteCategory->setBaseColor(gcn::Color(0,0,0,0));

		NoteArea *noteArea = new NoteArea();
		float factor = 720.0/1080.0;
		noteArea->setId("NoteArea");
		noteArea->setPosition(EDITCONFIG->NoteAreaX*factor, EDITCONFIG->NoteAreaY*factor);
		noteArea->adjustSize(factor);
		noteCategory->add(noteArea);

		return noteCategory;
	}
	gcn::Container* DivaEditorMainScene::initShowCategory()
	{
		//Init Note Category
		gcn::Container *showCategory = new gcn::Container();
		showCategory->setSize(1280,720);
		showCategory->setOpaque(true);
		showCategory->setBaseColor(gcn::Color(0,0,0,0));

		ResourcePanel *resourcePanel = new ResourcePanel();
		resourcePanel->addSelectionListener(this);
		resourcePanel->setId("resourcePanel");
		resourcePanel->setBaseColor(gcn::Color(41,57,85,100));
		resourcePanel->setForegroundColor(gcn::Color(255,255,255,255));
		resourcePanel->setSize(500,500);
		resourcePanel->setElementGridSize(128);
		resourcePanel->adjustSize();
		showCategory->add(resourcePanel);


#pragma region resourcePanelControlContainer

		gcn::BoarderedContainer *resourcePanelControlContainer = new gcn::BoarderedContainer();
		resourcePanelControlContainer->setBaseColor(resourcePanel->getBaseColor());
		resourcePanelControlContainer->setForegroundColor(gcn::Color(255,255,255,255));
		resourcePanelControlContainer->setSize(resourcePanel->getWidth(), 30);

		resourcePanel->setPosition(100,(showCategory->getHeight()-resourcePanel->getHeight()-resourcePanelControlContainer->getHeight())/2);
		resourcePanelControlContainer->setPosition(resourcePanel->getX(),resourcePanel->getY()+resourcePanel->getHeight());

		showCategory->add(resourcePanelControlContainer);

		int buttonSize = resourcePanelControlContainer->getHeight()-10;

		gcn::Button *btn_resourceLeftPage = new gcn::Button("��");
		btn_resourceLeftPage->setId("btn_resourceLeftPage");
		btn_resourceLeftPage->setSize(buttonSize, buttonSize);
		btn_resourceLeftPage->setPosition(resourcePanelControlContainer->getWidth()/2-20-buttonSize,5);
		btn_resourceLeftPage->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_resourceLeftPage, this, "btn_resourceLeftPage", sora::RESPONSEACTION);
		resourcePanelControlContainer->add(btn_resourceLeftPage);

		gcn::Label *label_resourcePageNum = new gcn::Label();
		label_resourcePageNum->setId("label_resourcePageNum");
		label_resourcePageNum->setSize(20*2,buttonSize);
		label_resourcePageNum->setPosition(btn_resourceLeftPage->getX()+btn_resourceLeftPage->getWidth(),5);
		label_resourcePageNum->setAlignment(gcn::Graphics::Alignment::CENTER);
		label_resourcePageNum->setForegroundColor(gcn::Color(255,255,255,255));
		resourcePanelControlContainer->add(label_resourcePageNum);
			
		gcn::Button *btn_resourceRightPage = new gcn::Button("��");
		btn_resourceRightPage->setId("btn_resourceRightPage");
		btn_resourceRightPage->setPosition(resourcePanelControlContainer->getWidth()/2+20,5);
		btn_resourceRightPage->setSize(buttonSize,buttonSize);
		btn_resourceRightPage->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_resourceRightPage, this, "btn_resourceRightPage", sora::RESPONSEACTION);
		resourcePanelControlContainer->add(btn_resourceRightPage);

		gcn::Button *btn_resourceAdd = new gcn::Button("+");
		btn_resourceAdd->setId("btn_resourceAdd");
		btn_resourceAdd->setPosition(resourcePanelControlContainer->getWidth()-buttonSize*2-10,5);
		btn_resourceAdd->setSize(buttonSize,buttonSize);
		btn_resourceAdd->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_resourceAdd, this, "btn_resourceAdd", sora::RESPONSEACTION);
		resourcePanelControlContainer->add(btn_resourceAdd);

		gcn::Button *btn_resourceRemove = new gcn::Button("-");
		btn_resourceRemove->setId("btn_resourceRemove");
		btn_resourceRemove->setPosition(btn_resourceAdd->getX()+btn_resourceAdd->getWidth()+5,5);
		btn_resourceRemove->setSize(buttonSize,buttonSize);
		btn_resourceRemove->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_resourceRemove, this, "btn_resourceRemove", sora::RESPONSEACTION);
		resourcePanelControlContainer->add(btn_resourceRemove);

#pragma endregion resourcePanelControlContainer

#pragma region resourceDetail

		gcn::BoarderedContainer *resourceDetailContainer = new gcn::BoarderedContainer();
		resourceDetailContainer->setId("resourceDetailContainer");
		resourceDetailContainer->setSize(resourcePanel->getWidth()+210,resourcePanel->getHeight()/2);
		resourceDetailContainer->setBaseColor(gcn::Color(41,57,85,100));
		resourceDetailContainer->setForegroundColor(gcn::Color(255,255,255,255));
		resourceDetailContainer->setPosition(resourcePanel->getX()+resourcePanel->getWidth()+20,resourcePanel->getY());
		resourceDetailContainer->setVisible(false);
		showCategory->add(resourceDetailContainer);

		//File Path
		gcn::WLabel *wlabel_resourceDetail_filePath = new gcn::WLabel(L"Path:");
		wlabel_resourceDetail_filePath->setId("wlabel_resourceDetail_filePath");
		wlabel_resourceDetail_filePath->setBaseColor(gcn::Color(0,0,0,0));
		wlabel_resourceDetail_filePath->setForegroundColor(gcn::Color(255,255,255,255));
		wlabel_resourceDetail_filePath->adjustSize();
		wlabel_resourceDetail_filePath->setPosition(100-wlabel_resourceDetail_filePath->getWidth(),20);
		resourceDetailContainer->add(wlabel_resourceDetail_filePath);

		gcn::WLabel *wlabel_resourceDetail_filePathValue = new gcn::WLabel();
		wlabel_resourceDetail_filePathValue->setId("wlabel_resourceDetail_filePathValue");
		wlabel_resourceDetail_filePathValue->setBaseColor(gcn::Color(0,0,0,0));
		wlabel_resourceDetail_filePathValue->setForegroundColor(gcn::Color(255,255,255,255));
		wlabel_resourceDetail_filePathValue->setPosition(100,wlabel_resourceDetail_filePath->getY());
		resourceDetailContainer->add(wlabel_resourceDetail_filePathValue);

		//File Type
		gcn::WLabel *wlabel_resourceDetail_fileType = new gcn::WLabel(L"Type:");
		wlabel_resourceDetail_fileType->setId("wlabel_resourceDetail_fileType");
		wlabel_resourceDetail_fileType->setBaseColor(gcn::Color(0,0,0,0));
		wlabel_resourceDetail_fileType->setForegroundColor(gcn::Color(255,255,255,255));
		wlabel_resourceDetail_fileType->adjustSize();
		wlabel_resourceDetail_fileType->setPosition(100-wlabel_resourceDetail_fileType->getWidth(),wlabel_resourceDetail_filePath->getY()+30);
		resourceDetailContainer->add(wlabel_resourceDetail_fileType);

		gcn::WLabel *wlabel_resourceDetail_fileTypeValue = new gcn::WLabel();
		wlabel_resourceDetail_fileTypeValue->setId("wlabel_resourceDetail_fileTypeValue");
		wlabel_resourceDetail_fileTypeValue->setBaseColor(gcn::Color(0,0,0,0));
		wlabel_resourceDetail_fileTypeValue->setForegroundColor(gcn::Color(255,255,255,255));
		wlabel_resourceDetail_fileTypeValue->setPosition(100,wlabel_resourceDetail_fileType->getY());
		resourceDetailContainer->add(wlabel_resourceDetail_fileTypeValue);

		//File Label
		gcn::WTextField *wtextField_resourceDetail_fileLabelValue = new gcn::WTextField();
		wtextField_resourceDetail_fileLabelValue->setId("wtextField_resourceDetail_fileLabelValue");
		wtextField_resourceDetail_fileLabelValue->setSize(450,20);
		wtextField_resourceDetail_fileLabelValue->setPosition(100,wlabel_resourceDetail_fileType->getY()+30);
		sora::SoraGUI::Instance()->registerGUIResponser(wtextField_resourceDetail_fileLabelValue, this, "wtextField_resourceDetail_fileLabelValue", sora::RESPONSEACTION);
		resourceDetailContainer->add(wtextField_resourceDetail_fileLabelValue);

		gcn::WLabel *wlabel_resourceDetail_fileLabel = new gcn::WLabel(L"Label:");
		wlabel_resourceDetail_fileLabel->setId("wlabel_resourceDetail_fileLabel");
		wlabel_resourceDetail_fileLabel->setBaseColor(gcn::Color(0,0,0,0));
		wlabel_resourceDetail_fileLabel->setForegroundColor(gcn::Color(255,255,255,255));
		wlabel_resourceDetail_fileLabel->adjustSize();
		wlabel_resourceDetail_fileLabel->setPosition(100-wlabel_resourceDetail_fileLabel->getWidth(),
													wtextField_resourceDetail_fileLabelValue->getY()+(wtextField_resourceDetail_fileLabelValue->getHeight()-wlabel_resourceDetail_fileLabel->getHeight())/2);
		resourceDetailContainer->add(wlabel_resourceDetail_fileLabel);


		//File events
		gcn::WLabel *wlabel_resourceDetail_fileEvents = new gcn::WLabel(L"Events:");
		wlabel_resourceDetail_fileEvents->setId("wlabel_resourceDetail_fileEvents");
		wlabel_resourceDetail_fileEvents->setBaseColor(gcn::Color(0,0,0,0));
		wlabel_resourceDetail_fileEvents->setForegroundColor(gcn::Color(255,255,255,255));
		wlabel_resourceDetail_fileEvents->adjustSize();
		wlabel_resourceDetail_fileEvents->setPosition(100-wlabel_resourceDetail_fileEvents->getWidth(),wlabel_resourceDetail_fileLabel->getY()+30);
		resourceDetailContainer->add(wlabel_resourceDetail_fileEvents);

		gcn::WListBox *wlistbox_resourceDetail_fileEventsValue = new gcn::WListBox(new WListModel());
		wlistbox_resourceDetail_fileEventsValue->setId("wlistbox_resourceDetail_fileEventsValue");
		wlistbox_resourceDetail_fileEventsValue->setSize(300,500);
		wlistbox_resourceDetail_fileEventsValue->setPosition(100,wlabel_resourceDetail_fileEvents->getY());
		wlistbox_resourceDetail_fileEventsValue->addSelectionListener(this);
		resourceDetailContainer->add(wlistbox_resourceDetail_fileEventsValue);

		gcn::WTextField *wtextField_resourceDetail_fileEventsPosition = new gcn::WTextField();
		wtextField_resourceDetail_fileEventsPosition->enableNumericMode(true);
		wtextField_resourceDetail_fileEventsPosition->setId("wtextField_resourceDetail_fileEventsPosition");
		wtextField_resourceDetail_fileEventsPosition->setSize(100,20);
		sora::SoraGUI::Instance()->registerGUIResponser(wtextField_resourceDetail_fileEventsPosition, this, "wtextField_resourceDetail_fileEventsPosition", sora::RESPONSEACTION);
		resourceDetailContainer->add(wtextField_resourceDetail_fileEventsPosition);

		gcn::Button *btn_resourceDetail_addFileEvent = new gcn::Button("+");
		btn_resourceDetail_addFileEvent->setId("btn_resourceDetail_addFileEvent");
		btn_resourceDetail_addFileEvent->setSize(buttonSize,buttonSize);
		btn_resourceDetail_addFileEvent->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_resourceDetail_addFileEvent, this, "btn_resourceDetail_addFileEvent", sora::RESPONSEACTION);
		resourceDetailContainer->add(btn_resourceDetail_addFileEvent);

		gcn::Button *btn_resourceDetail_removeFileEvent = new gcn::Button("-");
		btn_resourceDetail_removeFileEvent->setId("btn_resourceDetail_removeFileEvent");
		btn_resourceDetail_removeFileEvent->setSize(buttonSize,buttonSize);
		btn_resourceDetail_removeFileEvent->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_resourceDetail_removeFileEvent, this, "btn_resourceDetail_removeFileEvent", sora::RESPONSEACTION);
		resourceDetailContainer->add(btn_resourceDetail_removeFileEvent);


#pragma endregion resourceDetail

		return showCategory;
	}
	gcn::Container* DivaEditorMainScene::initPlayCategory()
	{
		//Init Note Category
		gcn::Container *playCategory = new gcn::Container();
		playCategory->setSize(1280,720);
		playCategory->setOpaque(true);
		playCategory->setBaseColor(gcn::Color(0,0,0,0));

		return playCategory;
	}

	void DivaEditorMainScene::flowDidEnd(void* arg)
	{
		CORE_PTR->pause();
		EditUtility.setPosition(CORE_FLOW_PTR->getTotalPosition());
	}

	DivaEditorMainScene::DivaEditorMainScene()
	{
		GCN_GLOBAL->addIgnoreKey(gcn::Key::SPACE);

		sceneIndex = Editor::State::MAIN;

		//Init Scene
		top = new Container();
		top->setBaseColor(gcn::Color(0,0,0,0));
		top->setOpaque(true);
		top->setSize(1280,720);

		//Tool Bar
		container_ToolBar = new Container();
		container_ToolBar->setSize(510,40);
		container_ToolBar->setBaseColor(gcn::Color(34,137,227,255));

#pragma region Category Buttons
		//Three Category Buttons
		gcn::Button *btn_TimeLine = new gcn::Button("Timeline");
		btn_TimeLine->setId("btn_TimeLine");
		btn_TimeLine->setSize(120,30);
		btn_TimeLine->setPosition(5,5);
		btn_TimeLine->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine, this, "btn_TimeLine", sora::RESPONSEACTION);
		container_ToolBar->add(btn_TimeLine);

		gcn::Button *btn_Note = new gcn::Button("Note");
		btn_Note->setId("btn_Note");
		btn_Note->setSize(120,30);
		btn_Note->setPosition(130,5);
		btn_Note->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_Note, this, "btn_Note", sora::RESPONSEACTION);
		container_ToolBar->add(btn_Note);

		gcn::Button *btn_Show = new gcn::Button("Show");
		btn_Show->setId("btn_Show");
		btn_Show->setSize(120,30);
		btn_Show->setPosition(255,5);
		btn_Show->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_Show, this, "btn_Show", sora::RESPONSEACTION);
		container_ToolBar->add(btn_Show);

		gcn::Button *btn_Category_Play = new gcn::Button("Play!");
		btn_Category_Play->setId("btn_Category_Play");
		btn_Category_Play->setSize(120,30);
		btn_Category_Play->setPosition(380,5);
		btn_Category_Play->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_Category_Play, this, "btn_Category_Play", sora::RESPONSEACTION);
		container_ToolBar->add(btn_Category_Play);

		top->add(container_ToolBar);

#pragma endregion Category Buttons
		
#pragma region Play Control And Timeline Widget

		//Add Total Time Progress
		DivaEditorMusicProgressWidget *progressBar = new DivaEditorMusicProgressWidget();
		progressBar->setId("progressBar");
		//progressBar->setSize(500,30);
		//progressBar->setPosition(50,680);
		progressBar->setSize(410,30);
		progressBar->setPosition(670,20);
		progressBar->setBackgroundColor(gcn::Color(0,0,0,150));
		progressBar->setForegroundColor(gcn::Color(255,255,255,255));
		top->add(progressBar);

		//Play Control Buttons
		/*
		gcn::Button *btn_Play = new gcn::Button("Play");
		btn_Play->setId("btn_Play");
		btn_Play->setSize(30,30);
		btn_Play->setPosition(progressBar->getX()+progressBar->getWidth()+5,progressBar->getY());
		btn_Play->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_Play, this, "btn_Play", sora::RESPONSEACTION);
		top->add(btn_Play);
		*/

		gcn::Button *btn_Pause = new gcn::Button("Pause");
		btn_Pause->setId("btn_Pause");
		btn_Pause->setSize(30,30);
		btn_Pause->setPosition(progressBar->getX()+progressBar->getWidth()+5,progressBar->getY());
		btn_Pause->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_Pause, this, "btn_Pause", sora::RESPONSEACTION);
		top->add(btn_Pause);

		gcn::Button *btn_Stop = new gcn::Button("Stop");
		btn_Stop->setId("btn_Stop");
		btn_Stop->setSize(btn_Pause->getWidth(),btn_Pause->getHeight());
		btn_Stop->setPosition(btn_Pause->getX()+btn_Pause->getWidth()+5,btn_Pause->getY());
		btn_Stop->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_Stop, this, "btn_Stop", sora::RESPONSEACTION);
		top->add(btn_Stop);

		gcn::WLabel *wlabel_playTime = new gcn::WLabel();
		wlabel_playTime->setId("wlabel_playTime");
		wlabel_playTime->setBaseColor(gcn::Color(0,0,0,150));
		wlabel_playTime->setForegroundColor(gcn::Color(255,255,255,255));
		wlabel_playTime->setPosition(btn_Stop->getX() + btn_Stop->getWidth()+5,progressBar->getY());
		top->add(wlabel_playTime);

		gcn::WLabel *wlabel_playPos = new gcn::WLabel();
		wlabel_playPos->setId("wlabel_playPos");
		wlabel_playPos->setBaseColor(gcn::Color(0,0,0,150));
		wlabel_playPos->setForegroundColor(gcn::Color(255,255,255,255));
		wlabel_playPos->setPosition(wlabel_playTime->getX(),wlabel_playTime->getY()+15);
		top->add(wlabel_playPos);

		gcn::Button *btn_Save = new gcn::Button("Save");
		btn_Save->setId("btn_Save");
		btn_Save->setSize(btn_Pause->getWidth()*2,btn_Pause->getHeight());
		btn_Save->setPosition(top->getWidth() - btn_Save->getWidth()-5, top->getHeight()-btn_Save->getHeight()-5);
		btn_Save->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_Save, this, "btn_Save", sora::RESPONSEACTION);
		top->add(btn_Save);



		Timeline *timeline = new Timeline();
		gcn::SoraGUIFont *soraFont = new gcn::SoraGUIFont(L"arial.ttf",12);
		timeline->setFont(soraFont);
		timeline->setId("timeline_TimeLine");
		//timeline->setSize(500,80);
		//timeline->setPosition(700,0);
		timeline->setSize(1100,80);
		timeline->setPosition(20,635);
		timeline->setBackgroundColor(gcn::Color(0,0,0,120));
		timeline->setForegroundColor(gcn::Color(255,255,255,255));
		timeline->setMaxGridHeightFactor(0.2);
		top->add(timeline);

		gcn::Button *btn_TimeLine_wider = new gcn::Button("-");
		btn_TimeLine_wider->setId("btn_TimeLine_wider");
		btn_TimeLine_wider->setSize(20,20);
		btn_TimeLine_wider->setPosition(timeline->getX()+timeline->getWidth()+5,timeline->getY());
		btn_TimeLine_wider->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_wider, this, "btn_TimeLine_wider", sora::RESPONSEACTION);
		top->add(btn_TimeLine_wider);

		gcn::Button *btn_TimeLine_tighter = new gcn::Button("+");
		btn_TimeLine_tighter->setId("btn_TimeLine_tighter");
		btn_TimeLine_tighter->setSize(20,20);
		btn_TimeLine_tighter->setPosition(btn_TimeLine_wider->getX(),btn_TimeLine_wider->getY()+btn_TimeLine_wider->getHeight()+5);
		btn_TimeLine_tighter->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_tighter, this, "btn_TimeLine_tighter", sora::RESPONSEACTION);
		top->add(btn_TimeLine_tighter);

		gcn::Button *btn_TimeLine_deeper = new gcn::Button("��");
		btn_TimeLine_deeper->setId("btn_TimeLine_deeper");
		btn_TimeLine_deeper->setSize(20,20);
		btn_TimeLine_deeper->setPosition(btn_TimeLine_wider->getX()+btn_TimeLine_wider->getWidth()+5,btn_TimeLine_wider->getY());
		btn_TimeLine_deeper->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_deeper, this, "btn_TimeLine_deeper", sora::RESPONSEACTION);
		top->add(btn_TimeLine_deeper);

		gcn::Button *btn_TimeLine_lighter = new gcn::Button("��");
		btn_TimeLine_lighter->setId("btn_TimeLine_lighter");
		btn_TimeLine_lighter->setSize(20,20);
		btn_TimeLine_lighter->setPosition(btn_TimeLine_deeper->getX(),btn_TimeLine_deeper->getY()+btn_TimeLine_deeper->getHeight()+5);
		btn_TimeLine_lighter->setForegroundColor(gcn::Color(255,255,255,255));
		sora::SoraGUI::Instance()->registerGUIResponser(btn_TimeLine_lighter, this, "btn_TimeLine_lighter", sora::RESPONSEACTION);
		top->add(btn_TimeLine_lighter);

#pragma endregion Play Control And Timeline Widget

#pragma region Layer Toggle

		gcn::WCheckBox *wcheckbox_showNote = new gcn::WCheckBox(L"Show Note");
		wcheckbox_showNote->setId("wcheckbox_showNote");
		wcheckbox_showNote->adjustSize();
		wcheckbox_showNote->setPosition(container_ToolBar->getX()+container_ToolBar->getWidth()+5,5);
		wcheckbox_showNote->setBaseColor(gcn::Color(0,0,0,150));
		wcheckbox_showNote->setForegroundColor(gcn::Color(255,255,255,255));
		wcheckbox_showNote->setCheckForeGroundColor(gcn::Color(0,0,0,255));
		sora::SoraGUI::Instance()->registerGUIResponser(wcheckbox_showNote, this, "wcheckbox_showNote", sora::RESPONSEACTION);
		top->add(wcheckbox_showNote);

		gcn::WCheckBox *wcheckbox_showGrid = new gcn::WCheckBox(L"Show Grid");
		wcheckbox_showGrid->setId("wcheckbox_showGrid");
		wcheckbox_showGrid->adjustSize();
		wcheckbox_showGrid->setPosition(wcheckbox_showNote->getX(),wcheckbox_showNote->getY()+wcheckbox_showNote->getHeight()+5);
		wcheckbox_showGrid->setBaseColor(gcn::Color(0,0,0,150));
		wcheckbox_showGrid->setForegroundColor(gcn::Color(255,255,255,255));
		wcheckbox_showGrid->setCheckForeGroundColor(gcn::Color(0,0,0,255));
		sora::SoraGUI::Instance()->registerGUIResponser(wcheckbox_showGrid, this, "wcheckbox_showGrid", sora::RESPONSEACTION);
		top->add(wcheckbox_showGrid);

		gcn::WCheckBox *wcheckbox_showBackground = new gcn::WCheckBox(L"Show Background");
		wcheckbox_showBackground->setId("wcheckbox_showBackground");
		wcheckbox_showBackground->adjustSize();
		wcheckbox_showBackground->setPosition(wcheckbox_showGrid->getX(),wcheckbox_showGrid->getY()+wcheckbox_showGrid->getHeight()+5);
		wcheckbox_showBackground->setBaseColor(gcn::Color(0,0,0,150));
		wcheckbox_showBackground->setForegroundColor(gcn::Color(255,255,255,255));
		wcheckbox_showBackground->setCheckForeGroundColor(gcn::Color(0,0,0,255));
		sora::SoraGUI::Instance()->registerGUIResponser(wcheckbox_showBackground, this, "wcheckbox_showBackground", sora::RESPONSEACTION);
		top->add(wcheckbox_showBackground);

#pragma endregion Layer Toggle

#pragma region Note Placement State

		gcn::WLabel *wlabel_nowPlaceNoteCategory = new gcn::WLabel();
		wlabel_nowPlaceNoteCategory->setId("wlabel_nowPlaceNoteCategory");
		wlabel_nowPlaceNoteCategory->setPosition(wcheckbox_showBackground->getX(),wcheckbox_showBackground->getY()+wcheckbox_showBackground->getHeight()+10);
		wlabel_nowPlaceNoteCategory->setBaseColor(gcn::Color(0,0,0,150));
		wlabel_nowPlaceNoteCategory->setForegroundColor(gcn::Color(255,255,255,255));
		top->add(wlabel_nowPlaceNoteCategory);
		

#pragma endregion Note Placement State

		container_Categories[State::TIMELINE] = initTimelineCategory();
		container_Categories[State::NOTE] = initNoteCategory();
		container_Categories[State::SHOW] = initShowCategory();
		container_Categories[State::PREVIEW] = initPlayCategory();



		for (std::map<State,gcn::Container*>::iterator i=container_Categories.begin();i!=container_Categories.end();i++)
		{
			top->add(i->second);
			top->moveToBottom(i->second);
		}


		Task task;
		task.setAsMemberFunc(&DivaEditorMainScene::flowDidEnd, this);
		CORE_FLOW_PTR->registerEndCallback(task);

		ChangeState(State::TIMELINE);

		rhythm_LastPos=0;
	}

	void DivaEditorMainScene::ChangeState(State state)
	{
		if(container_Categories.find(state)==container_Categories.end())
			return;
		for (std::map<State,gcn::Container*>::iterator i=container_Categories.begin();i!=container_Categories.end();i++)
			i->second->setVisible(false);
		container_Categories[state]->setVisible(true);
		nowState=state;

		EDITCONFIG->display_grid=true;
		EDITCONFIG->display_note=true;
		EDITCONFIG->display_background=true;

		gcn::WLabel *wlabel_nowPlaceNoteCategory = (gcn::WLabel*)top->findWidgetById("wlabel_nowPlaceNoteCategory");
		wlabel_nowPlaceNoteCategory->setVisible(false);

		if(nowState==State::TIMELINE)
		{
			EDITCONFIG->display_grid=false;
		}
		else if(nowState==State::NOTE)
		{
			wlabel_nowPlaceNoteCategory->setVisible(true);
		}
		else if(nowState==State::SHOW)
		{
			EDITCONFIG->display_grid=false;
			EDITCONFIG->display_note=false;
			refreshResourcePanelDetail();
			refreshEventDetail();
		}
		else if(nowState==State::PREVIEW)
		{
			EDITCONFIG->display_grid=false;
		}
		
		((divacore::EditMode*)CORE_PTR->getGameMode())->setPlayble(nowState==State::PREVIEW);

	}

	void DivaEditorMainScene::onUpdate(float dt)
	{
		//Play rhythm sound
		double thisPosition = CORE_PTR->getRunPosition();
		
		if(nowState == TIMELINE && CORE_FLOW_PTR->getState() == CoreFlow::RUN)
		{
			int beatCrossNum = EDITOR_PTR->mapData->getCrossAStandardBeatPos(rhythm_LastPos,thisPosition);
			if(beatCrossNum)
				CORE_PTR->getMusicManager()->playDirectWithFile("Data/tick_" + iToS(beatCrossNum) + ".wav",true);
		}
		rhythm_LastPos = thisPosition;



		gcn::WCheckBox *wcheckbox_showNote = (gcn::WCheckBox*)top->findWidgetById("wcheckbox_showNote");
		gcn::WCheckBox *wcheckbox_showGrid = (gcn::WCheckBox*)top->findWidgetById("wcheckbox_showGrid");
		gcn::WCheckBox *wcheckbox_showBackground = (gcn::WCheckBox*)top->findWidgetById("wcheckbox_showBackground");
		wcheckbox_showNote->setSelected(EDITCONFIG->display_note);
		wcheckbox_showGrid->setSelected(EDITCONFIG->display_grid);
		wcheckbox_showBackground->setSelected(EDITCONFIG->display_background);

		gcn::WLabel *wlabel_playTime = (gcn::WLabel*)top->findWidgetById("wlabel_playTime");
		wlabel_playTime->setCaption( secondToTimeWstr(CORE_PTR->getRunTime()) + L'/' + secondToTimeWstr(CORE_FLOW_PTR->getTotalTime()));
		wlabel_playTime->adjustSize();

		gcn::WLabel *wlabel_playPos = (gcn::WLabel*)top->findWidgetById("wlabel_playPos");
		wlabel_playPos->setCaption(iToWS(CORE_PTR->getRunPosition()) + L'/' + iToWS(CORE_FLOW_PTR->getTotalPosition())+L" pos");
		wlabel_playPos->adjustSize();

		if(nowState==TIMELINE)
		{
			gcn::WTextField* txtField_timeline_BPM = (gcn::WTextField*)container_Categories[nowState]->findWidgetById("txtField_timeline_BPM");
			gcn::WTextField* txtField_timeline_offSet = (gcn::WTextField*)container_Categories[nowState]->findWidgetById("txtField_timeline_offSet");
			gcn::WTextField* txtField_timeline_Stop = (gcn::WTextField*)container_Categories[nowState]->findWidgetById("txtField_timeline_Stop");
			gcn::WTextField* txtField_timeline_BeatNum = (gcn::WTextField*)container_Categories[nowState]->findWidgetById("txtField_timeline_BeatNum");
			gcn::WTextField* txtField_timeline_TailSpeed = (gcn::WTextField*)container_Categories[nowState]->findWidgetById("txtField_timeline_TailSpeed");

			gcn::Button* btn_TimeLine_changeOffset = (gcn::Button*)container_Categories[nowState]->findWidgetById("btn_TimeLine_changeOffset");

			gcn::Button* btn_TimeLine_changeBPM = (gcn::Button*)container_Categories[nowState]->findWidgetById("btn_TimeLine_changeBPM");
			gcn::Button* btn_TimeLine_insertBPM = (gcn::Button*)container_Categories[nowState]->findWidgetById("btn_TimeLine_insertBPM");
			gcn::Button* btn_TimeLine_deleteBPM = (gcn::Button*)container_Categories[nowState]->findWidgetById("btn_TimeLine_deleteBPM");

			gcn::Button* btn_TimeLine_changeStop = (gcn::Button*)container_Categories[nowState]->findWidgetById("btn_TimeLine_changeStop");
			gcn::Button* btn_TimeLine_insertStop = (gcn::Button*)container_Categories[nowState]->findWidgetById("btn_TimeLine_insertStop");
			gcn::Button* btn_TimeLine_deleteStop = (gcn::Button*)container_Categories[nowState]->findWidgetById("btn_TimeLine_deleteStop");

			gcn::Button* btn_TimeLine_changeBeatNum = (gcn::Button*)container_Categories[nowState]->findWidgetById("btn_TimeLine_changeBeatNum");
			gcn::Button* btn_TimeLine_deleteBeatNum = (gcn::Button*)container_Categories[nowState]->findWidgetById("btn_TimeLine_deleteBeatNum");

			gcn::Button* btn_TimeLine_changeTailSpeed = (gcn::Button*)container_Categories[nowState]->findWidgetById("btn_TimeLine_changeTailSpeed");

			if(!(txtField_timeline_BPM->isFocused()||btn_TimeLine_changeBPM->isFocused()||btn_TimeLine_insertBPM->isFocused()||btn_TimeLine_deleteBPM->isFocused()))
			{
				txtField_timeline_BPM->setText(fTows(EDITOR_PTR->mapData->getBPM(CORE_PTR->getRunPosition()),2));
			}
			if(!(txtField_timeline_offSet->isFocused()||btn_TimeLine_changeOffset->isFocused()))
			{
				txtField_timeline_offSet->setText(iToWS(EDITOR_PTR->mapData->getOffset()));
			}
			if(!(txtField_timeline_Stop->isFocused()||btn_TimeLine_changeStop->isFocused()||btn_TimeLine_insertStop->isFocused()||btn_TimeLine_deleteStop->isFocused()))
			{
				txtField_timeline_Stop->setText(iToWS(EDITOR_PTR->mapData->getStop(CORE_PTR->getRunPosition())));
			}
			if(EDITOR_PTR->mapData->getStop(CORE_PTR->getRunPosition())!=0)
			{
				btn_TimeLine_insertStop->setVisible(false);
				btn_TimeLine_changeStop->setVisible(true);
				btn_TimeLine_deleteStop->setVisible(true);
			}
			else
			{
				btn_TimeLine_insertStop->setVisible(true);
				btn_TimeLine_changeStop->setVisible(false);
				btn_TimeLine_deleteStop->setVisible(false);
			}
			if(!(txtField_timeline_BeatNum->isFocused()||btn_TimeLine_changeBeatNum->isFocused()||btn_TimeLine_deleteBeatNum->isFocused()))
			{
				txtField_timeline_BeatNum->setText(iToWS(EDITOR_PTR->mapData->getBeatNum(CORE_PTR->getRunPosition())));
			}
			if(!(txtField_timeline_TailSpeed->isFocused()||btn_TimeLine_changeTailSpeed->isFocused()))
			{
				txtField_timeline_TailSpeed->setText(fTows(EDITOR_PTR->mapData->coreInfoPtr->header.speedScale,1));
			}
		}
		else if(nowState==NOTE)
		{
			gcn::WLabel *wlabel_nowPlaceNoteCategory = (gcn::WLabel*)top->findWidgetById("wlabel_nowPlaceNoteCategory");

			if(EDITCONFIG->EDITSTATE_NOTESTATE == EditorConfig::NORMAL)
				wlabel_nowPlaceNoteCategory->setCaption(L"Normal Note");
			else if(EDITCONFIG->EDITSTATE_NOTESTATE == EditorConfig::LONG)
				wlabel_nowPlaceNoteCategory->setCaption(L"Long Note");
			else if(EDITCONFIG->EDITSTATE_NOTESTATE == EditorConfig::COMBO)
				wlabel_nowPlaceNoteCategory->setCaption(L"Combo Note");
			
			wlabel_nowPlaceNoteCategory->adjustSize();
		}
		else if(nowState==SHOW)
		{
			ResourcePanel *resourcePanel = (ResourcePanel*)container_Categories[nowState]->findWidgetById("resourcePanel");
			

			gcn::Label *label_resourcePageNum = (gcn::Label*)container_Categories[nowState]->findWidgetById("label_resourcePageNum");
			label_resourcePageNum->setCaption(iToS(resourcePanel->_nowPage+1)+"/"+iToS((EDITOR_PTR->mapData->coreInfoPtr->resources.size()-1)/resourcePanel->_gridPerPage+1));
			
			

			if(resourcePanel->getSelectedIndex()!=-1)
			{
				gcn::WTextField *wtextField_resourceDetail_fileLabelValue = (gcn::WTextField*)container_Categories[nowState]->findWidgetById("wtextField_resourceDetail_fileLabelValue");
				if(!wtextField_resourceDetail_fileLabelValue->isFocused())
					wtextField_resourceDetail_fileLabelValue->setText(EDITOR_PTR->mapData->getResourceDescriptionByIndex(resourcePanel->getSelectedIndex()));

				std::string selectedResourceID = EDITOR_PTR->mapData->findResourceIDByIndex(resourcePanel->getSelectedIndex());

				gcn::WListBox *wlistbox_resourceDetail_fileEventsValue = (WListBox*)container_Categories[State::SHOW]->findWidgetById("wlistbox_resourceDetail_fileEventsValue");
				gcn::WTextField *wtextField_resourceDetail_fileEventsPosition = (gcn::WTextField*)container_Categories[nowState]->findWidgetById("wtextField_resourceDetail_fileEventsPosition");

				if(wlistbox_resourceDetail_fileEventsValue->getSelected()!=-1 && !wtextField_resourceDetail_fileEventsPosition->isFocused())
				{
					wtextField_resourceDetail_fileEventsPosition->setText( iToWS(EDITOR_PTR->mapData->coreInfoPtr->events[
						EDITOR_PTR->mapData->findResourceEventIndexByIndexInResource(wlistbox_resourceDetail_fileEventsValue->getSelected(),
							selectedResourceID)].position) );
				}
			}
		}
	}

	void DivaEditorMainScene::willAppear()
	{
		top->setEnabled(true);
		GCN_GLOBAL->setTop(top);

		didAppear(top);
	}
	void DivaEditorMainScene::didAppear(gcn::Widget *widget)
	{
		if(Appeared)
			Appeared(this);
	}
	void DivaEditorMainScene::willDisappear()
	{
		
	}
	void DivaEditorMainScene::didDisappear(gcn::Widget *widget)
	{
		if(Disappeared)
			Disappeared(this);
	}

	void DivaEditorMainScene::action() 
	{
		gcn::Widget *actionWidget = top->findWidgetById(getID());

#pragma region Playback Control

		if(getID()=="btn_Play")
		{
			if(CORE_FLOW_PTR->getState()==CoreFlow::PAUSE)
				CORE_PTR->resume();
			else if(CORE_FLOW_PTR->getState()==CoreFlow::RUN)
				EditUtility.setPosition(0);
			
		}
		else if(getID()=="btn_Pause")
		{
			if(CORE_FLOW_PTR->getState() == CoreFlow::RUN)
				CORE_PTR->pause();
			else if(CORE_FLOW_PTR->getState() == CoreFlow::PAUSE)
				CORE_PTR->resume();
		}
		else if(getID()=="btn_Stop")
		{
			CORE_PTR->pause();
			EditUtility.setPosition(0);
		}

#pragma endregion Playback Control

#pragma region Category Change

		else if(getID() == "btn_TimeLine") 
		{
			ChangeState(State::TIMELINE);
		}
		else if(getID() == "btn_Note")
		{
			ChangeState(State::NOTE);
		}
		else if(getID() == "btn_Show")
		{
			ChangeState(State::SHOW);
		}
		else if(getID()=="btn_Category_Play")
		{
			ChangeState(State::PREVIEW);
		}
#pragma endregion Category Change

#pragma region TimeLine Widget Control

		else if(getID() == "btn_TimeLine_wider")
		{
			EDITCONFIG->increaseShowRangeScale();
		}
		else if(getID() == "btn_TimeLine_tighter")
		{
			EDITCONFIG->decreaseShowRangeScale();
		}
		else if(getID() == "btn_TimeLine_deeper")
		{
			EDITCONFIG->increaseGridToShowPerBeat();
		}
		else if(getID() == "btn_TimeLine_lighter")
		{
			EDITCONFIG->decreaseGridToShowPerBeat();
		}

#pragma endregion TimeLine Widget Control

#pragma region Timeline Category Actions

		//BPM
		else if(getID() == "txtField_timeline_BPM" || getID() == "btn_TimeLine_changeBPM")
		{			
			EDITOR_PTR->mapData->bpm_change(CORE_PTR->getRunPosition(), ((WTextField*)container_Categories[State::TIMELINE]->findWidgetById("txtField_timeline_BPM"))->getFloat());
			actionWidget->setFocusable(false);
			actionWidget->setFocusable(true);
		}
		else if(getID() == "btn_TimeLine_insertBPM")
		{
			EDITOR_PTR->mapData->bpm_insert(CORE_PTR->getRunPosition(), ((WTextField*)container_Categories[State::TIMELINE]->findWidgetById("txtField_timeline_BPM"))->getFloat());
			actionWidget->setFocusable(false);
			actionWidget->setFocusable(true);
		}
		else if(getID() == "btn_TimeLine_deleteBPM")
		{
			EDITOR_PTR->mapData->bpm_delete(CORE_PTR->getRunPosition());
			actionWidget->setFocusable(false);
			actionWidget->setFocusable(true);
		}

		//Stop
		else if(getID() == "btn_TimeLine_changeStop" || (getID() == "txtField_timeline_Stop" && container_Categories[State::TIMELINE]->findWidgetById("btn_TimeLine_changeStop")->isVisible()))
		{
			EDITOR_PTR->mapData->stop_change(CORE_PTR->getRunPosition(), ((WTextField*)container_Categories[State::TIMELINE]->findWidgetById("txtField_timeline_Stop"))->getFloat());
			actionWidget->setFocusable(false);
			actionWidget->setFocusable(true);
		}
		else if(getID() == "btn_TimeLine_insertStop" || (getID() == "txtField_timeline_Stop" && container_Categories[State::TIMELINE]->findWidgetById("btn_TimeLine_insertStop")->isVisible()))
		{
			EDITOR_PTR->mapData->stop_insert(CORE_PTR->getRunPosition(), ((WTextField*)container_Categories[State::TIMELINE]->findWidgetById("txtField_timeline_Stop"))->getFloat());
			actionWidget->setFocusable(false);
			actionWidget->setFocusable(true);
		}
		else if(getID() == "btn_TimeLine_deleteStop")
		{
			EDITOR_PTR->mapData->stop_delete(CORE_PTR->getRunPosition());
			actionWidget->setFocusable(false);
			actionWidget->setFocusable(true);
		}

		//Offset
		else if(getID() == "txtField_timeline_offSet" || getID() == "btn_TimeLine_changeOffset")
		{
			int thisOffset = ((WTextField*)container_Categories[State::TIMELINE]->findWidgetById("txtField_timeline_offSet"))->getFloat();
			EDITOR_PTR->mapData->offset_set(thisOffset, true);
			actionWidget->setFocusable(false);
			actionWidget->setFocusable(true);
		}

		//BeatNum
		else if(getID() == "txtField_timeline_BeatNum" || getID() == "btn_TimeLine_changeBeatNum")
		{			
			EDITOR_PTR->mapData->beatNum_change(CORE_PTR->getRunPosition(), ((WTextField*)container_Categories[State::TIMELINE]->findWidgetById("txtField_timeline_BeatNum"))->getFloat());
			actionWidget->setFocusable(false);
			actionWidget->setFocusable(true);
		}
		else if(getID() == "btn_TimeLine_deleteBeatNum")
		{
			EDITOR_PTR->mapData->beatNum_delete(CORE_PTR->getRunPosition());
			actionWidget->setFocusable(false);
			actionWidget->setFocusable(true);
		}

		//Tail Speed
		else if(getID() == "txtField_timeline_TailSpeed" || getID() == "btn_TimeLine_changeTailSpeed")
		{
			EDITOR_PTR->mapData->tailSpeed_change(((WTextField*)container_Categories[State::TIMELINE]->findWidgetById("txtField_timeline_TailSpeed"))->getFloat());
			actionWidget->setFocusable(false);
			actionWidget->setFocusable(true);
		}

#pragma endregion Timeline Category Actions

#pragma region Show Category Actions

		else if(getID() == "btn_resourceLeftPage")
		{
			((ResourcePanel*)container_Categories[State::SHOW]->findWidgetById("resourcePanel"))->prevPage();
		}
		else if(getID() == "btn_resourceRightPage")
		{
			((ResourcePanel*)container_Categories[State::SHOW]->findWidgetById("resourcePanel"))->nextPage();
		}
		else if(getID() == "btn_resourceAdd")
		{
			//Should get back current working directory
			wchar_t cwd[_MAX_PATH];
			_wgetcwd(cwd,_MAX_PATH);

			wstring selectFile = sora::SoraCore::Instance()->fileOpenDialogW(L"All Files(*.*)\0*.*\0");

			_wchdir(cwd);

			if(selectFile!=L"")
			{
				((ResourcePanel*)container_Categories[State::SHOW]->findWidgetById("resourcePanel"))->setSelectedIndex(
																				EDITOR_PTR->mapData->findResourceIndexByID(EDITOR_PTR->mapData->resource_add(selectFile)));
			}
		}
		else if(getID() == "btn_resourceRemove")
		{
			ResourcePanel *resourcePanel = (ResourcePanel*)container_Categories[State::SHOW]->findWidgetById("resourcePanel");
			if(resourcePanel->getSelectedIndex()!=-1)
			{
				EDITOR_PTR->mapData->resource_delete( EDITOR_PTR->mapData->findResourceIDByIndex(resourcePanel->getSelectedIndex()));
				((ResourcePanel*)container_Categories[State::SHOW]->findWidgetById("resourcePanel"))->setSelectedIndex(-1);
			}
		}
		else if(getID() == "wtextField_resourceDetail_fileLabelValue")
		{
			ResourcePanel *resourcePanel = (ResourcePanel*)container_Categories[State::SHOW]->findWidgetById("resourcePanel");
			gcn::WTextField *wtextFiled_resourceDetail_fileLabelValue = (gcn::WTextField*)container_Categories[State::SHOW]->findWidgetById("wtextField_resourceDetail_fileLabelValue");
			EDITOR_PTR->mapData->resourceDescription_modify(EDITOR_PTR->mapData->findResourceIDByIndex(resourcePanel->getSelectedIndex()),wtextFiled_resourceDetail_fileLabelValue->getText());
			actionWidget->setFocusable(false);
			actionWidget->setFocusable(true);
		}
		else if(getID() == "btn_resourceDetail_addFileEvent")
		{
			ResourcePanel *resourcePanel = (ResourcePanel*)container_Categories[State::SHOW]->findWidgetById("resourcePanel");
			if(resourcePanel->getSelectedIndex()!=-1)
			{
				EDITOR_PTR->mapData->resourceEvent_add(CORE_PTR->getRunPosition(),EDITOR_PTR->mapData->findResourceIDByIndex(resourcePanel->getSelectedIndex()));
				refreshResourcePanelDetail();
				refreshEventDetail();
				EditUtility.refreshAll();
			}
		}
		else if(getID() == "btn_resourceDetail_removeFileEvent")
		{
			ResourcePanel *resourcePanel = (ResourcePanel*)container_Categories[State::SHOW]->findWidgetById("resourcePanel");
			gcn::WListBox *wlistbox_resourceDetail_fileEventsValue = (WListBox*)container_Categories[State::SHOW]->findWidgetById("wlistbox_resourceDetail_fileEventsValue");

			if(wlistbox_resourceDetail_fileEventsValue->getSelected()>=0)
			{
				EDITOR_PTR->mapData->resourceEvent_delete( EDITOR_PTR->mapData->findResourceEventIndexByIndexInResource(
																					wlistbox_resourceDetail_fileEventsValue->getSelected(),
																					EDITOR_PTR->mapData->findResourceIDByIndex(resourcePanel->getSelectedIndex())) );
				refreshResourcePanelDetail();
				refreshEventDetail();
				EditUtility.refreshAll();
			}
		}
		else if(getID() == "wtextField_resourceDetail_fileEventsPosition")
		{
			gcn::WTextField *wtextField_resourceDetail_fileEventsPosition = (gcn::WTextField*)container_Categories[State::SHOW]->findWidgetById("wtextField_resourceDetail_fileEventsPosition");
			ResourcePanel *resourcePanel = (ResourcePanel*)container_Categories[State::SHOW]->findWidgetById("resourcePanel");
			gcn::WListBox *wlistbox_resourceDetail_fileEventsValue = (gcn::WListBox*)container_Categories[State::SHOW]->findWidgetById("wlistbox_resourceDetail_fileEventsValue");

			if(resourcePanel->getSelectedIndex()!=-1&&wlistbox_resourceDetail_fileEventsValue->getSelected()!=-1)
			{
				std::string selectedResourceID = EDITOR_PTR->mapData->findResourceIDByIndex(resourcePanel->getSelectedIndex());
				EDITOR_PTR->mapData->resourceEvent_modifyPos(EDITOR_PTR->mapData->findResourceEventIndexByIndexInResource(wlistbox_resourceDetail_fileEventsValue->getSelected(),selectedResourceID),
																wtextField_resourceDetail_fileEventsPosition->getFloat());
				refreshResourcePanelDetail();
				EditUtility.reCaltTime();
				EditUtility.refreshAll();
			}

			actionWidget->setFocusable(false);
			actionWidget->setFocusable(true);
		}
#pragma endregion Show Category Actions

#pragma region Layer Display Toggle
		else if(getID()=="wcheckbox_showNote")
		{
			gcn::WCheckBox *wcheckbox_showNote = (gcn::WCheckBox*)top->findWidgetById("wcheckbox_showNote");
			EDITCONFIG->display_note = wcheckbox_showNote->isSelected();
		}
		else if(getID()=="wcheckbox_showGrid")
		{
			gcn::WCheckBox *wcheckbox_showGrid = (gcn::WCheckBox*)top->findWidgetById("wcheckbox_showGrid");
			EDITCONFIG->display_grid = wcheckbox_showGrid->isSelected();
			if(EDITCONFIG->display_grid)
				EDITCONFIG->display_background=true;
		}
		else if(getID()=="wcheckbox_showBackground")
		{
			gcn::WCheckBox *wcheckbox_showBackground = (gcn::WCheckBox*)top->findWidgetById("wcheckbox_showBackground");
			EDITCONFIG->display_background = wcheckbox_showBackground->isSelected();
			if(!EDITCONFIG->display_background)
				EDITCONFIG->display_grid=false;
		}

#pragma endregion Layer Display Toggle

#pragma region Editor Controls
		
		else if(getID() == "btn_Save")
		{
			EDITOR_PTR->mapData->SaveFile();
		}

#pragma endregion Editor Controls
	}
	
	void DivaEditorMainScene::refreshResourcePanelDetail()
	{
		ResourcePanel *resourcePanel = (ResourcePanel*)container_Categories[State::SHOW]->findWidgetById("resourcePanel");
		gcn::BoarderedContainer *resourceDetailContainer = (gcn::BoarderedContainer*)container_Categories[State::SHOW]->findWidgetById("resourceDetailContainer");

		gcn::WListBox *wlistbox_resourceDetail_fileEventsValue = (gcn::WListBox*)container_Categories[State::SHOW]->findWidgetById("wlistbox_resourceDetail_fileEventsValue");
		wlistbox_resourceDetail_fileEventsValue->getListModel()->clearElements();

		if(resourcePanel->getSelectedIndex()!=-1)
		{
			resourceDetailContainer->setVisible(true);
			std::string selectedResourceID = EDITOR_PTR->mapData->findResourceIDByIndex(resourcePanel->getSelectedIndex());

			gcn::WLabel *wlabel_resourceDetail_filePath = (gcn::WLabel*)container_Categories[State::SHOW]->findWidgetById("wlabel_resourceDetail_filePath");
			gcn::WLabel *wlabel_resourceDetail_filePathValue = (gcn::WLabel*)container_Categories[State::SHOW]->findWidgetById("wlabel_resourceDetail_filePathValue");
			wlabel_resourceDetail_filePathValue->setCaption(EDITOR_PTR->mapData->coreInfoPtr->resources[selectedResourceID].filePath);
			wlabel_resourceDetail_filePathValue->adjustSize();
			wlabel_resourceDetail_filePathValue->setPosition(wlabel_resourceDetail_filePath->getX()+wlabel_resourceDetail_filePath->getWidth(),wlabel_resourceDetail_filePath->getY());

			gcn::WLabel *wlabel_resourceDetail_fileType = (gcn::WLabel*)container_Categories[State::SHOW]->findWidgetById("wlabel_resourceDetail_fileType");
			gcn::WLabel *wlabel_resourceDetail_fileTypeValue = (gcn::WLabel*)container_Categories[State::SHOW]->findWidgetById("wlabel_resourceDetail_fileTypeValue");
			wlabel_resourceDetail_fileTypeValue->setCaption(sora::s2ws(EDITOR_PTR->mapData->findResourceTypeStrByID(selectedResourceID)));
			wlabel_resourceDetail_fileTypeValue->adjustSize();
			wlabel_resourceDetail_fileTypeValue->setPosition(wlabel_resourceDetail_fileType->getX()+wlabel_resourceDetail_fileType->getWidth(),wlabel_resourceDetail_fileType->getY());

			gcn::WTextField *wtextField_resourceDetail_fileLabelValue = (gcn::WTextField*)container_Categories[State::SHOW]->findWidgetById("wtextField_resourceDetail_fileLabelValue");
			wtextField_resourceDetail_fileLabelValue->setText(EDITOR_PTR->mapData->getResourceDescriptionByIndex(resourcePanel->getSelectedIndex()));


			for (int i=0;i<EDITOR_PTR->mapData->coreInfoPtr->events.size();i++)
			{
				divacore::MapEvent &thisEvent = EDITOR_PTR->mapData->coreInfoPtr->events[i];
				if(thisEvent.eventType == "playVideo" || thisEvent.eventType == "displayImage" || thisEvent.eventType == "playMusic")
					if(Argument::asString("id",thisEvent.arg)==selectedResourceID)
						wlistbox_resourceDetail_fileEventsValue->getListModel()->pushElement(sora::s2ws(thisEvent.eventType) + L" at pos " + iToWS(thisEvent.position));
			}
			wlistbox_resourceDetail_fileEventsValue->adjustSize();

			gcn::Button *btn_resourceDetail_addFileEvent = (gcn::Button*)container_Categories[State::SHOW]->findWidgetById("btn_resourceDetail_addFileEvent");
			gcn::Button *btn_resourceDetail_removeFileEvent = (gcn::Button*)container_Categories[State::SHOW]->findWidgetById("btn_resourceDetail_removeFileEvent");

			btn_resourceDetail_addFileEvent->setPosition(wlistbox_resourceDetail_fileEventsValue->getX()+5, 
				wlistbox_resourceDetail_fileEventsValue->getY() + wlistbox_resourceDetail_fileEventsValue->getHeight()+5);
			btn_resourceDetail_removeFileEvent->setPosition(btn_resourceDetail_addFileEvent->getX()+btn_resourceDetail_addFileEvent->getWidth()+5, btn_resourceDetail_addFileEvent->getY());
		}
		else
			resourceDetailContainer->setVisible(false);
	}
	void DivaEditorMainScene::refreshEventDetail()
	{
		ResourcePanel *resourcePanel = (ResourcePanel*)container_Categories[State::SHOW]->findWidgetById("resourcePanel");
		gcn::WListBox *wlistbox_resourceDetail_fileEventsValue = (gcn::WListBox*)container_Categories[State::SHOW]->findWidgetById("wlistbox_resourceDetail_fileEventsValue");
		gcn::WTextField *wtextField_resourceDetail_fileEventsPosition = (gcn::WTextField*)container_Categories[State::SHOW]->findWidgetById("wtextField_resourceDetail_fileEventsPosition");
		std::string selectedResourceID = EDITOR_PTR->mapData->findResourceIDByIndex(resourcePanel->getSelectedIndex());

		if(wlistbox_resourceDetail_fileEventsValue->getSelected()>=wlistbox_resourceDetail_fileEventsValue->getListModel()->getNumberOfElements())
		{
			wlistbox_resourceDetail_fileEventsValue->setSelected(-1);
			return;
		}

		if(wlistbox_resourceDetail_fileEventsValue->getSelected()!=-1)
		{
			wtextField_resourceDetail_fileEventsPosition->setVisible(true);

			wtextField_resourceDetail_fileEventsPosition->setText( iToWS(EDITOR_PTR->mapData->coreInfoPtr->events[
				EDITOR_PTR->mapData->findResourceEventIndexByIndexInResource(wlistbox_resourceDetail_fileEventsValue->getSelected(),
					selectedResourceID)].position) );
				wtextField_resourceDetail_fileEventsPosition->setPosition(wlistbox_resourceDetail_fileEventsValue->getX()+wlistbox_resourceDetail_fileEventsValue->getWidth() + 5,
					wlistbox_resourceDetail_fileEventsValue->getY());
		}
		else
			wtextField_resourceDetail_fileEventsPosition->setVisible(false);
	}

	void DivaEditorMainScene::valueChanged(const gcn::SelectionEvent &event)
	{
		if(event.getSource()->getId()=="resourcePanel")
		{
			refreshResourcePanelDetail();
			refreshEventDetail();
		}
		else if(event.getSource()->getId()=="wlistbox_resourceDetail_fileEventsValue")
		{
			refreshEventDetail();
		}
		
	}

	void DivaEditorMainScene::onMouseWheelUp(sora::SoraMouseEvent& event)
	{
		for(int i=event.wheel;i!=0;i--)
		{
			int setTo = EDITOR_PTR->mapData->getPrevStandardGrid(CORE_PTR->getRunPosition(),EDITCONFIG->getGridToShowPerBeat());
			if(setTo<0) setTo=0;
			EditUtility.setPosition(setTo);
		}
	}
	void DivaEditorMainScene::onMouseWheelDown(sora::SoraMouseEvent& event)
	{
		for(int i=abs(event.wheel);i!=0;i--)
		{
			int setTo = EDITOR_PTR->mapData->getNextStandardGrid(CORE_PTR->getRunPosition(),EDITCONFIG->getGridToShowPerBeat());
			if(setTo>CORE_FLOW_PTR->getTotalPosition()) setTo = CORE_FLOW_PTR->getTotalPosition();
			EditUtility.setPosition(setTo);
		}
	}


	void DivaEditorMainScene::onKeyPressed(SoraKeyEvent& event)
	{
		if(event.key == sora::key::Ctrl)
			EDITCONFIG->isctrl=true;

		if(nowState!=State::PREVIEW && event.key == sora::key::Space)
		{
			if(CORE_FLOW_PTR->getState() == CoreFlow::RUN)
				CORE_PTR->pause();
			else
				CORE_PTR->resume();
		}

		if(nowState==State::NOTE)
		{
			NoteArea* noteArea = (NoteArea*)container_Categories[nowState]->findWidgetById("NoteArea");
			noteArea->onKeyPressed(event);
		}
	}
	void DivaEditorMainScene::onKeyReleased(SoraKeyEvent& event)
	{
		if(event.key == sora::key::Ctrl)
			EDITCONFIG->isctrl=false;

		if(nowState==State::NOTE)
		{
			NoteArea* noteArea = (NoteArea*)container_Categories[nowState]->findWidgetById("NoteArea");
			noteArea->onKeyReleased(event);
		}
	}


}