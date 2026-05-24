// Defines
#include "\x\enh\addons\main\script_component.hpp"
#include "\x\enh\addons\main\defineCtrls.inc"

// Configs
#include "\x\enh\addons\main\cfgPatches.hpp"
#include "\x\enh\addons\main\cfg3DEN\cfg3DEN.hpp"
#include "\x\enh\addons\main\cfgFunctions\cfgFunctions.hpp"
#include "\x\enh\addons\main\display3DEN\display3DEN.hpp"
#include "\x\enh\addons\main\cfgFontFamilies.hpp"
#include "\x\enh\addons\main\cfgCommands.hpp"

// Custom GUIs
#include "\x\enh\addons\main\GUI\3DENRadio.hpp"
#include "\x\enh\addons\main\GUI\attributeSearch.hpp"
#include "\x\enh\addons\main\GUI\briefingEditor.hpp"
#include "\x\enh\addons\main\GUI\CfgSentencesBrowser.hpp"
#include "\x\enh\addons\main\GUI\ESE.hpp"
#include "\x\enh\addons\main\GUI\exportGUIDefines.hpp"
#include "\x\enh\addons\main\GUI\functionsViewer.hpp"
#include "\x\enh\addons\main\GUI\moduleInformation.hpp"
#include "\x\enh\addons\main\GUI\moveToLayer.hpp"
#include "\x\enh\addons\main\GUI\nameObjects.hpp"
#include "\x\enh\addons\main\GUI\placementTools.hpp"
#include "\x\enh\addons\main\GUI\RPTViewer.hpp"
#include "\x\enh\addons\main\GUI\SAM.hpp"
#include "\x\enh\addons\main\GUI\selectionFilter.hpp"
#include "\x\enh\addons\main\GUI\templateData.hpp"
#include "\x\enh\addons\main\GUI\textureFinder.hpp"
#include "\x\enh\addons\main\GUI\variableViewer.hpp"
#include "\x\enh\addons\main\GUI\zeusAddons.hpp"

// Improved vanilla GUIs
#include "\x\enh\addons\main\GUI\RscDebugConsole.hpp"
#include "\x\enh\addons\main\GUI\display3DENSave.hpp"
#include "\x\enh\addons\main\GUI\display3DENPublishMissionSelectImage.hpp"
#include "\x\enh\addons\main\GUI\display3DENPlace.hpp"

class ENH_DisplayEmpty
{
    idd = IDD_NONE;
    class ControlsBackground {};
    class Controls {};
};

// #ifdef ISDEV
// class CfgVehicles
// {
//     class Module_F;
//     class ModuleMPType_F: Module_F
//     {
//         class ModuleDescription;
//     };
//     class ENH_TestModule: ModuleMPType_F
//     {
//         author = "Bohemia Interactive";
//         _generalMacro = "ModuleMPTypeSeize_F";
//         scope = 2;
//         icon = "\a3\Missions_F_Gamma\data\img\iconMPTypeSeize_ca.paa";
//         portrait = "\a3\Missions_F_Gamma\data\img\portraitMPTypeSeize_ca.paa";
//         function = "BIS_fnc_ModuleMPTypeSeize";
//         functionPriority = 1;
//         class Arguments
//         {
//             class RatioInfantry
//             {
//                 displayName = "Infantry priority";
//                 description = "How much the system will prioritize spawning infantry";
//                 defaultValue = "1";
//             };
//             class RatioGround
//             {
//                 displayName = "Ground vehicles priority";
//                 description = "How much the system will prioritize spawning ground vehicles";
//                 defaultValue = "1";
//             };
//             class RatioAir
//             {
//                 displayName = "Aircrafts priority";
//                 description = "How much the system will prioritize spawning aircraft";
//                 defaultValue = "1";
//             };
//             class RatioWater
//             {
//                 displayName = "Naval priority";
//                 description = "How much the system will prioritize spawning sea crafts";
//                 defaultValue = "1";
//             };
//             class CheatCoef
//             {
//                 displayName = "Auto coef";
//                 description = "Cost coefficient applied when no Zeus is present and the system creates enemies automatically.";
//                 defaultValue = "1";
//             };
//         };
//         class ModuleDescription: ModuleDescription
//         {
//             description[] = {"Create Seize mission mode, compatible both with single- and multiplayer.","","Players are capturing AI controlled sectors.","When they seize all of them, they win.","If they run out of time or respawn tickets, they lose","","Note: Curator spawning costs and limited time or respawns have to be configured separately."};
//             sync[] = {"ModuleSector_F","SidePlayers","SideEnemy"};
//             class SidePlayers
//             {
//                 description = "Side of attacking players.";
//                 displayName = "Player Side";
//                 vehicle = "SideBLUFOR_F";
//                 duplicate = 1;
//                 sync[] = {"ModuleSector_F"};
//             };
//             class s1
//             {
//                 description = "Side of defending forces, recognized by presence of synced curator.";
//                 displayName = "Enemy Side";
//                 vehicle = "SideOPFOR_F";
//                 // sync[] = {"Curator_F"};
//             };
//             class s2
//             {
//                 description = "Side of defending forces, recognized by presence of synced curator.";
//                 displayName = "Enemy Side";
//                 vehicle = "SideOPFOR_F";
//                 // sync[] = {"Curator_F"};
//             };
//             class s3
//             {
//                 description = "Side of defending forces, recognized by presence of synced curator.";
//                 displayName = "Enemy Side";
//                 vehicle = "SideOPFOR_F";
//             };
//             class s4
//             {
//                 description = "Side of defending forces, recognized by presence of synced curator.";
//                 displayName = "Enemy Side";
//                 vehicle = "SideOPFOR_F";
//             };
//             class Curator_F
//             {
//                 description = "Mark the side as enemy, curator controlled. At least one side has to be marked this way. All other sides will remain friendly, player controlled.";
//                 optional = 1;
//                 sync[] = {"ModuleSector_F"};
//             };
//             class ModuleSector_F
//             {
//                 description = "Add a contested sector.";
//                 duplicate = 1;
//                 sync[] = {"LocationArea_F","MiscLock_F", "s1", "s2", "s3", "s4"};
//             };
//             class LocationArea_F
//             {
//                 description = "";
//                 duplicate = 1;
//                 sync[] = {"TriggerArea"};
//             };
//             class TriggerArea
//             {
//                 position = 1;
//                 direction = 1;
//                 description = "Set the sector area. Enemy units will be spawned only in this area. When the sector is captured by a friendly side, the trigger will be activated, potentially triggering other modules synced to it (e.g., respawn module).";
//                 duplicate = 1;
//                 vehicle = "EmptyDetector";
//             };
//             class MiscLock_F
//             {
//                 description = "";
//                 optional = 1;
//                 sync[] = {"TriggerLock"};
//             };
//             class TriggerLock
//             {
//                 position = 1;
//                 direction = 1;
//                 description = "Disable enemy unit spawning in the sector when friendly units are within this area. Re-enable it in case they are gone again.";
//                 duplicate = 1;
//                 vehicle = "EmptyDetector";
//             };
//         };
//         displayName = "TEST";
//     };
// };
// #endif
