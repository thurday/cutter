#ifndef EDITINSTRUCTIONDIALOG_H
#define EDITINSTRUCTIONDIALOG_H

#include <QDialog>
#include <QKeyEvent>
#include <memory>

namespace Ui {
class EditInstructionDialog;
}

class EditInstructionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditInstructionDialog(QWidget *parent, bool isEditingBytes);
    ~EditInstructionDialog();

    QString getInstruction();
    void setInstruction(const QString &instruction);

    void updatePreview(const QString &input);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    std::unique_ptr<Ui::EditInstructionDialog> ui;
    bool isEditingBytes; // true if editing intruction **bytes**; false if editing instruction **text**

    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // EDITINSTRUCTIONDIALOG_H
