#include "Parser.hpp"
#include "Polynomial.hpp"
#include <QString>

Polynomial Parser::parse(const QString& equation) {
    QString eq(equation);
    prepare(eq);
    
    if(!eq.contains(PATTERN))
        return {};
    
    Polynomial polynomial = parseEquation(eq);
    return polynomial;
}

void Parser::prepare(QString& equation) {
    eraseSpacesAndBrackets(equation);
    addPlusSignBeforeMinusSign(equation);
    removeDoubledPlusSign(equation);
    addUnitDigit(equation);
}

void Parser::eraseSpacesAndBrackets(QString& str) {
    str.replace(' ', "").replace('(', "").replace(')', "");
}

void Parser::addPlusSignBeforeMinusSign(QString& str) {
    str.replace('-', "+-");
    if(str[0] == '+')
        str.remove(0, 1);
}

void Parser::removeDoubledPlusSign(QString& str) {
    str.replace("++", "+");
}

void Parser::addUnitDigit(QString& str) {
    if(str.length() >= 1 && str[0] == 'x')
        str.insert(0, '1');
    str.replace("-x", "-1x");
    str.replace("+x", "+1x");
}

Polynomial Parser::parseEquation(const QString& equation) {
    const auto& split = equation.split('+', Qt::SkipEmptyParts);
    Polynomial polynomial;
    
    foreach(const auto& part, split) {
        const auto& term = termFromString(part);
        polynomial.addTerm(term);
    }
    
    return polynomial;
}

poly::Term Parser::termFromString(const QString& term) {
    const auto& pair = term.split('x', Qt::KeepEmptyParts, Qt::CaseInsensitive);
    const int coefficient = pair[0].toInt();
    int power = 0;
    
    if(pair.size() == 2) {
        const auto& variable = pair[1];
        power = variable.isEmpty() ? 1
                                   : QString(variable).remove(0, 1).toInt();
    }
    
    return {coefficient, power};
}
