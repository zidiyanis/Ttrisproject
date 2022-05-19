#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HEIGHT 10

typedef struct {
  int line;
  int column;
}coord_t

typedef struct{
  coord_t tab[4];
  int num;
  int height;
  int weight;
  int orientation;
}piece_t;

typedef struct {
  piece_t model[7];
  piece_t piece;
  int line;
  int column;
  int end;
  int grid[HEIGHT][HEIGHT];
  int score;
  int count_full_line;
}game_t;

//-------------INITILISATION-----------------------------------------------


void init_grid(game_t* game){
  for(int i=0;i<HEIGHT;i++){
    for(int j=0;j<HEIGHT;j++){
      game->grid[i][j]=0;
    }
  }
}


void create_pieces (game_t* game)
{
if(game->piece.num>=0&&game->piece.num<4){
  if(game->piece.num==0){
    game->piece.tab[1].line=game->piece.tab[0].line;
    game->piece.tab[1].column=game->piece.tab[0].column+1;
    game->piece.tab[2].line=game->piece.tab[0].line-1;
    game->piece.tab[2].column=game->piece.tab[0].column;
    game->piece.tab[3].line=game->piece.tab[0].line-1;
    game->piece.tab[3].column=game->piece.tab[0].column+1;  
  }
  else if(game->piece.num==1){
   if(game->piece.orientation==1){
     game->piece.tab[1].line=game->piece.tab[0].line-1;
     game->piece.tab[1].column=game->piece.tab[0].column;
     game->piece.tab[2].line=game->piece.tab[0].line-2;
     game->piece.tab[2].column=game->piece.tab[0].column;
     game->piece.tab[3].line=game->piece.tab[0].line-3;
     game->piece.tab[3].column=game->piece.tab[0].column;
   }
   else if(game->piece.orientation==2){
     game->piece.tab[1].line=game->piece.tab[0].line;
     game->piece.tab[1].column=game->piece.tab[0].column+1;
     game->piece.tab[2].line=game->piece.tab[0].line;
     game->piece.tab[2].column=game->piece.tab[0].column+2;
     game->piece.tab[3].line=game->piece.tab[0].line;
     game->piece.tab[3].column=game->piece.tab[0].column+3;
   }
  }    
  else if(game->piece.num==2){
    if(game->piece.orientation==1){
     game->piece.tab[1].line=game->piece.tab[0].line;
     game->piece.tab[1].column=game->piece.tab[0].column+1;
     game->piece.tab[2].line=game->piece.tab[0].line-1;
     game->piece.tab[2].column=game->piece.tab[0].column+1;
     game->piece.tab[3].line=game->piece.tab[0].line-1;
     game->piece.tab[3].column=game->piece.tab[0].column+2;
    }
    else if(game->piece.orientation==2){
     game->piece.tab[1].line=game->piece.tab[0].line-1;
     game->piece.tab[1].column=game->piece.tab[0].column;
     game->piece.tab[2].line=game->piece.tab[0].line-1;
     game->piece.tab[2].column=game->piece.tab[0].column-1;
     game->piece.tab[3].line=game->piece.tab[0].line-2;
     game->piece.tab[3].column=game->piece.tab[0].column-1;
    }
  }
  else if(game->piece.num==3){
    if(game->piece.orientation==1){
     game->piece.tab[1].line=game->piece.tab[0].line;
     game->piece.tab[1].column=game->piece.tab[0].column+1;
     game->piece.tab[2].line=game->piece.tab[0].line;
     game->piece.tab[2].column=game->piece.tab[0].column+2;
     game->piece.tab[3].line=game->piece.tab[0].line-1;
     game->piece.tab[3].column=game->piece.tab[0].column+1;
    }
    else if(game->piece.orientation==2){
     game->piece.tab[1].line=game->piece.tab[0].line-1;
     game->piece.tab[1].column=game->piece.tab[0].column;
     game->piece.tab[2].line=game->piece.tab[0].line-2;
     game->piece.tab[2].column=game->piece.tab[0].column;
     game->piece.tab[3].line=game->piece.tab[0].line-1;
     game->piece.tab[3].column=game->piece.tab[0].column+1;
    }
    else if(game->piece.orientation==3){
     game->piece.tab[1].line=game->piece.tab[0].line-1;
     game->piece.tab[1].column=game->piece.tab[0].column;
     game->piece.tab[2].line=game->piece.tab[0].line-1;
     game->piece.tab[2].column=game->piece.tab[0].column-1;
     game->piece.tab[3].line=game->piece.tab[0].line-1;
     game->piece.tab[3].column=game->piece.tab[0].column+1;
    }
    else if(game->piece.orientation==4){
      game->piece.tab[1].line=game->piece.tab[0].line-1;
      game->piece.tab[1].column=game->piece.tab[0].column;
      game->piece.tab[2].line=game->piece.tab[0].line-2;
      game->piece.tab[2].column=game->piece.tab[0].column;
      game->piece.tab[3].line=game->piece.tab[0].line-1;
      game->piece.tab[3].column=game->piece.tab[0].column-1;
    }
  }
  }
for(int i = 0; i<4; i++){
    game->model[i].num = i;
  }
}



