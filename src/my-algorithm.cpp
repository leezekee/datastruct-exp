//
// Created by lizhi on 2022/11/24.
//

#include "my-algorithm.h"
std::vector<int>node_dfs;
std::vector<int>node_bfs;
//std::vector<int>node_bfs1;

void _dfs(GraphNode **_vexes, int v0, int *_visited){
    node_dfs.push_back(_vexes[v0][v0].adjInfo);
      _visited[v0]=1;

      for(int i=0;i<_vexes[0][0].nodeNumber;i++){
          for(int j=0;j<_vexes[0][0].nodeNumber;j++){
              if(_vexes[i][j].adjInfo!=0&&!_visited[j]){
                     _dfs(_vexes,j,_visited);
              }
          }
      }
}

void dfs(GraphNode **_vexes){
         int _visited[_vexes[0][0].nodeNumber];
    memset(_visited,0,sizeof(_visited));
    for(int i=0;i<_vexes[0][0].nodeNumber;i++){
        if(!_visited[i]==0){
            _dfs(_vexes,i,_visited);
        }
    }
}

int findAdjVex(GraphNode **_vexes, int v0, int *visited){
    for(int j=0;j<_vexes[0][0].nodeNumber;j++){
        if(_vexes[v0][j].adjInfo!=0&&visited[j]==0){
            return j;

        }

    }
    return -1;
}

void _bfs(GraphNode **_vexes, int v0, int *visited){


      std::  queue<int>p;
        p.push(v0);
        while(!p.empty()){
            int q=p.front();
            p.pop();
            visited[q]=1;
           node_bfs.push_back(_vexes[q][0].adjInfo);//这不知道对不对

            int m=findAdjVex(_vexes,q,visited);
            while(m!=-1){
                p.push(m);
                visited[m]=1;
                m=findAdjVex(_vexes,q,visited);
            }
        }

}

void bfs(GraphNode **_vexes){

    int visited[_vexes[0][0].nodeNumber];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<_vexes[0][0].nodeNumber;i++){
        if(!visited[i]){
            _bfs(_vexes,i,visited);
        }
    }

}
