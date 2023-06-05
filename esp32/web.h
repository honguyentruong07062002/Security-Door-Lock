 const char webpage[] PROGMEM = R"=====(
<!DOCTYPE html> 
  <html>
   <head> 
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
       <title>NHÓM BKER</title> 
       <style> 
     
     
   .box2 {
  background-color: blue;
  color: white;
}
          body {
      text-align:center;
      background-color:#E3EDF7
      ;
      color:Blue;
      font-family: Arial, Helvetica, sans-serif;
      }
          
      
      table
      {
      -moz-border-radius:10px;
      -webkit-border-radius:10px;
      border-radius:10px
  
      }
          #content {
            border:red solid 10px; 
            padding:5px;  
            height:auto; 
            width:auto; 
            border-radius:20px;
            margin: 0 auto;
      color: blue;
      background: #FF9999;

          }         
      .cssnhietdo{
  
              outline: none;
              margin: 15px 5px;
              width: 80px;
              height: 80px;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
              color:black;
              font-size:30px;
              font-weight: bold;
        border: solid 5px #ffff66;
              background: #66ffff;
          }   
      
      .cssdoam{
              outline: none;
              margin: 15px 5px;
              width: 80px;
              height: 80px;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
              color:black;
              font-size:30px;
              font-weight: bold;
        border: solid 5px #ffff66;
              background: #66ffff;
          }
      
    
      
      .cssden{
              outline: none;
              margin: 15px 5px;
              width: 80px;
              height: 80px;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
              color:white;
              font-size:20px;
              font-weight: bold;
         border: solid 2px #23C48E;
              background: #23C48E;
        border: solid 5px #33ff33;
              background: #ff0000;
        
          }
      
      .cssquat{
              outline: none;
              margin: 15px 5px;
              width: 80px;
              height: 80px;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
              color:white;
              font-size:20px;
              font-weight: bold;
         border: solid 2px #23C48E;
              background: #23C48E;
        border: solid 5px #33ff33;
              background: #ff0000;
          }     
          .button_quaylai{
  position: absolute;
  top: 10px;
  left: 10px;
} 
      .button {
        display: inline-block;
        padding: 10px 25px;
        font-size: 40px;
        cursor: pointer;
        text-align: center;
        text-decoration: none;
        outline: none;
        color: back;
        background-color: #ffff00;
        border: none;
        border-radius: 20px;
        box-shadow: 0 9px #999;
        height:70px; 
        width:150px;
        border: solid 5px red;
      }

      .button:hover {background-color: #33ff33}

      .button:active {
        background-color: #ff0000;
        box-shadow: 0 5px #666;
        transform: translateY(4px);
      }
      
      tr
      {
        background-color:#E0EAF6;
        color:white;
        -moz-border-radius:10px;
        -webkit-border-radius:10px;
        border-radius:10px
      }
      th    
      {
       
        -moz-border-radius:10px;
        -webkit-border-radius:10px;
        border-radius:10px
        border: solid 5px Blue;
      }
      td    
      {
       
        -moz-border-radius:10px;
        -webkit-border-radius:10px;
        border-radius:10px
        border: solid 5px Blue;
      }
      .field-icon {
        float: right;
        margin-left: -25px;
        margin-top: -25px;
        position: relative;
        z-index: 2;
      }

      .container{
        padding-top:50px;
        margin: auto;
      }   
     @use postcss-preset-env {
  stage: 0;
}

/* config.css */

:root {
  --baseColor: ##00FFFF;
}

/* helpers/align.css */

.align {
  display: grid;
  place-items: center;
}

.grid {
  inline-size: 90%;
  margin-inline: auto;
  max-inline-size: 25rem;
}

/* helpers/hidden.css */

.hidden {
  border: 0;
  clip: rect(0 0 0 0);
  height: 1px;
  margin: -1px;
  overflow: hidden;
  padding: 0;
  position: absolute;
  width: 1px;
}

/* helpers/icon.css */

:root {
  --iconFill: var(--baseColor);
}

.icons {
  display: none;
}

.icon {
  block-size: 1em;
  display: inline-block;
  fill: var(--iconFill);
  inline-size: 1em;
  vertical-align: middle;
}
.icon_mocua {
  block-size: 2em;
  display: inline-block;
  fill: var(--iconFill);
  inline-size: 1em;
  vertical-align: middle;
}
/* layout/base.css */

:root {
  --htmlFontSize: 100%;

  --bodyBackgroundColor: #F0F2F5;
  --bodyColor: var(--baseColor);
  --bodyFontFamily: "Open Sans";
  --bodyFontFamilyFallback: sans-serif;
  --bodyFontSize: 0.875rem;
  --bodyFontWeight: 400;
  --bodyLineHeight: 1.5;
}

* {
  box-sizing: inherit;
}

html {
  box-sizing: border-box;
  font-size: var(--htmlFontSize);
}

body {
  background-color: var(--bodyBackgroundColor);
  color: var(--bodyColor);
  font-family: var(--bodyFontFamily), var(--bodyFontFamilyFallback);
  font-size: var(--bodyFontSize);
  font-weight: var(--bodyFontWeight);
  line-height: var(--bodyLineHeight);
  margin: 0;
  min-block-size: 100vh;
}

/* modules/anchor.css */

:root {
  --anchorColor: #eee;
}

a {
  color: var(--anchorColor);
  outline: 0;
  text-decoration: none;
}

a:focus,
a:hover {
  text-decoration: underline;
}

/* modules/form.css */

:root {
  --formGap: 0.875rem;
}

input {
  background-image: none;
  border: 0;
  color: inherit;
  font: inherit;
  margin: 0;
  outline: 0;
  padding: 0;
  transition: background-color 0.3s;
}

input[type="submit"] {
  cursor: pointer;
}

.form {
 
  display: grid;
  gap: var(--formGap);
}

.form input[type="password"],
.form input[type="text"],
.form input[type="submit"] {
 
  inline-size: 100%;
}

.form__field {
border: 1px ;
 
  display: flex;
  
}

.form__input {
  flex: 1;
}

/* modules/login.css */

:root {

  
  --loginBorderRadus: 0.25rem  ;
  --loginColor: #black;

  --loginInputBackgroundColor: #FFFFFF;
  --loginInputHoverBackgroundColor: #FFFFFF;

  --loginLabelBackgroundColor: #E0EAF6;

  --loginSubmitBackgroundColor:#E0EAF6;
  --loginSubmitColor: #black;
  
}

.login {
  color: var(--loginColor);
}

.login label,
.login input[type="text"],
.login input[type="password"],
.login input[type="submit"] {
  border-radius: var(--loginBorderRadus);
  padding: 1rem;
}

.login label {
  background-color: var(--loginLabelBackgroundColor);
  border-bottom-right-radius: 0;
  border-top-right-radius: 0;
  padding-inline: 1.25rem;
}

.login input[type="password"],
.login input[type="text"] {
  background-color: var(--loginInputBackgroundColor);
  border-bottom-left-radius: 0;
  border-top-left-radius: 0;
}

.login input[type="password"]:focus,
.login input[type="password"]:hover,
.login input[type="text"]:focus,
.login input[type="text"]:hover {
  background-color: var(--loginInputHoverBackgroundColor);
}

.login input[type="submit"] {
  background-color: var(--loginSubmitBackgroundColor);
  color: var(--loginSubmitColor);
  font-weight: 700;
  text-transform: uppercase;
}

.login input[type="submit"]:fsocus,
.login input[type="submit"]:hover {
  background-color: var(--loginSubmitHoverBackgroundColor);
}

/* modules/text.css */

p {
  margin-block: 1.5rem;
}

.text--center {
  text-align: center;
}
    

  myButtonContainer {
  position: absolute;
  left: 10;
 top: 100;
  padding: 10px;
}   
      
  .table-wrapper {
  
  display: flex;
  flex-direction: column;
  justify-content: flex-start;
  align-items: flex-start;
  margin-right: 10px;
  margin-top: 50px;
  
}
}

