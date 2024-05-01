<!DOCTYPE html>
<html lang="en">
<head>
    <title>Input Color</title>
</head>
<body>
<div>
    <form method="POST" action="setcookie.php">
        <h3>Text color:</h3>
        <input type="color" name="textcolor" value="textcolor">
        <h3>Background color:</h3>
        <input type="color" name="bgcolor" value="bgcolor">
        <h3>Font family:</h3>
        <input type="radio" name="fontfamily" value="Times">
        <label for="Times">Times</label><br>
        <input type="radio" name="fontfamily" value="Arial">
        <label for="Arial">Arial</label><br>
        <input type="submit" name="submit" value="Submit">
    </form>
</div>
</body>
</html>