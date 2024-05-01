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

    $stmt = $mysqli->prepare("SELECT Firstname, Lastname, Email FROM Users ORDER by Lastname");
    $stmt->execute();
    $result = $stmt->get_result();

    echo "<h2> Before update </h2>";
    echo "<table>";
    echo "<tr>";
    echo "<td><b>Firstname</b></td>";
    echo "<td><b>Lastname</b></td>";
    echo "<td><b>Email</b></td>";
    echo "</tr>";
    while($row = $result->fetch_assoc()){
        echo "<tr>";
        echo "<td>" . $row["Firstname"] . "</td>";
        echo "<td>" . $row["Lastname"] . "</td>";
        echo "<td>" . $row["Email"] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
    
    $stmt = $mysqli->prepare("UPDATE users SET Firstname = ? WHERE email = ?");
    $name = "Calaberia";
    $email = "luigi.luigi@gmail.com";
	$stmt->bind_param("ss", $name, $email);
	$stmt->execute();
	$stmt->close();

    $stmt = $mysqli->prepare("SELECT Firstname, Lastname, Email FROM Users ORDER by Lastname");
    $stmt->execute();
    $result = $stmt->get_result();

    echo "<br>-------------------------<br><br>";
    echo "<h2> After update </h2>";
    echo "<table>";
    echo "<tr>";
    echo "<td><b>Firstname</b></td>";
    echo "<td><b>Lastname</b></td>";
    echo "<td><b>Email</b></td>";
    echo "</tr>";
    while($row = $result->fetch_assoc()){
        echo "<tr>";
        echo "<td>" . $row["Firstname"] . "</td>";
        echo "<td>" . $row["Lastname"] . "</td>";
        echo "<td>" . $row["Email"] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
    $stmt->close();

    $stmt = $mysqli->prepare("SELECT Firstname, Lastname, Email FROM Users ORDER by Lastname");
    $stmt->execute();
    $result = $stmt->get_result();

    echo "<br>-------------------------<br><br>";
    echo "<h2> Before delete </h2>";
    echo "<table>";
    echo "<tr>";
    echo "<td><b>Firstname</b></td>";
    echo "<td><b>Lastname</b></td>";
    echo "<td><b>Email</b></td>";
    echo "</tr>";
    while($row = $result->fetch_assoc()){
        echo "<tr>";
        echo "<td>" . $row["Firstname"] . "</td>";
        echo "<td>" . $row["Lastname"] . "</td>";
        echo "<td>" . $row["Email"] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
    $stmt->close();

    $stmt = $mysqli->prepare("DELETE FROM users WHERE email = ?");
    $email = "luigi.luigi@gmail.com";
    $stmt->bind_param("s", $email);
    $stmt->execute();
    $stmt->close();

    $stmt = $mysqli->prepare("SELECT Firstname, Lastname, Email FROM Users ORDER by Lastname");
    $stmt->execute();
    $result = $stmt->get_result();

    echo "<br>-------------------------<br><br>";
    echo "<h2> After delete </h2>";
    echo "<table>";
    echo "<tr>";
    echo "<td><b>Firstname</b></td>";
    echo "<td><b>Lastname</b></td>";
    echo "<td><b>Email</b></td>";
    echo "</tr>";
    while($row = $result->fetch_assoc()){
        echo "<tr>";
        echo "<td>" . $row["Firstname"] . "</td>";
        echo "<td>" . $row["Lastname"] . "</td>";
        echo "<td>" . $row["Email"] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
    $stmt->close();

    $mysqli->close();
?>