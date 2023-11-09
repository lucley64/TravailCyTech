<%@ page import="com.example.jee.mvc.Transportation" %><%--
  Created by IntelliJ IDEA.
  User: cytech
  Date: 04/10/2023
  Time: 10:20
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
    <style>
        label {
            margin: 1%;
        }
        input, select {
            width: 100%;
            padding: .1%;
        }
    </style>
</head>
<body>
    <form method="post" action="">
        <label for="name">Enter name
            <input type="text" name="name" id="name" required></label>

        <label for="surname">Enter surname
            <input type="text" name="surname" id="surname" required></label>

        <label for="birth">Enter birthdate
            <input type="date" name="birth" id="birth" required></label>

        <label for="birthplace">Enter birthplace
            <input type="text" name="birthplace" id="birthplace" required></label>

        <label for="gender">Enter gender
            <input type="text" name="gender" id="gender" required>
        </label>
        <label for="address">Enter address
            <input type="text" name="address" id="address" required>
        </label>
        <label for="postcode">Enter postcode
            <input type="text" name="postcode" id="postcode" required>
        </label>
        <label for="city">Enter city
            <input type="text" name="city" id="city" required>
        </label>
        <label for="transport">Enter transportation
            <select name="transport" id="transport" required>
                <% for (var t :
        Transportation.values()) {
    %> <option><%t.name();%></option><%
}%>
            </select>
        </label>

        <input type="submit" value="Submit">
    </form>



</body>
</html>
