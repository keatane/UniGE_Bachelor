let email = document.getElementById("email");
let check = document.getElementById("email-check");
//email.addEventListener("change", () => console.log("cambiato"));
email.addEventListener("change", () => 
    fetch("check_email.php",
    { method: "post",
    headers: {
        "Content-type": "application/x-www-form-urlencoded"},
     body: "echeck=" + email.value
    })
    // Converting to JSON
    .then(response => response.text())
     
    // Displaying results to console
    .then(data => check.innerHTML = data)
    .catch((error) => {
        console.error('Error:', error);
      }));
