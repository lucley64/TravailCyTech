<% int a = Integer.parseInt(request.getParameter("a"));
    int b = Integer.parseInt(request.getParameter("b"));
    int
            c = Integer.parseInt(request.getParameter("c"));
    int d = b * b - 4 * a * c;
    String rep;
    if (d < 0) {
        rep = "Pas de racines réelles.";
    } else if (d > 0) {
        rep = ((-b + d) / 2 * a) + "ou" + ((-b - d) / 2 * a);
    } else {
        rep = (-b / 2 * a) + "";
    } %>

<p><%=a%>x^2 + <%=b%>x + <%=c%>
</p>
<p>discriminant = <%= d%>
</p>
<p>Reponse = <%= rep%>
</p>