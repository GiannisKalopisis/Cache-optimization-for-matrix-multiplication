#include <iostream>

using namespace std;

int main() {
    int count=0;
    string command="./dineroIV -l2-usize 64k -l2-urepl l -l2-uassoc 4 -l2-uwback a -l2-uwalloc a ";
    string type;
    for(int i=0; i<2; i++){
        string command1;
        if(i==1) {
            command1="-l1-uwback a -l1-uwalloc a -l1-urepl l ";
            type='u';
        }
        else{
            command1="-l1-dwback a -l1-dwalloc a -l1-irepl l -l1-drepl l ";
            type='i';
        }
        for(int j=8; j<33; j*=2){
            string command2;
            if(i==1) {
                command2="-l1-usize "+to_string(j)+"k ";
            }
            else{
                command2="-l1-isize "+to_string(j/2)+"k -l1-dsize "+to_string(j/2)+"k ";
            }
            for(int x=1; x<9; x*=2){
                string command3;
                if(i==1) {
                    command3="-l1-uassoc "+to_string(x) + " ";
                }
                else{
                    command3="-l1-iassoc "+to_string(x)+" -l1-dassoc "+to_string(x) + " ";
                }
                for(int y=4; y<17; y*=2){
                    string command4;
                    if(i==1) {
                        command4="-l1-ubsize "+to_string(y) + " ";
                    }
                    else{
                        command4="-l1-ibsize "+to_string(y)+" -l1-dbsize "+to_string(y) + " ";
                    }
                    for(int z=8; z<17; z+=8){
                        string command5="-l2-ubsize "+to_string(z) + " < ergasia2_50x50.s.xdin";
                        cout<<command;
                        cout<<command1;
                        cout<<command2;
                        cout<<command3;
                        cout<<command4;
                        cout<<command5<<endl;
                        count++;
                    }
                }
            }
        }
    }
    cout<<endl;
    cout<<to_string(count) + " commands"<<endl;
}
