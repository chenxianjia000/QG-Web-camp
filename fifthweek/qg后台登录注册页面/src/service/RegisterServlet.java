package service;


import po.User;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;

/**
 * 注册相关
 */
@WebServlet("/registerServlet")
public class RegisterServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws  IOException {
        resp.setCharacterEncoding("GBK");
        req.setCharacterEncoding("utf-8");
        String userName = req.getParameter("userName");
        String userPass = req.getParameter("userPass");
        String userPass2 = req.getParameter("userPass2");


       if("".equals(userName) || "".equals(userPass) || "".equals(userPass2)) {
            //有空输入
            resp.getWriter().write("请把信息填完整");
        }
        else if (userPass.equals(userPass2)) {
            //两次密码输入一样
            UserService service = new UserService();

            if (!service.isTure(userName,userPass)) {
                //输入太长或太短
                resp.getWriter().write("请按要求输入");
            }
            else {
                User user = null;
                try {
                    user = service.register(userName,userPass);
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
                resp.getWriter().write("注册成功，请记住你的账号："+ user.getUserCount());
            }
        }
        else {
            resp.getWriter().write("两次密码不一致！");
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req,resp);
    }

    private class var {
    }
}
