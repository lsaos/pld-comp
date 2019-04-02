#pragma once

#include "irInstrRmen.hpp"

using namespace std;
using namespace ast;
using namespace ir;

IRInstrRmen::IRInstrRmen(BasicBlock* bb, string addr, string dest) : IRInstr(bb), addr(addr), dest(dest) { }

void IRInstrRmen::gen_asm(ostream &o) {} // TODO
