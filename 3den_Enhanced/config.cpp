#include "defines.hpp"
#include "cfgPatches.hpp"
#include "cfg3DEN.hpp"
#include "cfgFunctions.hpp"
#include "display3DEN.hpp"
//Custom GUIs
#include "GUI\Enh_briefingEditor.hpp"
#include "GUI\Enh_3denRadio.hpp"
#include "GUI\Enh_nameObjects.hpp"
#include "GUI\Enh_moduleInformation.hpp"
#include "GUI\Enh_textureFinder.hpp"
#include "GUI\Enh_batchReplace.hpp"
#include "GUI\Enh_functionsViewer.hpp"
#include "GUI\Enh_actionCreator.hpp"
#include "GUI\Enh_credits.hpp"
#include "GUI\Enh_placementTools.hpp"
#include "GUI\Enh_ScenarioAttributesManager.hpp"
#include "GUI\Enh_ScenarioAttributesManagerTemplateData.hpp"
//Overloaded and enhanced vanilla GUIs
#include "GUI\display3DENPublishMIssionSelectImage.hpp"

//Delete the original Functions Viewer button in the BIS Debug Console and replace it
class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class RscShortcutButton;
class RscButtonMenu;
class RscDebugConsole: RscControlsGroupNoScrollbars 
{
	class Controls 
    {
		delete ButtonFunctions;
		class Enh_FunctionsViewer: RscButtonMenu 
        {
			idc = -1;
			onLoad = "(_this # 0) ctrlSetText localize 'STR_A3_RscDebugConsole_ButtonFunctions'";
			onButtonClick = "ctrlParent (_this # 0) createDisplay 'Enh_FunctionsViewer'";
			x = "7.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "19.4 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "7.4 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};