<?php


$data = '{
	"capteur": "pluvio",
	"etat": "1"
}';

$capt = json_decode($data);


echo $capt->capteur;


$url = "10.16.37.161";

?>
