/* CSCI 261: A6 - A-MAZE-ing
 *
 * Author: Kylie Quinney
 * Resources used : friend from a different class (not 261) for debugging help 
 *
 * Description: combine the two-dimensional lists, stacks, and queues to implement a Maze solver using Breadth-First Search and Depth-First Search
 * 
 */
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct Vertex {
    int x;
    int y;
};

/**
 * @brief implement BFS
 * 
 * @param maze 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
bool breadthSearch (char** maze, int x, int y);

/**
 * @brief implement DFS
 * 
 * @param x 
 * @param y 
 * @param maze 
 * @return true 
 * @return false 
 */
bool depthSearch(int x, int y, char** maze); 

int main(int argc, char** argv){

    ifstream input;
    string fileName;

    //check if file name was given in command line
    if(argc > 1){
        fileName = argv[1];
    }

    else {
    //recieve input from user and open file
    cout << "Enter the name of the file you wish to open: " << endl;
    cin >> fileName;
    }

    input.open(fileName);

    //check if file opened successfully
    if (input.is_open() == false){
        cerr << "Error opening the file" << endl;
        return -1;
    }
    else{
        cout << "Success, the file is open" << endl;
    }

    int row = 0;
    int col = 0;
    input >> row >> col;
    char **maze = new char*[row];

    //copy maze
    for (int i = 0; i < row; i++ ){
        maze[i] = new char[col];
        for (int j = 0; j < col; j++ ){
            input >> maze[i][j];
        }
    }
    
    input.close();
    
    //ask user to choose search method
    int choice;
    cout << "Please choose the search method you'd like to use: (enter an integer)" << endl;
    cout << "1) to search via BFS" << endl;
    cout << "2) to search via DFS" << endl;
    cin >> choice;

    // if choose BFS
    if (choice == 1){
        for (int i = 0; i < row; i++ ){
            for (int j = 0; j < col; j++ ){
                if (maze[i][j] == 'S'){
                    if (breadthSearch(maze, i, j)) {
                        cout << "The maze was solved!!!!!!" << endl;
                    } 
                    else {
                        cout << "dead end" << endl;
                    }
                }
            }
        }
    }
    // if choose DFS
    else if (choice == 2){
        for (int i = 0; i < row; i++ ){
            for (int j = 0; j < col; j++ ){
                if (maze[i][j] == 'S'){
                    if (depthSearch(i, j, maze)) {
                        cout << "The maze was solved!!!!!!" << endl;
                    } 
                    else {
                        cout << "dead end" << endl;
                    }
                }
            }
        }
    }
    //if user doesn't enter 1 or 2
    else{
        cout << "Invalid entry" << endl;
        return -1;
    }

    //print out maze
    for (int i = 0; i < row; i++ ){
            for (int j = 0; j < col; j++ ){
                cout << maze[i][j];
            }
            cout << endl;
        }
}

 bool breadthSearch (char** maze, int x, int y) {
    char& v = maze[x][y];
    queue<Vertex> queue;

    v = '@';
    queue.push({ x, y });
    Vertex vert;
    while (queue.size() > 0){
        vert = queue.front();
        queue.pop();
        if (maze[vert.x-1][vert.y] == '.'){
            maze[vert.x-1][vert.y] = '@';
            queue.push({ vert.x-1, vert.y });
        }
        if (maze[vert.x+1][vert.y] == '.'){
            maze[vert.x+1][vert.y] = '@';
            queue.push({ vert.x+1, vert.y });
        }
        if (maze[vert.x][vert.y+1] == '.'){
            maze[vert.x][vert.y+1] = '@';
            queue.push({ vert.x, vert.y+1 });
        }
        if (maze[vert.x][vert.y-1] == '.'){
            maze[vert.x][vert.y-1] = '@';
           queue.push({ vert.x, vert.y-1 });
        }

        if (maze[vert.x-1][vert.y] == 'E'){
            return true;
        }
        else if (maze[vert.x+1][vert.y] == 'E'){
            return true;
        }
        else if (maze[vert.x][vert.y+1] == 'E'){
            return true;
        }
        else if (maze[vert.x][vert.y-1] == 'E'){
            return true;
        }

    }
    return false;
}

bool depthSearch(int x, int y, char** maze) {
    bool solve = false;
    if (maze[x-1][y] == '.'){
        maze[x-1][y] = '@';
        solve |= depthSearch(x-1, y, maze);
    }
    if (maze[x+1][y] == '.'){
        maze[x+1][y] = '@';
        solve |= depthSearch(x+1, y, maze);
    }
    if (maze[x][y+1] == '.'){
        maze[x][y+1] = '@';
        solve |= depthSearch(x, y+1, maze);
    }
    if (maze[x][y-1] == '.'){
        maze[x][y-1] = '@';
        solve |= depthSearch(x, y-1, maze);
    }

    if (maze[x-1][y] == 'E'){
        solve = true;
        return true;
    }
    else if (maze[x+1][y] == 'E'){
        solve = true;
        return true;
    }
    else if (maze[x][y+1] == 'E'){
        solve = true;
        return true;
    }
    else if (maze[x][y-1] == 'E'){
        solve = true;
        return true;
    }

    return solve;

}

