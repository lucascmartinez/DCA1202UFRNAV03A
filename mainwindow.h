#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include <QList>
/** @brief Esta é uma classe criada junto a uma interface gráfica do Qt para produzir dados e enviá-los a um servidor. Ela é herdeira de QMainWindow.
 */
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
public slots:
  /** @brief Esta função altera a variável booleana 'opengate' para o estado 'true', permitindo que os dados sejam enviados para o servidor.  */
  void putData();
  /** @brief Esta função altera a variável booleana 'opengate' para o estado 'false', bloqueando o envio de dados para o servidor. */
  void stopData();
  /** @brief Esta função captura o string inserido em uma caixa de texto e o guarda na memória, definindo assim o endereço de IP que será utilizado para a conexão.
    *  @param O string recebido de inputIP, uma entidade da classe QLineEdit. */
  void setIP(QString _ipaddress);
  /** @brief Esta função é ativada ao pressionar o botão de conexão, iniciando assim a conexão ao servidor desejado. */
  void tcpConnect();
  /**  @brief Esta função é ativada ao pressionar o botão de desconectar, concluindo assim a conexão ao servidor desejado. */
  void tcpDisconnect();
  /**  @brief Esta função recebe o valor da barra de valores mínimos, determinando assim o valor mínimo dos dados gerados pelo programa.
   * @param O valor recebido da barra de rolagem sliderMin. */
  void changeMin(int _min);
  /**  @brief Esta função recebe o valor da barra de valores máximos, determinando assim o valor máximo dos dados gerados pelo programa.   *
   * @param O valor recebido da barra de rolagem sliderMax.*/
  void changeMax(int _max);
  /** @brief Esta função recebe o valor da barra do temporizador, determinando a frequência com que os dados são enviados.
    *  @param O valor recebido da barra de rolagem sliderTiming */
  void changeTiming(int _speed);
  /** @brief Esta função envia para o textbrowser os dados que estão sendo enviados ao servidor.
     * @param O valor gerado dentro da função timerEvent. */
  void showMessage(QString msg);
  /** @brief Esta função ativa o envio dos dados ao servidor de acordo com o valor inserido no temporizador.
    *  @param Ativado a cada passagem do tempo determinado pelo temporizador. */
  void timerEvent(QTimerEvent *event);
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int min, max, speed, timerctrl; /**  */
  QString ipaddress; /**  */
  bool opengate; /**  */
};

#endif // MAINWINDOW_H
