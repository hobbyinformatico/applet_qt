#include <QApplication>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMessageBox>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crea l'icona nella barra delle applicazioni
    //QSystemTrayIcon trayIcon(QIcon("icona.png"), &app);
    QSystemTrayIcon trayIcon(QIcon("icona.png"), &app);
    trayIcon.setToolTip("Qt Applet Example");

    // Crea un menu contestuale per l'icona
    QMenu *menu = new QMenu();
    QAction *showAction = new QAction("Mostra", menu);
    QAction *quitAction = new QAction("Esci", menu);

    // Aggiungi le azioni al menu
    menu->addAction(showAction);
    menu->addAction(quitAction);

    // Connetti le azioni ai rispettivi slot
    QObject::connect(showAction, &QAction::triggered, [&]() {
        // Crea una finestra di dialogo
        QDialog dialog;
        dialog.setWindowTitle("Qt Applet Dialog");

        // Layout verticale per la finestra di dialogo
        QVBoxLayout *layout = new QVBoxLayout(&dialog);

        // Prima riga con icona, testo e pulsante
        QHBoxLayout *rowLayout1 = new QHBoxLayout();
        QLabel *iconLabel1 = new QLabel();
        iconLabel1->setPixmap(QPixmap("icona.png"));
        QLabel *textLabel1 = new QLabel("Riga 1 con icona e pulsante");
        QPushButton *button1 = new QPushButton("Pulsante 1");

        // Connessione del segnale clicked del pulsante alla funzione slotClicked()
        QObject::connect(button1, &QPushButton::clicked, [&]() {
            // LAMBDA con codice da eseguire al click del pulsante
            QMessageBox::information(nullptr, "Qt Applet", "Hai cliccato il pulsante 1!");
        });

        rowLayout1->addWidget(iconLabel1);
        rowLayout1->addWidget(textLabel1);
        rowLayout1->addWidget(button1);
        layout->addLayout(rowLayout1);

        // Seconda riga con icona, testo e pulsante
        QHBoxLayout *rowLayout2 = new QHBoxLayout();
        QLabel *iconLabel2 = new QLabel();
        iconLabel2->setPixmap(QPixmap(":/path/to/icon2.png"));
        QLabel *textLabel2 = new QLabel("Riga 2 con icona e pulsante");
        QPushButton *button2 = new QPushButton("Pulsante 2");

        // Connessione del segnale clicked del pulsante alla funzione slotClicked()
        QObject::connect(button2, &QPushButton::clicked, [&]() {
            // LAMBDA con codice da eseguire al click del pulsante
            QMessageBox::information(nullptr, "Qt Applet", "Hai cliccato il pulsante 2!");
        });

        rowLayout2->addWidget(iconLabel2);
        rowLayout2->addWidget(textLabel2);
        rowLayout2->addWidget(button2);
        layout->addLayout(rowLayout2);

        // Mostra la finestra di dialogo
        dialog.exec();
    });

    QObject::connect(quitAction, &QAction::triggered, [&]() {
        app.quit();
    });

    // Imposta il menu contestuale sull'icona
    trayIcon.setContextMenu(menu);

    // Mostra l'icona nella barra delle applicazioni
    trayIcon.show();

    return app.exec();
}
