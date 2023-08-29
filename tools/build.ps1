param($DoPublish = "false")


Get-Process -Name arma3_x64 -ErrorAction SilentlyContinue | Stop-Process

Wait-Process processArma3

#Change here---------
$ModVersion = "7.7.9"
#--------------------

$ProjectFolder = "$env:OneDrive\Games\Arma 3\Arma 3 Mods\3den-Enhanced"
$TargetFolder = "${env:ProgramFiles(x86)}\Steam\steamapps\common\Arma 3\Mods\@3den Enhanced v$ModVersion"
$ToolsFolder = "${env:ProgramFiles(x86)}\Steam\steamapps\common\Arma 3 Tools"
$Changelog = "$ModVersion [url=https://github.com/R3voA3/3den-Enhanced/blob/master/changelog.md] Changelog (GitHub) [/url]"
$WorkshopID = 623475643

function Update-Files
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

function Update-Build
{
  #Build, using ´" to turn arguments into strings
  Start-Process -FilePath ("$ToolsFolder\AddonBuilder\AddonBuilder.exe") -argumentList "`"$ProjectFolder\3denEnhanced`" `"$TargetFolder\addons`" `"-sign=$ProjectFolder\3denEnhanced.biprivatekey`" -packonly -prefix=`"3denEnhanced`""
}

function Update-Workshop
{
  Start-Process "$ToolsFolder\Publisher\PublisherCmd.exe" -ArgumentList "update /id:$WorkshopID /path:`"$TargetFolder`" /changeNote:`"$Changelog`""
}

function Update-Archive
{
  Compress-Archive -Path "$TargetFolder" -DestinationPath ($ProjectFolder + "\versions\@3den Enhanced v" + $ModVersion + ".zip") -Force
}

Update-Files
Write-Host "Copying files."

Start-Sleep 2

Update-Build
Write-Host "Creating pbo."

Start-Sleep 5

Write-Host "Packing done."

if ($DoPublish -eq "true")
{
  Write-Host "Creating zip file."

  Update-Compress

  Write-Host "Zip file created."
  Write-Host "Publishing to Steam"

  Update-Workshop

  Write-Host "Publishing finished"
  Write-Host "View 3den Enhanced on Steam: https://steamcommunity.com/sharedfiles/filedetails/?id=623475643"
}

#Start-Process -FilePath "${env:OneDrive}\Desktop\ENH.lnk"