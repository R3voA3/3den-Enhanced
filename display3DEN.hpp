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
	};
	class ContextMenu: ctrlMenu
	{
		#include "contextMenu.hpp"
	};
};