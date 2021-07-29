#include "def.h"
#include "boardstate.h"
#include <bitset>

int m_narr[11]{2,1,-1,-2,-2,-1,1,2,2,1,-3};
int m_karr[11]{1,1,1,0,-1,-1,-1,0,1,1,-2};


void boardstate::getmove(unsigned int movelist[256]) {

    //std::cout<<"getmove called"<<std::endl;

	unsigned int tempmove{0};
	unsigned int index{0};
    unsigned int checkpiece;
    int itr_a{0},itr_b{2};
	
	if(gturn){                                            //white.......................................................................................

	  //  std::cout<<"generating for white"<<std::endl;

	    for (int i = 0; i < 8; i++) {
           
            if(index>255){
                break;
            }

            for (int j = 0; j < 8; j++) {
               
                if(index>255){
                    
                    break;
                }

                if(piece(board[i][j])<=empty){
                    
                    continue;
                }


                checkpiece = piece(board[i][j]);
                if(checkpiece==P){                         //white pawn .................................................................................
                  
                    if(i==1 && piece(board[i+1][j])==empty && piece(board[i+2][j])==empty){    //double sq move
                       
                        setmove(tempmove,i,j,(i+2),j,0,0,0,0,0);
                        if(!ischeckedaftermove(*this,tempmove,1)){
                            movelist[index] = tempmove;
                            sscore(movelist[index],diff(movelist[index]));
                            index++;
                        }
                        tempmove = 0;
                      
                    }
                    if(i<6){                    //one step moves not including promotions
                        if(piece(board[i+1][j])==empty){
                         
                            setmove(tempmove,i,j,(i+1),j,0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                    
                        }

                        if(j<7 && (piece(board[i+1][j+1]) < empty || checkenpassant((i+1),(j+1))) ){                 //right side capture

                            setmove(tempmove,i,j,(i+1),(j+1),0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                            movelist[index] = tempmove;
                            sscore(movelist[index],diff(movelist[index]));
                            index++;
                            }
                            tempmove = 0;
                        }
                        if(j>0 && (piece(board[i+1][j-1]) < empty || checkenpassant((i+1),(j-1))) ){                 //left side capture

                            setmove(tempmove,i,j,(i+1),(j-1),0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                            movelist[index] = tempmove;
                            sscore(movelist[index],diff(movelist[index]));
                            index++;
                            }
                            tempmove = 0;
                        }
                    }

                    if(i==6  ){                    //for promotions
                        if(board[i+1][j]==empty){
                            setmove(tempmove,i,j,(i+1),j,1,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i+1),j,0,1,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i+1),j,0,0,1,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i+1),j,0,0,0,1,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                        if(j<7 && (piece(board[i+1][j+1]) < empty) ){                                        //right side capture
                            setmove(tempmove,i,j,(i+1),(j+1),1,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i+1),(j+1),0,1,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i+1),(j+1),0,0,1,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i+1),(j+1),0,0,0,1,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                        if(j>0 && (piece(board[i+1][j-1]) < empty) ){                                        //left side capture
                            setmove(tempmove,i,j,(i+1),(j-1),1,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i+1),(j-1),0,1,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i+1),(j-1),0,0,1,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i+1),(j-1),0,0,0,1,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }

                    }
    
                    continue;
                }

                else if(checkpiece==K){                        //white king .........................................................................

                    itr_a=2;
                    itr_b=0;

                    while(1){
        
                        if(m_karr[itr_a]==-2){
     
                            break;
                        }
                        if((i+m_karr[itr_a])<0 || (j+m_karr[itr_b])<0 || (i+m_karr[itr_a])>=8 || (j+m_karr[itr_b])>=8){
                            itr_a++;
                            itr_b++;
        
                            continue;
                        }
                        if(piece(board[i+m_karr[itr_a]][j+m_karr[itr_b]]) <= empty){
             
                            setmove(tempmove,i,j,(i+m_karr[itr_a]),(j+m_karr[itr_b]),0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                        itr_a++;
                        itr_b++;
                    }
                    if(i==0 && j==4){

                        if(castle(board[0][0]) && castle(board[0][4]) && (piece(board[0][1])==empty && piece(board[0][2])==empty && piece(board[0][3])==empty)
                        && !(isattacked(0,2,1) || isattacked(0,3,1) || isattacked(0,4,1))){
             
                            setmove(tempmove,0,4,0,2,0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                        if(castle(board[0][7]) && castle(board[0][4]) && (piece(board[0][6])==empty && piece(board[0][5])==empty )
                        && !(isattacked(0,6,1) || isattacked(0,5,1) || isattacked(0,4,1))){

                            setmove(tempmove,0,4,0,6,0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
      
                    }
        
                    continue;

                }

                else if(checkpiece == N ){                      //white knight .........................................................................
           
                    itr_a=0;
                    itr_b=2;
             

                    while(1){
                        if(m_narr[itr_b]== (-3)){

          

                            break;

                        }
                        if((i+m_narr[itr_a])<0 || (j+m_narr[itr_b])<0 || (i+m_narr[itr_a])>=8 || (j+m_narr[itr_b])>=8){
                            itr_a++;
                            itr_b++;
                
                            continue;

                        }
                        if(piece(board[i+m_narr[itr_a]][j+m_narr[itr_b]]) <= empty){
                     
                            setmove(tempmove,i,j,(i+m_narr[itr_a]),(j+m_narr[itr_b]),0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,1)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                        itr_a++;
                        itr_b++;
                    }
                    continue;
                }
                else if(checkpiece == B || checkpiece == R || checkpiece == Q) {
                    if(checkpiece == B || checkpiece == Q){           //white bishop or queen .........................................................................
                 
                        for (int itr_a=i,itr_b=j;itr_a<8 && itr_b<8;itr_a++,itr_b++){
                            if (itr_b==j){
                                continue;
                            }
                            if (piece(board[itr_a][itr_b])==empty) {
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[itr_a][itr_b])<empty){
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                                break;
                            }
                        }
                        for (int itr_a=i,itr_b=j;itr_a>=0 && itr_b<8;itr_a--,itr_b++){
                            if (itr_b==j){
                                continue;
                            }
                            if (piece(board[itr_a][itr_b])==empty) {
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[itr_a][itr_b])<empty){
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                                break;
                            }
                        }
                        for (int itr_a=i,itr_b=j;itr_a>=0 && itr_b>=0;itr_a--,itr_b--){
                            if (itr_b==j){
                                continue;
                            }
                            if (piece(board[itr_a][itr_b])==empty) {
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[itr_a][itr_b])<empty){
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                                break;
                            }
                        }
                        for (int itr_a=i,itr_b=j;itr_a<8 && itr_b>=0;itr_a++,itr_b--){
                            if (itr_b==j){
                                continue;
                            }
                            if (piece(board[itr_a][itr_b])==empty) {
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[itr_a][itr_b])<empty){
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                                break;
                            }
                        }

                    }
                    if(checkpiece == R || checkpiece == Q){                     //white rook or queen  ..................................................
                  
                        for (int itr_a=i;itr_a<8;itr_a++){
                 
                            if (itr_a==i){
                    
                                continue;
                            }
                            if (piece(board[itr_a][j])==empty) {
                   
                                setmove(tempmove,i,j,itr_a,j,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[itr_a][j]) < empty){
                      
                                setmove(tempmove,i,j,itr_a,j,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                    
                                break;
                            }
                        }
                        for (int itr_a=i;itr_a>=0;itr_a--){
                            if (itr_a==i){
                 
                                continue;
                            }
                            if (piece(board[itr_a][j])==empty) {
                   

                                setmove(tempmove,i,j,itr_a,j,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[itr_a][j]) < empty){
                        

                                setmove(tempmove,i,j,itr_a,j,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                      

                                break;
                            }
                        }
                        for (int itr_b=j;itr_b<8;itr_b++){
                    

                            if (itr_b==j){
                 
                                continue;
                            }
                            if (piece(board[i][itr_b])==empty) {
                          
                                setmove(tempmove,i,j,i,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[i][itr_b]) < empty){
                         
                                setmove(tempmove,i,j,i,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                          
                                break;
                            }
                        
                        }
                        for (int itr_b=j;itr_b>=0;itr_b--){
                        

                            if (itr_b==j){
                                continue;
                            }
                            if (piece(board[i][itr_b])==empty) {
                                setmove(tempmove,i,j,i,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[i][itr_b]) < empty){
                                setmove(tempmove,i,j,i,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,1)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                                break;
                            }
                        }
                       
                    }
                    continue;

                }
                else{
                    std::cout<<"move generation error"<<std::endl;
                }



            }
        }
	}
	else{                                            //black.......................................................................................

	   


	    for (int i = 0; i < 8; i++) {
            if(index>255){
                break;
            }
            for (int j = 0; j < 8; j++) {
                if(index>255){
                    break;
                }

                if(piece(board[i][j])>=empty){
                    continue;
                }


                checkpiece = piece(board[i][j]);
                if(checkpiece==p){                         //black pawn .................................................................................
                    if(i==6 && piece(board[i-1][j])==empty && piece(board[i-2][j])==empty){    //double sq move
                        setmove(tempmove,i,j,(i-2),j,0,0,0,0,0);
                        if(!ischeckedaftermove(*this,tempmove,0)){
                            movelist[index] = tempmove;
                            sscore(movelist[index],diff(movelist[index]));
                            index++;
                        }
                        tempmove = 0;
                    }
                    if(i>1){                    //one step moves not including promotions
                        if(piece(board[i-1][j])==empty){
                            setmove(tempmove,i,j,(i-1),j,0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }

                        if(j<7 && (piece(board[i-1][j+1]) > empty || checkenpassant((i-1),(j+1))) ){                 //right side capture

                            
                            setmove(tempmove,i,j,(i-1),(j+1),0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                        if(j>0 && (piece(board[i-1][j-1]) > empty || checkenpassant((i-1),(j-1))) ){                 //left side capture

                           
                            setmove(tempmove,i,j,(i-1),(j-1),0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                    }

                    if(i==1  ){                    //for promotions
                        if(piece(board[i-1][j])==empty){
                            setmove(tempmove,i,j,(i-1),j,1,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i-1),j,0,1,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i-1),j,0,0,1,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i-1),j,0,0,0,1,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                        if(j<7 && (piece(board[i-1][j+1]) > empty) ){                                        //right side capture
                            setmove(tempmove,i,j,(i-1),(j+1),1,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i-1),(j+1),0,1,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i-1),(j+1),0,0,1,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i-1),(j+1),0,0,0,1,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                        if(j>0 && (piece(board[i-1][j-1]) > empty) ){                                        //left side capture
                            setmove(tempmove,i,j,(i-1),(j-1),1,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i-1),(j-1),0,1,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i-1),(j-1),0,0,1,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                            setmove(tempmove,i,j,(i-1),(j-1),0,0,0,1,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }

                    }
                    continue;
                }

                else if(checkpiece==k){                        //white king .........................................................................
                    itr_a=2;
                    itr_b=0;

                    while(1){
                        if(m_karr[itr_a]==-2){
                            break;
                        }
                        if((i+m_karr[itr_a])<0 || (j+m_karr[itr_b])<0 || (i+m_karr[itr_a])>=8 || (j+m_karr[itr_b])>=8){
                            itr_a++;
                            itr_b++;
                            continue;
                        }
                        if(piece(board[i+m_karr[itr_a]][j+m_karr[itr_b]]) >= empty){
                            setmove(tempmove,i,j,(i+m_karr[itr_a]),(j+m_karr[itr_b]),0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                        itr_a++;
                        itr_b++;
                    }
                    if(i==7 && j==4){
                        if(castle(board[7][0]) && castle(board[7][4]) && (piece(board[7][1])==empty && piece(board[7][2])==empty && piece(board[7][3])==empty)
                        && !(isattacked(7,2,0) || isattacked(7,3,0) || isattacked(7,4,0))){
                            setmove(tempmove,7,4,7,2,0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                        if(castle(board[7][7]) && castle(board[7][4]) && (piece(board[7][6])==empty && piece(board[7][5])==empty )
                        && !(isattacked(7,6,0) || isattacked(7,5,0) || isattacked(7,4,0))){
                            setmove(tempmove,7,4,7,6,0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                    }
                    continue;

                }

                else if(checkpiece == n ){                      //white knight .........................................................................
                    itr_a=0;
                    itr_b=2;

                    while(1){
                        if(m_narr[itr_b]== (-3)){


                            break;

                        }
                        if((i+m_narr[itr_a])<0 || (j+m_narr[itr_b])<0 || (i+m_narr[itr_a])>=8 || (j+m_narr[itr_b])>=8){
                            itr_a++;
                            itr_b++;
                            continue;

                        }
                        if(piece(board[i+m_narr[itr_a]][j+m_narr[itr_b]]) >= empty){
                            setmove(tempmove,i,j,(i+m_narr[itr_a]),(j+m_narr[itr_b]),0,0,0,0,0);
                            if(!ischeckedaftermove(*this,tempmove,0)){
                                movelist[index] = tempmove;
                                sscore(movelist[index],diff(movelist[index]));
                                index++;
                            }
                            tempmove = 0;
                        }
                        itr_a++;
                        itr_b++;
                    }
                    continue;
                }
                else if(checkpiece == b || checkpiece == r || checkpiece == q) {
                    if(checkpiece == b || checkpiece == q){           //white bishop or queen .........................................................................
                        for (int itr_a=i,itr_b=j;itr_a<8 && itr_b<8;itr_a++,itr_b++){
                            if (itr_b==j){
                                continue;
                            }
                            if (piece(board[itr_a][itr_b])==empty) {
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[itr_a][itr_b])>empty){
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                                break;
                            }
                        }
                        for (int itr_a=i,itr_b=j;itr_a>=0 && itr_b<8;itr_a--,itr_b++){
                            if (itr_b==j){
                                continue;
                            }
                            if (piece(board[itr_a][itr_b])==empty) {
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[itr_a][itr_b])>empty){
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                                break;
                            }
                        }
                        for (int itr_a=i,itr_b=j;itr_a>=0 && itr_b>=0;itr_a--,itr_b--){
                            if (itr_b==j){
                                continue;
                            }
                            if (piece(board[itr_a][itr_b])==empty) {
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[itr_a][itr_b])>empty){
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                                break;
                            }
                        }
                        for (int itr_a=i,itr_b=j;itr_a<8 && itr_b>=0;itr_a++,itr_b--){
                            if (itr_b==j){
                                continue;
                            }
                            if (piece(board[itr_a][itr_b])==empty) {
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[itr_a][itr_b])>empty){
                                setmove(tempmove,i,j,itr_a,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                                break;
                            }
                        }

                    }
                    if(checkpiece == r || checkpiece == q){                     //white rook or queen  ..................................................
                        for (int itr_a=i;itr_a<8;itr_a++){
                            if (itr_a==i){
                                continue;
                            }
                            if (piece(board[itr_a][j])==empty) {
                                setmove(tempmove,i,j,itr_a,j,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[itr_a][j]) > empty){
                                setmove(tempmove,i,j,itr_a,j,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                                break;
                            }
                        }
                        for (int itr_a=i;itr_a>=0;itr_a--){
                            if (itr_a==i){
                                continue;
                            }
                            if (piece(board[itr_a][j])==empty) {

                                setmove(tempmove,i,j,itr_a,j,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[itr_a][j]) > empty){

                                setmove(tempmove,i,j,itr_a,j,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{

                                break;
                            }
                        }
                        for (int itr_b=j;itr_b<8;itr_b++){

                            if (itr_b==j){
                                continue;
                            }
                            if (piece(board[i][itr_b])==empty) {
                                setmove(tempmove,i,j,i,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[i][itr_b]) > empty){
                                setmove(tempmove,i,j,i,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                                break;
                            }
                        }
                        for (int itr_b=j;itr_b>=0;itr_b--){

                            if (itr_b==j){
                                continue;
                            }
                            if (piece(board[i][itr_b])==empty) {
                                setmove(tempmove,i,j,i,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                continue;
                            }
                            else if (piece(board[i][itr_b]) > empty){
                                setmove(tempmove,i,j,i,itr_b,0,0,0,0,0);
                                if(!ischeckedaftermove(*this,tempmove,0)){
                                    movelist[index] = tempmove;
                                    sscore(movelist[index],diff(movelist[index]));
                                    index++;
                                }
                                tempmove = 0;
                                break;
                            }
                            else{
                                break;
                            }
                        }
                    }
                    continue;

                }
                else{
                    std::cout << "move generation error" << std::endl;
                }



            }
        }
	}
}
