Get-ChildItem -recurse | 
Where-Object {$_.Name -eq "Makefile"} |
ForEach-Object {
    Set-Location $_.DirectoryName;
    make.exe;
    Set-Location ..;
}