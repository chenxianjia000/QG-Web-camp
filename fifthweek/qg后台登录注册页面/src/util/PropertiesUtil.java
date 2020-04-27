package util;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

/**
 * 读取文件配置，链接mysql
 */
public class PropertiesUtil {
    private static final Properties properties = new Properties();
    private static final String CONFIG = "jdbc.properties";
    private static final InputStream is = PropertiesUtil.class.getResourceAsStream(CONFIG);
    public static String JDBC_DRIVER;
    public static String JDBC_URL;
    public static String JDBC_USER;
    public static String JDBC_PASS;
    static {
        try {
            properties.load(is);
            JDBC_DRIVER = properties.getProperty("jdbc.driver");
            JDBC_URL = properties.getProperty("jdbc.url");
            JDBC_USER = properties.getProperty("jdbc.user");
            JDBC_PASS = properties.getProperty("jdbc.pass");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
