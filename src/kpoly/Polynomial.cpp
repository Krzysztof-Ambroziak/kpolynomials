#include "Polynomial.hpp"
#include "Global.hpp"

void Polynomial::addTerm(const poly::Term& t) {
    const auto& [newCoefficient, newPower] = t;
    
    for(int i = 0; i < m_terms.size(); i++) {
        const auto& [coefficient, power] = m_terms[i];
        
        if(power == newPower) {
            const auto coeff = coefficient + newCoefficient;
            if(coeff != 0)
                m_terms[i].coefficient = coeff;
            else
                m_terms.remove(i);
            return;
        }
    }
    m_terms.push_back(t);
}
