class CfgFunctions
{
	class 3denEnhanced
	{
		tag = "Enh";
		class 3denRadio
		{
			file = "3denEnhanced\functions\GUI\3denRadio";
			class 3denRadio_onLoad;
			class 3denRadio_onUnload;
			class 3denRadio_exportClassname;
			class 3denRadio_playMusic;
			class 3denRadio_toggleRadio;
			class 3denRadio_handlePlaylist;
			class 3denRadio_sortBy;
			class 3denRadio_searchList;
			class 3denRadio_selectNewSong;
		};
		class Garrison
		{
			file = "3denEnhanced\functions\GUI\garrison";
			class garrison_onLoad;
			class garrison_garrison;
		};
		class TextureFinder
		{
			file = "3denEnhanced\functions\GUI\TextureFinder";
			class textureFinder_updateProgressbar;
			class textureFinder_findTextures;
			class textureFinder_searchState;
			class textureFinder_exportTexturePath;
			class textureFinder_fillTextureLB;
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
			class placementTools_garrison;
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
		class Credits
		{
			file = "3denEnhanced\functions\GUI\credits";
			class credits_onLoad;
		};
		class ModuleInformation
		{
			file = "3denEnhanced\functions\GUI\moduleInformation";
			class moduleInformation_onLoad;
		};
		class Misc
		{
			file = "3denEnhanced\functions\Misc";
			class loadoutTool;
			class exportInventoryConfig;
			class measureDistance;
			class switchTime;
			class toggleGrass;
			class deleteCrew;
			class deleteEmptyLayers;
			class toggleSimpleObject;
			class toggleSimulation;
			class removeGear;
			class reverseOrientation;
			class setOrientation;
			class credits;
			class all3DENSelected;
			class statusbar_entityCounter;
			class exportWithLB;
			class generateSteamMissionDescription;
			class 3denNotificationNoSound;
			class gitHubNotification;
			class locationList;
			class setRandomOrientation;
			class getProfileColor;
			class initAmbientAnimationsInEditor;
		};
		class Log
		{
			file = "3denEnhanced\functions\log";
			class logPositions;
			class logPositions2D;
			class logObjectInfo;
			class logFactions;
			class logGridPosition;
			class log3DENIDs;
		};
		class Debug
		{
			file = "3denEnhanced\functions\debug";
			class productInfo;
			class toggleMapIDs;
			class sessionTimer;
			class onPreviewDebug;
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
			class missionEnding_onAttributeLoad;
			class missionEnding_onAttributeSave;
			class missionEnding_onButtonDown;
		};
	};
};