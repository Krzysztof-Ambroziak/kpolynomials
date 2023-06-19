#ifndef PARSER_HPP
#define PARSER_HPP

#include "Global.hpp"

#include <QRegularExpression>

class Polynomial;
class QString;

class Parser {
public:
    Parser() = delete;
    
    static Polynomial parse(const QString& equation);

private:
    static void prepare(QString& equation);
    
    static void eraseSpacesAndBrackets(QString& str);
    
    static void addPlusSignBeforeMinusSign(QString& str);
    
    static void removeDoubledPlusSign(QString& str);
    
    static void addUnitDigit(QString& str);
    
    static Polynomial parseEquation(const QString& equation);
    
    static poly::Term termFromString(const QString& term);

private:
    static const QRegularExpression PATTERN;
};

inline const QRegularExpression Parser::PATTERN("^-?\\d?([xX](\\^\\d+)?)?(\\+-?\\d?([xX](\\^\\d+)?)?)*$");

#endif // PARSER_HPP
