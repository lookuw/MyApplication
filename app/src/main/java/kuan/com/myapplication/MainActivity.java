package kuan.com.myapplication;

import android.app.Activity;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = (TextView)findViewById(R.id.tv);
        tv.setText(new EventReader().getEventFromInput());

        View rl = findViewById(R.id.rl_content);
        rl.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                EventReader.showEvent();
            }
        });
    }
}
