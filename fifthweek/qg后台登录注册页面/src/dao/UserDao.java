package dao;

import po.User;
import util.JdbcUtil;
import util.ResultSetUtil;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;


public class UserDao {
    @SuppressWarnings("unchecked")
    public User getUser(String count, String pass)  {
        String sql = "select * from user_table where " +
                "userCount ='" + count + "'and  userPass = '" + pass + "';";
        ResultSet rs = JdbcUtil.getJdbcUtil().executeQuery(sql);
        List<User> datas = (List<User>) ResultSetUtil.getObject(new ArrayList<>(), rs, User.class);
        return (datas.size() == 1) ?  datas.get(0) : null;
    }


    public void register(User user) throws SQLException {
        String userCount;
        userCount = "\""+user.getUserCount()+"\"";
        String userName;
        userName = "\""+user.getUserName()+"\"";
        String userPass;
        userPass = "\""+user.getUserPass()+"\"";
        String sql = "insert into user_table(userName,userCount,userPass) values("+
                userName+","+userCount+","+userPass+");";
        JdbcUtil.getJdbcUtil().executeUpdate(sql);
    }
}
