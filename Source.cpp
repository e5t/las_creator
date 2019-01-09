#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

int main(int argc, char* argv[]){

	int depthCtr = 0;
	int depth;
	int lasLen = 0;
	int bottomMax;
	int topMax;
	string las[14000] ;
	int depthNums[400];
	int depthNumLen = 0;
	int parserCoutn = 0;
	string inputFile = "";
	string outputFile = "";
	string instr = "";
	
	ifstream depthFile;
	// check to see if the proper amount of args were entered
	if ( argc == 3){
		inputFile = argv[1];
		outputFile = argv[2];
		} 
	else if( argc == 2 ) {

		string instr = argv[1];

			if (instr.c_str() == "/?"){
				cout << "LasCreator (c) Jason Turner 2016\n";
				cout << "[LasCreator.WellCompletions.Com]\n\n";
				cout << "Creates a ASCII Las logging file from a Casing Tally.\n\n";
				cout << "LASCREATOR.EXE source [destination] \n\n";
				cout << "source          Specifies the file that contains Casing Collar depths (one depth per line)\n";
				cout << "destination     Specifies the location and name of the new Las file.\n";
				cout << "\n\n";
				cout << "Usage: LasCreator.exe inputfile.txt outputfile.las\n";
				cout << "Or, alternatly you can enter the filenames at the Prompt.\n\n\n";
				system("pause");
				return 0;
			}
		
		}
	
	else {
		cout << "LasCreator (c) Jason Turner 2016\n";
		cout << "[LasCreator.WellCompletions.Com]\n\n";
		cout << "[MANUAL ENTRY]\n\n";
		cout << "Enter the name of the Casing tally text file [ex: F:\\tally.txt]:\n";
		getline(cin, inputFile);
		cout << "Enter the name of the Output filename [ex. F:\\somelasfile.las\n";
		getline(cin, outputFile);
		// return 1;
	}


	// ------------------------------------
	// Build LAS File Header
                las[0] = "~Version Information\n";
                las[1] = "VERS.                      2.0: CWLS Log ASCII Standard - VERSION 2.0\n";
                las[2] = "WRAP.                       NO: One line per depth step\n";
                las[3] = "~Well Information Block\n";
                las[4] = "";
                las[5] = "";
                las[6] = "STEP.FT                -1.0000: STEP\n";
                las[7] = "NULL.                -999.2500: NULL VALUE\n";
                las[8] = "COMP.                         : COMPANY\n";
                las[9] = "WELL.                         : WELL\n";
                las[10] = "FLD.                          : FIELD\n";
                las[11] = "LOC.                          : LOCATION\n";
                las[12] = "DATE.                         : LOG DATE\n";
                las[13] = "SECT.                         : SECTION\n";
                las[14] = "SECT.                         : SECTION\n";
                las[15] = "TOWN.                         : TOWNSHIP\n";
                las[16] = "RANG.                         : RANGE\n";
                las[17] = "API.                          : API#\n";
                las[18] = "OS.                           : OTHER SERVICES\n";
                las[19] = "PDAT.FT                       : PERMANENT DATUM\n";
                las[20] = "EEL.FT                        : ELEVATION\n";
                las[21] = "LMF.FT                        : LOG MEASURED FROM\n";
                las[22] = "DMF.FT                        : DRILLING MEASURED FROM\n";
                las[23] = "EKB.FT                        : KB\n";
                las[24] = "EDF.FT                        : DF\n";
                las[25] = "EGL.FT                        : GL\n";
                las[26] = "DATE1.                        : DATE1\n";
                las[27] = "RUN1.                         : RUN NUMBER\n";
                las[28] = "TDD1.FT                       : DEPTH DRILLER\n";
                las[29] = "TDL1.FT                       : DEPTH LOGGER\n";
                las[30] = "BLI1.FT                       : BOTTOM LOGGED INTERVAL\n";
                las[31] = "TLI1.FT                       : TOP LOG INTERVAL\n";
                las[32] = "CDD1.IN_FT                    : CASING DRILLER\n";
                las[33] = "CDL1.FT                       : CASING LOGGER\n";
                las[34] = "BS1.IN                        : BIT SIZE\n";
                las[35] = "DFT1.                         : TYPE FLUID IN HOLE\n";
                las[36] = "DFDV1.GM/C3_CP                : DENSITY/VISCOSITY\n";
                las[37] = "DFPL1.C3                      : PH/FLUID LOSS\n";
                las[38] = "MSS1.                         : SOURCE OF SAMPLE\n";
                las[39] = "RMT1.OHHM_DEGF                : RM@MEASURED TEMP\n";
                las[40] = "RMFT1.OHMM_DEGF               : RMF@MEASURED TEMP\n";
                las[41] = "RMCT1.OHMM_DEGF               : RMC@MEASURED TEMP\n";
                las[42] = "RMFS1.                        : SOURCE OF RMF/RMC\n";
                las[43] = "RMBT1.OHMM_DEGF               : RM@BHT\n";
                las[44] = "TCS1.                         : TIME CIRCULATION STOPPED\n";
                las[45] = "TLOB1.                        : TIME LOGGER ON BOTTOM\n";
                las[46] = "BHT1.DEGF                     : MAXIMUM RECORDED TEMPERATURE\n";
                las[47] = "LUN1.                         : EQUIPMENT NUMBER\n";
                las[48] = "LUL1.                         : LOCATION\n";
                las[49] = "ENGI1.                        : RECORDED BY\n";
                las[50] = "WITN1.                        : WITNESSED BY\n";
                las[51] = "~Curve Information Block\n";
                las[52] = "CCL.                         0: Casing Collar Locator\n";
                las[53] = "DEPT.FT            0 000 00 00: Depth\n";
                las[54] = "~Parameter Information Block\n";
                las[55] = "~A  Depth       CCL\n"; 
				lasLen = 56;
				// END of LAS BUILD
				// -------------------------------------------


				// read in the data into an array 


	depthFile.open(inputFile.c_str());
	if(depthFile.is_open()){
		while (depthFile >> depth) {
			depthNums[depthNumLen] = depth;
			// print it out to test it
			cout << depthNums[depthNumLen] << "\n";

			depthNumLen++;
			
		}
		cout << "\n\n" << depthNumLen << "\n";
		depthFile.close();
		system("pause");
	} 	else { 
		cout << "unable to open file";
	}
	
	
	// parse the depths
	for (int i = 0; i < depthNumLen; i++) {
		if (i == 0) {
			// firstline in data
			bottomMax = depthNums[i];
			////cout << depthNums[i] << ".0     1.0     ---\n";
			stringstream ss;
			ss << depthNums[i] << ".0000     1.0000\n";
			las[lasLen] = ss.str();
			depthCtr = depthNums[i] - 1;
			lasLen++;

		} else {
			// Loop for all the other depths
			

				while (depthCtr != depthNums[i]) {
					////cout << depthCtr << ".0     0.0     | |\n";
					stringstream ss;
					ss << depthCtr << ".0000     0.0000\n";
					las[lasLen] = ss.str();
					depthCtr--;
					lasLen++;
				}

				cout << depthNums[i] << ".0     1.0     ---\n";
				stringstream ss;
				ss << depthNums[i] << ".0000     1.0000\n";
				las[lasLen] = ss.str();
				depthCtr--;
				lasLen++;
				 //  cout << depthNumLen << "  " << i << "\n";
			     //system("pause");
		}
	}
	topMax = depthCtr + 1;
	cout << bottomMax << "\n";
	cout << topMax << "\n";
	stringstream ssBMax;
	ssBMax << "STRT.FT             " << bottomMax << ".0000: START DEPTH\n";
	las[4] = ssBMax.str();
	stringstream ssSMax;
	ssSMax << "STOP.FT             " << topMax << ".0000: STOP DEPTH\n";
	las[5] = ssSMax.str();
	////system("pause");

	ofstream lasFile(outputFile.c_str());


	for (int i = 0; i < lasLen; i++) {
		//if (i == 57) { system("pause"); }
		////cout << las[i];
		lasFile << las[i];
	}

	////system("pause");


	return 0;
}