<?php	
    $mysqli = new mysqli("localhost","root","","db-fake");
	if ($mysqli->connect_errno) {
		die('mysqli connection error: ' . $mysqli->connect_error);
	}
?>