void init_grid(game_t* game){
  for(int i=0;i<HEIGHT;i++){
    for(int j=0;j<HEIGHT;j++){
      game->grid[i][j]=0;
    }
  }
}
