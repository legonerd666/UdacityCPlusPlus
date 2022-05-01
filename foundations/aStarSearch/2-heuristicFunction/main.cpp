#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::fstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State { kEmpty, kObstacle };

string CellString(State state) {
  switch (state) {
  case State::kObstacle:
    return "⛰️  ";

  default:
    return "0 ";
  }
}

vector<State> ParseLine(string line) {
  vector<State> boardLine;
  istringstream boardStream(line);
  char c;
  int n;
  while (boardStream >> n >> c) {
    if (n == 1) {
      boardLine.push_back(State::kObstacle);
    } else {
      boardLine.push_back(State::kEmpty);
    }
  }
  return boardLine;
}

vector<vector<State>> ReadBoardFile(string filepath) {
  fstream board(filepath);
  string line;
  vector<vector<State>> newBoard;
  if (board) {
    while (getline(board, line)) {
      newBoard.push_back(ParseLine(line));
    }
  }
  return newBoard;
}

void PrintBoard(vector<vector<State>> board) {
  for (vector<State> v : board) {
    for (State s : v) {
      cout << CellString(s);
    }
    cout << "\n";
  }
}

vector<vector<State>> Search(vector<vector<State>> grid, int start[2],
                             int end[2]) {

  vector<vector<State>> newBoard = {};

  cout << "No path found!\n";
  return newBoard;
}

int main() {

  int start[2] = {0, 0};
  int end[2] = {4, 5};

  vector<vector<State>> solution =
      Search(ReadBoardFile("./1.board"), start, end);

  PrintBoard(solution);

  return 0;
}