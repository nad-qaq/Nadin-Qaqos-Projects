#include <iostream>
using namespace std;
class AbstractNode {
	public:
		virtual double eval() = 0;
		AbstractNode() {};
		virtual ~AbstractNode() {};
};
class LeafNode : public AbstractNode {
	private:
		double value;
	public:
		LeafNode(double d) : value(d) {};
		~LeafNode() {};
		double eval() {return value;};
};
class UnaryMinusNode : public AbstractNode {
	private:
		AbstractNode * child;
	public:
		UnaryMinusNode(AbstractNode * c) : child(c) {};
		~UnaryMinusNode() {delete child;};
		virtual double eval() {return ((-1.0)*child->eval());};
};
class BinaryNode : public AbstractNode {
	private:
		AbstractNode * left;
		AbstractNode * right;
		char op;
	public:
		BinaryNode(AbstractNode * l,AbstractNode * r,char o) : left(l), right(r), op(o) {};
		~BinaryNode() {delete left; delete right;};
		virtual double eval() {
			switch(op) {
				case '+':
					return left->eval()+right->eval();
				case '-':
					return left->eval()-right->eval();
				case '*':
					return left->eval()*right->eval();
				case '/':
					return left->eval()/right->eval();
				default:
					return 0;
			};
		};
};
// int main() {
// 	AbstractNode * expr =
// 		new BinaryNode(
// 				new LeafNode(10),
// 				new UnaryMinusNode(
// 					new LeafNode(5)
// 					),
// 				'+'
// 			      );
// 	cout << expr->eval() << endl;
// 	delete expr;
// 	return 0;
// };


