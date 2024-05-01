<?php
    if(isset($_POST("password")) && isset($_POST("confirm")))
        if($_POST("password") != ($_POST("confirm")))
            print_r("<script> alert('Password diverse')</script>");
?>