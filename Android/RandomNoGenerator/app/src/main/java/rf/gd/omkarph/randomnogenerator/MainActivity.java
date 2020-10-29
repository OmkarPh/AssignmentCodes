package rf.gd.omkarph.randomnogenerator;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Dialog;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        this.setTitle("Random No. Generator");
        result = (TextView)findViewById(R.id.result);
    }

    static boolean repeatAfterCycle = true;
    public void changeRepeat(View view){
        repeatAfterCycle = !repeatAfterCycle;
    }

    static int lowNo = 1, highNo = 6;
    static NoRepeat randomCreator = new NoRepeat(1,6);
    static TextView result;

    public void about(View view){
        Toast.makeText(getApplicationContext(), "This app is developed by Omkar Phansopkar.\nHave a nice day :)", Toast.LENGTH_LONG).show();
    }
    public void generateRandomNo(View view) {

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

        int resultNo = -1;

        // Check if cycle bounds have changed
        if(lowerBound != lowNo || upperBound != highNo){
            lowNo = lowerBound;
            highNo = upperBound;
            randomCreator.reset(lowerBound, upperBound);
        }

        // Diversion of repeat after cycle or not

        if(repeatAfterCycle){
            // No repeat, be cautious
            resultNo = randomCreator.nextRandom();
            if(randomCreator.isFull())
                Toast.makeText(getApplicationContext(), "Cycle complete, starting new cycle.\n Regards - Dark ;)", Toast.LENGTH_LONG).show();
        }else{
            // NOs can repeat even before a cycle
            resultNo = (int)(Math.random() * (upperBound - lowerBound + 1) + lowerBound);
        }


        String resultText = String.valueOf(resultNo);
        result.setText(resultText);

    }
}