#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {

    if (argc < 9){
        cout << "Not enough arguments, need 9 arguments and you gave " << argc << " ..." << endl ;
        cout << "Arguments: ./program <unified/seperate(L1)> 8Kb/16Kb/32Kb " ;
        cout << "L1-1/2/4/8way " ;
        cout << "L1-bsize-4/8/16w " ;
        cout << "dataMissesOfL1Cache InstMissesOfL1Cache " ;
        cout << "L2-bsize-8/16w " ;
        cout << "missesOfL2Cache" << endl ;
        exit(EXIT_FAILURE);
    }

    double T_clock = 1000.0;     //1 GHz
    int extra_miss_cycles_L1 = 0;
    int extra_miss_cycles_L2 = 0;

    /*find clock depended of the size*/
    //cout << argv[1];
    if (string(argv[1]) == "unified"){
        if (string(argv[2]) == "8Kb"){
            T_clock = 950.0;
        }
        else if (string(argv[2]) == "16Kb") {
            T_clock = 900.0;
        }
        else if (string(argv[2]) == "32Kb") {
            T_clock = 850.0;
        }
        else {
            cout << "Error at size of unified L1" << endl;
            exit(1);
        }
    }
    else if (string(argv[1]) == "separate"){
        if (string(argv[2]) == "8Kb"){
            T_clock = 1000.0;
        }
        else if (string(argv[2]) == "16Kb") {
            T_clock = 950.0;
        }
        else if (string(argv[2]) == "32Kb") {
            T_clock = 900.0;
        }
        else {
            cout << "Error at size of separate L1" << endl;
            exit(2);
        }
    } else {
        cout << "Error at unified/separate type of L1" << endl;
        exit(3);
    }


    /*find clock depended of the association of L1 cache*/
    if (string(argv[3]) == "L1-1way") {
        T_clock = T_clock * 1.00;
    }
    else if (string(argv[3]) == "L1-2way") {
        T_clock = T_clock * 0.98;
    }
    else if (string(argv[3]) == "L1-4way") {
        T_clock = T_clock * 0.96;
    }
    else if (string(argv[3]) == "L1-8way") {
        T_clock = T_clock * 0.94;
    } else {
        cout << "Error at association of L1" << endl;
        exit(4);
    }

    /*find extra cycles at misses of L1 depended on block size*/
    string  missL1String1(argv[5]);
    string  missL1String2(argv[6]);
    int missL1 = stoi(missL1String1);
    missL1 += stoi(missL1String2);

    if (string(argv[4]) == "L1-bsize-4w") {
        extra_miss_cycles_L1 += missL1*5;
    }
    else if (string(argv[4]) == "L1-bsize-8w") {
        extra_miss_cycles_L1 += missL1*6;
    }
    else if (string(argv[4]) == "L1-bsize-16w") {
        extra_miss_cycles_L1 += missL1*7;
    } else {
        cout << "Error at block size of L1" << endl;
        exit(5);
    }

    /*find extra cycles at misses of L2 depended on block size*/
    string  missL2String(argv[8]);
    int missL2 = stoi(missL2String);

    if (string(argv[7]) == "L2-bsize-8w") {
        extra_miss_cycles_L2 += missL2*50;
    }
    else if (string(argv[7]) == "L2-bsize-16w") {
        extra_miss_cycles_L2 += missL2*60;
    } else {
        cout << "Error at block size of L2" << endl;
        exit(6);
    }

    int eduMipsCycles = 1287824;
    //Instructions = 1157792;
    //CPI = 1.112;

    int final_cycles = eduMipsCycles + extra_miss_cycles_L1 + extra_miss_cycles_L2;
    double frequency = T_clock * 1000000; //transform to MHz

    double final_time = final_cycles / frequency;

    cout << "EduMips cycles: " << eduMipsCycles << endl;
    cout << "L1 extra cycles: " << extra_miss_cycles_L1 << endl;
    cout << "L2 extra cycles: " << extra_miss_cycles_L2 << endl;
    cout << "T_clock: " << T_clock << endl;
    cout << "Time: " << final_time << endl;


    return 0;
}
