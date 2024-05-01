<!DOCTYPE html>
<html lang="it">
<head>
    <title>Set cookie</title>
</head>

<body>

<?php

 // LEGGI IN VALORI RICEVUTI IN POST
 if(!isset($_POST["submit"])) exit();
 $textcolor = $_POST["textcolor"];
 $bgcolor = $_POST["bgcolor"];
 $fontfamily = $_POST["fontfamily"];
 // CREA I PARAMETRI PER IL COOKIE
 // CREA IL COOKIE CON LA FUNZIONE setcookie();
 setcookie("textcolor",$textcolor, time() + 60);
 setcookie("bgcolor",$bgcolor, time() + 60);
 setcookie("fontfamily",$fontfamily, time() + 60);
 setcookie("viewer",1, time() + 60);
 // LA FUNZIONE header() RIMANDA ALL'HOME PAGE
 header("Location: index.php");
?>


</body>
</html>