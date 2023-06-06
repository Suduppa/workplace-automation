#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <string>
#include <QMessageBox>
#include <QTextStream>
using namespace std;
void Mark(int** matr);
int SumMins(int s, int c);
void TableReduction(int** matr, int s, int c);
int r, ris = 0, prirost, xcenter, ycenter, mins = 10000, leng=0, s;
double gradus = 360;
int ways[10][10];
bool *was;
int *way, *minway;
int** matr;
struct Uzel{
    int x, y;
};
Uzel* uzel;
int* minstr, * mincol;
bool** mas;
int sumRoute = 0;
int counter = 0;
string *buffer_str;

QTextStream cout(stdout);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->build->hide();
    ui->go->hide();
    Hider();
}

void MainWindow::Hider()
{
    // скрывает элементы матрицы смежности
    QString sear;
    for (int i = 1; i < 10; i++)
    {
        sear = "clh" + QString::number(i);
        this->findChild<QWidget*>(sear)->hide();
    }
    for (int i = 1; i < 10; i++)
    {
        sear = "clv" + QString::number(i);
        this->findChild<QWidget*>(sear)->hide();
        sear = "d" + QString::number(i);
        this->findChild<QWidget*>(sear)->hide();
        for (int e = i+1; e<10; e++)
        {
            sear = "p" + QString::number(i) + QString::number(e);
            this->findChild<QWidget*>(sear)->hide();
        }
        for (int e = 1; e < i; e++)
        {
            sear = "l" + QString::number(i) + QString::number(e);
            this->findChild<QWidget*>(sear)->hide();
        }
    }
}

void MainWindow::Shower()
{
    // показывает элементы матрицы смежности
    QString sear;
    for (int i = 1; i < r + 1; i++)
    {
        sear = "clh" + QString::number(i);
        this->findChild<QWidget*>(sear)->show();
    }
    for (int i = 1; i < r+1; i++)
    {
        sear = "clv" + QString::number(i);
        this->findChild<QWidget*>(sear)->show();
        sear = "d" + QString::number(i);
        this->findChild<QWidget*>(sear)->show();
        for (int e = i+1; e<r+1;e++)
        {
            sear = "p" + QString::number(i) + QString::number(e);
            this->findChild<QWidget*>(sear)->show();
        }
        for (int e = 1; e<i;e++)
        {
            sear = "l" + QString::number(i) + QString::number(e);
            this->findChild<QWidget*>(sear)->show();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// преобразование из типа int в string
string FromIntToString(int a)
{
    string c;
    c = to_string(a);
    return c;
}
// преобразование из типа int в char
char FromIntToChar(int a)
{
    char c;
    c = a + '0';
    return c;
}

// преобразование из типа char в int
int FromCharToInt(char s)
{
    int a = s - '0';
    return a;
}

// проверяет, все ли пути найдены
bool NotAtAll(int** matr)
{
    for (int i = 0; i < r;i++)
    {
        for (int j = 0; j < r;j++)
        {
            if (matr[i][j] != -1) // если встретился хотя бы один элемент, не равный -1
                return false;     // значит он не обработан
        }
    }
    return true;
}
// находит минимальное значение в строках
void FindMinInStr(int **matr)
{
    for (int i = 0; i < r; i++)
    {
        int min = 1000;
        for (int j = 0; j < r; j++)
        {
            if (matr[i][j] != -1)
                if (matr[i][j] < min)
                    min = matr[i][j];
        }
        minstr[i] = min;
        if (minstr[i] == 10000)
            minstr[i] = 0;
    }
}
// находит минимальное значение в столбцах
void FindMinInCol(int** matr)
{
    for (int j = 0; j < r; j++)
    {
        int min = 1000;
        for (int i = 0; i < r; i++)
        {
            if (matr[i][j] != -1)
                if (matr[i][j] < min)
                    min = matr[i][j];
        }
        mincol[j] = min;
        if (minstr[j] == 10000)
            minstr[j] = 0;
    }
}
// производит редукцию строк
void ReductionStr(int** matr)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (matr[i][j] != -1)
            {
                matr[i][j] -= minstr[i];
            }
        }
    }
}
// производит редукцию столбцов
void ReductionCol(int** matr)
{
    for (int j = 0; j < r; j++)
    {
        for (int i = 0; i < r; i++)
        {
            if (matr[j][i] != -1)
            {
                matr[j][i] -= mincol[i];
            }
        }
    }
}
// алгоритм поиска оптимального пути
void MainWindow::NewSearch()
{
    QString qstr = "";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            mas[i][j] = false;
    buffer_str = new string [r];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < r; j++)
            {
                matr[i][j] = ways[i][j];
            }
        }
        minstr = new int[r];
        mincol = new int[r];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < r; j++)
            {
                if (matr[i][j] == 0)
                    matr[i][j] = -1;
            }
        }

        int** copyMatr = new int* [r];
        for (int i = 0; i < r; i++)
            copyMatr[i] = new int[r];
        for (int i = 0; i < r; i++)
            for (int j = 0; j < r; j++)
                copyMatr[i][j] = 0;

        while (NotAtAll(matr) == false)
        {
            FindMinInStr(matr);
            ReductionStr(matr);
            FindMinInCol(matr);
            ReductionCol(matr);
            for (int i = 0; i < r; i++)
                mas[i] = new bool[r];
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < r; j++)
                    mas[i][j] = false;
            }
            for (int i = 0; i < r;i++)
            {
                for (int j = 0;j < r;j++)
                {
                    copyMatr[i][j] = matr[i][j];
                }
            }
            Mark(matr);
            int m = -1;
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    if (mas[i][j] == true)
                    {
                        if (m < matr[i][j])
                        {
                            m = ways[i][j];
                            buffer_str[counter] = FromIntToString(i) + "->" + FromIntToString(j);
                        }
                    }
                }
            }
            sumRoute += m;
            string str = buffer_str[counter];
            for (int i = 0; i < r; i++)
                for (int j = 0;j < r;j++)
                    matr[i][j] = copyMatr[i][j];
            TableReduction(matr, FromCharToInt(str[0]), FromCharToInt(str[3]));
            counter++;
        }
        string result = "";
        for (int i = 0; i < r;i++)
        {
            string a = buffer_str[i];
            int first = FromCharToInt(a[0]), last = FromCharToInt(a[3]);
            a[0] = FromIntToChar(first + 1);
            a[3] = FromIntToChar(last + 1);
            buffer_str[i] = a;
            result += "\n" + buffer_str[i];
        }

        qstr = "Возможные передвижения: " + QString::fromStdString(result);
        string res = FromIntToString(sumRoute);
        qstr += "\nДлина кратчайшего пути = " + QString::fromStdString(res);
        QMessageBox::information(this, "Результат", qstr);

        /* очищение памяти */
        for (int i = 0; i < r;i++)
            delete[] matr[i];
        for (int i = 0; i < r;i++)
            delete[] mas[i];
        for (int i = 0; i < r;i++)
            delete[] copyMatr[i];
}

