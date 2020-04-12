
let serverUrl = 'http://recruit.qgailab.com/'



let lg_btn = document.getElementById('btn1')
let re_btn = document.getElementById('btn2')


lg_btn.onclick = function () {
    
    if (CheckForm1()==false) {
    	return;
    }

	let data = {
		username: document.getElementById('loginusername').value,
		password: document.getElementById('loginpassword').value
	}

	let xml_http = new XMLHttpRequest()
	xml_http.open("POST",serverUrl+"ajax/login",true);

	xml_http.setRequestHeader("Content-type","application/json");

    xml_http.send(JSON.stringify(data));

    xml_http.onreadystatechange = function() {
        if (xml_http.readyState === 4 && xml_http.status === 200) {
                                                                                                                                           .0
            let result = JSON.parse(xml_http.responseText)

            if (result.code === 1) {

                alert(result.message)
            } else {
                alert(result.message)
            }
        }
    }
}




re_btn.onclick = function () {
    
    if (CheckForm2()==false) {
    	return;
    }

    let data = {
        username: document.getElementById('username').value,
        password: document.getElementById('password').value,
        phone: document.getElementById('phone').value,
        email: document.getElementById('email').value,
        name: document.getElementById('name').value
    }
    let http = new XMLHttpRequest()
    http.open("POST",serverUrl + "ajax/register", true);  

    http.setRequestHeader("Content-type","application/json");

    http.send(JSON.stringify(data));

    http.onreadystatechange = function() {
        if (http.readyState === 4 && http.status === 200) {

            let result = JSON.parse(http.responseText)

            if (result.code === 1) {

                alert(result.message)
            } else {
                alert(result.message)
            }
        }
    }
}