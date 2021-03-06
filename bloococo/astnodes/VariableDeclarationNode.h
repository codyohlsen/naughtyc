#ifndef VARIABLE_DECL_NODE_H
#define VARIABLE_DECL_NODE_H

// include possible sub-nodes
#include "Types.h"
#include "Node.h"
#include "ParameterNode.h"
#include "StatementNode.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

class VariableDeclarationNode : public Node {
protected:
  string name;
  string type;
  bool isExtern;			

public:
	VariableDeclarationNode(string* t, string* n, bool ext);

	~VariableDeclarationNode();

	virtual void printNode(ofstream &out, map<string,string> &symbolTable, int numTabs, int &temp);
};

inline VariableDeclarationNode::VariableDeclarationNode(string* t, string* n, bool ext) {
	 this->type = *t;
	 this->name = *n;
	 this->isExtern = ext;

	 delete t;
	 delete n;
}

inline void VariableDeclarationNode::printNode(ofstream &out, map<string,string> &symbolTable, int numTabs, int &temp) {
	if (isExtern) {
		out << "extern ";
	}
	out << naughtToC[type] << " " << name << ";" << endl;

	// adds to the symbol table.
	symbolTable[name] = type;
}

inline VariableDeclarationNode::~VariableDeclarationNode() {
}

#endif //VARIABLE_DECL_NODE_H