int SumMins(int s, int c)
{
    // сумма минимальных элементов строки и столбца
    int ms = 10000, mc = 10000;
    for (int i = 0; i < r; i++)
    {
        if (i != c && matr[s][i] != -1)
        {
            if (ms > matr[s][i])
                ms = matr[s][i]; // нахождение минимального значения в строках
        }
    }
    if (ms == 10000) ms = 0;
    for (int i = 0; i < r; i++)
    {
        if (i != s && matr[i][c] != -1)
        {
            if (mc > matr[i][c])
                mc = matr[i][c]; // нахождение минимального значения в столбцах
        }
    }
    if (mc == 10000) mc = 0;
    return ms + mc;
}

void Mark(int** matr)
{
    // нахождение оценок для нулевых элементов
    int** newMatr = new int* [r];
    for (int i = 0; i < r; i++) {
        newMatr[i] = new int[r];
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            newMatr[i][j] = matr[i][j]; // копирование значений элементов в массив newMatr

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (matr[i][j] == 0)
            {
                mas[i][j] = true;
                newMatr[i][j] = SumMins(i, j);
                // присваивание элементу суммы минимальных
                // значений в соответствующих строке и столбце
            }
        }
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            matr[i][j] = newMatr[i][j];

    // очищение памяти
    for (int i = 0; i < r;i++)
        delete[] newMatr[i];
}

void TableReduction(int** matr, int s, int c)
{
    // редукция таблицы
    for (int i = 0; i < r; i++)
    {
        matr[s][i] = -1;
    }
    for (int i = 0; i < r;i++)
    {
        matr[i][c] = -1;
    }
    matr[c][s] = -1;
}

