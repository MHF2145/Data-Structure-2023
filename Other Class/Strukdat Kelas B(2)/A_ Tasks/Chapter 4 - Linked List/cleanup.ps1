Get-ChildItem -Recurse |
Where-Object {$_.Extension -eq ".exe"} |
Remove-Item