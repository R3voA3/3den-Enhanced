#Delete .rpt files
Get-ChildItem "$env:userprofile\AppData\Local\Arma 3" -Filter "*.rpt" -Recurse | Remove-Item -Verbose -ErrorAction SilentlyContinue
Get-ChildItem "$env:userprofile\AppData\Local\Arma 3" -Filter "*.mdmp" -Recurse | Remove-Item -Verbose -ErrorAction SilentlyContinue
Get-ChildItem "$env:userprofile\AppData\Local\Arma 3" -Filter "*.bidmp" -Recurse | Remove-Item -Verbose -ErrorAction SilentlyContinue

#Delete launcher log and dump files
Get-ChildItem "$env:userprofile\AppData\Local\Arma 3 Launcher" -Filter "*.log" -Recurse | Remove-Item -Verbose -ErrorAction SilentlyContinue
Get-ChildItem "$env:userprofile\AppData\Local\Arma 3 Launcher" -Filter "*.mdmp" -Recurse | Remove-Item -Verbose -ErrorAction SilentlyContinue

#Delete tools log files
Get-ChildItem "${env:ProgramFiles(x86)}\Steam\steamapps\common\Arma 3 Tools\Logs" | Remove-Item -Verbose -ErrorAction SilentlyContinue