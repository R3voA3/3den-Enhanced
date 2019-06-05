class Display3DEN
{
	class Controls
	{
		#include "statusbar.hpp"
		class MenuStrip: ctrlMenuStrip
		{
			class Items
			{
				#include "menuStrip_about.hpp"
				#include "menuStrip_tools.hpp"
				#include "menuStrip_help.hpp"
			};
		};
		//Make BLUFOR category collapsed by default
		class PanelRight:ctrlControlsGroupNoScrollbars
		{
			class Controls
			{
				class PanelRightCreate: ctrlControlsGroupNoScrollbars
				{
					class Controls
					{
						class Create: ctrlControlsGroupNoScrollbars
						{
							class Controls
							{
								class CreateObjectWEST: ctrlTree
								{
									defaultItem[] = {};
								};
							};	
						};
					};
				};
			};
		};
	};
	class ContextMenu: ctrlMenu
	{
		#include "contextMenu.hpp"
	};
};