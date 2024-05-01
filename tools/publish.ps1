$ModFolder = "${env:OneDrive}\Games\Arma 3\Arma 3 Mods\3den-Enhanced"
$SourceFolder = "$ModFolder\.hemttout\release"
$PrivateKey = "$ModFolder\3denEnhanced.biprivatekey"
$ToolsFolder = "${env:ProgramFiles(x86)}\Steam\steamapps\common\Arma 3 Tools"
$Changelog = "[url=https://github.com/R3voA3/3den-Enhanced/blob/master/CHANGELOG.md] Changelog (GitHub) [/url]"
$WorkshopID = #623475643
$VersionTxt = "$SourceFolder\version.txt"

# Check if version file exists
if (Test-Path -path $VersionTxt -PathType Leaf)
{
	$Version = Get-Content $VersionTxt

	$Changelog = $Version + " " + $Changelog

	Remove-Item $VersionTxt -Verbose

	# Sign each pbo
	foreach ($File in Get-ChildItem $SourceFolder\addons)
	{
		if ($file.extension -eq ".pbo")
		{
			$FileName = $File.Name
			Start-Process "$ToolsFolder\DSSignFile\DSSignFile.exe" -ArgumentList "`"$PrivateKey`" `"$SourceFolder\addons\$FileName`"" -Wait

			Write-Host $FileName "was signed."
		}
	}

	# Update translation stats
	& "$ModFolder\tools\getStringtableStats.ps1" -Wait


	Start-Process "$ToolsFolder\Publisher\PublisherCmd.exe" -ArgumentList "update /id:$WorkshopID /path:`"$SourceFolder`" /changeNote:`"$Changelog`"" -Wait

	Remove-Item $SourceFolder -Verbose -Recurse -Force

	Write-Host "Publishing finished"

	Write-Host "View 3den Enhanced on Steam: https://steamcommunity.com/sharedfiles/filedetails/?id=$WorkshopID"
}
else
{
	Write-Host "version.txt could not be found! Make sure to run hemtt release first!"
}