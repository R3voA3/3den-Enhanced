#include "defineCommon.hpp"
#include "defineCtrls.hpp"
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
#include "GUI\garrison.hpp"
#include "GUI\extraction.hpp"
#include "GUI\3DENCameraPositions.hpp"
#include "GUI\variableViewer.hpp"
#include "GUI\inventoryManager.hpp"
#include "GUI\CfgSentencesBrowser.hpp"
#include "GUI\RscTestControlXXX.hpp"
#include "GUI\ExportGUIDefines.hpp"

class RscControlsGroupNoScrollbars;
class RscDebugConsole: RscControlsGroupNoScrollbars
{
  class Controls
  {
    class ButtonSpectatorCamera;
    class ButtonFunctions: ButtonSpectatorCamera
    {
      idc = -1;
      //Dynamically reposition it if Connor's functions viewer is available as well.
      onLoad = "_this # 0 ctrlSetText ('ENH_' + localize 'STR_A3_RSCDEBUGCONSOLE_BUTTONFUNCTIONS'); if (isClass (configFile >> 'RscDisplayDebugPublic' >> 'Controls' >> 'DebugConsole' >> 'controls' >> 'CAU_xFuncViewer')) then {_this # 0 ctrlSetPosition [7.5 * (((safezoneW / safezoneH) min 1.2) / 40),21.6 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)]; _this # 0 ctrlCommit 0;}";
      x = 7.5 * GUI_GRID_W;
      onButtonClick = "ctrlParent (_this # 0) createDisplay 'ENH_FunctionsViewer'";
    };
  };
};