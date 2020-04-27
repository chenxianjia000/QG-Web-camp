package service;

import dao.UserDao;
import po.User;

import java.sql.SQLException;
import java.util.Calendar;
import static java.util.Calendar.*;

/**
 * 服务功能
 */
public class UserService {
    /**
     * 登录功能
     * @param count 账号
     * @param pass 密码
     * @return 用户对象
     */
    public User login(String count, String pass) throws SQLException {
        return new UserDao().getUser(count,pass);
    }

    /**
     * 注册功能
     * @param userName 用户名
     * @param userPass 用户密码
     * @return 用户对象
     */
    public User register(String userName,String userPass) throws SQLException {
        User user = new User();
        user.setUserName(userName);
        user.setUserPass(userPass);
        Calendar date;
        date = Calendar.getInstance();
        String temp;
        temp = date.get(YEAR)+""+date.get(MONTH)+""+date.get(DATE)+
                ""+date.get(HOUR)+""+date.get(MINUTE)+""+date.get(SECOND)+"";
        user.setUserCount(temp);
        new UserDao().register(user);
        return user;
    }

    /**
     * 对用户注册进行约束
     * @param userName 用户名
     * @param userPass 用户密码
     * @return 结果
     */
    public boolean isTure(String userName,String userPass) {
        if (userName.length() > 8 || userPass.length() > 15 || userPass.length() < 8) {
            return false;
        }
        return true;
    }
}
