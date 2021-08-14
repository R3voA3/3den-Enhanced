$Items = Get-ChildItem -Path "C:\Users\rober\OneDrive\Dokumente\Arma 3 - Other Profiles\R3vo\missions\TESTING\scriptLibrary.VR\Functions\ScriptLibrary" -Name
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

Print-Line "0" "CfgFunctions"
Print-Line "0" "{"
Print-Line "2" "class ENH"
Print-Line "2" "{"
Print-Line "4" "class Category"
Print-Line "4" "{"
$Items | forEach-Object {
    $FunctionName = [STRING] $_.Replace("fn_", "      class ")
    $FunctionName.Replace(".sqf", ";")
}
Print-Line "6" "}"
Print-Line "4" "}"
Print-Line "2" "}"
Print-Line "0" "}"