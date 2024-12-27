//Defines
#include "script_component.hpp"
#include "defineCtrls.inc"

//Configs
#include "cfgPatches.hpp"
#include "cfg3DEN.hpp"
#include "cfgFunctions.hpp"
#include "display3DEN\display3DEN.hpp"
#include "cfgFontFamilies.hpp"

//Custom GUIs
#include "GUI\3DENRadio.hpp"
#include "GUI\3DENShortcuts.hpp"
#include "GUI\attributeSearch.hpp"
#include "GUI\briefingEditor.hpp"
#include "GUI\CfgSentencesBrowser.hpp"
#include "GUI\customizeMenuStrip.hpp"
#include "GUI\ESE.hpp"
#include "GUI\exportGUIDefines.hpp"
#include "GUI\functionsViewer.hpp"
#include "GUI\garrison.hpp"
#include "GUI\moduleInformation.hpp"
#include "GUI\moveToLayer.hpp"
#include "GUI\nameObjects.hpp"
#include "GUI\placementTools.hpp"
#include "GUI\RPTViewer.hpp"
#include "GUI\SAM.hpp"
#include "GUI\selectionFilter.hpp"
#include "GUI\templateData.hpp"
#include "GUI\textureFinder.hpp"
#include "GUI\variableViewer.hpp"
#include "GUI\zeusAddons.hpp"

//Improved vanilla GUIs
#include "GUI\RscDebugConsole.hpp"
#include "GUI\display3DENSave.hpp"
#include "GUI\display3DENPublishMissionSelectImage.hpp"

class ENH_3DENMinimap: ctrlMap
{
    scaleMax = 3;
};
