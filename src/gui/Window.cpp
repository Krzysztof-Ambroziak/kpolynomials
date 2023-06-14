#include "Window.hpp"
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSplitter>

Window::Window(QWidget* parent) : QMainWindow(parent) {
    QWidget* centralWidget = new QWidget(this);
    QLayout* layout = new QVBoxLayout(centralWidget);
    QSplitter* splitter = new QSplitter(Qt::Orientation::Horizontal, centralWidget);
    
    m_pPolyLbl = new QLabel(P_POLY_STR, centralWidget);
    m_pPolyEdt = new QLineEdit(centralWidget);
    m_qPolyLbl = new QLabel(Q_POLY_STR, centralWidget);
    m_qPolyEdt = new QLineEdit(centralWidget);
    m_additionBtn = new QPushButton("+", splitter);
    m_subtractionBtn = new QPushButton("-", splitter);
    m_multiplicationBtn = new QPushButton("*", splitter);
    m_resultLbl = new QLabel(centralWidget);
    
    m_pPolyLbl->setAlignment(Qt::AlignCenter);
    m_pPolyEdt->setAlignment(Qt::AlignCenter);
    m_qPolyLbl->setAlignment(Qt::AlignCenter);
    m_qPolyEdt->setAlignment(Qt::AlignCenter);
    m_resultLbl->setAlignment(Qt::AlignCenter);
    m_resultLbl->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    
    splitter->addWidget(m_additionBtn);
    splitter->addWidget(m_subtractionBtn);
    splitter->addWidget(m_multiplicationBtn);
    
    layout->addWidget(m_pPolyLbl);
    layout->addWidget(m_pPolyEdt);
    layout->addWidget(m_qPolyLbl);
    layout->addWidget(m_qPolyEdt);
    layout->addWidget(splitter);
    layout->addWidget(m_resultLbl);
    
    setCentralWidget(centralWidget);
}
