#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>

class QLabel;
class QLineEdit;
class QPushButton;

class Window : public QMainWindow {
public:
    explicit Window(QWidget* parent = nullptr);

private:
    static const QString P_POLY_STR;
    static const QString Q_POLY_STR;
    
    QLabel* m_pPolyLbl;
    QLineEdit* m_pPolyEdt;
    QLabel* m_qPolyLbl;
    QLineEdit* m_qPolyEdt;
    QPushButton* m_additionBtn;
    QPushButton* m_subtractionBtn;
    QPushButton* m_multiplicationBtn;
    QLabel* m_resultLbl;
};

inline const QString Window::P_POLY_STR = "P(x) = ";
inline const QString Window::Q_POLY_STR = "Q(x) = ";

#endif // WINDOW_HPP
