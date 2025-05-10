#ifndef MESSAGES_H
#define MESSAGES_H

#include <QWidget>

class Messages
{
public:
    Messages() {}

    static bool okToDelete(QWidget *parent, const QString &title,
                           const QString &text, const QString &detailedText = QString());

    static void information(QWidget *parent, const QString &title,
                            const QString &text, const QString &detailedText = QString());
};

#endif // MESSAGES_H