int random_piece(){
return rand()%4;
}





//----------------DISPLAY-----------------------------------------

char cube(int column){
  switch(column)
    {
    case 0: return ' ';
      break;
    case 1: return 'o';
      break;
    }
}

void display_grid(game_t* game){
  printf(" ");
  for(int i=0;i<HEIGHT;i++){
    printf("%c ",48+i);
  }
  printf("\n");
  for(int i=0;i<HEIGHT;i++){
    for(int j=0;j<HEIGHT;j++){
      if(j<HEIGHT-1){
printf("|%c",cube(game->grid[i][j]));
      }
      else{
printf("|%c|",cube(game->grid[i][j]));
       }
    }
    printf("\n");
  }
}


void show_piece(game_t* game){
  printf("\n");
  if(game->piece.num==0){
    printf("  oo\n  oo\n");
  }
  else if(game->piece.num==1){
    printf("  1     2\n  o  o o o o\n  o\n  o\n  o\n");
  }
  else if(game->piece.num==2){
    printf("    1     2\n    o o   o\n  o o     o o\n            o\n");
  }
  else if(game->piece.num==3){
    printf("    1     2      3      4\n    o     o    o o o    o\n  o o o   o o    o    o o\n          o             o\n");
  }
  printf("\n");
}



//--------------UPDATE------------------------------------------------


void end(game_t* game){
  for(int i=0;i<4;i++){
    if(game->piece.tab[i].line<0){
      game->end=1;
    }
  }
}

int impossible(game_t* game){
  for(int i=0;i<4;i++){
    if(game->piece.tab[i].column<0||game->piece.tab[i].column>HEIGHT-1){
      printf("Imppossible de choisir cette colonne\n");
      return 1;
    }
  }
  return 0;
}

int no_orientation(game_t* game){
if(game->piece.num==1){
    if(game->piece.orientation==1||game->piece.orientation==2){
      return 1;
    }
    else{
      return 0;
    }
  }
else if(game->piece.num==2){
    if(game->piece.orientation==1||game->piece.orientation==2){
      return 1;
    }
    else{
      return 0;
    }
}
else if(game->piece.num==3){
if(game->piece.orientation>0&&game->piece.orientation<5){
      return 1;
}
    else{
return 0;
    }
  }
}

int read_box(int grid[HEIGHT][HEIGHT],int line,int column){
if(grid[line][column]==0){
return 0;
}
else{
return 1;
}
}


