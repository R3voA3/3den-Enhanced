::Use current directory and clear it (including files in sub folders). Don't ask. %CD% (Current Directory)
::del "C:\Users\rober\AppData\Local\Arma 3" /s /q

::Empty Arma 3 Log folder, subfolders as well
del "C:\Users\rober\AppData\Local\Arma 3" /s /q

::Delete Arma 3 Launcher logs and mdmp files, subfolders as well
del "C:\Users\rober\AppData\Local\Arma 3 Launcher\*.log" /s /q
del "C:\Users\rober\AppData\Local\Arma 3 Launcher\*.mdmp" /s /q

::Delete random windows dump folder
del "C:\Users\rober\AppData\Local\CrashDumps\*.dmp" /s /q

::Clear tools log folder
del "C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\Logs\*"  /s /q

pause