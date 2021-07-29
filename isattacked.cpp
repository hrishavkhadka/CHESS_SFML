#include "boardstate.h"

int a_narr[11]{2,1,-1,-2,-2,-1,1,2,2,1,-3};
int a_karr[11]{1,1,1,0,-1,-1,-1,0,1,1,-2};

bool boardstate::isattacked(int i,int j,bool player){
    int adjust{0};
    int pflag{1};
    if(!player){             //if black then adjust
        adjust=7;
        pflag= -1;
    }
    //std::cout<<"isattacked called"<<std::endl;
    //bishop and queen
    for (int itr_a=i,itr_b=j;itr_a<8 && itr_b<8;itr_a++,itr_b++){
        if (itr_b==j){
            continue;
        }
        if (piece(board[itr_a][itr_b])==empty) {
            continue;
        }
        else if (piece(board[itr_a][itr_b])!=(b+adjust) && piece(board[itr_a][itr_b])!=(q+adjust)){
            break;
        }
        else{
            //std::cout<<"isattacked by bishop 1.1"<<std::endl;
            return true;
        }
    }
    for (int itr_a=i,itr_b=j;itr_a>=0 && itr_b<8;itr_a--,itr_b++){
        if (itr_b==j){
            continue;
        }
        if (piece(board[itr_a][itr_b])==empty) {
            continue;
        }
        else if (piece(board[itr_a][itr_b])!=(b+adjust) && piece(board[itr_a][itr_b])!=(q+adjust)){
            break;
        }
        else{
            //std::cout<<"isattacked by bishop 1.2"<<std::endl;
            return true;
        }
    }

    for (int itr_a=i,itr_b=j;itr_a<8 && itr_b>=0;itr_a++,itr_b--){
        if (itr_b==j){
            continue;
        }
        if (piece(board[itr_a][itr_b])==empty) {
            //std::cout<<itr_a<<itr_b<<std::endl;
            continue;
        }
        else if (piece(board[itr_a][itr_b])!=(b+adjust) && piece(board[itr_a][itr_b])!=(q+adjust)){
            //std::cout<<itr_a<<itr_b<<std::endl;
            //std::cout << "blocked by : "<<piece(board[itr_a][itr_b])<<std::endl;
            break;
        }
        else{
            //std::cout<<"isattacked by bishop 1.4"<<std::endl;

            return true;
        }
    }
     for (int itr_a=i,itr_b=j;itr_a>=0 && itr_b>=0;itr_a--,itr_b--){
        if (itr_b==j){
            continue;
        }
        if (piece(board[itr_a][itr_b])==empty) {
            //std::cout<<itr_a<<itr_b<<std::endl;
            continue;
        }
        else if (piece(board[itr_a][itr_b])!=(q+adjust) && piece(board[itr_a][itr_b])!=(b+adjust)){
            //std::cout<<itr_a<<itr_b<<std::endl;
            break;
        }
        else{
            //std::cout<<"isattacked by bishop 1.3"<<std::endl;
            return true;
        }
    }
    //rook and queen
    for (int itr_a=i;itr_a<8;itr_a++){
        if (itr_a==i){
            continue;
        }
        if (piece(board[itr_a][j])==empty) {
            continue;
        }
        else if ((piece(board[itr_a][j])!=(r+adjust)) && piece(board[itr_a][j])!=(q+adjust)){
            break;
        }
        else{
            //std::cout<<"isattacked by rook 1.0"<<std::endl;
            return true;
        }
    }
    for (int itr_a=i;itr_a>=0;itr_a--){
        if (itr_a==i){
            continue;
        }
        if (piece(board[itr_a][j])==empty) {
            continue;
        }
        else if (piece(board[itr_a][j])!=(r+adjust) && piece(board[itr_a][j])!=(q+adjust)){
            break;
        }
        else{
            //std::cout<<"isattacked by rook 1.1"<<std::endl;
            return true;
        }
    }

    for (int itr_b=j;itr_b>=0;itr_b--){
        if (itr_b==j){
            continue;
        }
        if (piece(board[i][itr_b])==empty) {
            continue;
        }
        else if (piece(board[i][itr_b])!=(r+adjust) && piece(board[i][itr_b])!=(q+adjust)){
            break;
        }
        else{
            //std::cout<<"isattacked by rook 1.3"<<std::endl;
            return true;
        }
    }
    for (int itr_b=j;itr_b<8;itr_b++){
        if (itr_b==j){
            continue;
        }
        if (piece(board[i][itr_b])==empty) {
            continue;
        }
        else if (piece(board[i][itr_b])!=(r+adjust) && piece(board[i][itr_b])!=(q+adjust)){
            break;
        }
        else{
            //std::cout<<"isattacked by rook 1.2"<<std::endl;
            return true;
        }
    }
    //knight
    int itr_a{0},itr_b{2};

    while(1){
        if(a_narr[itr_b]==-3){
            break;
        }
        if((i+a_narr[itr_a])<0 || (j+a_narr[itr_b])<0 || (i+a_narr[itr_a])>=8 || (j+a_narr[itr_b])>=8){
            itr_a++;
            itr_b++;
            continue;
        }
        if(piece(board[i+a_narr[itr_a]][j+a_narr[itr_b]])==(n+adjust)){
            return true;
        }
        itr_a++;
        itr_b++;
    }
    //pawn
    if((player && i<6)||(!player && i>1 )){
        if (((j+1)<8) && piece(board[i+pflag][j+1])==(p+adjust)){
            return true;
        }
        if (((j-1)>0) && piece(board[i+pflag][j-1])==(p+adjust)){
            return true;
        }
    }
    //king{1,1,1,0,-1,-1,-1,0,1,1,-2}
    itr_a=2;
    itr_b=0;

    while(1){
        if(a_karr[itr_a]==-2){
            break;
        }
        if((i+a_karr[itr_a])<0 || (j+a_karr[itr_b])<0 || (i+a_karr[itr_a])>=8 || (j+a_karr[itr_b])>=8){
            itr_a++;
            itr_b++;
            continue;
        }
        if(piece(board[i+a_karr[itr_a]][j+a_karr[itr_b]])==(k+adjust)){
            return true;
        }
        itr_a++;
        itr_b++;
    }
    return false;
}
