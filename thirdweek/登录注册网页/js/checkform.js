

// 登录验证

function CheckForm1(){
		
	if (Checkloginusername() == 0) {
		alert("用户名应由汉字、字母、数字或下划线组成，且长度为8-16位");
		return false;
	}

	if (Checkloginpassword() == 0) {
		alert("密码应由数字、字母或下划线组成,且长度为8-16位");
        return false;
	}

	return true;
}



function Checkloginusername(){
	var username = document.getElementById("loginusername").value;
	var reg = /^[a-zA-Z0-9_\u4e00-\u9fa5]+$/;
	if ( !(reg.test(username)) ) {

		return 0;

	} 
}


function Checkloginpassword(){
	var password = document.getElementById("loginpassword").value;
	var reg = /^[\w+]{8,16}$/;
	if ( !(reg.test(password)) ) {

		return 0;

	} 
}



// 注册验证


function CheckForm2(){

	if (Checkusername() == 0) {
		alert("用户名应由汉字、字母、数字或下划线组成，且长度为8-16位");
        return false;
        console.log("44");
	}

	if (Checkpassword() == 0) {
		alert("密码应由数字、字母或下划线组成,且长度为8-16位");
        return false;
	}

	if (Checkphone() == 0) {
		alert("不是一个有效的手机号码");
		return false;
	}

	if (Checkemail() == 0) {
		alert("不是一个有效的邮箱地址");
		return false;
	}

	if (Checkname() == 0) {
		alert("名字格式不正确");
		return false;
	}


return true;
	
}




function Checkusername(){
	var username = document.getElementById("username").value;
	var reg = /^[a-zA-Z0-9_\u4e00-\u9fa5]+$/;
	if ( !(reg.test(username)) ) {

		return 0;

	} 
}


function Checkpassword(){
	var password = document.getElementById("password").value;
	var reg = /^[\w+]{8,16}$/;
	if ( !(reg.test(password)) ) {

		return 0;

	} 
}


function Checkphone(){
	var phone = document.getElementById("phone").value;
	var reg = /^[1][3|4|5|7|8][0-9]{9}$/;
	if ( !(reg.test(phone)) ) {

		return 0;

	} 
}

function Checkemail(){
	var email = document.getElementById("email").value;
	var reg = /^([a-zA-Z0-9_-])+@([a-zA-Z0-9_-])+(.[a-zA-Z0-9_-])+/;
	if ( !(reg.test(email))){

		return 0;

	}
}

function Checkname(){
	var name = document.getElementById("name").value;
	var reg = /^[\u4E00-\u9FA5]{2,4}$/;
	if ( !(reg.test(name))){

		return 0;

	}
}




 // console.log(CheckForm1());