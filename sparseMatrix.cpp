/////////////////////////////////
// Name: Alejandro Pena Caicedo//
// UF id: 3712-3113            //
// Gator id: alejandropenacai  //
// Discussion Section: 1085    //
////////////////////////////////


#include "sparseMatrix.h"

template <typename T>
sparseMatrix<T>::sparseMatrix(){ //edit

  //head = new Node;
  head = 0;
 // myArray =  new Node*[row];

  
  //sizeOfList = 0;
}

template <typename T>
sparseMatrix<T>::~sparseMatrix(){ //edit, for loop for each array element(rows)

  delete myArray;
  /*while(head != NULL) {
    Node * n = head->next;
    delete head;
    head = n;
        }*/
}

template <typename T>
typename sparseMatrix<T>::Node* sparseMatrix<T>::traverse_list(int position){ //edit

  Node* conductor = head;

  for(int i = 0; i<position; i++){
    conductor = conductor->next;
  }
  
  return conductor;
}

template <typename T>
void sparseMatrix<T>::insert(const T& element, int position, int columnValue){ 

	if(position == 0){				//if appended at the end?
	Node * elnode = new Node;
  elnode->x = element;
  elnode->column= columnValue;
	elnode->next = 0; //what if list empty
  head = elnode; 
 // sizeOfList++;//delete this variable?
		
}

	else{
		Node * elnode = new Node;
    elnode->next = traverse_list(position);
    elnode->x = element;
    elnode->column = columnValue;
    traverse_list(position-1)->next = elnode;
   // sizeOfList++;
}
}

template <typename T>
vector<int> sparseMatrix<T>::input(){ 

  string inputString = "";//rename simpler
  getline(cin, inputString);

  vector<int> myvec;
  stringstream ss(inputString);
  string token;

  while(getline(ss, token, ' ')){

    int newtoken = stoi(token);
    myvec.push_back(newtoken);
  
  }

  return myvec;
 
}

template <typename T>
void sparseMatrix<T>::read(){//edit parameter?


  cout<< "Enter number of rows, columns" <<endl;
  vector<int> vector1 = input();//handles input information
 
  row = vector1[0];
  column = vector1[1];
  myArray.reserve(row);
  vector1.clear();

  for(int i = 0; i<myArray.size(); i++){
  myArray[i] = new Node;
  }
  
  
  for(int i = 0; i<row ; i++){
   
    int temp = 0;
    cout<< "Enter number of terms in row " << i+1 <<endl; 
    vector1 = input();//google how vectors copy to vectors
    temp = vector1[0];
    
    
    cout<<"Enter element's column, and value of each term in row "<< i+1 <<endl;
    vector1 = input();
    


    for(int i = 0; i<temp; i++){ // fills in column values
    //use insert function, node should hold value and column
      int tmpcolumn= vector1[0];
      int tmpvalue= vector1[1];
      
      insert(tmpvalue,i,tmpcolumn);
      
      myArray[i]= head;
      //Node* conductor = head;

      while(vector1.empty() != 1){
      
      vector1.erase(vector1.begin());
      vector1.erase(vector1.begin()); 
      myArray[i] = myArray[i]->next;

      int tmpcolumn= vector1[0];
      int tmpvalue= vector1[1];
      
      insert(tmpvalue,i,tmpcolumn);
      

      
      }


     cout<<"col " <<myArray[i]->column<<"   element value  " <<myArray[i]->x <<endl; 
    }
 
  }
  

}

template <typename T>
void sparseMatrix<T>::print(){ //what if row is empty?? if else statement?

  cout<<"rows: "<<row << " columns: " << column <<endl;
  
  for(int i = 0; i<myArray.size(); i++){
  
    head = myArray[i];
    Node* conductor = new Node;
    conductor = head;
    
    cout<< "row " << i+1 <<" ";

   while(conductor->next){ 
   // for (int i = 0; i<4; i++){
      cout<<" col: "<< conductor->column <<" val= " << conductor->x ; //commas in b/w columns
      conductor = conductor->next;
   // }
    } 
  }

}

void mask(Node* b, Node* c){
  
  for(int i = 0; i< b.size(); i++ ){
  
  Node * conductor = b[i];
  while(conductor->next){
  
   if(conductor->x != 0) {
      c[i]->x = this[i]->x;
      c[i] = c[i]->next;
      this[i] = this[i]->next;

    }
  conductor = conductor->next;
  }
  
  }
  
  
  

} 


int main(){

sparseMatrix<int>* obj = new sparseMatrix<int>();

	sparseMatrix<int>* a = new sparseMatrix<int>();
	sparseMatrix<bool>* b = new sparseMatrix<bool>();
	sparseMatrix<int>* c = new sparseMatrix<int>();
	
  cout << "Reading Matrix A" << endl;
	a->read();
  
  cout << “Matrix A:” << endl;
	a->print();

  cout << "Reading Matrix B" << endl;
	b->read();
  
  cout << “Matrix B, the boolean mask matrix:” << endl;
	b->print();


	a->mask(*b,*c);
cout << “Matrix C, result:” << endl;
	c->print();

return 0;
}

