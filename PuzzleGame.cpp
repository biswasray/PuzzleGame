#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
int block[4][4];
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ESC 27
int vm=0;
int vn=0;
int movecount=0;
bool active=true;
bool gameover=false;
void print() {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
                if(block[i][j]==0)
                    cout<<"\t"<<"#";
                else
                    cout<<"\t"<<block[i][j];
        }
        cout<<"\n";
    }
}
void update() {
    system("cls");
    cout<<"Use arrow keys to move blocks\nPress ESC key to exit\n\n";
    print();
    cout<<"\n"<<movecount<<" block moved";
    if(gameover)
        return;
    int c=_getch();
    int t=c;
    if(c==224) {
        t=c=_getch();
    }
    else
        cout<<endl<<c<<endl;
    //t=c;
    switch(c) {
    case DOWN:
        if(vm>0) {
            block[vm][vn]=block[vm-1][vn];
            block[vm-1][vn]=0;
            vm--;
            movecount++;
        }
        break;
    case RIGHT:
        if(vn>0) {
            block[vm][vn]=block[vm][vn-1];
            block[vm][vn-1]=0;
            vn--;
            movecount++;
        }
        break;
    case UP:
        if(vm<3) {
            block[vm][vn]=block[vm+1][vn];
            block[vm+1][vn]=0;
            vm++;
            movecount++;
        }
        break;
    case LEFT:
        if(vn<3) {
            block[vm][vn]=block[vm][vn+1];
            block[vm][vn+1]=0;
            vn++;
            movecount++;
        }
        break;
    case ESC:
        active=false;
        cout<<"You exited the game\nThank you for playing";
        break;
    default :
        cout<<"INvaLid\n";
    }

}
bool checkGameActive() {
    if(!active)
        return false;
    for(int i=0;i<15;i++) {
        if(block[i/4][i%4]!=(i+1))
            return true;
    }
    return false;
}
void init() {
    movecount=0;
    active=true;
    gameover=false;
    block[0][0]=1;
    block[0][1]=4;
    block[0][2]=15;
    block[0][3]=7;
    block[1][0]=8;
    block[1][1]=10;
    block[1][2]=2;
    block[1][3]=11;
    block[2][0]=14;
    block[2][1]=3;
    block[2][2]=6;
    block[2][3]=13;
    block[3][0]=12;
    block[3][1]=9;
    block[3][2]=5;
    block[3][3]=0;
    vm=3;
    vn=3;
}
int main() {
    //Demo
    /*movecount=0;
    active=true;
    gameover=false;
    block[0][0]=1;
    block[0][1]=2;
    block[0][2]=3;
    block[0][3]=4;
    block[1][0]=5;
    block[1][1]=6;
    block[1][2]=7;
    block[1][3]=8;
    block[2][0]=9;
    block[2][1]=10;
    block[2][2]=11;
    block[2][3]=12;
    block[3][0]=13;
    block[3][1]=14;
    block[3][2]=0;
    block[3][3]=15;
    vm=3;
    vn=2;*/

    init();
    while(checkGameActive()) {
        update();
    }
    if(active) {
        gameover=true;
        update();
        cout<<"\nGame Over\nYou completed the block in "<<movecount<<" move\nDo you want to play again(y/n)";
        int cr;
        if((cr=_getch())==121)
            main();
        else {
            int r=cr;
        }
    }
    cout<<"\nPress any key to exit.";
    _getch();
    return 0;
}
