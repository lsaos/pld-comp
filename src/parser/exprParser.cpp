
// Generated from /home/lohl/Documents/COMP/src/parser/expr.g4 by ANTLR 4.7.1


#include "exprVisitor.h"

#include "exprParser.h"


using namespace antlrcpp;
using namespace antlr4;

exprParser::exprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

exprParser::~exprParser() {
  delete _interpreter;
}

std::string exprParser::getGrammarFileName() const {
  return "expr.g4";
}

const std::vector<std::string>& exprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& exprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

exprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::PreprocContext* exprParser::ProgContext::preproc() {
  return getRuleContext<exprParser::PreprocContext>(0);
}

exprParser::MainContext* exprParser::ProgContext::main() {
  return getRuleContext<exprParser::MainContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::ProgContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::ProgContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}


size_t exprParser::ProgContext::getRuleIndex() const {
  return exprParser::RuleProg;
}

antlrcpp::Any exprParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

exprParser::ProgContext* exprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, exprParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    preproc();
    setState(30);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(27);
      match(exprParser::SPACE);
      setState(32);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(33);
    main();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreprocContext ------------------------------------------------------------------

exprParser::PreprocContext::PreprocContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<exprParser::IncludeContext *> exprParser::PreprocContext::include() {
  return getRuleContexts<exprParser::IncludeContext>();
}

exprParser::IncludeContext* exprParser::PreprocContext::include(size_t i) {
  return getRuleContext<exprParser::IncludeContext>(i);
}

std::vector<tree::TerminalNode *> exprParser::PreprocContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::PreprocContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}


size_t exprParser::PreprocContext::getRuleIndex() const {
  return exprParser::RulePreproc;
}

antlrcpp::Any exprParser::PreprocContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitPreproc(this);
  else
    return visitor->visitChildren(this);
}

exprParser::PreprocContext* exprParser::preproc() {
  PreprocContext *_localctx = _tracker.createInstance<PreprocContext>(_ctx, getState());
  enterRule(_localctx, 2, exprParser::RulePreproc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(44);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(38);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(35);
          match(exprParser::SPACE);
          setState(40);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(41);
        include(); 
      }
      setState(46);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

exprParser::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* exprParser::IncludeContext::LIB() {
  return getToken(exprParser::LIB, 0);
}

std::vector<tree::TerminalNode *> exprParser::IncludeContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::IncludeContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}


size_t exprParser::IncludeContext::getRuleIndex() const {
  return exprParser::RuleInclude;
}

antlrcpp::Any exprParser::IncludeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInclude(this);
  else
    return visitor->visitChildren(this);
}

exprParser::IncludeContext* exprParser::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 4, exprParser::RuleInclude);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    match(exprParser::T__0);
    setState(51);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(48);
      match(exprParser::SPACE);
      setState(53);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(54);
    match(exprParser::T__1);
    setState(55);
    match(exprParser::LIB);
    setState(56);
    match(exprParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainContext ------------------------------------------------------------------

exprParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::FuncTypeContext* exprParser::MainContext::funcType() {
  return getRuleContext<exprParser::FuncTypeContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::MainContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::MainContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

std::vector<exprParser::DeclarationContext *> exprParser::MainContext::declaration() {
  return getRuleContexts<exprParser::DeclarationContext>();
}

exprParser::DeclarationContext* exprParser::MainContext::declaration(size_t i) {
  return getRuleContext<exprParser::DeclarationContext>(i);
}

std::vector<exprParser::InstructionContext *> exprParser::MainContext::instruction() {
  return getRuleContexts<exprParser::InstructionContext>();
}

exprParser::InstructionContext* exprParser::MainContext::instruction(size_t i) {
  return getRuleContext<exprParser::InstructionContext>(i);
}

exprParser::RetContext* exprParser::MainContext::ret() {
  return getRuleContext<exprParser::RetContext>(0);
}


size_t exprParser::MainContext::getRuleIndex() const {
  return exprParser::RuleMain;
}

antlrcpp::Any exprParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

exprParser::MainContext* exprParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 6, exprParser::RuleMain);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(58);
    funcType();
    setState(60); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(59);
      match(exprParser::SPACE);
      setState(62); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == exprParser::SPACE);
    setState(64);
    match(exprParser::T__3);
    setState(68);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(65);
      match(exprParser::SPACE);
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(71);
    match(exprParser::T__4);
    setState(75);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(72);
      match(exprParser::SPACE);
      setState(77);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(78);
    match(exprParser::T__5);
    setState(82);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(79);
      match(exprParser::SPACE);
      setState(84);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(85);
    match(exprParser::T__6);
    setState(89);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(86);
        match(exprParser::SPACE); 
      }
      setState(91);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
    setState(101);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::T__14

    || _la == exprParser::T__16) {
      setState(92);
      declaration();
      setState(96);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(93);
          match(exprParser::SPACE); 
        }
        setState(98);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(113);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::VAR) {
      setState(104);
      instruction();
      setState(108);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(105);
          match(exprParser::SPACE); 
        }
        setState(110);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      }
      setState(115);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(117);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == exprParser::T__8) {
      setState(116);
      ret();
    }
    setState(122);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(119);
      match(exprParser::SPACE);
      setState(124);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(125);
    match(exprParser::T__7);
    setState(129);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(126);
      match(exprParser::SPACE);
      setState(131);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetContext ------------------------------------------------------------------

