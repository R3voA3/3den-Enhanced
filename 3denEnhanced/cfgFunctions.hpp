class CfgFunctions
{
	class 3denEnhanced
	{
		tag = "ENH";
		class 3DENRadio
		{
			file = "3denEnhanced\functions\GUI\3DENRadio";
			class 3DENRadio_onLoad;
			class 3DENRadio_onUnload;
			class 3DENRadio_exportClassname;
			class 3DENRadio_playMusic;
			class 3DENRadio_toggleRadio;
			class 3DENRadio_handlePlaylist;
			class 3DENRadio_sortBy;
			class 3DENRadio_searchList;
			class 3DENRadio_selectNewSong;
		};
		class Garrison
		{
			file = "3denEnhanced\functions\GUI\garrison";
			class garrison_onLoad;
			class garrison_garrison;
		};
		class Extraction
		{
			file = "3denEnhanced\functions\GUI\extraction";
			class extraction_onLoad;
			class extraction_onCheckedChanged;
			class extraction_setup;
		};
		class TextureFinder
		{
			file = "3denEnhanced\functions\GUI\TextureFinder";
			class textureFinder_updateProgressbar;
			class textureFinder_findTextures;
			class textureFinder_exportTexturePath;
			class textureFinder_fillTextureLB;
			class textureFinder_search;
			class textureFinder_showTexture;
		};
		class BatchReplace
		{
			file = "3denEnhanced\functions\GUI\batchReplace";
			class batchReplace_createDisplay;
			class batchReplace;
		};
		class FunctionsViewer
		{
			file = "3denEnhanced\functions\GUI\functionsViewer";
			class functionsViewer_onLoad;
			class functionsViewer_onTreeSelChanged;
			class functionsViewer_recompileSelected;
			class functionsViewer_copy;
			class functionsViewer_getFunctionsData;
			class functionsViewer_fillCtrlTV;
      class functionsViewer_incrementKey;
      class functionsViewer_searchkey;
		};
		class ActionCreator
		{
			file = "3denEnhanced\functions\GUI\actionCreator";
			class actionCreator_onLoad;
			class actionCreator_export;
		};
		class BriefingEditor
		{
			file = "3denEnhanced\functions\GUI\briefingEditor";
			class briefingEditor_onLoad;
			class briefingEditor_onUnload;
			class briefingEditor_export;
			class briefingEditor_createTemplate;
			class briefingEditor_getTemplate;
			class briefingEditor_onLBSelChanged;
			class briefingEditor_addTAG;
		};
		class PlacementTools
		{
			file = "3denEnhanced\functions\GUI\placementTools";
			class placementTools_onLoad;
			class placementTools_onUnload;
			class placementTools_createDisplay;
			class placementTools_centralAngle;
			class placementTools_fillArea;
			class placementTools_grid;
			class placementTools_radius;
			class placementTools_initialAngle;
			class placementTools_spacing;
			class placementTools_onToolBoxSelChanged;
		};
		class ScenarioAttributesManager
		{
			file = "3denEnhanced\functions\GUI\scenarioAttributesManager";
			class scenarioAttributesManager_onLoad;
			class scenarioAttributesManager_onUnload;
			class scenarioAttributesManager_loadTemplate;
			class scenarioAttributesManager_deleteTemplate;
			class scenarioAttributesManager_applyTemplate;
			class scenarioAttributesManager_createTemplate;
			class scenarioAttributesManager_applyAttribute;
			class scenarioAttributesManager_getScenarioAttributes;
			class scenarioAttributesManager_exportToClipboard;
		};
		class NameObjects
		{
			file = "3denEnhanced\functions\GUI\nameObjects";
			class nameObjects_onLoad;
			class nameObjects_name;
		};
		class ModuleInformation
		{
			file = "3denEnhanced\functions\GUI\moduleInformation";
			class moduleInformation_onLoad;
		};
		class 3DENCam
		{
			file = "3denEnhanced\functions\GUI\3DENCam";
			class 3DENCam_updateList;
			class 3DENCam_deleteEntry;
			class 3DENCam_get3DENCameraParameters;
			class 3DENCam_set3DENCameraParameters;
			class 3DENCam_onKillFocus;
			class 3DENCam_onSetFocus;
			class 3DENCam_saveList;
		};
		class VariableViewer
		{
			file = "3denEnhanced\functions\GUI\variableViewer";
			class variableViewer_onLoad;
			class variableViewer_fillLNB;
			class variableViewer_hideFunctions;
			class variableViewer_messageConfirm;
			class variableViewer_onFilterChanged;
			class variableViewer_onLNBSelChanged;
			class variableViewer_onSearch;
			class variableViewer_setOrCreate;
			class variableViewer_delete;
			class variableViewer_getNamespace;
		};
		class InventoryManager
		{
			file = "3denEnhanced\functions\GUI\inventoryManager";
			class IM_open;
			class IM_addItem;
			class IM_applyAttribute;
			class IM_applyTemplate;
			class IM_clearInventory;
			class IM_createTemplate;
			class IM_deleteTemplate;
			class IM_filterList;
			class IM_lbAdd;
			class IM_lnbAddItem;
			class IM_loadAttributeValue;
			class IM_previewItem;
			class IM_removeItem;
			class IM_search;
			class IM_showTemplates;
			class IM_toggleVirtual;
			class IM_updateTemplateList;
      class IM_onModFilterChanged;
      class IM_resetSearch;
      class IM_resetStorage;
		};
    class CfgSentencesBrowser
		{
			file = "3denEnhanced\functions\GUI\CFGS";
			class CFGS_onLoad;
      class CFGS_changePage;
      class CFGS_changeFilter;
      class CFGS_getCfgSentences;
      class CFGS_getSentenceDataFromConfig;
      class CFGS_handleFavorites;
      class CFGS_playOrCopy;
		};
		class Misc
		{
			file = "3denEnhanced\functions\Misc";
      class sessionTimer;
      class twoDigitsStr;
			class loadoutTool;
			class exportLoadout;
			class measureDistance;
			class switchTime;
			class toggleGrass;
			class deleteCrew;
			class deleteEmptyLayers;
			class removeGear;
			class setOrientation;
			class all3DENSelected;
			class statusbar_entityCounter;
			class exportWithLB;
			class generateSteamMissionDescription;
			class 3denNotificationNoSound;
			class locationList;
			class initAmbientAnimationsInEditor;
			class toggleDrawBuildingPositions;
			class toggleDrawDLCIcons;
			class toggleAttribute;
			class toggleAIFeatures;
			class floatToTime;
			class firstPerson;
			class 3DENCollapseAssetBrowser;
      class hasStorage;
      class exportAttributesToWiki;
      class exportContextMenuToWiki;
      class exportFunctionsToWiki;
      class exportMenuStripToWiki;
      class dynamicViewDistance;
		};
		class Log
		{
			file = "3denEnhanced\functions\log";
			class logPositions3D;
			class logPositions2D;
			class logObjectInfo;
			class logFactions;
			class logGridPosition;
			class log3DENIDs;
			class logClassesString;
		};
		class Debug
		{
			file = "3denEnhanced\functions\debug";
			class productInfo;
			class toggleMapIDs;
			class debugOptions;
			class checkShortCutsDuplicates;
      class activeScripts;
		};
		class EventHandlers
		{
			file = "3denEnhanced\functions\eventHandlers";
			class EH_onMissionLoad;
			class EH_onMissionNew;
			class EH_onMissionPreview;
			class EH_onMissionPreviewEnd;
			class EH_onSelectionChange;
			class EH_onTerrainNew;
		};
		class AttributeControls
		{
			file = "3denEnhanced\functions\attributeControls";
			class groupMarker_onAttributeLoad;
			class groupMarker_onAttributeSave;
			class groupMarker_onButtonDown;
			class ambientAnimations_onAttributeLoad;
			class ambientAnimations_onAttributeSave;
			class ambientAnimations_onButtonDown;
			class establishingShot_onAttributeLoad;
			class establishingShot_onAttributeSave;
			class establishingShot_onButtonDown;
			class featureType_onAttributeLoad;
			class featureType_onAttributeSave;
			class holdAction_onAttributeLoad;
			class holdAction_onAttributeSave;
			class holdAction_onButtonDown;
			class introText_onAttributeLoad;
			class introText_onAttributeSave;
			class introText_onButtonDown;
			class terrainDetail_onAttributeLoad;
			class terrainDetail_onAttributeSave;
			class timeMultiplier_onAttributeLoad;
			class timeMultiplier_onAttributeSave;
			class airdrop_onAttributeLoad;
			class airdrop_onAttributeSave;
			class airdrop_onButtonDown;
			class ambientFlyby_onAttributeLoad;
			class ambientFlyby_onAttributeSave;
			class ambientFlyby_onButtonDown;
			class dynamicSkill_onAttributeLoad;
			class dynamicSkill_onAttributeSave;
			class dynamicSkill_onButtonDown;
			class mapIndicators_onAttributeLoad;
			class mapIndicators_onAttributeSave;
			class missionEndingCasualties_onAttributeLoad;
			class missionEndingCasualties_onAttributeSave;
			class missionEndingCasualties_onButtonDown;
			class missionEnding_onAttributeLoad;
			class missionEnding_onAttributeSave;
			class missionEnding_onButtonDown;
			class taskPatrol_onAttributeLoad;
			class taskPatrol_onAttributeSave;
			class SPR_onAttributeLoad;
			class SPR_onAttributeSave;
			class SPR_onButtonDown;
			class initDebriefingCombo;
		};
	};
};