
// Generated from /home/louis/Documents/Projets/COMP/src/parser/expr.g4 by ANTLR 4.7.2


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
    setState(34);
    preproc();
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
    setState(52);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(46);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(43);
          match(exprParser::SPACE);
          setState(48);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(49);
        include(); 
      }
      setState(54);
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

tree::TerminalNode* exprParser::IncludeContext::VAR() {
  return getToken(exprParser::VAR, 0);
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
    setState(55);
    match(exprParser::T__0);
    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(56);
      match(exprParser::SPACE);
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(62);
    match(exprParser::T__1);
    setState(63);
    match(exprParser::VAR);
    setState(64);
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
    setState(66);
    funcType();
    setState(68); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(67);
      match(exprParser::SPACE);
      setState(70); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == exprParser::SPACE);
    setState(72);
    match(exprParser::T__3);
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(73);
      match(exprParser::SPACE);
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(79);
    match(exprParser::T__4);
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(80);
      match(exprParser::SPACE);
      setState(85);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(86);
    match(exprParser::T__5);
    setState(90);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(87);
      match(exprParser::SPACE);
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(93);
    match(exprParser::T__6);
    setState(97);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(94);
        match(exprParser::SPACE); 
      }
      setState(99);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
    setState(109);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::T__17

    || _la == exprParser::T__19) {
      setState(100);
      declaration();
      setState(104);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(101);
          match(exprParser::SPACE); 
        }
        setState(106);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(111);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(121);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << exprParser::T__12)
      | (1ULL << exprParser::T__14)
      | (1ULL << exprParser::VAR))) != 0)) {
      setState(112);
      instruction();
      setState(116);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(113);
          match(exprParser::SPACE); 
        }
        setState(118);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      }
      setState(123);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(125);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == exprParser::T__11) {
      setState(124);
      ret();
    }
    setState(130);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(127);
      match(exprParser::SPACE);
      setState(132);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(133);
    match(exprParser::T__7);
    setState(137);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(134);
      match(exprParser::SPACE);
      setState(139);
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
  enterRule(_localctx, 8, exprParser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    varType();
    setState(144);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(141);
      match(exprParser::SPACE);
      setState(146);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(147);
    newVar();
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
    setState(170);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::T__8) {
      setState(154);
      match(exprParser::T__8);
      setState(158);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(155);
        match(exprParser::SPACE);
        setState(160);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(161);
      newVar();
      setState(165);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(162);
        match(exprParser::SPACE);
        setState(167);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(172);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(173);
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
  enterRule(_localctx, 10, exprParser::RuleNewVar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(191);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<NewVarContext *>(_tracker.createInstance<exprParser::PlainNewVariableContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(175);
      match(exprParser::VAR);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<NewVarContext *>(_tracker.createInstance<exprParser::ValuedNewVariableContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(176);
      match(exprParser::VAR);
      setState(180);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(177);
        match(exprParser::SPACE);
        setState(182);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(183);
      match(exprParser::T__10);
      setState(187);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(184);
        match(exprParser::SPACE);
        setState(189);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(190);
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
  enterRule(_localctx, 12, exprParser::RuleRet);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(216);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<RetContext *>(_tracker.createInstance<exprParser::RetExprContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(193);
      match(exprParser::T__11);
      setState(195); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(194);
        match(exprParser::SPACE);
        setState(197); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == exprParser::SPACE);
      setState(199);
      expression(0);
      setState(203);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(200);
        match(exprParser::SPACE);
        setState(205);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(206);
      match(exprParser::T__9);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<RetContext *>(_tracker.createInstance<exprParser::RetNoExprContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(208);
      match(exprParser::T__11);
      setState(212);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(209);
        match(exprParser::SPACE);
        setState(214);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(215);
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

std::vector<tree::TerminalNode *> exprParser::BlockContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::BlockContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

std::vector<exprParser::DeclarationContext *> exprParser::BlockContext::declaration() {
  return getRuleContexts<exprParser::DeclarationContext>();
}

exprParser::DeclarationContext* exprParser::BlockContext::declaration(size_t i) {
  return getRuleContext<exprParser::DeclarationContext>(i);
}

std::vector<exprParser::InstructionContext *> exprParser::BlockContext::instruction() {
  return getRuleContexts<exprParser::InstructionContext>();
}

exprParser::InstructionContext* exprParser::BlockContext::instruction(size_t i) {
  return getRuleContext<exprParser::InstructionContext>(i);
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
  enterRule(_localctx, 14, exprParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(exprParser::T__6);
    setState(222);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(219);
      match(exprParser::SPACE);
      setState(224);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::T__17

    || _la == exprParser::T__19) {
      setState(225);
      declaration();
      setState(229);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(226);
        match(exprParser::SPACE);
        setState(231);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(236);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(246);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << exprParser::T__12)
      | (1ULL << exprParser::T__14)
      | (1ULL << exprParser::VAR))) != 0)) {
      setState(237);
      instruction();
      setState(241);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(238);
        match(exprParser::SPACE);
        setState(243);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(248);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(249);
    match(exprParser::T__7);
   
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

exprParser::OptionalContext* exprParser::InstructionContext::optional() {
  return getRuleContext<exprParser::OptionalContext>(0);
}

exprParser::LoopContext* exprParser::InstructionContext::loop() {
  return getRuleContext<exprParser::LoopContext>(0);
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
  enterRule(_localctx, 16, exprParser::RuleInstruction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(254);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(251);
        assignment();
        break;
      }

      case exprParser::T__12: {
        enterOuterAlt(_localctx, 2);
        setState(252);
        optional();
        break;
      }

      case exprParser::T__14: {
        enterOuterAlt(_localctx, 3);
        setState(253);
        loop();
        break;
      }

    default:
      throw NoViableAltException(this);
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
    setState(256);
    match(exprParser::VAR);
    setState(260);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(257);
      match(exprParser::SPACE);
      setState(262);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(263);
    match(exprParser::T__10);
    setState(267);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(264);
      match(exprParser::SPACE);
      setState(269);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(270);
    expression(0);
    setState(271);
    match(exprParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OptionalContext ------------------------------------------------------------------

exprParser::OptionalContext::OptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::ConditionContext* exprParser::OptionalContext::condition() {
  return getRuleContext<exprParser::ConditionContext>(0);
}

std::vector<exprParser::ControlBodyContext *> exprParser::OptionalContext::controlBody() {
  return getRuleContexts<exprParser::ControlBodyContext>();
}

exprParser::ControlBodyContext* exprParser::OptionalContext::controlBody(size_t i) {
  return getRuleContext<exprParser::ControlBodyContext>(i);
}

std::vector<tree::TerminalNode *> exprParser::OptionalContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::OptionalContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}


size_t exprParser::OptionalContext::getRuleIndex() const {
  return exprParser::RuleOptional;
}


antlrcpp::Any exprParser::OptionalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitOptional(this);
  else
    return visitor->visitChildren(this);
}

exprParser::OptionalContext* exprParser::optional() {
  OptionalContext *_localctx = _tracker.createInstance<OptionalContext>(_ctx, getState());
  enterRule(_localctx, 20, exprParser::RuleOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    match(exprParser::T__12);
    setState(274);
    condition();
    setState(275);
    controlBody();
    setState(290);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(279);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(276);
        match(exprParser::SPACE);
        setState(281);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(282);
      match(exprParser::T__13);
      setState(286);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(283);
        match(exprParser::SPACE);
        setState(288);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(289);
      controlBody();
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

//----------------- LoopContext ------------------------------------------------------------------

exprParser::LoopContext::LoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::ConditionContext* exprParser::LoopContext::condition() {
  return getRuleContext<exprParser::ConditionContext>(0);
}

exprParser::ControlBodyContext* exprParser::LoopContext::controlBody() {
  return getRuleContext<exprParser::ControlBodyContext>(0);
}


size_t exprParser::LoopContext::getRuleIndex() const {
  return exprParser::RuleLoop;
}


antlrcpp::Any exprParser::LoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitLoop(this);
  else
    return visitor->visitChildren(this);
}

exprParser::LoopContext* exprParser::loop() {
  LoopContext *_localctx = _tracker.createInstance<LoopContext>(_ctx, getState());
  enterRule(_localctx, 22, exprParser::RuleLoop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    match(exprParser::T__14);
    setState(293);
    condition();
    setState(294);
    controlBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

exprParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::ExpressionContext* exprParser::ConditionContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::ConditionContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::ConditionContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}


size_t exprParser::ConditionContext::getRuleIndex() const {
  return exprParser::RuleCondition;
}


antlrcpp::Any exprParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

exprParser::ConditionContext* exprParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 24, exprParser::RuleCondition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(296);
      match(exprParser::SPACE);
      setState(301);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(302);
    match(exprParser::T__4);
    setState(306);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(303);
      match(exprParser::SPACE);
      setState(308);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(309);
    expression(0);
    setState(313);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(310);
      match(exprParser::SPACE);
      setState(315);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(316);
    match(exprParser::T__5);
    setState(320);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(317);
      match(exprParser::SPACE);
      setState(322);
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

//----------------- ControlBodyContext ------------------------------------------------------------------

exprParser::ControlBodyContext::ControlBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::BlockContext* exprParser::ControlBodyContext::block() {
  return getRuleContext<exprParser::BlockContext>(0);
}

exprParser::InstructionContext* exprParser::ControlBodyContext::instruction() {
  return getRuleContext<exprParser::InstructionContext>(0);
}


size_t exprParser::ControlBodyContext::getRuleIndex() const {
  return exprParser::RuleControlBody;
}


antlrcpp::Any exprParser::ControlBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitControlBody(this);
  else
    return visitor->visitChildren(this);
}

exprParser::ControlBodyContext* exprParser::controlBody() {
  ControlBodyContext *_localctx = _tracker.createInstance<ControlBodyContext>(_ctx, getState());
  enterRule(_localctx, 26, exprParser::RuleControlBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(325);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(323);
        block();
        break;
      }

      case exprParser::T__12:
      case exprParser::T__14:
      case exprParser::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(324);
        instruction();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
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
//----------------- ComparisonContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::ComparisonContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::ComparisonContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

tree::TerminalNode* exprParser::ComparisonContext::OPCOMP() {
  return getToken(exprParser::OPCOMP, 0);
}

std::vector<tree::TerminalNode *> exprParser::ComparisonContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::ComparisonContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::ComparisonContext::ComparisonContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::ComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitComparison(this);
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
//----------------- LogicalContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::LogicalContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::LogicalContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

tree::TerminalNode* exprParser::LogicalContext::LOGICOP() {
  return getToken(exprParser::LOGICOP, 0);
}

std::vector<tree::TerminalNode *> exprParser::LogicalContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::LogicalContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::LogicalContext::LogicalContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::LogicalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitLogical(this);
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
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, exprParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(363);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::VAR: {
        _localctx = _tracker.createInstance<VariableContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(328);
        match(exprParser::VAR);
        break;
      }

      case exprParser::INT: {
        _localctx = _tracker.createInstance<IntContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(329);
        match(exprParser::INT);
        break;
      }

      case exprParser::CHAR: {
        _localctx = _tracker.createInstance<CharContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(330);
        match(exprParser::CHAR);
        break;
      }

      case exprParser::T__4: {
        _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(331);
        match(exprParser::T__4);
        setState(335);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(332);
          match(exprParser::SPACE);
          setState(337);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(338);
        expression(0);
        setState(342);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(339);
          match(exprParser::SPACE);
          setState(344);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(345);
        match(exprParser::T__5);
        break;
      }

      case exprParser::UNARYOP: {
        _localctx = _tracker.createInstance<UnaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(347);
        match(exprParser::UNARYOP);
        setState(351);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(348);
          match(exprParser::SPACE);
          setState(353);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(354);
        expression(8);
        break;
      }

      case exprParser::T__15: {
        _localctx = _tracker.createInstance<NegativeUnaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(355);
        match(exprParser::T__15);
        setState(359);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(356);
          match(exprParser::SPACE);
          setState(361);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(362);
        expression(7);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(457);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(455);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(365);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(369);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(366);
            match(exprParser::SPACE);
            setState(371);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(372);
          match(exprParser::OPMUL);
          setState(376);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(373);
            match(exprParser::SPACE);
            setState(378);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(379);
          expression(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(380);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(384);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(381);
            match(exprParser::SPACE);
            setState(386);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(387);
          match(exprParser::T__16);
          setState(391);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(388);
            match(exprParser::SPACE);
            setState(393);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(394);
          expression(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<SubContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(395);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(399);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(396);
            match(exprParser::SPACE);
            setState(401);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(402);
          match(exprParser::T__15);
          setState(406);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(403);
            match(exprParser::SPACE);
            setState(408);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(409);
          expression(5);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ComparisonContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(410);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(414);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(411);
            match(exprParser::SPACE);
            setState(416);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(417);
          match(exprParser::OPCOMP);
          setState(421);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(418);
            match(exprParser::SPACE);
            setState(423);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(424);
          expression(4);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(425);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(429);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(426);
            match(exprParser::SPACE);
            setState(431);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(432);
          match(exprParser::OPBIN);
          setState(436);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(433);
            match(exprParser::SPACE);
            setState(438);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(439);
          expression(3);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(440);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(444);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(441);
            match(exprParser::SPACE);
            setState(446);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(447);
          match(exprParser::LOGICOP);
          setState(451);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(448);
            match(exprParser::SPACE);
            setState(453);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(454);
          expression(2);
          break;
        }

        } 
      }
      setState(459);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
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
  enterRule(_localctx, 30, exprParser::RuleFuncType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    _la = _input->LA(1);
    if (!(_la == exprParser::T__17

    || _la == exprParser::T__18)) {
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
  enterRule(_localctx, 32, exprParser::RuleVarType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    _la = _input->LA(1);
    if (!(_la == exprParser::T__17

    || _la == exprParser::T__19)) {
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
    case 14: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

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
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 1);

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
  "prog", "preproc", "include", "main", "declaration", "newVar", "ret", 
  "block", "instruction", "assignment", "optional", "loop", "condition", 
  "controlBody", "expression", "funcType", "varType"
};

std::vector<std::string> exprParser::_literalNames = {
  "", "'#include'", "'<'", "'>'", "'main'", "'('", "')'", "'{'", "'}'", 
  "','", "';'", "'='", "'return'", "'if'", "'else'", "'while'", "'-'", "'+'", 
  "'int'", "'void'", "'char'"
};

std::vector<std::string> exprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "SPACE", "OPMUL", "UNARYOP", "OPCOMP", "OPBIN", "LOGICOP", 
  "INT", "CHAR", "VAR"
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
    0x3, 0x1f, 0x1d3, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x27, 0xa, 0x2, 0xc, 
    0x2, 0xe, 0x2, 0x2a, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 
    0x2f, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x32, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 
    0x35, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x38, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x7, 0x4, 0x3c, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x3f, 0xb, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x6, 0x5, 0x47, 0xa, 
    0x5, 0xd, 0x5, 0xe, 0x5, 0x48, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x4d, 0xa, 
    0x5, 0xc, 0x5, 0xe, 0x5, 0x50, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 
    0x54, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x57, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x7, 0x5, 0x5b, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x5e, 0xb, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x7, 0x5, 0x62, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x65, 0xb, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x69, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x6c, 
    0xb, 0x5, 0x7, 0x5, 0x6e, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x71, 0xb, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x75, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x78, 
    0xb, 0x5, 0x7, 0x5, 0x7a, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x7d, 0xb, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x80, 0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 0x83, 0xa, 0x5, 
    0xc, 0x5, 0xe, 0x5, 0x86, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x8a, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x8d, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x7, 
    0x6, 0x91, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x94, 0xb, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x7, 0x6, 0x98, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x9b, 0xb, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x9f, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xa2, 0xb, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0xa6, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0xa9, 0xb, 0x6, 0x7, 0x6, 0xab, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xae, 
    0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 
    0xb5, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xb8, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x7, 0x7, 0xbc, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xbf, 0xb, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0xc2, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x6, 0x8, 0xc6, 0xa, 0x8, 
    0xd, 0x8, 0xe, 0x8, 0xc7, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xcc, 0xa, 0x8, 
    0xc, 0x8, 0xe, 0x8, 0xcf, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x7, 0x8, 0xd5, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xd8, 0xb, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0xdb, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xdf, 0xa, 
    0x9, 0xc, 0x9, 0xe, 0x9, 0xe2, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 
    0xe6, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xe9, 0xb, 0x9, 0x7, 0x9, 0xeb, 
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xee, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 
    0x9, 0xf2, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xf5, 0xb, 0x9, 0x7, 0x9, 0xf7, 
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xfa, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x101, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 
    0x7, 0xb, 0x105, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x108, 0xb, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x7, 0xb, 0x10c, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x10f, 
    0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x7, 0xc, 0x118, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x11b, 0xb, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x11f, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 
    0x122, 0xb, 0xc, 0x3, 0xc, 0x5, 0xc, 0x125, 0xa, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x7, 0xe, 0x12c, 0xa, 0xe, 0xc, 0xe, 
    0xe, 0xe, 0x12f, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x133, 0xa, 
    0xe, 0xc, 0xe, 0xe, 0xe, 0x136, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 
    0x13a, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x13d, 0xb, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x7, 0xe, 0x141, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x144, 0xb, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x148, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x150, 0xa, 0x10, 
    0xc, 0x10, 0xe, 0x10, 0x153, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 
    0x157, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x15a, 0xb, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x160, 0xa, 0x10, 0xc, 0x10, 
    0xe, 0x10, 0x163, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 
    0x168, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x16b, 0xb, 0x10, 0x3, 0x10, 
    0x5, 0x10, 0x16e, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x172, 
    0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x175, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x7, 0x10, 0x179, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x17c, 0xb, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x181, 0xa, 0x10, 0xc, 0x10, 
    0xe, 0x10, 0x184, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x188, 
    0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x18b, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x7, 0x10, 0x190, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x193, 
    0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x197, 0xa, 0x10, 0xc, 0x10, 
    0xe, 0x10, 0x19a, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 
    0x19f, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x1a2, 0xb, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x7, 0x10, 0x1a6, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x1a9, 
    0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x1ae, 0xa, 0x10, 
    0xc, 0x10, 0xe, 0x10, 0x1b1, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 
    0x1b5, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x1b8, 0xb, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x1bd, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 
    0x1c0, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x1c4, 0xa, 0x10, 
    0xc, 0x10, 0xe, 0x10, 0x1c7, 0xb, 0x10, 0x3, 0x10, 0x7, 0x10, 0x1ca, 
    0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x1cd, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x2, 0x3, 0x1e, 0x13, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x2, 0x4, 0x3, 0x2, 0x14, 0x15, 0x4, 0x2, 0x14, 0x14, 0x16, 
    0x16, 0x2, 0x209, 0x2, 0x24, 0x3, 0x2, 0x2, 0x2, 0x4, 0x36, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x39, 0x3, 0x2, 0x2, 0x2, 0x8, 0x44, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x8e, 0x3, 0x2, 0x2, 0x2, 0xc, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xe, 0xda, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x12, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x102, 0x3, 0x2, 0x2, 0x2, 0x16, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x126, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x12d, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x147, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x16d, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x22, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x28, 0x5, 0x4, 0x3, 0x2, 0x25, 0x27, 0x7, 0x17, 0x2, 0x2, 0x26, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0x27, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x5, 0x8, 0x5, 
    0x2, 0x2c, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2f, 0x7, 0x17, 0x2, 0x2, 
    0x2e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x32, 0x3, 0x2, 0x2, 0x2, 0x30, 
    0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x33, 0x35, 0x5, 
    0x6, 0x4, 0x2, 0x34, 0x30, 0x3, 0x2, 0x2, 0x2, 0x35, 0x38, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x37, 0x5, 0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0x3d, 0x7, 0x3, 0x2, 0x2, 0x3a, 0x3c, 0x7, 0x17, 0x2, 0x2, 0x3b, 
    0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x7, 0x4, 
    0x2, 0x2, 0x41, 0x42, 0x7, 0x1f, 0x2, 0x2, 0x42, 0x43, 0x7, 0x5, 0x2, 
    0x2, 0x43, 0x7, 0x3, 0x2, 0x2, 0x2, 0x44, 0x46, 0x5, 0x20, 0x11, 0x2, 
    0x45, 0x47, 0x7, 0x17, 0x2, 0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 
    0x48, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4e, 0x7, 
    0x6, 0x2, 0x2, 0x4b, 0x4d, 0x7, 0x17, 0x2, 0x2, 0x4c, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x4d, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x51, 0x55, 0x7, 0x7, 0x2, 0x2, 0x52, 
    0x54, 0x7, 0x17, 0x2, 0x2, 0x53, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 
    0x2, 0x2, 0x2, 0x56, 0x58, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x5c, 0x7, 0x8, 0x2, 0x2, 0x59, 0x5b, 0x7, 0x17, 0x2, 
    0x2, 0x5a, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5e, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5d, 
    0x5f, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x63, 
    0x7, 0x9, 0x2, 0x2, 0x60, 0x62, 0x7, 0x17, 0x2, 0x2, 0x61, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x65, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x66, 0x6a, 0x5, 0xa, 0x6, 0x2, 
    0x67, 0x69, 0x7, 0x17, 0x2, 0x2, 0x68, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x6b, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 
    0x2, 0x2, 0x2, 0x6d, 0x66, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x71, 0x3, 0x2, 
    0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x76, 0x5, 0x12, 0xa, 0x2, 0x73, 0x75, 0x7, 0x17, 0x2, 0x2, 0x74, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x78, 0x3, 0x2, 0x2, 0x2, 0x76, 0x74, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x7a, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x79, 0x72, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x7b, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x7d, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x80, 0x5, 0xe, 0x8, 0x2, 0x7f, 
    0x7e, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x84, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x83, 0x7, 0x17, 0x2, 0x2, 0x82, 0x81, 0x3, 
    0x2, 0x2, 0x2, 0x83, 0x86, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x87, 0x8b, 0x7, 0xa, 0x2, 0x2, 
    0x88, 0x8a, 0x7, 0x17, 0x2, 0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x8d, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 
    0x3, 0x2, 0x2, 0x2, 0x8c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x92, 0x5, 0x22, 0x12, 0x2, 0x8f, 0x91, 0x7, 0x17, 
    0x2, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x94, 0x3, 0x2, 0x2, 
    0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x93, 0x95, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 0x95, 
    0x99, 0x5, 0xc, 0x7, 0x2, 0x96, 0x98, 0x7, 0x17, 0x2, 0x2, 0x97, 0x96, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0xac, 0x3, 0x2, 
    0x2, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9c, 0xa0, 0x7, 0xb, 0x2, 
    0x2, 0x9d, 0x9f, 0x7, 0x17, 0x2, 0x2, 0x9e, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 
    0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0xa3, 0xa7, 0x5, 0xc, 0x7, 0x2, 0xa4, 0xa6, 0x7, 
    0x17, 0x2, 0x2, 0xa5, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xa8, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0xaa, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xab, 0xae, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xaf, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 
    0xc, 0x2, 0x2, 0xb0, 0xb, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xc2, 0x7, 0x1f, 
    0x2, 0x2, 0xb2, 0xb6, 0x7, 0x1f, 0x2, 0x2, 0xb3, 0xb5, 0x7, 0x17, 0x2, 
    0x2, 0xb4, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb8, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0xb9, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbd, 
    0x7, 0xd, 0x2, 0x2, 0xba, 0xbc, 0x7, 0x17, 0x2, 0x2, 0xbb, 0xba, 0x3, 
    0x2, 0x2, 0x2, 0xbc, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 
    0x2, 0x2, 0xbd, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0x1e, 0x10, 0x2, 
    0xc1, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc5, 0x7, 0xe, 0x2, 0x2, 0xc4, 0xc6, 
    0x7, 0x17, 0x2, 0x2, 0xc5, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 
    0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcd, 0x5, 0x1e, 0x10, 
    0x2, 0xca, 0xcc, 0x7, 0x17, 0x2, 0x2, 0xcb, 0xca, 0x3, 0x2, 0x2, 0x2, 
    0xcc, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 
    0xce, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 
    0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0xc, 0x2, 0x2, 0xd1, 0xdb, 0x3, 
    0x2, 0x2, 0x2, 0xd2, 0xd6, 0x7, 0xe, 0x2, 0x2, 0xd3, 0xd5, 0x7, 0x17, 
    0x2, 0x2, 0xd4, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 
    0xd7, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xdb, 0x7, 0xc, 0x2, 0x2, 0xda, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd2, 
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xf, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xe0, 0x7, 
    0x9, 0x2, 0x2, 0xdd, 0xdf, 0x7, 0x17, 0x2, 0x2, 0xde, 0xdd, 0x3, 0x2, 
    0x2, 0x2, 0xdf, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 
    0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xec, 0x3, 0x2, 0x2, 0x2, 
    0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe7, 0x5, 0xa, 0x6, 0x2, 0xe4, 
    0xe6, 0x7, 0x17, 0x2, 0x2, 0xe5, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe9, 
    0x3, 0x2, 0x2, 0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 
    0x2, 0x2, 0x2, 0xe8, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 
    0x2, 0x2, 0xea, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 0x2, 0x2, 
    0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 
    0xed, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 0xef, 
    0xf3, 0x5, 0x12, 0xa, 0x2, 0xf0, 0xf2, 0x7, 0x17, 0x2, 0x2, 0xf1, 0xf0, 
    0x3, 0x2, 0x2, 0x2, 0xf2, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf7, 0x3, 0x2, 
    0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0xf7, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf6, 0x3, 0x2, 0x2, 0x2, 
    0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfa, 
    0xf8, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0xa, 0x2, 0x2, 0xfc, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0xfd, 0x101, 0x5, 0x14, 0xb, 0x2, 0xfe, 0x101, 0x5, 
    0x16, 0xc, 0x2, 0xff, 0x101, 0x5, 0x18, 0xd, 0x2, 0x100, 0xfd, 0x3, 
    0x2, 0x2, 0x2, 0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0xff, 0x3, 0x2, 
    0x2, 0x2, 0x101, 0x13, 0x3, 0x2, 0x2, 0x2, 0x102, 0x106, 0x7, 0x1f, 
    0x2, 0x2, 0x103, 0x105, 0x7, 0x17, 0x2, 0x2, 0x104, 0x103, 0x3, 0x2, 
    0x2, 0x2, 0x105, 0x108, 0x3, 0x2, 0x2, 0x2, 0x106, 0x104, 0x3, 0x2, 
    0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 0x109, 0x3, 0x2, 
    0x2, 0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10d, 0x7, 0xd, 
    0x2, 0x2, 0x10a, 0x10c, 0x7, 0x17, 0x2, 0x2, 0x10b, 0x10a, 0x3, 0x2, 
    0x2, 0x2, 0x10c, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10b, 0x3, 0x2, 
    0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x110, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x5, 0x1e, 
    0x10, 0x2, 0x111, 0x112, 0x7, 0xc, 0x2, 0x2, 0x112, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x113, 0x114, 0x7, 0xf, 0x2, 0x2, 0x114, 0x115, 0x5, 0x1a, 
    0xe, 0x2, 0x115, 0x124, 0x5, 0x1c, 0xf, 0x2, 0x116, 0x118, 0x7, 0x17, 
    0x2, 0x2, 0x117, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11b, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x3, 0x2, 
    0x2, 0x2, 0x11a, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 
    0x2, 0x2, 0x11c, 0x120, 0x7, 0x10, 0x2, 0x2, 0x11d, 0x11f, 0x7, 0x17, 
    0x2, 0x2, 0x11e, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x122, 0x3, 0x2, 
    0x2, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 
    0x2, 0x2, 0x121, 0x123, 0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 
    0x2, 0x2, 0x123, 0x125, 0x5, 0x1c, 0xf, 0x2, 0x124, 0x119, 0x3, 0x2, 
    0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x127, 0x7, 0x11, 0x2, 0x2, 0x127, 0x128, 0x5, 0x1a, 0xe, 
    0x2, 0x128, 0x129, 0x5, 0x1c, 0xf, 0x2, 0x129, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x12a, 0x12c, 0x7, 0x17, 0x2, 0x2, 0x12b, 0x12a, 0x3, 0x2, 0x2, 
    0x2, 0x12c, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 
    0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x130, 0x3, 0x2, 0x2, 
    0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x130, 0x134, 0x7, 0x7, 0x2, 
    0x2, 0x131, 0x133, 0x7, 0x17, 0x2, 0x2, 0x132, 0x131, 0x3, 0x2, 0x2, 
    0x2, 0x133, 0x136, 0x3, 0x2, 0x2, 0x2, 0x134, 0x132, 0x3, 0x2, 0x2, 
    0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 0x135, 0x137, 0x3, 0x2, 0x2, 
    0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13b, 0x5, 0x1e, 0x10, 
    0x2, 0x138, 0x13a, 0x7, 0x17, 0x2, 0x2, 0x139, 0x138, 0x3, 0x2, 0x2, 
    0x2, 0x13a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 
    0x2, 0x13b, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13e, 0x3, 0x2, 0x2, 
    0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x142, 0x7, 0x8, 0x2, 
    0x2, 0x13f, 0x141, 0x7, 0x17, 0x2, 0x2, 0x140, 0x13f, 0x3, 0x2, 0x2, 
    0x2, 0x141, 0x144, 0x3, 0x2, 0x2, 0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 
    0x2, 0x142, 0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x145, 0x148, 0x5, 0x10, 0x9, 0x2, 
    0x146, 0x148, 0x5, 0x12, 0xa, 0x2, 0x147, 0x145, 0x3, 0x2, 0x2, 0x2, 
    0x147, 0x146, 0x3, 0x2, 0x2, 0x2, 0x148, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x149, 
    0x14a, 0x8, 0x10, 0x1, 0x2, 0x14a, 0x16e, 0x7, 0x1f, 0x2, 0x2, 0x14b, 
    0x16e, 0x7, 0x1d, 0x2, 0x2, 0x14c, 0x16e, 0x7, 0x1e, 0x2, 0x2, 0x14d, 
    0x151, 0x7, 0x7, 0x2, 0x2, 0x14e, 0x150, 0x7, 0x17, 0x2, 0x2, 0x14f, 
    0x14e, 0x3, 0x2, 0x2, 0x2, 0x150, 0x153, 0x3, 0x2, 0x2, 0x2, 0x151, 
    0x14f, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x3, 0x2, 0x2, 0x2, 0x152, 
    0x154, 0x3, 0x2, 0x2, 0x2, 0x153, 0x151, 0x3, 0x2, 0x2, 0x2, 0x154, 
    0x158, 0x5, 0x1e, 0x10, 0x2, 0x155, 0x157, 0x7, 0x17, 0x2, 0x2, 0x156, 
    0x155, 0x3, 0x2, 0x2, 0x2, 0x157, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x158, 
    0x156, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x3, 0x2, 0x2, 0x2, 0x159, 
    0x15b, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15b, 
    0x15c, 0x7, 0x8, 0x2, 0x2, 0x15c, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x15d, 
    0x161, 0x7, 0x19, 0x2, 0x2, 0x15e, 0x160, 0x7, 0x17, 0x2, 0x2, 0x15f, 
    0x15e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x163, 0x3, 0x2, 0x2, 0x2, 0x161, 
    0x15f, 0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x3, 0x2, 0x2, 0x2, 0x162, 
    0x164, 0x3, 0x2, 0x2, 0x2, 0x163, 0x161, 0x3, 0x2, 0x2, 0x2, 0x164, 
    0x16e, 0x5, 0x1e, 0x10, 0xa, 0x165, 0x169, 0x7, 0x12, 0x2, 0x2, 0x166, 
    0x168, 0x7, 0x17, 0x2, 0x2, 0x167, 0x166, 0x3, 0x2, 0x2, 0x2, 0x168, 
    0x16b, 0x3, 0x2, 0x2, 0x2, 0x169, 0x167, 0x3, 0x2, 0x2, 0x2, 0x169, 
    0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16b, 
    0x169, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16e, 0x5, 0x1e, 0x10, 0x9, 0x16d, 
    0x149, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x16d, 
    0x14c, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x16d, 
    0x15d, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x165, 0x3, 0x2, 0x2, 0x2, 0x16e, 
    0x1cb, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x173, 0xc, 0x8, 0x2, 0x2, 0x170, 
    0x172, 0x7, 0x17, 0x2, 0x2, 0x171, 0x170, 0x3, 0x2, 0x2, 0x2, 0x172, 
    0x175, 0x3, 0x2, 0x2, 0x2, 0x173, 0x171, 0x3, 0x2, 0x2, 0x2, 0x173, 
    0x174, 0x3, 0x2, 0x2, 0x2, 0x174, 0x176, 0x3, 0x2, 0x2, 0x2, 0x175, 
    0x173, 0x3, 0x2, 0x2, 0x2, 0x176, 0x17a, 0x7, 0x18, 0x2, 0x2, 0x177, 
    0x179, 0x7, 0x17, 0x2, 0x2, 0x178, 0x177, 0x3, 0x2, 0x2, 0x2, 0x179, 
    0x17c, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17a, 
    0x17b, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17c, 
    0x17a, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x1ca, 0x5, 0x1e, 0x10, 0x9, 0x17e, 
    0x182, 0xc, 0x7, 0x2, 0x2, 0x17f, 0x181, 0x7, 0x17, 0x2, 0x2, 0x180, 
    0x17f, 0x3, 0x2, 0x2, 0x2, 0x181, 0x184, 0x3, 0x2, 0x2, 0x2, 0x182, 
    0x180, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0x3, 0x2, 0x2, 0x2, 0x183, 
    0x185, 0x3, 0x2, 0x2, 0x2, 0x184, 0x182, 0x3, 0x2, 0x2, 0x2, 0x185, 
    0x189, 0x7, 0x13, 0x2, 0x2, 0x186, 0x188, 0x7, 0x17, 0x2, 0x2, 0x187, 
    0x186, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x189, 
    0x187, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18a, 
    0x18c, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x189, 0x3, 0x2, 0x2, 0x2, 0x18c, 
    0x1ca, 0x5, 0x1e, 0x10, 0x8, 0x18d, 0x191, 0xc, 0x6, 0x2, 0x2, 0x18e, 
    0x190, 0x7, 0x17, 0x2, 0x2, 0x18f, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 
    0x193, 0x3, 0x2, 0x2, 0x2, 0x191, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x191, 
    0x192, 0x3, 0x2, 0x2, 0x2, 0x192, 0x194, 0x3, 0x2, 0x2, 0x2, 0x193, 
    0x191, 0x3, 0x2, 0x2, 0x2, 0x194, 0x198, 0x7, 0x12, 0x2, 0x2, 0x195, 
    0x197, 0x7, 0x17, 0x2, 0x2, 0x196, 0x195, 0x3, 0x2, 0x2, 0x2, 0x197, 
    0x19a, 0x3, 0x2, 0x2, 0x2, 0x198, 0x196, 0x3, 0x2, 0x2, 0x2, 0x198, 
    0x199, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19a, 
    0x198, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x1ca, 0x5, 0x1e, 0x10, 0x7, 0x19c, 
    0x1a0, 0xc, 0x5, 0x2, 0x2, 0x19d, 0x19f, 0x7, 0x17, 0x2, 0x2, 0x19e, 
    0x19d, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a0, 
    0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a1, 
    0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a3, 
    0x1a7, 0x7, 0x1a, 0x2, 0x2, 0x1a4, 0x1a6, 0x7, 0x17, 0x2, 0x2, 0x1a5, 
    0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1a7, 
    0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 
    0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1aa, 
    0x1ca, 0x5, 0x1e, 0x10, 0x6, 0x1ab, 0x1af, 0xc, 0x4, 0x2, 0x2, 0x1ac, 
    0x1ae, 0x7, 0x17, 0x2, 0x2, 0x1ad, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
    0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1af, 
    0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b1, 
    0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b6, 0x7, 0x1b, 0x2, 0x2, 0x1b3, 
    0x1b5, 0x7, 0x17, 0x2, 0x2, 0x1b4, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b5, 
    0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b6, 
    0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1b8, 
    0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ca, 0x5, 0x1e, 0x10, 0x5, 0x1ba, 
    0x1be, 0xc, 0x3, 0x2, 0x2, 0x1bb, 0x1bd, 0x7, 0x17, 0x2, 0x2, 0x1bc, 
    0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1be, 
    0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1bf, 
    0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c1, 
    0x1c5, 0x7, 0x1c, 0x2, 0x2, 0x1c2, 0x1c4, 0x7, 0x17, 0x2, 0x2, 0x1c3, 
    0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
    0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c6, 
    0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c8, 
    0x1ca, 0x5, 0x1e, 0x10, 0x4, 0x1c9, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x1c9, 
    0x17e, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x1c9, 
    0x19c, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1c9, 
    0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cb, 
    0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1cc, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cf, 
    0x9, 0x2, 0x2, 0x2, 0x1cf, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 0x9, 
    0x3, 0x2, 0x2, 0x1d1, 0x23, 0x3, 0x2, 0x2, 0x2, 0x41, 0x28, 0x30, 0x36, 
    0x3d, 0x48, 0x4e, 0x55, 0x5c, 0x63, 0x6a, 0x6f, 0x76, 0x7b, 0x7f, 0x84, 
    0x8b, 0x92, 0x99, 0xa0, 0xa7, 0xac, 0xb6, 0xbd, 0xc1, 0xc7, 0xcd, 0xd6, 
    0xda, 0xe0, 0xe7, 0xec, 0xf3, 0xf8, 0x100, 0x106, 0x10d, 0x119, 0x120, 
    0x124, 0x12d, 0x134, 0x13b, 0x142, 0x147, 0x151, 0x158, 0x161, 0x169, 
    0x16d, 0x173, 0x17a, 0x182, 0x189, 0x191, 0x198, 0x1a0, 0x1a7, 0x1af, 
    0x1b6, 0x1be, 0x1c5, 0x1c9, 0x1cb, 
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
