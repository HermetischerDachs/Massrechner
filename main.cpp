#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>

using namespace std;

//Massrechner. Ermoeglicht Eingabe von Laengenmassen verschiedener Einheiten und speichert die kuerzeste, bzw. laengste Messung. Am Ende Ausgabe
//der Gesamtlaenge.
//Autor: Ahmet Yasar
//Betaversion 1.0


//Wandelt einen Wert mit dazugehöriger Einheit in Cm um und gibt dieses zurück
double convertToCm(double value, string unit){
    if(unit == "cm"){
        return value;
    }else if(unit == "in"){
        return value * 2.54;
    }else if(unit == "ft"){
        return value * 30.48;
    }else if(unit == "m"){
        return value * 100;
    }
}

int main(){

    //Idee, die eingegeben Maße der jeweligen Einheit im Hintergrund in Cm umzurechnen und abzuspeichern, um sie miteinander vergleichen zu
    //können. Vergleich über Umrechnung in Cm, Ausgabe in der ursprünglich angegebenen Einheit. Annahme, dass der Nutzer stets eine
    //Fließkommazahl eingibt, und anschließend eine dazugehörige Einzeit
    double smallest=1000, biggest = -1000, temp;             //Eingegebener Wert
    double smallestInCm=1000, biggestInCm = -1000, tempInCm; //Umgerechnet in Cm
    double sum = 0;
    string eingabe = "";
    string unit = "";
    string unitSmallest, unitBiggest;
    const double inToCm = 2.54;
    const double ftToCm = 30.48;
    const double mToCm = 100;
    vector <double> values;

    //Bis zur Eingabe eines "|", immer wieder neue Eingaben ermöglichen
    while(eingabe != "|"){
        try{
        cout << "Eine Zahl eingeben: \n";
        cin >> temp;
        cout << "Eine Einheit angeben [cm/in/ft/m]: \n";
        cin >> unit;
        if(unit != "cm" && unit != "in" && unit != "ft" && unit != "m"){
            throw std::invalid_argument ("Invalid argument");
        }
        }catch(exception){
            cerr << unit << " ist keine gueltige Einheit. Bitte gueltige Einheit eingeben" << "\n";
            continue;
        }
        cout << "Eingabe: " << temp << unit << "\n";
        cout << "Eingabe in cm: " << convertToCm(temp, unit) << "cm" << "\n";

        tempInCm = convertToCm(temp, unit);
        //Erweitert den Vektor bestehend aus den Werten um die letzte Eingabe umgerechnet in Cm
        values.push_back(tempInCm/100);

        //Wert abgleichen, ob er größer oder kleiner als die bisherigen Eingaben ist
        if(tempInCm > biggestInCm){
            smallest = biggest;
            biggest = temp;
            biggestInCm = convertToCm(biggest, unit);
            unitBiggest = unit;
            sum += biggestInCm;
            cout << "Groesste Zahl bis jetzt: " << biggest << unitBiggest << "\n";
        }else if(tempInCm < smallestInCm){
            smallest = temp;
            smallestInCm = convertToCm(smallest, unit);
            unitSmallest = unit;
            sum += smallestInCm;
            cout << "Kleinste Zahl bis jetzt: " << smallest << unitSmallest << "\n";
        }else{
            sum += tempInCm;
            cout << "Weder groesser noch kleiner \n";
        }
        cout << "Falls Sie das Programm beenden möchten, bitte [|] eingeben. Ansonsten mit EINGABE fortfahren\n";
        cin >> eingabe;
    }
        cout << "Kleinste Zahl bis jetzt: " << smallest << unitSmallest << "\n";
        cout << "Groesste Zahl bis jetzt: " << biggest << unitBiggest << "\n";
        cout << "Summe in Metern: " << sum/100 << "Meter \n";
        sort(values.begin(), values.end());
        int counter = 1;
        for(double value : values){
            cout << "Wert " << counter << ": " << value << "\n";
            counter++;
        }
}



