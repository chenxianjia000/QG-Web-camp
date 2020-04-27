package util;


import java.sql.*;

public class JdbcUtil {
    private static String DRIVER = PropertiesUtil.JDBC_DRIVER;
    private static String URL = PropertiesUtil.JDBC_URL;
    private static String USER = PropertiesUtil.JDBC_USER;
    private static String PASS = PropertiesUtil.JDBC_PASS;
    private static JdbcUtil jdbcUtil;
    private Statement stmt;



    private JdbcUtil() throws SQLException {

        try {
            Class.forName(DRIVER);
            Connection connection = null;
            connection = DriverManager.getConnection(URL,USER,PASS);
            stmt = connection.createStatement();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }



    public static JdbcUtil getJdbcUtil()  {
        if(jdbcUtil == null){
            try {
                jdbcUtil = new JdbcUtil();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
        return jdbcUtil;
    }



    public ResultSet executeQuery(String sql) {
        try {
            return stmt.executeQuery(sql);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public int executeUpdate(String sql) {
        int result = -1;
        try {
            stmt.executeUpdate(sql,Statement.RETURN_GENERATED_KEYS);
            ResultSet rs = stmt.getGeneratedKeys();
            while (rs.next()){
                result =rs.getInt(1);
            }
            rs.close();
            return result;
        } catch (SQLException throwables) {
            throwables.printStackTrace();
            return 0;
        }
    }
}
