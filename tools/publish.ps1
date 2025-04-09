$SourceFolder = "..\3den-Enhanced\.hemttout\release"
$PublisherExe = "${env:ProgramFiles(x86)}\Steam\steamapps\common\Arma 3 Tools\Publisher\PublisherCmd.exe"
$Changelog = "[url=https://github.com/R3voA3/3den-Enhanced/blob/master/CHANGELOG.md] Changelog (GitHub) [/url]"
$WorkshopID = 623475643
$VersionFilePath = $SourceFolder + "\" + "version.txt"

if (Test-Path $VersionFilePath -PathType Leaf)
{
    $ModVersion = Get-Content ($SourceFolder + "\" + "version.txt")
    $Changelog = $ModVersion + " " + $Changelog

    # Remove version.txt so it is not uploaded
    Remove-Item $VersionFilePath

    Start-Process "$PublisherExe" -ArgumentList "update /id:$WorkshopID /path:`"$SourceFolder`" /changeNote:`"$Changelog`"" -Wait

    # Clean up all remaining files
    Remove-Item $SourceFolder -Verbose -Recurse -Force
}
else
{
    "Version file not found! Publishing canceled!"
}
