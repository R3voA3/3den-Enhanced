#include "defines.hpp"
#include "cfgPatches.hpp"
#include "cfg3DEN.hpp"
#include "cfgFunctions.hpp"
#include "display3DEN.hpp"

//Custom GUIs
#include "GUI\briefingEditor.hpp"
#include "GUI\3DENRadio.hpp"
#include "GUI\nameObjects.hpp"
#include "GUI\moduleInformation.hpp"
#include "GUI\textureFinder.hpp"
#include "GUI\batchReplace.hpp"
#include "GUI\functionsViewer.hpp"
#include "GUI\actionCreator.hpp"
#include "GUI\placementTools.hpp"
#include "GUI\scenarioAttributesManager.hpp"
#include "GUI\scenarioAttributesManagerTemplateData.hpp"
#include "GUI\garrison.hpp"
#include "GUI\extraction.hpp"
#include "GUI\3DENCameraPositions.hpp"
#include "GUI\variableViewer.hpp"
#include "GUI\inventoryManager.hpp"
#include "GUI\inventoryManager_templateData.hpp"
#include "GUI\inventoryManager_itemPreview.hpp"
#include "GUI\CfgSentencesBrowser.hpp"

//Overloaded and enhanced vanilla GUIs
#include "GUI\display3DENPublishMIssionSelectImage.hpp"

/* 
  Adds button to debug menu, credits to
  Author: Connor
  Steam:  https://steamcommunity.com/id/_connor
  Github: https://github.com/ConnorAU
*/

class RscControlsGroupNoScrollbars;
class RscDebugConsole: RscControlsGroupNoScrollbars
{
	class Controls
  {
    class ENH_ButtonFunctions: ctrlButtonPictureKeepAspect
    {
      idc=0; // idc 0 to exclude from repositioning in CBA extended debug
      deletable=0;
      text="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\functions_ca.paa";
      tooltip="3den Enhanced Functions Viewer";
      colorBackground[]={0,0,0,0};
      colorBackgroundActive[]={0,0,0,0};
      colorFocused[]={0,0,0,0};
      colorBackgroundDisabled[]={0,0,0,0};
      onButtonClick="ctrlParent (_this # 0) createDisplay 'ENH_FunctionsViewer'";
      // get from title ctrl incase some mod moves it
      x="getNumber(configFile >> 'RscDebugConsole' >> 'controls' >> 'Title' >> 'w') - (4.1 * (((safezoneW / safezoneH) min 1.2) / 40))";
      y="getNumber(configFile >> 'RscDebugConsole' >> 'controls' >> 'Title' >> 'y')";
      w="1 * (((safezoneW / safezoneH) min 1.2) / 40)";
      h="1 *((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    };
  };
};