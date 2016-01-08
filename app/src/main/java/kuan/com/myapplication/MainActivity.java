package kuan.com.myapplication;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends ActionBarActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        TextView tv = new TextView(this);
        tv.setText(new EventReader().getEventFromInput());
        setContentView(tv);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        EventReader.showEvent();
        return super.onTouchEvent(event);
    }
}
