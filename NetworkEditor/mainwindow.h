#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include "workingthread.h"
#include "diagramscene.h"
#include "hyperparameterwidget.h"
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
	void basicUnitBtnGroupClicked(int);
	void deleteItem();
	void useMoveCursor();
	void outputNetworkAction();
	/* ���ݲ�������items��λ�ã�ʹ������ͼ�α�úÿ�*/
	void resetItemsPosition();
	void saveFileAction();
	void openFileAction();
	void onItemSelected(QGraphicsItem *);
    void doAlert();
    void onItemUnSelected(QGraphicsItem *);
private slots:
    void startTraining();
    void startPredict();
    void abortWorkingThread();
    void joinWorkingThread();
    void saveNetwork();
    void loadNetwork();
    void clearNetwork();
    void togglePauseNetwork();
private:
    WorkingThread* workingThread;
    Ui::MainWindow *ui;
    DiagramScene *scene;
	QToolButton *inputUnitBtn;
	QToolButton *linearLayerUnitBtn;
	QToolButton *nonlinearLayerUnitBtn;
	QToolButton *lineUnitBtn;
	QToolButton *moveCursorBtn;
	QToolButton *cnnSubnetBtn;
	QToolButton *cnnConvolutionalUnitBtn;
	QToolButton *cnnMaxPoolingUnitBtn;
    QToolButton *cnnNonlinearLayerUnitBtn;
    QToolButton *sigmoidUnitBtn;
	QMenu *itemMenu;
	HyperParameterWidget *currentHyperParameterWidget;
	/*
	 ���ڲ���һ�����絥Ԫ��ť�Ĺ�������
	 δ��Ӧ���޸ĳɽ���һ��NetworkUnitBase����������ķ���
	*/
	QToolButton *createUnitBtn(QString const & title);
	/*
	��������������ѡ�����絥Ԫѡ��
	*/
	void createUnitBox();
	/*
	���������з��õ���Щ����Ҽ��˵�
	*/
	void createItemMenu();
	/*
	����Ĭ�ϳ����ķ���
	*/
	void createScene();
	/*
	���Ӳ˵���ť���Ӧ��handler�ķ���
	*/
	void connectActions();
	/*
	����settingBox�ķ���
	*/
	void createSettingBox();
	/* ���쳬�������ƽ���ķ��� */
    void createWorkingThread();
	HyperParameterWidget* createHyperParameterWidget(HyperParameterControl *);
    void rebuildNetwork(shared_ptr<MasterControl> master);
	
};

#endif // MAINWINDOW_H
