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
			class 3denRadio_toggleHelp;
			class 3denRadio_searchList;
		};
		class ColourPicker
		{
			file = "3denEnhanced\functions\GUI\colourPicker";
			class colourPicker_onLoad;
			class colourPicker;
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
			class batchReplace;
		};
		class FunctionsViewer
		{
			file = "3denEnhanced\functions\GUI\functionsViewer";
			class functionsViewer;
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
			class briefingEditor_addMarker;
			class briefingEditor_addPicture;
			class briefingEditor_addLinebreak;
			class briefingEditor_createTemplate;
			class briefingEditor_getTemplate;
			class briefingEditor_addCustomText;
		};
		class PlacementTools
		{
			file = "3denEnhanced\functions\GUI\placementTools";
			class placementTools_onLoad;
			class placementTools_onUnload;
			class placementTools_centralAngle;
			class placementTools_fillArea;
			class placementTools_garrison;
			class placementTools_grid;
			class placementTools_radius;
			class placementTools_initialAngle;
			class placementTools_spacing;
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
			class nameObjects;
			class deleteEmptyLayers;
			class moduleInformation;
			class makeObjectSimple;
			class removeNVGs;
			class removeVests;
			class removeGoggles;
			class removeWeapons;
			class removeHeadgear;
			class setRandomDir;
			class reverseDirection;
			class setOrientation;
			class credits;
			class all3DENSelected;
			class numberOfSelectedEntities;
			class importMissionAttributes;
			class exportWithLB;
			class generateSteamMissionDescription;
			class 3denNotificationNoSound;
			class gitHubNotification;
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
			class logMissionAttributes;
		};
		class Debug
		{
			file = "3denEnhanced\functions\debug";
			class productInfo;
			class toggleMapIDs;
			class sessionTimer;
			class onPreviewDebug;
		};
		class Controls
		{
			file = "3denEnhanced\functions\controls";
			class attributeLoadCombo;
			class attributeSaveCombo;
			class locationList;
		};
	};
};