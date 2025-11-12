# 8.7.2
## ADDED
- Hold Action now supports radius

## CHANGED
- Module Information
    - Complete overhaul of Module Information UI. It now shows entites that can be synced similar to the old editor
    - Module Information UI would not show all descriptions of all modules

- Hostage Attriubute
    - Hostage will automatically be placed in the captive state, as well as out of it when freed, so that they aren't engaged by nearby AI
    - "MOVE" AI will be disabled while tied up, to prevent the hostage from turning around to look at nearby units
    - When freed, the hostage will automatically join the caller's group and run a doStop, preventing it from running around on its own until commanded to regroup or move to a new location by the group's leader.

- Debug Options
    - Improved visualization of triggers when "Show Triggers" debug option is enabled
    - Unified debug option  hint style
    - Fixed fleeing value in the group debug option would not show a value
    - Debug option to show triggers would not display data
    - Fixed draw triggers and dynamic simulation debug view would not work together
- Fixed edit boxes would prevent scrolling in some cases
- Fixed hold action edit boxes would in some cases not show entire text (#453)
- Improved Unit Trait Description's localization
- French translation update by Alfred-Neuman
- Removed 0 infront of spawn were applicable

# 8.7.1
## ADDED
- Added fn_iterTree.sqf (internal use only)
- CTRL + ALT + SPACE opens 3DEN Command Palette now, in addition to ALT + SPACE

## FIXED
- Config popup error when filling the mod filter in Eden Editor

# 8.7.0
## ADDED
- **3DEN Command Palette**
    - Access almost all Eden Editor commands
    - Add custom commands
    - Read https://github.com/R3voA3/3den-Enhanced/wiki/3DEN-Command-Palette for more information
![](https://github.com/R3voA3/3den-Enhanced/raw/master/images/3dencommandpalette.png)
- Added a setting to adjust attribute title width if it's too long. Enabled by default. Disabled it in Preferences -> Interface
- Added a search to the hold action icon picker

## CHANGED
- Asset Browser's mod filter no longer shows mods that don't add assets
- Fixed links to Steam and GitHub would not work when accessed through the menu strip
- Fixed missing translation for the Stance attribute in the preferences
- Fixed opening the Zeus Addons UI would create spam in the RPT
- Fixed RPT message (empty class)
- Fixed wrong translation for Minimap Scale attribute
- Help buttons in various UIs were standardized
- Improved Debug Options category names
- Marker Preview now only works if either custom shape or custom color was set
- Moon Phases Utility could not be opened from menu strip
- Search button in the favorites tab had no functionality
- Updated French translation by Alfred-Neuman

## REMOVED
- Shortcuts UI in favour of the 3DEN Command Palette (shortcuts can be viewed there too)

# 8.6.2
## CHANGED
- When marker preview setting is changed in preferences, changes are applied immediately now
- Custom Marker Color and Shape preview was overhauled. Instead of modifing the marker, a small icon will now appear next to the tooltip on hover

# 8.6.1
## CHANGED
- Fixed CBA Addon options and ACE Arsenal not working in Eden Editor due to a function returning true at the wrong place
- Renamed variable name of new "Show Marker Color and Shape" attribute (You need to update your setting if you changed it)

# 8.6.0
## ADDED
- Custom marker color attribute
- Custom marker shape attribute
    - By default, custom marker shapes and colors are displayed when hovering over them, this can be disabled in the Preferences -> Interface
    - Note that custom shapes are not available for markers of type ICON

# 8.5.0
## ADDED
- Custom icons for the hold action attribute can now be defined in the Editor preferences -> Misc.
- Icon picker to the hold action attribute  #435
- ENH_fnc_iconPicker, an simple Icon Picker

## CHANGED
- Fixed delete crew tool would not work on UAVs/UAV Turrets (Thanks hypoxia125) #433
- Fixed that unit traits and attributes would conflict with ACE (Thanks Nomas-X for the detailed issue) #436
- Fixed tooltips for the input list attribute control were swapped
- Fixed minimap code would run 1 frame into eden preview disabling map indicators
- Fixed that AI attributes would have no effect when entity is transfered to a headless client (Thanks KJW)
- Minor script optimizations and formatting improvements

# 8.4.0
## ADDED
- Added localization for garrison combo entries
- New Garrison tool
    - Garrison any building by simply dragging all selected entities onto it after pressing the "G" key
    - When dragging a single entity onto a building, the position that would be manned is highlighted
    - Various settings are available in the Editor Preferences:
        - Selection mode
        - Preventing to fill building positions that are already manned
        - Random orientation
        - Various stance options
        - Disabling pathfinding
        - Automatic grouping into layers
        - Automatic grouping (Currently broken in A3)

## CHANGED
- French translation update by Alfred-Neuman
- Fixed drawing of building positions wouldn't work

# 8.3.0
## ADDED
- The "Editable Objects (Zeus) has been expanded. You can now either only add pre placed objects to Zeus or all objects continiously
- ENH_fnc_initSearchControls to easily setup a search with an image button and a edit box as used everywhere in Eden editor
- Function to parse array3 from clipboard

## CHANGED
- Replaced mission sqm blacklist attribute with a scenario specific checkbox (General -> Misc.). If multiple people are working on the same scenario not everyone has to specifically set the blacklist
- Fixed CBA macro file would create a dependency and crash the game when trying to preprocess certain files
- Moved open ACE Arsenal code to unscheduled execution to fix an issue with shift being detected and adding always 5 items in ACE Arsenal (Thanks Komodo for the report)
- Fixed Briefing Editor text would not properly be displayed
- The "Editable Objects (Zeus) now waits until a curator is available
- Ambient Flyby Attribute
    - Completely overhauled the UI
    - Added paste from clipboard buttons to set the positions easily
    - Added support for randomized delay
    - Added support for randomized start and end positions
    - Added filterable tree view
- Airdrop Attribute
    - Completely overhauled the UI
- French translation update by Alfred-Neuman
- Controls of Dynamic Skill attribute are now properly disabled/enabled depening on attribute state
- The random music attribute now has a list showing all music tracks available
- Fixed that the first control in the advanced damage attribute would overlap the description
- Fixed event handler from casualties attribute would not get removed properly, sometimes executing the mission ending multiple times

# 8.2.0
## ADDED
- The ability to make hold actions persistent

## CHANGED
- Removed unused menu strip entries from ESE

# 8.1.1
## CHANGED
- Fixed config error when opening marker attributes

# 8.1.0
## ADDED
- Attribute can now be disabled by adding additional optional pbo files to the main folder ([Documentation](https://github.com/R3voA3/3den-Enhanced/wiki/Removing-Attributes))

- Shortcut to open ACE Arsenal if ACE is loaded (CTRL + SHIFT + L)

- Improved Capture Frame UI
    - Added none transparent background
    - Added search box to search through tree
    - UI can no longer be moved
    - Added collapse and expand tree control buttons
    - Added button to open https://ui.perfetto.dev/ in default browser (Profiling.exe only)

## CHANGED
- Minimap is now hidden when arsenal is opened

# 8.0.2
## CHANGED
- Allow Unit Traits To Be Set To 0
    - Adds new control "ENH_SliderMultiZero"

# 8.0.1
## CHANGED
- Name Objects UI
    - Unable to set variable names
    - Added support for Layer naming
    - Added last used index is now saved
    - Code optimization

# 8.0.0
## ADDED
- Added support for script files for all 3DEN event handlers. See [the documentation](https://github.com/R3voA3/3den-Enhanced/wiki/Event-Scripts)
- Added object event handler attributes
- Added group event handler attributes
- Added import from clipboard function to ESE #306 (Thanks to Pixelated-Grunt)
- Added blacklist for mission.sqm backup
- Added water leakiness can now be set for vehicles
- Added mission event handler attributes
- Added music event handlers attributes
- Added fuel consumption coef. attribute
- Added InputList attribute control

## CHANGED
- Optimizations
    - 3den Enhanced is now build with HEMTT
    - Fixed various config and macro issues
    - Improved config definitions
    - Added various script improvements
    - Mod is now binarized
    - Compiled all .sqf files to .sqfc
    - Major code overhaul of things running from various event handlers
    - Fixed updating base classes for RscDebugConsole, EditCodeMulti3, and Display3DEN
    - Optimized code of Add Objects to Zeus attribute
    - Simplified Minimap code logic
    - Minimap code was optimized
    - Draw DLC icons and building positions, code optimization
- Functions Viewer
    - Functions Viewer now updates list with last searched keyword when changing tree view layout
    - Functions Viewer now reloads currently selected file if loading type was changed (loadFile, preprocessFile...)
    - Functions Viewer recompiling single function will no longer throw an error when script file is selected
    - Visualization of menu strip item state has been improved
    - Added support for more file extensions when selecting "Other Files" option
- Garrison UI
    - Tweaked UI position and layout
    - Entities can now be selected on the fly
    - Editor placed buildings are not detected as well
    - The UI is now properly deinitialized before preview, when switching terrain or mission
- Group Marker Attribute
    - Optimized code
    - Marker is no longer attached to first group leader
    - Marker is only deleted once group becomes null
- Shortcuts UI
    - Shortcuts in the shortcuts UI are now properly translated
    - Shortcuts UI now shows all shortcuts per action
    - Added tooltip to shortcuts UI in case translations are too long
- Equipment Storage Editor
    - HashMap with all items would get rebuild each time resulting in slow loading of the UI
    - Fixed weapons of type "MissileLauncher" (Titan) would be missing
- Favorites list was overhauled
    - Place entities by dragging and dropping
    - Added support for markers, modules and objects
    - Added categories
    - Improved UI layout
- Translation
    - Updated French translation thanks to Alfred-Neuman
    - Full Italian translation thanks to Fil-ric
- General
    - Moved mass attribute from transformation category to state category
    - Moved limit speed attribute from special states category to state category
    - Fixed duplicated "Move to layer..." context menu entry (thanks to honger)
    - Fixed removing unit from remains collector had not effect (typo in code)
    - Add Editable Objects (Zeus) attribute now also adds all editor placed objects
    - Briefing attributes should now create diary entries in same order every time #297
    - Dynamic view distance was no longer working after preview ended
    - Draw DLC icons and building positions were move to preferences
    - Added description to menu strip items for easier documenation
    - Changed shortcut for Placement Tools from CTRL + L to CTRL + ALT + L (CBA compatibility)
    - SPR attribute controls are now enabled/disabled depending on ruleset

## REMOVED
- Removed Enable Minimap Attribute, it was merged with the Minimap Size attribute
- Customization via userconfig
- WIP scripts and UIs
- Unused functions
- Highlight area marker function as it's now implemented in the engine
- Menustrip customization
- ENH_init3DENMissionPreview.sqf is no longer supported. Use ENH_onMissionPreview.sqf instead!

# 7.8.8
## CHANGED
- Tweaked Dynamic Simulation debug mode
- Minimap is disabled by default. Enable it via the Preferences (CTRL + K)

# 7.8.7
## CHANGED
- Tweaked Dynamic Simulation debug mode
- Minimap is disabled by default. Enable it via the Preferences (CTRL + K)

# 7.8.6
## ADDED
- Added a Minimap to Eden Editor. Can be disabled in the Editor preferences
- Backup of mission.sqm now supports custom path outside of mission folder (Thanks to klausman)
- Added tool to show area markers in 3D space via triggers to the menu strip

## CHANGED
- Fixed SPR attribute would be saved to mission.sqm even though it was not enabled to begin with
- Fixed Dynamic Skill attribute would be saved to mission.sqm even though it was not enabled to begin with
- Dynamic Simulation debug option has been improved in various ways

# 7.8.5
## CHANGED
- Fixed entity counter

# 7.8.4
## CHANGED
- Move tools from root of context menu into a subfolder so that the context menu is even on very small screen fully accessable
- Improved display3DENPublishMissionSelectImage
- Turned version info into a button so it won't overlap on small screens. Clicking the button will show more information about
current session

# 7.8.3
## CHANGED
- Mission Backup attribute will now create backup files in mission root in a folder called ".enh_mission_sqm_backups". Existing backups will not be moved!
- Increased 3DEN Radio UI height
- Fixed Entity Counter positioning
- Header and Close button in Placement Tools UI are now static

## REMOVED
- Batch Replace
- Action Creator
- Steam Description Generator
- Create Object Tool

# 7.8.2
## ADDED
## CHANGED
- Fixed missing translation in Placement Tools UI
- Fixed description of Advanced Damage attribute would be cut off
- Updated Placement Tools functions
- Overhauled 3DEN Shortcuts UI
- Added missing translation in ESE
- Improved Move To Layer UI
- Fixed wrong inheritance of Template Data UIs
- Briefing Editor was redesigned #279
- Fixed shortcut for removing all gear was conflicting with engine shortcut
- Entire rewrite of Scenario Attribute Manager
- Entire rewrite of Placement Tools
- Tweaked Inventory Manager Error messaged on opening
- Session Timer control was changed to an icon. Tooltip shows session time

# 7.8.1
# ADDED

# CHANGED
- Reverted identity attributes changes
- Fixed RPT errors
- Fixed Move to Layer UI not working

# 7.8.0
## CHANGED
- Increased the size of EditMulti5 to be as big as EditCodeMulti5
- Variable Viewer has its background disabled again
- Added preview to Face and Unit Insignia attributes
- Fixed Unit Insignia would not accept empty insignia
- Many code improvements
- Fixed typo in Draw Marker Priority attribute (Thanks to anthonybartczak)
- Fixed searching in Face attribute would also filter Insignia attribute
- Fixed function path in Functions Viewer would clip on smaller screens
- Improved Zeus Addons Manager UI
- Added tooltips to entries of Zeus Addon Manager
- Search Attributes UI now supports more attributes
- Search Attributes tree view colors adjusted for better contrast
- Improved search of Search Attributes
- Improved search of Move to Layer UI
- Tweaked Move to Layer UI
- Tweaked ESE UI
- Tweaked Selection Filter UI
- Tweaked Export GUI Defines UI
- Fixed "Remove Name" translation clipping in differnt languages
- Tweaked Name Objects UI
- Tweaked RPT Viewer UI
- Tweaked CFGS UI
- Improved Texture Finder UI
- Removed flickering when texture preview is updated

# 7.7.9
## ADDED
- Variable to freed hostage that holds the player object of who freed it _hostage getVariable ["ENH_WasFreedBy", objNull]; #263
- New marker attributes Hide on Start and Conditional Show (thanks to hypoxia125)
- Variable Viewer now also lists logics/modules
- **Added an editor setting to enable auto backup of mission.sqm every time the scenario is saved/autosaved. Please report any issues with it ASAP**

## CHANGED
- Code for allowSprint attribute
- Stay on Position attribute is now again enabled for MP
- Code for marker draw priority
- Unit Insignia and Face attribute controls were enhanced
- Updated loadorder to latest in 2.14
- Updated Virtual Arsenal Manager code thanks to linkion
- It's now possible to search by texture size in Texture Finder
- Multiple code optimisations
- Preference values are no longer reset if game is started without mods
- Placement Tools
    - Sliders were replaced with Edit controls to allow any numeric value
    - Added the option to adjust center on the fly
    - Line pattern now also supports direction
    - Edit controls allow for fine adjustment via PAGE UP/DOWN and modifier keys such as CTRL, ALT and SHIFT
    - Orientation around Z-axis can now be freely set
    - Functions rewrite
- 3DEN Radio is now displayed properly on all aspect ratios, resolutions and UI sizes
- Equipment Storage Editor is now displayed properly on all aspect ratios, resolutions and UI sizes
- Module Information is now displayed properly on all aspect ratios, resolutions and UI sizes
- Scenario Attributes Manager is now displayed properly on all aspect ratios, resolutions and UI sizes
- Search Attributes UI is now displayed properly on all aspect ratios, resolutions and UI sizes
- Some notifications now have a clickable link
- Mod is now 100% translated in Chinese and Chinese Simplefied
- Variable Viewer has been rewritten

## REMOVED
- Menu strip entry of WIP feature
- Unused file
---
# HAPPY 10TH ANNIVERSARY ARMA 3
---

# 7.7.8
## ADDED
- Shortcut ALT+O now opens the scenario folder

## CHANGED
- Fixed link to changelog
- Fixed missing translation in menu strip
- Texture Finder is now creating a loading
    screen which drastically reduces fill time of the
    tree view
- Changed define files
- Added sqfc support where possible
- Entity counter is no longer shown on very small screen with large UI size

# 7.7.7
## CHANGED
- updated Spanish translation thanks to regiregi22
- tweaked statusbar
- added support for "ENH_init3DENMissionPreview.sqf" event script. Place this script in your folder and it will automatically be executed on mission preview
- fixed some missing ;
- Update fn_exportLoadout.sqf (PR #267) by hypoxia125
- Texture Finder
    - Improved performance
    - Added collapse/expand all buttons
    - Alpha of textures is now shown via tiled background
    - Increased UI size
    - Increase texture count from ~10k to around ~47k in vanilla

# 7.7.6
## CHANGED
- Vehicle Inventory Manager overhaul
    - Renamed to Equipment Storage Editor (to give it a similar name as the vanilla attribute)
    - Increased UI size
    - Added a list that shows compatible magazines and items of the selected item
    - Template list is now always visible
    - Code optimisations
- fixed text overlapping in large edit control
- increase size of large edit control
- removed excessive space underneath the large edit control

- Fixed a bug which disabled "Recompile All" button in functions viewer even though it should be available
- Fixed wrong help link in Functions Viewer menu strip
- Save Loadout attribute: Removed debugging, code cleanup
- added missing file to GUI Export

## REMOVED
- removed workaround to mute notification as
the volume can now be changed in the options
menu
- Extraction UI as there are compositions which do exactly that

# 7.7.5
## CHANGED
- Fixed ugly preview image for favorites list

# 7.7.4.1
## CHANGED
- Camera direction in statusbar now always has three digits
- Removed obsolete Location list function call
- Fixed incorrect version number

# 7.7.4
## ADDED
- Status bar now shows the camera direction

## CHANGED
- Shortcuts UI is now larger
- Added missing footer control to Shortcuts UI
- Changed width of distance gauge in status bar
- Location list update
    - Improved location list code
    - Custom location can now be saved to the location list
    - Custom locations are stored per map
    - Custom locations can be deleted
- Updated Polish translation, thanks to genjonakasone
- The scenario UI (Load/Save) is now using almost the full screen width to make sure folks with a complex folder structure can still navigate through it

## REMOVED
- Removed 3DEN Cam Positions UI

# 7.7.3
## ADDED
- Dynamic Simulation Debug Mode now also works for objects
- CTRL + SPACE added as shortcut to snap entities to surface
- Added Select all Layers button to the left panel
- Renamed recently added functions
- Updated Italian translation thanks to Fil-ric
- Search box is not automatically focused when Move To Layer UI is opened
- If AI skill settings are set to 0.5 (via Edit box) they will no longer be executed
- Moved Delete All Empty Layers to the left Panel
- ENH_fnc_setOrientation
    - Works now with 1 (trigger, markers) and 3 (object, system) dimensional attributes
    - Preserves orientation around X and Y

# 7.7.2
## ADDED
- Names of entries in the Asset Browser are now also shown as tooltip top prevent them from being cut off (Variable Names wouldn't be visible in some cases)

## CHANGED
- Dynamic Simulation Debug mode now shows activation distance for all units that can trigger dynamic simulation
- Dynamic Simulation Debug mode now also shows number of units and vehicles that can trigger dynamic simulation
- Trigger areas and trigger statements are now drawn on the map

# 7.7.1
## CHANGED
- Remove markerName attribute from Search Attributes GUI
- Fixed twitching of units that get killed during Ambient Animation

# 7.7.0
## CHANGED
- The Move Here context menu entry will now also center the map (if it's open) on the selected position

# 7.6.9
## CHANGED
- Muted incredible loud notification sounds until fixed by BI. This can be disabled via userconfig

# 7.6.8
## CHANGED
- Edit Attributes button in Search Attributes UI (SAUI) was sometimes not initialised correctly
- Entities in the SAUI are now better displayed
- Fixed script error when selecting groups in the SAUI
- Added support for markers to the SAUI
- When selecting a marker in SAUI, the map will now open, camera will be moved and the map view will be adjusted as well
- Added support for marker name to SAUI
- Save Loadout attribute was updated: (backwards compatible)
    - Added logging
    - Updated tooltip
    - Improved code
- Object scaling attribute now uses an Edit box again to allow more values
- Texture Finder UI can no longer be moved (dragged)
- Image Preview in Texture Finder UI is not properly positioned

## REMOVED
- Removed Recompile Functions menu strip entry
- Obsolete configs and functions
- Config Viewer customisation due to incompatibility with other mods that modify it

# 7.6.7
## ADDED
- Added a tool to find all entities with code attributes such as onActivation, waypoint condition (own attributes can be added, see function header ENH_fnc_attributeSearch_onLoad)

# 7.6.6
## CHANGED
- Fixed Group Attribute code being exported sqf even though it was disabled (Thanks Expunged)

# 7.6.5
## CHANGED
- Removed init msg for Debug Options
- Improved Debug Options code

# 7.6.4
## CHANGED
- Fixed typo in translation
- Remove unused files
- Fixed script error in Show Groups debug option script

# 7.6.3
## CHANGED
- Fixed missing semicolon (thanks to kju)
- removed duplicated entries in stringtable (thanks to kju)

# 7.6.2
## ADDED
- Added Selection Manager. Accessible through the context menu -> select.

# 7.6.1
## ADDED
- Added tool to quickly toggle local object attribute

## CHANGED
- Simplified menu strip
- Removed vanilla UI tools because of scripting errors inside the GUIs

# 7.6
## CHANGED
- Draw units and waypoints debug option was updated and merged into on option
- Log active script does now open a dialog for direct copy for easier access
- Object scaling should now work again in SP
- Measure distance tool was updated

# 7.5.1
## CHANGED
- Disabled Set Object Scale attribute in multiplayer

# 7.5
## CHANGED
- Improved locality handling of several object attributes
- Enable Gun Lights attribute now check if the slot of the gun light is already filled. This allows units to use modded gun light attachments.

# 7.4
## CHANGED
- Small tweak to Export GUI defines UI
- Hopefully fixed objectScale not working in MP

# 7.3
## CHANGED
- Updated Create Object UI
- Updated Camera Position UI

# 7.2
## CHANGED
- Updated batch replace UI

# 7.1
## CHANGED
- Fixed that Debug Options wouldn't get initialized
- Fixed missing ; in Move to Layer UI

# 7.0
## CHANGED
- Debug Options now work in Eden Multiplayer hosted
- Fixed a bug with recompiling functions in functions viewer
- Move to Layer UI now uses tree view with search
- Move to Layer UI size increased

# 6.9
## ADDED
- The ability to move entities into layers from the context menu

## CHANGED
- Increased initial delay for object scaling. Attempt to fix issue in MP

# 6.8
## CHANGED
- Fixed that terrain quality would reset itself

# 6.7
## CHANGED
- Optimizations in regards to setPos vs setPos*
- Fixed bug with feature type attribute (Thanks to IllidanS4)

# 6.6
## CHANGED
- Updated Spanish translation. Thanks to arv187!
- Fixed wrong control size in Texture Viewer GUI

# 6.5
## CHANGED
- Updated Chinese translation thanks to mihuan-0

# 6.4.1
## CHANGED
- Fixed a script error with ESE if ACE was used

# 6.4
## CHANGED
- Fixed missing ; in display3DEN
- Fixed ENH_AllowSprint being available for non Brain objects
- It's no longer possible to use the search in the Texture viewer before the list is fully filled
- Functions Viewer overhaul
- Polish translation was updated by Krzyciu. Thanks ;)
- Typo in stringtable.xml
- Improved the Texture Viewer UI by adding better feedback to indicate when loading is done
- Some other visual tweaks to the Texture Viewer

# 6.2
## ADDED
- A simple GUI to create Eden Entities that are not present in the Asset Browser e.g. (scope = 0)
- Readded object scaling for objects without simulation
- Alignment tools
- Spacing tools
- Disable AI "all"
- Added a link to quickly report an issue
- Some basic pylon tools
- Some basic vehicle customization tools

## CHANGED
- Fixed an issue that would make the Functions Viewer use an incorrect path in some rare cases
- Fixed incorrect line count in Functions Viewer
- Fixed to small control height in Functions Viewer if function was really short
- Locations list will now show the class name if no displayname is available instead of "Unknown"
- Removed icons from Batch Replace list to speed up loading
- Minor visual tweaks to almost all GUIs
- Fixed the incorrect shortcut in 3DEN Radio to focus search
- 3DEN Radio now has a dynamic width to make use to screen space when using UW screens
- Increased the height of all large edit boxes in Eden Editor
- Fixed an issue that would prevent 'Export Mission to SQF' to work properly with some attributes

- Group Marker Attribute
    - Fixed an issue that would cause a script error popping up
    - Attribute is now also properly loaded if multiple entites are edited at once
    - Minor network optimisations to the Group Marker attribute
    - Added tooltips to the controls
    - Tweaked default value
    - Changed the color of the combo box controls to increase the contrast when selecting the texture type
    - Thanks to Hypoxic, vehicle names can now also be displayed

- Fixed a missing name in Preferences Menu
- Garrison GUI will now save and restore the blacklist value
- Visual tweaks to the Ambient Animations UI. Icons will not indicate if the animation uses a weapon
- Ambient Animation attribute will now be set to "Disabled" if no animation is selected
- Remove obsolete code that was used as workaround https://feedback.bistudio.com/T141001
- Added some missing ;

- Briefing Editor
    - Changed the way templates are stored (backwards compatible)
    - Added basic syntax highlighting for easier editing
    - Redesigned parts of the UI
    - Changed how briefing text is exported
- Export Mission Parameters tool is now using display3denCopy
- Images in Texture Finder are now categorised by their size
- Image preview in Texture Finder GUI will now display images in original size if possible
- 3den Enhanced documenation has been updated (https://github.com/R3voA3/3den-Enhanced/wiki). This is an ongoing effort.
- Some tweaks and fixes to RscTestControlTypes and RscTestControlStyles
- Tweaked the tooltips of the view distance settings
- Delete empty layers tool will now also delete sublayers
- Fixed an issue which causes the progress text in the Texture Viewer to not work when language = German
- Visual overhaul of the Module Information GUI
- SPR will now restore original volumes after respawn
- Vehicle inventories are now preloaded to get rid of the initial lag and loading screen when opening the first vehicle
- Placement tools folder was reworked
- History entries will now use custom text, tooltip and icon if applicable
- Damage calculation of the SPR should now closer to the original damage values
- SPR now supports "After respawn code"
- Fixed an issue that causes the Functions Viewer to not properly generate the path to the function file

- Vehicle Inventory Manager
    - Completely redesigned the GUI
    - Fully using HashMap now
    - Added warning about unsaved changes when closing the GUI
    - New icons
    - Added function to export to sqf
    - Added function to export to scripted arsenal
    - Added direct link to online documention
    - Added shortcuts for most actions
    - Loadout is now properly reset even if config name in vehicle config has not got the proper casing
    - DescriptionShort is now shown in the tooltip as well
    - Fixed a rare "undefined variable" error when using the Vehicle Inventory Manager
    - Fixed empty value when exporting vehicle inventory in ACE format
- Chinese simplefied and Chinese traditional updated by mihuan-0
- Fixed an issue that would cause Export GUI Defines UI to export wrong values
- Export GUI Defines now uses display3denCopy

# 6.1.1
## REMOVED
- Removed Object Scaling attribute. There is an issue with Export Mission to SQF. See https://feedback.bistudio.com/T158949.

# 6.1
## ADDED
- Tool to quickly toggle the playable state of multiple units
- Vehicle Inventory Manager now has an option to export all items in format of ACE Arsenal. Just import the value into the ACE Arsenal attribute
- Added debugging mode for Dynamic Simulation during preview
- Added a tool which allows you to quickly show all markers in Eden Editor whose alpha value was set to 0. No more guessing where the markers are! (Shortcut: V)
- Updated Russian translation by Counserf
- Various translation tweaks
- Added tools to quickly select available addons for Zeus. See https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#zeus-addons
- More ambient animations
- Object scaling for objects without simulation

## CHANGED
- Found some stray semicolons and put them back in the correct place
- Fixed an issue with a missing texture. Blame Lou for reporting it ;)
- Fixed an issue with 3den Radio when mod name was too long
- Fixed an issue which would cause some special items not to be added to an inventory via the Vehicle Inventory Manager
- Debug options now have another category called "Map". Every option in there will draw information on the map
- Various improvements to the translations
- Fixed a bug with debug options
- 3DEN Radio will no longer list CBA or ACE3 as music addon
- Fixed issue with Menu Strip items not getting removed if set in the preferences (https://github.com/R3voA3/3den-Enhanced/issues/194)
- Moved object scaling and vehicle mass to transformation category
- Fixed some duplicates in the userconfig. Userconfig was also updated to support all new features
- Fixed an issue where respawn positions of SPR would not be recognized if they are not named all lower case
- Removed all debug logs
- Fixed an issue with SPR where the side of the unit which is respawning was incorrect

## REMOVED
- Removed shortcut from recompile all functions tool

# 6.0
## CHANGED
- Vehicle Inventory Manager (ESE)
    - Is now able to create a full arsenal with selected addon items
    - Is using HashMaps where possible now to improve performance when many items are available
    - Fixed the issue where the amount would not properly be saved if inventory was set to be virtual
    - Ok button was renamed to Save. Pressing this button is the only way to save the currently set up inventory
    - Removed the dialog when resetting the inventory to default
    - Various visual tweaks
- Timeline in 3DEN Radio is now working correctly
- Fixed an issue with Feature Type attribute sometimes not working on DS
- Fixed an issue with the briefing attribute
- Changed "Enable Captive Mode" tooltip to better descripe the behaviour

# 5.9
## ADDED
- Added an attribute to change sound volume of environment sounds
- Added GUI to quickly view all Eden Editor shortcuts (ALT + F1)

## CHANGED
- ChineseImp translation was updated
- Unit icons are now drawn above the unit
- Debug waypoints improvements
    - Marker text will only show the waypoint ID if nothing else changed compared to the previous marker
    - Markers are now connected by poly lines
    - Groups with only one waypoint e.g., units placed in the editor are now ignored (These changes should reduce the clutter on the map)
- Fixed RPT spam caused by 3den Radio if a song was in playlist but not available in-game anymore
- Batch Replace GUI has now a list with all vehicles to choose from. Pasting class names is still possible
- Batch Replace values are no longer saved persistently. They will be reset when the game is closed
- Fixed undefined variable in SRP code
- Fixed the height of some header controls
- Debug Options function will no longer run if not at least one action is activated
- Removed warning about custom userconfig
- Fixed left and right panel would be hidden by default
- Vanilla Config Viewer
    - Updated the design
    - Properties list can now be scrolled horizontally to view long values
- Texture Finder has an updated preview
- Slight performance improvement of the Inventory Manager
- Inventory Manager now also lists Oldman specific objects

# 5.8
## ADDED
- Added a tool to display vehicle hitpoints. Useful for the Advance Damage attribute
- Added missing translations for Advanced Damage attribute

## CHANGED
- Markers for 3D Path debugging are not oriented correctly
- Debug Option "Show FPS" is now in the "Draw" category
- Remove a debug message which was still left in code
- Updated overview text in Expansion Menu
- Fixed .RPT spam caused by missing translations
- DLC icons are not limited to 100m
- Draw functions optimized
- Fixed and issue with "Generate Steam Mission Description" function. It now auto pastes the description into the "Publish Scenario Window". Additionally, it now supports all DLCs (Was fixed by a hotfix)

# 5.7
## ADDED
- It is now possible to customize the available functionalities though an OPTIONAL userconfig. See https://github.com/R3voA3/3den-Enhanced/wiki/Customisation
- Added editor setting Dynamic View Distance. It removes the need to change view distance inside the editor by changing view distance depending on camera height
- Briefing attribute
- Added option to log var names of entities to clipboard
- Added some separators to the context menu
- Added another separator to the menu strip -> tools -> utilities folder
- Added more icons for the hold action attribute
- Added a debug options to draw trigger areas during preview
- Added new Advanced Damage attribute to replace the old system. The new attribute gets all available hit points dynamically and adds attribute controls for them

## CHANGED
- Batch Rename tool can now also rename markers
- Credits were moved to the 3den Enhanced Wiki
- FAQ was moved to the 3den Enhanced Wiki
- Column positions in 3DEN Camera Pos GUI were tweaked
- Various translation improvements
- It's now possible to search in the CfgSentences Browser if filter is set to "ALL"
- Documentation on GitHub has been updated
- Some internal functions have been hidden
- Fixed RPT spam caused by RscTestControlTypes and RscTestControlStyles (BI fix please? ;))
- Toggle DLC Icons runs now much faster and will not cause lag anymore
- Improved the way of exporting GUI base classes
- New logoSmall, logo and logoOver
- All log functions were merged into one function
- Fixed that Display3DENCopy would not have the correct height when using Log Object's Info function (BI fix please? ;))

- Attributes
    - Debug Path attribute is now part of debug options in Editor preferences
    - Merged onButtonDown code of attribute controls into onAttributeLoad functions
    - Added support to most attributes for localized text
    - Added missing tooltips for side toolbox controls
    - Feature Type and Terrain detail attribute controls were simplyfied
    - Task Patrol attribute uses an edit box now again to give the scenario editor more freedom
    - AI Features and AI Skill as well as Allow Fleeing attributes were merged into category AI
    - Editor Preferences are now using get3DENMissionAttribute instead of profileNamespace vars
    - Editable Objects (Zeus) would have an incorrect property name which would conflict with Dynamic Group attribute
    - Implementation for Debug Options in Eden Editor was changed
    - Fixed a bug which would cause the "Disable and Reset" button for the group marker attribute not to work
    - Size of Hold Action description has been slightly reduced
    - Map Indicator settings are now in the Misc category
    - All attributes now have "scriptName" defined for debugging
    - Added a Debug Tool to log all active scripts and mission EHs to .RPT
    - Text for Map Indicator attribute was improved
    - Visual appearance of many attributes were improved
    - Fixed Dynamic AI Skill attribute default value

- Inventory Manager
    - Fixed .RPT spam caused by the Inventory Manager
    - Fixed ACE items would not be properly sorted (Thanks to [KP] veteran29)
    - Fixed DLC icons would be incorrect if certain mods are loaded
    - Fixed item list box would sometimes not show items because it was scrolled down too far when selecting a different filter
    - Mines category was renamed to Explosives
    - Added localisation

- Texture Finder
    - Texture Finder is now faster. From 137 s down to 85 s to load all textures (Thanks to ConnorAU)
    - Another attempt to remove duplicated entries from Texture Finder (Thanks again to ConnorAU)
    - Texture Finder will now also scan arrays, thus find more textures (Thanks ConnorAU)
    - Texture Finder will now store textures in uiNamespace. That way it only has to search once
    - Progress text is now better formatted
    - Texture Finder now uses a CT_TREE with engine search
    - CTRL + F now focuses the search edit

- Functions Viewer
    - Functions Viewer is now the default functions viewer in the Debug Console (Will not overwrite button if Connor's Functions Viewer is loaded)
    - Functions Viewer can now view .inc and .hpp files as well as scripts used in missions and GUIs
    - Function list in Functions Viewer can now also be searched if functions are displayed as list
    - Behaviour of the "View on Biki" button in the Functions Viewer was improved
    - Functions counter in Functions Viewer works properly now also for campaign config and mission config
    - Open on Biki button in Functions Viewer is now actually a button instead of active text
    - Fixed a bug which would cause tree view control to be updated twice
    - It is now possible to toggle the left panel to increase space for code
    - Updated and added shortcuts
    - Last viewed file is now stored in profileNamespace. Restoring last viewed file is now reliable
    - Removed root entry (configFile, missionConfigFile and campaignConfigFile) from tree view
    - Mod icons are back due to recent optimisations
    - Fixed an issue with functions not being displayed if path definition was defined a bit differently (╯°□°）╯︵ ┻━┻)
    - Functions TAG is now always upper case

- 3DEN Radio
    - GUI was reworked
    - Search is now much faster
    - It is now possible to sort list by mods
    - List now also shows mod names
    - Added a timeline to the GUI
    - Some variables were moved from profileNamespace to uiNamespace
    - Help tooltip is now properly displayed
    - Music will now fade in slowly

- Variable Viewer
    - Columns of Variable Viewer can now be sorted
    - Loading the list is now ~four times faster
    - Fixed RPT 'spam 10:35:01 Bad conversion: bool' when opening the GUI (Thanks to Leopard20)
    - Fixed Variable Viewer not deselecting row on variable delete (Thanks to ConnorAU)

- Briefing Editor
    - Fixed missing localisation key

## REMOVED
- Credits GUI and all related functions
- Unused functions and config entries

# 5.6
## ADDED
- Vehicle Inventory Manager
- Added support for 3den Enhanced - Optionals. It will allow users to hide attributes and menu strip entries. Thanks to Freddo3000 (https://github.com/Freddo3000) for the idea and the help
- It's now possible to search a function in the Functions Viewer for a specific keyword
- Added CfgSentences Browser

## CHANGED
- Texture Finder will no longer list some textures multiple times
- Debug path attributes now uses is3DENPreview command to make sure it only runs in the editor
- Debug Options use is3DENPreview now
- Remove 3rdPartyTools folder from menu strip. Instead there is now a link to a Steam collection in the Help folder
- Removed obsolete stuff from configs
- Fixed missing string in 3den Radio
- 3DEN Cam Positions will now also show the time and date when the position was saved
- Fixed an issue in 3DEN Cam Positions which would show an error message when selecting a position
- German translation has recieved some fixes thanks to Mr-Melker
- Fixed a wrong condition in context menu causing some .RPT entries
- Fixed an issue which caused CTRL + X shortcut in the Functions Viewer to cause a script error
- Custom GUIs will no longer hide Eden Interface- Fixed a bug which would cause Grid Pattern to not work
- Increased max number of columns in Grid Pattern from 20 to 50
- Polish translation was updated by Krzyciu
- 3DEN Cam Positions will now properly display the tooltip for each entry
- Debug path attribute will only show for AI and player units now
- SPR Tickets attribute will only show for objectBrain
- Menu Strip was tidied up a bit

# 5.5
## CHANGED
- Italian translation was updated by zagor64bz
- Fixed a bug which caused Hold Action attribute to be always created in mission.sqm

# 5.4
## CHANGED
- Many translation tweaks, thanks to Poslovitch
- Fixed an issue with randomize directon tool

# 5.3
## CHANGED
- ENH_fnc_setOrientation can now reverse and randomise directions
- "Show Radio Message" would be cut off in the extraction GUI
- Updated Spanish translation (Thanks to arv187)
- Tweaked some functions
- Several fixes for Single Player respawn
## REMOVED
- Remove obsolete functions

# 5.2
## ADDED
- Tool to export loadouts in config format (Prior this change it would export in format of CfgRespawnInventory)
- Added tool to quickly export mission parameters (https://community.bistudio.com/wiki/Arma_3_Mission_Parameters)

## CHANGED
- It's no longer possible to switch to a unit which is about to respawn (Single Player Revive)
- Optimized Make Hostage attribute condition
- Handling of location list was changed
- Measure distance function now used ENH_fnc_floatToTime function
- Removed black in / black out effect when Eden Camera is set to custom position
- Renamed former "Export Loadout (Config)" to "Export Loadout (CfgRespawnInventory)
- Left and right arrows of custom slider controls now properly change the slider value
- Tweaked several attribute controls
- Improved localisations
- Added a delay before resetting captive mode on respawn (Single Player Respawn), to prevent the unit to be shot instantly again on respawn before they exit the animation
- Fixed some RPT spam
- Increase GUI height of Placement Tools

## REMOVED
- Removed some old, obsolete functions

# 5.1
## ADDED
- Added Single Player Respawn
- Added debug option to skip time
- Added debug option to change time multiplier
- Added Variable Browser to debug options

## CHANGED
- Debug options are now using BIS_fnc_holdAction
- Updated icon for debug options and tweaked several values
- Lenght of "laser beams" indicating view and aiming direction was shortened
- Mission ending attribute control was using EDIT_W_WIDE instead of EDIT_W resulting in slightly incorrect positioning
- Disabled ENH_DoStop in multiplayer https://github.com/R3voA3/3den-Enhanced/issues/85
- Changed attribute conditions from condition && condition to condition && code for best performance
- Fixed an issue where Hold Action attribute settings would not be saved
- Fixed an issue which caused Ambient Flyby and Airdrop attribute to be added to the mission.sqm unintentionally
- Debug option Teleport now teleports the player to the position at the center of the action icon
- Mission Ending attribute was only counting units killed by a player

# 5.0
## ADDED
- Context menu tool to move camera into first person view of selected entity
- Added shortcuts to GUIs to preview controls styles and types (menu strip)
- Added Debug Option to draw icons of nearby units and vehicles together with some basic information
- Added Debug Option to show waypoints of all group on the map
- Added Debug Option to enable unlimited ammo
- Added Debug Option to disable reload time
- Added Debug Option to draw view and aiming pos of AI
- Added Debug Option to teleport in 3D space
- Added Debug Option to disable weapon recoil
- Added Debug Option to disable weapon sway
- Added option to collapse asset browser (right panel) on startup
- Added option to collapse entity list (left panel) on startup
- Added option to hide left and rigt panel on startup

## CHANGED
- 3DEN Camera Positions UI now properly checks for incorrect description
- Icons updated
- Texture Finder
    - Will now search ~200.000 classes instead of ~30.000 for textures and images
    - Added search to Texture Finder tool
    - Optimized Texture Finder functions to be more performant (Thanks to shukari)
    - Search is now automatically started when UI is opened
    - Improved filter, now all none textures/images should be removed
    - Added progress bar to show listbox status
    - Update list button is now disable while list is updating
- Small improvements of the 3den Radio GUI
- Some general cleanup
- Fixed some typos in translation
- Batch Replace GUI will now properly display German localisation
- Added missing German Translations
- Hold Action and Ambient Animation attribute will no longer be written to mission.sqm for every entity which results in greatly reduced file sizes. Keep in mind that if the attribute was set once, it will remain in the mission.sqm even when reset to default values
- The menu for 3rd party tools was overhauled
- The airdrop attribute had a missplaced control
- The On Mission Debug attribute was overhauled
- German translation is now again 100% completed
- German translation was greatly polished and made consistent
- Description of Mission Ending attribute is now fully displayed when German localisation is shown
- Input description of Classname_1 Classname_2 Classname_3 Classname_n is now consistent throughout all controls
- Fixed Patrol tooltip. (Was showing -1 to disable instead of 0)
- Debug option Disable Stamina and Invincibility are now activated for all units in player's group
- Kill cursorObject is now only showing if cursorObject is not null
- Briefing Editor showed the wrong message when pressing the export button
- Module Information GUI got tweaked so that the description doesn't extent over the bottom of the control
- Fill Area tools max area was increased from 500x500 to 10.000 by 10.000

# 4.9
## ADDED
- Menu strip entry for additional 3rd party tools
- A UI to save 3den Camera positions in. You can use it to save interesting places

# 4.8
## CHANGED
- Updated Spanish translation by arv187

# 4.7
## ADDED
- An attribute to disable AIs radio protocol

## CHANGED
- Fixed mission semicolons in some configs
- Units using ambient animation will now reliably exit their animation if enemies are nearby

# 4.6
## CHANGED
- Fixed incorrect labeling of Dynamic Skill controls
- Added check to prevent player from exiting hostage state

# 4.5
## CHANGED
- Animations will now be exited when unit enters combat mode

# 4.4
## CHANGED
- Fixed Log position 3D tool
- Fixed Log classes as string tool
- Improved performance of functions viewer

# 4.3
## ADDED
- Scenario Attributes Manager
- Link to Mission Optimisation Biki page
- DisableAI "radioprotocol"
- Attribute to end mission after certain number of units of given side were killed (e.g. civilian casualties)
- Added Editor Attribute to toggle Entity Counter in status bar- Added a tool to quickly toggle simulation of selected objects
- Added a tool to quickly setup a simple extraction
- Script Commands Viewer to menu strip -> tools -> utilities
- A function to convert floats to time format minutes:seconds

## CHANGED
- Combo Box controls were replaced with Toolbox controls if possible
- Code cleanup
- Debug console now uses CTRL+D as shortcut (Same as CBA)
- Tweaked visuals of custom GUIs (Sliders, Background)
- Awareness attribute now uses hintSilent instead of custom display
- Some attributes showed wrong tooltips
- Functions Viewer can now be accessed by pressing ALT + F (Same as CBA)
- Config viewer can now be opened by pressing ALT + C
- GUIs use Eden Editor controls now
- 3den Radio got a new design
- Fixed some issues with 3den Radio sometimes not playing music
- Texture finder won't display a texture on start up
- Module Information GUI got some visual tweaks
- Texture Finder has now a filter option
- Batch Replace GUI would not save last used value correctly
- Tweaked layout of Batch Replace GUI
- Tweaked layout for Texture Finder
- Almost all GUIs use Pixel Grid System now and scale correctly
- Layouts of various GUIs were improved
- Functions of various GUIs were improved
- Updated Russian translation thanks to lexx__1
- Improved height of attribute control groups and positioning of controls
- Group Marker attribute has got a new attribute control and more options
- Moved code for attribute controls into functions library
- Establishing Shot attribute was overhauled and optimized
- Ambient Flyby attribute was overhauled and optimized
- Intro Text attribute was overhauled and optimized
- Airdrop Shot attribute was overhauled and optimized
- Some attributes have now a button to reset and disable them- All substantial attributes have now got their own attribute control, therefore no unnecessary missionNamespace variables are declared- All mission attribute are now collapsed by default
- Fixed various missing semicolons
- Fixed an issue where Preview Debug options would not apply to player when option "Play the Character" was used to preview the scenario
- Changed 3den notification for ENH_fnc_loadoutTools
- Added various new internal macros
- All substantial attributes now have a proper description of what they do, and links to further information if available- Rearanged some scenario attributes
- Intro text attribute now supports BIS_fnc_infoText
- Intro text attribute has a new control with images to select the intro type
- Values of Dynamic skill attributes are now handled by attribute control and not writting into mission namespace variables
- FunctionsViewer
    - Functions Viewer features now several different modes for sorting functions
    - Functions were rewritten
    - Shows number of available functions
    - Added button which leads to corresponding Biki page of the function (Keep in mind that not all functions might be documented there)
    - Functions viewer is now available in the debug console, together with the vanilla one. See the "fx" icon in the top right corner
        This also solves the issue where 3den Enhanced was incompatible with Extended Debug Console by Connor
    - Every function now shows the logo of the mod it was introduced with
    - Functions Viewer now uses pixel grid system
    - Fixed an issue where recompiling selected function wasn't possible
    - Removed X button and replaced it with the close button in the lower right corner to be consitent with all other UIs in Eden Editor
    - Functions Viewer shows mod icons again
    - Functions Viewer now displays line numbers

- Updated and revised Czech translation thanks to XerXesCZ
- Most functions which interact with eden entities will now exit and show a notification if no entities are selected
- Merged serveral functions into one
- Removed ENH_fnc_logMissionAttributes
- Placement Tools GUI now also supports setting of object orientation
- Added fine control to Placement Tools GUI
- Batch Replace GUI is now only opened when objects are selected
- Center of Placement Tools will now stay the same until reset- Replaced waitUntil {time > x} with sleep x to prevent inconsistencies in multiplier- Old garrison UI is back
- Added hold action attribute (WIP)
- Fixed feature type attribute would use incorrect data type
- Ambient Animation attribute uses Listbox control instead of Combobox control
- Ambient Animation attribute was overhauled, it now works in multiplayer
- Fixed an issue where Intro Text would be displayed immediately on dedicated server (delay was ignored)
- Added more ambient animations
- Ambient animations are now properly initialized when a new terrain or mission is loaded
- Time Multiplier will no longer be executed when value is 1
- Updated credits
- Task Patrol attribute now uses a slider control
- Logging of multiple map grid positions is now possible. Only unique value will be logged
- Faction are now logged to clipboard without [ ]
- Added context menu enty to log classes in format "class1", "class2",..- Added new folder to menu strip
- Added option to garrision tool to change stance of units
- Fixed missing shortcuts for some tools
- Fixed Switch Time would not properly set overcast, rain and fog to 0. Change is forced now- Song duration in 3den Radio is no displayed in format minutes:seconds (00:00)

## REMOVED
- Import/Export scenario attributes. Scenario Attribute Manager takes care of that now
- Removed on Event Code Attributes (Too complex for a simple attribute)
- Color Picker was removed. Use https://forums.bohemia.net/forums/topic/222104-color-picker/ instead
- Removed weapon sway and recoil attribute due to issues on dedicated server

# 4.2
## CHANGED
- Updated credits
- Briefing Editor: If marker has no name, the variable name is displayed instead
- Condition for Airdrop attribute is now checked every second. Instead of every frame
- Updated polish translation
- Exporting inventory to config is now possible with GUI
- Shortcut for Remove Vest tool was removed because it was blocking a default Eden action
- Functions Viewer performs better now
- Debug Console now uses the Eden Enhanced Functions Viewer
- ENH_fnc_FunctionsViewer was split into multiple function files

## REMOVED
- Export Inventory to Config GUI->Wasn't needed any longer
- Removed obsolete Icons

## KNOWN ISSUES
- Event Code Attribute does not work on dedicated servers
- Stay on Position attribute sometimes fails on dedicated server

# 4.1
## ADDED
- Tools to remove heargear, googles and weapons from characters
- Tool to generate mission description for the Steam page (Steam formatting is not supported because A3 does not support it)
- Move to To-do List attribute for comments
- Link to ARMAnet Eden Editor tutorial to the help section
- Brand new Placement Tools GUI

## CHANGED
- Debug Path attribute now also draws map markers
- Log Mission Attributes was moved from the context menu to the menu strip
- Some localisation tweaks
- Dynamic AI Skill attribute now uses Sliders instead of edit boxes
- Distance in between marker of the Debug Path attribute was increased from 5 m to 20 m
- Default value for the Establishing Shot attribute
- In the menu strip, the vanilla Functions Viewer was replaced by the 3den Enhanced Functions Viewer
- It's now possible to add markers in the Briefing Editor by double clicking on the marker list
- Briefing editor listboxes now have tooltips, explaining the controls
- The height set in the Airdrop attribute has now a small variance to prevent all units to touch the ground at the same time
- Optimized attribute controls
- Updated link to Scripting for Beginners help. (The old one was from 2013)
- Fixed a bug which caused dynamic AI skill to not work if default values were used
- Ambient Flyby does now use a vanilla control to set the speed
- Ambient Flyby attribute now has default values to fall back to
- It's now possible to export scenarios to sqf which were build with 3den Enhanced
- Visibility attribute is now unlocked for all entities
- Arsenal attribute is now unlocked for all entities
- Complete Overhaul of the Placement Tools GUI
- Garrison Buildings was removed from Context Menu and integrated into the new Placement Tools GUI
- Many GUI related function tweaks
- ... from translation have been removed. Entries use opensNewWindowAttribute now
- Remove ... from folders. They do not open a new window
- Function used for the Location List was completely overhauled
- Ambient Flyby attribute was overhauled, it can no be disabled by a missionNamespace variable, see tooltip

## REMOVED

## KNOWN ISSUES
- Event Code Attribute does not work on dedicated servers
- Stay on Position attribute sometimes fails on dedicated server

# 4.0
## CHANGED
- Feature Type attribute would sometimes cause issues because of wrong datatype. Type STRING and NUMBER can now be handled for backwards compatibility
- Readded Stay on Position attribute

## KNOWN ISSUES
- Event Code Attribute does not work on dedicated servers
- Stay on Position attribute sometime fails on dedicated server

# 3.9
## ADDED
- DiableAI "NVG" attribute
- Disable AI "LIGHTS" attribute

## CHANGED
- Updated translation, thanks to IllidanS4

## REMOVED
- Stay on Position attribute. It was not behaving as expected
## KNOWN ISSUES
- Event Code Attribute does not work on dedicated servers

# 3.8
## ADDED
- Polish translation by Kofeina101

## CHANGED
- Reduced distance from which a hostage can be freed from 15m to 2m
- If the hostage is dead, it cannot be freed anymore
- Some localisation fixes
- Changed shortcut CTRL+Q to CTRL+P to prevent issues with another mod
- Credits have they own UI now because CfgORBAT wouldn't work sometimes
- It's now possible to measure distance between two entities

# 3.7
## ADDED
- Translation of credits

## CHANGED
- Expanded French translation thanks to pokertour
- Updated some French, Czech and Chinesesimple thanks to TaktischerSpeck
- Name of the pbo changed from 3den Enhanced to 3den_enhanced to prevent a crash on linux server (Thanks to Dedmen)

# 3.6
## ADDED
- Added new function ENH_fnc_all3DENSelected
- A control to the statusbar which shows number of selected entities
- A tool to export and import mission attributes
- An airdrop mission attribute
- Many missing translations
- New function ENH_fnc_exportWithLB

## CHANGED
- Some shortcuts were changed for pattern tools
- Improved translation of some context menu entries
- Order of some context menu entries was changed
- Log 3DEN Entity IDs now logs ids of all selected objects
- Tool in menu strip are now sorted alphabetically
- New tool folder "GUI Tools"
- Updated credits
- Updates translation
- Spanish translation was updated by "TaktischerSpeck"
- Updated all log functions
- 3den Enhanced function viewer now correctly restores last viewed function

## REMOVED
- Removed obsolete functions
- Show mission stats tool. It's now in the statusbar

# 3.5
## CHANGED
- Added "A3_Data_F_Sams_Loadorder" to CfgPatches to prevent overwriting of config entries

## ADDED
- Added link to 3den Enhanced Youtube videos (Menu Strip -> About 3den Enhanced)
- Added Action Creator GUI
- Added Path Debugging attribute

# 3.4
## CHANGED
- Added missing semicolon
- Chinese translation was added by Jason Bert
- Updated credits
- On preview debug attribute state was not shared between different missions

## ADDED
- Loadout tool to remove NVGs from several units at once
- Loadout tool to remove vests from several units at once
- Added link to 3den Enhanced Youtube videos (Menu Strip -> About 3den Enhanced)
- Added Action Creator GUI
- Added Path Debugging attribute

# 3.3
## CHANGED
- Some shortcuts were interfering with vanilla shortcuts

# 3.2
## CHANGED
- Fixed some issues with new shortcuts

# 3.1
## ADDED
- Added missing attribute to disable map indicators
- Respawn tickets for civilian side
- 3den Radio has got an incremental seach now
- 3den Enhanced is now using the CBA versioning system (Only if CBA is used)
- New functions viewer with incremental search, new design, tree view etc
## CHANGED
- Log object info tool has been overhauled and uses display3denCopy now
- Pattern tools can now be used multiple times without reloading the GUI
- Serveral logic errors in pattern tools GUI and its functions
- The export loadout to config tool has got a GUI now- Some minor function improvements
- 3den Radio functionalities were mostly rewritten to solve serveral issues and make code more efficient
- Readded server key
- All GUIs are now using the BackgroundDisable and BackgroundDisableTiles controls
- Select Image GUI when publishing a mission to Steam has been widened to allow the ctrlTree to expand further
- Some general GUI overhauls
- Many shortcuts have been updated. Check the Menu Strip for the new shortcuts
        - Briefing editor shortcut was changed from CTRL + B to ALT + B
        - Texture Finder can now be opened by pretting ALT + T
        - Grid, Line, Grid & Circular Pattern tools can now be opened by a shortcut - Clear chat can now be performed by pressing ALT + CTRL + C
        - All debug tools have got a shortcut now
        - Loadout tools can now be accessed by CTRL + SHIFT shortcuts
        - Many shortcuts have been updated. Check the Menu Strip for the new shortcuts
- Added search icon next to search edit control in 3den Radio
- 3den Radio will now loop through playlist again one enabled

## REMOVED
- Disable team switch attribute, it's already available in the multiplayer attribute section
- Obsolete functions

## TRANSLATION
- Removed obsolete translations
- Changed German translation of respawn tickets
- Improved german translation of task patrol tooltip
- Many stringtable entries have been renamed to make them more consistent
- Fixed some translations
- A few missing translations in the menu strip
- Missing 3den Radio translation

# 3.0.01
- Added new logo (Steam)

# 3.0
## ADDED
- Credits (Menu Strip -> About 3den Enhanced -> Credits...) Shows all contributors. If I forgot about someone please let me know- Added tool to log map grid position to clipboard

## CHANGED
- Some base defines clean up
- Right-clicking on a group icon will now also show "Garrison Buildings..."
- Log 3den Entity ID is now available for all Eden entities
- Conditions for context menu entries were improved e.g, "Log Positions (3D) won't show for markers"
- Improved save loadout attribute (code) //Needs testing!
- Improved code (save loadout)
- Improved code (introText)
- Improved code (visual settings)
- Improved code (establishing shot)
- Updated localisation
- New mod logo/icon
- DebugOptions - Player was not able to edit objects in Zeus interface

## REMOVED
- Obsolete function

# 2.9
## ADDED
- Link to FAQ

# 2.8
## CHANGED
- Fixed error message caused by the visibility attribute
- Improved disableAI attribute expression, thanks to shukari
- Fixed issue with Eden removing Zeus in multiplayer
- Some improvements to translation
- Functions overview shows now functions sorted by functionality
- Replaced icons in menu strip to indicate folders better
- Session timer was not working after preview ended

## ADDED
- Menu strip tool to quickly toggle simple object state
- Context menu tool to log 2D positions of selected entites to clipboard
- Added help entry for description.ext
- "About 3den++" menu strip category

## REMOVED
- Removed "Export Arsenal Templates" was not ment to be released
- Tool to grab compositions (Was not working reliably)
- Removed changelog UI
- Youtube links. Most content was outdated. If you have suggestions for good up-to-date video tutorials let me know!
- Removed assets overview from help menu. It's quicker to just search for object directly within the Eden interface
- Obsolete function call via Eden EH

# 2.7
## ADDED
- It's now possible to either export GUI base classes of Eden, default or all
- Added missing translation
- Tool to quickly clear chat. Very handy when debugging via systemChat in the Editor
- Tool to quickly delete all empty layers
- Added grid pattern tool
- Added tool to export all Arsenal loadout templates for backup
- On preview debug (Those settings will only work during mission preview and won't influence the published scenario)
    - Show all units on map
    - Disable damage
    - Toggle captive mode
    - Enable bullet tracing
    - Enable Virtual Garage
    - Enable Virtual Arsenal
    - Disable stamina
    - Enable Zeus
    - Show awareness of all sides
    - Options to quickly kill all units of given side during scenario preview

## CHANGED
- Removed obsolete function call from ENH_Changelog GUI
- Changed/removed some icons from menu strip
- Reordered menu strip tools for easier access
- Fixed alot of missing/incorrect translations(German)
- The debug tool "Log Game Info" will now also copy the list of mods used
- Some improvements to the location list
- Increased size of Module Description GUI to improve legibility
- GUI of pattern tools was improved. Unused controls are now 50% faded and disabled. Used controls are now focused when GUI is opened for quicker usage- Some config cleanup
- Translation cleanup
- Translation improvements

## REMOVED
- Export/import camera parameters (Functionality is available through the vanilla "Splendid Camera")
- Obsolete translations
- FPS gauge in Eden (It's available now during preview)
- Removed debug triggers (They are available now during preview, see "Preferences")

# 2.6
## ADDED
- Tool to export selected Eden objects to sqf format(Thanks to Theassassinzz for sharing)
- Context menu function to show Eden entity ID
- Attribute to remove entity from garbage collector
- The location list has been expanded and now shows more points of interest

## CHANGED
- AI will now exit animations when damaged or in combat mode
- Fixed issue with garrison function not detecting building positions in some cases (Thanks to http://steamcommunity.com/id/Aestheticwww)
- Several translation improvements
- Fixed FPS Gauge and session timer would not work when a scenario was loaded or created
- Improved appearance of combo box control types
- Some config cleanup
- Measure distance functionality was rewritten and improved:
    If distance is measured in 3D view, then a line is drawn from point A to B showing the direct path
    If map is opened, then markers are drawn from point A to B showing the direct path
- Several menu entriess were missing "..." to indicate they are opening a new window

# 2.5
## ADDED
- Attribute which adds all alive entities to allCurators regulary during a mission
- Color picker. Can be found in the debug tools category
- Attribute to disable team switch
- Attribute to disable mine detection for AI units
- Attribute to disable weapon aim for AI units
- Attribute to add a flag to vehicles, units and flag poles
- Attribute to prevent AI from moving into position at the beginning on missions
- Context menu entry to quickly group selected entities to the player unit
- Translation for debug triggers

## CHANGED
- Some default attribute values
- Pattern tools feature has got its own GUI now
- Some attributes are now hidden where not appropriate
- Fixed misleading translation
- All functions were sorted into proper categories
- Some performance improvements of the 3den Radio code
- Improved some translations
- Improved reveal code (debug trigger)
- Updated Czech translation, thanks to XerXesCZ

## REMOVED
- Pattern tool settings from preferences menu
- Some functions became obsolete with the new pattern tool GUI
- Removed "Stay on road" attribute (The command seems to not have the desired effect and causes more issues)
- Hide terrain objects trigger (There is a vanilla module for this)

# 2.4
## CHANGED
- "Arsenal" and "Add Gun Light" attributes were missing there default values

# 2.3
## CHANGED
- "Arsenal" and "Add Gun Light" attribute should not be activated by default

# 2.2
## ADDED
- Tool to log positions of multiple objects

## CHANGED
- Garrison function feature now a custom UI
- ENH_fnc_garrisonNearest.sqf has been improved
- One wasn't able to play a song from the playlist via double click
- "Measure Distance" tool now also works when the map is opened
- "Establishing Shot" attribute has been overhauled and should now be less performance hungry and more reliable

## REMOVED
- Garrison settings were removed from the preferences menu
- Removed obsolete controls
- Removed "Remove x items" attributes. Conflict with Eden editor behaviour

# 2.1
## CHANGED
- Replaced 3den Radio defines with variables to improve performance
- Changelog can now be viewed in game (Menu Strip -> Help -> 3den Enhanced Changelog)
- Added shortcut for opening 3den Radio (ALT-R)
- Removed some obsolete config definitions
- Removed some ugly or unused icons
- Config clean up
- LogoSmall.paa and logo.paa are now packed
- "batch naming" features now a GUI, making the naming of large quantities of entities much quicker
- New mod logo & picture

## REMOVED
- Removed batch naming from preferences

# 2.0
## CHANGED
- Updated Spanish translation (kudos to arv187)
- Fixed some log entries
- Volume of 3den Radio can no be controlled more precisely via the arrows
- Overhauled the intro text mission attribute
- 3den Radio overhaul
- Complete overhaul of the briefing editor, added expression, image width and heigth. Fixed scaling issues, improved code & layout
- All custom UIs are now using the same defines in order to make them consistent
- Various translation tweaks

## REMOVED

# 1.9
## ADDED
- Attribute to set weapon sway coef
- Tool to quickly name multiple entities
- Debug trigger for healing and repairing
- Attribute to set the feature type
- Ambient animations. They only work in single player now and can be found in the "State" category- Added Arma 3 Utilities (Thanks to KK for those awesome tools)
- Added attribute to set weapon recoil coef
- Addes spanish translation (kudos to arv187)

## CHANGED
- Debug trigger "Toggle Invulnerability" is now using isDamageAllowed and also applies to player vehicle
- Fixed error when debug trigger "Reveal Units" was activated twice within short time
- Briefing editor can now be securily be closed by pressing Ctrl + B or ESC
- A new template can now be loaded by double clicking on the template list, preventing unwanted loading and overwriting
- Improved code behind time multiplier control

## REMOVED

# 1.8
## ADDED
- Scripting examples by Foxhound International (Help section)
- Readded the UAV intro (establishing shot), hopefully working more reliably than before
- The intro text attribute now supports a new type of intro text used in the Apex Protocol campaign
- Readded the "hide terrain objects" context menu entry
- Added tool to export GUI base classes (debug tool)
- Added tool to view default GUI Grids (debug tool)
- Added tool to delete vehicle crews quickly
- Added link to Gunter Severloh's Ai Compilation List
- Added Czech translation thanks to XerXesCZ
- Added French translation thanks to Artenis
- New tool to create "debug triggers" to make testing missions easier for beginners

## CHANGED
- Fixed issue with invisible logic creation causing low FPS in missions with many players
- Improved random patrol function
- Sound volume and random music attribute will no longer run on headless clients
- Various tooltip improvements
- The log faction names tool was moved from the menu strip to the context menu
- Tools in the menu strip are now better sorted
- Some tool icons were improved/changed
- Improved measure-distance function
- Fixed the reverse direction tool
- Serveral small improvements to the briefing editor functions
- Line pattern tool will no longer change the rotation
- Value of the FPS gauge is now rounded
- FPS gauge is now updated every second instead of every 1/2 second
- Default value of the 3DEN Radio volume was changed from 100% to 25%
- Preference menu was overhauled
- Default values for the tools were tweaked to make more sense
- Fill area tools will now use screen center as origin
- Garrison radius attribute is now using a edit control
- Multiple improvements of tooltips and display names
- Most placement tools can now be accessed via CTRL + numpad
- Circular pattern tool uses now center of the screen as initial position
- Improved session timer code
- Custom status bar controls have now the same visual style as the vanilla controls
- Mission stats tool now displays the number of simple objects
- Context menu entries are now only shown when necessary
- Improved tooltip for the "on event" attributes
- Game info tool now also logs architecture (x64, x86)
- Fixed missing localisation when using the garrison function
- Removed obsolete variable from fn_getModuleDescription.sqf
- Toggle Map IDs would only work when the map was opened manually beforehand
- 3den Radio was overhauled and can now be controlled via a custom GUI
- Improved position of session timer (Should not overlap with other controls anymore)
- Improved German translation (thanks to KiritoKun223)
- Units traits attribute is now using a new control type
- Garrison radius is now using a new control type
- Random patrol was renamed to Task Patrol and moved to the group attributes
- Task patrol is now using BIS_fnc_taskPatrol
- Updated stringtable.xml

## REMOVED
- Tutorials
- Preload arsenal settings
- Warning messages
- Set z = 0 tool (It's available in the context menu -> transform)
- Log class name tool (Functionality already exists)
- Ambient animations (Too many issues in multiplayer and general incompatibility with Eden)

# 1.7
## ADDED
- Tool to display module description
- Save gear on respawn (readded)

## CHANGED
- Fixed issue with toggle grass function
- Fixed the dynamic group attribute
- A few new help links

# 1.6 HOTFIX
## CHANGED
- Warning messages would not be displayed properly
- Added missing server key

# 1.6
## CHANGED
- Fixed position of song name display
- Display for name of currently played song is now integrated into the EDEN statusbar, should now properly scale with different resolutions and display sizes
- Improved delay attribute for intro text
- Some config clean-up
- Improved behaviour and speed mode control of random patrol
- Improved speed mode control for ambient flyby
- Improved some tooltips
- Fixed bug caused by event att- Fixed some inconsistencies in the configs
- Various improvements to the Random Patrol code with the goal to improve reliability
- Replaced some of my own translations with ones from BIS
- Improved code of remove NVG attribute
- Various function improvements
- Improve unit traits attribute (Attribute needs to be saved once, to apply the new values)
- Advanced skill was missing its Enh TAG
- Fixed issue where the garrison function would sometimes recieve a wrong data type
- Added tutorial for the garrison functionality
- Added ... to all menu strip entry which open a subfolder or new page. Mainly to be on par with the BIS design guidelines
- New icon for the tools folder
- Free Hostage action is now using the vanilla hold action system
- Unit which has the "Make Hostage" att. enabled, will now automatically change its animation in Eden
- Ambient animation should now work in mp again as expected (fingers crossed)
- Sorted all tools into new folders
- Improved shortcuts for tools and context menu entries
- Some more stringtable cleanup
- Some more function improvements
- Waypoints of the random patrol attribute are not visibel anymore
- The Log Game Info tool now also exports information about the resolution and UI scale
- All translations are now tagged with "ENH" to make them unique
- Serveral localisation tweaks
- Serveral tweaks to the random patrol function (random patrol attribute)
- Fixed an issue with grass not being visible
- The code for all mission attribute was overhauled. It should now properly execute for each JIP player without effecting players which were ingame already

## ADDED
- Added tool to set all selected entities to ATL/ASL 0
- Select new song button for the 3den Radio (Implemented into the status bar)
- One can now set the combat mode and formation of a random patrol
- Current song name played by 3DEN Radio is now display as a tooltip in the status bar
- Added disableAI "Path"
- Added tutorial for the garrison function
- Added tutorial for 3den Radio
- Added shortcuts for various tools and context menu entries
- Added help entry redirecting to youtube tutorials
- A warning message is now shown when patrol radius is smaller than 51 m to prevent unexpected behaviour- Session timer
- A tool to show amount of objects placed in a mission
- A new tool which retrieves all product information and formats it so it can directly be used inside a bug report etc- Added help link to KK's Blog
- Added Briefing Editor
- Added loadout tool. Select one or multiple units and use the "Copy Loadout" tool. Then select the units you want the loadout to apply to. If multiply loadouts were saved. A random one will be selected for each unit
- Warning message when new scenario is opened (If accepted it won't appear again)
- Added tool to measure distance2D, 3D and travel time between two points
- Added tool to quickly place units in a line
- Added tool to quickly reverse direction of selected units
- Added circular pattern tool
- Add tool to quickly change mission time to daylight for editing, using the tool again, will reset the time back to where it was. Does not effect the original time set via the intel attribute
- Added tools to change orientation of selected objects to exactly north, east, west or south
- Added help entry which links to the Mission Presentation Wiki page
- Context menu entry to set player as trigger owner of selected trigger/s
- Added help entry which links to kylania's scripting examples
- Moved help entries into separated folders
- Attribute to force unit to walk
- Tool to quickly export inventory of selected units in a config format used for CfgRespawnInventory
- Added version attribute to CfgPatches for internal use
- Improve the way the dev branch warning is displayed
- Added tool to display FPS while in Eden
- Added a tool to export and import eden camera params, like position, direction and pitch/bank. Mainly for debug purpose, but be creative. The output can also be pasted into BIS' Splendid Camera
- Added tool to quickly toggle Grass on/off (This will not effect the mission in any way)

## REMOVED
- Removed suppression level att- Removed fatigue level att- Removed obsolete entries from the stringtable.xml
- Removed side attribute from ambient fly by (Will always be civilian anyway)
- Removed rainbow att. (Functionality was not 100% clear to the user)
- Removed "hide map object" context menu entry (The code is not properly optimised and reliable yet)
- Clear vehicle cargo att. A vanilla solution got introduced
- Removed unit insignia attribute. A vanilla solution got introduced
- Removed advanced fog settings. A vanilla solution got introduced
- Remove stance att. A vanilla solution got introduced
- Advanced ending attribute (Needs further testing)
- Unit marker attribute (Not reliable)
- Establishing shot attribute (Not mp compatible, most likely not fixable)
- Removed save gear multiplayer attribute (on respawn the gear set in Eden is not automatically reapplied)
- Duplicated entry in stringtable.xml
- Removed some none-working animations

# 1.5
## CHANGED
- CfgPatches was changed to the up-to-date format
- 3den Enhanced tools now have their own folder
- Default insignia is an empty string now
- Some code improvements for the insignia control
- Overhauled most control configs
- Fixed script error which would appear when 3den preferences were not confirmed and the garrison function was used
- Replaced garrisonRadius combobox with slider control
- Fixed aspec ratio of loiter attribute
- Reduced size of insignia attribute (Please report any issues, controls might overlap)
- Moved most of the code from control configs to global functions
- Preferences are now applied when a preview ends, or a new scenario is created- Ambient animation attribute is now easier to use:
- To change the type of animation, simply select the new one and press Ok. The new animation is instantly applied In older versions, one had to deactivate the animation first- Activate checkbox from ambient animation att. removed, is now handled by the animation type checkbox (Above changes also apply to ambient combat animation att.)
NOTE: There are still quite a few bugs with the ambient anims. However, those I most likely will never be able to solve. We simply need a better BIS function- Improved code execution for multiplayer missions (Thanks to KK for his note on the remoteExec wiki page)
- Respawn tickets are now not always set to 0 when untouched
- Corrected some localisations
- Blacklisted another music track in the playMusic fnc
- Improved advanced fog attribute
- Replaced custom control for view distance att. with a edit box
- Improved view distance code
- All class names are not using the Enh TAG- Removed activate checkbox from intro text attribute. It can not be disable by leaving the delay undefined(empty)
- Changed config name of save gear attribute
- Improved code for hide terrain object trigger
- Improve ENH_fnc_playMusic, it now filters out classes which have no soundtrack defined and it's slightly faster
- Insignias are now also read from the local missionConfigfile

## ADDED
- Tool to recompile functions
- Five animations
- Several new functions for internal use
- Attribute to deactivate thermal optics for given vehicle
- Attribute to deactivate night vision optics for given vehicle
- Added tool to quickly export faction names
- Added icon for "log" context menu folder
- Added icon for "3den Enhanced" tool folder
- Added attribute for OnKilledEvent
- Added attribute for OnRespawnEvent
- Added attribute for OnDamagedEvent
- Added attribute to set the fleeing value for a unit
- Added unit marker attribute
- Flyby mission attribute
- Added setMass attribute
- Added advanced briefing att
# 1.4
## CHANGED
- Fixed position of time multiplier attribute
- Time multiplier edit box is now properly formatted
- Fixed position of song name display
- Fixed position of view distance setting attribute
- Removed some obsolete code from control configs

## ADDED
- Added attribute for rainbow probability
- Added insignia attribute
- Added preference attribute to enable preloading of the Arsenal -> Preferences-> Misc

## TRANSLATION
- Added translation for rainbow attribute
- Added translation for insignia attribute
- Corrected camouCoef & audibleCoef tooltip

# 1.3.1
## CHANGED
- Fixed a bug which would reset the unit traits controls

# 1.3
## ADDED
- One can now define a delay for the intro text attribute
- Attribute for unit traits

- Added hostage attribute:
    A unit can now be taken hostage. Every player including JIP will have an action to free the Hostage Mission designers can check whether the unit is hostage or not by retrieving the following variable:
    _unit getVariable "ENH_isHostage"; (true, is hostage/false, isn't hostage)

## CHANGED
- UAV intro center position attribute tooltip was using a wrong string
- Removed the tooltip from Advanced Damage Attributes
- UAV intro loiter direction is now using a better control

## TRANSLATION
- Added German translation for "Hide Map Objects" context menu entry
- Added German translation for unit traits attribute
- Added German translation for intro text delay
- Updated French translation (thanks to solentis)

# 1.2.1
- Completely overhauled the garrison function
1. Select the units/objects you want to place in houses and place them near the buildings
2. Open the Context menu (right click on one of the selected units) -> select Edit -> Garrison Buildings
3. Objects/Units will now be automatically be placed inside buildings, you'll recieve a msg in case some units/objects could no be placed
4. The size and coverage of the area can be changed in the preferences menu of Eden

# 1.2
## ADDED
- Function to quickly garrison placed building. Settings can be changed in the preferences
- Attribute to toggle map object IDs on/off
- Attribute to turn off/on vehicles engines
- English, German and Italian (partially) translation
- Attribute to disable BIS revive for specific units
- Attribute to remove all FAKs from a unit
- Mission attribute to initialise BIS Dynamic Groups
- Mission attribute to create an establishing shot
- Mission attribute for display text on mission start
- Currently played song of the playMusic preference attribute is now displayed at the bottom of the screen
- Attribute to play random music at the beginning of the mission -> Scenario Attributs -> Music, Sound & Radiosettings
- Attribute to set respawn tickets for all sides
- Version check. Player will now recieve a warning if game version is greater than required version and dev branch is used
- Version check function
- French translation

## CHANGED
- Added check to prevent vanilla fog to be overwritten by advanced fog
- Music loop is not restarted every time the preference settings are confirmed
- Some attributes were executed where not needed
- Completely overhauled the task patrol attribute, one can now set the number of waypoints, radius of the area, behaviour of unit/group, and speed of unit/group
- Removed an unwanted radio sound from playMusic function
- All functions, variables and attribute properties are now using the same tag (ENH_)
- Various function improvements
- Some categories where renamed
- Tooltips where improved
- Save gear on respawn attribute was moved to mission settings -> respawn and will now be applied to all playable units automatically
- Changes logo which is display in the expansion menu
- Improved fn_logClassName.sqf
- Added improved control for view distance setting
- Time multiplier settings uses a custom control with slider and edit box
- Removed toggleMapIDs attribute from Preferences and moved it to the Menu Strip -> Tools
- Added ID icon for ToggleMapIDs tool
- New server key
- Log classname function would not return classname of logics and modules

## REMOVED
- Custom compositions

# 1.1
## ADDED
- Time multiplier to environment attribute
- Advanced fog settings to environment attributes- Remove map attribute
- Remove GPS attribute
- Ambient combat animation
- View distance and disable grass option to environment mission attribute (Will be executed globally and for JIP playes)
- Attribute to create a small mission intro containing three lines (See scenario attribute -> general)
- Quick links for:(Can be found in the menu strip -> help)
    - Arma 3 Assets
    - Arma 3 Function Overview
    - 3den Enhanced Forum thread
- Ability to quickly copy class name of selected unit to clipboard
- Ability to quickly set random rotation for all selected entities
- Attribute to force walk
- Attribute to disallow sprinting
- Rearranged attributes into different classes
- Mission attribute for radio, music and sound volume
- Suppression attribute
- Fatigue level attribute
- Attribute to enable headlights of empty vehicles

## CHANGED
- Renamed some attributes
- Save gear now also works on dedicated, not only on hosted server (Thanks to larrow!)
- Crew in immobile is now only shown for vehicle entities
- Fixed typo in ambient animation tooltip
- Ambient anim attribute is now using combo boxes
- AllowCrewImmobile attribute has been tweaked
- Shortened ambient anim init time
- Removed some ambient animation that would not work, e.g sit and treat_injured

## REMOVED
- Removed composition tool
- Removed custom triggers (If used, remove those from your mission, otherwise it won't run without 3den Enhanced mod, sorry for the inconvinience that caused)
