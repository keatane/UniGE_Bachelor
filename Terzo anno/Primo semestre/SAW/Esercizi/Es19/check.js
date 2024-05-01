let img = document.getElementById("anim");
//email.addEventListener("change", () => console.log("cambiato"));
console.log("ciao");
fetch("proxy.php",
    { method: "get",
     headers: { "Content-type": "application/json" },
    }
    ).then(function (response) {
     /* code for Response object*/
     return response.json();
    }).then(function (data) {
     /* code for data */
     console.log(data);
     //img.setAttribute("src", data.img);
     //img.setAttribute("src", data.images[0].url);
     img.setAttribute("src", data.image);
    }).catch(error => console.error('Error:', error));