void MainWindow::on_go_clicked()
{
    ui->go->setStyleSheet("background-color:rgb(255, 255, 255); border-radius: 10px;");
    QString searcher, buffer;
    leng = 0;
    s = 0;
    mins = 10000;
    was = new bool[r];
    way = new int[r];
    minway = new int[r];
    mas = new bool* [r];
    matr = new int*[r];
    for (int i = 0; i < r; i++)
        matr[i] = new int[r];
    for (int i = 0; i < r; i++)
        mas[i] = new bool[r];
    NewSearch();
    delete[] was;
    delete[] way;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if (ris)
    {
        int otstup;
        gradus/=r;
        prirost=gradus;
        gradus = 0;
        QPainter paint;
        QPen pen;
        QBrush brush;
        QString stroka;
        QFont font;
        pen.setColor(Qt::black);
        pen.setWidth(5);
        pen.setStyle(Qt::SolidLine);
        font.setPointSize(20);
        brush.setStyle(Qt::Dense3Pattern);
        brush.setColor(Qt::white);
        paint.begin(this);
        paint.setPen(pen);
        paint.setFont(font);
        paint.setBrush(brush);
        for (int i=0;i<r;i++)
        {
            otstup = -10;
            if (gradus>100) otstup = 130;
            stroka = QString::number(i+1);
            uzel[i].x = xcenter+(200*cos(gradus/57));
            uzel[i].y = ycenter+(200*sin(gradus/57));
            paint.drawEllipse(uzel[i].x, uzel[i].y, 100, 100);
            paint.drawText(uzel[i].x+48, uzel[i].y+otstup, stroka);
            gradus+=prirost;
        }
        if (ris >1)
        {
            for (int i=0;i<r;i++)
            {
                for (int e=i+1;e<r;e++)
                {
                    if (ways[i][e])
                    {
                        pen.setStyle(Qt::DashLine);
                        pen.setWidth(2);
                        paint.setPen(pen);
                        paint.drawLine(uzel[i].x+50, uzel[i].y+50, uzel[e].x+50, uzel[e].y+50);
                    }
                }
            }
        }
        paint.end();
    }
}

void MainWindow::on_gotab_clicked()
{
    ui->gotab->setStyleSheet("background-color:rgb(255, 255, 255); border-radius: 10px;");
    ui->go->hide();
    if (ui->quantitylabel->text().toInt()<3 || ui->quantitylabel->text().toInt()>9)
    {
        ui->quantitylabel->setText("");
        ui->build->hide();
        Hider();
        ris=0;
        this->repaint();
        QMessageBox::warning(this, "Предупреждение", "Количество городов недопустимо");
    }
    else
    {
        Hider();
        ui->build->show();
        r = ui->quantitylabel->text().toInt();
        Shower();
        uzel= new Uzel[r];
        xcenter=800;
        ycenter=300;
        ris=1;
        this->repaint();
    }
}

void MainWindow::on_build_clicked()
{
    ui->build->setStyleSheet("background-color:rgb(255, 255, 255); border-radius: 10px;");
    ui->go->hide();
    QString searcher, buffer;
    for (int i=1;i<r;i++)
    {
        for (int e=i+1; e<r+1;e++)
        {
            searcher = "p"+QString::number(i) + QString::number(e);
            buffer = this->findChild<QLineEdit*>(searcher)->text();
            if (!buffer.length()) buffer = '0';
            searcher = "l"+QString::number(e) + QString::number(i);
            this->findChild<QLabel*>(searcher)->setText(buffer);
        }
    }
    for (int i = 0; i<r-1;i++)
    {
        for (int e=i+1;e<r;e++)
        {
            searcher="l"+QString::number(e+1) + QString::number(i+1);
            buffer = this->findChild<QLabel*>(searcher)->text();
            if (!buffer.length()) buffer='0';
            ways[i][e]=buffer.toInt();
            ways[e][i]=ways[i][e];
        }
    }
    ui->go->show();
    ris=2;
    this->repaint();
}


void MainWindow::on_gotab_pressed()
{
    ui->gotab->setStyleSheet("color: rgb(255, 255, 255); background-color: rgb(255, 255, 255); border: 1px solid rgb(0, 0, 0); border-radius: 10px;");
}
void MainWindow::on_build_pressed()
{
    ui->build->setStyleSheet("color: rgb(255, 255, 255); background-color: rgb(255, 255, 255); border: 1px solid rgb(0, 0, 0); border-radius: 10px;");
}
void MainWindow::on_go_pressed()
{
    ui->go->setStyleSheet("color: rgb(255, 255, 255); background-color: rgb(255, 255, 255); border: 1px solid rgb(0, 0, 0); border-radius: 10px;");
}
