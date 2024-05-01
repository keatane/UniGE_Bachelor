<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>List of users</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>
<h1> List of users </h1>
<?php	
    include("connection.php");

    $query = "SELECT Firstname, Lastname, Email FROM Users ORDER by Lastname";
    $res = $mysqli->query($query);

    echo "<table>";
    echo "<tr>";
    echo "<td><b>Firstname</b></td>";
    echo "<td><b>Lastname</b></td>";
    echo "<td><b>Email</b></td>";
    echo "</tr>";
    while($row = $res->fetch_array(MYSQLI_ASSOC)){
        echo "<tr>";
        echo "<td>" . $row["Firstname"] . "</td>";
        echo "<td>" . $row["Lastname"] . "</td>";
        echo "<td>" . $row["Email"] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
    $res->free();
    $mysqli->close();
?>