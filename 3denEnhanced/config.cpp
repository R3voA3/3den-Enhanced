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

/* 
  Adds button to debug menu, credits to
  Author: Connor
  Steam:  https://steamcommunity.com/id/_connor
  Github: https://github.com/ConnorAU
*/

class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class RscShortcutButton;
class RscButtonMenu;
class RscDebugConsole: RscControlsGroupNoScrollbars 
{
	class Controls 
  {
    class Enh_ButtonFunctions: ctrlButtonPictureKeepAspect 
    {
      idc=0; // idc 0 to exclude from repositioning in CBA extended debug
      deletable=0;
      text="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\functions_ca.paa";
      tooltip="3den Enhanced Functions Viewer";
      colorBackground[]={0,0,0,0};
      colorBackgroundActive[]={0,0,0,0};
      colorFocused[]={0,0,0,0};
      colorBackgroundDisabled[]={0,0,0,0};
      onButtonClick="ctrlParent (_this # 0) createDisplay 'Enh_FunctionsViewer'";

      // get from title ctrl incase some mod moves it
      x="getNumber(configFile >> 'RscDebugConsole' >> 'controls' >> 'Title' >> 'w') - (4.1 * (((safezoneW / safezoneH) min 1.2) / 40))";
      y="getNumber(configFile >> 'RscDebugConsole' >> 'controls' >> 'Title' >> 'y')";
      w="1 * (((safezoneW / safezoneH) min 1.2) / 40)";
      h="1 *((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    };
  };
};