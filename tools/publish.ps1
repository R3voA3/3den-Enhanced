$ModFolder = "..\3den-Enhanced"
$SourceFolder = "$ModFolder\.hemttout\release"
$PublisherExe = "${env:ProgramFiles(x86)}\Steam\steamapps\common\Arma 3 Tools\Publisher\PublisherCmd.exe"
$Changelog = "[url=https://github.com/R3voA3/3den-Enhanced/blob/master/CHANGELOG.md] Changelog (GitHub) [/url]"
$WorkshopID = 623475643

Start-Process "$PublisherExe" -ArgumentList "update /id:$WorkshopID /path:`"$SourceFolder`" /changeNote:`"$Changelog`"" -Wait

Remove-Item $SourceFolder -Verbose -Recurse -Force
