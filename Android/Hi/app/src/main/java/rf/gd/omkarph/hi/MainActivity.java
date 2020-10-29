package rf.gd.omkarph.hi;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        this.setTitle("Random No. Generator");
    }


    public void generateRandomNo(View view) {

        /*
        Random r = new Random();
        int no = r.nextInt(6);
        no++;
        TextView result = (TextView)findViewById(R.id.result);

        String resultText = String.valueOf(no);
        result.setText(resultText);

         */

        EditText from = (EditText)findViewById(R.id.fromNo);
        EditText to = (EditText)findViewById(R.id.toNo);

        int lowerBound = Integer.parseInt(from.getText().toString());
        int upperBound = Integer.parseInt(to.getText().toString());

        if(lowerBound > upperBound){
            int temp = lowerBound;
            lowerBound = upperBound;
            upperBound = temp;
        }

        if(lowerBound == 0 && upperBound == 0){
            upperBound = 6;
        }

        from.setText(String.valueOf(lowerBound));
        to.setText(String.valueOf(upperBound));

        int resultNo = (int)(Math.random() * (upperBound - lowerBound + 1) + lowerBound);

        TextView result = (TextView)findViewById(R.id.result);
        String resultText = String.valueOf(resultNo);
        result.setText(resultText);

    }
}