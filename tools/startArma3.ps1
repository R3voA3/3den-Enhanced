Start-Process "C:\Program Files (x86)\Steam\steamapps\common\Arma 3\arma3_x64.exe" -argumentList @(
  "-debug",
  "-filePatching",
  "-noSplash",
  "-showScriptErrors",
  "-skipIntro",
  "-noPause",
  '"-mod=!Workshop\@Pythia;Mods\@3den Enhanced v6.2;!Workshop\@Music Pack;!Workshop\@3Den Stringtable Viewer;!Workshop\@7erra''s Editing Extensions"',
  '"C:\Users\rober\OneDrive\Dokumente\Arma 3 - Other Profiles\R3vo\missions\TESTING\scriptLibrary.VR\mission.sqm"'
  #should use $env:USERPROFILE
)