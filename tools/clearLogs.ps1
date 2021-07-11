#Delete .rpt files
Get-ChildItem "$env:userprofile\AppData\Local\Arma 3" -Filter "*.rpt" -Recurse | Remove-Item -Verbose

#Delete launcher log and dump files
Get-ChildItem "$env:userprofile\AppData\Local\Arma 3 Launcher" -Filter "*.log" -Recurse | Remove-Item -Verbose
Get-ChildItem "$env:userprofile\AppData\Local\Arma 3 Launcher" -Filter "*.mdmp" -Recurse | Remove-Item -Verbose

#Delete tools log files
Get-ChildItem "${env:ProgramFiles(x86)}\Steam\steamapps\common\Arma 3 Tools\Logs" | Remove-Item -Verbose