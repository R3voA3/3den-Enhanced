class CfgFunctions
{
	class 3denEnhanced
	{
		tag = "Enh";
		class Tools
		{
			file = "3denEnhanced\functions\tools";
			class loadoutTool;
			class measureDistance;
			class switchTime;
			class exportInventoryConfig;
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
		class Placement
		{
			file = "3denEnhanced\functions\placement";
			class setRandomDir;
			class garrisonNearest;
			class reverseDirection;
			class setOrientation;
			class patternTool;
			class gridPattern;
			class patternTool_init;
			class gridPattern_onLoad;
		};
		class Debug
		{
			file = "3denEnhanced\functions\debug";
			class productInfo;
			class toggleMapIDs;
			class sessionTimer;
			class onPreviewDebug;
		};
		class BriefingEditor
		{
			file = "3denEnhanced\functions\briefingEditor";
			class briefingEditor_onLoad;
			class briefingEditor_onClose;
			class briefingEditor_export;
			class briefingEditor_addMarker;
			class briefingEditor_addPicture;
			class briefingEditor_addLinebreak;
			class briefingEditor_createTemplate;
			class briefingEditor_getTemplate;
			class briefingEditor_addCustomText;
		};
		class Controls
		{
			file = "3denEnhanced\functions\controls";
			class attributeLoadCombo;
			class attributeSaveCombo;
			class locationList;
		};
		class 3denRadio
		{
			file = "3denEnhanced\functions\3denRadio";
			class 3denRadio_exportClassname;
			class 3denRadio_playMusic;
			class 3denRadio_onLoad;
			class 3denRadio_onClose;
			class 3denRadio_toggleRadio;
			class 3denRadio_handlePlaylist;
			class 3denRadio_sortBy;
			class 3denRadio_toggleHelp;
			class 3denRadio_searchList;
		};
		class ColourPicker
		{
			file = "3denEnhanced\functions\colourPicker";
			class colourPicker_init;
			class colourPicker;
		};
		class TextureFinder
		{
			file = "3denEnhanced\functions\TextureFinder";
			class updateProgressbar;
			class findTextures;
			class searchState;
			class exportTexturePath;
			class fillTextureLB;
		};
		class BatchReplace
		{
			file = "3denEnhanced\functions\batchReplace";
			class batchReplace;
		};
		class Misc
		{
			file = "3denEnhanced\functions\misc";
			class credits;
			class all3DENSelected;
			class numberOfSelectedEntities;
			class importMissionAttributes;
			class exportWithLB;
			class generateSteamMissionDescription;
		};
		class FunctionsViewer
		{
			file = "3denEnhanced\functions\functionsViewer";
			class functionsViewer;
		};
		class ActionCreator
		{
			file = "3denEnhanced\functions\actionCreator";
			class actionCreator_onLoad;
			class actionCreator_export;
		};
	};
};