
// Generated from src/expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  exprParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, SPACE = 16, UNARYOP = 17, OPMUL = 18, OPADD = 19, OPBIN = 20, 
    INT = 21, LIB = 22, CHAR = 23, VAR = 24
  };

  enum {
    RuleProg = 0, RulePreproc = 1, RuleInclude = 2, RuleMain = 3, RuleRet = 4, 
    RuleBlock = 5, RuleInstruction = 6, RuleDeclaration = 7, RuleNewVar = 8, 
    RuleAssignment = 9, RuleExpression = 10, RuleFuncType = 11, RuleVarType = 12
  };

  exprParser(antlr4::TokenStream *input);
  ~exprParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class PreprocContext;
  class IncludeContext;
  class MainContext;
  class RetContext;
  class BlockContext;
  class InstructionContext;
  class DeclarationContext;
  class NewVarContext;
  class AssignmentContext;
  class ExpressionContext;
  class FuncTypeContext;
  class VarTypeContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PreprocContext *preproc();
    MainContext *main();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  PreprocContext : public antlr4::ParserRuleContext {
  public:
    PreprocContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IncludeContext *> include();
    IncludeContext* include(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PreprocContext* preproc();

  class  IncludeContext : public antlr4::ParserRuleContext {
  public:
    IncludeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIB();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncludeContext* include();

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncTypeContext *funcType();
    RetContext *ret();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);
    std::vector<InstructionContext *> instruction();
    InstructionContext* instruction(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MainContext* main();

  class  RetContext : public antlr4::ParserRuleContext {
  public:
    RetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RetContext() = default;
    void copyFrom(RetContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RetExprContext : public RetContext {
  public:
    RetExprContext(RetContext *ctx);

    ExpressionContext *expression();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RetNoExprContext : public RetContext {
  public:
    RetNoExprContext(RetContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RetContext* ret();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InstructionContext *> instruction();
    InstructionContext* instruction(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  InstructionContext : public antlr4::ParserRuleContext {
  public:
    InstructionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentContext *assignment();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InstructionContext* instruction();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarTypeContext *varType();
    std::vector<NewVarContext *> newVar();
    NewVarContext* newVar(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  NewVarContext : public antlr4::ParserRuleContext {
  public:
    NewVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NewVarContext() = default;
    void copyFrom(NewVarContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ValuedNewVariableContext : public NewVarContext {
  public:
    ValuedNewVariableContext(NewVarContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    ExpressionContext *expression();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PlainNewVariableContext : public NewVarContext {
  public:
    PlainNewVariableContext(NewVarContext *ctx);

    antlr4::tree::TerminalNode *VAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  NewVarContext* newVar();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    ExpressionContext *expression();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AddContext : public ExpressionContext {
  public:
    AddContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *OPADD();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultContext : public ExpressionContext {
  public:
    MultContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *OPMUL();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinContext : public ExpressionContext {
  public:
    BinContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *OPBIN();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableContext : public ExpressionContext {
  public:
    VariableContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *VAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CharContext : public ExpressionContext {
  public:
    CharContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *CHAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryContext : public ExpressionContext {
  public:
    UnaryContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *UNARYOP();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesisContext : public ExpressionContext {
  public:
    ParenthesisContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntContext : public ExpressionContext {
  public:
    IntContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *INT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  FuncTypeContext : public antlr4::ParserRuleContext {
  public:
    FuncTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncTypeContext* funcType();

  class  VarTypeContext : public antlr4::ParserRuleContext {
  public:
    VarTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarTypeContext* varType();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

