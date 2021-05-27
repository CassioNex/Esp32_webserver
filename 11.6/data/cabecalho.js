	 <header id="mainheader"></header>
 
 <div id="contaner">
 <p>&nbsp </p>
 <p>&nbsp </p>
 <!-- -->
 
 <!-- -->
 </div>
 
 <header id="mainfooter"></header>
 
 <script type="text/javascript"> 
    carregaDocumento("/", "#mainheader");
    carregaDocumento("rodape.html", "#mainfooter");

    function carregaDocumento(arquivo, target)
    {
        var el = document.querySelector(target);

        //Se o elemento não existir então não requisita
        if (!el) return;

        var xhr = new XMLHttpRequest();
        xhr.open("GET", arquivo, true);
        xhr.onreadystatechange = function(){
             if (xhr.readyState == 4 && xhr.status >= 200 && xhr.status < 300){
                  el.innerHTML = xhr.responseText;
             }
        };

        xhr.send(null);
    }
    </script>