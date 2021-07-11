Get-ChildItem "$env:USERPROFILE\\AppData\\Local\\Arma 3" -Filter *.rpt |
Sort-Object LastAccessTime -descending |
Select-Object -first 1 |
Get-Content -tail 1 -wait -encoding utf8