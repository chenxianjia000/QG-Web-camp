package util;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.sql.ResultSet;
import java.util.List;


/**
 * 将结果集转换为相对应对象、、
 * @author chenweihuang
 */
public class ResultSetUtil {
    /**
     * 完成转换过程
     * @param result 集合
     * @param rs 结果集
     * @param clazz 要转换成的类
     * @return 转换后的集合
     */
    public static List<?> getObject(List<Object> result, ResultSet rs, Class<?> clazz) {
        try{
            while (rs.next()) {
                Object t = clazz.getConstructor().newInstance();
                Field[] fields = clazz.getDeclaredFields();
                for (Field field : fields) {
                    if (!"class java.lang.String".equals(field.getType().toString())) {
                        continue;
                    }
                    String setterMethodName = getSetterMethodName(field.getName());
                    Method setterMethod = clazz.getMethod(setterMethodName, field.getType());
                    String value = rs.getString(field.getName());
                    setterMethod.invoke(t, value);
                }
                result.add(t);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return result;
    }

    /**
     * 获得setter方法的名称
     * @param fieldName 属性变量的名称
     * @return setter 方法的名称
     */
    private static String getSetterMethodName(String fieldName) {
        String begin = fieldName.substring(0, 1).toUpperCase();
        String end = fieldName.substring(1, fieldName.length());
        return "set" + begin + end;
    }
}
