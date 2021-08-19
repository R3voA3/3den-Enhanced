Function Get-Folder
{
    [System.Reflection.Assembly]::LoadWithPartialName("System.windows.forms")|Out-Null

    $foldername = New-Object System.Windows.Forms.FolderBrowserDialog
    $foldername.Description = "Select a folder"
    $foldername.rootfolder = "Desktop"
    $foldername.SelectedPath = "MyDocuments"
    $folderName.ShowNewFolderButton = $false

    if($foldername.ShowDialog() -eq "OK")
    {
        $folder += $foldername.SelectedPath
    }
    return $folder
}

Function Print-Line
{
    param([INT] $Indentations = 0, [STRING] $Text = "line")
    $Output = ""
    for ($Whitespaces = 1; $Whitespaces -ile $Indentations; $Whitespaces++)
    {
        $Output = $Output + " "
    }
    $OutPut + $Text
}

$directory = Get-Folder
$Items = Get-ChildItem -Path $directory -Name

Print-Line "0" "class CfgFunctions"
Print-Line "0" "{"
Print-Line "2" "class ENH"
Print-Line "2" "{"
Print-Line "4" "class Category"
Print-Line "4" "{"

$Items | forEach-Object {
    $FunctionName = [STRING] $_.Replace("fn_", "class ")
    Print-Line "6" $FunctionName.Replace(".sqf", ";")
}

Print-Line "4" "};"
Print-Line "2" "};"
Print-Line "0" "};"