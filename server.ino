
String head=R"===(
        <!DOCTYPE html>
        <html lang="en">
        <head>
        <title>Anuj | Project</title>

        <meta charset='utf-8'>
        <meta name='viewport' content='width=device-width, initial-scale=1'>
        
        <style>
            body {
                margin-top: 100px;
                font: 400 15px Lato, sans-serif; 
                font-family: Montserrat, sans-serif; 
                line-height: 1.8; 
                color: black; 
                background-color: #323232; 
            }
            .form-control {
                width: 100%;
                color:black;
            }
            .container {
                margin: 0 auto;
                max-width: 400px;
                padding: 30px;
                box-shadow: 0 10px 20px rgba(0,0,0,0.19), 0 6px 6px rgba(0,0,0,0.23);
                background-color: #ffffff;
            }
            h1 {
                text-align: center;
                margin-bottom: 40px;
                margin-top: 0px;
                color: #939393;
                font-size: 35px;
            }
            form .field-group {
                box-sizing: border-box;
                clear: both;
                padding: 4px 0;
                position: relative;
                margin: 1px 0;
                width: 100%;
            }
            input[type=text] {
                font-size: 15px;
                margin-bottom: 4%;
                -webkit-appearance: none;
                display: block;
                background: #fafafa;
                color: #636363;
                width: 100%;
                border: none;
                border-radius: 0;
                border-top: none;
                border-left: none;
                border-right: none;
                border-bottom: 1px solid #00bcd4;
                background-color: transparent;
            }
            input[type=text]:focus {
                border-color: #4C669F;
                outline: 0;
            }
            .button-container {
                box-sizing: border-box;
                clear: both;
                margin: 1px 0 0;
                padding: 4px 0;
                position: relative;
                width: 100%;
            }
            input[type=button] {
                background: #00bcd4;
                border: none;
                border-radius: 30px;
                color: #ffffff;
                cursor: pointer;
                display: block;
                font-weight: bold;
                font-size: 16px;
                padding: 15px 0;
                margin-top: 12%;
                text-align: center;
                text-transform: uppercase;
                width: 100%;
                -webkit-transition: background 250ms ease;
                -moz-transition: background 250ms ease;
                -o-transition: background 250ms ease;
                transition: background 250ms ease;
            }

        </style>
        </head>)===";

String body=R"===(
    <body>
        <div class='container'>
            <h1 align='text-align:center'>IoT</h1>
                <div class="field-group">
                     <div class="button-container">
                         <button type="button" onclick="window.location.href='/on'">LIGHT ON</button>
                    </div>
                    
                     <div class="button-container">
                         <button type="button" onclick="window.location.href='/off'">LIGH OFF</button>
                    </div>
                </div>
        </div>
    </body>
</html>
                    )===";




void handleRoot() {
//  digitalWrite(led, 1);
  server.send(200, "text/html", head+body);
//  digitalWrite(led, 0);
}
void onLed(){
    digitalWrite(LED,1);
    server.send(200,"text/html",head+body);
}

void offLed(){
    digitalWrite(LED,0);
    server.send(200,"text/html",head+body);
}
void handleNotFound(){
//  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
//  digitalWrite(led, 0);
}
