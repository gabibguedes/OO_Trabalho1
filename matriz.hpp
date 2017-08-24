#ifndef MATRIZ_HPP
#define MATRIZ_HPP

using namespace std;

class Matriz {
	private:
		char elemento[20][20];
	public:
		Matriz();
		~Matriz();
		char getElemento();
		void setElemento();
};

#endif

#ifndef LINHA_HPP
#define LINHA_HPP

using namespace std;

class Linha:public Matriz{
	public:
		Linha();
		~Linha();   
};

#endif

