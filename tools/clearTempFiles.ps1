Remove-Item "$env:LOCALAPPDATA\Arma 3\*.*" -Recurse -Verbose -Force -ErrorAction SilentlyContinue
Remove-Item "$env:LOCALAPPDATA\Arma 3\AnimDataCache\*.*" -Recurse -Verbose -Force -ErrorAction SilentlyContinue
Remove-Item "$env:LOCALAPPDATA\Arma 3\DataCache\*.*" -Recurse -Verbose -Force -ErrorAction SilentlyContinue
Remove-Item "$env:LOCALAPPDATA\Arma 3\MonetizedServersCache\*.*" -Recurse -Verbose -Force -ErrorAction SilentlyContinue
Remove-Item "$env:LOCALAPPDATA\Arma 3\OfficialServersCache\*.*" -Recurse -Verbose -Force -ErrorAction SilentlyContinue

Remove-Item "$env:LOCALAPPDATA\Arma 3 Launcher\Logs\" -Recurse -Verbose -Force -ErrorAction SilentlyContinue

Remove-Item "$env:ProgramFiles(x86)\Steam\steamapps\common\Arma 3 Tools\Logs\" -Recurse -Verbose -Force -ErrorAction SilentlyContinue
Remove-Item "$env:ProgramFiles(x86)\Steam\steamapps\common\Logs\*.*" -Recurse -Verbose -Force -ErrorAction SilentlyContinue

Remove-Item "$env:TEMP\*.*" -Recurse -Verbose -Force -ErrorAction SilentlyContinue
Remove-Item "C:\Windows\Temp\*.*" -Recurse -Verbose -Force -ErrorAction SilentlyContinue
