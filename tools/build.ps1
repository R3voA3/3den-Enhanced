param($DoPublish = "false")

$ProjectFolder = "$env:OneDrive\Games\Arma 3\Arma 3 Mods\3den-Enhanced"
$ModVersion = "6.4.1" #Get-Content -Path "$ProjectFolder\tools\`$VERSION`$"
$TargetFolder = "${env:ProgramFiles(x86)}\Steam\steamapps\common\Arma 3\Mods\@3den Enhanced v$ModVersion"
$ToolsFolder = "${env:ProgramFiles(x86)}\Steam\steamapps\common\Arma 3 Tools"
$WorkshopID = 623475643

function Addon-PrepareBuild
{
  #Clear target folder
  Remove-Item -Force -Path "$TargetFolder" -Recurse

  #Copy or create all files
  New-Item -Force -Path "$TargetFolder" -Name "addons" -ItemType "Directory"

  Copy-Item -Force -Path "$ProjectFolder\keys" -Destination "$TargetFolder\keys" -Recurse
  Copy-Item -Force -Path "$ProjectFolder\userconfig" -Destination "$TargetFolder\userconfig" -Recurse
  Copy-Item -Force -Path "$ProjectFolder\python_code" -Destination "$TargetFolder\python_code" -Recurse
  Copy-Item -Force -Path "$ProjectFolder\mod.cpp" -Destination "$TargetFolder"
};

function Addon-Build
{
  #Build, using ´" to turn arguments into strings
  Start-Process -FilePath ("$ToolsFolder\AddonBuilder\AddonBuilder.exe") -argumentList "`"$ProjectFolder\3denEnhanced`" `"$TargetFolder\addons`" `"-sign=$ProjectFolder\3denEnhanced.biprivatekey`" -packonly"
}

function Addon-Publish
{
  Start-Process "$ToolsFolder\Publisher\PublisherCmd.exe" -ArgumentList "update /id:$WorkshopID /path:`"$TargetFolder`" /changeNote:`"Auto Update: Changelog will follow!`""
}

function Addon-Compress
{
  Compress-Archive -Path "$TargetFolder" -DestinationPath ($ProjectFolder + "\versions\@3den Enhanced v" + $ModVersion + ".zip") -Force
}

Addon-PrepareBuild
Write-Host "Copying files."
Start-Sleep 2
Addon-Build
Write-Host "Creating pbo."
Start-Sleep 20
Write-Host "Packing done."


if ($DoPublish -eq "true")
{
  Write-Host "Publishing to Steam"
  Addon-Compress
  Addon-Publish
}

Write-Host "All done!"