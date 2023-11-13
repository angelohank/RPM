#ifndef RPMCONTROL_H
#define RPMCONTROL_H

#include <QObject>

class RPMControl : public QObject {
    Q_OBJECT

    Q_PROPERTY( int RPMCount READ RPMCount WRITE setRPMCount NOTIFY RPMCountChanged )
public:
    explicit RPMControl( QObject* parent = nullptr );

signals:
    void updateRPM( int RPM );
    void RPMCountChanged();

public slots:
    void doStart();
    int RPMCount();
    void setRPMCount( const int RPMCount );

private:
    int _RPMCount;
};

#endif // RPMCONTROL_H
