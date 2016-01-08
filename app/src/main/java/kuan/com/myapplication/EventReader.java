package kuan.com.myapplication;

/**
 * Created by dell on 2016/1/4.
 */
public class EventReader {
    static{
        System.loadLibrary("jniEvent");
    }

    public static native String getEventFromInput();

    public static native void showEvent();
}
