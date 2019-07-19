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
		{
			onTerrainNew = "call Enh_fnc_EH_onTerrainNew";
			onMissionPreviewEnd = "call Enh_fnc_EH_onMissionPreviewEnd";
			onMissionLoad = "call Enh_fnc_EH_onMissionLoad";
			onMissionNew = "call Enh_fnc_EH_onMissionNew";
			onMissionPreview = "call Enh_fnc_EH_onMissionPreview";
			onSelectionChange = "call Enh_fnc_EH_onSelectionChange";
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
		#include "controls\timeMultiplier.hpp"
		#include "controls\featureType.hpp"
		#include "controls\terrainDetail.hpp"
		#include "controls\ambientAnimation.hpp"
		#include "controls\introText.hpp"
		#include "controls\establishingShot.hpp"
		#include "controls\mapIndicators.hpp"
		#include "controls\groupMarker.hpp"
		#include "controls\airdrop.hpp"
		#include "controls\ambientFlyby.hpp"
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
			#include "attributesGroup\groupMarker.hpp"
			class State
			{
				class Attributes
				{
					#include "attributesGroup\patrol.hpp"
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
					#include "attributesObject\featureType.hpp"
					#include "attributesObject\forceFlag.hpp"
					#include "attributesObject\ambientAnimationSP.hpp"
				};
			};
		};
	};
};