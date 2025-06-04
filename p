<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Langkah Praktikum</title>
</head>
<body>
    <script src="header.js"></script>

    
    <tr>
        <div class="container">
            <h2> FORM BIODATA </h2>
            <style>
                .container{
                    height: 70px;
                    background-color: rgb(34, 106, 241);
                    border-radius: 10px;
                    display: flex;
                    padding-left: 20px;
                }
                h2{
                  color:white;
                  font-family: Verdana, Geneva, Tahoma, sans-serif;
                }
                .isi{
                    background-color:white;
                    border-radius: 10px;
                    padding-left: 20px;
                    padding-top: 20px;
                    padding-bottom: 20px;
                    font-family:  Verdana, Geneva, Tahoma, sans-serif;
                   
                }
                body{
                    background-color: rgb(220, 220, 220);
                }
            </style>

        </div>
    </tr>

    <br>
    <form name ="fform">
     <div class="isi">
       
        <tr>
                <td width="100%" colspan="1">
                    <h2 align="left" style="color: black;">Informasi pribadi</h2><br>
                </td>
            </tr>
            <tr>
                <td width="100%" style="padding: 100px;">
                    Nama : <br><input type="text" size="100" name="inama"><br><br>
                    nim : <br><input type="text" size="100" name="nim"><br><br>
                   
                   
                    jenis kelamin : <br><input type="radio" name="ijk">laki laki
                    <input type="radio" name="ijk">perempuan<br><br>
                     program studi : <br><select name="prodi">
                        <option value="">--Pilih program studi--</option>
                        <option value="infor">informatika</option>
                        <option value="manage">management</option>
                        <option value="dokter">kedokteran</option>
                    </select><br><br>
                     alamat : <br><input type="text" size="100" name="ijumlah"><br><br>
                </td>
            </tr>
            <tr>
                <td width="100%" colspan="2">
                    <center>
                        <input type="button" value="select" onclick="hitungtotal()" style="background-color: rgb(34, 106, 241); color: white; padding-left: 10px; padding-right: 10px">
                        <input type="reset" value="Ulang" style="background-color: rgb(34, 106, 241); color: white; padding-left: 10px; padding-right: 10px;">
                    </center>
                </td>
            </tr>
    
   </div>
    </form>
</body>
</html>
