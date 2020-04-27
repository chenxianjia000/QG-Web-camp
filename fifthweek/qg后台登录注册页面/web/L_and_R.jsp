<%--
  Created by IntelliJ IDEA.
  User: asus
  Date: 2020/4/26
  Time: 22:59
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>登录注册</title>
    <link rel="stylesheet" href="L_and_R.css" type="text/css">

</head>
<body>


<div id="loginbox">

    <h1>Login</h1>

    <form action="/qgtest/loginServlet" method="get">

        <div class="form">

            <div class="item">
                <i class="iconfont iconuser">&#xe651;</i>
                <input type="text" placeholder="Usercount" id="loginusername" name="userCount">
            </div>

            <div class="item">
                <i class="iconfont iconmima">&#xe657;</i>
                <input type="Password" placeholder="Password" id="loginpassword" name="userPass">
            </div>

        </div>

        <input type="submit" value="Login" id="btn1">

    </form>

    <a href="#" onclick="TurnToRegister()" class="ToRegister">Go to sign up</a>

</div>


<div id="registerbox">

    <h1>Sigh up</h1>

    <form action="/qgtest/registerServlet" method="post">

        <div class="form">

            <div class="item">

                <input id="username" name="userName" placeholder="请输入名字">

            </div>

            <div class="item">

                <input type="Password"  name="userPass" placeholder="请输入8-15位密码">

            </div>

            <div class="item">

                <input type="Password"  name="userPass2" placeholder="请再次输入密码">

            </div>

        </div>

        <input type="submit" value="Sigh up" id="btn2">

    </form>

    <a href="#" onclick="TurnToLogin()" class="ToLogin">Go to sigh up</a>

</div>


<script src="1.js"></script>

</body>
</html>
