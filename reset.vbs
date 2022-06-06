Set wshShell = WScript.CreateObject( "WScript.Shell" )

strComputerName = wshShell.ExpandEnvironmentStrings( "%COMPUTERNAME%" )

set WshShell = WScript.CreateObject("WScript.Shell") 

WshShell.Run "cmd" 

WScript.Sleep 100 

WshShell.AppActivate "C:\Windows\system32\cmd.exe" 

WshShell.SendKeys "telnet 192.168.43.71 8080{ENTER}" 

WScript.Sleep 300
set x=createobject("wscript.shell")
x.sendkeys "0 ~"
WScript.Sleep 150
x.sendkeys "2 ~"
WScript.Sleep 150
x.sendkeys "4 ~"
WScript.Sleep 150
x.sendkeys "6 ~"
WScript.Sleep 50
Set oshell =WScript.CreateObject("WScript.shell")
oshell.Run "taskkill /im cmd.exe",, True
