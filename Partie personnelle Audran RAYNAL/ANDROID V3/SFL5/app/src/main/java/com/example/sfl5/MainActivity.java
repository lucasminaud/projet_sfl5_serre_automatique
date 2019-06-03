package com.example.sfl5;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.provider.ContactsContract;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;

import java.lang.Object;


public class MainActivity extends AppCompatActivity {

    EditText pas,usr;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ImageView imageView_capteur1 = (ImageView) findViewById(R.id.ImageView_capteur1);
        ImageView imageView_capteur2 = (ImageView) findViewById(R.id.ImageView_capteur2);
        ImageView imageView_capteur3 = (ImageView) findViewById(R.id.ImageView_capteur3);
        ImageView imageView_capteur4 = (ImageView) findViewById(R.id.ImageView_capteur4);
        ImageView imageView_capteur5 = (ImageView) findViewById(R.id.ImageView_capteur5);
        ImageView imageView_capteur6 = (ImageView) findViewById(R.id.ImageView_capteur6);


        imageView_capteur1.setColorFilter(getApplicationContext().getResources().getColor(R.color.colorPrimary));
        imageView_capteur2.setColorFilter(getApplicationContext().getResources().getColor(R.color.colorAccent));
        imageView_capteur3.setColorFilter(getApplicationContext().getResources().getColor(R.color.colorPrimary));
        imageView_capteur4.setColorFilter(getApplicationContext().getResources().getColor(R.color.colorPrimary));
        imageView_capteur5.setColorFilter(getApplicationContext().getResources().getColor(R.color.colorAccent));
        imageView_capteur6.setColorFilter(getApplicationContext().getResources().getColor(R.color.colorPrimary));




        //usr = (EditText) findViewById(R.id.username);
        //pas = (EditText) findViewById(R.id.password);

    }


    public final class Boolean{
       boolean color =




    }


    public void loginBtn(View view){

        String user = usr.getText().toString();
        String pass = pas.getText().toString();

        background bg = new background(this);
        bg.execute(user,pass);

    }

   /* private void validate(){


        Response.Listener<String> responseListener = new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                try {

                    JSONObject jsonObject = new JSONObject(response);
                    boolean color = JSONObject.getBoolean("color");


                    if(color){






                    }
                }



            }
        }








    }*/



}
