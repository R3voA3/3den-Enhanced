# Store start time
$StartTime = Get-Date

Write-Host "Conversion in progress..."

# Force unicode for all cmdlets
$PSDefaultParameterValues['*:Encoding'] = 'utf8'

$PathXML = $env:OneDrive + "\Games\Arma 3\Arma 3 Mods\3den-Enhanced\3denEnhanced\stringtable.xml"
$PathXLSX = $env:OneDrive + "\Games\Arma 3\Arma 3 Mods\3den-Enhanced\stringtable.xlsx"

# Get XML content
[xml] $XML = Get-Content -Path $PathXML

$Excel = New-Object -ComObject Excel.Application

# Make Excel visible
$Excel.visible = $False

# Add a workbook (A new file basically)
$Workbook = $Excel.Workbooks.Add()

# Define the headers
$Languages = @(
  "English",
  "German",
  "Italian",
  "Czech",
  "Chinesesimp",
  "Spanish",
  "French",
  "Polish",
  "Russian",
  "Portuguese",
  "Turkish",
  "Chinese",
  "Korean",
  "Hungarian"
)

for ($i = $Languages.Length - 1; $i -ge 0; $i--) # Reverse so English is first
{
    $Language = $Languages[$i]

    # Use the default sheet for the Portuguese language
    if ($Language -eq "Portuguese")
    {
        $WorkSheet = $Workbook.worksheets.item(1)
        $WorkSheet.Name = $Language
    }
    else
    {
        $WorkSheet = $Workbook.worksheets.add()
        $WorkSheet.Name = $Language
    }

    #Add header to each sheet
    $Headers = @("Keys", "Original", $Language)

    for ($Column = 1; $Column -ile 3; $Column++)
    {
        $Worksheet.Cells.Item(1, $Column) = $Headers[$Column - 1]
        $Worksheet.Cells.Item(1, $Column).Font.Bold = $True
        $Worksheet.Cells.Item(1, $Column).Font.Size = 18
    }

    # Get keys
    $Col = 1
    $row = 2
    $XML.Project.ChildNodes.ID | ForEach-Object {
        $Worksheet.Cells.Item($row, $Col) = [String]$_ -replace "STR_ENH_" -replace ""
        $_.English
        $row++
    };

    # Get original (English) translation for easier editing
    $Col = 2
    $row = 2
    $XML.Project.ChildNodes.English | ForEach-Object {
        $Worksheet.Cells.Item($row, $Col) = $_
        $row++
    }

    # Get translation for each key
    $Col = 3
    $row = 2
    $XML.Project.ChildNodes.$Language | ForEach-Object {
        $Worksheet.Cells.Item($row, $Col) = $_
        $row++
    }


    # Use void to return nothing
    [Void] $Worksheet.columns.AutoFit()

    Write-Host $Language, "finished loading."
}

# Check if file already exists, if yes, delete it
if (Test-Path $PathXLSX)
{
  Remove-Item -Path $PathXLSX
}

$excel.DisplayAlerts = 'False'
$Workbook.SaveAs($PathXLSX, 51) # http://msdn.microsoft.com/en-us/library/bb241279.aspx
$Workbook.Close()
$excel.Quit()

# Print final message
$EndTime = Get-Date

$Duration = $EndTime - $StartTime


Write-Host "stringtable.xml to stringtable.xlsx convertion completed after", ($Duration.Seconds), "seconds."