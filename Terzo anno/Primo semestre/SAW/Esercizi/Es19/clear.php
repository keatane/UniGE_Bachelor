<?php
    session_start();
    if(isset($_COOKIE["Remember"])){
        setcookie("Remember", $token, time()-3600);
        unset($_COOKIE["Remember"]);
    }
        
    if(isset($_COOKIE["username"])){
        setcookie("username", $user, time()-3600);
        unset($_COOKIE["username"]);
    }
        
    session_unset();
    session_destroy();
    header('Location: index.php');
    exit;
?>