int weight_piece(game_t game){
  if(game.piece.num==0){
    return 2;
  }
  else if(game.piece.num==1){
    if(game.piece.orientation==1){
      return 1;
    }
    else if(game.piece.orientation==2){
      return 4;
    }
  }
  else if(game.piece.num==2){
    if(game.piece.orientation==1){
      return 3;
    }
    else if(game.piece.orientation==2){
      return 2;
    }
  }
  else if(game.piece.num==3){
    if(game.piece.orientation%2==1){
      return 3;
    }
    else if(game.piece.orientation%2==0){
      return 2;
    }
  }
}


int height_piece(game_t game){
  if(game.piece.num==0){
    return 2;
  }
  else if(game.piece.num==1){
    if(game.piece.orientation==1){
      return 4;
    }
    else if(game.piece.orientation==2){
      return 1;
    }
  }
  else if(game.piece.num==2){
    if(game.piece.orientation==1){
      return 2;
    }
    else if(game.piece.orientation==2){
      return 3;
    }
  }
  else if(game.piece.num==3){
    if(game.piece.orientation%2==1){
      return 2;
    }
    else if(game.piece.orientation%2==0){
      return 3;
    }
  }
}

 
int verification(game_t* game){
  int c=0;
  for(int i=0;i<4;i++){
    while(game->grid[game->piece.tab[i].line][game->piece.tab[i].column]==0 && game->piece.tab[0].line<HEIGHT-1 && c<i+1){
      c++;
      if(c==4){
  return 1;
      }
    }
    if(game->grid[game->piece.tab[i].line][game->piece.tab[i].column]==1){
      game->piece.tab[0].line--;
      create_pieces(game);
      return 0;
    }
  }
}
     
 


void put1(game_t* game){
  for(int i=0;i<4;i++){
    game->grid[game->piece.tab[i].line][game->piece.tab[i].column]=1;
    }
}



void line_max(game_t* game){
  game->piece.tab[0].line=height_piece(*game)-1;
  create_pieces(game);
  while(verification(game)!=0){
    game->piece.tab[0].line++;
    create_pieces(game);
  }
}




void placement(game_t* game){
  game->piece.num=random_piece();
  show_piece(game);
  printf("Your score is %d\n\n",game->score);
  if(game->piece.num!=0){
    do{
      printf("Choose the orientation of the piece:\n\n");
      scanf("%d",&game->piece.orientation);
    }while(no_orientation(game)==0);
  }
  do{
    printf("Choisir la colonne :\n");
    scanf("%d", &(game->piece.tab[0].column) );
    line_max(game);
    create_pieces(game);
  }while(impossible(game));
  put1(game);
}


int line_full(game_t* game,int grid[HEIGHT][HEIGHT],int line){
if(line>=0&&line<HEIGHT){
for(int i=0;i<HEIGHT;i++){
if(grid[line][i]==0){
return 0;
}
}
}
return 1;
}


int full(game_t* game){
for(int i=0;i<HEIGHT;i++){
if(line_full(game,game->grid,i)==1){
return i;
}
}
return 0;
}





void remove_line(game_t* game){
while((full(game)!=0)){
game->score=game->score+10;
for(int i=full(game)-1;i>0;i--){
for(int j=0;j<HEIGHT;j++){
game->grid[i+1][j]=game->grid[i][j];
game->grid[0][j]=0;
}
}
}
}



 
//---------------------MAIN FUNCTION--------------------------------------  
 
void initialisation(game_t* game){
  init_grid(game);
  game->end = 0;
  game->score=0;
}


void display(game_t* game){
  display_grid(game);
}


void update(game_t* game){
  placement(game);
  remove_line(game);
  end(game);
}
 



int main(){
float timer;
clock_t t_start, t_end;
t_start=clock();
  srand(time(NULL));
  game_t game;
  initialisation(&game);
  while(game.end==0){
    display(&game);
    update(&game);
  }
  t_end=clock();
  timer=(float)t_end-t_start;
  printf("Your time is %.2f\n",timer/1000);
}