table {
 
  border-collapse: collapse;
  border-radius: 300px;
  border: 8px solid white;
  margin-bottom: 50px;
  
}

td {
  padding: 35px;
}   

         
  
 
.icon-btn{
position: absolute
  display: inline-flex;
  align-items: center;
  justify-content: center;
  width: 40px;
  height: 40px;
  border-radius: 10px 10px 10px 10px;
  border: 0.25px solid black;
  background-color: #E0EAF6;
  cursor: pointer;
  transition: all 0.3s ease;
}

.icon-btn-back {
position: absolute;
  top:10px;
  left: 1px;
  display: inline-flex;
  align-items: center;
  justify-content: center;
  width: 40px;
  height: 40px;
  border-radius: 10px 10px 10px 10px;
  border: 1px solid #E0EAF6;
  background-color:#E0EAF6;
  cursor: pointer;
  transition: all 0.3s ease;
}

.btn-text {
position: absolute;
  margin-left: 20px;
   
  padding-left: 20px;
}
.btn-textduoi {
position: absolute;
  margin-left: 20px;
    margin-top: 20px;
  padding-left: 20px;
   color: #696969;
}
.btn-textduoi1 {
position: absolute;
  margin-left: 350px;
    margin-top: 10px;
  padding-left: 20px;
   color: #696969;
}
.icon-btn:hover {
  background-color: white;
  color: white;
}
.icon-btn-back:hover {
  background-color: white;
  color: white;
}
 
      
       </style>
      
   </head>
   
    <script>
    function LoadForm()
    {
          document.getElementById("dangnhap").style.display = "block";
          document.getElementById("dieukhien").style.display = "none";

        }
  
    
        function UpdateData(){
      var xhttp = new XMLHttpRequest();
      
      // kiểm tra XMLHttpRequest() có dữ liệu không
      xhttp.onreadystatechange = function (){
        // nếu có this.readyState == 4 && this.status == 200
         if(this.readyState == 4 && this.status == 200)
         {
         
          // dữ liệu ESP gửi về biến xhttp.responseText
           var DataVDK  = xhttp.responseText;        
           // hiển thị dữ liệu ra F12        
           console.log("Dữ liệu VDK:" + DataVDK);
           
           var DataJson = JSON.parse(DataVDK); 
           
           if(DataJson.ND != null)
          {
          // hiển thi nhiệt độ ESP ra web
          document.getElementById("nhietdo").value = DataJson.ND;   
          }
          
          if(DataJson.DA != null)
          {
          // hiển thi Độ Ẩm ESP ra web
          document.getElementById("doam").value = DataJson.DA;  
          }
          
          
          if(DataJson.TTD != null)
          {
          if(DataJson.TTD == 1)
          {
            document.getElementById("den").value = "ON";
            document.getElementById("den").style.background = "#00ff00";  
          }
          else if(DataJson.TTD == 0)
          {
            document.getElementById("den").value = "OFF";
            document.getElementById("den").style.background = "#ff0000";   
          }
          }
          
          
          if(DataJson.TTQ != null)
          {
          if(DataJson.TTQ == 1)
          {
            document.getElementById("quat").value = "ON";
            document.getElementById("quat").style.background = "#00ff00";     
          }
          else if(DataJson.TTQ == 0)
          {
            document.getElementById("quat").value = "OFF";
            document.getElementById("quat").style.background = "#ff0000";  
          }
          }
                
        }
      }
      
      xhttp.open('GET','/Update',true);
      xhttp.send(); 
      setTimeout(function(){ UpdateData() }, 1000);   
    }
        function backHOME(){
          //window.onload();
      if (window.confirm('Bạn muốn đăng xuất?'))
      {
        document.getElementById("dangnhap").style.display = "block";
        document.getElementById("dieukhien").style.display = "none";
      }
      else
      {
        document.getElementById("dangnhap").style.display = "none";
        document.getElementById("dieukhien").style.display = "block"; 
      }
        }
       
     // check login form
     function login()
     {
      var ssid = document.getElementById("ssid").value;
      var pass = document.getElementById("pass").value;
      
      if(ssid == "1" && pass == "1")
      {
        console.log("OK");
        document.getElementById("ssid").value = ""; 
        document.getElementById("pass").value = "";
        document.getElementById("dangnhap").style.display = "none";
        

        document.getElementById("dieukhien").style.display = "block"; 
            
      }
      else 
      {
        console.log("Error!!!");
        document.getElementById("ssid").value = ""; 
        document.getElementById("pass").value = "";
        alert("Tên đăng nhập hoặc mật khẩu không đúng vui lòng kiểm tra lại!!!");
      }
     }
     
   
  
    
    
  function Start()
  {
    LoadForm();
    myFunction();
    UpdateData();
  }
  
  
  function GetButtonData(data)
  {
    switch (data)
    {
      
      case 1:
           
        console.log("OnClick Button TB 1"); 
        
        var trangthaitb1 = document.getElementById("den").value;
        console.log(trangthaitb1);  
        
        if(trangthaitb1 == "ON")      
        {
            
          
          var xhttp = new XMLHttpRequest(); 
          xhttp.open("GET","/nhantatden",true);        
          xhttp.send();
        }
        else if(trangthaitb1 == "OFF")
        {
          var tx = "A1B";
          
          var xhttp = new XMLHttpRequest(); 
          xhttp.open("GET","/nhanbatden=",true);        
          xhttp.send();
        }
        
    
        
                break;
      case 2:
        console.log("OnClick Button TB 1"); 
        
        var trangthaitb2 = document.getElementById("quat").value;
        console.log(trangthaitb2);
        
    
        if(trangthaitb2 == "ON")      
        {
           
          var xhttp = new XMLHttpRequest(); 
          xhttp.open("GET","/nhantatquat",true);        
          xhttp.send();
        }
        else if(trangthaitb2 == "OFF")
        {
          var tx = "C1D";
          var xhttp = new XMLHttpRequest(); 
          xhttp.open("GET","/nhanbatquat",true);        
          xhttp.send();
        }
        
        
            
                break;
        
        case 3:
        console.log("OnClick Mo cua");  
           
          var xhttp = new XMLHttpRequest(); 
          xhttp.open("GET","/mocua",true);        
          xhttp.send();     
                break;
        case 4:
        console.log("OnClick 1 LOP"); 
           
          var xhttp = new XMLHttpRequest(); 
          xhttp.open("GET","/1lop",true);        
          xhttp.send();     
                break;
        case 5:
        console.log("OnClick 2 lop"); 
           
          var xhttp = new XMLHttpRequest(); 
          xhttp.open("GET","/2lop",true);        
          xhttp.send();     
                break;
        case 6:
        console.log("OnClick doi mat khau");  
           
          var xhttp = new XMLHttpRequest(); 
          xhttp.open("GET","/doimatkhau",true);        
          xhttp.send();     
                break;
        case 7:
        console.log("themthe"); 
           
          var xhttp = new XMLHttpRequest(); 
          xhttp.open("GET","/themthe",true);        
          xhttp.send();     
                break;
        case 8:
        console.log("xoathe");  
           
          var xhttp = new XMLHttpRequest(); 
          xhttp.open("GET","/xoathe",true);        
          xhttp.send();     
                break;
                case 99:
        var tx = document.getElementById("textcai1").value;
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "/Text1?name1="+tx, true);
        xhttp.send();
                  break;
        }
      }
    
     function myFunction() {
      var x = document.getElementById("pass");
      if (x.type === "password") {
      x.type = "text";
      } else {
      x.type = "password";
      }
    }
    
    
     </script>
   
   
   
   <body onload="Start()" class="align">




  <div id="dangnhap" class="grid" >
   
    <form class="form login"   >

      <div class="form__field">
        <label for="ssid"><svg class="icon">
            <use xlink:href="#icon-user"></use>
          </svg><span class="hidden">Username</span></label>
        <input autocomplete="ssid" id="ssid"  type="text" name="ssid" class="form__input" placeholder="Username" required>
      </div>

      <div class="form__field">
        <label for="pass"><svg class="icon">
            <use xlink:href="#icon-lock"></use>
          </svg><span class="hidden">Password</span></label>
        <input id="pass" type="password" name="password" class="form__input" placeholder="Password" required>
      </div>

      <div class="form__field">
        <input type="submit"  onclick="login()"   value="Sign In"border="2" >
      </div>
      <svg xmlns="http://www.w3.org/2000/svg" class="icons">
    <symbol id="icon-arrow-right" viewBox="0 0 1792 1792">
      <path d="M1600 960q0 54-37 91l-651 651q-39 37-91 37-51 0-90-37l-75-75q-38-38-38-91t38-91l293-293H245q-52 0-84.5-37.5T128 1024V896q0-53 32.5-90.5T245 768h704L656 474q-38-36-38-90t38-90l75-75q38-38 90-38 53 0 91 38l651 651q37 35 37 90z" />
    </symbol>
    <symbol id="icon-lock" viewBox="0 0 1792 1792">
      <path d="M640 768h512V576q0-106-75-181t-181-75-181 75-75 181v192zm832 96v576q0 40-28 68t-68 28H416q-40 0-68-28t-28-68V864q0-40 28-68t68-28h32V576q0-184 132-316t316-132 316 132 132 316v192h32q40 0 68 28t28 68z" />
    </symbol>
    <symbol id="icon-user" viewBox="0 0 1792 1792">
      <path d="M1600 1405q0 120-73 189.5t-194 69.5H459q-121 0-194-69.5T192 1405q0-53 3.5-103.5t14-109T236 1084t43-97.5 62-81 85.5-53.5T538 832q9 0 42 21.5t74.5 48 108 48T896 971t133.5-21.5 108-48 74.5-48 42-21.5q61 0 111.5 20t85.5 53.5 62 81 43 97.5 26.5 108.5 14 109 3.5 103.5zm-320-893q0 159-112.5 271.5T896 896 624.5 783.5 512 512t112.5-271.5T896 128t271.5 112.5T1280 512z" />
    </symbol>
  <symbol id="ngoinha" viewBox="0 0 512 512">
    <path d="M256,319.841c-35.346,0-64,28.654-64,64v128h128v-128C320,348.495,291.346,319.841,256,319.841z"/>
    <g>
      <path d="M362.667,383.841v128H448c35.346,0,64-28.654,64-64V253.26c0.005-11.083-4.302-21.733-12.011-29.696l-181.29-195.99    c-31.988-34.61-85.976-36.735-120.586-4.747c-1.644,1.52-3.228,3.103-4.747,4.747L12.395,223.5    C4.453,231.496-0.003,242.31,0,253.58v194.261c0,35.346,28.654,64,64,64h85.333v-128c0.399-58.172,47.366-105.676,104.073-107.044    C312.01,275.383,362.22,323.696,362.667,383.841z"/>
      <path d="M256,319.841c-35.346,0-64,28.654-64,64v128h128v-128C320,348.495,291.346,319.841,256,319.841z"/>
    </g>
  </symbol>
   <symbol id="mocua" viewBox="0 0 24 24">
    <path d="M20,22V5c0-1.654-1.346-3-3-3h-1.19c-.18-.507-.48-.968-.908-1.319C14.205,.109,13.298-.115,12.412.059L6.411,1.259c-1.397,.28-2.411,1.518-2.411,2.941V22H0v2H24v-2h-4Zm-7.5-8.75c-.828,0-1.5-.672-1.5-1.5s.672-1.5,1.5-1.5,1.5,.672,1.5,1.5-.672,1.5-1.5,1.5Zm5.5,8.75h-2V4h1c.551,0,1,.448,1,1V22Z"/>
  </symbol>
  <symbol id="them" viewBox="0 0 512 512">
      <path d="M480,224H288V32c0-17.673-14.327-32-32-32s-32,14.327-32,32v192H32c-17.673,0-32,14.327-32,32s14.327,32,32,32h192v192   c0,17.673,14.327,32,32,32s32-14.327,32-32V288h192c17.673,0,32-14.327,32-32S497.673,224,480,224z"/>
  </symbol>
  <symbol id="xoa" viewBox="0 0 24 24">
    <path d="M21,4H17.9A5.009,5.009,0,0,0,13,0H11A5.009,5.009,0,0,0,6.1,4H3A1,1,0,0,0,3,6H4V19a5.006,5.006,0,0,0,5,5h6a5.006,5.006,0,0,0,5-5V6h1a1,1,0,0,0,0-2ZM11,2h2a3.006,3.006,0,0,1,2.829,2H8.171A3.006,3.006,0,0,1,11,2Zm7,17a3,3,0,0,1-3,3H9a3,3,0,0,1-3-3V6H18Z"/>
    <path d="M10,18a1,1,0,0,0,1-1V11a1,1,0,0,0-2,0v6A1,1,0,0,0,10,18Z"/>
    <path d="M14,18a1,1,0,0,0,1-1V11a1,1,0,0,0-2,0v6A1,1,0,0,0,14,18Z"/>
  </symbol>
  <symbol id="chuyendoi" viewBox="0 0 24 24">
   <path d="M12,2a10.032,10.032,0,0,1,7.122,3H16a1,1,0,0,0-1,1h0a1,1,0,0,0,1,1h4.143A1.858,1.858,0,0,0,22,5.143V1a1,1,0,0,0-1-1h0a1,1,0,0,0-1,1V3.078A11.981,11.981,0,0,0,.05,10.9a1.007,1.007,0,0,0,1,1.1h0a.982.982,0,0,0,.989-.878A10.014,10.014,0,0,1,12,2Z"/>
    <path d="M22.951,12a.982.982,0,0,0-.989.878A9.986,9.986,0,0,1,4.878,19H8a1,1,0,0,0,1-1H9a1,1,0,0,0-1-1H3.857A1.856,1.856,0,0,0,2,18.857V23a1,1,0,0,0,1,1H3a1,1,0,0,0,1-1V20.922A11.981,11.981,0,0,0,23.95,13.1a1.007,1.007,0,0,0-1-1.1Z"/>
  </symbol>
  <symbol id="2key" viewBox="0 0 24 24">
 <path d="M19,0c-2.41,0-4.43,1.72-4.9,4H2v6h3v-3h2v3h3v-3h4.1c.46,2.28,2.48,4,4.9,4,2.76,0,5-2.24,5-5v-1c0-2.76-2.24-5-5-5Zm2,6c0,1.1-.9,2-2,2s-2-.9-2-2v-1c0-1.1,.9-2,2-2s2,.9,2,2v1Zm-2,11h-2v-3h-3v3h-4.1c-.46-2.28-2.48-4-4.9-4-2.76,0-5,2.24-5,5v1c0,2.76,2.24,5,5,5,2.41,0,4.43-1.72,4.9-4h12.1v-6h-3v3Zm-12,2c0,1.1-.9,2-2,2s-2-.9-2-2v-1c0-1.1,.9-2,2-2s2,.9,2,2v1Z"/>
  </symbol>
  </symbol>
  <symbol id="1key" viewBox="0 0 24 24">
 <path d="m21.5 0h-3.306a3.477 3.477 0 0 0 -2.474 1.025l-7.008 7.008a7.9 7.9 0 0 0 -2.878.267 8 8 0 1 0 9.866 9.866 7.9 7.9 0 0 0 .264-2.931l1.036-1.163v-2.072h3v-3h1.96l1.015-.72a3.477 3.477 0 0 0 1.025-2.474v-3.306a2.5 2.5 0 0 0 -2.5-2.5zm-.5 5.806a.5.5 0 0 1 -.04.194h-3.96v3h-3v3.928l-1.321 1.359a4.945 4.945 0 0 1 .321 1.713 5 5 0 1 1 -5-5 4.947 4.947 0 0 1 1.678.31l8.163-8.164a.5.5 0 0 1 .353-.146h2.806zm-16 11.694a1.5 1.5 0 1 0 1.5-1.5 1.5 1.5 0 0 0 -1.5 1.5z"/>
  </symbol>
   <symbol id="back" viewBox="0 0 24 24">
 <path d="M17.17,24a1,1,0,0,1-.71-.29L8.29,15.54a5,5,0,0,1,0-7.08L16.46.29a1,1,0,1,1,1.42,1.42L9.71,9.88a3,3,0,0,0,0,4.24l8.17,8.17a1,1,0,0,1,0,1.42A1,1,0,0,1,17.17,24Z"/>
  </symbol>
  </svg>
 
  
    </form>

    

  </div>

  
   
   
        
     <div id="dieukhien" >  

        <button class="icon-btn-back" onclick="backHOME()" >
  <svg class="icon_mocua">
            <use xlink:href="#back"></use>a
          </svg>
