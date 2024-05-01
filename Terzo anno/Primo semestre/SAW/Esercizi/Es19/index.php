<!DOCTYPE html>
<html lang="it">
<head>
	<title> Template </title>
	<meta charset="utf-8">
	<meta name="keywords" content="esercizio5, saw, 2022">
	<meta name="author" content="Kevin">
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
<header> 
	<div class="header-container">
		<div class="vertical-center"> 
			<h1> Template</h1>
		</div>
	</div>
</header>
<nav>
	<div class="nav-container">
		<div class="vertical-center"> 
			<a class="nav-text" href="#"> Home </a> |
			<a class="nav-text" href="#"> Chi siamo</a> |
			<a class="nav-text" href="#"> Lavora con noi</a> |
			<a class="nav-text" href="#"> Contatti</a>
		</div>
	</div>
</nav>
<br>
<br>
<img width="50%" height="50%" id="anim" src="" alt="img"></img>
<br>
<div class="form-container">
		<h2> Crea un account </h2>
		<form method="POST" action="registration.php">
			<label for="firstname">Nome</label><br>
			<input type="text" id="firstname" name="firstname" placeholder="e.g. Mario">
			<br><br><label for="lastname">Cognome</label><br>
			<input type="text" id="lastname" name="lastname" placeholder="e.g. Rossi">
			<br><br><label for="email">Indirizzo email</label><br>
			<input type="email" id="email" name="email" placeholder="e.g. mario.rossi@gmail.com" required>
			<div id="email-check"></div>
			<br><br><label for="password">Password</label><br>
			<input type="password" id="password" name="password" placeholder="Password" pattern="[0-9]{3}" required>
			<br><br><label for="confirm">Conferma password</label><br>
			<input type="password" id="confirm" name="confirm" placeholder="Password" pattern="[0-9]{3}" required>
			<br><br>
			<input type="submit" name="submit" value="Registrati">
		</form>
		<br>
</div>
<br>
<a href="#">
	<h3>Leggi la nostra Informativa sulla Pubblicità definita in base agli interessi</h3>
</a>
<br>
<div class="form-container">
		<h2> Login </h2>
		<form method="POST" action="login.php">
		<br><br><label for="email">Indirizzo email</label><br>
		<input type="email" id="email" name="email">
		<br><br><label for="confirm">Conferma password</label><br>
		<input type="password" id="pass" name="pass">
		<br><br>
		<input type="checkbox" name="rememberMe" value="rememberMe">
		<label for="rememberMe">Ricordami</label>
		<br><br>
		<input type="submit" name="submit" value="Login">
		</form>
</div>
<br>
<footer>
	Copyright: Template Website - 
	<a href="#">Cookie policy</a> - 
	<a href="#">Feedback</a>
</footer>
<script src="check.js"></script>
</body>
</html>