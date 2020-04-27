package service;

import po.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet("/loginServlet")
public class LoginServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        String userCount = req.getParameter("userCount");
        String userPass = req.getParameter("userPass");

        UserService service = new UserService();
        User user = new User();
        try {
            user = service.login(userCount,userPass);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        if (user == null) {
                req.getRequestDispatcher("/failServlet").forward(req,resp);
            }
            else {
                req.setAttribute("user",user);
                req.getRequestDispatcher("/successServlet").forward(req,resp);
            }
        }


    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req,resp);
    }
}
