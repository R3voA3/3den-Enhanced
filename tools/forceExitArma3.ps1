#Force exit. If process does not exist, exit silently
Get-Process -Name arma3_x64 -ErrorAction SilentlyContinue | Stop-Process