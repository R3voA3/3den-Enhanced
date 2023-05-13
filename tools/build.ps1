param($DoPublish = "false")


$processArma3 = Get-Process -Name arma3_x64 -ErrorAction SilentlyContinue | Stop-Process

Wait-Process processArma3

$ProjectFolder = "$env:OneDrive\Games\Arma 3\Arma 3 Mods\3den-Enhanced"
$ModVersion = "7.7.4" #Get-Content -Path "$ProjectFolder\tools\`$VERSION`$"
$TargetFolder = "${env:ProgramFiles(x86)}\Steam\steamapps\common\Arma 3\Mods\@3den Enhanced v$ModVersion"
$ToolsFolder = "${env:ProgramFiles(x86)}\Steam\steamapps\common\Arma 3 Tools"
$WorkshopID = 623475643

function Addon-PrepareBuild
{
  #Clear target folder
  Remove-Item -Force -Path "$TargetFolder" -Recurse -Verbose -errorAction SilentlyContinue

  #Copy or create all files
  New-Item -Force -Path "$TargetFolder" -Name "addons" -ItemType "Directory" -Verbose

  Copy-Item -Force -Path "$ProjectFolder\keys" -Destination "$TargetFolder\keys" -Recurse -Verbose
  Copy-Item -Force -Path "$ProjectFolder\userconfig" -Destination "$TargetFolder\userconfig" -Recurse -Verbose
  Copy-Item -Force -Path "$ProjectFolder\python_code" -Destination "$TargetFolder\python_code" -Recurse -Verbose
  Copy-Item -Force -Path "$ProjectFolder\mod.cpp" -Destination "$TargetFolder" -Verbose
};

function Addon-Build
{
  #Build, using ´" to turn arguments into strings
  Start-Process -FilePath ("$ToolsFolder\AddonBuilder\AddonBuilder.exe") -argumentList "`"$ProjectFolder\3denEnhanced`" `"$TargetFolder\addons`" `"-sign=$ProjectFolder\3denEnhanced.biprivatekey`" -packonly"
}

function Addon-Publish
{
  Start-Process "$ToolsFolder\Publisher\PublisherCmd.exe" -ArgumentList "update /id:$WorkshopID /path:`"$TargetFolder`" /changeNote:`"[url=https://github.com/R3voA3/3den-Enhanced/blob/master/changelog.md] Changelog (GitHub) [/url]`""
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
Start-Sleep 5
Write-Host "Packing done."

if ($DoPublish -eq "true")
{
  Write-Host "Creating zip file."
  Addon-Compress
  Write-Host "Zip file created."
  Write-Host "Publishing to Steam"
  Addon-Publish
  Write-Host "Publishing finished"
  Write-Host "View 3den Enhanced on Steam: https://steamcommunity.com/sharedfiles/filedetails/?id=623475643"
}