
# Force unicode for all cmdlets
$PSDefaultParameterValues['*:Encoding'] = 'utf8'

# Get XML content
[xml] $XML = Get-Content -Path ($env:OneDrive + "\Games\Arma 3\Arma 3 Mods\3den-Enhanced\3denEnhanced\stringtable.xml")

# Create Excel file
$Excel = New-Object -ComObject Excel.Application

# Make Excel visible
$Excel.visible = $True

# Add a workbook (A new file basically)
$Workbook = $Excel.Workbooks.Add()

# Add a worksheet (A new page basically)
$Worksheet= $workbook.Worksheets.Item(1)
$Worksheet.Name = "Translations"

# Define the headers
$Headers = @(
    "Key",
    "English",
    "German",
    "Italian",
    "Czech",
    "Chinesesimp",
    "Spanish",
    "French",
    "Polish",
    "Russian",
    "Portuguese"
)



# Loop through the headers and create them
$Col = 1
$Headers | ForEach-Object -Process {
    $Worksheet.Cells.Item(1,$col) = $_
    $Worksheet.Cells.Item(1,$col).Font.Bold = $True
    $Worksheet.Cells.Item(1,$col).Font.Size = 18
    $Col++
}


$row = 2
$XML.Project.ChildNodes.ID | ForEach-Object -Process {
    $Worksheet.Cells.Item($row,1) = $_
    $row++
};

$row = 2
$Col = 2
$XML.Project.ChildNodes.English | ForEach-Object -Process {
    $Worksheet.Cells.Item($row, $Col) = $_

    $row++
};

$row = 2
$Col = 3
$XML.Project.ChildNodes.German | ForEach-Object -Process {
    $Worksheet.Cells.Item($row, $Col) = $_

    $row++
};

$row = 2
$Col = 4
$XML.Project.ChildNodes.Italian | ForEach-Object -Process {
    $Worksheet.Cells.Item($row, $Col) = $_

    $row++
};

$row = 2
$Col = 5
$XML.Project.ChildNodes.Czech | ForEach-Object -Process {
    $Worksheet.Cells.Item($row, $Col) = $_

    $row++
};

$row = 2
$Col = 6
$XML.Project.ChildNodes.Chinesesimp | ForEach-Object -Process {
    $Worksheet.Cells.Item($row, $Col) = $_

    $row++
};

$row = 2
$Col = 7
$XML.Project.ChildNodes.Spanish | ForEach-Object -Process {
    $Worksheet.Cells.Item($row, $Col) = $_

    $row++
};

$row = 2
$Col = 8
$XML.Project.ChildNodes.French | ForEach-Object -Process {
    $Worksheet.Cells.Item($row, $Col) = $_

    $row++
};

$row = 2
$Col = 9
$XML.Project.ChildNodes.Polish | ForEach-Object -Process {
    $Worksheet.Cells.Item($row, $Col) = $_

    $row++
};

$row = 2
$Col = 10
$XML.Project.ChildNodes.Russian | ForEach-Object -Process {
    $Worksheet.Cells.Item($row, $Col) = $_

    $row++
};

$row = 2
$Col = 11
$XML.Project.ChildNodes.Portuguese | ForEach-Object -Process {
    $Worksheet.Cells.Item($row, $Col) = $_
};

# Auto size all columns
$Worksheet.Columns.autofit()

$Workbook.SaveAs(($env:OneDrive + "\Games\Arma 3\Arma 3 Mods\3den-Enhanced\stringtable"), 51) # http://msdn.microsoft.com/en-us/library/bb241279.aspx
$workbookObject.Close()
$Workbook.Close()

Get-Process -Name "Excel" | Stop-Process