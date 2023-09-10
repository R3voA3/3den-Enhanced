$Patterns = @(
    "<Key ID=",
    "<English>",
    "<German>",
    "<Italian>",
    "<Czech>",
    "<Chinesesimp>",
    "<Spanish>",
    "<French>",
    "<Polish>",
    "<Russian>",
    "<Portuguese>",
    "<Chinese>"
)

# "<Korean>"
# "<Hungarian>"
# "<Turkish>"

# Get content of stringtable.xml
$Content = Get-Content ($env:OneDrive + "\Games\Arma 3\Arma 3 Mods\3den-Enhanced\3denEnhanced\stringtable.xml")

# Add the number of translations per language in an array
$Counts = $Patterns | forEach-Object {
  $AllMatches = Select-String -InputObject $Content -Pattern $_ -AllMatches
  $AllMatches.Matches.Count
}

$TotalKeys = $Counts[0]

# Get total number of translations. Sustract number of keys since it's at the first place in the array
$TotalTranslationCount = 0
$Counts | Foreach-Object {$TotalTranslationCount += $_}
$TotalTranslationCount -= $TotalKeys
$TotalTranslationCount

# Calculate overall translation progress
$LanguageCount = $Patterns.Count - 1
$TotalTranslationProgress = $TotalTranslationCount / ($TotalKeys * $LanguageCount)
$TotalTranslationProgress

# Create file
$OutPutFilePath = $env:OneDrive + "\Games\Arma 3\Arma 3 Mods\3den-Enhanced\TRANSLATIONSTATS.md"
New-Item -Path $OutPutFilePath -Force

# Create file content
"# Translation Progress" | Add-Content -Path $OutPutFilePath
"**Last update:** {0:dd.MM.yyyy}" -f (Get-Date) | Add-Content -Path $OutPutFilePath

# Add table with overall data
"" | Add-Content -Path $OutPutFilePath
"| Number of Keys | Number of Translations | Total Progress |" | Add-Content -Path $OutPutFilePath
"|----------|:-----------------:|--------:|" | Add-Content -Path $OutPutFilePath
"{0} | {1} | {2:p} |" -f $TotalKeys, $TotalTranslationCount, $TotalTranslationProgress | Add-Content -Path $OutPutFilePath

"" | Add-Content -Path $OutPutFilePath

# Add table header for translation data
"| Language | Translated Entries | Missing Entries | Progress |" | Add-Content -Path $OutPutFilePath
"|----------|:-----------------:|--------:|--------:|" | Add-Content -Path $OutPutFilePath

# Add translation data
for ($i = 1 ; $i -le $Patterns.Length - 1 ; $i++)
{
  # Remove "<" and ">"
  $Language = $Patterns[$i]
  $Language = $Language.ToString().Trim('<', '>')

  "| | | |" | Add-Content -Path $OutPutFilePath
  "| {0} | {1} | {2} | {3:p}" -f $Language, $Counts[$i], ($TotalKeys - $Counts[$i]), ($Counts[$i] / $TotalKeys) | Add-Content -Path $OutPutFilePath
}

# Open file with content
#Start-Process -FilePath 'C:\windows\system32\notepad.exe'-ArgumentList $OutPutFilePath