</button>
     <p style="text-align: left; margin-top: 50px;font-size: 20px; font-weight: bold;">Smart Lock</p>     
   
          
      
        
      <div class="table-wrapper" >
   
  
  
  <table style= "width:1500px" >
    <tr>
      <td style="text-align: left; color: black;">
        <button class="icon-btn" onclick="GetButtonData(3)">
  <svg class="icon">
            <use xlink:href="#mocua"></use>
          </svg>
</button>
<span class="btn-text">Mở cửa</span>
<span class="btn-textduoi">Nhấn nút mở cửa để mở cửa trực tiếp từ xa </span>
      </td>
    </tr>
  </table>
  
  <table style= "width:1500px" >
    <tr>
      <td style="text-align: left; color: black;">
        <button class="icon-btn" onclick="GetButtonData(4)">
  <svg class="icon">
            <use xlink:href="#1key"></use>
          </svg>
</button>
<span class="btn-text">Khóa cửa một lớp</span>
<span class="btn-textduoi">Nhấn nút để chọn chế độ một lớp bảo mật </span>
      </td>
    </tr>
  </table>
   <table style="width: 1500px" >
    <tr>
      <td style="text-align: left; color: black;">
        <button class="icon-btn" onclick="GetButtonData(5)">
  <svg class="icon">
            <use xlink:href="#2key"></use>
          </svg>
