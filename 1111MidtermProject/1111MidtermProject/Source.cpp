/*
 * Brittany Munyeshuli
 * CIS 1111
 * Midterm Project
 * This project will calculate efficiencies for radiation survey technicians in the field
 */


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

	cout << "       Rad Survey Efficiency Calculator" << endl << endl << endl;

	string todaysDate, currentTime, currentTemp, currentHum, meterHV; 
	

	cout << "Today's Date: ";
	cin >> todaysDate;

	cout << "Current Time: ";
	cin >> currentTime;

	cout << "Current Temperature in degrees F: ";
	cin >> currentTemp;

	cout << "Current % Humidity: ";
	cin >> currentHum;
	
	cout << "___________________________________________________________________________________" << endl << endl;

	cout << "   1 for Ludlum 2221 and FIDLER" << endl; 
	cout << "   2 for Ludlum 2221 and 44-10" << endl;
	cout << "   3 for Ludlum 3 and 44-9" << endl;
	cout << "   4 for Ludlum 2360 and 43-89" << endl;
	
	int equipPair;
	cout << " " << endl;
	cout << "Your selection is: ";
	cin >> equipPair;
	
	cout << "           " << endl;

	if (equipPair >= 1 && equipPair <= 4) {
		
		string sourceType, alphaSource, betaSource, serialNum2221, serialNumFidler, serialNum4410, serialNum3, serialNum449, serialNum2360, serialNum4389, sourceSN, alphaSourceSN, betaSourceSN;

		double  sourceActivity, alphaSourceActivity, betaSourceActivity, minBackground, sourceReading, alphaBkd, betaBkd, alphaRdgAlphaSrc, betaRdgAlphaSrc, betaRdgBetaSrc, alphaRdgBetaSrc, percentEff, alphaXTalk, betaXTalk, alphaEff, betaEff;


		switch (equipPair) {
		
		case 1:
			cout << "Ludlum 2221 Serial Number: ";
			cin >> serialNum2221;

			cout << "FIDLER Serial Number: ";
			cin >> serialNumFidler;

			cout << "Source type: ";
			cin >> sourceType;

			cout << "Source Serial Number: ";
			cin >> sourceSN;

			cout << "Source activity in DPM: ";
			cin >> sourceActivity;

			cout << "1 minute background reading in cpm: ";
			cin >> minBackground;

			cout << "Reading with source 0.25 inches from detector face: ";
			cin >> sourceReading;

			cout << "___________________________________________________________________________________" << endl << endl;

			//Efficiency Calculation
			percentEff = ((sourceReading - minBackground) / sourceActivity) * 100;
			
			//Summary of data and calculations

			cout << "                Data Results for Field Efficiency" << endl << endl;
			cout << "   Date" << "             Time" << "         Temperature" << "          Humidity" << endl;
			cout << "  " << todaysDate << "	    " 
				         << currentTime << "             " 
						 << currentTemp << "F              " 
						 << currentHum << "%     " << endl << endl;

			cout << "Ludlum 2221   SN: " << serialNum2221 
				 << "        FIDLER   SN: " << serialNumFidler << endl << endl;
			cout << sourceType << "   SN: " << sourceSN << "  " << setprecision(7) 
				 << sourceActivity << " DPM" << endl << endl;

			cout << "Background Reading: " << minBackground << " CPM    " 
				 << "Reading with " << sourceType << ": " 
				 << sourceReading << " CPM" << endl<< endl;
			
			cout << "Calculated Efficiency: " << setprecision(3) << percentEff << "%" << endl << endl << endl;

			break;
		
			case 2:
			cout << "Ludlum 2221 Serial Number: ";
			cin >> serialNum2221;

			cout << "Ludlum 44-10 Serial Number: ";
			cin >> serialNum4410;

			cout << "Source type: ";
			cin >> sourceType;

			cout << "Source Serial Number: ";
			cin >> sourceSN;

			cout << "Source activity in DPM: ";
			cin >> sourceActivity;

			cout << "1 minute background reading in cpm: ";
			cin >> minBackground;

			cout << "Reading with source 0.25 inches from detector face: ";
			cin >> sourceReading;

			cout << "___________________________________________________________________________________" << endl << endl;

			//Summary of data and calculations

			cout << "                Data Results for Field Efficiency" << endl << endl;
			cout << "   Date" << "             Time" << "         Temperature" << "          Humidity" << endl;
			cout << "  " << todaysDate << "	    " 
						 << currentTime << "             " 
					     << currentTemp << "F              " 
						 << currentHum << "%     " << endl << endl;
			
			cout << "Ludlum 2221   SN: " << serialNum2221 
				 << "        Ludlum 44-10   SN: " << serialNum4410 << endl << endl;

			cout << sourceType << "   SN: " << sourceSN << "  " << setprecision(6) 
				 << sourceActivity << " DPM" << endl << endl;

			cout << "Background Reading: " << minBackground << " CPM    " 
				 << "Reading with " << sourceType << ": " << sourceReading << " CPM" << endl << endl;
			

			//Efficiency Calculation
			percentEff = ((sourceReading - minBackground) / sourceActivity) * 100;

			cout << "Calculated Efficiency: " << setprecision(3) << percentEff << "%" << endl << endl << endl;

			break;
		
			case 3:
			cout << "Ludlum 3 Serial Number: ";
			cin >> serialNum3;

			cout << "Ludlum 44-9 Serial Number: ";
			cin >> serialNum449;

			cout << "Source type: ";
			cin >> sourceType;

			cout << "Source Serial Number: ";
			cin >> sourceSN;

			cout << "Source activity in DPM: ";
			cin >> sourceActivity;

			cout << "1 minute background reading in cpm: ";
			cin >> minBackground;

			cout << "Reading with source 0.25 inches from detector face: ";
			cin >> sourceReading;

			cout << "___________________________________________________________________________________" << endl << endl;

			//Summary of data and calculations

			cout << "                Data Results for Field Efficiency" << endl << endl;
			cout << "   Date" << "             Time" << "         Temperature" << "          Humidity" << endl;
			cout << "  " << todaysDate << "	    " 
						 << currentTime << "             " 
						 << currentTemp << "F               " 
						 << currentHum << "%     " << endl << endl;

			cout << "Ludlum 3   SN: " << serialNum3 
				 << "       Ludlum 44-9   SN: " << serialNum449 << endl << endl;

			cout << sourceType << "   SN: " 
				 << sourceSN << "  " << setprecision(5) 
				 << sourceActivity << " DPM" << endl << endl;
			
			cout << "Background Reading: " << minBackground << " CPM    " 
				 << "Reading with " << sourceType << ": " 
				 << sourceReading << " CPM" << endl << endl;
			

			//Efficiency Calculation
			percentEff = ((sourceReading - minBackground) / sourceActivity) * 100;

			cout << "Calculated Efficiency: " << setprecision(3) << percentEff << "%" << endl << endl << endl;

			break;

		case 4:
			cout << "Ludlum 2360 Serial Number: ";
			cin >> serialNum2360;

			cout << "Ludlum 43-89 Serial Number: ";
			cin >> serialNum4389;

			cout << "Alpha Source: ";
			cin >> alphaSource;

			cout << "Alpha Source Serial Number: ";
			cin >> alphaSourceSN;

			cout << "Alpha Source activity in DPM: ";
			cin >> alphaSourceActivity;

			cout << "Beta Source: ";
			cin >> betaSource;

			cout << "Beta Source Serial Number: ";
			cin >> betaSourceSN;

			cout << "Beta Source activity in DPM: ";
			cin >> betaSourceActivity;

			cout << "Alpha Background: ";
			cin >> alphaBkd;

			cout << "Beta Background: ";
			cin >> betaBkd;

			cout << "Alpha Reading with Alpha Source: ";
			cin >> alphaRdgAlphaSrc;

			cout << "Beta Reading with Alpha Source: ";
			cin >> betaRdgAlphaSrc;

			cout << "Beta Reading with Beta Source: ";
			cin >> betaRdgBetaSrc;

			cout << "Alpha Reading with Beta Source: ";
			cin >> alphaRdgBetaSrc;
			
	alphaXTalk = ((betaRdgAlphaSrc) - (betaBkd)) / (alphaRdgAlphaSrc)*100;
    betaXTalk = ((alphaRdgBetaSrc) - (alphaBkd)) / (betaRdgBetaSrc)*100;
	alphaEff = (((alphaRdgAlphaSrc) - (alphaBkd)) / (alphaSourceActivity)) * 100;
	betaEff = (((betaRdgBetaSrc) - (betaBkd)) / (betaSourceActivity)) * 100;

	cout << "                Data Results for Field Efficiency" << endl << endl;
	cout << "   Date" << "             Time" << "         Temperature" << "          Humidity" << endl;
	cout << "  " << todaysDate << "	    "
		<< currentTime << "             "
		<< currentTemp << "F               "
		<< currentHum << "%     " << endl << endl;

	cout << "Ludlum 2360   SN: " << serialNum2360
		 << "        43-89   SN: " << serialNum4389 << endl << endl;

	cout << alphaSource << "   SN: " << alphaSourceSN << setprecision(5) << alphaSourceActivity << " DPM" << endl << endl;
	cout << betaSource << "    SN: " << betaSourceSN << setprecision(5) << betaSourceActivity << " DPM" << endl << endl;

	cout << "Alpha Crosstalk: " << setprecision (3) << alphaXTalk << " %" << "       " 
		 << "Beta Crosstalk: " << setprecision(3) << betaXTalk << " %" << endl << endl;

	cout << "Alpha Efficiency: " << setprecision(3) << alphaEff << " %" << "       "
		 << "Beta Efficiency: " << setprecision(3) << betaEff << " %" << endl << endl;


	break;

		
		default:
			cout << "Error. Please Try Again." << endl;
		
		}
	}
	else {
		//invalid choice
		cout << "Please select a valid Equipment Pairing option." << endl;
	}
	

	system("pause");
	return 0;
}
