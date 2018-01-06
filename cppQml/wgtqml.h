#ifndef WGTQML
#define WGTQML
#include <QQuickImageProvider>

class wgtqml : public QQuickImageProvider
{
private:
    QImage brightness(const QImage& imgOrig, int n);
public:
    wgtqml();

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
};

#endif // WGTQML