</button>
<span class="btn-text">Chức năng khóa cửa hai lớp</span>
<span class="btn-textduoi">Nhấn nút để chọn chế độ hai lớp bảo mật </span>
      </td>
    </tr>
  </table>
   <table style="width: 1500px" >
    <tr>
      <td style="text-align: left; color: black;">
        <button class="icon-btn" onclick="GetButtonData(6)">
  <svg class="icon">
            <use xlink:href="#chuyendoi"></use>
          </svg>
</button>
<span class="btn-text">Đổi mật khẩu</span>
<span class="btn-textduoi">Nhấn nút để bắt đầu đổi mật khẩu </span>
      </td>
    </tr>
  </table>
   <table style="width: 1500px" >
    <tr>
      <td style="text-align: left; color: black;">
        <button class="icon-btn" onclick="GetButtonData(7)">
  <svg class="icon">
            <use xlink:href="#them"></use>
          </svg>
</button>
<span class="btn-text">Chức năng thêm thẻ</span>
<span class="btn-textduoi">Nhấn nút để bắt đầu thêm thẻ người dùng </span>

      </td>
    </tr>
  </table>
   <table style="width: 1500px" >
    <tr>
      <td style="text-align: left; color: black;">
        <button class="icon-btn" onclick="GetButtonData(8)">
  <svg class="icon">
            <use xlink:href="#xoa"></use>
          </svg>
</button>
<span class="btn-text">Chức năng xóa thẻ</span>
<span class="btn-textduoi">Nhấn nút để bắt đầu xóa thẻ người dùng </span>
      </td>
    </tr>
  </table>
  
   <table style="width: 1500px" >
      <tr>
        <td style="text-align: left; color: black;">
        
          <button class="icon-btn" onclick="GetButtonData(99)">
    <svg class="icon">
              <use xlink:href="#xoa"></use>
            </svg>
  </button>
  <span class="btn-text">Chức năng xóa thẻ chỉ định</span>
  <span class="btn-textduoi">Nhập vào số thứ tự thẻ cần xóa và nhấn nút </span>
  <input class="btn-textduoi1" id="textcai1"></input>
        </td>
      </tr>
    </table>
    
</div>  
  
   </body> 
   
  </html>
  )=====";