exprParser::RetContext::RetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::RetContext::getRuleIndex() const {
  return exprParser::RuleRet;
}

void exprParser::RetContext::copyFrom(RetContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RetExprContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::RetExprContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::RetExprContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::RetExprContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::RetExprContext::RetExprContext(RetContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::RetExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitRetExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RetNoExprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> exprParser::RetNoExprContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::RetNoExprContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::RetNoExprContext::RetNoExprContext(RetContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::RetNoExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitRetNoExpr(this);
  else
    return visitor->visitChildren(this);
}
exprParser::RetContext* exprParser::ret() {
  RetContext *_localctx = _tracker.createInstance<RetContext>(_ctx, getState());
  enterRule(_localctx, 8, exprParser::RuleRet);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(155);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<RetContext *>(_tracker.createInstance<exprParser::RetExprContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(132);
      match(exprParser::T__8);
      setState(134); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(133);
        match(exprParser::SPACE);
        setState(136); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == exprParser::SPACE);
      setState(138);
      expression(0);
      setState(142);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(139);
        match(exprParser::SPACE);
        setState(144);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(145);
      match(exprParser::T__9);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<RetContext *>(_tracker.createInstance<exprParser::RetNoExprContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(147);
      match(exprParser::T__8);
      setState(151);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(148);
        match(exprParser::SPACE);
        setState(153);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(154);
      match(exprParser::T__9);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

exprParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<exprParser::InstructionContext *> exprParser::BlockContext::instruction() {
  return getRuleContexts<exprParser::InstructionContext>();
}

exprParser::InstructionContext* exprParser::BlockContext::instruction(size_t i) {
  return getRuleContext<exprParser::InstructionContext>(i);
}

std::vector<tree::TerminalNode *> exprParser::BlockContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::BlockContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}


size_t exprParser::BlockContext::getRuleIndex() const {
  return exprParser::RuleBlock;
}

antlrcpp::Any exprParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

exprParser::BlockContext* exprParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 10, exprParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(157);
      instruction();
      setState(161);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(158);
        match(exprParser::SPACE);
        setState(163);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(166); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == exprParser::VAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionContext ------------------------------------------------------------------

exprParser::InstructionContext::InstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::AssignmentContext* exprParser::InstructionContext::assignment() {
  return getRuleContext<exprParser::AssignmentContext>(0);
}


size_t exprParser::InstructionContext::getRuleIndex() const {
  return exprParser::RuleInstruction;
}

antlrcpp::Any exprParser::InstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInstruction(this);
  else
    return visitor->visitChildren(this);
}

exprParser::InstructionContext* exprParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 12, exprParser::RuleInstruction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    assignment();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

exprParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::VarTypeContext* exprParser::DeclarationContext::varType() {
  return getRuleContext<exprParser::VarTypeContext>(0);
}

std::vector<exprParser::NewVarContext *> exprParser::DeclarationContext::newVar() {
  return getRuleContexts<exprParser::NewVarContext>();
}

exprParser::NewVarContext* exprParser::DeclarationContext::newVar(size_t i) {
  return getRuleContext<exprParser::NewVarContext>(i);
}

std::vector<tree::TerminalNode *> exprParser::DeclarationContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::DeclarationContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}


size_t exprParser::DeclarationContext::getRuleIndex() const {
  return exprParser::RuleDeclaration;
}

antlrcpp::Any exprParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

exprParser::DeclarationContext* exprParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 14, exprParser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    varType();
    setState(174);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(171);
      match(exprParser::SPACE);
      setState(176);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(177);
    newVar();
    setState(181);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(178);
      match(exprParser::SPACE);
      setState(183);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(200);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::T__10) {
      setState(184);
      match(exprParser::T__10);
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(185);
        match(exprParser::SPACE);
        setState(190);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(191);
      newVar();
      setState(195);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(192);
        match(exprParser::SPACE);
        setState(197);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(202);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(203);
    match(exprParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewVarContext ------------------------------------------------------------------

exprParser::NewVarContext::NewVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::NewVarContext::getRuleIndex() const {
  return exprParser::RuleNewVar;
}

void exprParser::NewVarContext::copyFrom(NewVarContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ValuedNewVariableContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::ValuedNewVariableContext::VAR() {
  return getToken(exprParser::VAR, 0);
}

exprParser::ExpressionContext* exprParser::ValuedNewVariableContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::ValuedNewVariableContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::ValuedNewVariableContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::ValuedNewVariableContext::ValuedNewVariableContext(NewVarContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ValuedNewVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitValuedNewVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlainNewVariableContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::PlainNewVariableContext::VAR() {
  return getToken(exprParser::VAR, 0);
}

exprParser::PlainNewVariableContext::PlainNewVariableContext(NewVarContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::PlainNewVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitPlainNewVariable(this);
  else
    return visitor->visitChildren(this);
}
exprParser::NewVarContext* exprParser::newVar() {
  NewVarContext *_localctx = _tracker.createInstance<NewVarContext>(_ctx, getState());
  enterRule(_localctx, 16, exprParser::RuleNewVar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(221);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<NewVarContext *>(_tracker.createInstance<exprParser::PlainNewVariableContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(205);
      match(exprParser::VAR);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<NewVarContext *>(_tracker.createInstance<exprParser::ValuedNewVariableContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(206);
      match(exprParser::VAR);
      setState(210);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(207);
        match(exprParser::SPACE);
        setState(212);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(213);
      match(exprParser::T__11);
      setState(217);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(214);
        match(exprParser::SPACE);
        setState(219);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(220);
      expression(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

exprParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* exprParser::AssignmentContext::VAR() {
  return getToken(exprParser::VAR, 0);
}

exprParser::ExpressionContext* exprParser::AssignmentContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::AssignmentContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::AssignmentContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}


size_t exprParser::AssignmentContext::getRuleIndex() const {
  return exprParser::RuleAssignment;
}

antlrcpp::Any exprParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

exprParser::AssignmentContext* exprParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 18, exprParser::RuleAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    match(exprParser::VAR);
    setState(227);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(224);
      match(exprParser::SPACE);
      setState(229);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(230);
    match(exprParser::T__11);
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(231);
      match(exprParser::SPACE);
      setState(236);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(237);
    expression(0);
    setState(238);
    match(exprParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

exprParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::ExpressionContext::getRuleIndex() const {
  return exprParser::RuleExpression;
}

void exprParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AddContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::AddContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::AddContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> exprParser::AddContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::AddContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::AddContext::AddContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::AddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitAdd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::SubContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::SubContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> exprParser::SubContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::SubContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::SubContext::SubContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::SubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::MultContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::MultContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

tree::TerminalNode* exprParser::MultContext::OPMUL() {
  return getToken(exprParser::OPMUL, 0);
}

std::vector<tree::TerminalNode *> exprParser::MultContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::MultContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::MultContext::MultContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::MultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitMult(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::BinContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::BinContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

tree::TerminalNode* exprParser::BinContext::OPBIN() {
  return getToken(exprParser::OPBIN, 0);
}

std::vector<tree::TerminalNode *> exprParser::BinContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::BinContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::BinContext::BinContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::BinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitBin(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::VariableContext::VAR() {
  return getToken(exprParser::VAR, 0);
}

exprParser::VariableContext::VariableContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::CharContext::CHAR() {
  return getToken(exprParser::CHAR, 0);
}

exprParser::CharContext::CharContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::CharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitChar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegativeUnaryContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::NegativeUnaryContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::NegativeUnaryContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::NegativeUnaryContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::NegativeUnaryContext::NegativeUnaryContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::NegativeUnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitNegativeUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::UnaryContext::UNARYOP() {
  return getToken(exprParser::UNARYOP, 0);
}

exprParser::ExpressionContext* exprParser::UnaryContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::UnaryContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::UnaryContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::UnaryContext::UnaryContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::ParenthesisContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::ParenthesisContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::ParenthesisContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::ParenthesisContext::ParenthesisContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::IntContext::INT() {
  return getToken(exprParser::INT, 0);
}

exprParser::IntContext::IntContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}

exprParser::ExpressionContext* exprParser::expression() {
   return expression(0);
}

exprParser::ExpressionContext* exprParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  exprParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  exprParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, exprParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(276);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::VAR: {
        _localctx = _tracker.createInstance<VariableContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(241);
        match(exprParser::VAR);
        break;
      }

      case exprParser::INT: {
        _localctx = _tracker.createInstance<IntContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(242);
        match(exprParser::INT);
        break;
      }

      case exprParser::CHAR: {
        _localctx = _tracker.createInstance<CharContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(243);
        match(exprParser::CHAR);
        break;
      }

      case exprParser::T__4: {
        _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(244);
        match(exprParser::T__4);
        setState(248);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(245);
          match(exprParser::SPACE);
          setState(250);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(251);
        expression(0);
        setState(255);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(252);
          match(exprParser::SPACE);
          setState(257);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(258);
        match(exprParser::T__5);
        break;
      }

      case exprParser::T__13: {
        _localctx = _tracker.createInstance<NegativeUnaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(260);
        match(exprParser::T__13);
        setState(264);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(261);
          match(exprParser::SPACE);
          setState(266);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(267);
        expression(2);
        break;
      }

      case exprParser::UNARYOP: {
        _localctx = _tracker.createInstance<UnaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(268);
        match(exprParser::UNARYOP);
        setState(272);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(269);
          match(exprParser::SPACE);
          setState(274);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(275);
        expression(1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(340);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(338);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(278);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(282);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(279);
            match(exprParser::SPACE);
            setState(284);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(285);
          match(exprParser::OPMUL);
          setState(289);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(286);
            match(exprParser::SPACE);
            setState(291);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(292);
          expression(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(293);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(297);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(294);
            match(exprParser::SPACE);
            setState(299);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(300);
          match(exprParser::T__12);
          setState(304);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(301);
            match(exprParser::SPACE);
            setState(306);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(307);
          expression(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<SubContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(308);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(312);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(309);
            match(exprParser::SPACE);
            setState(314);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(315);
          match(exprParser::T__13);
          setState(319);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(316);
            match(exprParser::SPACE);
            setState(321);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(322);
          expression(5);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(323);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(327);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(324);
            match(exprParser::SPACE);
            setState(329);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(330);
          match(exprParser::OPBIN);
          setState(334);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(331);
            match(exprParser::SPACE);
            setState(336);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(337);
          expression(4);
          break;
        }

        } 
      }
      setState(342);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

exprParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::FuncTypeContext::getRuleIndex() const {
  return exprParser::RuleFuncType;
}

antlrcpp::Any exprParser::FuncTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitFuncType(this);
  else
    return visitor->visitChildren(this);
}

exprParser::FuncTypeContext* exprParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 22, exprParser::RuleFuncType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(343);
    _la = _input->LA(1);
    if (!(_la == exprParser::T__14

    || _la == exprParser::T__15)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarTypeContext ------------------------------------------------------------------

exprParser::VarTypeContext::VarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::VarTypeContext::getRuleIndex() const {
  return exprParser::RuleVarType;
}

antlrcpp::Any exprParser::VarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitVarType(this);
  else
    return visitor->visitChildren(this);
}

exprParser::VarTypeContext* exprParser::varType() {
  VarTypeContext *_localctx = _tracker.createInstance<VarTypeContext>(_ctx, getState());
  enterRule(_localctx, 24, exprParser::RuleVarType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(345);
    _la = _input->LA(1);
    if (!(_la == exprParser::T__14

    || _la == exprParser::T__16)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool exprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 10: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool exprParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> exprParser::_decisionToDFA;
atn::PredictionContextCache exprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN exprParser::_atn;
std::vector<uint16_t> exprParser::_serializedATN;

std::vector<std::string> exprParser::_ruleNames = {
  "prog", "preproc", "include", "main", "ret", "block", "instruction", "declaration", 
  "newVar", "assignment", "expression", "funcType", "varType"
};

std::vector<std::string> exprParser::_literalNames = {
  "", "'#include'", "'<'", "'>'", "'main'", "'('", "')'", "'{'", "'}'", 
  "'return'", "';'", "','", "'='", "'+'", "'-'", "'int'", "'void'", "'char'"
};

std::vector<std::string> exprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "SPACE", "OPMUL", "UNARYOP", "OPBIN", "INT", "LIB", "CHAR", "VAR"
};

dfa::Vocabulary exprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> exprParser::_tokenNames;

exprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1b, 0x15e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x1f, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x22, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0x27, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x2a, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 0x2d, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x30, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x34, 0xa, 
    0x4, 0xc, 0x4, 0xe, 0x4, 0x37, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x6, 0x5, 0x3f, 0xa, 0x5, 0xd, 0x5, 0xe, 
    0x5, 0x40, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x45, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0x48, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x4c, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x4f, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x53, 0xa, 
    0x5, 0xc, 0x5, 0xe, 0x5, 0x56, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 
    0x5a, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x5d, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x7, 0x5, 0x61, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x64, 0xb, 0x5, 0x7, 0x5, 
    0x66, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x69, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x7, 0x5, 0x6d, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x70, 0xb, 0x5, 0x7, 0x5, 
    0x72, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x75, 0xb, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x78, 0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 0x7b, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x7e, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x82, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0x85, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x89, 0xa, 0x6, 
    0xd, 0x6, 0xe, 0x6, 0x8a, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x8f, 0xa, 0x6, 
    0xc, 0x6, 0xe, 0x6, 0x92, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x7, 0x6, 0x98, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x9b, 0xb, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0x9e, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0xa2, 0xa, 
    0x7, 0xc, 0x7, 0xe, 0x7, 0xa5, 0xb, 0x7, 0x6, 0x7, 0xa7, 0xa, 0x7, 0xd, 
    0x7, 0xe, 0x7, 0xa8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 
    0xaf, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xb2, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x7, 0x9, 0xb6, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xb9, 0xb, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x7, 0x9, 0xbd, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xc0, 0xb, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xc4, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xc7, 
    0xb, 0x9, 0x7, 0x9, 0xc9, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xcc, 0xb, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xd3, 0xa, 
    0xa, 0xc, 0xa, 0xe, 0xa, 0xd6, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0xda, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xdd, 0xb, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0xe0, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xe4, 0xa, 0xb, 0xc, 0xb, 
    0xe, 0xb, 0xe7, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xeb, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0xee, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xf9, 
    0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xfc, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 
    0xc, 0x100, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x103, 0xb, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x109, 0xa, 0xc, 0xc, 0xc, 0xe, 
    0xc, 0x10c, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x111, 
    0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x114, 0xb, 0xc, 0x3, 0xc, 0x5, 0xc, 0x117, 
    0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x11b, 0xa, 0xc, 0xc, 0xc, 0xe, 
    0xc, 0x11e, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x122, 0xa, 0xc, 
    0xc, 0xc, 0xe, 0xc, 0x125, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 
    0xc, 0x12a, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x12d, 0xb, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x7, 0xc, 0x131, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x134, 0xb, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x139, 0xa, 0xc, 0xc, 0xc, 
    0xe, 0xc, 0x13c, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x140, 0xa, 
    0xc, 0xc, 0xc, 0xe, 0xc, 0x143, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x7, 0xc, 0x148, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x14b, 0xb, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x7, 0xc, 0x14f, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x152, 
    0xb, 0xc, 0x3, 0xc, 0x7, 0xc, 0x155, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x158, 
    0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x2, 0x3, 
    0x16, 0xf, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x2, 0x4, 0x3, 0x2, 0x11, 0x12, 0x4, 0x2, 0x11, 0x11, 0x13, 
    0x13, 0x2, 0x185, 0x2, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x31, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3c, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xc, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xe, 0xaa, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xac, 0x3, 0x2, 0x2, 0x2, 0x12, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xe1, 0x3, 0x2, 0x2, 0x2, 0x16, 0x116, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x159, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x15b, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x20, 0x5, 0x4, 0x3, 0x2, 0x1d, 0x1f, 0x7, 0x14, 0x2, 0x2, 
    0x1e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x22, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x20, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x5, 
    0x8, 0x5, 0x2, 0x24, 0x3, 0x3, 0x2, 0x2, 0x2, 0x25, 0x27, 0x7, 0x14, 
    0x2, 0x2, 0x26, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x2a, 0x3, 0x2, 0x2, 
    0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x29, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x2d, 0x5, 0x6, 0x4, 0x2, 0x2c, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x35, 0x7, 0x3, 0x2, 0x2, 0x32, 0x34, 0x7, 0x14, 0x2, 
    0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 
    0x7, 0x4, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x19, 0x2, 0x2, 0x3a, 0x3b, 0x7, 
    0x5, 0x2, 0x2, 0x3b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3e, 0x5, 0x18, 
    0xd, 0x2, 0x3d, 0x3f, 0x7, 0x14, 0x2, 0x2, 0x3e, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x46, 0x7, 0x6, 0x2, 0x2, 0x43, 0x45, 0x7, 0x14, 0x2, 0x2, 0x44, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x45, 0x48, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4d, 0x7, 0x7, 0x2, 
    0x2, 0x4a, 0x4c, 0x7, 0x14, 0x2, 0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x50, 0x54, 0x7, 0x8, 0x2, 0x2, 0x51, 0x53, 0x7, 
    0x14, 0x2, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 0x2, 0x53, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x55, 0x57, 0x3, 0x2, 0x2, 0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x5b, 0x7, 0x9, 0x2, 0x2, 0x58, 0x5a, 0x7, 0x14, 0x2, 0x2, 0x59, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x67, 0x3, 
    0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x62, 0x5, 0x10, 
    0x9, 0x2, 0x5f, 0x61, 0x7, 0x14, 0x2, 0x2, 0x60, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x64, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x65, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x66, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x73, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x6e, 0x5, 0xe, 0x8, 0x2, 0x6b, 0x6d, 0x7, 0x14, 0x2, 
    0x2, 0x6c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x70, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 
    0x72, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6a, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x75, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x76, 0x78, 0x5, 0xa, 0x6, 
    0x2, 0x77, 0x76, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7b, 0x7, 0x14, 0x2, 0x2, 0x7a, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7a, 
    0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7f, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x83, 0x7, 0xa, 
    0x2, 0x2, 0x80, 0x82, 0x7, 0x14, 0x2, 0x2, 0x81, 0x80, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x85, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x9, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0x83, 0x3, 0x2, 0x2, 0x2, 0x86, 0x88, 0x7, 0xb, 0x2, 0x2, 0x87, 0x89, 
    0x7, 0x14, 0x2, 0x2, 0x88, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x90, 0x5, 0x16, 0xc, 
    0x2, 0x8d, 0x8f, 0x7, 0x14, 0x2, 0x2, 0x8e, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x8f, 0x92, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x90, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0x93, 0x3, 0x2, 0x2, 0x2, 0x92, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0xc, 0x2, 0x2, 0x94, 0x9e, 0x3, 
    0x2, 0x2, 0x2, 0x95, 0x99, 0x7, 0xb, 0x2, 0x2, 0x96, 0x98, 0x7, 0x14, 
    0x2, 0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 0x9b, 0x3, 0x2, 0x2, 
    0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x9e, 0x7, 0xc, 0x2, 0x2, 0x9d, 0x86, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x95, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa3, 0x5, 
    0xe, 0x8, 0x2, 0xa0, 0xa2, 0x7, 0x14, 0x2, 0x2, 0xa1, 0xa0, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa7, 
    0xa8, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 
    0x3, 0x2, 0x2, 0x2, 0xa9, 0xd, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x5, 
    0x14, 0xb, 0x2, 0xab, 0xf, 0x3, 0x2, 0x2, 0x2, 0xac, 0xb0, 0x5, 0x1a, 
    0xe, 0x2, 0xad, 0xaf, 0x7, 0x14, 0x2, 0x2, 0xae, 0xad, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb2, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb7, 0x5, 0x12, 0xa, 0x2, 0xb4, 0xb6, 
    0x7, 0x14, 0x2, 0x2, 0xb5, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb9, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 
    0x2, 0x2, 0xb8, 0xca, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0xba, 0xbe, 0x7, 0xd, 0x2, 0x2, 0xbb, 0xbd, 0x7, 0x14, 0x2, 0x2, 
    0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbe, 
    0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc5, 0x5, 
    0x12, 0xa, 0x2, 0xc2, 0xc4, 0x7, 0x14, 0x2, 0x2, 0xc3, 0xc2, 0x3, 0x2, 
    0x2, 0x2, 0xc4, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 
    0x2, 0xc5, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc9, 0x3, 0x2, 0x2, 0x2, 
    0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xba, 0x3, 0x2, 0x2, 0x2, 0xc9, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xcb, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 
    0x2, 0x2, 0x2, 0xcd, 0xce, 0x7, 0xc, 0x2, 0x2, 0xce, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0xcf, 0xe0, 0x7, 0x1b, 0x2, 0x2, 0xd0, 0xd4, 0x7, 0x1b, 0x2, 
    0x2, 0xd1, 0xd3, 0x7, 0x14, 0x2, 0x2, 0xd2, 0xd1, 0x3, 0x2, 0x2, 0x2, 
    0xd3, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd4, 
    0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xdb, 0x7, 0xe, 0x2, 0x2, 0xd8, 0xda, 0x7, 
    0x14, 0x2, 0x2, 0xd9, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdd, 0x3, 0x2, 
    0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 
    0x2, 0xdc, 0xde, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 0x2, 
    0xde, 0xe0, 0x5, 0x16, 0xc, 0x2, 0xdf, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xdf, 
    0xd0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x13, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe5, 
    0x7, 0x1b, 0x2, 0x2, 0xe2, 0xe4, 0x7, 0x14, 0x2, 0x2, 0xe3, 0xe2, 0x3, 
    0x2, 0x2, 0x2, 0xe4, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe3, 0x3, 0x2, 
    0x2, 0x2, 0xe5, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe8, 0x3, 0x2, 0x2, 
    0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xec, 0x7, 0xe, 0x2, 0x2, 
    0xe9, 0xeb, 0x7, 0x14, 0x2, 0x2, 0xea, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 
    0x3, 0x2, 0x2, 0x2, 0xed, 0xef, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 
    0x2, 0x2, 0x2, 0xef, 0xf0, 0x5, 0x16, 0xc, 0x2, 0xf0, 0xf1, 0x7, 0xc, 
    0x2, 0x2, 0xf1, 0x15, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x8, 0xc, 0x1, 
    0x2, 0xf3, 0x117, 0x7, 0x1b, 0x2, 0x2, 0xf4, 0x117, 0x7, 0x18, 0x2, 
    0x2, 0xf5, 0x117, 0x7, 0x1a, 0x2, 0x2, 0xf6, 0xfa, 0x7, 0x7, 0x2, 0x2, 
    0xf7, 0xf9, 0x7, 0x14, 0x2, 0x2, 0xf8, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf9, 
    0xfc, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 
    0x3, 0x2, 0x2, 0x2, 0xfb, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfa, 0x3, 
    0x2, 0x2, 0x2, 0xfd, 0x101, 0x5, 0x16, 0xc, 0x2, 0xfe, 0x100, 0x7, 0x14, 
    0x2, 0x2, 0xff, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0x103, 0x3, 0x2, 0x2, 
    0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0x102, 0x104, 0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 
    0x104, 0x105, 0x7, 0x8, 0x2, 0x2, 0x105, 0x117, 0x3, 0x2, 0x2, 0x2, 
    0x106, 0x10a, 0x7, 0x10, 0x2, 0x2, 0x107, 0x109, 0x7, 0x14, 0x2, 0x2, 
    0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10c, 0x3, 0x2, 0x2, 0x2, 
    0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 
    0x10b, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10a, 0x3, 0x2, 0x2, 0x2, 
    0x10d, 0x117, 0x5, 0x16, 0xc, 0x4, 0x10e, 0x112, 0x7, 0x16, 0x2, 0x2, 
    0x10f, 0x111, 0x7, 0x14, 0x2, 0x2, 0x110, 0x10f, 0x3, 0x2, 0x2, 0x2, 
    0x111, 0x114, 0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 
    0x112, 0x113, 0x3, 0x2, 0x2, 0x2, 0x113, 0x115, 0x3, 0x2, 0x2, 0x2, 
    0x114, 0x112, 0x3, 0x2, 0x2, 0x2, 0x115, 0x117, 0x5, 0x16, 0xc, 0x3, 
    0x116, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x116, 0xf4, 0x3, 0x2, 0x2, 0x2, 0x116, 
    0xf5, 0x3, 0x2, 0x2, 0x2, 0x116, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x116, 0x106, 
    0x3, 0x2, 0x2, 0x2, 0x116, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x117, 0x156, 
    0x3, 0x2, 0x2, 0x2, 0x118, 0x11c, 0xc, 0x8, 0x2, 0x2, 0x119, 0x11b, 
    0x7, 0x14, 0x2, 0x2, 0x11a, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11e, 
    0x3, 0x2, 0x2, 0x2, 0x11c, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 
    0x3, 0x2, 0x2, 0x2, 0x11d, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11c, 
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x123, 0x7, 0x15, 0x2, 0x2, 0x120, 0x122, 
    0x7, 0x14, 0x2, 0x2, 0x121, 0x120, 0x3, 0x2, 0x2, 0x2, 0x122, 0x125, 
    0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 
    0x3, 0x2, 0x2, 0x2, 0x124, 0x126, 0x3, 0x2, 0x2, 0x2, 0x125, 0x123, 
    0x3, 0x2, 0x2, 0x2, 0x126, 0x155, 0x5, 0x16, 0xc, 0x9, 0x127, 0x12b, 
    0xc, 0x7, 0x2, 0x2, 0x128, 0x12a, 0x7, 0x14, 0x2, 0x2, 0x129, 0x128, 
    0x3, 0x2, 0x2, 0x2, 0x12a, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 
    0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12e, 
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x132, 
    0x7, 0xf, 0x2, 0x2, 0x12f, 0x131, 0x7, 0x14, 0x2, 0x2, 0x130, 0x12f, 
    0x3, 0x2, 0x2, 0x2, 0x131, 0x134, 0x3, 0x2, 0x2, 0x2, 0x132, 0x130, 
    0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 0x135, 
    0x3, 0x2, 0x2, 0x2, 0x134, 0x132, 0x3, 0x2, 0x2, 0x2, 0x135, 0x155, 
    0x5, 0x16, 0xc, 0x8, 0x136, 0x13a, 0xc, 0x6, 0x2, 0x2, 0x137, 0x139, 
    0x7, 0x14, 0x2, 0x2, 0x138, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13c, 
    0x3, 0x2, 0x2, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 
    0x3, 0x2, 0x2, 0x2, 0x13b, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13a, 
    0x3, 0x2, 0x2, 0x2, 0x13d, 0x141, 0x7, 0x10, 0x2, 0x2, 0x13e, 0x140, 
    0x7, 0x14, 0x2, 0x2, 0x13f, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x140, 0x143, 
    0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 
    0x3, 0x2, 0x2, 0x2, 0x142, 0x144, 0x3, 0x2, 0x2, 0x2, 0x143, 0x141, 
    0x3, 0x2, 0x2, 0x2, 0x144, 0x155, 0x5, 0x16, 0xc, 0x7, 0x145, 0x149, 
    0xc, 0x5, 0x2, 0x2, 0x146, 0x148, 0x7, 0x14, 0x2, 0x2, 0x147, 0x146, 
    0x3, 0x2, 0x2, 0x2, 0x148, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x149, 0x147, 
    0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14c, 
    0x3, 0x2, 0x2, 0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x150, 
    0x7, 0x17, 0x2, 0x2, 0x14d, 0x14f, 0x7, 0x14, 0x2, 0x2, 0x14e, 0x14d, 
    0x3, 0x2, 0x2, 0x2, 0x14f, 0x152, 0x3, 0x2, 0x2, 0x2, 0x150, 0x14e, 
    0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 0x3, 0x2, 0x2, 0x2, 0x151, 0x153, 
    0x3, 0x2, 0x2, 0x2, 0x152, 0x150, 0x3, 0x2, 0x2, 0x2, 0x153, 0x155, 
    0x5, 0x16, 0xc, 0x6, 0x154, 0x118, 0x3, 0x2, 0x2, 0x2, 0x154, 0x127, 
    0x3, 0x2, 0x2, 0x2, 0x154, 0x136, 0x3, 0x2, 0x2, 0x2, 0x154, 0x145, 
    0x3, 0x2, 0x2, 0x2, 0x155, 0x158, 0x3, 0x2, 0x2, 0x2, 0x156, 0x154, 
    0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x3, 0x2, 0x2, 0x2, 0x157, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x9, 
    0x2, 0x2, 0x2, 0x15a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x9, 0x3, 
    0x2, 0x2, 0x15c, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x31, 0x20, 0x28, 0x2e, 0x35, 
    0x40, 0x46, 0x4d, 0x54, 0x5b, 0x62, 0x67, 0x6e, 0x73, 0x77, 0x7c, 0x83, 
    0x8a, 0x90, 0x99, 0x9d, 0xa3, 0xa8, 0xb0, 0xb7, 0xbe, 0xc5, 0xca, 0xd4, 
    0xdb, 0xdf, 0xe5, 0xec, 0xfa, 0x101, 0x10a, 0x112, 0x116, 0x11c, 0x123, 
    0x12b, 0x132, 0x13a, 0x141, 0x149, 0x150, 0x154, 0x156, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

exprParser::Initializer exprParser::_init;
