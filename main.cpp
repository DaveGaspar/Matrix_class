#include <iostream>

class matrix{
	private:
		int row, column;
		int** arr_2d;
	public:
		matrix(){
			row = 3;
			column = 3;
			arr_2d = new int*[row];
			for(int i = 0; i < row; i++)
				arr_2d[i] = new int[column];
		}
		matrix(int const n, int const m){
			if (n < 1 || m < 1)
				throw std::invalid_argument("Rows and columns must be over 1.");
			row = n;
			column = m;
			arr_2d = new int*[row];
			for(int i = 0; i < row; i++)
				arr_2d[i] = new int[column];
		}
		~matrix(){
			for(int i = 0; i < row; i++){
				delete[] arr_2d[i];
				arr_2d[i] = nullptr;
			}
			delete[] arr_2d;
		}
		void init(){
			for(int i = 0; i < row; i++)
				for(int j = 0; j < column; j++)
					arr_2d[i][j] = rand() % 90 + 10;
		}
		void print(){
			for(int i = 0; i < row; i++){
				for(int j = 0; j < column; j++)
					std::cout << arr_2d[i][j] << "\t";
				std::cout << std::endl;
			}
		}
};

int main(){
	matrix* obj1 = new matrix;
	obj1->init();
	obj1->print();
	
	int n, m;

	std::cout << "Row = ";
	std::cin >> n;
	
	std::cout << "Column = ";
	std::cin >> m;
	
	matrix* obj2 = new matrix(n,m);
	obj2->init();
	obj2->print();

	delete obj1;
	obj1 = nullptr;

	delete obj2;
	obj2 = nullptr;

	return 0;
}
