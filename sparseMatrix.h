/////////////////////////////////
// Name: Alejandro Pena Caicedo//
// UF id: 3712-3113            //
// Gator id: alejandropenacai  //
// Discussion Section: 1085    //
////////////////////////////////

#ifndef _SPARSEMATRIX_H_
#define _SPARSEMATRIX_H_

#include <iostream>
#include <string> 
#include <stdexcept>
#include <sstream>
#include <vector>

using namespace std;

template <typename T>
class sparseMatrix {

  private:  

  struct Node{
		T x;
    int column;
		Node *next;
  };

  void insert(const T& element, int position, int columnValue);//helper function


  Node* head; //= new Node;

  vector<Node*> myArray ;//= new vector<Node*>;

  Node* traverse_list(int position);
  int row;//holds row value from read for print funct
  int column;//same as row, but for column values


  public:

  sparseMatrix();
  ~sparseMatrix();


  vector<int> input(); //helper function

  void read();
  void print();
  void mask(Node* a, Node* b); //possibly change




};

#endif

