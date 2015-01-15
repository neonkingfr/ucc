#ifndef SEMA_H_
#define SEMA_H_

#include "parser.h"

typedef struct Symbol Symbol;
typedef struct TypeTag TypeTag;

struct Symbol {
    TypeExp *decl_specs;
    TypeExp *declarator;
    Symbol *next;
};

struct TypeTag {
    TypeExp *type;
    TypeTag *next;
};

void push_scope(void);
void pop_scope(void);
void restore_scope(void);
// Symbol *lookup(char *id, int all);
// void install(TypeExp *decl_specs, TypeExp *declarator);
void install_tag(TypeExp *t);
TypeTag *lookup_tag(char *id, int all);

Token get_id_token(char *id);
int is_typedef_name(char *id);
char *stringify_type_exp(Declaration *d);

void analyze_init_declarator(TypeExp *decl_specs, TypeExp *declarator, int is_func_def);
void analyze_declarator(TypeExp *decl_specs, TypeExp *declarator, int inst_sym);
void analyze_decl_specs(TypeExp *d);
void analyze_enumerator(TypeExp *e);
void analyze_parameter_declaration(Declaration *d);
void analyze_function_definition(FuncDef *f);
void analyze_struct_declarator(TypeExp *sql, TypeExp *declarator);
void check_for_dup_member(DeclList *d);

#endif
