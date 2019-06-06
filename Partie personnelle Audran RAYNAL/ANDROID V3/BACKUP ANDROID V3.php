/* private void validate(){


        Response.Listener<String> responseListener = new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                try {

                    JSONObject jsonObject = new JSONObject(response);
                    boolean color = (boolean) JSONObject.getBoolean("Etat_capteur");

                    if(color){




                    }
                } catch (JSONException e) {
                    e.printStackTrace();
                }


            }
        }; */