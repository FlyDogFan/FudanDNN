#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
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
    void onItemUnSelected(QGraphicsItem *);
    void trainAction();
    void onAlert(QString);
private:
    Ui::MainWindow *ui;
    DiagramScene *scene;
	QToolButton *inputUnitBtn;
	QToolButton *linearLayerUnitBtn;
	QToolButton *nonlinearLayerUnitBtn;
	QToolButton *lineUnitBtn;
	QToolButton *moveCursorBtn;
    QToolButton *convolutionLayerUnitBtn;
	QToolButton *maxPoolingLayerUnitBtn;
    QToolButton *concatLayerUnitBtn;
	QMenu *itemMenu;
    QButtonGroup *basicUnitBtnGroup = nullptr;
	HyperParameterWidget *currentHyperParameterWidget;
    NetworkHyperParameterWidget *networkSettingWidget;
    NetworkHyperParameterControl *networkHyperParameterControl;
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
	HyperParameterWidget* createHyperParameterWidget(HyperParameterControl *);
	
    void addButtonToBasicUnitBtnGroup(QToolButton * &btn, const char* str, int id);
};

#endif // MAINWINDOW_H
