class Cfg3DEN
{
	class Notifications
	{
		class Enh_DataCopied
		{
			isWarning = 0;
			text = $STR_a3_RscDisplayArsenal_message_clipboard;
		};
		class Enh_ActionPerformed
		{
			isWarning = 0;
			text = $STR_ENH_notifications_actionPerformed;
		};
		class Enh_NoEntitiesSelected
		{
			isWarning = 1;
			text = $STR_ENH_notifications_noEntitiesSelected;
		};
	};
	class EventHandlers
	{
		class ENH
		{//Statusbar and interface need to be reinitialised when game directly starts in Eden editor
			onTerrainNew = "['init'] call BIS_fnc_3DENStatusBar; ['init'] call BIS_fnc_3DENInterface; 'ONLOAD' call Enh_fnc_3denRadio_toggleRadio; [] spawn Enh_fnc_sessionTimer; call Enh_fnc_locationList; call Enh_fnc_gitHubNotification";
			onMissionPreviewEnd = "'ONLOAD' call Enh_fnc_3denRadio_toggleRadio; [] spawn Enh_fnc_sessionTimer";
			onMissionLoad = "'ONLOAD' call Enh_fnc_3denRadio_toggleRadio; [] spawn Enh_fnc_sessionTimer";
			onMissionNew = "'ONLOAD' call Enh_fnc_3denRadio_toggleRadio; [] spawn Enh_fnc_sessionTimer";
			onMissionPreview = "call Enh_fnc_onPreviewDebug";
			onSelectionChange = "call Enh_fnc_numberOfSelectedEntities";
		};
	};
	class Attributes
	{
		// Base class templates
		class Default;
		class Title: Default
		{
			class Controls
			{
				class Title;
			};
		};
		//Combo
		#include "controls\terrainGrid.hpp"
		#include "controls\featureType.hpp"
		//Slider
		#include "controls\timeMultiplier.hpp"
		//Misc
		#include "controls\ambientAnimation.hpp"
		#include "controls\introText.hpp"
		#include "controls\establishingShot.hpp"
		#include "controls\mapIndicators.hpp"
	};
	class Mission
	{
		class Preferences
		{
			class AttributeCategories
			{
				#include "attributesEditor\onPreviewDebug.hpp"
			};
		};
		class Intel
		{
			class AttributeCategories
			{
				#include "attributesMission\timeMultiplier.hpp"
				#include "attributesMission\visualSettings.hpp"
			};
		};
		class Scenario
		{
			class AttributeCategories
			{
				#include "attributesMission\mapIndicators.hpp"
				#include "attributesMission\volume.hpp"
				#include "attributesMission\introText.hpp"
				#include "attributesMission\ambientFlyby.hpp"
				#include "attributesMission\establishingShot.hpp"
				#include "attributesMission\airdrop.hpp"
				class Misc
				{
					class Attributes
					{
						#include "attributesMission\addObjectsToZeus.hpp"
					};
				};
				class States
				{
					class Attributes
					{
						#include "attributesMission\groupIndicator.hpp"
					};
				};
			};
		};
		class Multiplayer
		{
			class AttributeCategories
			{
				#include "attributesMission\dynamicGroups.hpp"
				#include "attributesMission\dynamicSkill.hpp"
				class Respawn
				{
					class Attributes
					{
						#include "attributesMission\respawnTickets.hpp"
						#include "attributesMission\saveLoadout.hpp"
					};
				};
			};
		};
	};
	class Comment
	{
		class AttributeCategories
		{
			class Init
			{
				class Attributes
				{
					#include "attributesComment\moveIntoToDo.hpp"
				};
			};
		};
	};
	class Group
	{
		class AttributeCategories
		{
			class State
			{
				class Attributes
				{
					#include "attributesGroup\patrol.hpp"
					#include "attributesGroup\groupMarker.hpp"
				};
			};
		};
	};
	class Object
	{
		class AttributeCategories
		{
			#include "attributesObject\advancedDamageUnit.hpp"
			#include "attributesObject\advancedDamageVehicle.hpp"
			#include "attributesObject\disableAI.hpp"
			#include "attributesObject\advancedSkill.hpp"
			#include "attributesObject\unitTraits.hpp"
			#include "attributesObject\onEventCode.hpp"
			class StateSpecial
			{
				class Attributes
				{
					#include "attributesObject\setCaptive.hpp"
					#include "attributesObject\allowSprint.hpp"
					#include "attributesObject\forceWalk.hpp"
					#include "attributesObject\makeHostage.hpp"
					#include "attributesObject\enableHeadlights.hpp"
					#include "attributesObject\allowCrewInImmobile.hpp"
					#include "attributesObject\engineOn.hpp"
					#include "attributesObject\disableNVGE.hpp"
					#include "attributesObject\disableTIE.hpp"
					#include "attributesObject\limitSpeed.hpp"
					#include "attributesObject\doStop.hpp"
					#include "attributesObject\removeFromRemainsCollector.hpp"
					#include "attributesObject\debugPath.hpp"
				};
			};
			class Inventory
			{
				class Attributes
				{
					#include "attributesObject\addGunLight.hpp"
					#include "attributesObject\arsenal.hpp"
				};
			};
			class State
			{
				class Attributes
				{
					#include "attributesObject\allowFleeing.hpp"
					#include "attributesObject\setMass.hpp"
					#include "attributesObject\weaponSway.hpp"
					#include "attributesObject\weaponRecoil.hpp"
					#include "attributesObject\featureType.hpp"
					#include "attributesObject\forceFlag.hpp"
					#include "attributesObject\ambientAnimationSP.hpp"
				};
			};
		};
	};
};